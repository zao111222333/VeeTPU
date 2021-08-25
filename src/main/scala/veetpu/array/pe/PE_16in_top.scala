package veetpu.array.pe


import spinal.core._
import spinal.lib._

//class CSLA(dataWidth:Int = 29, PRE_WIDTH:Int = 6, PRE_UNIT_NUM:Int = 4,RCA_WIDTH:Int = 5) extends BlackBox{
class PE_16in_top extends BlackBox{
  val io=new Bundle{
    val clk  = in Bool
    val rstn = in Bool
    val mode_sel = in Bits(2 bits)
    val A  = in Bits(256 bits)
    val B  = in Bits(256 bits)
    val result   = out Bits(64 bits)
    val mode_out = out Bits(2  bits)
  }
  noIoPrefix()
  mapClockDomain(clock = io.clk,reset = io.rstn)
  val Path:String = "./src/main/scala/veetpu/array/pe/"
  
  addRTLPath(Path+"pe_mergeRTL.v")
}

class PE_16in_TOP_ extends Component {
  val io=new Bundle{
    val mode_sel = in Bits(2 bits)
    val A  = in Bits (256 bits)
    val B  = in Bits (256 bits)
    val result   = out Bits(64 bits)
    val mode_out = out Bits(2  bits)
  }
  noIoPrefix()
  // Instantiate the blackbox
  val pe = new PE_16in_top
  // Connect all the signals
  io.mode_sel <> pe.io.mode_sel
  io.A <> pe.io.A
  io.B <> pe.io.B
  io.result <> pe.io.result
  io.mode_out <> pe.io.mode_out
  }

object PE_16in_TOP_COMPILE {
  def main(args: Array[String]): Unit = {
    val path = "simWorkspace/PE_16in_TOP/rtl"
    java.nio.file.Files.createDirectories(java.nio.file.Paths.get(path))
    val report = SpinalConfig(
      mode=Verilog,
      targetDirectory=path
    ).generate(new PE_16in_TOP_)
    report.mergeRTLSource(path+"/mergeRTL") // Merge all rtl sources into mergeRTL.vhd and mergeRTL.v files
  }
}

//
//object Test extends App{
//  SpinalConfig(
//    defaultConfigForClockDomains = ClockDomainConfig(resetActiveLevel = HIGH,resetKind = SYNC)
//  ).generate(new compare_logic_4in(8))
//}
