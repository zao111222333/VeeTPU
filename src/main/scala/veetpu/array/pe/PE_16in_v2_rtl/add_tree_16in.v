//signed
module add_tree_16in #(parameter WIDTH=53)(
    input [1      : 0] mode_sel_pip1,
    input [WIDTH-1: 0] data_in0 ,
    input [WIDTH-1: 0] data_in1 ,
    input [WIDTH-1: 0] data_in2 ,
    input [WIDTH-1: 0] data_in3 ,
    input [WIDTH-1: 0] data_in4 ,
    input [WIDTH-1: 0] data_in5 ,
    input [WIDTH-1: 0] data_in6 ,
    input [WIDTH-1: 0] data_in7 ,
    input [WIDTH-1: 0] data_in8 ,
    input [WIDTH-1: 0] data_in9 ,
    input [WIDTH-1: 0] data_inA ,
    input [WIDTH-1: 0] data_inB ,
    input [WIDTH-1: 0] data_inC ,
    input [WIDTH-1: 0] data_inD ,
    input [WIDTH-1: 0] data_inE ,
    input [WIDTH-1: 0] data_inF ,
    input [52     : 0] i_man_A_53b   , 
    input [52     : 0] i_man_B_53b   , 
    output[108    : 0] sum_out  ,
    output[108    : 0] carry_out,
    output[108    : 0] add_result
);

    wire [WIDTH+1 : 0]       sum0_0;
    wire [WIDTH+1 : 0]     carry0_0;
    wire [WIDTH+1 : 0]       sum0_1;
    wire [WIDTH+1 : 0]     carry0_1;
    wire [WIDTH+1 : 0]       sum0_2;
    wire [WIDTH+1 : 0]     carry0_2;
    wire [WIDTH+1 : 0]       sum0_3;
    wire [WIDTH+1 : 0]     carry0_3;

    CSA4_2 #(WIDTH+2) U00_CSA4_2(
        .a({{2{data_in0[WIDTH-1]}},data_in0}),
	.b({{2{data_in1[WIDTH-1]}},data_in1}),
	.c({{2{data_in2[WIDTH-1]}},data_in2}),
	.d({{2{data_in3[WIDTH-1]}},data_in3}),
	.sum(sum0_0),
	.carry(carry0_0),
	.carry_out()
    );

    CSA4_2 #(WIDTH+2) U01_CSA4_2(
        .a({{2{data_in4[WIDTH-1]}},data_in4}),
	.b({{2{data_in5[WIDTH-1]}},data_in5}),
	.c({{2{data_in6[WIDTH-1]}},data_in6}),
	.d({{2{data_in7[WIDTH-1]}},data_in7}),
	.sum(sum0_1),
	.carry(carry0_1),
	.carry_out()
    );

    CSA4_2 #(WIDTH+2) U02_CSA4_2(
        .a({{2{data_in8[WIDTH-1]}},data_in8}),
	.b({{2{data_in9[WIDTH-1]}},data_in9}),
	.c({{2{data_inA[WIDTH-1]}},data_inA}),
	.d({{2{data_inB[WIDTH-1]}},data_inB}),
	.sum(sum0_2),
	.carry(carry0_2),
	.carry_out()
    );

    CSA4_2 #(WIDTH+2) U03_CSA4_2(
        .a({{2{data_inC[WIDTH-1]}},data_inC}),
	.b({{2{data_inD[WIDTH-1]}},data_inD}),
	.c({{2{data_inE[WIDTH-1]}},data_inE}),
	.d({{2{data_inF[WIDTH-1]}},data_inF}),
	.sum(sum0_3),
	.carry(carry0_3),
	.carry_out()
    );


    wire [WIDTH+2:0]    sum1_0;
    wire [WIDTH+2:0]  carry1_0;
    wire [WIDTH+2:0]    sum1_1;
    wire [WIDTH+2:0]  carry1_1;

    wire [WIDTH+2:0]  u10_cin;
    wire [WIDTH+2:0]  u10_din;
    wire a4b4 = i_man_A_53b[52]&i_man_B_53b[52];
    wire [51:0] a4b3210 = i_man_A_53b[52] ? i_man_A_53b[51:0] : 52'b0;
    wire [51:0] b4a3210 = i_man_B_53b[52] ? i_man_B_53b[51:0] : 52'b0;
    assign u10_cin = mode_sel_pip1[1] ? {3'b0, a4b4, a4b3210} : {sum0_3[WIDTH+1],sum0_3};
    assign u10_din = mode_sel_pip1[1] ? {4'b0, b4a3210} : {carry0_3,1'b0};

    CSA4_2 #(WIDTH+3) U10_CSA4_2(
        .a({sum0_0[WIDTH+1],sum0_0}),
	.b({carry0_0,1'b0}),
	.c(u10_cin),
	.d(u10_din),
	.sum(sum1_0),
	.carry(carry1_0),
	.carry_out()
    );

    CSA4_2 #(WIDTH+3) U11_CSA4_2(
        .a({sum0_1[WIDTH+1],sum0_1}),
	.b({carry0_1,1'b0}),
	.c({sum0_2[WIDTH+1],sum0_2}),
	.d({carry0_2,1'b0}),
	.sum(sum1_1),
	.carry(carry1_1),
	.carry_out()
    );


    wire [WIDTH+3+26: 0]       sum2_0;
    wire [WIDTH+3+26: 0]     carry2_0;

    wire [WIDTH+29 : 0] u20_ain;
    wire [WIDTH+29 : 0] u20_bin;
    wire [WIDTH+29 : 0] u20_cin;
    wire [WIDTH+29 : 0] u20_din;

    assign u20_ain = mode_sel_pip1[1] ? {sum1_0[WIDTH+2],sum1_0,sum0_3[51:26]} : {sum1_0[WIDTH+2],sum1_0,26'b0} ;
    assign u20_bin = mode_sel_pip1[1] ? {carry1_0,1'b0,carry0_3[50:25]}        : {carry1_0,1'b0,26'b0}     ;
    assign u20_cin = mode_sel_pip1[1] ? {26'b0,sum1_1[WIDTH+2],sum1_1} : {sum1_1[WIDTH+2],sum1_1,26'b0};
    assign u20_din = mode_sel_pip1[1] ? {26'b0,carry1_1,1'b0} : {carry1_1,1'b0,26'b0};


    CSA4_2 #(WIDTH+30) U20_CSA4_2(
        .a(u20_ain),
	.b(u20_bin),
	.c(u20_cin),
	.d(u20_din),
	.sum(sum2_0),
	.carry(carry2_0),
	.carry_out()
    );
//*************************accumulation********************//

assign add_result[12:0] = data_inF[12:0];
//assign add_result[108:13] = {sum2_0,sum0_3[25:13]} + {carry2_0[WIDTH+28:0], 1'b0, carry0_3[24:12]};
wire [96:0] adr; 
csla #(96, 9, 10, 6) u_csla({sum2_0,sum0_3[25:13]}, {carry2_0[WIDTH+28:0], 1'b0, carry0_3[24:12]}, adr);
assign add_result[108:13] = adr[95:0];
assign sum_out = {sum2_0, sum0_3[25:0]};
assign carry_out = {carry2_0[WIDTH+28:0], 1'b0, carry0_3[24:0],1'b0};

endmodule
