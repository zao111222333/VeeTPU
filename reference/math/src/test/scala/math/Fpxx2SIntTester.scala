
package veetpu.fp

import org.scalatest.FunSuite

import math.FPTesterSupport._

import spinal.sim._
import spinal.core._
import spinal.core.sim._

object FP2SIntTester {

    class FP2SIntDut(config: FPConfig) extends Component {
        val io = new Bundle {
            val op_vld      = in(Bool)
            val op          = in(Bits(config.full_size bits))

            val result_vld  = out(Bool)
            val result      = out(Bits(28 bits))
        }

        val u_FP2sint_8 = new FP2SInt(16, 12, config)
        u_FP2sint_8.io.op_vld := RegNext(io.op_vld) init(False)
        u_FP2sint_8.io.op.fromVec(RegNext(io.op))

        io.result_vld := RegNext(u_FP2sint_8.io.result_vld) init(False)
        io.result     := RegNext(u_FP2sint_8.io.result).asBits
    }
}

class FP2SIntTester extends FunSuite {

    test("FP2SInt") {

        val config = FPConfig(8, 23)

        var compiled = SimConfig
            .withWave
            .compile(new FP2SIntTester.FP2SIntDut(config))

        compiled.doSim { dut =>

            dut.clockDomain.forkStimulus(period = 10)
            dut.clockDomain.forkSimSpeedPrinter(0.2)
            dut.io.op_vld #= false
            dut.clockDomain.waitSampling()

            val stimuli = Array[Double](0.0, 1.0, -1.0, 0.0001, 0.5, 20.0, 50.0,
                                        32767.5, 32768.0, -32767.5, -32768.0, 65535.5, 65536.0, -65535.5, -65536.0,
                                        (1L<<40).toDouble, -((1L<<32).toDouble), -1000.0, 127.55555, 255.55555)

            var i = 0
            var pass = 0
            var fail = 0

            while(i < stimuli.size){
                var input = stimuli(i)

                val op            = input

                // Convert signed int to positive long
                var op_long : Long = Fp32.asBits(op.toFloat)

                // Apply operands
                dut.io.op_vld #= true
                dut.io.op     #= op_long
                dut.clockDomain.waitSampling(1)
                dut.io.op_vld #= false

                // Wait until result appears
                while(!dut.io.result_vld.toBoolean){
                    dut.clockDomain.waitSampling()
                }

                // Actual result
                val result_act = ((dut.io.result.toInt<<4)>>4).toDouble / (1<<12)

                dut.clockDomain.waitSampling()

                printf("%f: (act) %f, (exp) %f\n", op, result_act, input)

                i+=1
            }

        }
    }

}
