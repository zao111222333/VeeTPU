package veetpu.array.weightbuffer

import spinal.core._
import spinal.lib._
// sbt "runMain veetpu.array.weightbuffer.WeightBuffer_Verilog"
// import spinal.lib.experimental.math._


case class BufferConfig(
          dataWidth: Int,
          dataNumb: Int
){
  val addrWidth = log2Up(dataNumb)
}

class Buffer(bufferConfig: BufferConfig) extends Component{
  import bufferConfig._

  val w = new Bundle{
    val addr = in UInt(addrWidth bits)
    val en   = in Bool
    val data = in Bits(dataWidth bits)
  }
  val r = new Bundle{
    val addr = in UInt(addrWidth bits)
    val data = out Bits(dataWidth bits)
  }
  private val buffer = Vec(Reg(Bits(dataWidth bits)) randBoot(), dataNumb)
  for (n <- 0 to dataNumb-1){
    when(w.addr===U(n) & w.en){ buffer(n) := w.data }
  }
  r.data := buffer(r.addr)
}

class WeightBuffer(bufferConfig: BufferConfig, size: Int) extends Component{
  import bufferConfig._

  val io = new Bundle{
    val w = new Bundle{
      val addr = in UInt(addrWidth bits)
      val en   = in Bool
      val data = in Vec(Bits(dataWidth bits), size)
    }
    val r = new Bundle{
      val addr = in UInt(addrWidth bits)
      val data = out Vec(Bits(dataWidth bits), size)
    }
  }
  noIoPrefix()
  val buffRow = Array.tabulate(size)((n) => { new Buffer(bufferConfig) })
  for (n <- 0 to size-1){
    buffRow(n).w.addr := io.w.addr
    buffRow(n).w.en   := io.w.en
    buffRow(n).w.data := io.w.data(n)
    buffRow(n).r.addr := io.r.addr
    io.r.data(n) := buffRow(n).r.data
  }
}
// sbt "runMain veetpu.array.weightbuffer.WeightBuffer_Verilog"

object WeightBuffer_Verilog {
  def main(args: Array[String]): Unit = {
    val bufferConfig=BufferConfig(
                      dataWidth = 14,
                      dataNumb  = 16
                      )
    val size = 16

    val path = "simWorkspace/WeightBuffer/rtl"
    java.nio.file.Files.createDirectories(java.nio.file.Paths.get(path))
    val report = SpinalConfig(
      mode=Verilog,
      targetDirectory=path
    ).generate(new WeightBuffer(bufferConfig,size))
    report.mergeRTLSource(path+"/mergeRTL") // Merge all rtl sources into mergeRTL.vhd and mergeRTL.v files
  }
}
