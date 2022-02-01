package veetpu.reconfigurable.vector

import spinal.core._
import spinal.lib._

import ip._
import fp._


case class VecConfig(
  size: Int=0,
  modeWidth: Int = 8
){
  import ModeConfig._
  def modeDef = Array(
//  0001xxxx  0010xxxx  0011xxxx
    ADD_INT8, MUL_INT8, MAC_INT8, // xxxx0000
    ADD_FP16, MUL_FP16, MAC_FP16, // xxxx1000
    ADD_FP32, MUL_FP32, MAC_FP32, // xxxx1001
    ADD_FP64, MUL_FP64, MAC_FP64, // xxxx1010
    ADD_BF16, MUL_BF16, MAC_BF16, // xxxx1100
    ADD_TF32, MUL_TF32, MAC_TF32, // xxxx1101
  )
}

class Vector(config: VecConfig) extends Component{
  import config._

  val ctl = new Bundle{
    val i = new Bundle{
      val mode = in (Mode())
    }
    val o = new Bundle{
      val mode = out (Mode())
    }
  }

  // val io = new Bundle{
  //   val i = new Bundle{
  //     val MUL_A = in Vec(Bits(64 bits), size)
  //     val MUL_B = in Vec(Bits(64 bits), size)
  //     val ADD_A = in Vec(Bits(64 bits),    2)
  //     val ADD_B = in Vec(Bits(64 bits),    2)
  //   }
  //   val o = new Bundle{
  //     val MUL_A = out Vec(Bits(64 bits), size)
  //   }
  // }
  noIoPrefix()
  ctl.o.mode := ctl.i.mode
  // val ADD_FP16 = Mode(ModeConfig.Add_FP16).o
  // val aaa = ADD_FP16.o

}

object Vector_Verilog {
  def main(args: Array[String]): Unit = {
    val vecConfig = VecConfig()

    val path = "simWorkspace/Vector/rtl"
    java.nio.file.Files.createDirectories(java.nio.file.Paths.get(path))
    val report = SpinalConfig(
      mode=Verilog,
      targetDirectory=path
    ).generate(new Vector(vecConfig))
    report.mergeRTLSource(path+"/mergeRTL") // Merge all rtl sources into mergeRTL.vhd and mergeRTL.v files
  }
}