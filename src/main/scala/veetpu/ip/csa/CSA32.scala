package veetpu.ip

import spinal.core._
import spinal.lib._

// object CSA32{
//   def apply:CSA32=new CSA32
// }

//Hardware definition
class CSA32_UNIT extends Component{
  val io = new Bundle{
    val i = new Bundle{
      val X = in Vec(Bool, 3)
    }
    val o = new Bundle{
      val s = out Bool
      val c = out Bool
    }
  }
  io.o.s := io.i.X(0) ^ io.i.X(1) ^ io.i.X(2)
  io.o.c := (io.i.X(0) & io.i.X(1)) | (io.i.X(0) & io.i.X(2)) | (io.i.X(1) & io.i.X(2));    //variable assignment
}
class CSA32(dataWidth: Int) extends Component{
  val io=new Bundle{
    val i = new Bundle {
      val X = in  Vec(UInt(dataWidth bit), 3)
    }
    val o = new Bundle {
      val Y = out Vec(UInt(dataWidth bit), 2)
    }
  }
  noIoPrefix()
  //mapClockDomain(clock = io.clk,reset = io.rst)
  val csa_unitArray = Array.tabulate(dataWidth)((n) => {new CSA32_UNIT})
  for (n <- 0 to dataWidth-1){
    for (m <- 0 to 3-1) {
      csa_unitArray(n).io.i.X(m) := io.i.X(m)(n)
    }
    io.o.Y(0)(n) := csa_unitArray(n).io.o.s
    io.o.Y(1)(n) := csa_unitArray(n).io.o.c
  }
}