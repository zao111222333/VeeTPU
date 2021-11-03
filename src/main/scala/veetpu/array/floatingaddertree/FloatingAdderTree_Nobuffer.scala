package veetpu.array.floatingaddertree

import spinal.core._
import spinal.lib._
// sbt "runMain veetpu.array.floatingaddertree.FloatingAdderTree_Nobuffer_Verilog"
// import spinal.lib.experimental.math._
import veetpu.ip._
import veetpu.fp._
import veetpu.stage._



class FloatingAdderTree_Nobuffer(fpatConfig: FPATConfig) extends Component{
  import fpatConfig._

  val io = new Bundle{
    val i = new Bundle{
      val X = in Vec(FP(fpConfig),size)
    }
    val o = new Bundle{
      val Y = out (FP(fpConfig))
    }
  }
  noIoPrefix()

//============================================================
// **********   pipe_0   **********
// 比较各指数并返回最大值Max 和 各指数与最大值的Diff（这个减法是否需要调整到pipe_1?）
// 得出flag
// 通过flag中的isDeno得到fullMant
// 得到hasFlag
  var pipe_0 = new Area{
    val stageModule = new Area{
      val compare = new compare16(fpConfig.expSize)
      val hasFlag = new HasFlag(size,fpConfig)
    }
    
    val stageOut = ({new Bundle{
      val sign = Vec(Bool, size)
      val compare = new Bundle {
        val Max = UInt (fpConfig.expSize bit)
        val Diff = Vec(UInt (fpConfig.expSize bit), size)
      }
      val fullMant = Vec(UInt(fpConfig.fullMantSize bit), size)
      val hasFlag = FPHasFlag()
    }})
    // Input  of Pipe
    stageModule.hasFlag.io.i.X := io.i.X
    for (m <- 0 to size-1){
      stageModule.compare.io.i.X(m) := io.i.X(m).exp
    }
    // Inside logic

    // Output of Pipe
    for (m <- 0 to size-1){
      stageOut.sign(m)     := io.i.X(m).sign
      stageOut.fullMant(m) := io.i.X(m).fullMant(stageModule.hasFlag.io.o.isDenoOrZero(m))
    }
    stageOut.compare.Max  := stageModule.compare.io.o.Max
    stageOut.compare.Diff := stageModule.compare.io.o.Diff
    stageOut.hasFlag := stageModule.hasFlag.io.o.hasFlag
  }

//============================================================
// **********   pipe_1   **********
// 根据 pipe_0 的 Diff 对 fullMant 做向右移位 （移位精度+4）
// 将移位后的 尾数 与 符号位 构成的补码做加法树 adderTree
// TODO : spinalHDL的补码功能需要验证
// TODO : adderTree 内部csla的设置需要每次都手动调整

