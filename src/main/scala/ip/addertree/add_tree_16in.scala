package ip.addertree

import spinal.core._
import spinal.lib._

// sbt "runMain ip.addertree.add_tree_16in_COMPILE"

class add_tree_16in(dataWidth: Int) extends BlackBox {
  addGeneric("WIDTH",dataWidth)
  val io=new Bundle{
    val i = new Bundle {
      val data  = in Vec(Bits (dataWidth bits), 16)
    }
    val o = new Bundle {
      val sum        = out Bits(dataWidth+4 bits)
      val carry      = out Bits(dataWidth+4 bits)
      val add_result = out Bits(dataWidth+4 bits)
    }
  }
  noIoPrefix()
  //mapClockDomain(clock = io.clk,reset = io.rst)
  val Path:String = "src/main/verilog/veetpu/ip/addertree/"
  addRTLPath(Path+"add_tree_16in.v")
  val refPath = "reference/PE_16in_v2_acc_rtl/"
  addRTLPath(refPath+"CSA4_2_UNIT.v")
  addRTLPath(refPath+"CSA4_2.v")
  addRTLPath(refPath+"csla_unit.v")
  addRTLPath(refPath+"csla.v")
  addRTLPath(refPath+"cpa.v")
  addRTLPath(refPath+"Hadd.v")
  addRTLPath(refPath+"Fadd.v")
}

class add_tree_16in_TOP extends Component {
  val io=new Bundle{
    // val clk = in Bool
    // val rst = in Bool
    val i = new Bundle {
      val data  = in Vec(Bits (5 bits), 16)
    }
    val o = new Bundle {
      val sum        = out Bits(5+4 bits)
      val carry      = out Bits(5+4 bits)
      val add_result = out Bits(5+4 bits)
    }
  }
    noIoPrefix()
  // Instantiate the blackbox
  val add_tree_16 = new add_tree_16in(5)
  val sim = Reg(Bool)

  // Connect all the signals
  io.i.data <> add_tree_16.io.i.data
  io.o.sum  <> add_tree_16.io.o.sum
  io.o.carry  <> add_tree_16.io.o.carry
  io.o.add_result  <> add_tree_16.io.o.add_result
}
object add_tree_16in_COMPILE {
  def main(args: Array[String]): Unit = {
    val path = "simWorkspace/add_tree_16in/rtl"
    java.nio.file.Files.createDirectories(java.nio.file.Paths.get(path))
    val report = SpinalConfig(
      mode=Verilog,
      targetDirectory=path
    ).generate(new add_tree_16in_TOP())
    report.mergeRTLSource(path+"/mergeRTL") // Merge all rtl sources into mergeRTL.vhd and mergeRTL.v files
  }
}

//
//object Test extends App{
//  SpinalConfig(
//    defaultConfigForClockDomains = ClockDomainConfig(resetActiveLevel = HIGH,resetKind = SYNC)
//  ).generate(new compare_logic_4in(8))
//}
