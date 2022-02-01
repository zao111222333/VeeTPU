package ip

import spinal.core._
import spinal.lib._

// object MyCSA42{
//   def apply(dataWidth: Int):MyCSA42=new MyCSA42(dataWidth)
// }


// sbt "runMain ip.MyCSA42_COMPILE"
class MyCSA42(dataWidth: Int) extends Component{
  val io=new Bundle{
    val i = new Bundle {
      val X = in Vec(UInt(dataWidth bit), 4)
      val c = in Bool()
    }
    val o = new Bundle {
      val Y = out Vec(UInt(dataWidth+1 bit), UInt(dataWidth bit))
    }
  }
  noIoPrefix()
  //mapClockDomain(clock = io.clk,reset = io.rst)
  val csa_unitArray = Array.tabulate(dataWidth)((n) => {new CSA42_UNIT})
  for (n <- 0 to dataWidth-1){
    for (m <- 0 to 4-1) {
      csa_unitArray(n).io.i.X(m) := io.i.X(m)(n)
    }
    csa_unitArray(n).io.i.c_in := (if (n == 0) io.i.c else csa_unitArray(n-1).io.o.c_out)
    io.o.Y(0)(n) := csa_unitArray(n).io.o.sum
    io.o.Y(1)(n) := csa_unitArray(n).io.o.carry
  }
  io.o.Y(0)(dataWidth) := csa_unitArray(dataWidth-1).io.o.c_out
}

object MyCSA42_COMPILE {
  def main(args: Array[String]): Unit = {
    val path = "simWorkspace/MyCSA42_COMPILE/rtl"
    java.nio.file.Files.createDirectories(java.nio.file.Paths.get(path))
    val report = SpinalConfig(
      mode=Verilog,
      targetDirectory=path
    ).generate(new MyCSA42(40))
    report.mergeRTLSource(path+"/mergeRTL") // Merge all rtl sources into mergeRTL.vhd and mergeRTL.v files
  }
}

//
//object Test extends App{
//  SpinalConfig(
//    defaultConfigForClockDomains = ClockDomainConfig(resetActiveLevel = HIGH,resetKind = SYNC)
//  ).generate(new compare_logic_4in(8))
//}
