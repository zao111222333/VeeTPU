package veetpu.reconfigurable.vector

import spinal.core._
import spinal.lib._


/* --------------------------------                             -------------------------------- *\
** --------------------------------    ____    _____   _        -------------------------------- **
** --------------------------------   |  _ \  |_   _| | |       -------------------------------- **
** --------------------------------   | |_) |   | |   | |       -------------------------------- **
** --------------------------------   |  _ <    | |   | |___    -------------------------------- **
** --------------------------------   |_| \_\   |_|   |_____|   -------------------------------- **
\* --------------------------------                             -------------------------------- */

class ADDBasic16() extends Component{
  val io = new Bundle{
    val i = new Bundle{
      val carry = in Vec(UInt( 1 bits), 16)
      val input = in Vec(UInt(23 bits), 16)
    }
    val o = new Bundle{
      val sum = out UInt(23+4+1 bits)
    }
  }
    io.o.sum := ((((io.i.input( 0)+^io.i.input( 1))+^(io.i.input( 2)+^io.i.input( 3)))+^
                  ((io.i.input( 4)+^io.i.input( 5))+^(io.i.input( 6)+^io.i.input( 7))))+^
                 (((io.i.input( 8)+^io.i.input( 9))+^(io.i.input(10)+^io.i.input(11)))+^
                  ((io.i.input(12)+^io.i.input(13))+^(io.i.input(14)+^io.i.input(15)))))
  noIoPrefix()
}

