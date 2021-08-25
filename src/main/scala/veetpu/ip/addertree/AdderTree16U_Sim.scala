package veetpu.ip

import spinal.core._
import spinal.sim._
import spinal.core.sim._

import scala.util.Random

import scala.math.pow

// sbt "runMain veetpu.ip.AdderTree16USim" 
object AdderTree16USim {

  def main(args: Array[String]) {
    
    val simConfig = SpinalConfig(
      defaultClockDomainFrequency = FixedFrequency(10 MHz),
      defaultConfigForClockDomains = ClockDomainConfig(resetKind = SYNC))
        
    val compiled = SimConfig
                    .withWave
                    .withConfig(simConfig)
                    .allOptimisation
                    .workspacePath("simWorkspace")
                    .compile(new AdderTree16U(32,3))
    
    // compiled.mergeRTLSource("mergeRTL")
    def toBigInt(s : String):BigInt={
      var out : BigInt = 0
      for ((b,i)<-s.reverse.zipWithIndex){
        out += b.asDigit*(BigInt(1)<<i)
      }
      return out
    }
    compiled.doSim("AdderTree"){dut =>
      //Fork a process to generate the reset and the clock on the dut
      dut.clockDomain.forkStimulus(period = 10)
      val X = new Array[Int](16)
      var sum: Long = 0
        for(m <- 0 to 1 ){
          for(i <- 0 to 15 ){
            X(i) = Random.nextInt
            sum += X(i)
            var x = toBigInt(X(i).toBinaryString)
            //dut.io.i.X(i) #= X(i)
            println(X(i).toBinaryString)
            println(x.toString(2))
            dut.io.i.X(i) #= x
          }
          val result_of_input = sum
          dut.clockDomain.waitRisingEdge()
          val rtl_out = dut.io.o.S.toBigInt
          println(result_of_input)
          println(rtl_out)
          println(result_of_input.toBinaryString)
          println(rtl_out.toString(2))
          // assert(result_of_input == rtl_out)
          }
        }
    }
}
// 1011_1011_1010_1011_0000_1101_1010_1011

// 1111111111111111111111111111111010100011001001100100001101000110
//                              11110011010101001000110101101101110