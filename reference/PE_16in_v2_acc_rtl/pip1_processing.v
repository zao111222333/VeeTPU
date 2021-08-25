module pip1_processing (
    input         clk             ,
    input         rstn            ,
    input  [ 1:0] mode_sel_pip0   , //mode sel input
    input  [15:0] i_sign_AB      , //sign AB of fp16 and fp32; 
    input         i_sign_AB_fp64 , //sign AB for FP64
    input  [11:0] i_exp_AB_fp64  , //exp AB for FP64
    input  [ 9:0] i_exp_AB0      , //exp AB for FP64,FP32,FP16
    input  [ 9:0] i_exp_AB1      , //exp AB for FP64,FP32,FP16
    input  [ 9:0] i_exp_AB2      , //exp AB for FP64,FP32,FP16
    input  [ 9:0] i_exp_AB3      , //exp AB for FP64,FP32,FP16
    input  [ 9:0] i_exp_AB4      , //exp AB for FP64,FP32,FP16
    input  [ 9:0] i_exp_AB5      , //exp AB for FP64,FP32,FP16
    input  [ 9:0] i_exp_AB6      , //exp AB for FP64,FP32,FP16
    input  [ 9:0] i_exp_AB7      , //exp AB for FP64,FP32,FP16
    input  [ 9:0] i_exp_AB8      , //exp AB for FP64,FP32,FP16
    input  [ 9:0] i_exp_AB9      , //exp AB for FP64,FP32,FP16
    input  [ 9:0] i_exp_ABA      , //exp AB for FP64,FP32,FP16
    input  [ 9:0] i_exp_ABB      , //exp AB for FP64,FP32,FP16
    input  [ 9:0] i_exp_ABC      , //exp AB for FP64,FP32,FP16
    input  [ 9:0] i_exp_ABD      , //exp AB for FP64,FP32,FP16
    input  [ 9:0] i_exp_ABE      , //exp AB for FP64,FP32,FP16
    input  [ 9:0] i_exp_ABF      , //exp AB for FP64,FP32,FP16
    input  [12:0] i_man_A0      , //mantisa A for FP64,FP32,FP16
    input  [12:0] i_man_A1      , //mantisa A for FP64,FP32,FP16
    input  [12:0] i_man_A2      , //mantisa A for FP64,FP32,FP16
    input  [12:0] i_man_A3      , //mantisa A for FP64,FP32,FP16
    input  [12:0] i_man_A4      , //mantisa A for FP64,FP32,FP16
    input  [12:0] i_man_A5      , //mantisa A for FP64,FP32,FP16
    input  [12:0] i_man_A6      , //mantisa A for FP64,FP32,FP16
    input  [12:0] i_man_A7      , //mantisa A for FP64,FP32,FP16
    input  [12:0] i_man_A8      , //mantisa A for FP64,FP32,FP16
    input  [12:0] i_man_A9      , //mantisa A for FP64,FP32,FP16
    input  [12:0] i_man_AA      , //mantisa A for FP64,FP32,FP16
    input  [12:0] i_man_AB      , //mantisa A for FP64,FP32,FP16
    input  [12:0] i_man_AC      , //mantisa A for FP64,FP32,FP16
    input  [12:0] i_man_AD      , //mantisa A for FP64,FP32,FP16
    input  [12:0] i_man_AE      , //mantisa A for FP64,FP32,FP16
    input  [12:0] i_man_AF      , //mantisa A for FP64,FP32,FP16
    input         i_fp64_imbitA , 
    input  [12:0] i_man_B0      , //mantisa B for FP64,FP32,FP16
    input  [12:0] i_man_B1      , //mantisa B for FP64,FP32,FP16
    input  [12:0] i_man_B2      , //mantisa B for FP64,FP32,FP16
    input  [12:0] i_man_B3      , //mantisa B for FP64,FP32,FP16
    input  [12:0] i_man_B4      , //mantisa B for FP64,FP32,FP16
    input  [12:0] i_man_B5      , //mantisa B for FP64,FP32,FP16
    input  [12:0] i_man_B6      , //mantisa B for FP64,FP32,FP16
    input  [12:0] i_man_B7      , //mantisa B for FP64,FP32,FP16
    input  [12:0] i_man_B8      , //mantisa B for FP64,FP32,FP16
    input  [12:0] i_man_B9      , //mantisa B for FP64,FP32,FP16
    input  [12:0] i_man_BA      , //mantisa B for FP64,FP32,FP16
    input  [12:0] i_man_BB      , //mantisa B for FP64,FP32,FP16
    input  [12:0] i_man_BC      , //mantisa B for FP64,FP32,FP16
    input  [12:0] i_man_BD      , //mantisa B for FP64,FP32,FP16
    input  [12:0] i_man_BE      , //mantisa B for FP64,FP32,FP16
    input  [12:0] i_man_BF      , //mantisa B for FP64,FP32,FP16
    input         i_fp64_imbitB , 
    output reg [ 1:0] mode_sel_pip1 ,
    output reg [15:0] o_sign_AB     ,
    output reg        o_sign_AB_fp64,
    output reg [11:0] o_exp_AB_fp64 ,
    output reg [ 9:0] o_exp_max     ,
    output reg [ 9:0] o_shift0      ,
    output reg [ 9:0] o_shift1      ,
    output reg [ 9:0] o_shift2      ,
    output reg [ 9:0] o_shift3      ,
    output reg [ 9:0] o_shift4      ,
    output reg [ 9:0] o_shift5      ,
    output reg [ 9:0] o_shift6      ,
    output reg [ 9:0] o_shift7      ,
    output reg [ 9:0] o_shift8      ,
    output reg [ 9:0] o_shift9      ,
    output reg [ 9:0] o_shiftA      ,
    output reg [ 9:0] o_shiftB      ,
    output reg [ 9:0] o_shiftC      ,
    output reg [ 9:0] o_shiftD      ,
    output reg [ 9:0] o_shiftE      ,
    output reg [ 9:0] o_shiftF      ,
    output reg [25:0] o_man_AB0     ,
    output reg [25:0] o_man_AB1     ,
    output reg [25:0] o_man_AB2     ,
    output reg [25:0] o_man_AB3     ,
    output reg [25:0] o_man_AB4     ,
    output reg [25:0] o_man_AB5     ,
    output reg [25:0] o_man_AB6     ,
    output reg [25:0] o_man_AB7     ,
    output reg [25:0] o_man_AB8     ,
    output reg [25:0] o_man_AB9     ,
    output reg [25:0] o_man_ABA     ,
    output reg [25:0] o_man_ABB     ,
    output reg [25:0] o_man_ABC     ,
    output reg [25:0] o_man_ABD     ,
    output reg [25:0] o_man_ABE     ,
    output reg [25:0] o_man_ABF     ,
    output reg [52:0] o_man_A_53b   , 
    output reg [52:0] o_man_B_53b   
);
//clock count output
always@(posedge clk or negedge rstn)begin
    if(!rstn)begin
        mode_sel_pip1<= 2'b11;
    end
    else begin
        mode_sel_pip1<= mode_sel_pip0;
    end
