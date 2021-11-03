
package veetpu.fp

import spinal.core._

object FPConfig{
    def apply(expSize: Int,mantSize: Int):FPConfig={
        val fpConfig = new FPConfig()
        fpConfig.expSize_ = expSize
        fpConfig.mantSize_ = mantSize
        fpConfig}
    def FP16():FPConfig={
        val fpConfig = new FPConfig()
        fpConfig.expSize_ = 5
        fpConfig.mantSize_ = 10
        fpConfig}
    def FP32():FPConfig={
        val fpConfig = new FPConfig()
        fpConfig.expSize_ = 8
        fpConfig.mantSize_ = 23
        fpConfig}
    def FP64():FPConfig={
        val fpConfig = new FPConfig()
        fpConfig.expSize_ = 11
        fpConfig.mantSize_ = 52
        fpConfig}
    def BF16():FPConfig={
        val fpConfig = new FPConfig()
        fpConfig.expSize_ = 8
        fpConfig.mantSize_ = 7
        fpConfig}
}

class FPConfig(){
    var expSize_  : Int = -1
    var mantSize_ : Int = -1
    def expSize  = this.expSize_
    def mantSize = this.mantSize_

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
    def FP16():FP={new FP(FPConfig.FP16)}
    def FP32():FP={new FP(FPConfig.FP32)}
    def FP64():FP={new FP(FPConfig.FP64)}
}
class FP(c: FPConfig) extends Bundle {
    
    val sign    = Bool
    val exp     = UInt(c.expSize  bits)
    val mant    = UInt(c.mantSize bits)

    def config: FPConfig = c

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
        sign := that.sign
        exp  := ((config.bias - that.config.bias)+that.exp).resize(config.expSize)
        mant := that.mant.asBits.resizeLeft(config.mantSize).asUInt
    }

    def init() : FP = {
        sign init(False)
        exp  init(0)
        mant init(0)
        this
    }

    override def clone: FP = {
//         override def clone: Bundle = {
//     if (hardtype != null) {
//       val ret = hardtype().asInstanceOf[this.type]
//       ret.hardtype = hardtype
//       return ret
//     }
//     super.clone.asInstanceOf[Bundle]
//   }

        val fp = new FP(this.config)
        // fp.sign := this.sign
        // fp.exp  := this.exp
        // fp.mant := this.mant
        fp
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