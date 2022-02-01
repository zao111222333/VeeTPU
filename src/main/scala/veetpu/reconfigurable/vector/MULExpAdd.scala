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

class MULExpAdd() extends Component{

  val ctl = new Bundle{
    val i = new Bundle{
      val mode = in (Mode())
    }
  }

  val io = new Bundle{
    val i = new Bundle{
      val BF16  = in Vec(Vec(UInt( 7 bits), 16), 2)
      val FP16  = in Vec(Vec(UInt( 5 bits), 16), 2)
      val FP32  = in Vec(Vec(UInt( 8 bits),  4), 2)
      val TF32  = in Vec(Vec(UInt( 8 bits),  4), 2)
      val FP64  = in Vec(Vec(UInt(11 bits),  1), 2)
    }
    val o = new Bundle{
      val BF16 = out Vec(UInt( 7+1   bits), 16)
      val FP16 = out Vec(UInt( 5+1   bits), 16)
      val FP32 = out Vec(UInt( 8+1   bits),  4)
      val TF32 = out Vec(UInt( 8+1   bits),  4)
      val FP64 = out Vec(UInt(11+1   bits),  1)
    }
  }
  noIoPrefix()
  val ADDsIN = Vec(Vec(UInt( 7 bits), 16), 2)
  val ADDs = Array.tabulate(16)((m) => {
    ADDsIN(0)(m) +^ ADDsIN(1)(m)
  })
  Array.tabulate(16,2)((m,p) => {
    ADDsIN(p)(m) := {(ctl.i.mode.isFP16|ctl.i.mode.isBF16) ? 
                                                    //  FP16 or BF16
                                                    io.i.BF16(p)(m) | 
                    ((ctl.i.mode.isFP32|ctl.i.mode.isTF32) ? 
                                                    //  FP32 or TF32
                                                    (if(m<=7){
                                                      (if(m%2==0){
                                                        io.i.FP32(p)(m/2)(0 to 3)
                                                      }else{
                                                        io.i.FP32(p)(m/2)(4 to 7)
                                                      })
                                                    }else{
                                                      io.i.BF16(p)(m)
                                                    })|
                                      ((ctl.i.mode.isFP64) ?
                                                    //  FP64
                                                    (if(m==0){
                                                      io.i.FP64(p)(0)(0 to 6)
                                                    }else{
                                                      (if(m==1){
                                                        io.i.FP64(p)(0)(7 to 10)
                                                      }else{
                                                        io.i.BF16(p)(m)
                                                      })
                                                    })
                                                    //  Defalut
                                                    | io.i.BF16(p)(m)
    ))}
  })
  Array.tabulate(16)((m) => {
    io.o.BF16(m) := ADDs(m)
    io.o.FP16(m) := ADDs(m).resized
  })
  Array.tabulate(4)((m) => {
    io.o.FP32(m) := ((ADDs(2*m+1).resize(5)@@U"0000")+^ADDs(2*m).resize(5)).resized
    io.o.TF32(m) := ((ADDs(2*m+1).resize(5)@@U"0000")+^ADDs(2*m).resize(5)).resized
  })
  io.o.FP64(0) := ((ADDs(1).resize(5)@@U"0000000")+^ADDs(0).resize(8)).resized
}
object MULExpAdd_Verilog {
  def main(args: Array[String]): Unit = {
    val path = "simWorkspace/MULExpAdd/rtl"
    java.nio.file.Files.createDirectories(java.nio.file.Paths.get(path))
    val report = SpinalConfig(
      mode=Verilog,
      targetDirectory=path
    ).generate(new MULExpAdd())
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

class MULExpAdd_Verif() extends Component{

  val ctl = new Bundle{
    val i = new Bundle{
      val mode = in (Mode())
    }
  }

  val io = new Bundle{
    val i = new Bundle{
      val BF16  = in Vec(Vec(UInt( 7 bits), 16), 2)
      val FP16  = in Vec(Vec(UInt( 5 bits), 16), 2)
      val FP32  = in Vec(Vec(UInt( 8 bits),  4), 2)
      val TF32  = in Vec(Vec(UInt( 8 bits),  4), 2)
      val FP64  = in Vec(Vec(UInt(11 bits),  1), 2)
    }
    val o = new Bundle{
      val BF16 = out Vec(UInt( 7+1   bits), 16)
      val FP16 = out Vec(UInt( 5+1   bits), 16)
      val FP32 = out Vec(UInt( 8+1   bits),  4)
      val TF32 = out Vec(UInt( 8+1   bits),  4)
      val FP64 = out Vec(UInt(11+1   bits),  1)
    }
  }
  val dut = new MULExpAdd()
  dut.io.i.assignAllByName(io.i)
  dut.ctl.i.assignAllByName(ctl.i)
  io.o.assignAllByName(dut.io.o)
  val verify = new Bundle{
    val o = new Bundle{
      val BF16 = out Vec(UInt( 7+1   bits), 16)
      val FP16 = out Vec(UInt( 5+1   bits), 16)
      val FP32 = out Vec(UInt( 8+1   bits),  4)
      val TF32 = out Vec(UInt( 8+1   bits),  4)
      val FP64 = out Vec(UInt(11+1   bits),  1)
    }
    val equal = new Bundle{
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
    verify.o.BF16(n) := io.i.BF16(0)(n)+^io.i.BF16(1)(n)
    verify.o.FP16(n) := io.i.FP16(0)(n)+^io.i.FP16(1)(n)
  })
  Array.tabulate(4)((n) => {
    verify.o.FP32(n) := io.i.FP32(0)(n)+^io.i.FP32(1)(n)
    verify.o.TF32(n) := io.i.TF32(0)(n)+^io.i.TF32(1)(n)
  })
  verify.o.FP64(0) := io.i.FP64(0)(0)+^io.i.FP64(1)(0)
  verify.equal.BF16 := io.o.BF16===verify.o.BF16
  verify.equal.FP16 := io.o.FP16===verify.o.FP16
  verify.equal.FP32 := io.o.FP32===verify.o.FP32
  verify.equal.TF32 := io.o.TF32===verify.o.TF32
  verify.equal.FP64 := io.o.FP64===verify.o.FP64
  when(ctl.i.mode.isBF16) {
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

object MULExpAdd_Sim {

  def main(args: Array[String]) {

    val simConfig = SpinalConfig(
      defaultClockDomainFrequency = FixedFrequency(10 MHz),
      defaultConfigForClockDomains = ClockDomainConfig(resetKind = SYNC))
    
    val compiled = SimConfig
                    // .withWave
                    .withConfig(simConfig)
                    // .allOptimisation
                    .workspacePath("simWorkspace")
                    .compile(new MULExpAdd_Verif())

    def simBF16(times: Int = 10, seed: Int = scala.util.Random.nextInt()){
      def name: String = "BF16"
      compiled.doSim(name){dut =>
        //Fork a process to generate the reset and the clock on the dut
        dut.clockDomain.forkStimulus(period = 10)
        dut.ctl.i.mode #= ModeConfig.MUL_BF16
        dut.clockDomain.waitRisingEdge()
        for(_times <- 0 to times-1 ){
          Array.tabulate(16,2)((m,p) => {
            dut.io.i.BF16(p)(m) #= BigInt(dut.io.i.BF16(p)(m).getBitsWidth, scala.util.Random)
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
            dut.io.i.FP64(p)(m) #= BigInt(dut.io.i.FP64(p)(m).getBitsWidth, scala.util.Random)
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

    simBF16(times=100000)
    simFP32(times=100000)
    simFP64(times=100000)

  }
}