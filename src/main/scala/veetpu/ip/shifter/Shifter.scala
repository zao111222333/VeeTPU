package veetpu.ip

import spinal.core._
import spinal.lib._
// sbt "runMain veetpu.array.floatingaddertree.FloatingAdderTree_Verilog"
case class ShifterConfig(
                size         : Int,
                dataInWidth  : Int,
                dataOutWidth : Int,
                diffWidth    :Int
                ) {
}

class LeftShifter(config: ShifterConfig) extends Component{
  import config._
  val io = new Bundle{
    val i = new Bundle{
      val X    = in Vec(UInt(dataInWidth bits),size)
      val Diff = in Vec(UInt(diffWidth bits),size)
    }
    val o = new Bundle{
      val Y = out Vec(UInt(dataOutWidth bits),size)
    } 
  }
  for (m <- 0 to size-1){
      io.o.Y(m) := ((io.i.X(m)).asBits << io.i.Diff(m)).resize(dataInWidth).resizeLeft(dataOutWidth).asUInt
  }
}

class RightShifter(config: ShifterConfig) extends Component{
  import config._
  val io = new Bundle{
    val i = new Bundle{
      val X    = in Vec(UInt(dataInWidth bits),size)
      val Diff = in Vec(UInt(diffWidth bits),size)
    }
    val o = new Bundle{
      val Y = out Vec(UInt(dataOutWidth bits),size)
    } 
  }
  for (m <- 0 to size-1){
      io.o.Y(m) := ((io.i.X(m)).asBits >> io.i.Diff(m)).resizeLeft(dataOutWidth).asUInt
  }
}
// sbt "runMain veetpu.ip.Shifter_Verilog"
object Shifter_Verilog {
  def main(args: Array[String]) {

    //SpinalVerilog(new Shifter())
  }
}