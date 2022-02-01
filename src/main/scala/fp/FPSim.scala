// String
// 
// Float   (Value, can + - x /)
// to Float(Value): java.lang.Float.intBitsToFloat(intValue)
// to String      : java.lang.Float.floatToRawIntBits(f).toBinaryString

package fp
object  FPSim32{
  val fpConfig = FPConfig.FP32
  def toBigInt(s : String):BigInt={
    var out : BigInt = 0
    for ((b,i)<-s.reverse.zipWithIndex){
      out += b.asDigit*(BigInt(1)<<i)
    }
    return out
  }
  def apply(f: Float):FPSim={
    val fp = new FPSim()
    fp.initFromFloat(f,fpConfig)
    return fp
  }
  def apply(sign: Boolean, exp: Int, mant: Int):FPSim={
    val fp = new FPSim()
    fp.initFromArray(sign,exp,mant,fpConfig)
    return fp
  }
  def apply(sign: String, exp: String, mant: String):FPSim={
    apply(sign=="1",toBigInt(exp).toInt,toBigInt(mant).toInt)
  }
  def Random:FPSim={
    val f = scala.util.Random.nextFloat * scala.util.Random.nextInt
    val fp = new FPSim()
    fp.initFromFloat(f,fpConfig)
    return fp
  }
  def PositiveRandom:FPSim={
    val f = scala.util.Random.nextFloat * scala.util.Random.nextInt(2048)
    val fp = new FPSim()
    fp.initFromFloat(f,fpConfig)
    return fp
  }
}

class FPSim() {  
    var fpConfig = FPConfig.FP32
    var f    : Float   = 0f
    var sign : Boolean = false
    var exp  : Int     = 0
    var mant : Int     = 0

    override def toString: String={
      def getString(n: Int, s: String):String={
        var out = ""
        for (i <- 0 to n-1){
          out = out + s
        }
        return out
      }
			val f_str = java.lang.Float.floatToRawIntBits(f).toBinaryString
      getString(fpConfig.fullSize-f_str.length(),"0")+f_str
		}
    def toStringArray: (String,String,String)={
      val str = this.toString
      (str.substring(0,1),str.substring(1,1+fpConfig.expSize),str.substring(1+fpConfig.expSize,1+fpConfig.expSize+fpConfig.mantSize))
    }
    def toIntArray: (Boolean,Int,Int)={
      val (sign,exp,mant) = this.toStringArray
      (sign=="1",
       java.lang.Integer.parseInt(exp,2),
       java.lang.Integer.parseInt(mant,2))
    }
    def initFromFloat(f_ : Float, fpConfig_ : FPConfig):Unit={
      this.f = f_
      this.fpConfig = fpConfig_
      val (sign_,exp_,mant_) = this.toIntArray
      this.sign = sign_
      this.exp  = exp_
      this.mant = mant_
    }
    def initFromArray(sign_ : Boolean, exp_ : Int, mant_ : Int, fpConfig_ : FPConfig):Unit={
      this.sign = sign_
      this.exp  = exp_
      this.mant = mant_
      this.fpConfig = fpConfig_
      implicit def bool2int(b:Boolean) = if (b) 1 else 0
      val intValue : Int = (sign <<(fpConfig.expSize+fpConfig.mantSize)) + (exp << fpConfig.mantSize) + mant
      this.f = java.lang.Float.intBitsToFloat(intValue)
    }
    def toFloat(sign : Boolean, exp : Int, mant : Int):Float={
      implicit def bool2int(b:Boolean) = if (b) 1 else 0
      val intValue : Int = (sign <<(fpConfig.expSize+fpConfig.mantSize)) + (exp << fpConfig.mantSize) + mant
      java.lang.Float.intBitsToFloat(intValue)
    }
    def getFloat:Float=f
}

object FPSim32_Test {
  def main(args: Array[String]){
    // val fp32 = FP32(172.8000f)
    val fp32 = FPSim32(java.lang.Float.NaN)
    println(fp32.toStringArray)
    println(fp32.toIntArray)
    val fp321 = FPSim32(false,134,2936013)
    println(fp32.sign+"_"+fp32.exp+"_"+fp32.mant)
    println(fp321.toStringArray)
    // val fp32 = new Array[FP32](16)
    // for(i <- 0 to 15 ){
      // val f = 3.3f+i
      // fp32(i) = FP32(f)
    // }
  }
}

//0_10000000_10011001100110011001101
//11111101100011100010010001001111