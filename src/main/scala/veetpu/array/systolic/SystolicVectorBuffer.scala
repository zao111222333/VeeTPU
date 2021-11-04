package veetpu.array

import spinal.core._
import spinal.lib._
// sbt "runMain veetpu.array.Systolic_Verilog"
// import spinal.lib.experimental.math._
import veetpu.ip._
import veetpu.fp._
// import build
class Vector(vecSize: Int=16) extends Component{
  val fpatConfig = floatingaddertree.FPATConfig(
                      fpConfig = FPConfig.FP64, 
                      size     = vecSize,
                      accuracy = 0,
                      adderTree_CLSA_PRE_WIDTH = 5
                      )
  import fpatConfig._
  val ctl = new Bundle{
      val mode_sel     = in Bits(2 bits)
  }
  val io = new Bundle{
    val i = new Bundle{
      val input = in Vec(Bits(256 bits),vecSize)
      val weight = in Vec(Bits(256 bits),vecSize)
    }
    val o = new Bundle{
      val vecOut = out (FP(fpConfig))
      // val mode_sel = out Vec(Bits(2 bits),vecNum)
    }
  }
  val peVec = Array.tabulate(vecSize)((s) => {new pe.PE_16in_top})
  val fpAddTree = new floatingaddertree.MultiFloatingAdderTree(fpatConfig)
  Array.tabulate(vecSize)((s) => {
    peVec(s).io.mode_sel := ctl.mode_sel
    peVec(s).io.A := io.i.input(s)
    peVec(s).io.B := io.i.weight(s)
    fpAddTree.io.i.X(s) := FP(fpConfig, peVec(s).io.result)
  })
  fpAddTree.ctl.mode_sel := peVec(0).io.mode_out
  io.o.vecOut := fpAddTree.io.o.Y
}

case class SystolicConfig(
          xVectorLength: Int=16, 
          yVectorLength: Int=16, 
          xDataWidth: Int=256, 
          yDataWidth: Int=256
){

}

class SystolicVectorBuffer(systolicConfig: SystolicConfig) extends Component{
  import systolicConfig._
  val ctl = new Bundle{
      val modeSel     = in Vec(Bits(2 bits),xVectorLength)
      val wAddr       = in UInt(log2Up(xVectorLength) bits)
      val wEn         = in Bool
  }
  val io = new Bundle{
    val i = new Bundle{
      val xData = in Vec(Bits(xDataWidth bits), xVectorLength)
      val yData = in Vec(Bits(yDataWidth bits), yVectorLength)
    }
    val o = new Bundle{
      val xData = out Vec(Vec(Bits(xDataWidth bits), xVectorLength), yVectorLength)
      val yData = out Vec(Vec(Bits(yDataWidth bits), xVectorLength), yVectorLength)
    }
  }
  val xBuffer = Array.tabulate(xVectorLength,yVectorLength)((n,s) => { RegNextWhen(io.i.weight(s), ctl.w_addr===U(n) & ctl.w_en) })
  val inputRegs  = Array.tabulate(vecNum,vecSize)((n,s) => { (if (n==0) Bits(256 bits) else Reg(Bits(256 bits))) })
  Array.tabulate(vecNum,vecSize)((n,s) => {
    inputRegs(n)(s) := (if (n==0) io.i.input(n) else inputRegs(n-1)(n) )
  })
  val vecArray = Array.tabulate(vecNum)((n) => {new Vector(vecSize)})
  Array.tabulate(vecNum,vecSize)((n,s) => {
    vecArray(n).io.i.input(s) := inputRegs(n)(s)
    vecArray(n).io.i.weight(s):= weightRegs(n)(s)
  })
  Array.tabulate(vecNum)((n) => {
    vecArray(n).ctl.mode_sel := ctl.mode_sel(n)
    io.o.arrayOut(n) := vecArray(n).io.o.vecOut
  })
}

object Systolic_Verilog {
  def main(args: Array[String]): Unit = {
    val path = "simWorkspace/Systolic/rtl"
    java.nio.file.Files.createDirectories(java.nio.file.Paths.get(path))
    val report = SpinalConfig(
      mode=Verilog,
      targetDirectory=path,
      oneFilePerComponent=true
      // netlistFileName="Systolic_16.v"
    ).generate(new Systolic())
    report.mergeRTLSource(path+"/mergeRTL") // Merge all rtl sources into mergeRTL.vhd and mergeRTL.v files
  }
}
