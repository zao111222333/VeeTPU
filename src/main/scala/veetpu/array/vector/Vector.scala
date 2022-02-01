package veetpu.array

import spinal.core._
import spinal.lib._
// sbt "runMain veetpu.array.SystolicReg_Verilog"
// import spinal.lib.experimental.math._
import ip._
import fp._

class Vector(vecSize: Int=16) extends Component{
  val fpatConfig = floatingaddertree.FPATConfig(
                      fpConfig = FPConfig.FP64, 
                      size     = vecSize,
                      accuracy = 0,
                      adderTree_CLSA_PRE_WIDTH = 5
                      )
  import fpatConfig._
  val ctl = new Bundle{
      val mode_sel     = in Bits(2 bits)
  }
  val io = new Bundle{
    val i = new Bundle{
      val input = in Vec(Bits(256 bits),vecSize)
      val weight = in Vec(Bits(256 bits),vecSize)
    }
    val o = new Bundle{
      val vecOut = out (FP(fpConfig))
      // val mode_sel = out Vec(Bits(2 bits),vecNum)
    }
  }
  val peVec = Array.tabulate(vecSize)((s) => {new pe.PE_16in_top})
  val fpAddTree = new floatingaddertree.MultiFloatingAdderTree(fpatConfig)
  Array.tabulate(vecSize)((s) => {
    peVec(s).io.mode_sel := ctl.mode_sel
    peVec(s).io.A := io.i.input(s)
    peVec(s).io.B := io.i.weight(s)
    fpAddTree.io.i.X(s) := FP(fpConfig, peVec(s).io.result)
  })
  fpAddTree.ctl.mode_sel := peVec(0).io.mode_out
  io.o.vecOut := fpAddTree.io.o.Y
}

object Vector_Verilog {
  def main(args: Array[String]): Unit = {
    val path = "simWorkspace/Vector/rtl"
    java.nio.file.Files.createDirectories(java.nio.file.Paths.get(path))
    val report = SpinalConfig(
      mode=Verilog,
      targetDirectory=path,
      oneFilePerComponent=true
    ).generate(new Vector(16))
    report.mergeRTLSource(path+"/mergeRTL") // Merge all rtl sources into mergeRTL.vhd and mergeRTL.v files
  }
}
