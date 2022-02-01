package veetpu.array

import spinal.core._
import spinal.lib._
// mill runMain veetpu.array.SystolicReg_Verilog
// import spinal.lib.experimental.math._
import ip._
import fp._
import veetpu.array.pe.PE_16in_top

class Systolic(systolicConfig: SystolicConfig) extends Component{
  import systolicConfig._
  val ctl = new Bundle{
    val modeSel     = in Vec(Bits(2 bits),yVectorLength)
    val modeOut     = out Vec(Bits(2 bits),yVectorLength)
    val wAddr       = in UInt(log2Up(yVectorLength) bits)
    val wEn         = in Bool()
  }
  val io = new Bundle{
    val i = new Bundle{
      val dataA = in Vec(Bits(dataAWidth bits), xVectorLength)
      val dataB = in Vec(Bits(dataBWidth bits), xVectorLength)
    }
    val o = new Bundle{
      val result = out Vec(Bits(outWidth bits), yVectorLength)
    }
  }
  val bufferReg = new SystolicReg(systolicConfig)
  bufferReg.io.i.assignAllByName(io.i)
  bufferReg.ctl.wAddr := ctl.wAddr
  bufferReg.ctl.wEn   := ctl.wEn
  val peVec = Array.tabulate(xVectorLength,yVectorLength)((xl,yl) => {
    def gen_pe:PE_16in_top = {
      val pe = new PE_16in_top
      pe.io.A := bufferReg.io.o.dataA(xl)(yl)
      pe.io.B := bufferReg.io.o.dataB(xl)(yl)
      pe.io.mode_sel := ctl.modeSel(yl)
      pe
    }
    gen_pe
  })
  Array.tabulate(yVectorLength)((yl) => {
    io.o.result(yl) := peVec(0)(yl).io.result
    ctl.modeOut(yl) := peVec(0)(yl).io.mode_out
  })
}

class Systolic_TOP(systolicConfig: SystolicConfig) extends Component{
  import systolicConfig._
  val ctl = new Bundle{
      val modeSel     = in Bits(2 bits)
      // val wAddr       = in UInt(log2Up(xVectorLength) bits)
      // val wEn         = in Bool()
  }
  val io = new Bundle{
    val i = new Bundle{
      val dataA = in Vec(Bits(dataAWidth bits), xVectorLength)
      val dataB = in Vec(Bits(dataBWidth bits), xVectorLength)
    }
    val o = new Bundle{
      val result = out Vec(Bits(outWidth bits), yVectorLength)
    }
  }
  val systolic = new Systolic(systolicConfig)
  val regModeSel = Array.tabulate(yVectorLength)((yl) => { if (yl==0) Bits(2 bits) else Reg(Bits(2 bits)) })
  Array.tabulate(yVectorLength)((yl) => {
    regModeSel(yl) := (if (yl==0) ctl.modeSel else regModeSel(yl-1) )
    systolic.ctl.modeSel(yl) := regModeSel(yl)
  })
  val regWAddr = Reg(UInt(log2Up(yVectorLength) bits)) init(0)
  regWAddr := (if (regWAddr == (yVectorLength-1)) U(0) else (regWAddr+1) )
  systolic.ctl.wAddr := regWAddr
  systolic.ctl.wEn   := True
  systolic.io.i.assignAllByName(io.i)
  io.o.assignAllByName(systolic.io.o)
}
object Systolic_Verilog {
  def main(args: Array[String]): Unit = {
    val systolicConfig = SystolicConfig(
          xVectorLength =1,
          yVectorLength =4,
          dataAWidth    =256,
          dataBWidth    =256,
          outWidth      =64,
          addPipeLength =1
                      )
    val path = "simWorkspace/Systolic"+systolicConfig+"/rtl"
    java.nio.file.Files.createDirectories(java.nio.file.Paths.get(path))
    val report = SpinalConfig(
      mode=Verilog,
      targetDirectory=path,
      oneFilePerComponent=true,
      defaultConfigForClockDomains = ClockDomainConfig( resetKind = ASYNC,
                                                        clockEdge = RISING,
                                                        resetActiveLevel = LOW),
      // netlistFileName="Systolic_16.v"
    ).generate(new Systolic_TOP(systolicConfig))
    report.mergeRTLSource(path+"/mergeRTL") // Merge all rtl sources into mergeRTL.vhd and mergeRTL.v files
  }
}
