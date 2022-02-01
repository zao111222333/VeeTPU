package veetpu.reconfigurable.vector

import spinal.core._
import spinal.lib._
import fp._
// sbt "runMain veetpu.array.floatingaddertree.FloatingAdderTree_Verilog"

class Correct(fpConfig: FPConfig) extends Component{
  val io = new Bundle{
    val i = new Bundle{
      val X = in (FP(fpConfig))
      val hasFlag = in (FPHasFlag())
      val hasCarry = in Bool()
    }
    val o = new Bundle{
      val Y = out (FP(fpConfig))
    }
  }
  val comaperExp = UInt(fpConfig.expSize bits)
  comaperExp := (default -> true)                        // Assign comaperExp with "11111111"
  io.o.Y.sign := io.i.X.sign
  when(io.i.hasFlag.hasSNaN){
    io.o.Y.setSNaN
  }.elsewhen(io.i.hasFlag.hasQNaN){
    io.o.Y.setQNaN
  }.elsewhen( (io.i.hasCarry || io.i.X.exp === comaperExp )
          || (io.i.hasFlag.hasPInf ^ io.i.hasFlag.hasNInf)){
    io.o.Y.setInfi
  }.otherwise{
    io.o.Y.exp  := (io.i.X.exp<=0) ? U(0) | io.i.X.exp
    io.o.Y.mant := io.i.X.mant
  }
}