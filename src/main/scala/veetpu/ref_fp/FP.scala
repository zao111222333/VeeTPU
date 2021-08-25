
package veetpu.ref_fp

import spinal.core._

case class FPConfig(
                expSize    : Int,
                mantSize   : Int
                ) {

    def fullSize = 1 + expSize + mantSize
    def fullMantSize = 1 + mantSize

    def bias = (1<<(expSize-1))-1
}

case class FPFlag() extends Bundle {
    val isZero = Bool
    val isDeno = Bool
    val isInfi = Bool
    val isQNaN = Bool
    val isSNaN = Bool
}

case class FP(c: FPConfig) extends Bundle {
    val sign    = Bool
    val exp     = UInt(c.expSize  bits)
    val mant    = UInt(c.mantSize bits)

    def mantIsZero: Bool = {
        !mant.orR
    }
    def highMantIsZero: Bool = {
        mant(c.mantSize-1)
    }
    def expIsZero: Bool = {
        !exp.orR
    }
    def expIsOnes: Bool = {
        exp.andR
    }
    def getFlag(): FPFlag = {
        val fpFlag = FPFlag()
        val mantIsZero     = this.mantIsZero
        val highMantIsZero = this.highMantIsZero
        val expIsZero      = this.expIsZero
        val expIsOnes      = this.expIsOnes
        fpFlag.isZero :=  expIsZero &&  mantIsZero
        fpFlag.isDeno := !expIsZero &&  mantIsZero
        fpFlag.isInfi :=  expIsOnes &&  mantIsZero
        fpFlag.isQNaN :=  expIsOnes && !mantIsZero && !highMantIsZero
        fpFlag.isSNaN :=  expIsOnes && !mantIsZero &&  highMantIsZero
        return fpFlag
    }
    
    def fullMant(isDenormal: Bool) : UInt = {
        isDenormal ? mant.resize(c.mantSize+1) | mant.resize(c.mantSize+1) | (1<<c.mantSize)
    }

    def isZero() : Bool = {
        !exp.orR && !mant.orR
    }

    def isDenormal() : Bool = {
        !exp.orR && mant.orR
    }

    def isNan(): Bool = {
        exp.andR && mant.orR
    }

    def isInfinite(): Bool = {
        exp.andR && !mant.orR
    }

    def setZero() = {
        sign    := False
        exp     := 0
        mant    := 0
    }

    def abs() : FP = {
        val abs = FP(c)

        abs.sign := False
        abs.exp  := exp
        abs.mant := mant

        abs
    }
    
    override def asBits() : Bits = {
        sign ## exp.asBits ## mant.asBits
    }

    def fromBits(bit: Bits) = {
        sign    := bit(c.expSize + c.mantSize)
        exp     := bit(c.mantSize, c.expSize bits).asUInt
        mant    := bit(0, c.mantSize bits).asUInt
    }

    def fromDouble(d: Double) = {
        if (Fp64.exp(d) == 0){
            sign    := False
            exp     := U(0, c.expSize bits)
            mant    := U(0, c.mantSize bits)
        }
        else{
            sign    := Bool((Fp64.sign(d) & 1) == 1)
            exp     := U(Fp64.exp(d)- Fp64.bias + c.bias, c.expSize bits)
            mant    := U(Fp64.mant(d) >> (Fp64.mant_bits - c.mantSize), c.mantSize bits)
        }
    }

    def init() : FP = {
        sign init(False)
        exp  init(0)
        mant init(0)
        this
    }
}

