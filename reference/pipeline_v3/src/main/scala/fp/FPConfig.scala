package FP

import spinal.core._
import spinal.lib._

case class FPConfig(
  exponentSize  : Int,
  mantissaSize  : Int
)

class FP(config: FPConfig) extends Bundle{
  val sign     = Bits(1 bit)
  val exponent = Bits(config.exponentSize bit)
  val mantissa = Bits(config.mantissaSize bit)
  def fromBits(data: Bits) {
    this.sign     := data(0 to 0)
    this.exponent := data(1 to config.exponentSize)
    this.mantissa := data(config.exponentSize+1 to config.exponentSize+config.mantissaSize)
  }
  override def asBits() : Bits = {
    val bits : Bits = this.sign ## this.exponent ## this.mantissa
    return bits
  }
}