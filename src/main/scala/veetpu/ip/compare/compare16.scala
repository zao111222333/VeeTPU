package veetpu.ip

import spinal.core._
import spinal.lib._

class compare2(dataWidth:Int) extends BlackBox {
  addGeneric("dataWidth",dataWidth)
  val io=new Bundle{
    val i = new Bundle {
      val X  = in Vec(UInt (dataWidth bit), 2)
    }
    val o = new Bundle {
      val Max = out UInt (dataWidth bit)
    }
  }
  noIoPrefix()
  val PATH:String = "./src/main/verilog/veetpu/ip/compare/"
  addRTLPath(PATH+"compare2.v")
  // when(io.i.X(0).asUInt >= io.i.X(1).asUInt){
  //   io.o.Max := io.i.X(0)
  // }.otherwise{
  //   io.o.Max := io.i.X(1)
  // }
}

class compare2_diff(dataWidth:Int) extends Component {
  
  val io=new Bundle{
    val i = new Bundle {
      val X  = in Vec(UInt (dataWidth bit), 2)
    }
    val o = new Bundle {
      val Max = out UInt (dataWidth bit)
      val Diff = out Vec(UInt (dataWidth bit), 2)
    }
  }
  noIoPrefix()

  val compareArray = new compare2(dataWidth)
  compareArray.io.i.X := io.i.X
  io.o.Max := compareArray.io.o.Max

  io.o.Diff(0) := compareArray.io.o.Max - io.i.X(0)
  io.o.Diff(1) := compareArray.io.o.Max - io.i.X(1)


}


class compare16(dataWidth:Int) extends Component {
  
  val io=new Bundle{
    val i = new Bundle {
      val X  = in Vec(UInt (dataWidth bit), 16)
    }
    val o = new Bundle {
      val Max = out UInt (dataWidth bit)
      val Diff = out Vec(UInt (dataWidth bit), 16)
    }
  }
  noIoPrefix()
  val sim = Reg(Bool)

  val compareArray = Array.tabulate(4)((n) => {
    def gen_compare_line(m:Int): Array[compare2] = {
      val compare_line = Array.tabulate(m)((m) => {
        def gen_compare: compare2 = {
          val compare = new compare2(dataWidth)
          return compare
        }
        gen_compare
      })
      return compare_line
    }
    gen_compare_line(scala.math.pow(2,3-n).toInt)
  })
  
  for((compare_line,i) <- compareArray.view.zipWithIndex) {
    for((compare,j) <- compare_line.view.zipWithIndex) {
      if (i==0){
        compareArray(i)(j).io.i.X(0) := io.i.X(2*j)
        compareArray(i)(j).io.i.X(1) := io.i.X(2*j+1)
      } else{
        compareArray(i)(j).io.i.X(0) := compareArray(i-1)(j*2).io.o.Max
        compareArray(i)(j).io.i.X(1) := compareArray(i-1)(j*2+1).io.o.Max
      }
    }
  }
  io.o.Max := compareArray(3)(0).io.o.Max
  for(i <- 0 to 16-1){
    io.o.Diff(i) := compareArray(3)(0).io.o.Max - io.i.X(i)
  }


}

object compare16_COMPLIE {
  def main(args: Array[String]): Unit = {
    val path = "simWorkspace/compare16/rtl"
    java.nio.file.Files.createDirectories(java.nio.file.Paths.get(path))
    val report = SpinalConfig(
      mode=Verilog,
      targetDirectory=path
    ).generate(new compare16(11))
    report.mergeRTLSource(path+"/mergeRTL") // Merge all rtl sources into mergeRTL.vhd and mergeRTL.v files
  }
}
