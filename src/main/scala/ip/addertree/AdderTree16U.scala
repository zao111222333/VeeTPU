package ip

import spinal.core._
import spinal.lib._

// sbt "runMain ip.AdderTree16U_COMPLIE"
class AdderTree16U(dataWidth: Int = 53, CSLA_PRE_WIDTH: Int) extends Component {
  val io=new Bundle{
    val i = new Bundle {
      val X  = in Vec(Bits(dataWidth bits), 16)
    }
    val o = new Bundle {
      val S = out Bits(dataWidth+4 bits)
    }
  }
  noIoPrefix()
  val sim = Reg(Bool)
  val csaArray_0 = Array.tabulate(4)((n) => {
    def gen_csa42: CSA42 = {
      val csa42 = new CSA42(dataWidth)
      for (m <- 0 to 4-1) {
        csa42.io.i.X(m) := io.i.X(4*n+m)
      }
      return csa42
    }
    gen_csa42
  })

  val csaArray_1_0 = new CSA42(dataWidth+1)
  val csaArray_1_1 = new CSA42(dataWidth)
  for (m <- 0 to 4-1) {
    csaArray_1_0.io.i.X(m) := csaArray_0(m).io.o.carry_out ## csaArray_0(m).io.o.sum
    csaArray_1_1.io.i.X(m) := csaArray_0(m).io.o.carry
  }

  val csaArray_2_0 = new CSA42(dataWidth)
  csaArray_2_0.io.i.X(0) := csaArray_1_0.io.o.carry_out ## csaArray_1_0.io.o.sum.resizeLeft(dataWidth-1)
  csaArray_2_0.io.i.X(1) := csaArray_1_0.io.o.carry.resizeLeft(dataWidth)
  csaArray_2_0.io.i.X(2) := csaArray_1_1.io.o.carry_out ## csaArray_1_1.io.o.sum.resizeLeft(dataWidth-1)
  csaArray_2_0.io.i.X(3) := csaArray_1_1.io.o.carry
  val csaArray_2_1 = new FA
  csaArray_2_1.io.i.X(0) := csaArray_1_0.io.o.sum.resize(2).resizeLeft(1).asBool
  csaArray_2_1.io.i.X(1) := csaArray_1_0.io.o.carry.resize(1).asBool
  csaArray_2_1.io.i.X(2) := csaArray_1_1.io.o.sum.resize(1).asBool

  val S_ = Vec(Bits(dataWidth+3 bits), Bits(dataWidth+1 bits))
  S_(0) := csaArray_2_0.io.o.carry_out ## csaArray_2_0.io.o.sum ## csaArray_2_1.io.o.sum ## csaArray_1_0.io.o.sum.resize(1)
  S_(1) := csaArray_2_0.io.o.carry ## csaArray_2_1.io.o.carry

  val cslaConfig = new CSLAConfig(
    dataWidth = dataWidth+1,
    PRE_WIDTH = CSLA_PRE_WIDTH//,
    // PRE_UNIT_NUM = scala.math.ceil((dataWidth+1)/CSLA_PRE_WIDTH).toInt - 1,
    // RCA_WIDTH = dataWidth+1 - CSLA_PRE_WIDTH*(scala.math.ceil((dataWidth+1)/CSLA_PRE_WIDTH).toInt - 1)
  )
  val csla = new CSLA(cslaConfig)
  csla.io.i.X(0) := S_(0).resizeLeft(dataWidth+1)
  csla.io.i.X(1) := S_(1)

  io.o.S := csla.io.o.S ## S_(0).resize(2)
}

class AdderTree16U_TOP extends Component {
  val adder = new AdderTree16U(11,3)
  

}

object AdderTree16U_COMPLIE {
  def main(args: Array[String]): Unit = {
    val path = "simWorkspace/AdderTree16U/rtl"
    java.nio.file.Files.createDirectories(java.nio.file.Paths.get(path))
    val report = SpinalConfig(
      mode=Verilog,
      targetDirectory=path
    ).generate(new AdderTree16U(11,3))
    report.mergeRTLSource(path+"/mergeRTL")
    report.printPruned
  }
}