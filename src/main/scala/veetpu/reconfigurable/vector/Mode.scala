package veetpu.reconfigurable.vector

import spinal.core._
import spinal.lib._
// sbt "runMain veetpu.array.floatingaddertree.FloatingADDerTree_Verilog"
// import spinal.lib.experimental.math._
import ip._
import fp._

// INT8():FPConfig=FPConfig( 0, 7)
// FP16():FPConfig=FPConfig( 5,10)
// FP32():FPConfig=FPConfig( 8,23)
// FP64():FPConfig=FPConfig(11,52)
// BF16():FPConfig=FPConfig( 8, 7)


object ModeConfig{
  def apply(
    length: Int          = 8,
    instr: String        = "00000000",
    delay: Int           = 3,
    inType: FPConfig     = FPConfig.FP16,
    outType: FPConfig    = FPConfig.FP16,
    inShape: Array[Int]  = Array(-1),
    outShape: Array[Int] = Array(-1),
  ):ModeConfig={new ModeConfig(length, instr, delay, inType, outType, inShape, outShape)}
  import FPConfig._
  // INT 的带宽会上升, 累加需要用2倍的寄存器
  // 乘法是INT8, 加法是INT32
  // INT8 ADD
  def ADD_INT8 = ModeConfig(instr="0001_0000", delay=2, inType=INT8, outType=INT32,inShape=Array(4, 0+4), outShape=Array(4,1))
  // INT8 MUL
  def MUL_INT8 = ModeConfig(instr="0010_0000", delay=2, inType=INT8, outType=INT32,inShape=Array(4,32+0), outShape=Array(4,1))
  // INT8 MAC
  def MAC_INT8 = ModeConfig(instr="0011_0000", delay=2, inType=INT8, outType=INT32,inShape=Array(4,32+2), outShape=Array(4,1))
  // Floating ADD
  def ADD_FP16 = ModeConfig(instr="0001_1000", delay=2, inType=FP16, outType=FP16, inShape=Array(4, 0+2), outShape=Array(4,1))
  def ADD_FP32 = ModeConfig(instr="0001_1001", delay=2, inType=FP32, outType=FP32, inShape=Array(2, 0+2), outShape=Array(2,1))
  def ADD_FP64 = ModeConfig(instr="0001_1010", delay=2, inType=FP64, outType=FP64, inShape=Array(1, 0+2), outShape=Array(1,1))
  def ADD_BF16 = ModeConfig(instr="0001_1100", delay=2, inType=BF16, outType=BF16, inShape=Array(4, 0+2), outShape=Array(4,1))
  def ADD_TF32 = ModeConfig(instr="0001_1101", delay=2, inType=TF32, outType=TF32, inShape=Array(2, 0+2), outShape=Array(2,1))
  // Floating MUL
  def MUL_FP16 = ModeConfig(instr="0010_1000", delay=3, inType=FP16, outType=FP16, inShape=Array(4,16+0), outShape=Array(4,1))
  def MUL_FP32 = ModeConfig(instr="0010_1001", delay=3, inType=FP32, outType=FP32, inShape=Array(2, 8+0), outShape=Array(2,1))
  def MUL_FP64 = ModeConfig(instr="0010_1010", delay=3, inType=FP64, outType=FP64, inShape=Array(1, 4+0), outShape=Array(1,1))
  def MUL_BF16 = ModeConfig(instr="0010_1100", delay=3, inType=BF16, outType=BF16, inShape=Array(4,16+0), outShape=Array(4,1))
  def MUL_TF32 = ModeConfig(instr="0010_1101", delay=3, inType=TF32, outType=TF32, inShape=Array(2, 8+0), outShape=Array(2,1))
  // Floating MAC
  def MAC_FP16 = ModeConfig(instr="0011_1000", delay=4, inType=FP16, outType=FP16, inShape=Array(4,16+1), outShape=Array(4,1))
  def MAC_FP32 = ModeConfig(instr="0011_1001", delay=4, inType=FP32, outType=FP32, inShape=Array(2, 8+1), outShape=Array(2,1))
  def MAC_FP64 = ModeConfig(instr="0011_1010", delay=4, inType=FP64, outType=FP64, inShape=Array(1, 4+1), outShape=Array(1,1))
  def MAC_BF16 = ModeConfig(instr="0011_1100", delay=4, inType=BF16, outType=BF16, inShape=Array(4,16+1), outShape=Array(4,1))
  def MAC_TF32 = ModeConfig(instr="0011_1101", delay=4, inType=TF32, outType=TF32, inShape=Array(2, 8+1), outShape=Array(2,1))
}


class ModeConfig(
  _length: Int         ,
  _instr: String       ,
  _delay: Int          ,
  _inType: FPConfig    ,
  _outType: FPConfig   ,
  _inShape: Array[Int] ,
  _outShape: Array[Int],
){
  def length   = _length
  def delay    = _delay
  def inType   = _inType
  def outType  = _outType
  def inShape  = _inShape
  def outShape = _outShape
  private[this] def instr = _instr.replace("_", "")
  private[this] def toBigInt (s : String):BigInt={
    var out : BigInt = 0
    for ((b,i)<-s.reverse.zipWithIndex){
      out += b.asDigit*(BigInt(1)<<i)
    }
    return out
  }
  def value = toBigInt(instr)

  def description:String={
    val opType=(_instr.substring(0,4) match {
      case "0001" => "ADD"
      case "0010" => "MUL"
      case "0011" => "MAC"
      case _ => "Not Define"
    })
    val dataType=(_instr.substring(4,8) match {
      case "0000" => "INT8"
      case "1000" => "FP16"
      case "1001" => "FP32"
      case "1010" => "FP64"
      case "1100" => "BF16"
      case "1101" => "TF32"
      case _ => "Not Define"
    })
    "opType: "+opType+"\ndataType: "+dataType
  }
}

case class ModeIO(c: ModeConfig) {
  def i = Vec(Vec(FP(c.inType),  c.inShape(1)),  c.inShape(0) )
  def o = Vec(Vec(FP(c.outType), c.outShape(1)), c.outShape(0))
}

case class Mode() extends Bundle{
  import spinal.core.sim._
  val bits : Bits = Bits(8 bits)
  def := (that : Mode) : Unit = this.bits := that.bits
  def := (that : Bits) : Unit = this.bits := that
  def #= (value: Int       ) : Unit = this.bits #= value
  def #= (value: Long      ) : Unit = this.bits #= value
  def #= (value: BigInt    ) : Unit = this.bits #= value
  def #= (mode : ModeConfig) : Unit = this.bits #= mode.value
  def isADD  : Bool = bits(4 to 7) === B"0001"
  def isMUL  : Bool = bits(4 to 7) === B"0010"
  def isMAC  : Bool = bits(4 to 7) === B"0011"
  def isINT8 : Bool = bits(0 to 3) === B"0000"
  def isFP16 : Bool = bits(0 to 3) === B"1000"
  def isFP32 : Bool = bits(0 to 3) === B"1001"
  def isFP64 : Bool = bits(0 to 3) === B"1010"
  def isBF16 : Bool = bits(0 to 3) === B"1100"
  def isTF32 : Bool = bits(0 to 3) === B"1101"
}

object Mode_Test {
  def main(args: Array[String]): Unit = {
    // val fp32 = FP32(172.8000f)
    // val mode = Mode(ModeConfig.ADD_FP32)
    // println(mode.description)
    // println(mode.value)
    // println(mode.length)
  }
}