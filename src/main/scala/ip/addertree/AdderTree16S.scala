package ip

import spinal.core._
import spinal.lib._

// sbt "runMain ip.AdderTree16S_COMPLIE"

class CsaArray_0(dataWidth: Int,compWidth: Int) extends Component {
  val fullWidth = dataWidth+compWidth
  val io=new Bundle{
    val i = new Bundle {
      val abs  = in Vec(UInt(dataWidth bits), 4)
      val sign = in Vec(Bool, 4)
    }
    val o = out Vec(UInt(fullWidth+1 bits),
                    UInt(fullWidth+1 bits),
                    UInt(1 bits))
  }
  noIoPrefix()
  // val sim = Reg(Bool)
  
  val onesComplement = Array.tabulate(4)((n) => {
    def gen:UInt={
      val tmp_0 = UInt(fullWidth bits)
      val tmp_1 = UInt(fullWidth bits)
      tmp_0 := io.i.abs(n).resize(fullWidth)
      tmp_1 := io.i.sign(n) ? ~tmp_0 | tmp_0
      return tmp_1
    }
    gen
  })
  // pp_0:
  // * * * * * * * * * * * *
  // * * * * * * * * * * * *
  // * * * * * * * * * * * *
  // * * * * * * * * * * * *
  //                       *
  //                       *
  //                       *
  //                       *
  // x 4
  val csa42 = new MyCSA42(fullWidth)
  val csa32 = new CSA32_UNIT
  for (n <- 0 to 4-1) {
    csa42.io.i.X(n) := onesComplement(n)
  }
  csa32.io.i.X(0) := io.i.sign(0)
  csa32.io.i.X(1) := io.i.sign(1)
  csa32.io.i.X(2) := io.i.sign(2)
  csa42.io.i.c := io.i.sign(3)
  io.o(0) := csa42.io.o.Y(0)
  io.o(1) := csa42.io.o.Y(1) @@ csa32.io.o.s
  io.o(2)(0) := csa32.io.o.c
}

class AdderTree16S(dataWidth: Int = 53, CSLA_PRE_WIDTH: Int) extends Component {
  val size: Int = 16
  // complementSize
  val compWidth = log2Up(size)+1
  val fullWidth = dataWidth+compWidth
  val io=new Bundle{
    val i = new Bundle {
      val abs  = in Vec(UInt(dataWidth bits), size)
      val sign = in Vec(Bool, size)
    }
    val o = new Bundle {
      val sum  = out SInt(fullWidth bits)
      // val abs  = out UInt(fullWidth bits)
      // val sign = out Bool
    }
  }
  noIoPrefix()
  val sim = Reg(Bool)
  val csaArray_0 = Array.tabulate(4)((n) => {new CsaArray_0(dataWidth,compWidth)})
  for (n <- 0 to 4-1) {
    for (m <- 0 to 4-1) {
      csaArray_0(n).io.i.abs(m)  := io.i.abs(4*n+m)
      csaArray_0(n).io.i.sign(m) := io.i.sign(4*n+m)
    }
  }
  // pp_0:
  // * * * * * * * * * * * *
  // * * * * * * * * * * * *
  //                     *
  // x 4
  val pp_0 = Vec(
                 Vec(UInt(fullWidth+1 bits), 
                     UInt(fullWidth+1 bits), 
                     UInt(1 bits))
                ,4)
  for (n <- 0 to 4-1) {
    pp_0(n) := csaArray_0(n).io.o
  }
  val csaArray_1_0_0 = new MyCSA42(fullWidth+1)
  val csaArray_1_0_1 = new MyCSA42(fullWidth)
  val csaArray_1_1_0 = new CSA32_UNIT
  val csaArray_1_1_1 = new CSA32_UNIT
  for (n <- 0 to 4-1) {
    csaArray_1_0_0.io.i.X(n) := pp_0(n)(0)
    csaArray_1_0_1.io.i.X(n) := pp_0(n)(1).asBits.resizeLeft(fullWidth).asUInt
  }
  for (n <- 0 to 3-1) {
    csaArray_1_1_0.io.i.X(n) := pp_0(n)(1)(0)
    csaArray_1_1_1.io.i.X(n) := pp_0(n)(2)(0)
  }
  csaArray_1_0_0.io.i.c := pp_0(3)(1)(0)
  csaArray_1_0_1.io.i.c := pp_0(3)(2)(0)

