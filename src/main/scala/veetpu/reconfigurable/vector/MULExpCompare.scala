package veetpu.reconfigurable.vector

import spinal.core._
import spinal.lib._

import ip._
import fp._


/* --------------------------------                             -------------------------------- *\
** --------------------------------    ____    _____   _        -------------------------------- **
** --------------------------------   |  _ \  |_   _| | |       -------------------------------- **
** --------------------------------   | |_) |   | |   | |       -------------------------------- **
** --------------------------------   |  _ <    | |   | |___    -------------------------------- **
** --------------------------------   |_| \_\   |_|   |_____|   -------------------------------- **
\* --------------------------------                             -------------------------------- */
class MULExpCompareBasic() extends Component{
  val ctl = new Bundle{
    val i = new Bundle{
      val isMode0 = in Bool()
    }
  }
  val io = new Bundle{
    val i = new Bundle{
      val Mode0 = in Vec(Vec(UInt( 8 bits), 2), 2)
      val Mode1 = in Vec(Vec(UInt(16 bits), 2), 1)
    }
    val o = new Bundle{
      val Mode0 = out Vec(UInt( 8 bits), 2)
      val Mode1 = out Vec(UInt(16 bits), 1)
    }
  }
  noIoPrefix()
  val INT8 = Vec(Vec(UInt( 8 bits), 2), 2)
  INT8(0)(0) := ctl.i.isMode0? io.i.Mode0(0)(0)|io.i.Mode1(0)(0)(0 to 7 )
  INT8(0)(1) := ctl.i.isMode0? io.i.Mode0(0)(1)|io.i.Mode1(0)(1)(0 to 7 )
  INT8(1)(0) := ctl.i.isMode0? io.i.Mode0(1)(0)|io.i.Mode1(0)(0)(8 to 15)
  INT8(1)(1) := ctl.i.isMode0? io.i.Mode0(1)(1)|io.i.Mode1(0)(1)(8 to 15)
  val equal = io.i.Mode1(0)(0)(8 to 15) === io.i.Mode1(0)(1)(8 to 15)
  val compare = Array.tabulate(2)((m) => {INT8(m)(0)>INT8(m)(1)})
  val Selcet_Mode1 = compare(1) || (!compare(1)&compare(0)&equal)
  val Selcet = Vec(Bool(), 2)
  Array.tabulate(2)((m) => {
    Selcet(m) := ctl.i.isMode0? compare(m)|Selcet_Mode1
  })
  val max = Array.tabulate(2)((m) => {Selcet(m)?INT8(m)(0)|INT8(m)(1)})
  io.o.Mode0(0) := max(0)
  io.o.Mode0(1) := max(1)
  io.o.Mode1(0) := max(1) @@ max(0)
}

class MULExpCompareDiff() extends Component{
  val ctl = new Bundle{
    val i = new Bundle{
      val isINT8 = in Bool()
    }
  }
  val io = new Bundle{
    val i = new Bundle{
      val INT8  = in Vec(UInt( 8 bits), 2)
      val INT16 = in Vec(UInt(16 bits), 1)
      val max = new Bundle{
        val INT8  = in UInt( 8 bits)
        val INT16 = in UInt(16 bits)
      }
    }
    val o = new Bundle{
      val INT8  = out Vec(UInt( 8 bits), 2)
      val INT16 = out Vec(UInt(16 bits), 1)
    }
  }
  noIoPrefix()
  val INT8_minus  = Vec(UInt( 8+1 bits), 2)
  val INT16_minus = io.i.INT16(0).twoComplement(True)
  INT8_minus(0) := ctl.i.isINT8? io.i.INT8(0).twoComplement(True).asUInt|INT16_minus(0 to 7).asUInt.resize(9)
  INT8_minus(1) := ctl.i.isINT8? io.i.INT8(1).twoComplement(True).asUInt|INT16_minus(8 to 16).asUInt
  val UINT_ADDs = Vec(UInt( 8+1 bits), 2)
  UINT_ADDs(0) := (INT8_minus(0)+(ctl.i.isINT8? io.i.max.INT8|io.i.max.INT16(0 to 7 )))
  UINT_ADDs(1) := (INT8_minus(1)+(ctl.i.isINT8? io.i.max.INT8|io.i.max.INT16(8 to 15)))+(ctl.i.isINT8? U"0"|UINT_ADDs(0).msb.asUInt)
  io.o.INT8(0)  := UINT_ADDs(0).resized
  io.o.INT8(1)  := UINT_ADDs(1).resized
  io.o.INT16(0) := UINT_ADDs(1).resize(8) @@ UINT_ADDs(0).resize(8)
}

