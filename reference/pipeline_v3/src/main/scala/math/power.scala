import scala.math.pow

object RichIntt {

  implicit class PowerInt(val i:Double) extends AnyVal {
    def ** (exp:Double):Double = pow(i,exp)
  }

  def main(args:Array[String])
  {
    println(5**6)
  }

}