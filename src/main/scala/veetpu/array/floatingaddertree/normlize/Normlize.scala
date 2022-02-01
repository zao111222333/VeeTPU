package veetpu.array.floatingaddertree

import spinal.core._
import spinal.lib._
import fp._
// sbt "runMain veetpu.array.floatingaddertree.FloatingAdderTree_Verilog"

class Normlize(size: Int,fpConfig: FPConfig) extends Component{
  val io = new Bundle{
    val i = new Bundle{
      val addRes = in 
      val X = in Vec(FP(fpConfig),size)
    }
    val o = new Bundle{
    }
  }
}