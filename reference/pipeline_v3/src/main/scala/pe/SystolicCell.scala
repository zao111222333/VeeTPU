package pe

import spinal.core._
import spinal.lib._

class CellConfig (
  val size_X: Int,
  val size_W: Int,
  val n: Int,
  // "None" "Tradition" "MyDesign" "NewDesign"
  val pipelineType: String
  // 要考虑乘法的长度，若 pipelineLength=8, mutiLength=size_X+size_W=4
  // 则第一个adderLength=pipelineLength-mutiLength=4
  // 后面的adderLength=pipelineLength=8
  // val pipelineLength: Int =  size_X+size_W
){
  def ceil(m: Double) = java.lang.Math.ceil(m).toInt
  private def log2(m: Int) = java.lang.Math.log(m) / java.lang.Math.log(2)
  private val size_P = size_X+size_W
  private val size_Yin  = if(n==0) 0 else size_P + ceil(log2(n))
  private val size_Yout = size_P + ceil(log2(n+1))
  private val size_Yin_t  = if(n==0) 0 else if(size_Yin%size_P==0) size_P else size_Yin%size_P
  private val size_Yout_t = if(n==0||size_Yout%size_P==0) size_P else size_Yout%size_P
  private val length_Yin  = ceil(size_Yin /size_P.toDouble)
  private val length_Yout = ceil(size_Yout/size_P.toDouble)
  // 对外
  var sizeYin  = new Array[Int](length_Yin)
  var sizeYout = new Array[Int](length_Yout)
  for (i <- 0 to length_Yin-2) {
    sizeYin(i) = size_P
  }
  if (length_Yin!=0)  sizeYin(length_Yin-1) = size_Yin_t
  for (i <- 0 to length_Yout-2) {
    sizeYout(i) = size_P
  }
  sizeYout(length_Yout-1) = size_Yout_t
  override def toString() : String = {
    return "_" + size_X + "_" + size_W + "_" + n + "_" + pipelineType
  }
}

