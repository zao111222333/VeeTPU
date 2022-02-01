package veetpu.array.floatingaddertree
import fp._
object  Data1{
  val FPData = Array(
  Array("1","10011101","00100100011011001100000"),
  Array("0","10011101","00000110010011110010010"),
  Array("1","10011011","01110011101011011111111"),
  Array("1","10010111","10111101001001101110111"),
  Array("0","10011011","01010110101101000001011"),
  Array("1","10011100","01100101001010110101111"),
  Array("0","10011010","10001100011101001001011"),
  Array("0","10011100","01110011110011011111111"),
  Array("1","10011001","00011110010111110011111"),
  Array("0","10011100","10001000110010001001000"),
  Array("0","10011100","00000110101010100010101"),
  Array("1","10011100","01000010001101110000000"),
  Array("1","10011011","01011001111010000011110"),
  Array("1","10011100","11010100111010010011111"),
  Array("0","10011011","01110101101100101000100"),
  Array("0","10011011","00000001100110001011101"))
  val FP32_List = Array.tabulate(16)((n) => {
    FPSim32(FPData(n)(0),FPData(n)(1),FPData(n)(2))
  })
}

// sbt "runMain veetpu.array.floatingaddertree.Data1Test" 
object Data1Test {
  def main(args: Array[String]): Unit = {
    var sum = 0f
    for (i <- 0 to 16-1){
      sum += Data1.FP32_List(i).getFloat
      println (Data1.FP32_List(i).getFloat)
    }
    println (sum)
  }
}