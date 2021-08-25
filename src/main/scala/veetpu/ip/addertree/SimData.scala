package veetpu.ip.addertree

object simData{
  def genRandom(dataWidth: Int):Array[Array[String]] = Array.tabulate(16)((n) => {
    Array(RandomZeroOne(1),RandomZeroOne(dataWidth))
  })
  def genNegative(dataWidth: Int):Array[Array[String]] = Array.tabulate(16)((n) => {
    Array("0",getString(dataWidth,"1"))
  })
  def genOpsitvie(dataWidth: Int):Array[Array[String]] = Array.tabulate(16)((n) => {
    Array("1",getString(dataWidth,"1"))
  })
  def apply(dataWidth: Int):simData = new simData(genRandom(dataWidth))
  def Negative(dataWidth: Int):simData = new simData(genNegative(dataWidth))
  def Opsitvie(dataWidth: Int):simData = new simData(genOpsitvie(dataWidth))
}

class simData(sIntData : Array[Array[String]]){
  def sign_List:Array[Boolean] = Array.tabulate(16)((n) => {
    sIntData(n)(0)=="1"
  })
  def abs_List:Array[BigInt] = Array.tabulate(16)((n) => {
    toBigInt(sIntData(n)(1))
  })
  def SInt_List:Array[BigInt] = Array.tabulate(16)((n) => {
    (if (sign_List(n)) -1 else 1 )*abs_List(n)
  })
  def one_List:Array[String] = Array.tabulate(16)((n) => {
    def getString(n: Int, s: String):String={
      var out = ""
      for (i <- 0 to n-1){
        out = out + s
      }
      return out
    }
    notString(getString(4,"0")+sIntData(n)(1),sIntData(n)(0) == "1")
  })
  def two_List:Array[String] = Array.tabulate(16)((n) => {
    def getString(n: Int, s: String):String={
      var out = ""
      for (i <- 0 to n-1){
        out = out + s
      }
      return out
    }
    notString(getString(4,"0")+sIntData(n)(1),sIntData(n)(0) == "1")
  })
}
//      s  mant
// ori  1  1 0111 1011 1111 1010 0110 0101
// 1's  1  0 1000 0100 0000 0101 1001 1010
// 2‘s  1  0 1000 0100 0000 0101 1001 1011

// sbt "runMain veetpu.ip.Data1Test" 
object Data1Test {
  def main(args: Array[String]): Unit = {
    // var sum = BigInt(0)
    // for (i <- 0 to 16-1){
      // sum += Data1.SInt_List(i)
      // println (Data1.SInt_List(i))
      // println (Data1.one_List(i))
      // println (toBigInt(Data1.one_List(i)))
    // }
    // println (sum)
    for (m <- 0 to 3){
      var sum = BigInt(0)
      val data1 = simData(23)
      for (n <- 0 to 3){
        println (data1.SInt_List(4*m+n))
        println (data1.one_List(4*m+n)+"  "+toBigInt(data1.one_List(4*m+n)))
        sum += toBigInt(data1.one_List(4*m+n))
      }
      println(sum)
    }
  }
}
// 1101 0101 0011 1101 1111 000
