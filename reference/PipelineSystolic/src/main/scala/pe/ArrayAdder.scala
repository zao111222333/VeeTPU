package pe

import spinal.core._
import spinal.lib._

import scala.util.Random

//Hardware definition
class ArrayAdder(size_A: Int, size_B: Int, size_S: Int) extends Component{
  val io = new Bundle{
    val A = in UInt(size_A bits)
    val B = in UInt(size_B bits)
    val S = out UInt(size_S bits)      //result = a + b
    val Cout = out Bool
  }
  var c = False                   //Carry, like a VHDL variable
  val sim = Reg(Bool)
  for (i <- 0 until size_S) {
    //Create some intermediate value in the loop scope.
    val a = if (size_A > i) io.A(i) else False
    val b = if (size_B > i) io.B(i) else False

    //The carry adder's asynchronous logic
    io.S(i) := a ^ b ^ c
    c \= (a & b) | (a & c) | (b & c);    //variable assignment
  }
  io.Cout := c
}

// sbt "runMain pe.ArrayAdderVerilog"
object ArrayAdderVerilog {
  def main(args: Array[String]) {
    SpinalVerilog(new ArrayAdder(4,1,5))
  }
}

// source ~/.syn.sh ArrayAdder -pl ArrayAdder.v