class MULExpCompare() extends Component{
  noIoPrefix()
  val ctl = new Bundle{
    val i = new Bundle{
      val mode = in (Mode())
    }
  }
  val io = new Bundle{
    val i = new Bundle{
      val mul = new Bundle{
        val BF16 = in Vec(Vec(UInt( 7+1 bits), 16), 4)
        val FP16 = in Vec(Vec(UInt( 5+1 bits), 16), 4)
        val FP32 = in Vec(Vec(UInt( 8+1 bits),  8), 2)
        val TF32 = in Vec(Vec(UInt( 8+1 bits),  8), 2)
        val FP64 = in Vec(Vec(UInt(11+1 bits),  4), 1)
      }
      val mac = new Bundle{
        val BF16 = in Vec(Vec(UInt( 7 bits), 1), 4)
        val FP16 = in Vec(Vec(UInt( 5 bits), 1), 4)
        val FP32 = in Vec(Vec(UInt( 8 bits), 1), 2)
        val TF32 = in Vec(Vec(UInt( 8 bits), 1), 2)
        val FP64 = in Vec(Vec(UInt(11 bits), 1), 1)
      }
      val add = new Bundle{
        val BF16 = in Vec(Vec(UInt( 7 bits), 1), 4)
        val FP16 = in Vec(Vec(UInt( 5 bits), 1), 4)
        val FP32 = in Vec(Vec(UInt( 8 bits), 1), 2)
        val TF32 = in Vec(Vec(UInt( 8 bits), 1), 2)
        val FP64 = in Vec(Vec(UInt(11 bits), 1), 1)
      }
    }
    val o = new Bundle{
      val max = new Bundle{
        val BF16 = out Vec(UInt( 7+1 bits), 4)
        val FP16 = out Vec(UInt( 5+1 bits), 4)
        val FP32 = out Vec(UInt( 8+1 bits), 2)
        val TF32 = out Vec(UInt( 8+1 bits), 2)
        val FP64 = out Vec(UInt(11+1 bits), 1)
      }
      val diff = new Bundle{
        val mul = new Bundle{
          val BF16 = out Vec(Vec(UInt( 7+1 bits), 16), 4)
          val FP16 = out Vec(Vec(UInt( 5+1 bits), 16), 4)
          val FP32 = out Vec(Vec(UInt( 8+1 bits),  8), 2)
          val TF32 = out Vec(Vec(UInt( 8+1 bits),  8), 2)
          val FP64 = out Vec(Vec(UInt(11+1 bits),  4), 1)
        }
        val mac = new Bundle{
          val BF16 = out Vec(Vec(UInt( 7+1 bits), 1), 4)
          val FP16 = out Vec(Vec(UInt( 5+1 bits), 1), 4)
          val FP32 = out Vec(Vec(UInt( 8+1 bits), 1), 2)
          val TF32 = out Vec(Vec(UInt( 8+1 bits), 1), 2)
          val FP64 = out Vec(Vec(UInt(11+1 bits), 1), 1)
        }
        val add = new Bundle{
          val BF16 = out Vec(Vec(UInt( 7+1 bits), 1), 4)
          val FP16 = out Vec(Vec(UInt( 5+1 bits), 1), 4)
          val FP32 = out Vec(Vec(UInt( 8+1 bits), 1), 2)
          val TF32 = out Vec(Vec(UInt( 8+1 bits), 1), 2)
          val FP64 = out Vec(Vec(UInt(11+1 bits), 1), 1)
        }
      }
    }
  }
  val max = new Area{
    val COMPAREs_0 = Array.tabulate(4,4)((m,n) => {
      def gen():MULExpCompareBasic={
        val compare = new MULExpCompareBasic()
        compare.ctl.i.isMode0 := (ctl.i.mode.isBF16|ctl.i.mode.isFP16)
        compare.io.i.Mode0(0)(0) := io.i.mul.BF16(m)(4*n)
        compare.io.i.Mode0(0)(1) := io.i.mul.BF16(m)(4*n+1)
        compare.io.i.Mode0(1)(0) := io.i.mul.BF16(m)(4*n+2)
        compare.io.i.Mode0(1)(1) := io.i.mul.BF16(m)(4*n+3)
        Array.tabulate(2)((p) => {
          compare.io.i.Mode1(0)(p) := (((ctl.i.mode.isFP32|ctl.i.mode.isTF32) ? 
                                                                        //  FP32 or TF32
                                                                        (if(m<=1){
                                                                          io.i.mul.FP32(m)(2*n+p).resize(16)
                                                                        }else{
                                                                          U"0".resize(16)
                                                                        })|
                                                        ((ctl.i.mode.isFP64) ?
                                                                        //  FP64
                                                                        (if(m==0){
                                                                          (if(n<=1){
                                                                            io.i.mul.FP64(m)(2*n+p).resize(16)
                                                                        }else{
                                                                          U"0".resize(16)
                                                                        })
                                                                        }else{
                                                                          U"0".resize(16)
                                                                        })
                                                                        //  Defalut
                                                                        | U"0".resize(16)
          )))
        })
        return compare
      }
      gen
    })
    val COMPAREs_1 = Array.tabulate(4,2)((m,n) => {
      def gen():MULExpCompareBasic={
        val compare = new MULExpCompareBasic()
        compare.ctl.i.isMode0 := (ctl.i.mode.isBF16|ctl.i.mode.isFP16)
        compare.io.i.Mode0(0)(0) := COMPAREs_0(m)(2*n  ).io.o.Mode0(0)
        compare.io.i.Mode0(0)(1) := COMPAREs_0(m)(2*n  ).io.o.Mode0(1)
        compare.io.i.Mode0(1)(0) := COMPAREs_0(m)(2*n+1).io.o.Mode0(0)
        compare.io.i.Mode0(1)(1) := COMPAREs_0(m)(2*n+1).io.o.Mode0(1)
        Array.tabulate(2)((p) => {
          compare.io.i.Mode1(0)(p) := (((ctl.i.mode.isFP32|ctl.i.mode.isTF32) ? 
                                                                        //  FP32 or TF32
                                                                        (if(m<=1){
                                                                          COMPAREs_0(m)(2*n+p).io.o.Mode1(0)
                                                                        }else{
                                                                          U"0".resize(16)
                                                                        })|
                                                        ((ctl.i.mode.isFP64) ?
                                                                        //  FP64
                                                                        (if(m==0){
                                                                          (if(n==0){
                                                                            COMPAREs_0(0)(p).io.o.Mode1(0)
                                                                        }else{
                                                                          U"0".resize(16)
                                                                        })
                                                                        }else{
                                                                          U"0".resize(16)
                                                                        })
                                                                        //  Defalut
                                                                        | U"0".resize(16)
          )))
        })
        return compare
      }
      gen
    })
    val COMPAREs_2 = Array.tabulate(4,1)((m,n) => {
      def gen():MULExpCompareBasic={
        val compare = new MULExpCompareBasic()
        compare.ctl.i.isMode0 := (ctl.i.mode.isBF16|ctl.i.mode.isFP16)
        compare.io.i.Mode0(0)(0) := COMPAREs_1(m)(2*n  ).io.o.Mode0(0)
        compare.io.i.Mode0(0)(1) := COMPAREs_1(m)(2*n  ).io.o.Mode0(1)
        compare.io.i.Mode0(1)(0) := COMPAREs_1(m)(2*n+1).io.o.Mode0(0)
        compare.io.i.Mode0(1)(1) := COMPAREs_1(m)(2*n+1).io.o.Mode0(1)
        Array.tabulate(2)((p) => {
          compare.io.i.Mode1(0)(p) := (((ctl.i.mode.isFP32|ctl.i.mode.isTF32) ? 
                                                                        //  FP32 or TF32
                                                                        (if(m<=1){
                                                                          COMPAREs_1(m)(2*n+p).io.o.Mode1(0)
                                                                        }else{
                                                                          U"0".resize(16)
                                                                        })
                                                                        | U"0".resize(16)
          ))
        })
        return compare
      }
      gen
    })
    val COMPAREs_3 = Array.tabulate(4)((m) => {

      ((COMPAREs_2(m)(0).io.o.Mode0(0) > COMPAREs_2(m)(0).io.o.Mode0(1)) ? COMPAREs_2(m)(0).io.o.Mode0(0)|COMPAREs_2(m)(0).io.o.Mode0(1))
    })
    val max = new Bundle{
      val mul = new Bundle{
        val BF16 = Vec(UInt( 7+1 bits), 4)
        // val FP16 = Vec(UInt( 5+1 bits), 4)
        val FP32 = Vec(UInt( 8+1 bits), 2)
        val TF32 = Vec(UInt( 8+1 bits), 2)
        val FP64 = Vec(UInt(11+1 bits), 1)
      }
    }
    Array.tabulate(4)((m) => {
      max.mul.BF16(m) := COMPAREs_3(m)
    })
    max.mul.TF32(0) := COMPAREs_2(0)(0).io.o.Mode1(0).resized
    max.mul.TF32(1) := COMPAREs_2(1)(0).io.o.Mode1(0).resized
    max.mul.FP32(0) := COMPAREs_2(0)(0).io.o.Mode1(0).resized
    max.mul.FP32(1) := COMPAREs_2(1)(0).io.o.Mode1(0).resized
    max.mul.FP64(0) := COMPAREs_1(0)(0).io.o.Mode1(0).resized
    val COMPAREs_4_0 = new MULExpCompareBasic()
    COMPAREs_4_0.ctl.i.isMode0 := (ctl.i.mode.isBF16|ctl.i.mode.isFP16)
    COMPAREs_4_0.io.i.Mode0(0)(0) := ctl.i.mode.isMAC? max.mul.BF16(0) | (ctl.i.mode.isADD? io.i.add.BF16(0)(0)| U"0".resize(8))
    // COMPAREs_4_0.io.i.Mode0(0)(1) := ctl.i.mode.isMAC? io.i.mac.BF16(0)(0) | (ctl.i.mode.isADD? io.i.add.BF16(0)(1)| U"0".resize(8))
    COMPAREs_4_0.io.i.Mode0(0)(1) := (ctl.i.mode.isMAC|ctl.i.mode.isADD)? io.i.mac.BF16(0)(0) | U"0".resize(8)
    io.o.max.BF16(0) := ctl.i.mode.isMUL?max.mul.BF16(0)|COMPAREs_4_0.io.o.Mode0(0)
    io.o.max.FP16(0) :=(ctl.i.mode.isMUL?max.mul.BF16(0)|COMPAREs_4_0.io.o.Mode0(0)).resized
    COMPAREs_4_0.io.i.Mode0(1)(0) := ctl.i.mode.isMAC? max.mul.BF16(1) | (ctl.i.mode.isADD? io.i.add.BF16(1)(0)| U"0".resize(8))
    // COMPAREs_4_0.io.i.Mode0(1)(1) := ctl.i.mode.isMAC? io.i.mac.BF16(1)(0) | (ctl.i.mode.isADD? io.i.add.BF16(1)(1)| U"0".resize(8))
    COMPAREs_4_0.io.i.Mode0(1)(1) := (ctl.i.mode.isMAC|ctl.i.mode.isADD)? io.i.mac.BF16(1)(0) | U"0".resize(8)
    io.o.max.BF16(1) := ctl.i.mode.isMUL?max.mul.BF16(1)|COMPAREs_4_0.io.o.Mode0(1)
    io.o.max.FP16(1) :=(ctl.i.mode.isMUL?max.mul.BF16(1)|COMPAREs_4_0.io.o.Mode0(1)).resized
    COMPAREs_4_0.io.i.Mode1(0)(0) := ctl.i.mode.isMAC? 
                                        ((ctl.i.mode.isFP32|ctl.i.mode.isTF32) ? max.mul.FP32(0)| ((ctl.i.mode.isFP64)?max.mul.FP64(0)| U"0".resize(16))) |
                                    (ctl.i.mode.isADD? 
                                        ((ctl.i.mode.isFP32|ctl.i.mode.isTF32) ? io.i.add.FP32(0)(0)| ((ctl.i.mode.isFP64)?io.i.add.FP64(0)(0)| U"0".resize(16)))
                                        | U"0".resize(8))
    COMPAREs_4_0.io.i.Mode1(0)(1) := (ctl.i.mode.isMAC|ctl.i.mode.isADD)? 
                                        ((ctl.i.mode.isFP32|ctl.i.mode.isTF32) ? io.i.mac.FP32(0)(0)| ((ctl.i.mode.isFP64)?io.i.mac.FP64(0)(0)| U"0".resize(16)))| 
                                        U"0".resize(8)
    io.o.max.TF32(0) := (ctl.i.mode.isMUL?max.mul.TF32(0)|COMPAREs_4_0.io.o.Mode1(0)).resized
    io.o.max.FP32(0) := (ctl.i.mode.isMUL?max.mul.FP32(0)|COMPAREs_4_0.io.o.Mode1(0)).resized
    io.o.max.FP64(0) := (ctl.i.mode.isMUL?max.mul.FP64(0)|COMPAREs_4_0.io.o.Mode1(0)).resized
    val COMPAREs_4_1 = new MULExpCompareBasic()
    COMPAREs_4_1.ctl.i.isMode0 := (ctl.i.mode.isBF16|ctl.i.mode.isFP16)
    COMPAREs_4_1.io.i.Mode0(0)(0) := ctl.i.mode.isMAC? max.mul.BF16(2) | (ctl.i.mode.isADD? io.i.add.BF16(2)(0)| U"0".resize(8))
    // COMPAREs_4_1.io.i.Mode0(0)(1) := ctl.i.mode.isMAC? io.i.mac.BF16(2)(0) | (ctl.i.mode.isADD? io.i.add.BF16(2)(1)| U"0".resize(8))
    COMPAREs_4_1.io.i.Mode0(0)(1) := (ctl.i.mode.isMAC|ctl.i.mode.isADD)? io.i.mac.BF16(2)(0) | U"0".resize(8)
    io.o.max.BF16(2) := ctl.i.mode.isMUL?max.mul.BF16(2)|COMPAREs_4_1.io.o.Mode0(0)
    io.o.max.FP16(2) :=(ctl.i.mode.isMUL?max.mul.BF16(2)|COMPAREs_4_1.io.o.Mode0(0)).resized
    COMPAREs_4_1.io.i.Mode0(1)(0) := ctl.i.mode.isMAC? max.mul.BF16(3) | (ctl.i.mode.isADD? io.i.add.BF16(3)(0)| U"0".resize(8))
    // COMPAREs_4_1.io.i.Mode0(1)(1) := ctl.i.mode.isMAC? io.i.mac.BF16(3)(0) | (ctl.i.mode.isADD? io.i.add.BF16(3)(1)| U"0".resize(8))
    COMPAREs_4_1.io.i.Mode0(1)(1) := (ctl.i.mode.isMAC|ctl.i.mode.isADD)? io.i.mac.BF16(3)(0) | U"0".resize(8)
    io.o.max.BF16(3) := ctl.i.mode.isMUL?max.mul.BF16(3)|COMPAREs_4_1.io.o.Mode0(1)
    io.o.max.FP16(3) :=(ctl.i.mode.isMUL?max.mul.BF16(3)|COMPAREs_4_1.io.o.Mode0(1)).resized
    COMPAREs_4_1.io.i.Mode1(0)(0) := ctl.i.mode.isMAC? 
                                        ((ctl.i.mode.isFP32|ctl.i.mode.isTF32) ? max.mul.FP32(1)| U"0".resize(16)) |
                                    (ctl.i.mode.isADD? 
                                        ((ctl.i.mode.isFP32|ctl.i.mode.isTF32) ? io.i.add.FP32(1)(0)| U"0".resize(16))
                                        | U"0".resize(8))
    COMPAREs_4_1.io.i.Mode1(0)(1) := (ctl.i.mode.isMAC|ctl.i.mode.isADD)? 
                                        ((ctl.i.mode.isFP32|ctl.i.mode.isTF32) ? io.i.mac.FP32(1)(0)| ((ctl.i.mode.isFP64)?io.i.mac.FP32(0)(0)| U"0".resize(16)))| 
                                        U"0".resize(8)
    io.o.max.TF32(1) := (ctl.i.mode.isMUL?max.mul.TF32(1)|COMPAREs_4_1.io.o.Mode1(0)).resized
    io.o.max.FP32(1) := (ctl.i.mode.isMUL?max.mul.FP32(1)|COMPAREs_4_1.io.o.Mode1(0)).resized
  }
  val diff = new Area{
    val MULs = Array.tabulate(4,8)((m,n) => {
      def gen():MULExpCompareDiff={
        val diff = new MULExpCompareDiff()
        diff.ctl.i.isINT8 := (ctl.i.mode.isBF16|ctl.i.mode.isFP16)
        diff.io.i.INT8(0) := io.i.mul.BF16(m)(2*n)
        diff.io.i.INT8(1) := io.i.mul.BF16(m)(2*n+1)
        diff.io.i.max.INT8 := io.o.max.BF16(m)
        io.o.diff.mul.BF16(m)(2*n  ) := diff.io.o.INT8(0)
        io.o.diff.mul.BF16(m)(2*n+1) := diff.io.o.INT8(1)
        io.o.diff.mul.FP16(m)(2*n  ) := diff.io.o.INT8(0).resized
        io.o.diff.mul.FP16(m)(2*n+1) := diff.io.o.INT8(1).resized
        diff.io.i.INT16(0) := (((ctl.i.mode.isFP32|ctl.i.mode.isTF32) ? 
                                                                 //  FP32 or TF32
                                                                 (if(m<=1){
                                                                   io.i.mul.FP32(m)(n).resize(16)
                                                                 }else{
                                                                   U"0".resize(16)
                                                                 })|
                                                 ((ctl.i.mode.isFP64) ?
                                                                 //  FP64
                                                                 (if(m==0){
                                                                   (if(n<=3){
                                                                     io.i.mul.FP64(m)(n).resize(16)
                                                                 }else{
                                                                   U"0".resize(16)
                                                                 })
                                                                 }else{
                                                                   U"0".resize(16)
                                                                 })
                                                                 //  Defalut
                                                                 | U"0".resize(16)
          )))
        diff.io.i.max.INT16 := (((ctl.i.mode.isFP32|ctl.i.mode.isTF32) ? 
                                                                 //  FP32 or TF32
                                                                 (if(m<=1){
                                                                   io.o.max.FP32(m).resize(16)
                                                                 }else{
                                                                   U"0".resize(16)
                                                                 })|
                                                 ((ctl.i.mode.isFP64) ?
                                                                 //  FP64
                                                                 (if(m==0){
                                                                   (if(n<=3){
                                                                     io.o.max.FP64(m).resize(16)
                                                                 }else{
                                                                   U"0".resize(16)
                                                                 })
                                                                 }else{
                                                                   U"0".resize(16)
                                                                 })
                                                                 //  Defalut
                                                                 | U"0".resize(16)
          )))
        if(m<=1){
          io.o.diff.mul.FP32(m)(n) := diff.io.o.INT16(0).resized
          io.o.diff.mul.TF32(m)(n) := diff.io.o.INT16(0).resized
        }
        if(m==0){
          if(n<=3){
            io.o.diff.mul.FP64(m)(n) := diff.io.o.INT16(0).resized
          }
        }
        return diff
      }
      gen
    })
    val MACADD = Array.tabulate(4,1)((m,n) => {
      def gen():MULExpCompareDiff={
        val diff = new MULExpCompareDiff()
        diff.ctl.i.isINT8 := (ctl.i.mode.isBF16|ctl.i.mode.isFP16)
        diff.io.i.INT8(0) := io.i.mac.BF16(m)(0).resized
        diff.io.i.INT8(1) := io.i.add.BF16(m)(0).resized
        diff.io.i.max.INT8 := io.o.max.BF16(m)
        io.o.diff.mac.BF16(m)(0) := diff.io.o.INT8(0)
        io.o.diff.add.BF16(m)(0) := diff.io.o.INT8(1)
        io.o.diff.mac.FP16(m)(0) := diff.io.o.INT8(0).resized
        io.o.diff.add.FP16(m)(0) := diff.io.o.INT8(1).resized
        diff.io.i.INT16(0) := (((ctl.i.mode.isFP32|ctl.i.mode.isTF32) ? 
                                                                 //  FP32 or TF32
                                                                 (if(m<=1){
                                                                   io.i.mac.FP32(m)(n).resize(16)
                                                                 }else{
                                                                   io.i.add.FP32(m%2)(n).resize(16)
                                                                 })|
                                                 ((ctl.i.mode.isFP64) ?
                                                                 //  FP64
                                                                 (if(m<=1){
                                                                   (if(m==0){
                                                                      io.i.mac.FP64(0)(0).resize(16)
                                                                    }else{
                                                                      io.i.add.FP64(0)(0).resize(16)
                                                                    })
                                                                 }else{
                                                                   U"0".resize(16)
                                                                 })
                                                                 //  Defalut
                                                                 | U"0".resize(16)
        )))
        diff.io.i.max.INT16 := (((ctl.i.mode.isFP32|ctl.i.mode.isTF32) ? 
                                                                 //  FP32 or TF32
                                                                  io.o.max.FP32(m%2).resize(16)|
                                                 ((ctl.i.mode.isFP64) ?
                                                                 //  FP64
                                                                 (if(m<=1){
                                                                     io.o.max.FP64(0).resize(16)
                                                                 }else{
                                                                   U"0".resize(16)
                                                                 })
                                                                 //  Defalut
                                                                 | U"0".resize(16)
        )))
        
        if(m<=1){
          io.o.diff.mac.FP32(m)(n) := diff.io.o.INT16(0).resized
          io.o.diff.mac.TF32(m)(n) := diff.io.o.INT16(0).resized
        }else{
          io.o.diff.add.FP32(m%2)(n) := diff.io.o.INT16(0).resized
          io.o.diff.add.TF32(m%2)(n) := diff.io.o.INT16(0).resized
        }
        if(m==0){
          io.o.diff.mac.FP64(0)(0) := diff.io.o.INT16(0).resized
        }else if(m==1){
          io.o.diff.add.FP64(0)(0) := diff.io.o.INT16(0).resized
        }
        return diff
      }
      gen
    })
  }
}

