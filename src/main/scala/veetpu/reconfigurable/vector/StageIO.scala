package veetpu.reconfigurable.vector

import spinal.core._
import spinal.lib._


/* --------------------------------                             -------------------------------- *\
** --------------------------------    ____    _____   _        -------------------------------- **
** --------------------------------   |  _ \  |_   _| | |       -------------------------------- **
** --------------------------------   | |_) |   | |   | |       -------------------------------- **
** --------------------------------   |  _ <    | |   | |___    -------------------------------- **
** --------------------------------   |_| \_\   |_|   |_____|   -------------------------------- **
\* --------------------------------                             -------------------------------- */


class StageIO() extends Component{

  val ctl = new Bundle{
    val i = new Bundle{
      val mode = in (Mode())
    }
    val o = new Bundle{
      val mode = out (Mode())
    }
  }

  val io = new Bundle{
    val i = new Bundle{
      val sign = new Bundle{
        val mul = new Bundle{
          val BF16 = in Vec(Vec(Bool(), 16), 4)
          val FP16 = in Vec(Vec(Bool(), 16), 4)
          val FP32 = in Vec(Vec(Bool(),  8), 2)
          val TF32 = in Vec(Vec(Bool(),  8), 2)
          val FP64 = in Vec(Vec(Bool(),  4), 1)
        }
        val mac = new Bundle{
          val BF16 = in Vec(Vec(Bool(), 1), 4)
          val FP16 = in Vec(Vec(Bool(), 1), 4)
          val FP32 = in Vec(Vec(Bool(), 1), 2)
          val TF32 = in Vec(Vec(Bool(), 1), 2)
          val FP64 = in Vec(Vec(Bool(), 1), 1)
        }
        val add = new Bundle{
          val BF16 = in Vec(Vec(Bool(), 1), 4)
          val FP16 = in Vec(Vec(Bool(), 1), 4)
          val FP32 = in Vec(Vec(Bool(), 1), 2)
          val TF32 = in Vec(Vec(Bool(), 1), 2)
          val FP64 = in Vec(Vec(Bool(), 1), 1)
        }
      }
      val exp = new Bundle{
        val max = new Bundle{
          val BF16 = in Vec(UInt( 7+1 bits), 4)
          val FP16 = in Vec(UInt( 5+1 bits), 4)
          val FP32 = in Vec(UInt( 8+1 bits), 2)
          val TF32 = in Vec(UInt( 8+1 bits), 2)
          val FP64 = in Vec(UInt(11+1 bits), 1)
        }
        val diff = new Bundle{
          val mul = new Bundle{
            val BF16 = in Vec(Vec(UInt( 7+1 bits), 16), 4)
            val FP16 = in Vec(Vec(UInt( 5+1 bits), 16), 4)
            val FP32 = in Vec(Vec(UInt( 8+1 bits),  8), 2)
            val TF32 = in Vec(Vec(UInt( 8+1 bits),  8), 2)
            val FP64 = in Vec(Vec(UInt(11+1 bits),  4), 1)
          }
          val mac = new Bundle{
            val BF16 = in Vec(Vec(UInt( 7+1 bits), 1), 4)
            val FP16 = in Vec(Vec(UInt( 5+1 bits), 1), 4)
            val FP32 = in Vec(Vec(UInt( 8+1 bits), 1), 2)
            val TF32 = in Vec(Vec(UInt( 8+1 bits), 1), 2)
            val FP64 = in Vec(Vec(UInt(11+1 bits), 1), 1)
          }
          val add = new Bundle{
            val BF16 = in Vec(Vec(UInt( 7+1 bits), 1), 4)
            val FP16 = in Vec(Vec(UInt( 5+1 bits), 1), 4)
            val FP32 = in Vec(Vec(UInt( 8+1 bits), 1), 2)
            val TF32 = in Vec(Vec(UInt( 8+1 bits), 1), 2)
            val FP64 = in Vec(Vec(UInt(11+1 bits), 1), 1)
          }
        }
      }
      val mant = new Bundle{
        val INT8 = in Vec(Vec(SInt( 8*2+1 bits), 16), 4)
        val BF16 = in Vec(Vec(UInt( 8*2   bits), 16), 4)
        val FP16 = in Vec(Vec(UInt(11*2   bits), 16), 4)
        val FP32 = in Vec(Vec(UInt(24*2   bits),  4), 4)
        val TF32 = in Vec(Vec(UInt(11*2   bits),  4), 4)
        val FP64 = in Vec(Vec(UInt(53*2   bits),  1), 4)
      }
    }
    val o = new Bundle{
      val sign = new Bundle{
        val mul = new Bundle{
          val BF16 = out Vec(Vec(Bool(), 16), 4)
          val FP16 = out Vec(Vec(Bool(), 16), 4)
          val FP32 = out Vec(Vec(Bool(),  8), 2)
          val TF32 = out Vec(Vec(Bool(),  8), 2)
          val FP64 = out Vec(Vec(Bool(),  4), 1)
        }
        val mac = new Bundle{
          val BF16 = out Vec(Vec(Bool(), 1), 4)
          val FP16 = out Vec(Vec(Bool(), 1), 4)
          val FP32 = out Vec(Vec(Bool(), 1), 2)
          val TF32 = out Vec(Vec(Bool(), 1), 2)
          val FP64 = out Vec(Vec(Bool(), 1), 1)
        }
        val add = new Bundle{
          val BF16 = out Vec(Vec(Bool(), 1), 4)
          val FP16 = out Vec(Vec(Bool(), 1), 4)
          val FP32 = out Vec(Vec(Bool(), 1), 2)
          val TF32 = out Vec(Vec(Bool(), 1), 2)
          val FP64 = out Vec(Vec(Bool(), 1), 1)
        }
      }
      val exp = new Bundle{
        val max = new Bundle{
          val BF16 = out Vec(UInt( 7+1 bits), 4)
          val FP16 = out Vec(UInt( 5+1 bits), 4)
          val FP32 = out Vec(UInt( 8+1 bits), 2)
          val TF32 = out Vec(UInt( 8+1 bits), 2)
          val FP64 = out Vec(UInt(11+1 bits), 1)
        }
        val diff = new Bundle{
          val mul = new Bundle{
            val BF16 = out Vec(Vec(UInt( 7+1 bits), 16), 4)
            val FP16 = out Vec(Vec(UInt( 5+1 bits), 16), 4)
            val FP32 = out Vec(Vec(UInt( 8+1 bits),  8), 2)
            val TF32 = out Vec(Vec(UInt( 8+1 bits),  8), 2)
            val FP64 = out Vec(Vec(UInt(11+1 bits),  4), 1)
          }
          val mac = new Bundle{
            val BF16 = out Vec(Vec(UInt( 7+1 bits), 1), 4)
            val FP16 = out Vec(Vec(UInt( 5+1 bits), 1), 4)
            val FP32 = out Vec(Vec(UInt( 8+1 bits), 1), 2)
            val TF32 = out Vec(Vec(UInt( 8+1 bits), 1), 2)
            val FP64 = out Vec(Vec(UInt(11+1 bits), 1), 1)
          }
          val add = new Bundle{
            val BF16 = out Vec(Vec(UInt( 7+1 bits), 1), 4)
            val FP16 = out Vec(Vec(UInt( 5+1 bits), 1), 4)
            val FP32 = out Vec(Vec(UInt( 8+1 bits), 1), 2)
            val TF32 = out Vec(Vec(UInt( 8+1 bits), 1), 2)
            val FP64 = out Vec(Vec(UInt(11+1 bits), 1), 1)
          }
        }
      }
      val mant = new Bundle{
        val INT8 = out Vec(Vec(SInt( 8*2+1 bits), 16), 4)
        val BF16 = out Vec(Vec(UInt( 8*2   bits), 16), 4)
        val FP16 = out Vec(Vec(UInt(11*2   bits), 16), 4)
        val FP32 = out Vec(Vec(UInt(24*2   bits),  4), 4)
        val TF32 = out Vec(Vec(UInt(11*2   bits),  4), 4)
        val FP64 = out Vec(Vec(UInt(53*2   bits),  1), 4)
      }
    }
  }
  noIoPrefix()

}
object StageIO_Verilog {
  def main(args: Array[String]): Unit = {
    val path = "simWorkspace/StageIO/rtl"
    java.nio.file.Files.createDirectories(java.nio.file.Paths.get(path))
    val report = SpinalConfig(
      mode=Verilog,
      targetDirectory=path
    ).generate(new StageIO())
    report.mergeRTLSource(path+"/mergeRTL") // Merge all rtl sources into mergeRTL.vhd and mergeRTL.v files
  }
}

/* ----------------------------                                    ----------------------------- *\
** ----------------------------   __     __        _  __           ----------------------------- **
** ----------------------------   \ \   / /__ _ __(_)/ _|_   _     ----------------------------- **
** ----------------------------    \ \ / / _ \ '__| | |_| | | |    ----------------------------- **
** ----------------------------     \ V /  __/ |  | |  _| |_| |    ----------------------------- **
** ----------------------------      \_/ \___|_|  |_|_|  \__, |    ----------------------------- **
\* ----------------------------                          |___/     ----------------------------- */