end

//sign processing
always@(posedge clk)begin
    o_sign_AB <= i_sign_AB;
    o_sign_AB_fp64 <= i_sign_AB_fp64;
end

//exp copmare
 
wire [9:0] oexp_max ;
wire [9:0] oshift_00;
wire [9:0] oshift_01;
wire [9:0] oshift_02;
wire [9:0] oshift_03;
wire [9:0] oshift_04;
wire [9:0] oshift_05;
wire [9:0] oshift_06;
wire [9:0] oshift_07;
wire [9:0] oshift_08;
wire [9:0] oshift_09;
wire [9:0] oshift_10;
wire [9:0] oshift_11;
wire [9:0] oshift_12;
wire [9:0] oshift_13;
wire [9:0] oshift_14;
wire [9:0] oshift_15;

exp_compare_16in #(10)u_exp_compare(
        .iexp_00(i_exp_AB0),
	.iexp_01(i_exp_AB1),
	.iexp_02(i_exp_AB2),
	.iexp_03(i_exp_AB3),
	.iexp_04(i_exp_AB4),
	.iexp_05(i_exp_AB5),
	.iexp_06(i_exp_AB6),
	.iexp_07(i_exp_AB7),
	.iexp_08(i_exp_AB8),
	.iexp_09(i_exp_AB9),
	.iexp_10(i_exp_ABA),
	.iexp_11(i_exp_ABB),
	.iexp_12(i_exp_ABC),
	.iexp_13(i_exp_ABD),
	.iexp_14(i_exp_ABE),
	.iexp_15(i_exp_ABF),
	.oexp_max(oexp_max),
	.oshift_00(oshift_00),
	.oshift_01(oshift_01),
	.oshift_02(oshift_02),
	.oshift_03(oshift_03),
	.oshift_04(oshift_04),
	.oshift_05(oshift_05),
	.oshift_06(oshift_06),
	.oshift_07(oshift_07),
	.oshift_08(oshift_08),
	.oshift_09(oshift_09),
	.oshift_10(oshift_10),
	.oshift_11(oshift_11),
	.oshift_12(oshift_12),
	.oshift_13(oshift_13),
	.oshift_14(oshift_14),
	.oshift_15(oshift_15)
	);