  // pp_1:
  // * * * * * * * * * * * *
  // * * * * * * * * * * * *
  // * * * * * * * * * * *
  // * * * * * * * * * * *
  //                   * *
  // x 1
  val pp_1 = Vec(
    UInt(fullWidth+1 bits), 
    UInt(fullWidth+1 bits), 
    UInt(fullWidth bits), 
    UInt(fullWidth bits), 
    UInt(2 bits)
  )
  pp_1(0) := csaArray_1_0_0.io.o.Y(0).resize(fullWidth+1)
  pp_1(1) := csaArray_1_0_0.io.o.Y(1).resize(fullWidth) @@ csaArray_1_1_0.io.o.s
  pp_1(2) := csaArray_1_0_1.io.o.Y(0).resize(fullWidth)
  pp_1(3) := csaArray_1_0_1.io.o.Y(1).resize(fullWidth-1) @@ csaArray_1_1_1.io.o.s
  pp_1(4)(0) := csaArray_1_1_0.io.o.c
  pp_1(4)(1) := csaArray_1_1_1.io.o.c

  val csaArray_2_0_0 = new MyCSA42(fullWidth)
  val csaArray_2_1_0 = new CSA22_UNIT
  for (n <- 0 to 4-1) {
    csaArray_2_0_0.io.i.X(n) := pp_1(n).asBits.resizeLeft(fullWidth).asUInt
  }
  csaArray_2_0_0.io.i.c := pp_1(4)(0)
  csaArray_2_1_0.io.i.X(0) := pp_1(0)(0)
  csaArray_2_1_0.io.i.X(1) := pp_1(1)(0)

  // pp_2:
  // * * * * * * * * * * * *
  // * * * * * * * * * * *
  //                   *
  // x 1
  val pp_2 = Vec(
    UInt(fullWidth+1 bits), 
    UInt(fullWidth bits), 
    UInt(1 bits)
  )
  pp_2(0) := csaArray_2_0_0.io.o.Y(0).resize(fullWidth) @@ csaArray_2_1_0.io.o.s
  pp_2(1) := csaArray_2_0_0.io.o.Y(1).resize(fullWidth-1) @@ csaArray_2_1_0.io.o.c
  pp_2(2)(0) := pp_1(4)(1)
  val csaArray_3_0_0 = new CSA32_UNIT
  csaArray_3_0_0.io.i.X(0) := pp_2(0)(2)
  csaArray_3_0_0.io.i.X(1) := pp_2(1)(1)
  csaArray_3_0_0.io.i.X(2) := pp_2(2)(0)
  val csaArray_3_1_0 = new CSA22_UNIT
  csaArray_3_1_0.io.i.X(0) := pp_2(0)(1)
  csaArray_3_1_0.io.i.X(1) := pp_2(1)(0)
  val csaArray_3_1_1 = new CSA22(fullWidth-2)
  csaArray_3_1_1.io.i.X(0) := pp_2(0).asBits.resizeLeft(fullWidth-2).asUInt
  csaArray_3_1_1.io.i.X(1) := pp_2(1).asBits.resizeLeft(fullWidth-2).asUInt

  // pp_3:
  // * * * * * * * * * * * *
  // * * * * * * * * * *
  // x 1
  val pp_3 = Vec(
    UInt(fullWidth+1 bits), 
    UInt(fullWidth-1 bits)
  )
  pp_3(0) := csaArray_3_1_1.io.o.Y(0) @@ csaArray_3_0_0.io.o.s @@ csaArray_3_1_0.io.o.s @@ pp_2(0)(0)
  pp_3(1) := csaArray_3_1_1.io.o.Y(1).resize(fullWidth-3) @@ csaArray_3_0_0.io.o.c @@ csaArray_3_1_0.io.o.c
  val csaArray_4 = new CSLA(CSLAConfig(fullWidth-1,CSLA_PRE_WIDTH))
  csaArray_4.io.i.X(0) := pp_3(0).asBits.resizeLeft(fullWidth-1)
  csaArray_4.io.i.X(1) := pp_3(1).asBits

  io.o.sum := (csaArray_4.io.o.S.resize(fullWidth-2) ## pp_3(0).resize(2).asBits).asSInt
}
object AdderTree16S_COMPLIE {
  def main(args: Array[String]): Unit = {
    val path = "simWorkspace/AdderTree16S/rtl"
    java.nio.file.Files.createDirectories(java.nio.file.Paths.get(path))
    val report = SpinalConfig(
      mode=Verilog,
      targetDirectory=path
    ).generate(new AdderTree16S(23,3))
    report.mergeRTLSource(path+"/mergeRTL")
    report.printPruned
  }
}