package veetpu.stage

import spinal.core._
import spinal.lib._
import fp._

object Stage {
  def apply(isStage: Boolean,data: Bundle): Data = {
    if(isStage){
      return Reg(data)
    }
    data
  }

  //def apply[T <: SpinalEnum](enumType: T): enumType.C = Reg(enumType())
}
class aaa extends Component{
  val fpConfig = FPConfig(8, 23)

  val io = new Bundle{
    val i = new Bundle{
      val X = in (FP(fpConfig))
    }
    val o = new Bundle{
      val Y = out (FP(fpConfig))
    }
  }
  val stageOut = Reg({new Bundle{
      val test = (FP(fpConfig))
    }})
  stageOut.test := io.i.X
  io.o.Y := stageOut.test
}
object aaa_Verilog {
  def main(args: Array[String]): Unit = {
    SpinalConfig(mode=Verilog)
          .generate(new aaa)
  }
}


