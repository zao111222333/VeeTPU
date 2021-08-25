package pe

import spinal.core._
import spinal.sim._
import spinal.core.sim._

import scala.util.Random

import scala.math.pow

// sbt "runMain pe.ArrayAdderCinSim" 
object ArrayAdderCinSim {
  implicit def bool2int(b:Boolean) = if (b) 1 else 0
  implicit def int2bool(b:Int) = if (b==0) false else true
  def log2up(m: Int) = java.lang.Math.ceil(java.lang.Math.log(m) / java.lang.Math.log(2)).toInt

  def main(args: Array[String]) {

    val size_A:Int = 8
    val size_B:Int = 1
    val size_S:Int = 8
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
                    .compile(new ArrayAdderCin(size_A,size_B,size_S))

    // 随机数仿真
    compiled.doSim("testA"){dut =>
      //Fork a process to generate the reset and the clock on the dut
      var idx = 0
      while(idx < 100){
        val A   = Random.nextInt(max_A+1)
        val B   = Random.nextInt(max_B+1)
        val Cin = Random.nextInt(2)
        dut.io.A   #= A
        dut.io.B   #= B
        dut.io.Cin #= Cin
        sleep(1) // Sleep 1 simulation timestep
        val Cout = dut.io.Cout.toBoolean
        val S = dut.io.S.toInt
        //assert(Cout*pow(2,size_S).toInt+S==((A+B+Cin) & 0xFF))
        idx += 1
      }
    }

    // 历变仿真
    compiled.doSim("testB"){dut =>
      //Fork a process to generate the reset and the clock on the dut
      dut.clockDomain.forkStimulus(period = 10)

      for(idx_A <- 0 to max_A ){
        dut.io.A #= idx_A
        dut.clockDomain.waitRisingEdge()
        for(idx_B <- 0 to max_B ){
          dut.io.B #= idx_B
          dut.clockDomain.waitRisingEdge()
          for(idx_Cin <- 0 to 1 ){
            dut.io.Cin #= idx_Cin
            dut.clockDomain.waitRisingEdge()

            val Cout = dut.io.Cout.toBoolean
            val S = dut.io.S.toInt
            //Update the reference model value
            //assert(Cout*pow(2,size_S).toInt+S==((idx_A+idx_B+idx_Cin) & 0xFF))
            if(Cout*pow(2,size_S).toInt+S!=idx_A+idx_B+idx_Cin) {
              haveError = true
              println(Console.RED + "have error")
              println(Console.RED + idx_A)
            }
          }
        }
      }
      if(haveError) simFailure() else simSuccess()
    }
  }
}