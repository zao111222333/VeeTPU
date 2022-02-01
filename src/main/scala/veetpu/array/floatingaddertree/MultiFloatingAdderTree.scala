package veetpu.array.floatingaddertree

import spinal.core._
import spinal.lib._
// sbt "runMain veetpu.array.floatingaddertree.FloatingAdderTree_Verilog"
// import spinal.lib.experimental.math._
import ip._
import fp._
import veetpu.stage._

class MultiFloatingAdderTree(fpatConfig: FPATConfig) extends Component{
  import fpatConfig._
  val ctl = new Bundle{
    val mode_sel = in Bits(2 bits)
  }
  val io = new Bundle{
    val i = new Bundle{
      val X = in Vec(FP(fpConfig),size)
    }
    val o = new Bundle{
      val Y = out (FP(fpConfig))
    }
  }
  noIoPrefix()
  val fpAddTree = new FloatingAdderTree(fpatConfig)
  
      // FP64 low 16bit -> FP16;
      // convert FP16 to FP64
  Array.tabulate(16)((m) => {
    def fromFPxx(fpxxConfig:FPConfig):FP={
      val bits = io.i.X(m).asBits.resize(fpxxConfig.fullSize)
      val fpxx = FP(fpxxConfig,bits)
      val fp64 = FP(FPConfig.FP64,fpxx)
      fp64
    }
    fpAddTree.io.i.X(m) := ctl.mode_sel.mux(
        // B"00" -> fromFP16
        // ,
        // B"10" -> fromFP16
        // ,
        // B"11" -> fromFP16
        // ,
        // default -> fromFP16
        B"00" -> fromFPxx(FPConfig.FP16)
        ,
        B"10" -> fromFPxx(FPConfig.FP32)
        ,
        B"11" -> fromFPxx(FPConfig.FP64)
        ,
        default -> fromFPxx(FPConfig.FP64)
  
        )
    
  })

  io.o.Y := fpAddTree.io.o.Y

}
// sbt "runMain veetpu.array.floatingaddertree.MultiFloatingAdderTree_Verilog"

object MultiFloatingAdderTree_Verilog {
  def main(args: Array[String]): Unit = {
    val fpatConfig = FPATConfig(
                      fpConfig = FPConfig.FP64, 
                      size     = 16,
                      accuracy = 0,
                      adderTree_CLSA_PRE_WIDTH = 5
                      )

    val path = "simWorkspace/MultiFloatingAdderTree/rtl"
    java.nio.file.Files.createDirectories(java.nio.file.Paths.get(path))
    val report = SpinalConfig(
      mode=Verilog,
      targetDirectory=path
    ).generate(new MultiFloatingAdderTree(fpatConfig))
    report.mergeRTLSource(path+"/mergeRTL") // Merge all rtl sources into mergeRTL.vhd and mergeRTL.v files
  }
}
