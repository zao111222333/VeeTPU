
package veetpu.fp

import spinal.core._

class FPDemo extends Component {
    
    val config = FPConfig(8, 23)

    val io = new Bundle {
        val osc_clk     = in(Bool)

        val op_vld      = in(Bool)
        val op_a        = in(Bits(config.full_size bits))
        val op_b        = in(Bits(config.full_size bits))

        val op_a_p_op_b_vld     = out(Bool)
        val op_a_p_op_b         = out(Bits(config.full_size bits))

        val op_a_mul_op_b_vld   = out(Bool)
        val op_a_mul_op_b       = out(Bits(config.full_size bits))

        val op_a_div_op_b_vld   = out(Bool)
        val op_a_div_op_b       = out(Bits(config.full_size bits))
    }

    noIoPrefix()

    val resetCtrlClockDomain = ClockDomain(
        clock = io.osc_clk,
        frequency = FixedFrequency(50 MHz),
        config = ClockDomainConfig(
                    resetKind = BOOT
        )
    )

    val resetCtrl = new ClockingArea(resetCtrlClockDomain) {
        val reset_unbuffered_ = True

        val reset_cntr = Reg(UInt(5 bits)) init(0)
        when(reset_cntr =/= U(reset_cntr.range -> true)){
            reset_cntr := reset_cntr + 1
            reset_unbuffered_ := False
        }

        val reset_ = RegNext(reset_unbuffered_)
    }

    val coreClockDomain = ClockDomain(
        clock = io.osc_clk,
        reset = resetCtrl.reset_,
        config = ClockDomainConfig(
            resetKind = SYNC,
            resetActiveLevel = LOW
        )
    )

    val core = new ClockingArea(coreClockDomain) {

        val u_sint2FP_8 = new SInt2FP(8, config)
        u_sint2FP_8.io.op_vld := True
        u_sint2FP_8.io.op     := S(24, 8 bits)

        val u_sint2FP_16 = new SInt2FP(16, config)
        u_sint2FP_16.io.op_vld := True
        u_sint2FP_16.io.op     := S(-24, 16 bits)

        val add = new FPAdd(config, FPAddConfig(pipeStages = 5))
        add.io.op_vld :=    RegNext(io.op_vld)
        add.io.op_a.fromVec(RegNext(io.op_a))
        add.io.op_b.fromVec(RegNext(io.op_b))

        io.op_a_p_op_b_vld := RegNext(add.io.result_vld)
        io.op_a_p_op_b     := RegNext(add.io.result).toVec()

        val mul = new FPMul(config, FPMulConfig(pipeStages = 5))
        mul.io.op_vld :=    RegNext(io.op_vld)
        mul.io.op_a.fromVec(RegNext(io.op_a))
        mul.io.op_b.fromVec(RegNext(io.op_b))

        io.op_a_mul_op_b_vld := RegNext(mul.io.result_vld)
        io.op_a_mul_op_b     := RegNext(mul.io.result).toVec()

        val div = new FPDiv(config, FPDivConfig(pipeStages = 4, tableSizeBits = -1))
        div.io.op_vld :=    RegNext(io.op_vld)
        div.io.op_a.fromVec(RegNext(io.op_a))
        div.io.op_b.fromVec(RegNext(io.op_b))

        io.op_a_div_op_b_vld := RegNext(div.io.result_vld)
        io.op_a_div_op_b     := RegNext(div.io.result).toVec()
    }
}

object TopVerilog {
    def main(args: Array[String]) {
        SpinalVerilog(new FPDemo)
    }
}