class ADDMulti() extends Component{
  val ctl = new Bundle{
    val i = new Bundle{
      val mode = in (Mode())
    }
  }
  def oneComplement(trueForm: UInt, enable: Bool): UInt = enable.asUInt @@ Mux(enable, ~trueForm, trueForm)
  val io = new Bundle{
    val i = new Bundle{
      val mant = new Bundle{
        val mul = new Bundle{
          val INT8 = in Vec(Vec(SInt(  8*2+1 bits), 16), 4)
          val BF16 = in Vec(Vec(UInt(  8*2   bits), 16), 4)
          val FP16 = in Vec(Vec(UInt( 11*2   bits), 16), 4)
          val FP32 = in Vec(Vec(UInt( 24*2   bits),  8), 2)
          val TF32 = in Vec(Vec(UInt( 11*2   bits),  8), 2)
          val FP64 = in Vec(Vec(UInt( 53*2   bits),  4), 1)
        }
        val mac = new Bundle{
          val INT8 = in Vec(Vec(SInt( 32 bits), 1), 4)
          val BF16 = in Vec(Vec(UInt(  8 bits), 1), 4)
          val FP16 = in Vec(Vec(UInt( 11 bits), 1), 4)
          val FP32 = in Vec(Vec(UInt( 24 bits), 1), 2)
          val TF32 = in Vec(Vec(UInt( 11 bits), 1), 2)
          val FP64 = in Vec(Vec(UInt( 53 bits), 1), 1)
        }
        val add = new Bundle{
          val INT8 = in Vec(Vec(SInt( 32 bits), 1), 4)
          val BF16 = in Vec(Vec(UInt(  8 bits), 1), 4)
          val FP16 = in Vec(Vec(UInt( 11 bits), 1), 4)
          val FP32 = in Vec(Vec(UInt( 24 bits), 1), 2)
          val TF32 = in Vec(Vec(UInt( 11 bits), 1), 2)
          val FP64 = in Vec(Vec(UInt( 53 bits), 1), 1)
        }
      }
      val sign = new Bundle{
        val mul = new Bundle{
          val BF16 = in Vec(Vec(Bool(), 16), 4)
          val FP16 = in Vec(Vec(Bool(), 16), 4)
          val FP32 = in Vec(Vec(Bool(),  8), 2)
          val TF32 = in Vec(Vec(Bool(),  8), 2)
          val FP64 = in Vec(Vec(Bool(),  4), 1)
        }
        val mac = new Bundle{
          val BF16 = in Vec(Vec(Bool(), 1), 4)
          val FP16 = in Vec(Vec(Bool(), 1), 4)
          val FP32 = in Vec(Vec(Bool(), 1), 2)
          val TF32 = in Vec(Vec(Bool(), 1), 2)
          val FP64 = in Vec(Vec(Bool(), 1), 1)
        }
        val add = new Bundle{
          val BF16 = in Vec(Vec(Bool(), 1), 4)
          val FP16 = in Vec(Vec(Bool(), 1), 4)
          val FP32 = in Vec(Vec(Bool(), 1), 2)
          val TF32 = in Vec(Vec(Bool(), 1), 2)
          val FP64 = in Vec(Vec(Bool(), 1), 1)
        }
      }
    }
    val o = new Bundle{
      // 64 -> 2 , 32 = 2^5
      val INT8 = out Vec(SInt(      32 bits), 4)
      // 64 -> 4 , 16 = 2^4
      val BF16 = out Vec(SInt( 8*2+4+1 bits), 4)
      val FP16 = out Vec(SInt(11*2+4+1 bits), 4)
      // 16 -> 2 ,  8 = 2^3
      val FP32 = out Vec(SInt(24*2+3+1 bits), 2)
      val TF32 = out Vec(SInt(11*2+3+1 bits), 2)
      //  4 -> 1 ,  4 = 2^2
      val FP64 = out Vec(SInt(53*2+2+1 bits), 1)
    }
  }
  noIoPrefix()
  val OneComplement = new Bundle{
    val mul = new Bundle{
      val INT8 = Vec(Vec(UInt(  8*2+1 bits), 16), 4)
      val BF16 = Vec(Vec(UInt(  8*2+1 bits), 16), 4)
      val FP16 = Vec(Vec(UInt( 11*2+1 bits), 16), 4)
      val FP32 = Vec(Vec(UInt( 24*2+1 bits),  8), 2)
      val TF32 = Vec(Vec(UInt( 11*2+1 bits),  8), 2)
      val FP64 = Vec(Vec(UInt( 53*2+1 bits),  4), 1)
    }
    val mac = new Bundle{
      val INT8 = Vec(Vec(UInt(   32 bits),  1), 4)
      val BF16 = Vec(Vec(UInt(  8+1 bits),  1), 4)
      val FP16 = Vec(Vec(UInt( 11+1 bits),  1), 4)
      val FP32 = Vec(Vec(UInt( 24+1 bits),  1), 2)
      val TF32 = Vec(Vec(UInt( 11+1 bits),  1), 2)
      val FP64 = Vec(Vec(UInt( 53+1 bits),  1), 1)
    }
    val add = new Bundle{
      val INT8 = Vec(Vec(UInt(   32 bits),  1), 4)
      val BF16 = Vec(Vec(UInt(  8+1 bits),  1), 4)
      val FP16 = Vec(Vec(UInt( 11+1 bits),  1), 4)
      val FP32 = Vec(Vec(UInt( 24+1 bits),  1), 2)
      val TF32 = Vec(Vec(UInt( 11+1 bits),  1), 2)
      val FP64 = Vec(Vec(UInt( 53+1 bits),  1), 1)
    }
  }
  Array.tabulate(4)((m) => {
    Array.tabulate(16)((n) => {
      OneComplement.mul.INT8(m)(n) := io.i.mant.mul.INT8(m)(n).asUInt
    })
    OneComplement.mac.INT8(m)(0) := io.i.mant.mac.INT8(m)(0).asUInt
    OneComplement.add.INT8(m)(0) := io.i.mant.add.INT8(m)(0).asUInt
  })
  Array.tabulate(4)((m) => {
    Array.tabulate(16)((n) => {
      OneComplement.mul.BF16(m)(n) := oneComplement(io.i.mant.mul.BF16(m)(n),io.i.sign.mul.BF16(m)(n))
      OneComplement.mul.FP16(m)(n) := oneComplement(io.i.mant.mul.FP16(m)(n),io.i.sign.mul.FP16(m)(n))
    })
    OneComplement.mac.BF16(m)(0) := oneComplement(io.i.mant.mac.BF16(m)(0),io.i.sign.mac.BF16(m)(0))
    OneComplement.add.BF16(m)(0) := oneComplement(io.i.mant.add.BF16(m)(0),io.i.sign.add.BF16(m)(0))
    OneComplement.mac.FP16(m)(0) := oneComplement(io.i.mant.mac.FP16(m)(0),io.i.sign.mac.FP16(m)(0))
    OneComplement.add.FP16(m)(0) := oneComplement(io.i.mant.add.FP16(m)(0),io.i.sign.add.FP16(m)(0))
  })
  Array.tabulate(2)((m) => {
    Array.tabulate(8)((n) => {
      OneComplement.mul.FP32(m)(n) := oneComplement(io.i.mant.mul.FP32(m)(n),io.i.sign.mul.FP32(m)(n))
      OneComplement.mul.TF32(m)(n) := oneComplement(io.i.mant.mul.TF32(m)(n),io.i.sign.mul.TF32(m)(n))
    })
    OneComplement.mac.FP32(m)(0) := oneComplement(io.i.mant.mac.FP32(m)(0),io.i.sign.mac.FP32(m)(0))
    OneComplement.mac.TF32(m)(0) := oneComplement(io.i.mant.mac.TF32(m)(0),io.i.sign.mac.TF32(m)(0))
    OneComplement.add.FP32(m)(0) := oneComplement(io.i.mant.add.FP32(m)(0),io.i.sign.add.FP32(m)(0))
    OneComplement.add.TF32(m)(0) := oneComplement(io.i.mant.add.TF32(m)(0),io.i.sign.add.TF32(m)(0))
  })
  Array.tabulate(1)((m) => {
    Array.tabulate(4)((n) => {
      OneComplement.mul.FP64(m)(n) := oneComplement(io.i.mant.mul.FP64(m)(n),io.i.sign.mul.FP64(m)(n))
    })
    OneComplement.mac.FP64(m)(0) := oneComplement(io.i.mant.mac.FP64(m)(0),io.i.sign.mac.FP64(m)(0))
    OneComplement.add.FP64(m)(0) := oneComplement(io.i.mant.add.FP64(m)(0),io.i.sign.add.FP64(m)(0))
  })

