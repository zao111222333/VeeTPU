

[[1] " An in-depth look at Google’s firstTensor Processing Unit (TPU) "](https://cloud.google.com/blog/products/ai-machine-learning/an-in-depth-look-at-googles-first-tensor-processing-unit-tpu)

[[2] "In-Datacenter Performance Analysis of a Tensor Processing Unit"](https://dl.acm.org/doi/pdf/10.1145/3079856.3080246)

[[3] "脉动阵列在二维矩阵乘法及卷积运算中的应用"](https://blog.csdn.net/anntang18/article/details/77718531)

[[4] "脉动阵列 - 因Google TPU获得新生"](https://zhuanlan.zhihu.com/p/26522315)

[[5] "Efficient Processing of Deep Neural Networks: A Tutorial and Survey"](https://arxiv.org/pdf/1703.09039.pdf)

[[6] "Should We All Embrace Systolic Arrays?"](https://www.linkedin.com/pulse/should-we-all-embrace-systolic-arrays-chien-ping-lu)

[[7] Automated Systolic Array Architecture Synthesis for High Throughput CNN Inference on FPGAs](https://vast.cs.ucla.edu/publications/automated-systolic-array-architecture-synthesis-high-throughput-cnn-inference-fpgas)

[[8] "深度學習加速器：Architecture and Energy Efficiency"](https://allenlu2007.wordpress.com/2019/05/12/%E6%B7%B1%E5%BA%A6%E5%AD%B8%E7%BF%92%E5%8A%A0%E9%80%9F%E5%99%A8%EF%BC%9Aarchitecture-and-energy-efficiency/)



    For an MXU, however, matrix multiplication reuses both inputs many times as part of producing the output. We can read each input value once, but use it for many different operations without storing it back to a register. Wires only connect spatially adjacent ALUs, which makes them short and energy-efficient. The ALUs perform only multiplications and additions in fixed patterns, which simplifies their design.
    
![image](https://storage.googleapis.com/gweb-cloudblog-publish/original_images/Systolic_Array_for_Neural_Network_1pkw3.GIF)

Multiplying an input vector by a weight matrix with a systolic array


    The design is called systolic because the data flows through the chip in waves, reminiscent of the way that the heart pumps blood. The particular kind of systolic array in the MXU is optimized for power and area efficiency in performing matrix multiplications, and is not well suited for general-purpose computation. It makes an engineering tradeoff: limiting registers, control and operational flexibility in exchange for efficiency and much higher operation density.

![image](https://storage.googleapis.com/gweb-cloudblog-publish/original_images/Systolic_Array_for_Neural_Network_2g8b7.GIF)

Multiplying an input matrix by a weight matrix with a systolic array

    The TPU Matrix Multiplication Unit has a systolic array mechanism that contains 256 × 256 = total 65,536 ALUs. That means a TPU can process 65,536 multiply-and-adds for 8-bit integers every cycle. Because a TPU runs at 700MHz, a TPU can compute 65,536 × 700,000,000 = 46 × 1012 multiply-and-add operations or 92 Teraops per second (92 × 1012) in the matrix unit.
    
    所以请看google的另外一篇专利【Prefetching weights for use in a neural network processor】，里面详细说明了weight怎么流转的。其实google 加载weight是单独的一步操作，将weight加载到相应的cell中，再将feature map 从左侧依次流入脉动矩阵。
    
<img width="500" alt="Matrix Multiplier Unit (MXU) of TPU" src="https://storage.googleapis.com/gweb-cloudblog-publish/images/tpu-131a5h.max-1000x1000.PNG">

Matrix Multiplier Unit (MXU) of TPU



    具体，TPU怎么计算卷积的过程细节在TPU的论文[4]中没有提及，我也只能从Google几个专利中窥见一斑。这里提一句，Google卷积神经网络处理器的几个专利分别是：
    [Ros15b] Computing Convolutions Using a Neural NetworkProcessor. Patent Application NO.62/164,902, US20160342889A1, WO2016186811A1
    [Ros15d] Rotating Data for Neural NetworkComputation.
    Patent Application NO.62/164,908,US20160342893, WO2016186826A1
    其中[Ros15d]讲的更仔细一点。我下面说的也是基于[Ros15d]中的内容的个人理解

    在专利中，给出了一个cell的结构。cell中包含一个activation（input）寄存器，放activationinput的值。activation寄存器可以从左边的cell单元或者unifiedbuffer中获得数据，这个取决于这个cell在脉动阵列中的位置。cell中还有一个用来放weight的寄存器。同样，根据cell在脉动阵列中位置，weight数据的来源可以是上方的cell单元或者weightfetch interface。剩余的就是一个乘法电路和求和电路。求和电路将乘法得到的乘积和sum in register中的数加起来。在专利中，还提到了一点，这个在图中没有画出来，cell还包含一个controlregister。这个寄存器存的是一个控制信号，决定是否把当前的weight或者activation的是否传递到临近的cell中。
    
![image](https://user-images.githubusercontent.com/57790433/111885046-58d63b00-8a00-11eb-8006-ecc24c2d2735.png)

[source](https://zhuanlan.zhihu.com/p/26522315)
    
    虽然，从cell的结构看，weight、input、sum都可以传播，但是在真正计算中，这三者的传播并不是同时流动。根据专利中所述，weight是提前先被放在weight register上的，并且会保持多个周期不进行传递，直至需要更新weight的时候，weight才会进行传递。在计算中，主要传递的是activation和partial sum。
    “The weight register 502can statically store the weight input such that as activation inputs aretransferred to the cell, e.g., through the activation register, over multipleclock cycles, the weight input remains within the cell and is transferred to anadjacent cell. Therefore, the weight input can be applied to multipleactivation inputs, e.g., using the multiplication circuitry, and respective accumulatedvalues can be transferred to an adjacent cell.”

![image](https://user-images.githubusercontent.com/57790433/111886331-f4b77500-8a07-11eb-8eb6-8206b17938b6.png)

    脉动阵列中的一个cell也非常简单。几组寄存器分别存储weight，activation和来自上方cell的部分和。weight从上向下传播，可以在weight path register中存储，保持不动或者传输给weight register进行运算。weight register可以把数据发到乘法器进行处理，也可以直接传递给下方的cell；同样activation register也可以把数据发到乘法器进行处理，或者直接传递给右侧的cell。乘法器的输出和Sum in register的数值求和并传递给下方的cell。所有运算和传递都由控制寄存器控制（通过指令决定）。That’s it。

![image](https://user-images.githubusercontent.com/57790433/111886414-44963c00-8a08-11eb-8235-c0f7e06bcbfd.png)


    那么，在这样一个大规模的脉动阵列中怎么实现卷积操作呢？在Google的专利中有这样一个例子，可以看出一些端倪。如下图所示，activation输入被转换成一定的向量形式，作为脉动阵列的行输入。而3x3卷积核（Kernel）经过旋转，变成9个矩阵分别输入到脉动阵列的9个列。第一列计算的是卷积核和activation矩阵左上角的9个数据的卷积，得到输出矩阵的左上角的第一个数据，依此类推。

![image](https://user-images.githubusercontent.com/57790433/111886536-457b9d80-8a09-11eb-88e2-e74072f3378f.png)


    另外，在2017DAC会议上也有一篇利用脉动阵列来加速卷积神经网络的Inference [5]。大致浏览了一下，硬件的结构基本上与其他的脉动阵列式类似的。在下面这张图中，WB（Weight Buffer），IB（Input Buffer），OB（Output Buffer），在进行计算时，脉动阵列中Weight和Input分别向右、向下传播。在Buffer之间WB之间可由上向下传播参数，在IB之间可由左至右传播参数。最后计算的结果由PE一级级向上传至OB（图中的实线路径）。在PE中，一个乘加器，其他的都是为了缓存数据的寄存器或者进行数据选择的MUX。在Buffer的设计中，论文的作者使用了double buffering，因为每个buffer都会进行两个方向的传播，double buffering的方法是其能pipeline起来。
    
![image](https://user-images.githubusercontent.com/57790433/111886688-98098980-8a0a-11eb-8676-1330a200c9ef.png)

    The first statement seems to indicate 256-by-256 and 512-by-512 units are at the plateau section of the speedup curve. The second statement implies 128-by-128 might be at the plateau. It indicates a possibility that given the on-chip buffer size and memory bandwidth, Google could have designed TPU with a 128-by-128 or smaller unit without significant performance loss, except for compute-bound applications. Such a wide performance plateau from 128-by-128 to 512-by-512 (a factor of 16) could be due to an unbalanced design and/or fundamental limitations of systolic arrays. Being the first successfully deployed implementation of systolic array, the TPU might help us identify issues.


## Reuse 

### (a) No Local Reuse (NLR) Architecture
如果沿著上圖 2D systolic array 的縱切面 (one column)，可以分為三類。第一類是沒有 weight or pixel local (PE/RF) reuse.  稱為 NLR.
Dataflow: weight 和 pixel 流入 (no broadcast) PEs, Psum: Buffer->PE, PE->PE, PE-> Buffer
每一次 Psum 都要 update weight and pixel, 更多的功耗!
Pixel:  Input features
Psum: Output features

### (b) Weight Stationary (WS) Architecture
第二類是 weight stationary, maximize weight reuse, 儘量減少 weight read buffer energy. 

如何 maximize weight resue, 就是把 weight 固定在 PE/RF 儘量不要 update weight.

此時 dataflow 就是 Pixels 流入 (broadcast) PEs，Psum : Buffer->PE, PE->PE, PE->Buffer.



### (c) Output Stationary (OS) Architecture
第三類是 output stationary.

就是把 Psum 固定在 PE/RF, 只作 local update (accumulation).  儘量減少 Psum R/W buffer. 

此時 dataflow 就是 Weight 流入 (broadcast) PEs，Pixel : Buffer->PE, PE->PE
