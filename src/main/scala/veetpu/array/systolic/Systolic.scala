package veetpu.array

import spinal.core._
import spinal.lib._
// sbt "runMain veetpu.array.Systolic_Verilog"
// import spinal.lib.experimental.math._
import veetpu.ip._
import veetpu.fp._


class Systolic(size_M: Int=16, size_N: Int=16) extends Component{
  val fpatConfig = floatingaddertree.FPATConfig(
                      fpConfig = FPConfig(11, 52), 
                      size     = size_N,
                      accuracy = 0,
                      adderTree_CLSA_PRE_WIDTH = 5
                      )
  import fpatConfig._  
  val control = new Bundle{
      val mode_sel     = in Vec(Bits(2 bits),size_M)
      // val pingpong_sel = in Vec(Bool,size_N)
      val w_addr       = in UInt(log2Up(size_M) bits)
      val w_en         = in Bool
  }
  val io = new Bundle{
    val i = new Bundle{
      val ifmap = in Vec(Bits(256 bits),size_N)
      val wight = in Vec(Bits(256 bits),size_N)
    }
    val o = new Bundle{
      val sum = out Vec(FP(fpConfig),size_M)
      // val mode_sel = out Vec(Bits(2 bits),size_M)
    }
  }
  
  //  pingpong_sel    true  false
  //  weightBuffer(0)   w     r
  //  weightBuffer(1)   r     w
  val weightBuffer = Array.tabulate(size_M,size_N)((m,n) => { RegNextWhen(io.i.wight(n), control.w_addr===U(m) & control.w_en) })
  val ifmapBuffer  = Array.tabulate(size_M,size_N)((m,n) => { (if (m==0) Bits(256 bits) else Reg(Bits(256 bits))) })
  Array.tabulate(size_M,size_N)((m,n) => {
    ifmapBuffer(m)(n) := (if (m==0) io.i.ifmap(n) else ifmapBuffer(m-1)(n) )
  })
  val peArray = Array.tabulate(size_M,size_N)((m,n) => {new pe.PE_16in_top})
  val fpAddTreeArray = Array.tabulate(size_M)((m) => {new floatingaddertree.FloatingAdderTree(fpatConfig)})
  Array.tabulate(size_M,size_N)((m,n) => {
    peArray(m)(n).io.mode_sel := control.mode_sel(m)
    peArray(m)(n).io.A := ifmapBuffer(m)(n)
    peArray(m)(n).io.B := weightBuffer(m)(n)
    fpAddTreeArray(m).io.i.X(n) := FP(fpConfig, peArray(m)(n).io.result)
  })
  Array.tabulate(size_M)((m) => {
    io.o.sum(m) := fpAddTreeArray(m).io.o.Y
  })
}

object Systolic_Verilog {
  def main(args: Array[String]): Unit = {
    val path = "simWorkspace/Systolic/rtl"
    java.nio.file.Files.createDirectories(java.nio.file.Paths.get(path))
    val report = SpinalConfig(
      mode=Verilog,
      targetDirectory=path,
      oneFilePerComponent=true
      // netlistFileName="Systolic_16.v"
    ).generate(new Systolic())
    report.mergeRTLSource(path+"/mergeRTL") // Merge all rtl sources into mergeRTL.vhd and mergeRTL.v files
  }
}
