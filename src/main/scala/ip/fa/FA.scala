package ip

import spinal.core._
import spinal.lib._

//Hardware definition
class FA extends Component{
  val io = new Bundle{
    val i = new Bundle{
      val X = in Vec(Bool, 3)
    }
    val o = new Bundle{
      val carry = out Bool()
      val sum   = out Bool()
    }
  }
  io.o.sum := io.i.X(0) ^ io.i.X(1) ^ io.i.X(2)
  io.o.carry := (io.i.X(0) & io.i.X(1)) | (io.i.X(0) & io.i.X(2)) | (io.i.X(1) & io.i.X(2));    //variable assignment
}

// sbt "runMain ip.ArrayAdderVerilog"
object FAVerilog {
  def main(args: Array[String]) {
    SpinalVerilog(new FA)
  }
}