package pe

import spinal.core._
import spinal.lib._

import scala.util.Random

class FullAdder extends Component {
  // Declaring external ports in a Bundle called `io` is recommended
  val io = new Bundle {
    val a, b, cin = in Bool
    val sum, cout = out Bool
  }
  // Do some logic
  io.sum := io.a ^ io.b ^ io.cin
  io.cout := (io.a & io.b) | (io.a & io.cin) | (io.b & io.cin)
}

//Hardware definition
// https://zhuanlan.zhihu.com/p/139173424
// https://zhuanlan.zhihu.com/p/119444283
// https://www.icourse163.org/course/HUST-1205809816
// SpinalTemplateSbt/src/main/scala/mylib/ArrayMultiplier.jpg
class ArrayMultiplier(size_X: Int, size_Y: Int) extends Component{
  val size_P: Int = size_X + size_Y
  val io = new Bundle{
    val X = in  UInt(size_X bits)
    val Y = in  UInt(size_Y bits)
    val P = out UInt(size_P bits)      // P = X * Y
  }

  if (size_X==2){
    io.P := io.X * io.Y
  }else{
    val xmax = size_X-1
    val ymax = size_Y
    val fullAdder = Array.fill(xmax,ymax)(new FullAdder)
    
    io.P(0) := io.X(0) & io.Y(0)
    
    for (y <- 0 to ymax-1) {
      for (x <- 0 to xmax-1) {
        if(x==0){
          if(y==0){
            fullAdder(x)(y).io.a   := io.X(x+1) & io.Y(y)
            fullAdder(x)(y).io.b   := io.X(x) & io.Y(y+1)
            fullAdder(x)(y).io.cin := False
            io.P(x+y+1) := fullAdder(x)(y).io.sum
          }else if(y==ymax-1){
            fullAdder(x)(y).io.a   := fullAdder(x+1)(y-1).io.sum
            fullAdder(x)(y).io.b   := False
            fullAdder(x)(y).io.cin := fullAdder(x)(y-1).io.cout
            io.P(x+y+1) := fullAdder(x)(y).io.sum
          }else {
            fullAdder(x)(y).io.a   := fullAdder(x+1)(y-1).io.sum
            fullAdder(x)(y).io.b   := io.X(x) & io.Y(y+1)
            fullAdder(x)(y).io.cin := fullAdder(x)(y-1).io.cout
            io.P(x+y+1) := fullAdder(x)(y).io.sum
          }
        }else if(x==xmax-1){
          if(y==0){
            fullAdder(x)(y).io.a   := io.X(x+1) & io.Y(y)
            fullAdder(x)(y).io.b   := io.X(x) & io.Y(y+1)
            fullAdder(x)(y).io.cin := False
          }else if(y==ymax-1){
            fullAdder(x)(y).io.a   := io.X(x+1) & io.Y(y)
            fullAdder(x)(y).io.b   := fullAdder(x-1)(y).io.cout
            fullAdder(x)(y).io.cin := fullAdder(x)(y-1).io.cout
            io.P(x+y+1) := fullAdder(x)(y).io.sum
            io.P(x+y+2) := fullAdder(x)(y).io.cout
          }else {
            fullAdder(x)(y).io.a   := io.X(x+1) & io.Y(y)
            fullAdder(x)(y).io.b   := io.X(x) & io.Y(y+1)
            fullAdder(x)(y).io.cin := fullAdder(x)(y-1).io.cout
          }
        }else {
          if(y==0){
            fullAdder(x)(y).io.a   := io.X(x+1) & io.Y(y)
            fullAdder(x)(y).io.b   := io.X(x) & io.Y(y+1)
            fullAdder(x)(y).io.cin := False
          }else if(y==ymax-1){
            fullAdder(x)(y).io.a   := fullAdder(x+1)(y-1).io.sum
            fullAdder(x)(y).io.b   := fullAdder(x-1)(y).io.cout
            fullAdder(x)(y).io.cin := fullAdder(x)(y-1).io.cout
            io.P(x+y+1) := fullAdder(x)(y).io.sum
          }else {
            fullAdder(x)(y).io.a   := fullAdder(x+1)(y-1).io.sum
            fullAdder(x)(y).io.b   := io.X(x) & io.Y(y+1)
            fullAdder(x)(y).io.cin := fullAdder(x)(y-1).io.cout
          }
        }
      }
    }
  }
}
// sbt "runMain pe.ArrayMultiplierVerilog"
object ArrayMultiplierVerilog {
  def main(args: Array[String]) {
    SpinalVerilog(new ArrayMultiplier(4,4))
  }
}