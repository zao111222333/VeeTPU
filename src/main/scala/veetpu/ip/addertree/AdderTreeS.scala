package veetpu.ip

import spinal.core._
import spinal.lib._

// sbt "runMain veetpu.ip.AdderTreeS_COMPLIE"
class SUM(dataWidth: Int, LOG_NUM: Int) extends Component {
  val INPUT_NUM: Int = (1 << LOG_NUM)
  val io = new Bundle {
    val x = in Vec(SInt(dataWidth bits), INPUT_NUM)
    val r = out SInt(dataWidth+LOG_NUM bits)
  }
  noIoPrefix()
  if (LOG_NUM==0){
    io.r := io.x(0)
  }else{
    val AdderSum = Vec(Array.tabulate(LOG_NUM)((m) => {
      val n:Int = 1 << (LOG_NUM-m-1)
      Vec(SInt(dataWidth+m+1 bits),n)
    }))
    for (i <- 0 to LOG_NUM-1){
      val n:Int = 1 << (LOG_NUM-i-1)
      for (k <- 0 to n-1) {
        AdderSum(i)(k) := (if (i==0) (io.x(2*k)+^io.x(2*k+1)) else (AdderSum(i-1)(2*k)+^AdderSum(i-1)(2*k+1)))
      }
    }
    io.r := AdderSum(LOG_NUM-1)(0)
  }
}

class AdderTreeS(dataWidth: Int = 53,size: Int = 16) extends Component {
  val compWidth = log2Up(size)+1
  val fullWidth = dataWidth+compWidth
  val io=new Bundle{
    val i = new Bundle {
      val abs  = in Vec(UInt(dataWidth bits), size)
      val sign = in Vec(Bool, size)
    }
    val o = new Bundle {
      val sum  = out SInt(fullWidth bits)
    }
  }
  noIoPrefix()
  val sim = Reg(Bool)
  val sumModule = new SUM(dataWidth+1,log2Up(size))
  Array.tabulate(size)((m) => {
    println(m)
    sumModule.io.x(m) := io.i.abs(m).twoComplement(io.i.sign(m))
  })
  io.o.sum := sumModule.io.r
}
object AdderTreeS_COMPLIE {
  def main(args: Array[String]): Unit = {
    val path = "simWorkspace/AdderTreeS/rtl"
    java.nio.file.Files.createDirectories(java.nio.file.Paths.get(path))
    val report = SpinalConfig(
      mode=Verilog,
      targetDirectory=path
    ).generate(new AdderTreeS(11,16))
    report.mergeRTLSource(path+"/mergeRTL")
    report.printPruned
  }
}