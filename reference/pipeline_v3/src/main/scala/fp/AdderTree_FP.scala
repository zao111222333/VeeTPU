package FP

import spinal.core._
import spinal.lib._

class AdderTree_FP(size: Int, fpConfig: FPConfig) extends Component {
  val io = new Bundle {
    val i = new Bundle {
      val X = in Vec(new FP(fpConfig), size)
    }
    val o = new Bundle {
      val S = out (new FP(fpConfig))
    }
  }
  noIoPrefix()

  //w.fromBits(i.X(0))
  //o.S := w.asBits()
  //o.S := i.X(0).asBits()
  io.o.S := io.i.X(0)
  
  
}
// sbt "runMain FP.AdderTree_FP"
object AdderTree_FP {
  def main(args: Array[String]) {
    val fpConfig = FPConfig(
      exponentSize = 11,
      mantissaSize = 52
    )
    val path = "simWorkspace/AdderTree_FP64/rtl"
    java.nio.file.Files.createDirectories(java.nio.file.Paths.get(path))
    SpinalConfig(
      mode=Verilog,
      targetDirectory=path
    ).generate(new AdderTree_FP(16,fpConfig))
  }
}