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
class MULBasic() extends Component{
  val ctl = new Bundle{
    val i = new Bundle{
      val isINT = in Bool()
    }
  }
  val io = new Bundle{
    val i = new Bundle{
      val ModeSINT = in Vec(Vec(SInt( 8 bits), 2), 2)
      val ModeUINT = in Vec(Vec(UInt(13 bits), 1), 2)
    }
    val o = new Bundle{
      // SINT_A1[8]*SINT_B1[8] + SINT_A2[8]*SINT_B2[8] = SINT_ModeSINT[17]
      val ModeSINT = out SInt(17 bits)
      // UINT_A1[13]*UINT_B1[13] = UINT_ModeUINT[26]
      val ModeUINT = out UInt(26 bits)
    }
  }
  noIoPrefix()
  val MUL_SINT8_IN = Vec(Vec(SInt( 8 bits), 2), 2)
  MUL_SINT8_IN(0)(0) := ctl.i.isINT ? io.i.ModeSINT(0)(0) | (U"0"  @@ io.i.ModeUINT(0)(0)(0 to  6)).asSInt
  MUL_SINT8_IN(1)(0) := ctl.i.isINT ? io.i.ModeSINT(1)(0) | (U"0"  @@ io.i.ModeUINT(1)(0)(0 to  6)).asSInt
  
  MUL_SINT8_IN(0)(1) := ctl.i.isINT ? io.i.ModeSINT(0)(1) | (U"0"  @@ io.i.ModeUINT(0)(0)(0 to  6)).asSInt
  MUL_SINT8_IN(1)(1) := ctl.i.isINT ? io.i.ModeSINT(1)(1) | (U"00" @@ io.i.ModeUINT(1)(0)(7 to 12)).asSInt
  val MUL_SINT8_OUT = MUL_SINT8_IN(0)(0)*MUL_SINT8_IN(1)(0) +^ MUL_SINT8_IN(0)(1)*MUL_SINT8_IN(1)(1)
  val MUL_SINT8_OUT_1 = MUL_SINT8_IN(0)(0)*MUL_SINT8_IN(1)(0) +^ ( MUL_SINT8_IN(0)(1)*MUL_SINT8_IN(1)(1)@@U"0000000")
  val MUL_UINT_OUT = io.i.ModeUINT(0)(0)(7 to 12)*io.i.ModeUINT(1)(0)
  io.o.ModeSINT := MUL_SINT8_OUT
  io.o.ModeUINT := MUL_SINT8_OUT_1.resize(20).asUInt + (MUL_UINT_OUT@@U"0000000")
}

object MULBasic_Verilog {
  def main(args: Array[String]): Unit = {
    val path = "simWorkspace/MULBasic/rtl"
    java.nio.file.Files.createDirectories(java.nio.file.Paths.get(path))
    val report = SpinalConfig(
      mode=Verilog,
      targetDirectory=path
    ).generate(new MULBasic())
    report.mergeRTLSource(path+"/mergeRTL") // Merge all rtl sources into mergeRTL.vhd and mergeRTL.v files
  }
}


class MULMulti() extends Component{

  val ctl = new Bundle{
    val i = new Bundle{
      val mode = in (Mode())
    }
  }

  val io = new Bundle{
    val i = new Bundle{
      val INT8  = in Vec(Vec(SInt( 8 bits), 32), 2)
      val BF16  = in Vec(Vec(UInt( 8 bits), 16), 2)
      val FP16  = in Vec(Vec(UInt(11 bits), 16), 2)
      val FP32  = in Vec(Vec(UInt(24 bits),  4), 2)
      val TF32  = in Vec(Vec(UInt(11 bits),  4), 2)
      val FP64  = in Vec(Vec(UInt(53 bits),  1), 2)
    }
    val o = new Bundle{
      // SINT_A1[8]*SINT_B1[8] + SINT_A2[8]*SINT_B2[8] = SINT_ModeSINT[17]
      val INT8 = out Vec(SInt( 8*2+1 bits), 16)
      val BF16 = out Vec(UInt( 8*2   bits), 16)
      val FP16 = out Vec(UInt(11*2   bits), 16)
      val FP32 = out Vec(UInt(24*2   bits),  4)
      val TF32 = out Vec(UInt(11*2   bits),  4)
      val FP64 = out Vec(UInt(53*2   bits),  1)
    }
    val StageOut = new Bundle{
      val INT8 = out Vec(SInt( 8*2+1 bits), 16)
      val BF16 = out Vec(UInt( 8*2   bits), 16)
      val FP16 = out Vec(UInt(11*2   bits), 16)
      val FP32 = out Vec(UInt(24*2   bits),  4)
      val TF32 = out Vec(UInt(11*2   bits),  4)
      val FP64 = out Vec(UInt(53*2   bits),  1)
    }
  }
  noIoPrefix()