  var pipe_1 = new Area{

    val shiftConfig = ShifterConfig(
                size         = size,
                dataInWidth  = fpConfig.fullMantSize,
                dataOutWidth = fpConfig.fullMantSize+accuracy,
                diffWidth    = fpConfig.expSize
                )
    val stageModule = new Area{
      val rightShifter = new RightShifter(shiftConfig)
      val adderTree = new AdderTree16S(fpConfig.fullMantSize + accuracy, adderTree_CLSA_PRE_WIDTH) //sign 1bit
    }
    
    val stageOut = ({new Bundle{
      val Max     = UInt(fpConfig.expSize bit)
      val addRes  = SInt(addResSize-1 bit)
      val hasFlag = FPHasFlag()
      //val fullMant = Vec(UInt(fpConfig.mantSize+1 bit), size)
    }})

    // Input  of Pipe
    stageModule.rightShifter.io.i.X    := pipe_0.stageOut.fullMant
    stageModule.rightShifter.io.i.Diff := pipe_0.stageOut.compare.Diff
    for (m <- 0 to size-1){
      // 需要转成补码形式
      stageModule.adderTree.io.i.abs(m)  := stageModule.rightShifter.io.o.Y(m)
      stageModule.adderTree.io.i.sign(m) := pipe_0.stageOut.sign(m)
    }
    stageOut.Max     := pipe_0.stageOut.compare.Max
    stageOut.addRes  := stageModule.adderTree.io.o.sum.resize(addResSize-1)
    stageOut.hasFlag := pipe_0.stageOut.hasFlag
  }

//============================================================
// **********   pipe_2   **********
// normalize
// 通过 LeadingZeros 找到最左边的 zero 的位置
// diff = 位宽 - leadingZeroPosition (补码运算)
// 位宽 代表着 Max + 4(?) 指数位
// Exp = Max + 4 - diff = Max + 4 - 位宽 + leadingZeroPosition
// #0
// flag 有SNaN: 结果为SNaN
// #1
// flag 有QNaN 或者 正负无穷都有: 结果为QNaN
// #2
// Exp > 111...10 或者 flag 有且只有1种无穷: 结果为无穷
// outExp = 111...11 ; outMant = 0
// #3
// Exp 为0或负： outExp = 0
// outMant = abs 左移 diff 位
// #4
// 正常情况：outExp = Max - diff
// outMant = abs 左移 diff 位 并舍去最左边的1位（相当于左移 diff+1 位）
//
// TODO : Round
// 简明口诀：「4舍6入5看右，5后有数进上去，尾数为0向左看，左数奇进偶舍弃」。
// 为了避免四舍五入规则造成的结果偏高，误差偏大的现象出现，一般采用四舍六入五留双规则。
  var pipe_2 = new Area{
    val shiftConfig = ShifterConfig(
                size         = 1,
                dataInWidth  = addResSize-1,
                dataOutWidth = fpConfig.mantSize + 4, // +4 for Round
                diffWidth    = log2Up(addResSize-1+1) 
                )
    
    val stageModule = new Area{
      val leadingZeros = new LeadingZeros(addResSize-1)
      val leftShifter  = new LeftShifter(shiftConfig)
      
    }

    
    
    

    // Input  of Pipe
    //val sign = pipe_1.stageOut.addRes.sign
    //val abs  = pipe_1.stageOut.addRes.absWithSym
    val sign = pipe_1.stageOut.addRes.resize(addResSize-1).sign
    val abs  = UInt(addResSize-1 bit)
    //  TO DO
    // val exp  = pipe_1.stageOut.Max +^ 4 - diff
    
    abs := (sign ? ~pipe_1.stageOut.addRes | pipe_1.stageOut.addRes).asUInt.resize(addResSize-1) + sign.asUInt

    // Inside logic
    stageModule.leadingZeros.io.i := abs.asBits
    // 不确定位宽是否正确
    val diff = stageModule.leadingZeros.io.o
    val exp_  = pipe_1.stageOut.Max +^ 4 - diff
    val stageOut = ({new Bundle{
      val sign = Bool
      val exp = UInt(exp_.getWidth bits)
      val shifterResult = UInt(shiftConfig.dataOutWidth bits)
      val hasFlag = FPHasFlag()
    }})
    stageOut.exp := exp_
    // val exp  = pipe_1.stageOut.Max +^ 4 - diff
    // 要补码实现
    stageModule.leftShifter.io.i.X(0) := abs
    
    stageModule.leftShifter.io.i.Diff(0) := (exp_ <=0) ? diff | diff+1
    stageOut.sign := sign
    // stageOut.exp  := exp
    stageOut.hasFlag := pipe_1.stageOut.hasFlag
    stageOut.shifterResult:= stageModule.leftShifter.io.o.Y(0)

    // Output of Pipe
  }
  var pipe_3 = new Area{
    
    val stageModule = new Area{
      val round        = new Round(fpConfig.mantSize)
      val correct      = new Correct(fpConfig)
    }
    val stageOut = Reg({new Bundle{
      val Y = FP(fpConfig)
    }})
    val sign = pipe_2.stageOut.sign
    val exp  = pipe_2.stageOut.exp
    stageModule.round.io.i := pipe_2.stageOut.shifterResult
    stageModule.correct.io.i.hasCarry := exp.asBits.resizeLeft(1).asBools(0)
    stageModule.correct.io.i.hasFlag  := pipe_2.stageOut.hasFlag
    stageModule.correct.io.i.X.sign := sign
    stageModule.correct.io.i.X.exp  := exp.asBits.resize(fpConfig.expSize).asUInt
    stageModule.correct.io.i.X.mant := stageModule.round.io.o
    stageOut.Y := stageModule.correct.io.o.Y
  }
io.o.Y := pipe_3.stageOut.Y

}
// sbt "runMain veetpu.array.floatingaddertree.FloatingAdderTree_Verilog"

object FloatingAdderTree_Nobuffer_Verilog {
  def main(args: Array[String]): Unit = {
    val fpatConfig = FPATConfig(
                      fpConfig = FPConfig(11, 53), 
                      size     = 16,
                      accuracy = 0,
                      adderTree_CLSA_PRE_WIDTH = 5
                      )

    val path = "simWorkspace/FloatingAdderTree_Nobuffer/rtl"
    java.nio.file.Files.createDirectories(java.nio.file.Paths.get(path))
    val report = SpinalConfig(
      mode=Verilog,
      targetDirectory=path
    ).generate(new FloatingAdderTree_Nobuffer(fpatConfig))
    report.mergeRTLSource(path+"/mergeRTL") // Merge all rtl sources into mergeRTL.vhd and mergeRTL.v files
  }
}
