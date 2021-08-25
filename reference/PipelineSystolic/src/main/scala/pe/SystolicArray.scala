package pe

import spinal.core._
import spinal.lib._

class ArrayConfig (
  val size_X: Int,
  val size_W: Int,
  val M: Int,
  val N: Int,
  // "None" "Tradition" "MyDesign"
  val pipelineType: String
){
  private val cellConfig_N = new CellConfig(
    size_X = size_X,
    size_W = size_W,
    n      = N-1,
    pipelineType = pipelineType
  )
  val sizeYout_N = cellConfig_N.sizeYout
  override def toString() : String = {
    return "_" + size_X + "_" + size_W + "_" + M + "_" + N + "_" + pipelineType
  }
}

//Hardware definition
class SystolicArray(config: ArrayConfig) extends Component {
  import config._
  private def getY(sizeY :Array[Int])  : Array[UInt] = {
    val array = new Array[UInt](sizeY.length)
    for (i <- 0 to sizeY.length-1) {
      array(i) = UInt(sizeY(i) bits)
    }
    return array
  }

  val io = new Bundle {
    val Xin = in Vec(UInt(size_X bits), N)
    val Win = in Vec(Vec(UInt(size_W bits), N), M)
    val Yout = out Vec(Vec(getY(sizeYout_N)), M)
  }
  val systolicArray = Array.tabulate(M,N)((m,n) => {
    val config = new CellConfig(
      size_X = size_X,
      size_W = size_W,
      n      = n,
      pipelineType = pipelineType
    )
    new SystolicCell(config)
  })
  for (m <- 0 to M-1) {
    for (n <- 0 to N-1) {
      // for Win
      systolicArray(m)(n).io.Win := io.Win(m)(n)
      // for Yin Yout
      if (n==0){
      } else {
        systolicArray(m)(n).io.Yin := systolicArray(m)(n-1).io.Yout
      }
      if (n==N-1){
        io.Yout(m) := systolicArray(m)(n).io.Yout
      }
      // for A/B in out
      if (m==0){
        systolicArray(m)(n).io.Xin := io.Xin(n)
      } else {
        systolicArray(m)(n).io.Xin := systolicArray(m-1)(n).io.Xout
      }
    }
  }
}

//sbt "runMain pe.SystolicArrayVerilog"
object SystolicArrayVerilog {
  def main(args: Array[String]) {
    val config = new ArrayConfig(
        size_X = 2,
        size_W = 2,
        M      = 2,
        N      = 256,
        pipelineType = "MyDesign"
      )
    val path = "simWorkspace/SystolicArray"+config+"/rtl"
    java.nio.file.Files.createDirectories(java.nio.file.Paths.get(path))
    SpinalConfig(
      mode=Verilog,
      targetDirectory=path
    ).generate(new SystolicArray(config))
  }
}

