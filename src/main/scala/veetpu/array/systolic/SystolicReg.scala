package veetpu.array

import spinal.core._
import spinal.lib._
// sbt "runMain veetpu.array.SystolicReg_Verilog"
// import spinal.lib.experimental.math._
import ip._
import fp._

case class SystolicConfig(
          xVectorLength: Int=16,
          yVectorLength: Int=16,
          dataAWidth:    Int=256,
          dataBWidth:    Int=256,
          outWidth:      Int=64,
          addPipeLength: Int=1
){
  override def toString() : String = {
    return "_"+xVectorLength+"_"+yVectorLength+"_"+dataAWidth+"_"+dataBWidth+"_"+addPipeLength
  }
}

class SystolicReg(systolicConfig: SystolicConfig) extends Component{
  import systolicConfig._
  val ctl = new Bundle{
    val wAddr       = in UInt(log2Up(yVectorLength) bits)
    val wEn         = in Bool()
  }
  val io = new Bundle{
    val i = new Bundle{
      val dataA = in Vec(Bits(dataAWidth bits), xVectorLength)
      val dataB = in Vec(Bits(dataBWidth bits), xVectorLength)
    }
    val o = new Bundle{
      val dataA = out Vec(Vec(Bits(dataAWidth bits), yVectorLength), xVectorLength)
      val dataB = out Vec(Vec(Bits(dataBWidth bits), yVectorLength), xVectorLength)
    }
  }
  val aBuffer = Array.tabulate(xVectorLength,yVectorLength)((xl,yl) => { RegNextWhen(io.i.dataA(xl), ctl.wAddr===U(yl) & ctl.wEn) })
  val bBuffer = Array.tabulate(xVectorLength,yVectorLength)((xl,yl) => { Vec((if (yl==0) Bits(dataBWidth bits) else Reg(Bits(dataBWidth bits))),addPipeLength) })
  Array.tabulate(xVectorLength,yVectorLength)((xl,yl) => {
    bBuffer(xl)(yl)(0) := (if (yl==0) io.i.dataB(xl) else bBuffer(xl)(yl-1)(addPipeLength-1) )
    Array.tabulate(addPipeLength-1)((apl) => {
      bBuffer(xl)(yl)(apl+1) := bBuffer(xl)(yl)(apl)
    })
  })
  Array.tabulate(xVectorLength,yVectorLength)((xl,yl) => {
    io.o.dataA(xl)(yl) := aBuffer(xl)(yl)
    io.o.dataB(xl)(yl) := bBuffer(xl)(yl)(addPipeLength-1)
  })
}

object SystolicReg_Verilog {
  def main(args: Array[String]): Unit = {
    val systolicConfig = SystolicConfig(
          xVectorLength =1,
          yVectorLength =16,
          dataAWidth    =256,
          dataBWidth    =256,
          addPipeLength =1
                      )
    val path = "simWorkspace/SystolicReg"+systolicConfig+"/rtl"
    java.nio.file.Files.createDirectories(java.nio.file.Paths.get(path))
    val report = SpinalConfig(
      mode=Verilog,
      targetDirectory=path,
      oneFilePerComponent=true,
      // netlistFileName="Systolic_16.v"
    ).generate(new SystolicReg(systolicConfig))
    report.mergeRTLSource(path+"/mergeRTL") // Merge all rtl sources into mergeRTL.vhd and mergeRTL.v files
  }
}
