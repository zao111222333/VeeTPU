package veetpu.array

import spinal.core._
import spinal.lib._
// sbt "runMain veetpu.array.SystolicReg_Verilog"
// import spinal.lib.experimental.math._
import ip._
import fp._

class SystolicRegNew(config: SystolicConfig) extends Component{
  import config._
  val ctl = new Bundle{
    val i = new Bundle{
      val wEn   = in Bool()
      val wAddr = in UInt(log2Up(yVectorLength) bits)
      val mode  = in Bits(2 bits)
    }
    val o = new Bundle{
      val mode = out Vec(Vec(Bits(2 bits), yVectorLength), xVectorLength)
    }
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
  val isFP64 = ctl.i.mode === M"11"
  val isFP32 = ctl.i.mode === M"10"
  val isFP16 = ctl.i.mode === M"00"
  val aFP64IN = Vec(Bits( 64 bits), 4)
  val bFP64IN = Vec(Bits( 64 bits), 4)
  val aFP32IN = Vec(Bits(128 bits), 2)
  val bFP32IN = Vec(Bits(128 bits), 2)
  val aFP16IN = Vec(Bits(256 bits), 1)
  val bFP16IN = Vec(Bits(256 bits), 1)
  Array.tabulate(4)((i) => { 
    aFP64IN(i) := io.i.dataA(0)(Range(64*i, 64*(i+1)))
    bFP64IN(i) := io.i.dataB(0)(Range(64*i, 64*(i+1)))
  })
  Array.tabulate(2)((i) => { 
    aFP32IN(i) := io.i.dataA(0)(Range(128*i, 128*(i+1)))
    bFP32IN(i) := io.i.dataB(0)(Range(128*i, 128*(i+1)))
  })
  aFP16IN(0) := io.i.dataA(0)
  bFP16IN(0) := io.i.dataB(0)
  val aBuffer = Array.tabulate(xVectorLength,yVectorLength)((xl,yl) => { 
    val aDate = Bits(256 bits)
    val aWEn  = Bool()
    when(isFP64) {
      aWEn  := ctl.i.wAddr===U(yl%4)
      aDate := aFP64IN(yl/4).resize(256)
    }.elsewhen(isFP32) {
      aWEn  := ctl.i.wAddr===U(yl%8)
      aDate := aFP32IN(yl/8).resize(256)
    }.elsewhen(isFP16){
      aWEn  := ctl.i.wAddr===U(yl%16)
      aDate := aFP16IN(yl/16).resize(256)
    }.otherwise {
      aWEn  := ctl.i.wAddr===U(yl%16)
      aDate := aFP16IN(yl/16).resize(256)
    }
    RegNextWhen(aDate, aWEn & ctl.i.wEn)
  })
  val bBuffer    = Array.tabulate(xVectorLength,yVectorLength)((xl,yl) => { Reg(Bits(dataBWidth bits)) })
  val modeBuffer = Array.tabulate(xVectorLength,yVectorLength)((xl,yl) => { Reg(Bits(2 bits)) })
  Array.tabulate(xVectorLength,yVectorLength)((xl,yl) => {
    val bDate = Bits(256 bits)
    val mode  = Bits(  2 bits)
    when(isFP64){
      bDate := (if(yl%4 ==0) bFP64IN(yl/16).resize(256) else bBuffer(0)(yl-1))
      mode  := (if(yl%4 ==0) ctl.i.mode else modeBuffer(0)(yl-1))
    }.elsewhen(isFP32){
      bDate := (if(yl%8 ==0) bFP32IN(yl/8).resize(256) else bBuffer(0)(yl-1))
      mode  := (if(yl%8 ==0) ctl.i.mode else modeBuffer(0)(yl-1))
    }.elsewhen(isFP16){
      bDate := (if(yl%16==0) bFP16IN(yl/16).resize(256) else bBuffer(0)(yl-1))
      mode  := (if(yl%16==0) ctl.i.mode else modeBuffer(0)(yl-1))
    }.otherwise{
      bDate := (if(yl%16==0) bFP16IN(yl/16).resize(256) else bBuffer(0)(yl-1))
      mode  := (if(yl%16==0) ctl.i.mode else modeBuffer(0)(yl-1))
    }
    bBuffer(0)(yl)    := bDate
    modeBuffer(0)(yl) := mode
  })
  Array.tabulate(xVectorLength,yVectorLength)((xl,yl) => {
    io.o.dataA(xl)(yl) := aBuffer(xl)(yl)
    io.o.dataB(xl)(yl) := bBuffer(xl)(yl)
    ctl.o.mode(xl)(yl) := modeBuffer(xl)(yl)
  })
}
object SystolicRegNew_Verilog {
  def main(args: Array[String]): Unit = {
    val config = SystolicConfig(
          xVectorLength =1,
          yVectorLength =16,
          dataAWidth    =256,
          dataBWidth    =256,
          addPipeLength =1
                      )
    val path = "simWorkspace/SystolicRegNew"+config+"/rtl"
    java.nio.file.Files.createDirectories(java.nio.file.Paths.get(path))
    val report = SpinalConfig(
      mode=Verilog,
      targetDirectory=path,
      oneFilePerComponent=true,
      // netlistFileName="Systolic_16.v"
    ).generate(new SystolicRegNew(config))
    report.mergeRTLSource(path+"/mergeRTL") // Merge all rtl sources into mergeRTL.vhd and mergeRTL.v files
    report.printPruned
  }
}