  // Array.tabulate(4)((m) => {
  //   io.o.INT8(m) :=(ctl.i.mode.isMUL? sum(OneComplement.mul.INT8(m)) |
  //                  (ctl.i.mode.isMAC? sum(OneComplement.mul.INT8(m),OneComplement.mac.INT8(m))| 
  //                  (ctl.i.mode.isMAC? sum(OneComplement.add.INT8(m),OneComplement.mac.INT8(m))| S"0".resized))).resized
  // })
  // Array.tabulate(4)((m) => {
  //   io.o.BF16(m) :=(ctl.i.mode.isMUL? sum(OneComplement.mul.BF16(m)) |
  //                  (ctl.i.mode.isMAC? sum(OneComplement.mul.BF16(m),OneComplement.mac.BF16(m))| 
  //                  (ctl.i.mode.isMAC? sum(OneComplement.add.BF16(m),OneComplement.mac.BF16(m))| S"0".resized))).resized
  //   io.o.FP16(m) :=(ctl.i.mode.isMUL? sum(OneComplement.mul.FP16(m)) |
  //                  (ctl.i.mode.isMAC? sum(OneComplement.mul.FP16(m),OneComplement.mac.FP16(m))| 
  //                  (ctl.i.mode.isMAC? sum(OneComplement.add.FP16(m),OneComplement.mac.FP16(m))| S"0".resized))).resized
  // })
  // Array.tabulate(2)((m) => {
  //   io.o.FP32(m) :=(ctl.i.mode.isMUL? sum(OneComplement.mul.FP32(m)) |
  //                  (ctl.i.mode.isMAC? sum(OneComplement.mul.FP32(m),OneComplement.mac.FP32(m))| 
  //                  (ctl.i.mode.isMAC? sum(OneComplement.add.FP32(m),OneComplement.mac.FP32(m))| S"0".resized))).resized
  //   io.o.TF32(m) :=(ctl.i.mode.isMUL? sum(OneComplement.mul.TF32(m)) |
  //                  (ctl.i.mode.isMAC? sum(OneComplement.mul.TF32(m),OneComplement.mac.TF32(m))| 
  //                  (ctl.i.mode.isMAC? sum(OneComplement.add.TF32(m),OneComplement.mac.TF32(m))| S"0".resized))).resized
  // })
  // Array.tabulate(1)((m) => {
  //   io.o.FP64(m) :=(ctl.i.mode.isMUL? sum(OneComplement.mul.FP64(m)) |
  //                  (ctl.i.mode.isMAC? sum(OneComplement.mul.FP64(m),OneComplement.mac.FP64(m))| 
  //                  (ctl.i.mode.isMAC? sum(OneComplement.add.FP64(m),OneComplement.mac.FP64(m))| S"0".resized))).resized
  // })
}
object ADDMulti_Verilog {
  def main(args: Array[String]): Unit = {
    val path = "simWorkspace/ADDMulti/rtl"
    java.nio.file.Files.createDirectories(java.nio.file.Paths.get(path))
    val report = SpinalConfig(
      mode=Verilog,
      targetDirectory=path
    ).generate(new ADDMulti())
    report.mergeRTLSource(path+"/mergeRTL") // Merge all rtl sources into mergeRTL.vhd and mergeRTL.v files
  }
}

