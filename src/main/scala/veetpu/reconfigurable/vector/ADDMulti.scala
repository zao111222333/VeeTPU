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

class ADDBasic16(bitWidth: Int = 27) extends Component{
  val ctl = new Bundle{
    val i = new Bundle{
      val mode = in (Mode())
      val isSign = in Bool()
      val signed = in Bool()
    }
  }
  val io = new Bundle{
    val i = new Bundle{
      val sign = new Bundle{
        val mul  = in Vec(Bool(),16)
        val mac  = in Bool()
        val add  = in Bool()
      }
      val carry = in UInt(3 bits)
      val mant = new Bundle{
        val mul = in Vec(UInt(bitWidth bits), 16)
        val mac = in UInt(32 bits)
        val add = in UInt(32 bits)
      }
    }
    val o = new Bundle{
        val sum      = out UInt(32 bits)
        val overflow = out Bool()
    }
  }
  def signedBits(that:UInt)={
    ((ctl.i.signed?that.msb.asUInt|U"0") @@ that)
  }
  val sum_mul_0 = Array.tabulate(8)((m) => {
    signedBits(io.i.sign.mul(2*m).asUInt+io.i.mant.mul(2*m)) + signedBits(io.i.sign.mul(2*m+1).asUInt+io.i.mant.mul(2*m+1)) 
  })
  val sum_mul_1 = Array.tabulate(4)((m) => {
    signedBits(sum_mul_0(2*m))+signedBits(sum_mul_0(2*m+1))
  })
  val sum_mul_2 = Array.tabulate(2)((m) => {
    signedBits(sum_mul_1(2*m))+signedBits(sum_mul_1(2*m+1))
  })
  val sum_mul_3 = Array.tabulate(1)((m) => {
    signedBits(sum_mul_2(2*m))+signedBits(sum_mul_2(2*m+1))
  })
  io.o.sum := (ctl.i.mode.isADD?io.i.mant.add|signedBits(sum_mul_3(0)))+((ctl.i.mode.isMAC|ctl.i.mode.isADD)?io.i.mant.mac|U(0,32 bits))+(ctl.i.isSign?(((ctl.i.mode.isMAC|ctl.i.mode.isADD)? io.i.sign.mac.asUInt|U"0")+^(ctl.i.mode.isADD? io.i.sign.add.asUInt|U"0"))|U"00")+io.i.carry
  
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
  val ADDs = Array.tabulate(4)((m) => {new ADDBasic16()})
  Array.tabulate(4)((m) => {
    ADDs(m).ctl.i.mode := ctl.i.mode
    ADDs(m).ctl.i.isSign := (ctl.i.mode.isINT8 | ctl.i.mode.isBF16 | ctl.i.mode.isFP16) ? True | 
                                               ((ctl.i.mode.isTF32 | ctl.i.mode.isFP32) ? (m%2 match {
                                                                                            case 0 => True
                                                                                            case 1 => False
                                                                                          })|
                                                                     (ctl.i.mode.isFP64 ? (m match {
                                                                                            case 0 => True
                                                                                            case _ => False
                                                                                          })|
                                                                                          False))
    ADDs(m).ctl.i.signed := (ctl.i.mode.isINT8 | ctl.i.mode.isBF16 | ctl.i.mode.isFP16) ? True |
                                               ((ctl.i.mode.isTF32 | ctl.i.mode.isFP32) ? (m%2 match {
                                                                                            case 0 => False
                                                                                            case 1 => True
                                                                                          })|
                                                                     (ctl.i.mode.isFP64 ? (m match {
                                                                                            case 3 => True
                                                                                            case _ => False
                                                                                          })|
                                                                                          False))
    ADDs(m).io.i.sign.add := ctl.i.mode.isINT8 ? False |
      ((ctl.i.mode.isFP16 | ctl.i.mode.isBF16) ? io.i.sign.add.FP16(m)(0) | 
      ((ctl.i.mode.isFP32 | ctl.i.mode.isTF32) ? (m%2 match {
                                                    case 0 => io.i.sign.add.FP32(m/2)(0)
                                                    case 1 => False
                                                  }) | 
                            (ctl.i.mode.isFP64 ? (m match {
                                                    case 0 => io.i.sign.add.FP64(0)(0)
                                                    case 1 => False
                                                    case 2 => False
                                                    case 3 => False
                                                  }) | 
                                                 False)))
    ADDs(m).io.i.sign.mac := ctl.i.mode.isINT8 ? False |
      ((ctl.i.mode.isFP16 | ctl.i.mode.isBF16) ? io.i.sign.mac.FP16(m)(0) | 
      ((ctl.i.mode.isFP32 | ctl.i.mode.isTF32) ? (m%2 match {
                                                    case 0 => io.i.sign.mac.FP32(m/2)(0)
                                                    case 1 => False
                                                  }) | 
                            (ctl.i.mode.isFP64 ? (m match {
                                                    case 0 => io.i.sign.mac.FP64(0)(0)
                                                    case 1 => False
                                                    case 2 => False
                                                    case 3 => False
                                                  }) | 
                                                 False)))
    ADDs(m).io.i.mant.add := ctl.i.mode.isINT8 ? OneComplement.add.INT8(m)(0) |
      ((ctl.i.mode.isFP16 | ctl.i.mode.isBF16) ? OneComplement.add.FP16(m)(0).asSInt.resize(32).asUInt | 
      ((ctl.i.mode.isFP32 | ctl.i.mode.isTF32) ? (m%2 match {
                                                    case 0 => OneComplement.add.FP32(m/2)(0).asSInt.resize(32).asUInt
                                                    case 1 => U(0, 32 bits)
                                                    // case 1 => OneComplement.add.FP32(m%2)(0)(27 to 3)
                                                  }) | 
                            (ctl.i.mode.isFP64 ? (m match {
                                                    case 0 => OneComplement.add.FP64(0)(0)( 0 to 27-1).resized
                                                    case 1 => OneComplement.add.FP64(0)(0)(27 to 53).asSInt.resize(32).asUInt
                                                    case 2 => U(0, 32 bits)
                                                    case 3 => U(0, 32 bits)
                                                    // case 1 => OneComplement.add.FP32(m%2)(0)(27 to 3)
                                                  }) | 
                                                 U(0, 32 bits))))
    ADDs(m).io.i.mant.mac := ctl.i.mode.isINT8 ? OneComplement.mac.INT8(m)(0) |
          ((ctl.i.mode.isFP16 | ctl.i.mode.isBF16) ? OneComplement.mac.FP16(m)(0).asSInt.resize(32).asUInt | 
          ((ctl.i.mode.isFP32 | ctl.i.mode.isTF32) ? (m%2 match {
                                                        case 0 => OneComplement.mac.FP32(m/2)(0).asSInt.resize(32).asUInt
                                                        case 1 => U(0, 32 bits)
                                                        // case 1 => OneComplement.mac.FP32(m%2)(0)(27 to 3)
                                                      }) | 
                                (ctl.i.mode.isFP64 ? (m match {
                                                        case 0 => OneComplement.mac.FP64(0)(0)( 0 to 27-1).resized
                                                        case 1 => OneComplement.mac.FP64(0)(0)(27 to 53).asSInt.resize(32).asUInt
                                                        case 2 => U(0, 32 bits)
                                                        case 3 => U(0, 32 bits)
                                                        // case 1 => OneComplement.mac.FP32(m%2)(0)(27 to 3)
                                                      }) | 
                                                     U(0, 32 bits))))
    ADDs(m).io.i.carry   := (ctl.i.mode.isINT8 | ctl.i.mode.isBF16 | ctl.i.mode.isFP16) ? U(0, 3 bits) | 
                                               ((ctl.i.mode.isTF32 | ctl.i.mode.isFP32) ? (m match {
                                                                                            case 0 => U(0, 3 bits)
                                                                                            case 1 => ADDs(0).io.o.sum(27 to 29)
                                                                                            case 2 => U(0, 3 bits)
                                                                                            case 3 => ADDs(2).io.o.sum(27 to 29)
                                                                                          })|
                                                                     (ctl.i.mode.isFP64 ? (m match {
                                                                                            case 0 => U(0, 3 bits)
                                                                                            case _ => ADDs(m-1).io.o.sum(27 to 29)
                                                                                          })|
                                                                                          U(0, 3 bits)))
    Array.tabulate(16)((n) => {
      ADDs(m).io.i.sign.mul(n) := ctl.i.mode.isINT8 ? False |
           ((ctl.i.mode.isFP16 | ctl.i.mode.isBF16) ? io.i.sign.mul.FP16(m)(n) | 
           ((ctl.i.mode.isFP32 | ctl.i.mode.isTF32) ? (m%2 match {
                                                         case 0 => (if (n<8) io.i.sign.mul.FP32(m/2)(n) else False)
                                                         case 1 => False
                                                       }) |
                                 (ctl.i.mode.isFP64 ? (m match {
                                                         case 0 => (if (n<4) io.i.sign.mul.FP64(m)(n) else False)
                                                         case 1 => False
                                                         case 2 => False
                                                         case 3 => False
                                                       }) | 
                                                      False)))
      ADDs(m).io.i.mant.mul(n) := ctl.i.mode.isINT8 ? (OneComplement.mul.INT8(m)(n).asSInt).resize(27).asUInt |
           ((ctl.i.mode.isFP16 | ctl.i.mode.isBF16) ? OneComplement.mul.FP16(m)(n).asSInt.resize(27).asUInt | 
           ((ctl.i.mode.isFP32 | ctl.i.mode.isTF32) ? (m%2 match {
                                                         case 0 => (if (n<8) OneComplement.mul.FP32(m/2)(n)( 0 to 26) else U(0, 27 bits))
                                                         case 1 => (if (n<8) OneComplement.mul.FP32(m/2)(n)(27 to 48).asSInt.resize(27).asUInt else U(0, 27 bits))
                                                       }) |
                                 (ctl.i.mode.isFP64 ? (m match {
                                                         case 0 => (if (n<4) OneComplement.mul.FP64(0)(n)( 0 to  26).resized else U(0, 27 bits))
                                                         case 1 => (if (n<4) OneComplement.mul.FP64(0)(n)(27 to  53).resized else U(0, 27 bits))
                                                         case 2 => (if (n<4) OneComplement.mul.FP64(0)(n)(54 to  80).resized else U(0, 27 bits))
                                                         case 3 => (if (n<4) OneComplement.mul.FP64(0)(n)(81 to 106).asSInt.resize(27).asUInt else U(0, 27 bits))
                                                       }) |
                                                      U(0, 27 bits))))
    })
  })
  Array.tabulate(4)((m) => {
    io.o.INT8(m) := ADDs(m).io.o.sum.asSInt.resized
    io.o.FP16(m) := ADDs(m).io.o.sum.asSInt.resized
    io.o.BF16(m) := ADDs(m).io.o.sum.asSInt.resized
  })
  Array.tabulate(2)((m) => {
    io.o.FP32(m) := ((ctl.i.mode.isADD?ADDs(2*m).io.o.sum(26).asSInt.resize(25).asUInt|ADDs(2*m+1).io.o.sum(27-27 to 51-27)) @@ ADDs(2*m).io.o.sum(0 to 26)).asSInt
    io.o.TF32(m) := ADDs(2*m).io.o.sum(0 to 25).asSInt
  })
  Array.tabulate(1)((m) => {
    io.o.FP64(m) := ((ctl.i.mode.isADD?
                          ADDs(1).io.o.sum(27).asSInt.resize(55).asUInt|
                          ADDs(3).io.o.sum(81-3*27 to 108-3*27) @@ ADDs(2).io.o.sum(54-2*27 to 80-2*27)
                      ) @@
                      ADDs(1).io.o.sum(27-1*27 to 53-1*27) @@ ADDs(0).io.o.sum(0 to 26)).asSInt
  })
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
        val INT8 = out Bool()
        val BF16 = out Bool()
        val FP16 = out Bool()
        val FP32 = out Bool()
        val TF32 = out Bool()
        val FP64 = out Bool()
      }
      val mac = new Bundle{
        val INT8 = out Bool()
        val BF16 = out Bool()
        val FP16 = out Bool()
        val FP32 = out Bool()
        val TF32 = out Bool()
        val FP64 = out Bool()
      }
      val add = new Bundle{
        val INT8 = out Bool()
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
  val TwoComplement = new Bundle{
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
      TwoComplement.mul.INT8(m)(n) := io.i.mant.mul.INT8(m)(n)
    })
    TwoComplement.mac.INT8(m)(0) := io.i.mant.mac.INT8(m)(0)
    TwoComplement.add.INT8(m)(0) := io.i.mant.add.INT8(m)(0)
    verify.o.INT8(m) :=(ctl.i.mode.isMUL? sum(TwoComplement.mul.INT8(m)) |
                    (ctl.i.mode.isMAC? sum(TwoComplement.mul.INT8(m),TwoComplement.mac.INT8(m))| 
                    (ctl.i.mode.isADD? sum(TwoComplement.add.INT8(m),TwoComplement.mac.INT8(m))| S"0".resized))).resized
  })
  Array.tabulate(4)((m) => {
    Array.tabulate(16)((n) => {
      TwoComplement.mul.BF16(m)(n) := io.i.mant.mul.BF16(m)(n).twoComplement(io.i.sign.mul.BF16(m)(n))
      TwoComplement.mul.FP16(m)(n) := io.i.mant.mul.FP16(m)(n).twoComplement(io.i.sign.mul.FP16(m)(n))
    })
    TwoComplement.mac.BF16(m)(0) := io.i.mant.mac.BF16(m)(0).twoComplement(io.i.sign.mac.BF16(m)(0))
    TwoComplement.add.BF16(m)(0) := io.i.mant.add.BF16(m)(0).twoComplement(io.i.sign.add.BF16(m)(0))
    TwoComplement.mac.FP16(m)(0) := io.i.mant.mac.FP16(m)(0).twoComplement(io.i.sign.mac.FP16(m)(0))
    TwoComplement.add.FP16(m)(0) := io.i.mant.add.FP16(m)(0).twoComplement(io.i.sign.add.FP16(m)(0))
    verify.o.BF16(m) :=(ctl.i.mode.isMUL? sum(TwoComplement.mul.BF16(m)) |
                    (ctl.i.mode.isMAC? sum(TwoComplement.mul.BF16(m),TwoComplement.mac.BF16(m))| 
                    (ctl.i.mode.isMAC? sum(TwoComplement.add.BF16(m),TwoComplement.mac.BF16(m))| S"0".resized))).resized
    verify.o.FP16(m) :=(ctl.i.mode.isMUL? sum(TwoComplement.mul.FP16(m)) |
                    (ctl.i.mode.isMAC? sum(TwoComplement.mul.FP16(m),TwoComplement.mac.FP16(m))| 
                    (ctl.i.mode.isADD? sum(TwoComplement.add.FP16(m),TwoComplement.mac.FP16(m))| S"0".resized))).resized
  })
  Array.tabulate(2)((m) => {
    Array.tabulate(8)((n) => {
      TwoComplement.mul.FP32(m)(n) := io.i.mant.mul.FP32(m)(n).twoComplement(io.i.sign.mul.FP32(m)(n))
      TwoComplement.mul.TF32(m)(n) := io.i.mant.mul.TF32(m)(n).twoComplement(io.i.sign.mul.TF32(m)(n))
    })
    TwoComplement.mac.FP32(m)(0) := io.i.mant.mac.FP32(m)(0).twoComplement(io.i.sign.mac.FP32(m)(0))
    TwoComplement.mac.TF32(m)(0) := io.i.mant.mac.TF32(m)(0).twoComplement(io.i.sign.mac.TF32(m)(0))
    TwoComplement.add.FP32(m)(0) := io.i.mant.add.FP32(m)(0).twoComplement(io.i.sign.add.FP32(m)(0))
    TwoComplement.add.TF32(m)(0) := io.i.mant.add.TF32(m)(0).twoComplement(io.i.sign.add.TF32(m)(0))
    verify.o.FP32(m) :=(ctl.i.mode.isMUL? sum(TwoComplement.mul.FP32(m)) |
                    (ctl.i.mode.isMAC? sum(TwoComplement.mul.FP32(m),TwoComplement.mac.FP32(m))| 
                    (ctl.i.mode.isADD? sum(TwoComplement.add.FP32(m),TwoComplement.mac.FP32(m))| S"0".resized))).resized
    verify.o.TF32(m) :=(ctl.i.mode.isMUL? sum(TwoComplement.mul.TF32(m)) |
                    (ctl.i.mode.isMAC? sum(TwoComplement.mul.TF32(m),TwoComplement.mac.TF32(m))| 
                    (ctl.i.mode.isADD? sum(TwoComplement.add.TF32(m),TwoComplement.mac.TF32(m))| S"0".resized))).resized
  })
  Array.tabulate(1)((m) => {
    Array.tabulate(4)((n) => {
      TwoComplement.mul.FP64(m)(n) := io.i.mant.mul.FP64(m)(n).twoComplement(io.i.sign.mul.FP64(m)(n))
    })
    TwoComplement.mac.FP64(m)(0) := io.i.mant.mac.FP64(m)(0).twoComplement(io.i.sign.mac.FP64(m)(0))
    TwoComplement.add.FP64(m)(0) := io.i.mant.add.FP64(m)(0).twoComplement(io.i.sign.add.FP64(m)(0))
    verify.o.FP64(m) :=(ctl.i.mode.isMUL? sum(TwoComplement.mul.FP64(m)) |
                    (ctl.i.mode.isMAC? sum(TwoComplement.mul.FP64(m),TwoComplement.mac.FP64(m))| 
                    (ctl.i.mode.isADD? sum(TwoComplement.add.FP64(m),TwoComplement.mac.FP64(m))| S"0".resized))).resized
  })
    verify.equal.mul.INT8 := verify.o.INT8===io.o.INT8
    verify.equal.mac.INT8 := verify.o.INT8===io.o.INT8
    verify.equal.add.INT8 := verify.o.INT8===io.o.INT8
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
  when(ctl.i.mode.isINT8) {
    when(ctl.i.mode.isMUL)       {verify.EQUAL := verify.equal.mul.INT8
    }.elsewhen(ctl.i.mode.isMAC) {verify.EQUAL := verify.equal.mac.INT8
    }.elsewhen(ctl.i.mode.isADD) {verify.EQUAL := verify.equal.add.INT8
    }.otherwise {verify.EQUAL := False}
  }.elsewhen(ctl.i.mode.isBF16) {
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

    def sim_MUL_INT8(times: Int = 10, seed: Int = scala.util.Random.nextInt()){
      def name: String = "sim_MUL_INT8"
      compiled.doSim(name,seed){dut =>
        //Fork a process to generate the reset and the clock on the dut
        dut.clockDomain.forkStimulus(period = 10)
        dut.ctl.i.mode #= ModeConfig.MUL_INT8
        dut.clockDomain.waitRisingEdge()
        for(_times <- 0 to times-1 ){
          Array.tabulate(16,4)((m,p) => {
            dut.io.i.mant.mul.INT8(p)(m) #= BigInt(17, scala.util.Random)-65536 //2^17-1 -2^16
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
    def sim_MAC_INT8(times: Int = 10, seed: Int = scala.util.Random.nextInt()){
      def name: String = "sim_MAC_INT8"
      compiled.doSim(name,seed){dut =>
        //Fork a process to generate the reset and the clock on the dut
        dut.clockDomain.forkStimulus(period = 10)
        dut.ctl.i.mode #= ModeConfig.MAC_INT8
        dut.clockDomain.waitRisingEdge()
        for(_times <- 0 to times-1 ){
          Array.tabulate(16,4)((m,p) => {
            dut.io.i.mant.mul.INT8(p)(m) #= BigInt(17, scala.util.Random)-65536 //2^17-1 -2^16
          })
          Array.tabulate(4)((p) => {
            dut.io.i.mant.mac.INT8(p)(0) #= BigInt(32, scala.util.Random)-BigInt("2147483648") //2^17-1 -2^16
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
    def sim_ADD_INT8(times: Int = 10, seed: Int = scala.util.Random.nextInt()){
      def name: String = "sim_ADD_INT8"
      compiled.doSim(name,seed){dut =>
        //Fork a process to generate the reset and the clock on the dut
        dut.clockDomain.forkStimulus(period = 10)
        dut.ctl.i.mode #= ModeConfig.ADD_INT8
        dut.clockDomain.waitRisingEdge()
        for(_times <- 0 to times-1 ){
          Array.tabulate(4)((p) => {
            dut.io.i.mant.mac.INT8(p)(0) #= BigInt(32, scala.util.Random)-BigInt("2147483648") //2^17-1 -2^16
            dut.io.i.mant.add.INT8(p)(0) #= BigInt(32, scala.util.Random)-BigInt("2147483648") //2^17-1 -2^16
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
    def sim_MUL_FP16(times: Int = 10, seed: Int = scala.util.Random.nextInt()){
      def name: String = "sim_MUL_FP16"
      compiled.doSim(name,seed){dut =>
        //Fork a process to generate the reset and the clock on the dut
        dut.clockDomain.forkStimulus(period = 10)
        dut.ctl.i.mode #= ModeConfig.MUL_FP16
        dut.clockDomain.waitRisingEdge()
        for(_times <- 0 to times-1 ){
          Array.tabulate(16,4)((m,p) => {
            dut.io.i.mant.mul.FP16(p)(m) #= BigInt(dut.io.i.mant.mul.FP16(p)(m).getBitsWidth, scala.util.Random)
            dut.io.i.sign.mul.FP16(p)(m) #= scala.util.Random.nextBoolean()
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
    def sim_MAC_FP16(times: Int = 10, seed: Int = scala.util.Random.nextInt()){
      def name: String = "sim_MAC_FP16"
      compiled.doSim(name,seed){dut =>
        //Fork a process to generate the reset and the clock on the dut
        dut.clockDomain.forkStimulus(period = 10)
        dut.ctl.i.mode #= ModeConfig.MAC_FP16
        dut.clockDomain.waitRisingEdge()
        for(_times <- 0 to times-1 ){
          Array.tabulate(16,4)((m,p) => {
            dut.io.i.mant.mul.FP16(p)(m) #= BigInt(dut.io.i.mant.mul.FP16(p)(m).getBitsWidth, scala.util.Random)
            dut.io.i.sign.mul.FP16(p)(m) #= scala.util.Random.nextBoolean()
          })
          Array.tabulate(4)((p) => {
            dut.io.i.mant.mac.FP16(p)(0) #= BigInt(dut.io.i.mant.mac.FP16(p)(0).getBitsWidth, scala.util.Random)
            dut.io.i.sign.mac.FP16(p)(0) #= scala.util.Random.nextBoolean()
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
    def sim_ADD_FP16(times: Int = 10, seed: Int = scala.util.Random.nextInt()){
      def name: String = "sim_ADD_FP16"
      compiled.doSim(name,seed){dut =>
        //Fork a process to generate the reset and the clock on the dut
        dut.clockDomain.forkStimulus(period = 10)
        dut.ctl.i.mode #= ModeConfig.ADD_FP16
        dut.clockDomain.waitRisingEdge()
        for(_times <- 0 to times-1 ){
          Array.tabulate(4)((p) => {
            dut.io.i.mant.mac.FP16(p)(0) #= BigInt(dut.io.i.mant.mac.FP16(p)(0).getBitsWidth, scala.util.Random)
            dut.io.i.sign.mac.FP16(p)(0) #= scala.util.Random.nextBoolean()
            dut.io.i.mant.add.FP16(p)(0) #= BigInt(dut.io.i.mant.add.FP16(p)(0).getBitsWidth, scala.util.Random)
            dut.io.i.sign.add.FP16(p)(0) #= scala.util.Random.nextBoolean()
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
    def sim_MUL_FP32(times: Int = 10, seed: Int = scala.util.Random.nextInt()){
      def name: String = "sim_MUL_FP32"
      compiled.doSim(name,seed){dut =>
        //Fork a process to generate the reset and the clock on the dut
        dut.clockDomain.forkStimulus(period = 10)
        dut.ctl.i.mode #= ModeConfig.MUL_FP32
        dut.clockDomain.waitRisingEdge()
        for(_times <- 0 to times-1 ){
          Array.tabulate(8,2)((m,p) => {
            dut.io.i.mant.mul.FP32(p)(m) #= BigInt(dut.io.i.mant.mul.FP32(p)(m).getBitsWidth, scala.util.Random)
            dut.io.i.sign.mul.FP32(p)(m) #= scala.util.Random.nextBoolean()
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
    def sim_MAC_FP32(times: Int = 10, seed: Int = scala.util.Random.nextInt()){
      def name: String = "sim_MAC_FP32"
      compiled.doSim(name,seed){dut =>
        //Fork a process to generate the reset and the clock on the dut
        dut.clockDomain.forkStimulus(period = 10)
        dut.ctl.i.mode #= ModeConfig.MAC_FP32
        dut.clockDomain.waitRisingEdge()
        for(_times <- 0 to times-1 ){
          Array.tabulate(8,2)((m,p) => {
            dut.io.i.mant.mul.FP32(p)(m) #= BigInt(dut.io.i.mant.mul.FP32(p)(m).getBitsWidth, scala.util.Random)
            dut.io.i.sign.mul.FP32(p)(m) #= scala.util.Random.nextBoolean()
          })
          Array.tabulate(2)((p) => {
            dut.io.i.mant.mac.FP32(p)(0) #= BigInt(dut.io.i.mant.mac.FP32(p)(0).getBitsWidth, scala.util.Random)
            dut.io.i.sign.mac.FP32(p)(0) #= scala.util.Random.nextBoolean()
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
    def sim_ADD_FP32(times: Int = 10, seed: Int = scala.util.Random.nextInt()){
      def name: String = "sim_ADD_FP32"
      compiled.doSim(name,seed){dut =>
        //Fork a process to generate the reset and the clock on the dut
        dut.clockDomain.forkStimulus(period = 10)
        dut.ctl.i.mode #= ModeConfig.ADD_FP32
        dut.clockDomain.waitRisingEdge()
        for(_times <- 0 to times-1 ){
          Array.tabulate(2)((p) => {
            dut.io.i.mant.mac.FP32(p)(0) #= BigInt(dut.io.i.mant.mac.FP32(p)(0).getBitsWidth, scala.util.Random)
            dut.io.i.sign.mac.FP32(p)(0) #= scala.util.Random.nextBoolean()
            dut.io.i.mant.add.FP32(p)(0) #= BigInt(dut.io.i.mant.add.FP32(p)(0).getBitsWidth, scala.util.Random)
            dut.io.i.sign.add.FP32(p)(0) #= scala.util.Random.nextBoolean()
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
    def sim_MUL_FP64(times: Int = 10, seed: Int = scala.util.Random.nextInt()){
      def name: String = "sim_MUL_FP64"
      compiled.doSim(name,seed){dut =>
        //Fork a process to generate the reset and the clock on the dut
        dut.clockDomain.forkStimulus(period = 10)
        dut.ctl.i.mode #= ModeConfig.MUL_FP64
        dut.clockDomain.waitRisingEdge()
        for(_times <- 0 to times-1 ){
          Array.tabulate(4,1)((m,p) => {
            dut.io.i.mant.mul.FP64(p)(m) #= BigInt(dut.io.i.mant.mul.FP64(p)(m).getBitsWidth, scala.util.Random)
            dut.io.i.sign.mul.FP64(p)(m) #= scala.util.Random.nextBoolean()
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
    def sim_MAC_FP64(times: Int = 10, seed: Int = scala.util.Random.nextInt()){
      def name: String = "sim_MAC_FP64"
      compiled.doSim(name,seed){dut =>
        //Fork a process to generate the reset and the clock on the dut
        dut.clockDomain.forkStimulus(period = 10)
        dut.ctl.i.mode #= ModeConfig.MAC_FP64
        dut.clockDomain.waitRisingEdge()
        for(_times <- 0 to times-1 ){
          Array.tabulate(4,1)((m,p) => {
            dut.io.i.mant.mul.FP64(p)(m) #= BigInt(dut.io.i.mant.mul.FP64(p)(m).getBitsWidth, scala.util.Random)
            dut.io.i.sign.mul.FP64(p)(m) #= scala.util.Random.nextBoolean()
          })
          Array.tabulate(1)((p) => {
            dut.io.i.mant.mac.FP64(p)(0) #= BigInt(dut.io.i.mant.mac.FP64(p)(0).getBitsWidth, scala.util.Random)
            dut.io.i.sign.mac.FP64(p)(0) #= scala.util.Random.nextBoolean()
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
    def sim_ADD_FP64(times: Int = 10, seed: Int = scala.util.Random.nextInt()){
      def name: String = "sim_ADD_FP64"
      compiled.doSim(name,seed){dut =>
        //Fork a process to generate the reset and the clock on the dut
        dut.clockDomain.forkStimulus(period = 10)
        dut.ctl.i.mode #= ModeConfig.ADD_FP64
        dut.clockDomain.waitRisingEdge()
        for(_times <- 0 to times-1 ){
          Array.tabulate(1)((p) => {
            dut.io.i.mant.mac.FP64(p)(0) #= BigInt(dut.io.i.mant.mac.FP64(p)(0).getBitsWidth, scala.util.Random)
            dut.io.i.sign.mac.FP64(p)(0) #= scala.util.Random.nextBoolean()
            dut.io.i.mant.add.FP64(p)(0) #= BigInt(dut.io.i.mant.add.FP64(p)(0).getBitsWidth, scala.util.Random)
            dut.io.i.sign.add.FP64(p)(0) #= scala.util.Random.nextBoolean()
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

    // sim_MUL_INT8(times=100000)
    // sim_MAC_INT8(times=100000)
    // sim_ADD_INT8(times=100000)
    // sim_MUL_FP16(times=100000)
    // sim_MAC_FP16(times=100000)
    // sim_ADD_FP16(times=100000)
    // sim_MUL_FP32(times=100000)
    // sim_MAC_FP32(times=100000)
    // sim_ADD_FP32(times=100000)
    // sim_MUL_FP64(times=100000)
    sim_MAC_FP64(times=100000,seed = -75150430)
    sim_ADD_FP64(times=100000)
  }
}