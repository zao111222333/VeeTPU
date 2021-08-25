package FP

import spinal.core._
import spinal.sim._
import spinal.core.sim._

import scala.util.Random

import scala.math.pow

// sbt "runMain FP.AdderTree16Sim" 
object AdderTree16Sim {

  def main(args: Array[String]) {
    
    val simConfig = SpinalConfig(
      defaultClockDomainFrequency = FixedFrequency(10 MHz),
      defaultConfigForClockDomains = ClockDomainConfig(resetKind = SYNC))
    

    val compiled = SimConfig
                    .withWave
                    .withConfig(simConfig)
                    .allOptimisation
                    .workspacePath("simWorkspace")
                    .compile(new AdderTree16(11))
    
    // compiled.mergeRTLSource("mergeRTL")

    compiled.doSim("testA"){dut =>
      //Fork a process to generate the reset and the clock on the dut
      dut.clockDomain.forkStimulus(period = 10)
      val X = new Array[Int](16)
        for(m <- 0 to 1000000 ){
          for(i <- 0 to 15 ){
              X(i) = Random.nextInt(2048)
              dut.io.i.X(i) #= X(i)
          }
          val result_of_input = X.sum
          dut.clockDomain.waitRisingEdge()
          val rtl_out = dut.io.o.S.toInt
          assert(result_of_input == rtl_out)
          }
        }
    }
}