always@(posedge clk)begin
    o_exp_AB_fp64 <= i_exp_AB_fp64 ; //fp64 output
    o_exp_max     <= oexp_max ;
    o_shift0      <= oshift_00;
    o_shift1      <= oshift_01;
    o_shift2      <= oshift_02;
    o_shift3      <= oshift_03;
    o_shift4      <= oshift_04;
    o_shift5      <= oshift_05;
    o_shift6      <= oshift_06;
    o_shift7      <= oshift_07;
    o_shift8      <= oshift_08;
    o_shift9      <= oshift_09;
    o_shiftA      <= oshift_10;
    o_shiftB      <= oshift_11;
    o_shiftC      <= oshift_12;
    o_shiftD      <= oshift_13;
    o_shiftE      <= oshift_14;
    o_shiftF      <= oshift_15;
end

//mul array
wire [25:0] oman_AB0;     
wire [25:0] oman_AB1;     
wire [25:0] oman_AB2;     
wire [25:0] oman_AB3;     
wire [25:0] oman_AB4;     
wire [25:0] oman_AB5;     
wire [25:0] oman_AB6;     
wire [25:0] oman_AB7;     
wire [25:0] oman_AB8;     
wire [25:0] oman_AB9;     
wire [25:0] oman_ABA;     
wire [25:0] oman_ABB;     
wire [25:0] oman_ABC;     
wire [25:0] oman_ABD;     
wire [25:0] oman_ABE;     
wire [25:0] oman_ABF;     

