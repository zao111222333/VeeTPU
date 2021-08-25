package veetpu.ip.addertree

object toBigInt{
  def apply (s : String):BigInt={
    var out : BigInt = 0
    for ((b,i)<-s.reverse.zipWithIndex){
      out += b.asDigit*(BigInt(1)<<i)
    }
    return out
  }
}
object getString{
  def apply(n: Int, s: String):String={
    var out = ""
    for (i <- 0 to n-1){
      out = out + s
    }
    return out
  }
}

object notString{
  def apply (s : String, not : Boolean):String={
    var out : String = ""
    for ((b,i)<-s.zipWithIndex){
      out += (if (not) (if (b == '0') '1' else '0') else b)
    }
    return out
  }
}


object isEqual{
  def apply(str1: String, str2: String,dataWidth:Int):Boolean={
    val len1 = str1.length()
    val len2 = str2.length()
    val str1_ = if (len1<dataWidth) getString(dataWidth-len1,"0")+str1 else str1.substring(len1-dataWidth)
    val str2_ = if (len2<dataWidth) getString(dataWidth-len2,"0")+str2 else str2.substring(len2-dataWidth)
    // println(str1_)
    // println(str2_)
    str1_ == str2_
  }
}
object RandomZeroOne{
  def apply(len :Int):String={
    var out = ""
    def dLen : Int = len - out.length
    while(dLen > 0){
      val str = scala.util.Random.nextLong.toBinaryString
      if(str.length>dLen){
        out += str.substring(str.length-dLen)  
      }else{
        out += str
      }
    }
    out
  }
}