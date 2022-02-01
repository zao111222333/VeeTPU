package ip

import spinal.core._
import spinal.lib._
// sbt "runMain ip.compare_COMPLIE"
class compare(dataWidth: Int, LOG_NUM: Int) extends Component {
  val INPUT_NUM: Int = (1 << LOG_NUM)
  val io = new Bundle {
    val x   = in  Vec(UInt(dataWidth bit), INPUT_NUM)
    val max = out UInt(dataWidth bits)
  }
  noIoPrefix()
  if (LOG_NUM==0){
    io.max := io.x(0)
  }else{
    val maxArray = Vec(Array.tabulate(LOG_NUM)((m) => {
      val n:Int = 1 << (LOG_NUM-m-1)
      Vec(UInt(dataWidth bits),n)
    }))
    for (i <- 0 to LOG_NUM-1){
      val n:Int = 1 << (LOG_NUM-i-1)
      for (k <- 0 to n-1) {
        val in1 = (if (i==0) io.x(2*k) else maxArray(i-1)(2*k))
        val in2 = (if (i==0) io.x(2*k+1) else maxArray(i-1)(2*k+1))
        maxArray(i)(k) := (in1 > in2) ? in1 | in2
      }
    }
    io.max := maxArray(LOG_NUM-1)(0)
  }
}

object compare_COMPLIE {
  def main(args: Array[String]): Unit = {
    val path = "simWorkspace/compare/rtl"
    java.nio.file.Files.createDirectories(java.nio.file.Paths.get(path))
    val report = SpinalConfig(
      mode=Verilog,
      targetDirectory=path
    ).generate(new compare(11,4))
    report.mergeRTLSource(path+"/mergeRTL") // Merge all rtl sources into mergeRTL.vhd and mergeRTL.v files
  }
}
