package ip.addertree

import spinal.core._
import spinal.sim._
import spinal.core.sim._

import scala.util.Random

import scala.math.pow

// sbt "runMain ip.addertree.add_tree_16in_Sim" 
object add_tree_16in_Sim {

  def main(args: Array[String]) {
    
    val simConfig = SpinalConfig(
      defaultClockDomainFrequency = FixedFrequency(10 MHz),
      defaultConfigForClockDomains = ClockDomainConfig(resetKind = SYNC))

    val compiled = SimConfig
                    .withWave
                    .withConfig(simConfig)
                    .allOptimisation
                    .workspacePath("simWorkspace")
                    .compile(new add_tree_16in_TOP)
    
    // compiled.mergeRTLSource("mergeRTL")
    compiled.doSim("test1"){dut =>
      //Fork a process to generate the reset and the clock on the dut
      dut.clockDomain.forkStimulus(period = 10)
      // 已经测试完成 
      // [success] Total time: 7675 s (02:07:55), completed Jul 26, 2021 1:53:30 PM                                               
      val simTime = 10
      for(m <- 0 to simTime ){
          for(n <- 0 to 15 ){
            //println(data1.SInt_List(i))
            val data1 = simData(4)
            dut.io.i.data(n) #= toBigInt("10001")
          }
          // val result_of_input = sum.toLong
          dut.clockDomain.waitRisingEdge()
          // val rtl_out = dut.io.o.sum.toLong
          // println(rtl_out)
          // println(rtl_out.toBinaryString)
          // assert(isEqual(result_of_input.toBinaryString,rtl_out.toBinaryString,28))
          // isEqual(result_of_input.toBinaryString,rtl_out.toBinaryString)
          }
        }
  }
}