/* ----------------------------                                    ----------------------------- *\
** ----------------------------   __     __        _  __           ----------------------------- **
** ----------------------------   \ \   / /__ _ __(_)/ _|_   _     ----------------------------- **
** ----------------------------    \ \ / / _ \ '__| | |_| | | |    ----------------------------- **
** ----------------------------     \ V /  __/ |  | |  _| |_| |    ----------------------------- **
** ----------------------------      \_/ \___|_|  |_|_|  \__, |    ----------------------------- **
\* ----------------------------                          |___/     ----------------------------- */

class ADDMulti_Verif() extends Component{

  // def randomInput()

  def sum(in0:SInt,in1:SInt):SInt={
    return in0+^in1
  }
  def sum(in:Array[SInt]):SInt={
    val len = in.length
    var maxWidth = in(0).getWidth
    val sumArray = Array.tabulate(len-1)((n) => {
      maxWidth = maxWidth+1
      maxWidth = maxWidth.max(in(n+1).getWidth)
      SInt(maxWidth bits)
    })
    sumArray(0) := sum(in(0),in(1))
    Array.tabulate(len-2)((n) => {
      sumArray(n+1) := sum(sumArray(n),in(n+2))
    })
    sumArray(len-2)
  }
  def sum(in:Vec[SInt]):SInt={
    val _in = Array.tabulate(in.length)((n) => { in(n) })
    sum(_in)
  }
  def sum(in1:Vec[SInt],in2:Vec[SInt]):SInt={
    val _in = Array.tabulate(in1.length+in2.length)((n) => { 
      if(n>in1.length-1) in2(n-in1.length) else in1(n)
    })
    sum(_in)
  }
  val ctl = new Bundle{
    val i = new Bundle{
      val mode = in (Mode())
    }
  }

