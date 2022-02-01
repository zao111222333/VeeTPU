package ip

import spinal.core._
import spinal.lib._

// sbt "runMain ip.AdderTree2S_COMPLIE"

class AdderTree2S(dataWidth: Int = 53, CSLA_PRE_WIDTH: Int) extends Component {
  val size: Int = 2
  // complementSize
  val compWidth = log2Up(size)+1
  val fullWidth = dataWidth+compWidth
  val io=new Bundle{
    val i = new Bundle {
      val abs  = in Vec(UInt(dataWidth bits), size)
      val sign = in Vec(Bool, size)
    }
    val o = new Bundle {
      val sum  = out SInt(fullWidth bits)
      // val abs  = out UInt(fullWidth bits)
      // val sign = out Bool
    }
  }
  noIoPrefix()
  // * * * * * * * * * * * *
  // * * * * * * * * * * * *
  //                       *
  //                       *
  val a = io.i.abs(0).twoComplement(io.i.sign(0))
  val b = io.i.abs(1).twoComplement(io.i.sign(1))
  io.o.sum := a +^ b
}

object AdderTree2S_COMPLIE {
  def main(args: Array[String]): Unit = {
    val path = "simWorkspace/AdderTree2S/rtl"
    java.nio.file.Files.createDirectories(java.nio.file.Paths.get(path))
    val report = SpinalConfig(
      mode=Verilog,
      targetDirectory=path
    ).generate(new AdderTree2S(23,3))
    report.mergeRTLSource(path+"/mergeRTL")
    report.printPruned
  }
}