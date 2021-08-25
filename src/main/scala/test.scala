package test

import spinal.core._
import spinal.lib._

class test() extends Component{
    val pipelined = true
  def delayed[T <: Data](signal: T) = if(pipelined) RegNext(signal) else signal

  val io = new Bundle{
    val i = new Bundle{
      val x = in Bits(2 bits)
    }
    val o = delayed(new Bundle{
      val y = out Bits(2 bits)
    })
  }
  val i = delayed(io.i)
  noIoPrefix()
  io.o.y := i.x
}

object test_sim {
  def main(args: Array[String]): Unit = {
    val report = SpinalConfig(
      mode=Verilog
    ).generate(new test)
  }
}
