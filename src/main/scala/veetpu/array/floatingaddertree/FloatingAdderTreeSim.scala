package veetpu.array.floatingaddertree

import spinal.core._
import spinal.sim._
import spinal.core.sim._

import scala.util.Random
import scala.collection.mutable.Queue

import ip._
import fp._
// 问题：误差出现过 8388567
// 需要定位
// sbt "runMain veetpu.array.floatingaddertree.FloatingAdderTreeSim" 
object FloatingAdderTreeSim {

  def main(args: Array[String]) {

    val simConfig = SpinalConfig(
      defaultClockDomainFrequency = FixedFrequency(10 MHz),
      defaultConfigForClockDomains = ClockDomainConfig(resetKind = SYNC))
    
    val fpatConfig = FPATConfig(
                    fpConfig = FPConfig.FP32(), 
                    size     = 16,
                    accuracy = 30,
                    adderTree_CLSA_PRE_WIDTH = 5
                    )
    
    val compiled = SimConfig
                    .withWave
                    .withConfig(simConfig)
                    // .allOptimisation
                    .workspacePath("simWorkspace")
                    .compile(new FloatingAdderTree(fpatConfig))

    compiled.doSim("fpaddertree"){dut =>
      //Fork a process to generate the reset and the clock on the dut
      dut.clockDomain.forkStimulus(period = 10)
      //val fp32 = FP32(3.3f)
      val fp32 = new Array[FPSim](16)
      val stage = 4
      val exp_out_fifo = new Queue[FPSim]
      var err:   Long = 0
      var errAbs:Long = 0
      var maxx = 0
      val simTimes:Int = 10
      
      for(m <- 0 to simTimes ){
        var sum = 0f
        for(i <- 0 to 15 ){
          // val f = scala.util.Random.nextFloat * scala.util.Random.nextInt
          fp32(i) = FPSim32.Random
          println("[input"+i+"] "+fp32(i).toStringArray)
          // println(fp32(i).toStringArray)
          // fp32(i) = Data1.FP32_List(i)
          // fp32(i) = FP32(java.lang.Float.MAX_VALUE/15)

          // if (i!=15){
          //   fp32(i) = FP32(java.lang.Float.MAX_VALUE/15)
          // }else{
          //   fp32(i) = FP32(java.lang.Float.NaN)
          // }
          // if (i!=15){
          //   fp32(i) = FP32(java.lang.Float.NEGATIVE_INFINITY)
          // }else{
          //   fp32(i) = FP32(java.lang.Float.POSITIVE_INFINITY)
          // }
          // println(m+" "+i)
          // println(fp32(i).getFloat)
          sum = sum + fp32(i).getFloat
          val (sign,exp,mant) = fp32(i).toIntArray
          dut.io.i.X(i).sign #= sign
          dut.io.i.X(i).exp  #= exp
          dut.io.i.X(i).mant #= mant
          
        }
        dut.clockDomain.waitRisingEdge()

        val rtl_out_sign = dut.io.o.Y.sign.toBoolean
        val rtl_out_exp  = dut.io.o.Y.exp.toInt
        val rtl_out_mant = dut.io.o.Y.mant.toInt
        val rtl_out = FPSim32(rtl_out_sign,rtl_out_exp,rtl_out_mant)
        exp_out_fifo.enqueue(FPSim32(sum))
        if (m>=stage){
          val exp_out = exp_out_fifo.dequeue()
          val errr = rtl_out.mant - exp_out.mant
          err    +=  errr
          errAbs += errr.abs
          maxx = math.max(errr.abs,maxx)
          println(errr)
          println("[rtl_out] "+rtl_out.getFloat)
          println("[exp_out] "+exp_out.getFloat)
          println("[rtl_out] "+rtl_out.toStringArray)
          println("[exp_out] "+exp_out.toStringArray)
        }
      }
      println (err.toFloat/simTimes/(1 << fpatConfig.fpConfig.mantSize))
      println (errAbs.toFloat/simTimes/(1 << fpatConfig.fpConfig.mantSize))
      println (err)
      println (errAbs)
      println (maxx)
    }
  }
}