  val io = new Bundle{
    val i = new Bundle{
      val mant = new Bundle{
        val mul = new Bundle{
          val INT8 = in Vec(Vec(SInt(  8*2+1 bits), 16), 4)
          val BF16 = in Vec(Vec(UInt(  8*2   bits), 16), 4)
          val FP16 = in Vec(Vec(UInt( 11*2   bits), 16), 4)
          val FP32 = in Vec(Vec(UInt( 24*2   bits),  8), 2)
          val TF32 = in Vec(Vec(UInt( 11*2   bits),  8), 2)
          val FP64 = in Vec(Vec(UInt( 53*2   bits),  4), 1)
        }
        val mac = new Bundle{
          val INT8 = in Vec(Vec(SInt( 32 bits), 1), 4)
          val BF16 = in Vec(Vec(UInt(  8 bits), 1), 4)
          val FP16 = in Vec(Vec(UInt( 11 bits), 1), 4)
          val FP32 = in Vec(Vec(UInt( 24 bits), 1), 2)
          val TF32 = in Vec(Vec(UInt( 11 bits), 1), 2)
          val FP64 = in Vec(Vec(UInt( 53 bits), 1), 1)
        }
        val add = new Bundle{
          val INT8 = in Vec(Vec(SInt( 32 bits), 1), 4)
          val BF16 = in Vec(Vec(UInt(  8 bits), 1), 4)
          val FP16 = in Vec(Vec(UInt( 11 bits), 1), 4)
          val FP32 = in Vec(Vec(UInt( 24 bits), 1), 2)
          val TF32 = in Vec(Vec(UInt( 11 bits), 1), 2)
          val FP64 = in Vec(Vec(UInt( 53 bits), 1), 1)
        }
      }
      val sign = new Bundle{
        val mul = new Bundle{
          val BF16 = in Vec(Vec(Bool(), 16), 4)
          val FP16 = in Vec(Vec(Bool(), 16), 4)
          val FP32 = in Vec(Vec(Bool(),  8), 2)
          val TF32 = in Vec(Vec(Bool(),  8), 2)
          val FP64 = in Vec(Vec(Bool(),  4), 1)
        }
        val mac = new Bundle{
          val BF16 = in Vec(Vec(Bool(), 1), 4)
          val FP16 = in Vec(Vec(Bool(), 1), 4)
          val FP32 = in Vec(Vec(Bool(), 1), 2)
          val TF32 = in Vec(Vec(Bool(), 1), 2)
          val FP64 = in Vec(Vec(Bool(), 1), 1)
        }
        val add = new Bundle{
          val BF16 = in Vec(Vec(Bool(), 1), 4)
          val FP16 = in Vec(Vec(Bool(), 1), 4)
          val FP32 = in Vec(Vec(Bool(), 1), 2)
          val TF32 = in Vec(Vec(Bool(), 1), 2)
          val FP64 = in Vec(Vec(Bool(), 1), 1)
        }
      }
    }
    val o = new Bundle{
      // 64 -> 2 , 32 = 2^5
      val INT8 = out Vec(SInt(      32 bits), 4)
      // 64 -> 4 , 16 = 2^4
      val BF16 = out Vec(SInt( 8*2+4+1 bits), 4)
      val FP16 = out Vec(SInt(11*2+4+1 bits), 4)
      // 16 -> 2 ,  8 = 2^3
      val FP32 = out Vec(SInt(24*2+3+1 bits), 2)
      val TF32 = out Vec(SInt(11*2+3+1 bits), 2)
      //  4 -> 1 ,  4 = 2^2
      val FP64 = out Vec(SInt(53*2+2+1 bits), 1)
    }
  }
  val dut = new ADDMulti()
  dut.io.i.assignAllByName(io.i)
  dut.ctl.i.assignAllByName(ctl.i)
  io.o.assignAllByName(dut.io.o)
  val verify = new Bundle{
    val o = new Bundle{
      // 64 -> 2 , 32 = 2^5
      val INT8 = out Vec(SInt(      32 bits), 4)
      // 64 -> 4 , 16 = 2^4
      val BF16 = out Vec(SInt( 8*2+4+1 bits), 4)
      val FP16 = out Vec(SInt(11*2+4+1 bits), 4)
      // 16 -> 2 ,  8 = 2^3
      val FP32 = out Vec(SInt(24*2+3+1 bits), 2)
      val TF32 = out Vec(SInt(11*2+3+1 bits), 2)
      //  4 -> 1 ,  4 = 2^2
      val FP64 = out Vec(SInt(53*2+2+1 bits), 1)
    }
    val equal = new Bundle{
      val mul = new Bundle{
        val BF16 = out Bool()
        val FP16 = out Bool()
        val FP32 = out Bool()
        val TF32 = out Bool()
        val FP64 = out Bool()
      }
      val mac = new Bundle{
        val BF16 = out Bool()
        val FP16 = out Bool()
        val FP32 = out Bool()
        val TF32 = out Bool()
        val FP64 = out Bool()
      }
      val add = new Bundle{
        val BF16 = out Bool()
        val FP16 = out Bool()
        val FP32 = out Bool()
        val TF32 = out Bool()
        val FP64 = out Bool()
      }
    }
    val EQUAL = out Bool()
    val sim = Reg(Bool())
  }
  noIoPrefix()
  val OneComplement = new Bundle{
    val mul = new Bundle{
      val INT8 = Vec(Vec(SInt(  8*2+1 bits), 16), 4)
      val BF16 = Vec(Vec(SInt(  8*2+1 bits), 16), 4)
      val FP16 = Vec(Vec(SInt( 11*2+1 bits), 16), 4)
      val FP32 = Vec(Vec(SInt( 24*2+1 bits),  8), 2)
      val TF32 = Vec(Vec(SInt( 11*2+1 bits),  8), 2)
      val FP64 = Vec(Vec(SInt( 53*2+1 bits),  4), 1)
    }
    val mac = new Bundle{
      val INT8 = Vec(Vec(SInt(   32 bits),  1), 4)
      val BF16 = Vec(Vec(SInt(  8+1 bits),  1), 4)
      val FP16 = Vec(Vec(SInt( 11+1 bits),  1), 4)
      val FP32 = Vec(Vec(SInt( 24+1 bits),  1), 2)
      val TF32 = Vec(Vec(SInt( 11+1 bits),  1), 2)
      val FP64 = Vec(Vec(SInt( 53+1 bits),  1), 1)
    }
    val add = new Bundle{
      val INT8 = Vec(Vec(SInt(   32 bits),  1), 4)
      val BF16 = Vec(Vec(SInt(  8+1 bits),  1), 4)
      val FP16 = Vec(Vec(SInt( 11+1 bits),  1), 4)
      val FP32 = Vec(Vec(SInt( 24+1 bits),  1), 2)
      val TF32 = Vec(Vec(SInt( 11+1 bits),  1), 2)
      val FP64 = Vec(Vec(SInt( 53+1 bits),  1), 1)
    }
  }
  Array.tabulate(4)((m) => {
    Array.tabulate(16)((n) => {
      OneComplement.mul.INT8(m)(n) := io.i.mant.mul.INT8(m)(n)
    })
    OneComplement.mac.INT8(m)(0) := io.i.mant.mac.INT8(m)(0)
    OneComplement.add.INT8(m)(0) := io.i.mant.add.INT8(m)(0)
    verify.o.INT8(m) :=(ctl.i.mode.isMUL? sum(OneComplement.mul.INT8(m)) |
                   (ctl.i.mode.isMAC? sum(OneComplement.mul.INT8(m),OneComplement.mac.INT8(m))| 
                   (ctl.i.mode.isMAC? sum(OneComplement.add.INT8(m),OneComplement.mac.INT8(m))| S"0".resized))).resized
  })
  Array.tabulate(4)((m) => {
    Array.tabulate(16)((n) => {
      OneComplement.mul.BF16(m)(n) := io.i.mant.mul.BF16(m)(n).twoComplement(io.i.sign.mul.BF16(m)(n))
      OneComplement.mul.FP16(m)(n) := io.i.mant.mul.FP16(m)(n).twoComplement(io.i.sign.mul.FP16(m)(n))
    })
    OneComplement.mac.BF16(m)(0) := io.i.mant.mac.BF16(m)(0).twoComplement(io.i.sign.mac.BF16(m)(0))
    OneComplement.add.BF16(m)(0) := io.i.mant.add.BF16(m)(0).twoComplement(io.i.sign.add.BF16(m)(0))
    OneComplement.mac.FP16(m)(0) := io.i.mant.mac.FP16(m)(0).twoComplement(io.i.sign.mac.FP16(m)(0))
    OneComplement.add.FP16(m)(0) := io.i.mant.add.FP16(m)(0).twoComplement(io.i.sign.add.FP16(m)(0))
    verify.o.BF16(m) :=(ctl.i.mode.isMUL? sum(OneComplement.mul.BF16(m)) |
                   (ctl.i.mode.isMAC? sum(OneComplement.mul.BF16(m),OneComplement.mac.BF16(m))| 
                   (ctl.i.mode.isMAC? sum(OneComplement.add.BF16(m),OneComplement.mac.BF16(m))| S"0".resized))).resized
    verify.o.FP16(m) :=(ctl.i.mode.isMUL? sum(OneComplement.mul.FP16(m)) |
                   (ctl.i.mode.isMAC? sum(OneComplement.mul.FP16(m),OneComplement.mac.FP16(m))| 
                   (ctl.i.mode.isMAC? sum(OneComplement.add.FP16(m),OneComplement.mac.FP16(m))| S"0".resized))).resized
  })
  Array.tabulate(2)((m) => {
    Array.tabulate(8)((n) => {
      OneComplement.mul.FP32(m)(n) := io.i.mant.mul.FP32(m)(n).twoComplement(io.i.sign.mul.FP32(m)(n))
      OneComplement.mul.TF32(m)(n) := io.i.mant.mul.TF32(m)(n).twoComplement(io.i.sign.mul.TF32(m)(n))
    })
    OneComplement.mac.FP32(m)(0) := io.i.mant.mac.FP32(m)(0).twoComplement(io.i.sign.mac.FP32(m)(0))
    OneComplement.mac.TF32(m)(0) := io.i.mant.mac.TF32(m)(0).twoComplement(io.i.sign.mac.TF32(m)(0))
    OneComplement.add.FP32(m)(0) := io.i.mant.add.FP32(m)(0).twoComplement(io.i.sign.add.FP32(m)(0))
    OneComplement.add.TF32(m)(0) := io.i.mant.add.TF32(m)(0).twoComplement(io.i.sign.add.TF32(m)(0))
    verify.o.FP32(m) :=(ctl.i.mode.isMUL? sum(OneComplement.mul.FP32(m)) |
                   (ctl.i.mode.isMAC? sum(OneComplement.mul.FP32(m),OneComplement.mac.FP32(m))| 
                   (ctl.i.mode.isMAC? sum(OneComplement.add.FP32(m),OneComplement.mac.FP32(m))| S"0".resized))).resized
    verify.o.TF32(m) :=(ctl.i.mode.isMUL? sum(OneComplement.mul.TF32(m)) |
                   (ctl.i.mode.isMAC? sum(OneComplement.mul.TF32(m),OneComplement.mac.TF32(m))| 
                   (ctl.i.mode.isMAC? sum(OneComplement.add.TF32(m),OneComplement.mac.TF32(m))| S"0".resized))).resized
  })
  Array.tabulate(1)((m) => {
    Array.tabulate(4)((n) => {
      OneComplement.mul.FP64(m)(n) := io.i.mant.mul.FP64(m)(n).twoComplement(io.i.sign.mul.FP64(m)(n))
    })
    OneComplement.mac.FP64(m)(0) := io.i.mant.mac.FP64(m)(0).twoComplement(io.i.sign.mac.FP64(m)(0))
    OneComplement.add.FP64(m)(0) := io.i.mant.add.FP64(m)(0).twoComplement(io.i.sign.add.FP64(m)(0))
    verify.o.FP64(m) :=(ctl.i.mode.isMUL? sum(OneComplement.mul.FP64(m)) |
                   (ctl.i.mode.isMAC? sum(OneComplement.mul.FP64(m),OneComplement.mac.FP64(m))| 
                   (ctl.i.mode.isMAC? sum(OneComplement.add.FP64(m),OneComplement.mac.FP64(m))| S"0".resized))).resized
  })
    verify.equal.mul.BF16 := verify.o.BF16===io.o.BF16
    verify.equal.mul.FP16 := verify.o.FP16===io.o.FP16
    verify.equal.mac.BF16 := verify.o.BF16===io.o.BF16
    verify.equal.mac.FP16 := verify.o.FP16===io.o.FP16
    verify.equal.add.BF16 := verify.o.BF16===io.o.BF16
    verify.equal.add.FP16 := verify.o.FP16===io.o.FP16
    verify.equal.mul.FP32 := verify.o.FP32===io.o.FP32
    verify.equal.mul.TF32 := verify.o.TF32===io.o.TF32
    verify.equal.mac.FP32 := verify.o.FP32===io.o.FP32
    verify.equal.mac.TF32 := verify.o.TF32===io.o.TF32
    verify.equal.add.FP32 := verify.o.FP32===io.o.FP32
    verify.equal.add.TF32 := verify.o.TF32===io.o.TF32
    verify.equal.mul.FP64 := verify.o.FP64===io.o.FP64
    verify.equal.mac.FP64 := verify.o.FP64===io.o.FP64
    verify.equal.add.FP64 := verify.o.FP64===io.o.FP64
  when(ctl.i.mode.isBF16) {
    when(ctl.i.mode.isMUL)       {verify.EQUAL := verify.equal.mul.BF16
    }.elsewhen(ctl.i.mode.isMAC) {verify.EQUAL := verify.equal.mac.BF16
    }.elsewhen(ctl.i.mode.isADD) {verify.EQUAL := verify.equal.add.BF16
    }.otherwise {verify.EQUAL := False}
  }.elsewhen(ctl.i.mode.isFP16) {
    when(ctl.i.mode.isMUL)       {verify.EQUAL := verify.equal.mul.FP16
    }.elsewhen(ctl.i.mode.isMAC) {verify.EQUAL := verify.equal.mac.FP16
    }.elsewhen(ctl.i.mode.isADD) {verify.EQUAL := verify.equal.add.FP16
    }.otherwise {verify.EQUAL := False}
  }.elsewhen(ctl.i.mode.isFP32) {
    when(ctl.i.mode.isMUL)       {verify.EQUAL := verify.equal.mul.FP32
    }.elsewhen(ctl.i.mode.isMAC) {verify.EQUAL := verify.equal.mac.FP32
    }.elsewhen(ctl.i.mode.isADD) {verify.EQUAL := verify.equal.add.FP32
    }.otherwise {verify.EQUAL := False}
  }.elsewhen(ctl.i.mode.isTF32) {
    when(ctl.i.mode.isMUL)       {verify.EQUAL := verify.equal.mul.TF32
    }.elsewhen(ctl.i.mode.isMAC) {verify.EQUAL := verify.equal.mac.TF32
    }.elsewhen(ctl.i.mode.isADD) {verify.EQUAL := verify.equal.add.TF32
    }.otherwise {verify.EQUAL := False}
  }.elsewhen(ctl.i.mode.isFP64) {
    when(ctl.i.mode.isMUL)       {verify.EQUAL := verify.equal.mul.FP64
    }.elsewhen(ctl.i.mode.isMAC) {verify.EQUAL := verify.equal.mac.FP64
    }.elsewhen(ctl.i.mode.isADD) {verify.EQUAL := verify.equal.add.FP64
    }.otherwise {verify.EQUAL := False}
  }.otherwise {
    verify.EQUAL := False
  }
}