class SystolicCell(config: CellConfig) extends Component{  
  import config._
  private class MyReg(size: Int) extends Component{
    val io = new Bundle{
      val i = in  UInt(size bits)
      val o = out UInt(size bits)
    }
    val r = Reg(UInt(size bits)) init(0)
    r := io.i
    io.o := r
  }
  private class MyConnect(size: Int, isReg: Boolean) extends Component{
    val io = new Bundle{
      val i = in  UInt(size bits)
      val o = out UInt(size bits)
    }
    if (isReg) {
      val r = Reg(UInt(size bits)) init(0)
      r := io.i
      io.o := r
    } else {
      io.o := io.i
    }
  }
  private def getY(sizeY :Array[Int])  : Array[UInt] = {
    val array = new Array[UInt](sizeY.length)
    for (i <- 0 to sizeY.length-1) {
      array(i) = UInt(sizeY(i) bits)
    }
    return array
  }
  val io = new Bundle{
    val Xin  = in UInt(size_X bits)
    val Win  = in UInt(size_W bits)
    val Yin  = in Vec(getY(sizeYin))
    val Xout = out UInt(size_X bits)
    val Yout = out Vec(getY(sizeYout))      //result = a + b
  }
  val X = Reg(UInt(size_X bits)) init(0)
  val W = Reg(UInt(size_W bits)) init(0)
  X := io.Xin
  W := io.Win
  io.Xout := X
  // 乘法
  val arrayMultiplier = new ArrayMultiplier(size_X, size_W)
  arrayMultiplier.io.X := X
  arrayMultiplier.io.Y := W
  // 加法
  pipelineType match {
    case "MyDesign"  => {
      if (sizeYin.length != 0){
        var yinBuffer   = new Array[MyReg](sizeYin.length)
        var adderArray  = new Array[ArrayAdder](sizeYin.length)
        var bufferArray = new Array[MyReg](sizeYout.length)
        bufferArray(0) = new MyReg(size_W+size_X)
        bufferArray(0).io.i := arrayMultiplier.io.P
        for(i <- 0 to sizeYin.length-2){
          yinBuffer(i)   = new MyReg(sizeYin(i))
          adderArray(i)  = if(i==0) 
                              new ArrayAdder(sizeYin(i),size_W+size_X,sizeYout(i)) 
                            else 
                              new ArrayAdder(sizeYin(i),1,sizeYout(i))
          bufferArray(i+1) = new MyReg(1)
          yinBuffer(i).io.i := io.Yin(i)
          adderArray(i).io.A := yinBuffer(i).io.o
          adderArray(i).io.B := bufferArray(i).io.o
          bufferArray(i+1).io.i := adderArray(i).io.Cout.asUInt
          io.Yout(i) := adderArray(i).io.S
        }
        yinBuffer(sizeYin.length-1)   = new MyReg(sizeYin(sizeYin.length-1))
        adderArray(sizeYin.length-1)  = if (sizeYin.length-1==0) 
                                          new ArrayAdder(sizeYin(sizeYin.length-1),size_W+size_X,sizeYout(sizeYin.length-1)) 
                                        else 
                                          new ArrayAdder(sizeYin(sizeYin.length-1),1,sizeYout(sizeYin.length-1))
        yinBuffer(sizeYin.length-1).io.i := io.Yin(sizeYin.length-1)
        adderArray(sizeYin.length-1).io.A := yinBuffer(sizeYin.length-1).io.o
        adderArray(sizeYin.length-1).io.B := bufferArray(sizeYin.length-1).io.o
        io.Yout(sizeYin.length-1) := adderArray(sizeYin.length-1).io.S
        if (sizeYin.length+1 == sizeYout.length){
          bufferArray(sizeYin.length) = new MyReg(1)
          bufferArray(sizeYin.length).io.i := adderArray(sizeYin.length-1).io.Cout.asUInt
          io.Yout(sizeYin.length) := bufferArray(sizeYin.length).io.o
        }
      }else{
        io.Yout(0) := arrayMultiplier.io.P
      }
    }
    case "NewDesign"  => {
      if (sizeYin.length != 0){
        var state: Boolean = false
        val bufferLength:Int = sizeYout.length
        var yinBuffer   = new Array[MyReg](sizeYin.length)
        var adderArray  = new Array[ArrayAdder](sizeYin.length)
        var bufferArray = new Array[MyConnect](sizeYout.length)
        bufferArray(0) = new MyConnect(size_W+size_X,state)
        state = !state
        bufferArray(0).io.i := arrayMultiplier.io.P
        for(i <- 0 to sizeYin.length-2){
          yinBuffer(i)   = new MyReg(sizeYin(i))
          adderArray(i)  = if(i==0) 
                              new ArrayAdder(sizeYin(i),size_W+size_X,sizeYout(i)) 
                            else 
                              new ArrayAdder(sizeYin(i),1,sizeYout(i))
          bufferArray(i+1) = new MyConnect(1,state)
          state = !state
          yinBuffer(i).io.i := io.Yin(i)
          adderArray(i).io.A := yinBuffer(i).io.o
          adderArray(i).io.B := bufferArray(i).io.o
          bufferArray(i+1).io.i := adderArray(i).io.Cout.asUInt
          io.Yout(i) := adderArray(i).io.S
        }
        yinBuffer(sizeYin.length-1)   = new MyReg(sizeYin(sizeYin.length-1))
        adderArray(sizeYin.length-1)  = if (sizeYin.length-1==0) 
                                          new ArrayAdder(sizeYin(sizeYin.length-1),size_W+size_X,sizeYout(sizeYin.length-1)) 
                                        else 
                                          new ArrayAdder(sizeYin(sizeYin.length-1),1,sizeYout(sizeYin.length-1))
        yinBuffer(sizeYin.length-1).io.i := io.Yin(sizeYin.length-1)
        adderArray(sizeYin.length-1).io.A := yinBuffer(sizeYin.length-1).io.o
        adderArray(sizeYin.length-1).io.B := bufferArray(sizeYin.length-1).io.o
        io.Yout(sizeYin.length-1) := adderArray(sizeYin.length-1).io.S
        if (sizeYin.length+1 == sizeYout.length){
          bufferArray(sizeYin.length) = new MyConnect(1,state)
          state = !state
          bufferArray(sizeYin.length).io.i := adderArray(sizeYin.length-1).io.Cout.asUInt
          io.Yout(sizeYin.length) := bufferArray(sizeYin.length).io.o
        }
      }else{
        io.Yout(0) := arrayMultiplier.io.P
      }
    }

 
    case "Tradition"  => {
    }

    case "None"  => {
      if (sizeYin.length != 0){
        var yinBuffer   = new Array[MyReg](sizeYin.length)
        var adderArray  = new Array[ArrayAdder](sizeYin.length)
        for(i <- 0 to sizeYin.length-2){
          yinBuffer(i)   = new MyReg(sizeYin(i))
          adderArray(i)  = if(i==0) 
                              new ArrayAdder(sizeYin(i),size_W+size_X,sizeYout(i)) 
                            else 
                              new ArrayAdder(sizeYin(i),1,sizeYout(i))
          yinBuffer(i).io.i := io.Yin(i)
          adderArray(i).io.A := yinBuffer(i).io.o
          adderArray(i).io.B := {if(i==0)
                                  arrayMultiplier.io.P
                                else
                                  adderArray(i-1).io.Cout.asUInt}
          io.Yout(i) := adderArray(i).io.S
        }
        yinBuffer(sizeYin.length-1)   = new MyReg(sizeYin(sizeYin.length-1))
        adderArray(sizeYin.length-1)  = if (sizeYin.length-1==0) 
                                          new ArrayAdder(sizeYin(sizeYin.length-1),size_W+size_X,sizeYout(sizeYin.length-1)) 
                                        else 
                                          new ArrayAdder(sizeYin(sizeYin.length-1),1,sizeYout(sizeYin.length-1))
        yinBuffer(sizeYin.length-1).io.i := io.Yin(sizeYin.length-1)
        adderArray(sizeYin.length-1).io.A := yinBuffer(sizeYin.length-1).io.o
        adderArray(sizeYin.length-1).io.B := {if(sizeYin.length-1==0)
                                                arrayMultiplier.io.P
                                              else
                                                adderArray(sizeYin.length-2).io.Cout.asUInt}
        io.Yout(sizeYin.length-1) := adderArray(sizeYin.length-1).io.S
        if (sizeYin.length+1 == sizeYout.length){
          io.Yout(sizeYin.length) := adderArray(sizeYin.length-1).io.Cout.asUInt
        }
      }else{
        io.Yout(0) := arrayMultiplier.io.P
      }
    }
    case _  => println("Invalid type")
  }
}

// sbt "runMain pe.SystolicCellVerilog"
object SystolicCellVerilog {
  def main(args: Array[String]) {
    val config = new CellConfig(
        size_X = 2,
        size_W = 2,
        n      = 255,
        pipelineType = "NewDesign"
      )
    val path = "simWorkspace/SystolicCell"+config+"/rtl"
    java.nio.file.Files.createDirectories(java.nio.file.Paths.get(path))
    SpinalConfig(
      mode=Verilog,
      targetDirectory=path
    ).generate(new SystolicCell(config))
  }
}