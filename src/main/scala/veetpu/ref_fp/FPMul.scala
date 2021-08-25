
package veetpu.ref_fp

import spinal.core._

case class FPMulConfig(
    pipeStages      : Int     = 1,
    hwMul           : Boolean = false
    ){
}

class FPMul(c: FPConfig, mulConfig: FPMulConfig = null) extends Component {

    def pipeStages      = if (mulConfig == null) 1     else mulConfig.pipeStages
    def hwMul           = if (mulConfig == null) false else mulConfig.hwMul

    val io = new Bundle {
        val op_vld      = in(Bool)
        val op_a        = in(FP(c))
        val op_b        = in(FP(c))

        val result_vld  = out(Bool)
        val result      = out(FP(c))
    }

    val p0_vld  = io.op_vld
    val op_a_p0 = io.op_a
    val op_b_p0 = io.op_b

    val op_isNan_p0    = op_a_p0.isNan() || op_b_p0.isNan()
    val op_a_isZero_p0 = op_a_p0.isZero()
    val op_b_isZero_p0 = op_b_p0.isZero()
    val op_isZero_p0   = (op_a_isZero_p0 || op_b_isZero_p0) && !op_isNan_p0

    val exp_a_p0 = op_a_p0.exp
    val exp_b_p0 = op_b_p0.exp

    val mant_a_p0 = U(1, 1 bits) @@ op_a_p0.mant
    val mant_b_p0 = U(1, 1 bits) @@ op_b_p0.mant

    val sign_mul_p0 = op_a_p0.sign ^ op_b_p0.sign

    //============================================================

    val p1_pipe_ena = pipeStages >= 2
    val p1_vld          = OptPipeInit(p0_vld, False, p1_pipe_ena)
    val op_isZero_p1   = OptPipe(op_isZero_p0,   p0_vld, p1_pipe_ena)
    val op_isNan_p1    = OptPipe(op_isNan_p0,    p0_vld, p1_pipe_ena)
    val sign_mul_p1     = OptPipe(sign_mul_p0,     p0_vld, p1_pipe_ena)
    val exp_a_p1        = OptPipe(exp_a_p0,        p0_vld, p1_pipe_ena)
    val exp_b_p1        = OptPipe(exp_b_p0,        p0_vld, p1_pipe_ena)
    val mant_a_p1       = if (hwMul) null else OptPipe(mant_a_p0, p0_vld, p1_pipe_ena)
    val mant_b_p1       = if (hwMul) null else OptPipe(mant_b_p0, p0_vld, p1_pipe_ena)

    //============================================================

    val exp_mul_p1 = SInt(c.expSize+2 bits)

    exp_mul_p1 := exp_a_p1.resize(c.expSize+2).asSInt + exp_b_p1.resize(c.expSize+2).asSInt - S(c.bias, c.expSize+2 bits)

    val mant_mul_p1 = UInt(c.mantSize+2 bits)
    if (hwMul){
        val mul_result = SInt(36 bits)

        val u_mul = new MULT18X18SIO(
            inputFF     = pipeStages >= 2,          // p1_pipe_ena
            outputFF    = pipeStages >= 1           // p2_pipe_ena
            )

        u_mul.io.A      <> mant_a_p0.resize(18).asSInt
        u_mul.io.B      <> mant_b_p0.resize(18).asSInt
        u_mul.io.P      <> mul_result
        u_mul.io.BCIN   <> S(0, 18 bits)
        u_mul.io.CEA    <> p0_vld
        u_mul.io.CEB    <> p0_vld
        u_mul.io.CEP    <> True
        u_mul.io.RSTA   <> False
        u_mul.io.RSTB   <> False
        u_mul.io.RSTP   <> False

        mant_mul_p1 := mul_result.asUInt(c.mantSize, mant_mul_p1.getWidth bits)
    }
    else{
        mant_mul_p1 := (mant_a_p1 * mant_b_p1) >> c.mantSize
    }

    //============================================================
    val p2_pipe_ena = pipeStages >= 1
    val p2_vld          = OptPipeInit(p1_vld, False, p2_pipe_ena)
    val op_isZero_p2   = OptPipe(op_isZero_p1,   p1_vld, p2_pipe_ena)
    val op_isNan_p2    = OptPipe(op_isNan_p1,    p1_vld, p2_pipe_ena)
    val sign_mul_p2     = OptPipe(sign_mul_p1,     p1_vld, p2_pipe_ena)
    val exp_mul_p2      = OptPipe(exp_mul_p1,      p1_vld, p2_pipe_ena)
    val mant_mul_p2     = if (hwMul) mant_mul_p1 else OptPipe(mant_mul_p1,     p1_vld, p2_pipe_ena)
    //============================================================

    val exp_mul_adj_p2  = SInt(c.expSize+2 bits)
    val mant_mul_adj_p2 = UInt(c.mantSize+1 bits)

    mant_mul_adj_p2 := (mant_mul_p2 |>> mant_mul_p2.msb.asUInt).resize(c.mantSize+1)
    exp_mul_adj_p2  := exp_mul_p2 + mant_mul_p2.msb.asUInt.resize(2).asSInt

    val sign_final_p2 = Bool
    val exp_final_p2  = UInt(c.expSize bits)
    val mant_final_p2 = UInt(c.mantSize bits)

    when(op_isNan_p2){
        sign_final_p2   := False
        exp_final_p2.setAll
        mant_final_p2   := (c.mantSize-1 -> True, default -> False)
    }
    .elsewhen(op_isZero_p2 || exp_mul_adj_p2 <= 0){
        sign_final_p2   := False
        exp_final_p2.clearAll
        mant_final_p2.clearAll
    }
    .elsewhen(exp_mul_adj_p2 >= 255){
        sign_final_p2   := sign_mul_p2
        exp_final_p2.setAll
        mant_final_p2.clearAll
    }
    .otherwise{
        sign_final_p2   := sign_mul_p2
        exp_final_p2    := exp_mul_adj_p2.resize(c.expSize).asUInt
        mant_final_p2   := mant_mul_adj_p2.resize(c.mantSize)
    }

    io.result_vld   := p2_vld
    io.result.sign  := sign_final_p2
    io.result.exp   := exp_final_p2
    io.result.mant  := mant_final_p2

}
