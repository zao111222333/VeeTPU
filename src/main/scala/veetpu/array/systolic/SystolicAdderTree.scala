package veetpu.array

import spinal.core._
import spinal.lib._
// sbt "runMain veetpu.array.SystolicReg_Verilog"
// import spinal.lib.experimental.math._
import ip._
import fp._

class SystolicAdderTree(config: SystolicConfig) extends Component{
  import config._
  val ctl = new Bundle{
    val i = new Bundle{
      val mode  = in Bits(2 bits)
    }
    val o = new Bundle{
      val mode = out Bits(2 bits)
    }
  }
  val io = new Bundle{
    val i = new Bundle{
      val result = in Vec(Bits(64 bits), yVectorLength)
    }
    val o = new Bundle{
      val result = out Bits(256 bits)
    }
  }
  val isFP64 = ctl.i.mode === M"11"
  val isFP32 = ctl.i.mode === M"10"
  val isFP16 = ctl.i.mode === M"00"

  val FP64OUT = Vec(Bits(64 bits), 4)
  Array.tabulate( 4)((i) => {
    FP64OUT(i) := io.i.result(i)(Range(0,64))
  })
  val FP32OUT = Vec(Bits(32 bits), 8)
  Array.tabulate( 8)((i) => { 
    FP32OUT(i) := io.i.result(i)(Range(0,32))
  })
  val FP16OUT = Vec(Bits(16 bits),16)
  Array.tabulate(16)((i) => {
    FP16OUT(i) := io.i.result(i)(Range(0,16))
  })
  when(isFP64){
    io.o.result := FP64OUT.asBits
  }.elsewhen(isFP32){
    io.o.result := FP32OUT.asBits
  }.elsewhen(isFP16){
    io.o.result := FP16OUT.asBits
  }.otherwise {
    io.o.result := FP16OUT.asBits
  }
  ctl.o.mode := ctl.i.mode
}

object SystolicAdderTree_Verilog {
  def main(args: Array[String]): Unit = {
    val config = SystolicConfig(
          xVectorLength =1,
          yVectorLength =16,
          dataAWidth    =256,
          dataBWidth    =256,
          addPipeLength =1
                      )
    val path = "simWorkspace/SystolicAdderTree"+config+"/rtl"
    java.nio.file.Files.createDirectories(java.nio.file.Paths.get(path))
    val report = SpinalConfig(
      mode=Verilog,
      targetDirectory=path,
      oneFilePerComponent=true,
      // netlistFileName="Systolic_16.v"
    ).generate(new SystolicAdderTree(config))
    report.mergeRTLSource(path+"/mergeRTL") // Merge all rtl sources into mergeRTL.vhd and mergeRTL.v files
  }
}