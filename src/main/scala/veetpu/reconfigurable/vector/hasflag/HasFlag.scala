package veetpu.reconfigurable.vector

import spinal.core._
import spinal.lib._
import fp._
// sbt "runMain veetpu.array.floatingaddertree.FloatingAdderTree_Verilog"
case class FPHasFlag() extends Bundle {
    val hasPInf = Bool
    val hasNInf = Bool
    val hasQNaN = Bool
    val hasSNaN = Bool
}

class HasFlag(size: Int,fpConfig: FPConfig) extends Component{
  val io = new Bundle{
    val i = new Bundle{
      val X = in Vec(FP(fpConfig),size)
    }
    val o = new Bundle{
      val hasFlag = out (FPHasFlag())
      val isDenoOrZero = out Vec(Bool,size)
    }
  }
  val flag = Vec(FPFlag(), size)
  val hasPInf_ = Bits(size bits)
  val hasNInf_ = Bits(size bits)
  val hasQNaN_ = Bits(size bits)
  val hasSNaN_ = Bits(size bits)
  for (m <- 0 to size-1){
    flag(m)  := io.i.X(m).getFlag
    hasPInf_(m) := flag(m).isInfi &&  io.i.X(m).sign
    hasNInf_(m) := flag(m).isInfi && !io.i.X(m).sign
    hasQNaN_(m) := flag(m).isQNaN
    hasSNaN_(m) := flag(m).isSNaN
    io.o.isDenoOrZero(m) := flag(m).isDeno|flag(m).isZero
  }
  io.o.hasFlag.hasPInf := hasPInf_.orR
  io.o.hasFlag.hasNInf := hasNInf_.orR
  io.o.hasFlag.hasQNaN := hasQNaN_.orR || (io.o.hasFlag.hasNInf && io.o.hasFlag.hasPInf)
  io.o.hasFlag.hasSNaN := hasSNaN_.orR
}