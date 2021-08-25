package FP

import spinal.core._
import spinal.lib._

case class CSLAConfig(
  dataWidth  : Int = 29,
  PRE_WIDTH  : Int = 6,
  PRE_UNIT_NUM: Int = 4,
  RCA_WIDTH: Int = 5
){      
    if (dataWidth != PRE_WIDTH*PRE_UNIT_NUM+RCA_WIDTH){
      println(Console.WHITE +"[" + Console.RED + "error" + Console.WHITE + "] CSLA config is WRONG")
      sys.error("dataWidth != PRE_WIDTH*PRE_UNIT_NUM+RCA_WIDTH")
    }
}

//class CSLA(dataWidth:Int = 29, PRE_WIDTH:Int = 6, PRE_UNIT_NUM:Int = 4,RCA_WIDTH:Int = 5) extends BlackBox{
class CSLA(cslaConfig: CSLAConfig) extends BlackBox{
  import cslaConfig._
  //if (dataWidth != PRE_WIDTH*PRE_UNIT_NUM+RCA_WIDTH){
  //  println(Console.WHITE +"[" + Console.RED + "error" + Console.WHITE + "] CSLA config is WRONG")
  //  sys.error("dataWidth != PRE_WIDTH*PRE_UNIT_NUM+RCA_WIDTH")
  //}
  addGeneric("WIDTH",dataWidth)
  addGeneric("PRE_WIDTH",PRE_WIDTH)
  addGeneric("PRE_UNIT_NUM",PRE_UNIT_NUM)
  addGeneric("RCA_WIDTH",RCA_WIDTH)
  val io=new Bundle{
    val clk = in Bool
    val rst = in Bool
    val i = new Bundle {
      val X  = in  Vec(Bits (dataWidth bits), 2)
    }
    val o = new Bundle {
      val S = out Bits(dataWidth+1 bits)
    }
  }
  noIoPrefix()
  mapClockDomain(clock = io.clk,reset = io.rst)
  addRTLPath("./src/main/scala/fp/basic/csla/verilog/Fadd.v")
  addRTLPath("./src/main/scala/fp/basic/csla/verilog/Hadd.v")
  addRTLPath("./src/main/scala/fp/basic/csla/verilog/cpa.v")
  addRTLPath("./src/main/scala/fp/basic/csla/verilog/csla_unit.v")
  addRTLPath("./src/main/scala/fp/basic/csla/verilog/CSLA.v")
}

class CSLA_TOP extends Component {
  val cslaConfig = new CSLAConfig(
    dataWidth= 29,
    PRE_WIDTH= 6,
    PRE_UNIT_NUM = 2,
    RCA_WIDTH= 5
  )
  val io=new Bundle{
    val clk = in Bool
    val rst = in Bool
    val i = new Bundle {
      val X = in  Vec(Bits(cslaConfig.dataWidth bits), 2)
    }
    val o = new Bundle {
      val S = out Bits(cslaConfig.dataWidth+1 bits)
    }
  }
    noIoPrefix()
  // Instantiate the blackbox
  val csla = new CSLA(cslaConfig)

  // Connect all the signals
  io.i.X        <> csla.io.i.X
  io.o.S        <> csla.io.o.S
  }

object CSLA_TOP_COMPILE {
  def main(args: Array[String]): Unit = {
    val path = "simWorkspace/CSLA_TOP_COMPILE/rtl"
    java.nio.file.Files.createDirectories(java.nio.file.Paths.get(path))
    val report = SpinalConfig(
      mode=Verilog,
      targetDirectory=path
    ).generate(new CSLA_TOP)
    report.mergeRTLSource(path+"/mergeRTL") // Merge all rtl sources into mergeRTL.vhd and mergeRTL.v files
  }
}

//
//object Test extends App{
//  SpinalConfig(
//    defaultConfigForClockDomains = ClockDomainConfig(resetActiveLevel = HIGH,resetKind = SYNC)
//  ).generate(new compare_logic_4in(8))
//}