  val MULs = Array.tabulate(4,4)((m,n) => {
    def genMUL:MULBasic={
      val MUL = new MULBasic()
      val k = 4*m+n
      MUL.io.i.ModeSINT(0)(0) := io.i.INT8(0)(2*k  )
      MUL.io.i.ModeSINT(1)(0) := io.i.INT8(1)(2*k  )
      MUL.io.i.ModeSINT(0)(1) := io.i.INT8(0)(2*k+1)
      MUL.io.i.ModeSINT(1)(1) := io.i.INT8(1)(2*k+1)
      MUL.ctl.i.isINT := ctl.i.mode.isINT8
      return MUL
    }
    genMUL
  })
  Array.tabulate(2,2,2,2,2)((m1,n1,m2,n2,p) => {
    val m = 2*m1+m2
    val n = 2*n1+n2
    val k = 4*m+n
    MULs(m)(n).io.i.ModeUINT(p)(0) := {(ctl.i.mode.isFP16|ctl.i.mode.isBF16) ? 
                                                                //  FP16 or BF16
                                                                io.i.FP16(p)(k).resized | 
                                      ((ctl.i.mode.isFP32|ctl.i.mode.isTF32) ? 
                                                                //  FP32
                                                                (if (p==0)
                                                                  (io.i.FP32(0)(2*m1+n1)(m2*13 to 23.min((m2+1)*13-1))).resized
                                                                else
                                                                  (io.i.FP32(1)(2*m1+n1)(n2*13 to 23.min((n2+1)*13-1))).resized)|
                                                      ((ctl.i.mode.isFP64) ?
                                                                //  FP64
                                                                (if (p==0)
                                                                  (io.i.FP64(0)(0)((m1*2+m2)*13 to (m1*2+m2+1)*13-1))
                                                                else
                                                                  (io.i.FP64(1)(0)((n1*2+n2)*13 to (n1*2+n2+1)*13-1))
                                                                ) | 
                                                                //  Defalut
                                                                U"0".resized
    ))}
  })
  val StageReg = Reg(Vec(UInt(11*2 bits), 16))
  Array.tabulate(2,2,2,2)((m1,n1,m2,n2) => {
    val m = 2*m1+m2
    val n = 2*n1+n2
    val k = 4*m+n
    StageReg(k) :=        ctl.i.mode.isINT8 ? 
                                //  INT8
                                io.o.INT8(k).asUInt.resize(22)|
     ((ctl.i.mode.isFP16|ctl.i.mode.isBF16) ? 
                                //  FP16 or BF16
                                io.o.FP16(k).resize(22) | 
     ((ctl.i.mode.isFP32|ctl.i.mode.isTF32) ? 
                                //  FP32
                                // val FP32 = out Vec(UInt(48   bits),  4)
                                (n match {
                                  case 0 => io.o.FP32(m)( 0 to 21)
                                  case 1 => io.o.FP32(m)(22 to 43)
                                  case 2 => io.o.FP32(m)(44 to 47).resize(22)
                                  case _ => U"0".resize(22)
                                })|
                       ((ctl.i.mode.isFP64) ?
                                //  FP64
                                // val FP64 = out Vec(UInt(106   bits),  1)
                                (k match {
                                  case 0 => io.o.FP64(0)( 0 to 21)
                                  case 1 => io.o.FP64(0)(22 to 43)
                                  case 2 => io.o.FP64(0)(44 to 65)
                                  case 3 => io.o.FP64(0)(66 to 87)
                                  case 4 => io.o.FP64(0)(88 to 105).resize(22)
                                  case _ => U"0".resize(22)
                                })|
                                //  Defalut
                                U"0".resize(22)
      )))
  })
  Array.tabulate(4,4)((m,n) => {
    val k = 4*m+n
    io.o.INT8(k) := MULs(m)(n).io.o.ModeSINT
    io.o.BF16(k) := MULs(m)(n).io.o.ModeUINT.resized
    io.o.FP16(k) := MULs(m)(n).io.o.ModeUINT.resized
  })
  Array.tabulate(4,4)((m,n) => {
    val k = 4*m+n
    io.StageOut.INT8(k) := StageReg(k).asSInt.resized
    io.StageOut.BF16(k) := StageReg(k).resized
    io.StageOut.FP16(k) := StageReg(k).resized
  })
  val ADDs = Array.tabulate(2,2)((m1,n1) => {
    (MULs(m1*2)(n1*2).io.o.ModeUINT
    +^ (MULs(m1*2+1)(n1*2).io.o.ModeUINT @@ U(0,13 bits))
    +^ (MULs(m1*2)(n1*2+1).io.o.ModeUINT @@ U(0,13 bits))
    +^ (MULs(m1*2+1)(n1*2+1).io.o.ModeUINT @@ U(0,26 bits))
    ).resize(52)
  })
  Array.tabulate(2,2)((m1,n1) => {
    io.o.FP32(2*m1+n1) := ADDs(m1)(n1).resized
    io.o.TF32(2*m1+n1) := ADDs(m1)(n1).resized
  })
  Array.tabulate(4)((m) => {
    io.StageOut.FP32(m) := (StageReg(4*m+3) @@ StageReg(4*m+2) @@ StageReg(4*m+1) @@ StageReg(4*m)).resized
    io.StageOut.TF32(m) := (StageReg(4*m+3) @@ StageReg(4*m+2) @@ StageReg(4*m+1) @@ StageReg(4*m)).resized
  })
  io.o.FP64(0) := 
     (ADDs(0)(0) 
  +^ (ADDs(0)(1) @@ U(0,26 bits))
  +^ (ADDs(1)(0) @@ U(0,26 bits))
  +^ (ADDs(1)(1) @@ U(0,52 bits))
  +^ (((io.i.FP64(0)(0).resize(52) * io.i.FP64(1)(0)(52).asUInt)+^(io.i.FP64(1)(0) * io.i.FP64(0)(0)(52).asUInt)) @@ U(0,52 bits))
  ).resized
  io.StageOut.FP64(0) := (StageReg(4) @@ StageReg(3) @@ StageReg(2) @@ StageReg(1) @@ StageReg(0)).resized
}
object MULMulti_Verilog {
  def main(args: Array[String]): Unit = {
    val path = "simWorkspace/MULMulti/rtl"
    java.nio.file.Files.createDirectories(java.nio.file.Paths.get(path))
    val report = SpinalConfig(
      mode=Verilog,
      targetDirectory=path
    ).generate(new MULMulti())
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

class MULMulti_Verif() extends Component{

  // def randomInput()

  val ctl = new Bundle{
    val i = new Bundle{
      val mode = in (Mode())
    }
  }

  val io = new Bundle{
    val i = new Bundle{
      val INT8  = in Vec(Vec(SInt( 8 bits), 32), 2)
      val BF16  = in Vec(Vec(UInt( 8 bits), 16), 2)
      val FP16  = in Vec(Vec(UInt(11 bits), 16), 2)
      val FP32  = in Vec(Vec(UInt(24 bits),  4), 2)
      val TF32  = in Vec(Vec(UInt(11 bits),  4), 2)
      val FP64  = in Vec(Vec(UInt(53 bits),  1), 2)
    }
    val o = new Bundle{
      // SINT_A1[8]*SINT_B1[8] + SINT_A2[8]*SINT_B2[8] = SINT_ModeSINT[17]
      val INT8 = out Vec(SInt( 8*2+1 bits), 16)
      val BF16 = out Vec(UInt( 8*2   bits), 16)
      val FP16 = out Vec(UInt(11*2   bits), 16)
      val FP32 = out Vec(UInt(24*2   bits),  4)
      val TF32 = out Vec(UInt(11*2   bits),  4)
      val FP64 = out Vec(UInt(53*2   bits),  1)
    }
    val StageOut = new Bundle{
      val INT8 = out Vec(SInt( 8*2+1 bits), 16)
      val BF16 = out Vec(UInt( 8*2   bits), 16)
      val FP16 = out Vec(UInt(11*2   bits), 16)
      val FP32 = out Vec(UInt(24*2   bits),  4)
      val TF32 = out Vec(UInt(11*2   bits),  4)
      val FP64 = out Vec(UInt(53*2   bits),  1)
    }
  }
  val dut = new MULMulti()
  dut.io.i.assignAllByName(io.i)
  dut.ctl.i.assignAllByName(ctl.i)
  io.o.assignAllByName(dut.io.o)
  io.StageOut.assignAllByName(dut.io.StageOut)
  val verify = new Bundle{
    val o = new Bundle{
      // SINT_A1[8]*SINT_B1[8] + SINT_A2[8]*SINT_B2[8] = SINT_ModeSINT[17]
      val INT8 = out Vec(SInt( 8*2+1 bits), 16)
      val BF16 = out Vec(UInt( 8*2   bits), 16)
      val FP16 = out Vec(UInt(11*2   bits), 16)
      val FP32 = out Vec(UInt(24*2   bits),  4)
      val TF32 = out Vec(UInt(11*2   bits),  4)
      val FP64 = out Vec(UInt(53*2   bits),  1)
    }
    val StageOut = Reg(new Bundle{
      val INT8 = out Vec(SInt( 8*2+1 bits), 16)
      val BF16 = out Vec(UInt( 8*2   bits), 16)
      val FP16 = out Vec(UInt(11*2   bits), 16)
      val FP32 = out Vec(UInt(24*2   bits),  4)
      val TF32 = out Vec(UInt(11*2   bits),  4)
      val FP64 = out Vec(UInt(53*2   bits),  1)
    })
    val equal = new Bundle{
      val INT8 = out Bool()
      val BF16 = out Bool()
      val FP16 = out Bool()
      val FP32 = out Bool()
      val TF32 = out Bool()
      val FP64 = out Bool()
    }
    val EQUAL = out Bool()
    val sim = Reg(Bool())
  }
  Array.tabulate(16)((n) => {
    verify.o.INT8(n) := io.i.INT8(0)(2*n)*io.i.INT8(1)(2*n)+^io.i.INT8(0)(2*n+1)*io.i.INT8(1)(2*n+1)
    verify.o.BF16(n) := io.i.BF16(0)(n)*io.i.BF16(1)(n)
    verify.o.FP16(n) := io.i.FP16(0)(n)*io.i.FP16(1)(n)
  })
  Array.tabulate(4)((n) => {
    verify.o.FP32(n) := io.i.FP32(0)(n)*io.i.FP32(1)(n)
    verify.o.TF32(n) := io.i.TF32(0)(n)*io.i.TF32(1)(n)
  })
  verify.o.FP64(0) := io.i.FP64(0)(0)*io.i.FP64(1)(0)
  verify.StageOut.assignAllByName(io.StageOut)
  verify.equal.INT8 := io.o.INT8===verify.o.INT8 && io.StageOut.INT8===verify.StageOut.INT8
  verify.equal.BF16 := io.o.BF16===verify.o.BF16 && io.StageOut.INT8===verify.StageOut.INT8
  verify.equal.FP16 := io.o.FP16===verify.o.FP16 && io.StageOut.INT8===verify.StageOut.INT8
  verify.equal.FP32 := io.o.FP32===verify.o.FP32 && io.StageOut.INT8===verify.StageOut.INT8
  verify.equal.TF32 := io.o.TF32===verify.o.TF32 && io.StageOut.INT8===verify.StageOut.INT8
  verify.equal.FP64 := io.o.FP64===verify.o.FP64 && io.StageOut.INT8===verify.StageOut.INT8
  when(ctl.i.mode.isINT8) {
    verify.EQUAL := verify.equal.INT8
  }.elsewhen(ctl.i.mode.isBF16) {
    verify.EQUAL := verify.equal.BF16
  }.elsewhen(ctl.i.mode.isFP16) {
    verify.EQUAL := verify.equal.FP16
  }.elsewhen(ctl.i.mode.isFP32) {
    verify.EQUAL := verify.equal.FP32
  }.elsewhen(ctl.i.mode.isTF32) {
    verify.EQUAL := verify.equal.TF32
  }.elsewhen(ctl.i.mode.isFP64) {
    verify.EQUAL := verify.equal.FP64
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


object MULMulti_Sim {

  def main(args: Array[String]) {

    val simConfig = SpinalConfig(
      defaultClockDomainFrequency = FixedFrequency(10 MHz),
      defaultConfigForClockDomains = ClockDomainConfig(resetKind = SYNC))
    
    val compiled = SimConfig
                    .withWave
                    .withConfig(simConfig)
                    // .allOptimisation
                    .workspacePath("simWorkspace")
                    .compile(new MULMulti_Verif())

    def simINT8(times: Int = 10, seed: Int = scala.util.Random.nextInt()){
      def name: String = "INT8"
      compiled.doSim(name){dut =>
        //Fork a process to generate the reset and the clock on the dut
        dut.clockDomain.forkStimulus(period = 10)
        dut.ctl.i.mode #= ModeConfig.MUL_INT8
        dut.clockDomain.waitRisingEdge()
        for(_times <- 0 to times-1 ){
          Array.tabulate(32,2)((m,p) => {
            dut.io.i.INT8(p)(m) #= scala.util.Random.nextInt(255)-128 //2^8-1 -2^7
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

    def simFP16(times: Int = 10, seed: Int = scala.util.Random.nextInt()){
      def name: String = "FP16"
      compiled.doSim(name){dut =>
        //Fork a process to generate the reset and the clock on the dut
        dut.clockDomain.forkStimulus(period = 10)
        dut.ctl.i.mode #= ModeConfig.MUL_FP16
        dut.clockDomain.waitRisingEdge()
        for(_times <- 0 to times-1 ){
          Array.tabulate(16,2)((m,p) => {
            dut.io.i.FP16(p)(m) #= BigInt(dut.io.i.FP16(p)(m).getBitsWidth, scala.util.Random)
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

    def simFP32(times: Int = 10, seed: Int = scala.util.Random.nextInt()){
      def name: String = "FP32"
      compiled.doSim(name){dut =>
        //Fork a process to generate the reset and the clock on the dut
        dut.clockDomain.forkStimulus(period = 10)
        dut.ctl.i.mode #= ModeConfig.MUL_FP32
        dut.clockDomain.waitRisingEdge()
        for(_times <- 0 to times-1 ){
          Array.tabulate(4,2)((m,p) => {
            dut.io.i.FP32(p)(m) #= BigInt(dut.io.i.FP32(p)(m).getBitsWidth, scala.util.Random)
            // dut.io.i.FP32(p)(m) `#=` (1)
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

    def simFP64(times: Int = 10, seed: Int = scala.util.Random.nextInt()){
      def name: String = "FP64"
      compiled.doSim(name){dut =>
        //Fork a process to generate the reset and the clock on the dut
        dut.clockDomain.forkStimulus(period = 10)
        dut.ctl.i.mode #= ModeConfig.MUL_FP64
        dut.clockDomain.waitRisingEdge()
        for(_times <- 0 to times-1 ){
          Array.tabulate(1,2)((m,p) => {
            val in____ = BigInt(dut.io.i.FP64(p)(m).getBitsWidth, scala.util.Random)
            dut.io.i.FP64(p)(m) #= in____
            // println(in____)
            // println(in____.toString(2))
          })
          dut.clockDomain.waitRisingEdge()
          val EQUAL = dut.verify.EQUAL.toBoolean
          val verify_out = dut.verify.o.FP64(0).toBigInt
          val rtl_out = dut.io.o.FP64(0).toBigInt
          // println("verify_out")
          // println(verify_out)
          // println(verify_out.toString(2))
          // println("rtl_out")
          // println(rtl_out)
          // println(rtl_out.toString(2))
          if (!EQUAL) {
            System.err.println("** ERROR ** "+name+" with seed "+seed)
          }
        }
      }
      println(Console.GREEN+"** FINISHED ** "+name+" with "+times+" times")
    }

    simINT8(times=100)
    simFP16(times=100)
    simFP32(times=100)
    simFP64(times=100)

  }
}