object MULExpCompare_Verilog {
  def main(args: Array[String]): Unit = {
    val path = "simWorkspace/MULExpCompare/rtl"
    java.nio.file.Files.createDirectories(java.nio.file.Paths.get(path))
    val report = SpinalConfig(
      mode=Verilog,
      targetDirectory=path
    ).generate(new MULExpCompare())
    report.printPruned
    // report.mergeRTLSource(path+"/mergeRTL") // Merge all rtl sources into mergeRTL.vhd and mergeRTL.v files
  }
}

/* ----------------------------                                    ----------------------------- *\
** ----------------------------   __     __        _  __           ----------------------------- **
** ----------------------------   \ \   / /__ _ __(_)/ _|_   _     ----------------------------- **
** ----------------------------    \ \ / / _ \ '__| | |_| | | |    ----------------------------- **
** ----------------------------     \ V /  __/ |  | |  _| |_| |    ----------------------------- **
** ----------------------------      \_/ \___|_|  |_|_|  \__, |    ----------------------------- **
\* ----------------------------                          |___/     ----------------------------- */

class MULExpCompare_Verif() extends Component{
  def max(in0:UInt,in1:UInt):UInt={
    val width = if(in0.getWidth>8)16 else 8
    return (in0.resize(width)>in1.resize(width))?in0.resize(width)|in1.resize(width)
  }
  
