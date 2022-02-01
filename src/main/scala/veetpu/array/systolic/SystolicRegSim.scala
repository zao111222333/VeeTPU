package veetpu.array

import spinal.core._
import spinal.lib._
// sbt runMain veetpu.array.SystolicReg_Verilog
// import spinal.lib.experimental.math._
import ip._
import fp._
import spinal.sim._
import spinal.core.sim._
import scala.util.Random

object SystolicRegSim {
  def main(args: Array[String]) {
    
    val simConfig = SpinalConfig(
      defaultClockDomainFrequency = FixedFrequency(10 MHz),
      defaultConfigForClockDomains = ClockDomainConfig(resetKind = SYNC))
    val systolicConfig = SystolicConfig(
          xVectorLength =16,
          yVectorLength =16,
          dataAWidth    =256,
          dataBWidth    =256,
          addPipeLength =2
                      )
    val compiled = SimConfig
                    .withWave
                    .withConfig(simConfig)
                    // .allOptimisation
                    .workspacePath("simWorkspace")
                    .compile(new SystolicReg(systolicConfig))

    compiled.doSim("Systolic"){dut =>
      //Fork a process to generate the reset and the clock on the dut
      dut.clockDomain.forkStimulus(period = 10)
      //val fp32 = FP32(3.3f)
      val simTimes:Int = 10
      
      for(m <- 0 to simTimes ){
        
        dut.ctl.wAddr #=m
        dut.ctl.wEn #= true
        
        for(i <- 0 to 15 ){
          dut.io.i.dataA(i) #= 111
          dut.io.i.dataB(i) #= 222
        }
        dut.clockDomain.waitRisingEdge()
      }
    }
  }
}