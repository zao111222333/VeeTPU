package veetpu.ip

import spinal.core._
import spinal.lib._
// sbt "runMain veetpu.ip.CSA42_TOP_COMPILE"
class CSA42_UNIT extends BlackBox{
  val io=new Bundle{
    val i = new Bundle {
      val X = in Vec(Bool, 4)
      val c_in = in Bool
    }
    val o = new Bundle {
      val c_out = out Bool 
      val carry = out Bool 
      val sum   = out Bool 
    }
  }
  noIoPrefix()
  //mapClockDomain(clock = io.clk,reset = io.rst)
  val Path:String = "./src/main/verilog/veetpu/ip/csa/"
  addRTLPath(Path+"/CSA42_UNIT.v")
}