  def max(in:Array[UInt]):UInt={
    val len = in.length
    val width = if(in(0).getWidth>8)16 else 8
    val maxArray = Array.tabulate(len-1)((n) => {
      UInt( in(n).getWidth.max(width) bits)
    })
    maxArray(0) := max(in(0),in(1))
    Array.tabulate(len-2)((n) => {
      maxArray(n+1) := max(maxArray(n),in(n+2))
    })
    maxArray(len-2)
  }
  def max(in:Vec[UInt]):UInt={
    val _in = Array.tabulate(in.length)((n) => { in(n) })
    max(_in)
  }

  val ctl = new Bundle{
    val i = new Bundle{
      val mode = in (Mode())
    }
  }
  

  val io = new Bundle{
    val i = new Bundle{
      val mul = new Bundle{
        val BF16 = in Vec(Vec(UInt( 7+1 bits), 16), 4)
        val FP16 = in Vec(Vec(UInt( 5+1 bits), 16), 4)
        val FP32 = in Vec(Vec(UInt( 8+1 bits),  8), 2)
        val TF32 = in Vec(Vec(UInt( 8+1 bits),  8), 2)
        val FP64 = in Vec(Vec(UInt(11+1 bits),  4), 1)
      }
      val mac = new Bundle{
        val BF16 = in Vec(Vec(UInt( 7 bits), 1), 4)
        val FP16 = in Vec(Vec(UInt( 5 bits), 1), 4)
        val FP32 = in Vec(Vec(UInt( 8 bits), 1), 2)
        val TF32 = in Vec(Vec(UInt( 8 bits), 1), 2)
        val FP64 = in Vec(Vec(UInt(11 bits), 1), 1)
      }
      val add = new Bundle{
        val BF16 = in Vec(Vec(UInt( 7 bits), 1), 4)
        val FP16 = in Vec(Vec(UInt( 5 bits), 1), 4)
        val FP32 = in Vec(Vec(UInt( 8 bits), 1), 2)
        val TF32 = in Vec(Vec(UInt( 8 bits), 1), 2)
        val FP64 = in Vec(Vec(UInt(11 bits), 1), 1)
      }
    }
    val o = new Bundle{
      val max = new Bundle{
        val BF16 = out Vec(UInt( 7+1 bits), 4)
        val FP16 = out Vec(UInt( 5+1 bits), 4)
        val FP32 = out Vec(UInt( 8+1 bits), 2)
        val TF32 = out Vec(UInt( 8+1 bits), 2)
        val FP64 = out Vec(UInt(11+1 bits), 1)
      }
      val diff = new Bundle{
        val mul = new Bundle{
          val BF16 = out Vec(Vec(UInt( 7+1 bits), 16), 4)
          val FP16 = out Vec(Vec(UInt( 5+1 bits), 16), 4)
          val FP32 = out Vec(Vec(UInt( 8+1 bits),  8), 2)
          val TF32 = out Vec(Vec(UInt( 8+1 bits),  8), 2)
          val FP64 = out Vec(Vec(UInt(11+1 bits),  4), 1)
        }
        val mac = new Bundle{
          val BF16 = out Vec(Vec(UInt( 7+1 bits), 1), 4)
          val FP16 = out Vec(Vec(UInt( 5+1 bits), 1), 4)
          val FP32 = out Vec(Vec(UInt( 8+1 bits), 1), 2)
          val TF32 = out Vec(Vec(UInt( 8+1 bits), 1), 2)
          val FP64 = out Vec(Vec(UInt(11+1 bits), 1), 1)
        }
        val add = new Bundle{
          val BF16 = out Vec(Vec(UInt( 7+1 bits), 1), 4)
          val FP16 = out Vec(Vec(UInt( 5+1 bits), 1), 4)
          val FP32 = out Vec(Vec(UInt( 8+1 bits), 1), 2)
          val TF32 = out Vec(Vec(UInt( 8+1 bits), 1), 2)
          val FP64 = out Vec(Vec(UInt(11+1 bits), 1), 1)
        }
      }
    }
  }
  val dut = new MULExpCompare()
  dut.io.i.assignAllByName(io.i)
  dut.ctl.i.assignAllByName(ctl.i)
  io.o.assignAllByName(dut.io.o)
  val verify = new Bundle{
    val o = new Bundle{
      val max = new Bundle{
        val mul = new Bundle{
          val BF16 = out Vec(UInt( 7+1 bits), 4)
          val FP16 = out Vec(UInt( 5+1 bits), 4)
          val FP32 = out Vec(UInt( 8+1 bits), 2)
          val TF32 = out Vec(UInt( 8+1 bits), 2)
          val FP64 = out Vec(UInt(11+1 bits), 1)
        }
        val mac = new Bundle{
          val BF16 = out Vec(UInt( 7+1 bits), 4)
          val FP16 = out Vec(UInt( 5+1 bits), 4)
          val FP32 = out Vec(UInt( 8+1 bits), 2)
          val TF32 = out Vec(UInt( 8+1 bits), 2)
          val FP64 = out Vec(UInt(11+1 bits), 1)
        }
        val add = new Bundle{
          val BF16 = out Vec(UInt( 7+1 bits), 4)
          val FP16 = out Vec(UInt( 5+1 bits), 4)
          val FP32 = out Vec(UInt( 8+1 bits), 2)
          val TF32 = out Vec(UInt( 8+1 bits), 2)
          val FP64 = out Vec(UInt(11+1 bits), 1)
        }
      }
      val diff = new Bundle{
        val mul = new Bundle{
          val BF16 = out Vec(Vec(UInt( 7+1 bits), 16), 4)
          val FP16 = out Vec(Vec(UInt( 5+1 bits), 16), 4)
          val FP32 = out Vec(Vec(UInt( 8+1 bits),  8), 2)
          val TF32 = out Vec(Vec(UInt( 8+1 bits),  8), 2)
          val FP64 = out Vec(Vec(UInt(11+1 bits),  4), 1)
        }
        val mac = new Bundle{
          val BF16 = out Vec(Vec(UInt( 7+1 bits), 1), 4)
          val FP16 = out Vec(Vec(UInt( 5+1 bits), 1), 4)
          val FP32 = out Vec(Vec(UInt( 8+1 bits), 1), 2)
          val TF32 = out Vec(Vec(UInt( 8+1 bits), 1), 2)
          val FP64 = out Vec(Vec(UInt(11+1 bits), 1), 1)
        }
        val add = new Bundle{
          val BF16 = out Vec(Vec(UInt( 7+1 bits), 1), 4)
          val FP16 = out Vec(Vec(UInt( 5+1 bits), 1), 4)
          val FP32 = out Vec(Vec(UInt( 8+1 bits), 1), 2)
          val TF32 = out Vec(Vec(UInt( 8+1 bits), 1), 2)
          val FP64 = out Vec(Vec(UInt(11+1 bits), 1), 1)
        }
      }
    }
    val equal = new Bundle{
      val max = new Bundle{
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
      val diff = new Bundle{
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
    }
    val EQUAL = out Bool()
    val sim = Reg(Bool())
  }
  val MAX = new Area{
    Array.tabulate(4)((n) => {
      verify.o.max.mul.BF16(n) := max(io.i.mul.BF16(n)).resized
      verify.o.max.mul.FP16(n) := max(io.i.mul.FP16(n)).resized
      verify.o.max.mac.BF16(n) := max(max(io.i.mul.BF16(n)),io.i.mac.BF16(n)(0)).resized
      verify.o.max.mac.FP16(n) := max(max(io.i.mul.FP16(n)),io.i.mac.FP16(n)(0)).resized
      verify.o.max.add.BF16(n) := max(io.i.add.BF16(n)(0),io.i.mac.BF16(n)(0)).resized
      verify.o.max.add.FP16(n) := max(io.i.add.FP16(n)(0),io.i.mac.FP16(n)(0)).resized
    })
    verify.equal.max.mul.BF16 := verify.o.max.mul.BF16===io.o.max.BF16
    verify.equal.max.mul.FP16 := verify.o.max.mul.FP16===io.o.max.FP16
    verify.equal.max.mac.BF16 := verify.o.max.mac.BF16===io.o.max.BF16
    verify.equal.max.mac.FP16 := verify.o.max.mac.FP16===io.o.max.FP16
    verify.equal.max.add.BF16 := verify.o.max.add.BF16===io.o.max.BF16
    verify.equal.max.add.FP16 := verify.o.max.add.FP16===io.o.max.FP16
    Array.tabulate(2)((n) => {
      verify.o.max.mul.FP32(n) := max(io.i.mul.FP32(n)).resized
      verify.o.max.mul.TF32(n) := max(io.i.mul.TF32(n)).resized
      verify.o.max.mac.FP32(n) := max(max(io.i.mul.FP32(n)),io.i.mac.FP32(n)(0)).resized
      verify.o.max.mac.TF32(n) := max(max(io.i.mul.TF32(n)),io.i.mac.TF32(n)(0)).resized
      verify.o.max.add.FP32(n) := max(io.i.add.FP32(n)(0),io.i.mac.FP32(n)(0)).resized
      verify.o.max.add.TF32(n) := max(io.i.add.TF32(n)(0),io.i.mac.TF32(n)(0)).resized
    })
    verify.equal.max.mul.FP32 := verify.o.max.mul.FP32===io.o.max.FP32
    verify.equal.max.mul.TF32 := verify.o.max.mul.TF32===io.o.max.TF32
    verify.equal.max.mac.FP32 := verify.o.max.mac.FP32===io.o.max.FP32
    verify.equal.max.mac.TF32 := verify.o.max.mac.TF32===io.o.max.TF32
    verify.equal.max.add.FP32 := verify.o.max.add.FP32===io.o.max.FP32
    verify.equal.max.add.TF32 := verify.o.max.add.TF32===io.o.max.TF32
    Array.tabulate(1)((n) => {
      verify.o.max.mul.FP64(n) := max(io.i.mul.FP64(n)).resized
      verify.o.max.mac.FP64(n) := max(max(io.i.mul.FP64(n)),io.i.mac.FP64(n)(0)).resized
      verify.o.max.add.FP64(n) := max(io.i.add.FP64(n)(0),io.i.mac.FP64(n)(0)).resized
    })
    verify.equal.max.mul.FP64 := verify.o.max.mul.FP64===io.o.max.FP64
    verify.equal.max.mac.FP64 := verify.o.max.mac.FP64===io.o.max.FP64
    verify.equal.max.add.FP64 := verify.o.max.add.FP64===io.o.max.FP64
  }
  val DIFF = new Area{
    Array.tabulate(4,16)((m,n) => {
      verify.o.diff.mul.BF16(m)(n) := io.o.max.BF16(m) - io.i.mul.BF16(m)(n)
      verify.o.diff.mul.FP16(m)(n) := io.o.max.FP16(m) - io.i.mul.FP16(m)(n)
    })
    Array.tabulate(4,1)((m,n) => {
      verify.o.diff.mac.BF16(m)(n) := io.o.max.BF16(m) - io.i.mac.BF16(m)(n)
      verify.o.diff.mac.FP16(m)(n) := io.o.max.FP16(m) - io.i.mac.FP16(m)(n)
      verify.o.diff.add.BF16(m)(n) := io.o.max.BF16(m) - io.i.add.BF16(m)(n)
      verify.o.diff.add.FP16(m)(n) := io.o.max.FP16(m) - io.i.add.FP16(m)(n)
    })
    Array.tabulate(2,8)((m,n) => {
      verify.o.diff.mul.FP32(m)(n) := io.o.max.FP32(m) - io.i.mul.FP32(m)(n)
      verify.o.diff.mul.TF32(m)(n) := io.o.max.TF32(m) - io.i.mul.TF32(m)(n)
    })
    Array.tabulate(2,1)((m,n) => {
      verify.o.diff.mac.FP32(m)(n) := io.o.max.FP32(m) - io.i.mac.FP32(m)(n)
      verify.o.diff.mac.TF32(m)(n) := io.o.max.TF32(m) - io.i.mac.TF32(m)(n)
      verify.o.diff.add.FP32(m)(n) := io.o.max.FP32(m) - io.i.add.FP32(m)(n)
      verify.o.diff.add.TF32(m)(n) := io.o.max.TF32(m) - io.i.add.TF32(m)(n)
    })
    Array.tabulate(1,4)((m,n) => {
      verify.o.diff.mul.FP64(m)(n) := io.o.max.FP64(m) - io.i.mul.FP64(m)(n)
    })
    Array.tabulate(1,1)((m,n) => {
      verify.o.diff.mac.FP64(m)(n) := io.o.max.FP64(m) - io.i.mac.FP64(m)(n)
      verify.o.diff.add.FP64(m)(n) := io.o.max.FP64(m) - io.i.add.FP64(m)(n)
    })
    verify.equal.diff.mul.BF16 := verify.o.diff.mul.BF16===io.o.diff.mul.BF16
    verify.equal.diff.mul.FP16 := verify.o.diff.mul.FP16===io.o.diff.mul.FP16
    verify.equal.diff.mac.BF16 := verify.o.diff.mac.BF16===io.o.diff.mac.BF16
    verify.equal.diff.mac.FP16 := verify.o.diff.mac.FP16===io.o.diff.mac.FP16
    verify.equal.diff.add.BF16 := verify.o.diff.add.BF16===io.o.diff.add.BF16
    verify.equal.diff.add.FP16 := verify.o.diff.add.FP16===io.o.diff.add.FP16
    verify.equal.diff.mul.FP32 := verify.o.diff.mul.FP32===io.o.diff.mul.FP32
    verify.equal.diff.mul.TF32 := verify.o.diff.mul.TF32===io.o.diff.mul.TF32
    verify.equal.diff.mac.FP32 := verify.o.diff.mac.FP32===io.o.diff.mac.FP32
    verify.equal.diff.mac.TF32 := verify.o.diff.mac.TF32===io.o.diff.mac.TF32
    verify.equal.diff.add.FP32 := verify.o.diff.add.FP32===io.o.diff.add.FP32
    verify.equal.diff.add.TF32 := verify.o.diff.add.TF32===io.o.diff.add.TF32
    verify.equal.diff.mul.FP64 := verify.o.diff.mul.FP64===io.o.diff.mul.FP64
    verify.equal.diff.mac.FP64 := verify.o.diff.mac.FP64===io.o.diff.mac.FP64
    verify.equal.diff.add.FP64 := verify.o.diff.add.FP64===io.o.diff.add.FP64
  }
  when(ctl.i.mode.isBF16) {
    when(ctl.i.mode.isMUL)       {verify.EQUAL := verify.equal.max.mul.BF16===verify.equal.diff.mul.BF16
    }.elsewhen(ctl.i.mode.isMAC) {verify.EQUAL := verify.equal.max.mac.BF16===verify.equal.diff.mac.BF16
    }.elsewhen(ctl.i.mode.isADD) {verify.EQUAL := verify.equal.max.add.BF16===verify.equal.diff.add.BF16
    }.otherwise {verify.EQUAL := False}
  }.elsewhen(ctl.i.mode.isFP16) {
    when(ctl.i.mode.isMUL)       {verify.EQUAL := verify.equal.max.mul.FP16===verify.equal.diff.mul.FP16
    }.elsewhen(ctl.i.mode.isMAC) {verify.EQUAL := verify.equal.max.mac.FP16===verify.equal.diff.mac.FP16
    }.elsewhen(ctl.i.mode.isADD) {verify.EQUAL := verify.equal.max.add.FP16===verify.equal.diff.add.FP16
    }.otherwise {verify.EQUAL := False}
  }.elsewhen(ctl.i.mode.isFP32) {
    when(ctl.i.mode.isMUL)       {verify.EQUAL := verify.equal.max.mul.FP32===verify.equal.diff.mul.FP32
    }.elsewhen(ctl.i.mode.isMAC) {verify.EQUAL := verify.equal.max.mac.FP32===verify.equal.diff.mac.FP32
    }.elsewhen(ctl.i.mode.isADD) {verify.EQUAL := verify.equal.max.add.FP32===verify.equal.diff.add.FP32
    }.otherwise {verify.EQUAL := False}
  }.elsewhen(ctl.i.mode.isTF32) {
    when(ctl.i.mode.isMUL)       {verify.EQUAL := verify.equal.max.mul.TF32===verify.equal.diff.mul.TF32
    }.elsewhen(ctl.i.mode.isMAC) {verify.EQUAL := verify.equal.max.mac.TF32===verify.equal.diff.mac.TF32
    }.elsewhen(ctl.i.mode.isADD) {verify.EQUAL := verify.equal.max.add.TF32===verify.equal.diff.add.TF32
    }.otherwise {verify.EQUAL := False}
  }.elsewhen(ctl.i.mode.isFP64) {
    when(ctl.i.mode.isMUL)       {verify.EQUAL := verify.equal.max.mul.FP64===verify.equal.diff.mul.FP64
    }.elsewhen(ctl.i.mode.isMAC) {verify.EQUAL := verify.equal.max.mac.FP64===verify.equal.diff.mac.FP64
    }.elsewhen(ctl.i.mode.isADD) {verify.EQUAL := verify.equal.max.add.FP64===verify.equal.diff.add.FP64
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


object MULExpCompare_Sim {
  def main(args: Array[String]) {

    val simConfig = SpinalConfig(
      defaultClockDomainFrequency = FixedFrequency(10 MHz),
      defaultConfigForClockDomains = ClockDomainConfig(resetKind = SYNC))
    
    val compiled = SimConfig
                    // .withWave
                    .withConfig(simConfig)
                    // .allOptimisation
                    .workspacePath("simWorkspace")
                    .compile(new MULExpCompare_Verif())

    def sim_MUL_BF16(times: Int = 10, seed: Int = scala.util.Random.nextInt()){
      def name: String = "sim_MUL_BF16"
      compiled.doSim(name,seed){dut =>
        //Fork a process to generate the reset and the clock on the dut
        dut.clockDomain.forkStimulus(period = 10)
        dut.ctl.i.mode #= ModeConfig.MUL_BF16
        dut.clockDomain.waitRisingEdge()
        for(_times <- 0 to times-1 ){
          Array.tabulate(16,4)((m,p) => {
            dut.io.i.mul.BF16(p)(m) #= BigInt(dut.io.i.mul.BF16(p)(m).getBitsWidth, scala.util.Random)
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
    def sim_MAC_BF16(times: Int = 10, seed: Int = scala.util.Random.nextInt()){
      def name: String = "sim_MAC_BF16"
      compiled.doSim(name){dut =>
        //Fork a process to generate the reset and the clock on the dut
        dut.clockDomain.forkStimulus(period = 10)
        dut.ctl.i.mode #= ModeConfig.MAC_BF16
        dut.clockDomain.waitRisingEdge()
        for(_times <- 0 to times-1 ){
          Array.tabulate(16,4)((m,p) => {
            dut.io.i.mul.BF16(p)(m) #= BigInt(dut.io.i.mul.BF16(p)(m).getBitsWidth-1, scala.util.Random)
          })
          Array.tabulate( 1,4)((m,p) => {
            dut.io.i.mac.BF16(p)(m) #= BigInt(dut.io.i.mac.BF16(p)(m).getBitsWidth, scala.util.Random)
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
    def sim_ADD_BF16(times: Int = 10, seed: Int = scala.util.Random.nextInt()){
      def name: String = "sim_ADD_BF16"
      compiled.doSim(name){dut =>
        //Fork a process to generate the reset and the clock on the dut
        dut.clockDomain.forkStimulus(period = 10)
        dut.ctl.i.mode #= ModeConfig.ADD_BF16
        dut.clockDomain.waitRisingEdge()
        for(_times <- 0 to times-1 ){
          Array.tabulate( 1,4)((m,p) => {
            dut.io.i.add.BF16(p)(m) #= BigInt(dut.io.i.add.BF16(p)(m).getBitsWidth, scala.util.Random)
          })
          Array.tabulate( 1,4)((m,p) => {
            dut.io.i.mac.BF16(p)(m) #= BigInt(dut.io.i.mac.BF16(p)(m).getBitsWidth, scala.util.Random)
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
      compiled.doSim(name){dut =>
        //Fork a process to generate the reset and the clock on the dut
        dut.clockDomain.forkStimulus(period = 10)
        dut.ctl.i.mode #= ModeConfig.MUL_FP32
        dut.clockDomain.waitRisingEdge()
        for(_times <- 0 to times-1 ){
          Array.tabulate(8,2)((m,p) => {
            dut.io.i.mul.FP32(p)(m) #= BigInt(dut.io.i.mul.FP32(p)(m).getBitsWidth, scala.util.Random)
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
      compiled.doSim(name){dut =>
        //Fork a process to generate the reset and the clock on the dut
        dut.clockDomain.forkStimulus(period = 10)
        dut.ctl.i.mode #= ModeConfig.MAC_FP32
        dut.clockDomain.waitRisingEdge()
        for(_times <- 0 to times-1 ){
          Array.tabulate(8,2)((m,p) => {
            dut.io.i.mul.FP32(p)(m) #= BigInt(dut.io.i.mul.FP32(p)(m).getBitsWidth-1, scala.util.Random)
          })
          Array.tabulate( 1,2)((m,p) => {
            dut.io.i.mac.FP32(p)(m) #= BigInt(dut.io.i.mac.FP32(p)(m).getBitsWidth, scala.util.Random)
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
      compiled.doSim(name){dut =>
        //Fork a process to generate the reset and the clock on the dut
        dut.clockDomain.forkStimulus(period = 10)
        dut.ctl.i.mode #= ModeConfig.ADD_FP32
        dut.clockDomain.waitRisingEdge()
        for(_times <- 0 to times-1 ){
          Array.tabulate( 1,2)((m,p) => {
            dut.io.i.add.FP32(p)(m) #= BigInt(dut.io.i.add.FP32(p)(m).getBitsWidth, scala.util.Random)
          })
          Array.tabulate( 1,2)((m,p) => {
            dut.io.i.mac.FP32(p)(m) #= BigInt(dut.io.i.mac.FP32(p)(m).getBitsWidth, scala.util.Random)
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
      compiled.doSim(name){dut =>
        //Fork a process to generate the reset and the clock on the dut
        dut.clockDomain.forkStimulus(period = 10)
        dut.ctl.i.mode #= ModeConfig.MUL_FP64
        dut.clockDomain.waitRisingEdge()
        for(_times <- 0 to times-1 ){
          Array.tabulate(4,1)((m,p) => {
            dut.io.i.mul.FP64(p)(m) #= BigInt(dut.io.i.mul.FP64(p)(m).getBitsWidth, scala.util.Random)
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
      compiled.doSim(name){dut =>
        //Fork a process to generate the reset and the clock on the dut
        dut.clockDomain.forkStimulus(period = 10)
        dut.ctl.i.mode #= ModeConfig.MAC_FP64
        dut.clockDomain.waitRisingEdge()
        for(_times <- 0 to times-1 ){
          Array.tabulate(4,1)((m,p) => {
            dut.io.i.mul.FP64(p)(m) #= BigInt(dut.io.i.mul.FP64(p)(m).getBitsWidth-1, scala.util.Random)
          })
          Array.tabulate(1,1)((m,p) => {
            dut.io.i.mac.FP64(p)(m) #= BigInt(dut.io.i.mac.FP64(p)(m).getBitsWidth, scala.util.Random)
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
      compiled.doSim(name){dut =>
        //Fork a process to generate the reset and the clock on the dut
        dut.clockDomain.forkStimulus(period = 10)
        dut.ctl.i.mode #= ModeConfig.ADD_FP64
        dut.clockDomain.waitRisingEdge()
        for(_times <- 0 to times-1 ){
          Array.tabulate(1,1)((m,p) => {
            dut.io.i.add.FP64(p)(m) #= BigInt(dut.io.i.add.FP64(p)(m).getBitsWidth, scala.util.Random)
          })
          Array.tabulate(1,1)((m,p) => {
            dut.io.i.mac.FP64(p)(m) #= BigInt(dut.io.i.mac.FP64(p)(m).getBitsWidth, scala.util.Random)
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
    sim_MUL_BF16(times=1000000)
    sim_MAC_BF16(times=1000000)
    sim_ADD_BF16(times=1000000)
    sim_MUL_FP32(times=1000000)
    sim_MAC_FP32(times=1000000)
    sim_ADD_FP32(times=1000000)
    sim_MUL_FP64(times=1000000)
    sim_MAC_FP64(times=1000000)
    sim_ADD_FP64(times=1000000)
  }
}