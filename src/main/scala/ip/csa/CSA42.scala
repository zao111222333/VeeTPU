package ip

import spinal.core._
import spinal.lib._
// sbt "runMain ip.CSA42_TOP_COMPILE"
class CSA42(dataWidth:Int) extends BlackBox{
  addGeneric("dataWidth",dataWidth)
  val io=new Bundle{
    //val clk = in Bool
    //val rst = in Bool
    val i = new Bundle {
      val X = in Vec(Bits (dataWidth bit), 4)
    }
    val o = new Bundle {
      val sum         = out Bits (dataWidth bit)
      val carry       = out Bits (dataWidth bit)
      val carry_out   = out Bits (1 bit)
    }
  }
  noIoPrefix()
  //mapClockDomain(clock = io.clk,reset = io.rst)
  val Path:String = "./src/main/verilog/veetpu/ip/csa/"
  addRTLPath(Path+"/CSA42.v")
  addRTLPath(Path+"/CSA42_UNIT.v")
}

class CSA42_TOP extends Component {
  val dataWidth = 11
  val io=new Bundle{
    val i = new Bundle {
      val X = in Vec(Bits (dataWidth bit), 4)
    }
    val o = new Bundle {
      val sum         = out Bits (dataWidth bit)
      val carry       = out Bits (dataWidth bit)
      val carry_out = out Bits (1 bit)
    }
  }
    noIoPrefix()
  // Instantiate the blackbox
  val csa42 = new CSA42(dataWidth)

  // Connect all the signals
  io.i.X         <> csa42.io.i.X
  io.o.sum       <> csa42.io.o.sum
  io.o.carry     <> csa42.io.o.carry
  io.o.carry_out <> csa42.io.o.carry_out
  }

object CSA42_TOP_COMPILE {
  def main(args: Array[String]): Unit = {
    val path = "simWorkspace/CSA42_TOP_COMPILE/rtl"
    java.nio.file.Files.createDirectories(java.nio.file.Paths.get(path))
    val report = SpinalConfig(
      mode=Verilog,
      targetDirectory=path
    ).generate(new CSA42_TOP)
    report.mergeRTLSource(path+"/mergeRTL") // Merge all rtl sources into mergeRTL.vhd and mergeRTL.v files
  }
}

//
//object Test extends App{
//  SpinalConfig(
//    defaultConfigForClockDomains = ClockDomainConfig(resetActiveLevel = HIGH,resetKind = SYNC)
//  ).generate(new compare_logic_4in(8))
//}
