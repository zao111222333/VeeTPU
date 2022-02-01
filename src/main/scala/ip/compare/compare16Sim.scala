package ip

import spinal.core._
import spinal.sim._
import spinal.core.sim._

import scala.util.Random

import scala.math.pow

// sbt "runMain ip.compare16Sim" 
object compare16Sim {

  def main(args: Array[String]) {
    
    val simConfig = SpinalConfig(
      defaultClockDomainFrequency = FixedFrequency(10 MHz),
      defaultConfigForClockDomains = ClockDomainConfig(resetKind = SYNC))
    
    val dataWidth:Int = 11
    

    val compiled = SimConfig
                    .withWave
                    .withConfig(simConfig)
                    .allOptimisation
                    .workspacePath("simWorkspace")
                    .compile(new compare16(11))
    
    // compiled.mergeRTLSource("mergeRTL")

    compiled.doSim("testA"){dut =>
      //Fork a process to generate the reset and the clock on the dut
      dut.clockDomain.forkStimulus(period = 10)
      
      val X = new Array[Int](16)
      for(m <- 0 to 100000 ){
        for(i <- 0 to 15 ){
          X(i) = Random.nextInt(2048)
          dut.io.i.X(i) #= X(i)
        }
        dut.clockDomain.waitRisingEdge()
        val expect_max = X.max
        val rtl_out_max = dut.io.o.Max.toInt
        //println(expect_max)
        //println(rtl_out_max)
        assert(expect_max == rtl_out_max)
        for(i <- 0 to 15 ){
          val rtl_out_shift_i:Int = dut.io.o.Diff(i).toInt
          val expect_shift_i:Int = expect_max-X(i)
          //println(rtl_out_shift_i)
          //println(expect_shift_i)
          assert(rtl_out_shift_i == expect_shift_i)
        }
      }
    }
  }
}