/* -------------------------                                          -------------------------- *\
** -------------------------    ____  _           _       _           -------------------------- **
** -------------------------   / ___|(_)_ __ ___ | | __ _| |_ ___     -------------------------- **
** -------------------------   \___ \| | '_ ` _ \| |/ _` | __/ _ \    -------------------------- **
** -------------------------    ___) | | | | | | | | (_| | ||  __/    -------------------------- **
** -------------------------   |____/|_|_| |_| |_|_|\__,_|\__\___|    -------------------------- **
\* -------------------------                                          -------------------------- */

import spinal.sim._
import spinal.core.sim._




object ADDMulti_Sim {

  def main(args: Array[String]) {

    val simConfig = SpinalConfig(
      defaultClockDomainFrequency = FixedFrequency(10 MHz),
      defaultConfigForClockDomains = ClockDomainConfig(resetKind = SYNC))
    
    val compiled = SimConfig
                    .withWave
                    .withConfig(simConfig)
                    // .allOptimisation
                    .workspacePath("simWorkspace")
                    .compile(new ADDMulti_Verif())

    def sim_MUL_BF16(times: Int = 10, seed: Int = scala.util.Random.nextInt()){
      def name: String = "sim_MUL_BF16"
      compiled.doSim(name,seed){dut =>
        //Fork a process to generate the reset and the clock on the dut
        dut.clockDomain.forkStimulus(period = 10)
        dut.ctl.i.mode #= ModeConfig.MUL_BF16
        dut.clockDomain.waitRisingEdge()
        for(_times <- 0 to times-1 ){
          Array.tabulate(16,4)((m,p) => {
            dut.io.i.mant.mul.BF16(p)(m) #= BigInt(dut.io.i.mant.mul.BF16(p)(m).getBitsWidth, scala.util.Random)
            dut.io.i.sign.mul.BF16(p)(m) #= scala.util.Random.nextBoolean()
          })
          dut.clockDomain.waitRisingEdge()
          val EQUAL = dut.verify.EQUAL.toBoolean
          if (!EQUAL) {
            System.err.println("** ERROR ** "+name+" with seed "+seed)
          }
        }
      }
      println(Console.GREEN+"** FINISHED ** "+name+" with "+times+" times")
    }
    // def sim_MUL_INT8(times: Int = 10, seed: Int = scala.util.Random.nextInt()){
    //   def name: String = "sim_MAC_BF16"
    //   compiled.doSim(name){dut =>
    //     //Fork a process to generate the reset and the clock on the dut
    //     dut.clockDomain.forkStimulus(period = 10)
    //     dut.ctl.i.mode #= ModeConfig.MAC_BF16
    //     dut.clockDomain.waitRisingEdge()
    //     for(_times <- 0 to times-1 ){
    //       Array.tabulate(16,4)((m,p) => {
    //         dut.io.i.mul.BF16(p)(m) #= BigInt(dut.io.i.mul.BF16(p)(m).getBitsWidth-1, scala.util.Random)
    //       })
    //       Array.tabulate( 1,4)((m,p) => {
    //         dut.io.i.mac.BF16(p)(m) #= BigInt(dut.io.i.mac.BF16(p)(m).getBitsWidth, scala.util.Random)
    //       })
    //       dut.clockDomain.waitRisingEdge()
    //       val EQUAL = dut.verify.EQUAL.toBoolean
    //       if (!EQUAL) {
    //         System.err.println("** ERROR ** "+name+" with seed "+seed)
    //       }
    //     }
    //   }
    //   println(Console.GREEN+"** FINISHED ** "+name+" with "+times+" times")
    // }
    
    sim_MUL_BF16(times=1000)
    // sim_MAC_BF16(times=1000000)
    // sim_ADD_BF16(times=1000000)
    // sim_MUL_FP32(times=1000000)
    // sim_MAC_FP32(times=1000000)
    // sim_ADD_FP32(times=1000000)
    // sim_MUL_FP64(times=1000000)
    // sim_MAC_FP64(times=1000000)
    // sim_ADD_FP64(times=1000000)
  }
}