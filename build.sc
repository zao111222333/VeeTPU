import mill._, scalalib._
import coursier.maven.MavenRepository

val spinalVersion = "1.6.1"

object veetpu extends SbtModule {
  def scalaVersion = "2.12.14"
  override def millSourcePath = os.pwd
  def ivyDeps = Agg(
    ivy"com.github.spinalhdl::spinalhdl-core:$spinalVersion",
    ivy"com.github.spinalhdl::spinalhdl-lib:$spinalVersion"
  )
  def scalacPluginIvyDeps = Agg(ivy"com.github.spinalhdl::spinalhdl-idsl-plugin:$spinalVersion")
}

trait veetpu extends SbtModule{
  def repositories() = super.repositories ++ Seq(
    MavenRepository("https://maven.aliyun.com/repository/public")
  )
}