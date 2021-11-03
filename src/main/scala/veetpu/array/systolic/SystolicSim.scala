package veetpu.array

import spinal.core._
import spinal.lib._
// sbt "runMain veetpu.array.Systolic_Verilog"
// import spinal.lib.experimental.math._
import veetpu.ip._
import veetpu.fp._
// import build
import spinal.sim._
import spinal.core.sim._
import scala.util.Random
// 问题：误差出现过 8388567
// 需要定位
// sbt "runMain veetpu.array.floatingaddertree.FloatingAdderTreeSim" 
object SystolicSim {

  def main(args: Array[String]) {
    
    val simConfig = SpinalConfig(
      defaultClockDomainFrequency = FixedFrequency(10 MHz),
      defaultConfigForClockDomains = ClockDomainConfig(resetKind = SYNC))
    
    val compiled = SimConfig
                    .withWave
                    .withConfig(simConfig)
                    // .allOptimisation
                    .workspacePath("simWorkspace")
                    .compile(new Systolic())

    compiled.doSim("Systolic"){dut =>
      //Fork a process to generate the reset and the clock on the dut
      dut.clockDomain.forkStimulus(period = 10)
      //val fp32 = FP32(3.3f)
      val simTimes:Int = 10
      
      for(m <- 0 to simTimes ){
        
        dut.ctl.w_addr #=m
        dut.ctl.w_en #=true
        
        for(i <- 0 to 15 ){
          dut.ctl.mode_sel(i) #= 0
          dut.io.i.input(i) #= Random.nextLong
          dut.io.i.weight(i) #= Random.nextLong
        }
        dut.clockDomain.waitRisingEdge()
      }
    }
  }
}