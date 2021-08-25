package pe

import spinal.core._
import spinal.sim._
import spinal.core.sim._

import scala.util.Random

import scala.math.pow

// sbt "runMain pe.ArrayAdderSim" 
//MyTopLevel's testbench
object ArrayAdderSim {
  implicit def bool2int(b:Boolean) = if (b) 1 else 0
  def log2up(m: Int) = java.lang.Math.ceil(java.lang.Math.log(m) / java.lang.Math.log(2)).toInt

  def main(args: Array[String]) {

    val size_A:Int = 4
    val size_B:Int = 1
    val size_S:Int = 4
    val max_A:Int = (pow(2,size_A)-1).toInt
    val max_B:Int = (pow(2,size_B)-1).toInt
    var haveError = false
    
    val simConfig = SpinalConfig(
      defaultClockDomainFrequency = FixedFrequency(10 MHz),
      defaultConfigForClockDomains = ClockDomainConfig(resetKind = SYNC))
    

    val compiled = SimConfig
                    .withWave
                    .withConfig(simConfig)
                    .allOptimisation
                    .workspacePath("simWorkspace")
                    .compile(new ArrayAdder(size_A,size_B,size_S))

    compiled.doSim("testA"){dut =>
      //Fork a process to generate the reset and the clock on the dut
      dut.clockDomain.forkStimulus(period = 10)

      for(idx_A <- 0 to max_A ){
        for(idx_B <- 0 to max_B ){
          //Drive the dut inputs with random values
          dut.io.A #= idx_A
          dut.io.B #= idx_B
          
          //Wait a rising edge on the clock
          dut.clockDomain.waitRisingEdge()
          
          val Cout = dut.io.Cout.toBoolean
          val S = dut.io.S.toInt
          
          //Update the reference model value
          if(Cout*pow(2,size_S).toInt+S!=idx_A+idx_B) {
            haveError = true
            println(Console.RED + "have error")
          }
        }
      }
    }
  }
}