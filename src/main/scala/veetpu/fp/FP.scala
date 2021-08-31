
package veetpu.fp

import spinal.core._

case class FPConfig(
                expSize    : Int,
                mantSize   : Int
                ) {

    def fullSize = 1 + expSize + mantSize
    def fullMantSize = 1 + mantSize

    def bias = (1<<(expSize-1))-1
    def maxExp = (1<<(expSize))-1
}

case class FPFlag() extends Bundle {
    val isZero = Bool
    val isDeno = Bool
    val isInfi = Bool
    val isQNaN = Bool
    val isSNaN = Bool
}
object FP{
    def apply(c: FPConfig):FP={new FP(c)}
    def apply(c: FPConfig, bits: Bits):FP={
        val fp = new FP(c)
        fp.fromBits(bits)
        fp
    }
    def apply(c: FPConfig, other: FP):FP={
        val fp = new FP(c)
        fp.fromOther(other)
        fp
    }
}
class FP(c: FPConfig) extends Bundle {
    
    val sign    = Bool
    val exp     = UInt(c.expSize  bits)
    val mant    = UInt(c.mantSize bits)

    def getConfig: FPConfig = c

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
        fpFlag.isZero := expIsZero &&  mantIsZero
        fpFlag.isDeno := expIsZero && !mantIsZero
        fpFlag.isInfi := expIsOnes &&  mantIsZero
        fpFlag.isQNaN := expIsOnes && !mantIsZero && !highMantIsZero
        fpFlag.isSNaN := expIsOnes && !mantIsZero &&  highMantIsZero
        return fpFlag
    }
    
    def fullMant(isDenoOrZero: Bool) : UInt = {
        isDenoOrZero ? mant.resize(c.mantSize+1) | (mant.resize(c.mantSize+1) | (1<<c.mantSize))
    }
    
    def setZero() = {
        exp     := 0
        mant    := 0
    }

    def setQNaN = {
        exp     := (default -> true)                        // Assign exp with "11111111"
        mant    := (default -> true)                        // Assign mant with "11111111"
    }
    
    def setSNaN = {
        exp     := (default -> true)                        // Assign exp with "11111111"
        mant    := 1
    }

    def setInfi = {
        exp     := (default -> true)                        // Assign exp with "11111111"
        mant    := 0
    }

    override def asBits() : Bits = {
        sign ## exp.asBits ## mant.asBits
    }

    def fromBits(bit: Bits) = {
        sign    := bit(c.expSize + c.mantSize)
        exp     := bit(c.mantSize, c.expSize bits).asUInt
        mant    := bit(0, c.mantSize bits).asUInt
    }

    def fromOther(that: FP) = {
        // val flag = that.getFlag
        // this.exp  := flag.mux(
        //             B"00" -> 0,
        //             B"00" -> (default -> true),
        //             default -> that.exp
        //             )
        // TODO Flag select
        this.sign := that.sign
        this.exp  := (this.getConfig.bias - that.getConfig.bias)+that.exp
        this.mant := that.mant.asBits.resizeLeft(this.getConfig.mantSize).asUInt
    }

    def init() : FP = {
        sign init(False)
        exp  init(0)
        mant init(0)
        this
    }
}

object FP_Test {
  def main(args: Array[String]): Unit = {
    // val fp32 = FP32(172.8000f)
    val fp32 = FP32(122.2f)
    println(fp32.toStringArray)
    println(fp32.toIntArray)
    println(fp32.getFloat)
    // val fp321 = FP32(false,134,2936013)
    // println(fp32.sign+"_"+fp32.exp+"_"+fp32.mant)
    // println(fp321.toStringArray)
    // val fp32 = new Array[FP32](16)
    // for(i <- 0 to 15 ){
      // val f = 3.3f+i
      // fp32(i) = FP32(f)
    // }
  }
}