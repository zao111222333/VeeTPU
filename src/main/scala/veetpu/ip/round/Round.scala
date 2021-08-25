package veetpu.ip

import spinal.core._
import spinal.lib._
// sbt "runMain veetpu.array.floatingaddertree.FloatingAdderTree_Verilog"

class Round(dataWidth: Int) extends Component{
  val io = new Bundle{
    val i = in  UInt(dataWidth+4 bits)
    val o = out UInt(dataWidth   bits)
  }
  io.o := io.i.roundToInf(4 bits, align = false).sat(1) //  ---+
  // val bitsToBeRounded = io.i.resize(5)
  // val bitRounded = UInt(1 bits)
  // //00000    -> 0
  // //01000    -> 0
  // //01100    -> 0
  // //01110 15 -> 0
  // //01111    -> 1
  // when(bitsToBeRounded<=15) {
  //   bitRounded := U"1'b0"
  // }otherwise{
  //   bitRounded := U"1'b1"
  // }
  // io.o := (io.i.asBits.resizeLeft(dataWidth-1) ## bitRounded).asUInt
}