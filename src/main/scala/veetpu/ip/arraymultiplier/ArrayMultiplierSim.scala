package veetpu.ip

import spinal.core._
import spinal.sim._
import spinal.core.sim._

import scala.util.Random

import scala.math.pow

// sbt "runMain veetpu.ip.ArrayMultiplierSim" 
object ArrayMultiplierSim {

  def main(args: Array[String]) {
    
    val simConfig = SpinalConfig(
      defaultClockDomainFrequency = FixedFrequency(10 MHz),
      defaultConfigForClockDomains = ClockDomainConfig(resetKind = SYNC))
    

    val compiled = SimConfig
                    .withWave
                    .withConfig(simConfig)
                    .allOptimisation
                    .workspacePath("simWorkspace")
                    .compile(new ArrayMultiplier(16,16))
    
    // compiled.mergeRTLSource("mergeRTL")

    compiled.doSim("testA"){dut =>
      //Fork a process to generate the reset and the clock on the dut
      dut.clockDomain.forkStimulus(period = 10)
      var X:BigInt = 0
      var Y:BigInt = 0
      var P:BigInt = 0
        for(m <- 0 to 1000000 ){
          X = Random.nextInt(pow(2,16).toInt)
          Y = Random.nextInt(pow(2,16).toInt)
          dut.io.X #= X
          dut.io.Y #= Y
          P = X*Y
          //println(X)
          //println(Y)
          //println(P)
          dut.clockDomain.waitRisingEdge()
          val io_P = dut.io.P.toBigInt
          //println(io_P)
          assert(io_P == P)
          }
        }
    }
}