mul_array #(13) u_mul_array(
    .i_man_A00     (i_man_A0     ), 
    .i_man_A01     (i_man_A1     ), 
    .i_man_A02     (i_man_A2     ),  
    .i_man_A03     (i_man_A3     ),  
    .i_man_A04     (i_man_A4     ),  
    .i_man_A05     (i_man_A5     ),  
    .i_man_A06     (i_man_A6     ),  
    .i_man_A07     (i_man_A7     ),  
    .i_man_A08     (i_man_A8     ),  
    .i_man_A09     (i_man_A9     ),  
    .i_man_A10     (i_man_AA     ),  
    .i_man_A11     (i_man_AB     ),  
    .i_man_A12     (i_man_AC     ),  
    .i_man_A13     (i_man_AD     ),  
    .i_man_A14     (i_man_AE     ),  
    .i_man_A15     (i_man_AF     ),  
    .i_man_B00     (i_man_B0     ),  
    .i_man_B01     (i_man_B1     ),  
    .i_man_B02     (i_man_B2     ),  
    .i_man_B03     (i_man_B3     ),  
    .i_man_B04     (i_man_B4     ),  
    .i_man_B05     (i_man_B5     ),  
    .i_man_B06     (i_man_B6     ),  
    .i_man_B07     (i_man_B7     ),  
    .i_man_B08     (i_man_B8     ),  
    .i_man_B09     (i_man_B9     ),  
    .i_man_B10     (i_man_BA     ),  
    .i_man_B11     (i_man_BB     ),  
    .i_man_B12     (i_man_BC     ),  
    .i_man_B13     (i_man_BD     ),  
    .i_man_B14     (i_man_BE     ),  
    .i_man_B15     (i_man_BF     ), 
    .oman_AB00     (oman_AB0     ), 
    .oman_AB01     (oman_AB1     ), 
    .oman_AB02     (oman_AB2     ), 
    .oman_AB03     (oman_AB3     ), 
    .oman_AB04     (oman_AB4     ), 
    .oman_AB05     (oman_AB5     ), 
    .oman_AB06     (oman_AB6     ), 
    .oman_AB07     (oman_AB7     ), 
    .oman_AB08     (oman_AB8     ), 
    .oman_AB09     (oman_AB9     ), 
    .oman_AB10     (oman_ABA     ), 
    .oman_AB11     (oman_ABB     ), 
    .oman_AB12     (oman_ABC     ),
    .oman_AB13     (oman_ABD     ), 
    .oman_AB14     (oman_ABE     ), 
    .oman_AB15     (oman_ABF     ) 
);
wire [26:0] inv_man_AB0;
wire [26:0] inv_man_AB1;
wire [26:0] inv_man_AB2;
wire [26:0] inv_man_AB3;
wire [26:0] inv_man_AB4;
wire [26:0] inv_man_AB5;
wire [26:0] inv_man_AB6;
wire [26:0] inv_man_AB7;
wire [26:0] inv_man_AB8;
wire [26:0] inv_man_AB9;
wire [26:0] inv_man_ABA;
wire [26:0] inv_man_ABB;
wire [26:0] inv_man_ABC;
wire [26:0] inv_man_ABD;
wire [26:0] inv_man_ABE;
wire [26:0] inv_man_ABF;
/*
assign inv_man_AB0 = ~oman_AB0+1'b1;
assign inv_man_AB1 = ~oman_AB1+1'b1;
assign inv_man_AB2 = ~oman_AB2+1'b1;
assign inv_man_AB3 = ~oman_AB3+1'b1;
assign inv_man_AB4 = ~oman_AB4+1'b1;
assign inv_man_AB5 = ~oman_AB5+1'b1;
assign inv_man_AB6 = ~oman_AB6+1'b1;
assign inv_man_AB7 = ~oman_AB7+1'b1;
assign inv_man_AB8 = ~oman_AB8+1'b1;
assign inv_man_AB9 = ~oman_AB9+1'b1;
assign inv_man_ABA = ~oman_ABA+1'b1;
assign inv_man_ABB = ~oman_ABB+1'b1;
assign inv_man_ABC = ~oman_ABC+1'b1;
assign inv_man_ABD = ~oman_ABD+1'b1;
assign inv_man_ABE = ~oman_ABE+1'b1;
assign inv_man_ABF = ~oman_ABF+1'b1;
*/
csla #(26,5,5,1) csla_0(.in_01(~oman_AB0), .in_02({25'b0,1'b1}), .out(inv_man_AB0));
csla #(26,5,5,1) csla_1(.in_01(~oman_AB1), .in_02({25'b0,1'b1}), .out(inv_man_AB1));
csla #(26,5,5,1) csla_2(.in_01(~oman_AB2), .in_02({25'b0,1'b1}), .out(inv_man_AB2));
csla #(26,5,5,1) csla_3(.in_01(~oman_AB3), .in_02({25'b0,1'b1}), .out(inv_man_AB3));
csla #(26,5,5,1) csla_4(.in_01(~oman_AB4), .in_02({25'b0,1'b1}), .out(inv_man_AB4));
csla #(26,5,5,1) csla_5(.in_01(~oman_AB5), .in_02({25'b0,1'b1}), .out(inv_man_AB5));
csla #(26,5,5,1) csla_6(.in_01(~oman_AB6), .in_02({25'b0,1'b1}), .out(inv_man_AB6));
csla #(26,5,5,1) csla_7(.in_01(~oman_AB7), .in_02({25'b0,1'b1}), .out(inv_man_AB7));
csla #(26,5,5,1) csla_8(.in_01(~oman_AB8), .in_02({25'b0,1'b1}), .out(inv_man_AB8));
csla #(26,5,5,1) csla_9(.in_01(~oman_AB9), .in_02({25'b0,1'b1}), .out(inv_man_AB9));
csla #(26,5,5,1) csla_A(.in_01(~oman_ABA), .in_02({25'b0,1'b1}), .out(inv_man_ABA));
csla #(26,5,5,1) csla_B(.in_01(~oman_ABB), .in_02({25'b0,1'b1}), .out(inv_man_ABB));
csla #(26,5,5,1) csla_C(.in_01(~oman_ABC), .in_02({25'b0,1'b1}), .out(inv_man_ABC));
csla #(26,5,5,1) csla_D(.in_01(~oman_ABD), .in_02({25'b0,1'b1}), .out(inv_man_ABD));
csla #(26,5,5,1) csla_E(.in_01(~oman_ABE), .in_02({25'b0,1'b1}), .out(inv_man_ABE));
csla #(26,5,5,1) csla_F(.in_01(~oman_ABF), .in_02({25'b0,1'b1}), .out(inv_man_ABF));
always@(posedge clk)begin
    o_man_AB0 <= i_sign_AB[ 0] ? inv_man_AB0[25:0] : oman_AB0;
    o_man_AB1 <= i_sign_AB[ 1] ? inv_man_AB1[25:0] : oman_AB1;
    o_man_AB2 <= i_sign_AB[ 2] ? inv_man_AB2[25:0] : oman_AB2;
    o_man_AB3 <= i_sign_AB[ 3] ? inv_man_AB3[25:0] : oman_AB3;
    o_man_AB4 <= i_sign_AB[ 4] ? inv_man_AB4[25:0] : oman_AB4;
    o_man_AB5 <= i_sign_AB[ 5] ? inv_man_AB5[25:0] : oman_AB5;
    o_man_AB6 <= i_sign_AB[ 6] ? inv_man_AB6[25:0] : oman_AB6;
    o_man_AB7 <= i_sign_AB[ 7] ? inv_man_AB7[25:0] : oman_AB7;
    o_man_AB8 <= i_sign_AB[ 8] ? inv_man_AB8[25:0] : oman_AB8;
    o_man_AB9 <= i_sign_AB[ 9] ? inv_man_AB9[25:0] : oman_AB9;
    o_man_ABA <= i_sign_AB[10] ? inv_man_ABA[25:0] : oman_ABA;
    o_man_ABB <= i_sign_AB[11] ? inv_man_ABB[25:0] : oman_ABB;
    o_man_ABC <= i_sign_AB[12] ? inv_man_ABC[25:0] : oman_ABC;
    o_man_ABD <= i_sign_AB[13] ? inv_man_ABD[25:0] : oman_ABD;
    o_man_ABE <= i_sign_AB[14] ? inv_man_ABE[25:0] : oman_ABE;
    o_man_ABF <= i_sign_AB[15] ? inv_man_ABF[25:0] : oman_ABF;
    o_man_A_53b <= {i_fp64_imbitA, i_man_A1, i_man_A2, i_man_AE, i_man_AF}; 
    o_man_B_53b <= {i_fp64_imbitB, i_man_B9, i_man_BA, i_man_B6, i_man_B7};  
end

endmodule

