package veetpu.ip.addertree

import spinal.core._
import spinal.sim._
import spinal.core.sim._

import scala.util.Random

import scala.math.pow

// sbt "runMain veetpu.ip.addertree.AdderTree16S_Sim" 
object AdderTree16S_Sim {

  def main(args: Array[String]) {
    
    val simConfig = SpinalConfig(
      defaultClockDomainFrequency = FixedFrequency(10 MHz),
      defaultConfigForClockDomains = ClockDomainConfig(resetKind = SYNC))

    val compiled = SimConfig
                    //.withWave
                    .withConfig(simConfig)
                    .allOptimisation
                    .workspacePath("simWorkspace")
                    .compile(new veetpu.ip.AdderTree16S(23,3))
    
    // compiled.mergeRTLSource("mergeRTL")
    compiled.doSim("test1"){dut =>
      //Fork a process to generate the reset and the clock on the dut
      dut.clockDomain.forkStimulus(period = 10)
      // 已经测试完成 
      // [success] Total time: 7675 s (02:07:55), completed Jul 26, 2021 1:53:30 PM                                               
      val simTime = 10
      for(m <- 0 to simTime ){
          var sum: BigInt = 0
          for(i <- 0 to 15 ){
            //println(data1.SInt_List(i))
            val data1 = simData(23)
            sum += data1.SInt_List(i)
            dut.io.i.abs(i)  #= data1.abs_List(i)
            dut.io.i.sign(i) #= data1.sign_List(i)
          }
          val result_of_input = sum.toLong
          dut.clockDomain.waitRisingEdge()
          val rtl_out = dut.io.o.sum.toLong
          println(result_of_input)
          println(rtl_out)
          println(result_of_input.toBinaryString)
          println(rtl_out.toBinaryString)
          // assert(isEqual(result_of_input.toBinaryString,rtl_out.toBinaryString,28))
          // isEqual(result_of_input.toBinaryString,rtl_out.toBinaryString)
          }
        }
  }
}