//signed
module add_tree_16in #(parameter WIDTH=49)(
    input [WIDTH-1: 0] i_data_0 ,
    input [WIDTH-1: 0] i_data_1 ,
    input [WIDTH-1: 0] i_data_2 ,
    input [WIDTH-1: 0] i_data_3 ,
    input [WIDTH-1: 0] i_data_4 ,
    input [WIDTH-1: 0] i_data_5 ,
    input [WIDTH-1: 0] i_data_6 ,
    input [WIDTH-1: 0] i_data_7 ,
    input [WIDTH-1: 0] i_data_8 ,
    input [WIDTH-1: 0] i_data_9 ,
    input [WIDTH-1: 0] i_data_10 ,
    input [WIDTH-1: 0] i_data_11 ,
    input [WIDTH-1: 0] i_data_12 ,
    input [WIDTH-1: 0] i_data_13 ,
    input [WIDTH-1: 0] i_data_14 ,
    input [WIDTH-1: 0] i_data_15 ,
    output[WIDTH+3: 0] o_sum  ,
    output[WIDTH+3: 0] o_carry,
    output[WIDTH+3: 0] o_add_result
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
        .a({{2{i_data_0[WIDTH-1]}},i_data_0}),
	.b({{2{i_data_1[WIDTH-1]}},i_data_1}),
	.c({{2{i_data_2[WIDTH-1]}},i_data_2}),
	.d({{2{i_data_3[WIDTH-1]}},i_data_3}),
	.sum(sum0_0),
	.carry(carry0_0),
	.carry_out()
    );

    CSA4_2 #(WIDTH+2) U01_CSA4_2(
        .a({{2{i_data_4[WIDTH-1]}},i_data_4}),
	.b({{2{i_data_5[WIDTH-1]}},i_data_5}),
	.c({{2{i_data_6[WIDTH-1]}},i_data_6}),
	.d({{2{i_data_7[WIDTH-1]}},i_data_7}),
	.sum(sum0_1),
	.carry(carry0_1),
	.carry_out()
    );

    CSA4_2 #(WIDTH+2) U02_CSA4_2(
        .a({{2{i_data_8[WIDTH-1]}},i_data_8}),
	.b({{2{i_data_9[WIDTH-1]}},i_data_9}),
	.c({{2{i_data_10[WIDTH-1]}},i_data_10}),
	.d({{2{i_data_11[WIDTH-1]}},i_data_11}),
	.sum(sum0_2),
	.carry(carry0_2),
	.carry_out()
    );

    CSA4_2 #(WIDTH+2) U03_CSA4_2(
        .a({{2{i_data_12[WIDTH-1]}},i_data_12}),
	.b({{2{i_data_13[WIDTH-1]}},i_data_13}),
	.c({{2{i_data_14[WIDTH-1]}},i_data_14}),
	.d({{2{i_data_15[WIDTH-1]}},i_data_15}),
	.sum(sum0_3),
	.carry(carry0_3),
	.carry_out()
    );


    wire [WIDTH+2:0]    sum1_0;
    wire [WIDTH+2:0]  carry1_0;
    wire [WIDTH+2:0]    sum1_1;
    wire [WIDTH+2:0]  carry1_1;

    wire [WIDTH+2:0]  u10_ain;
    wire [WIDTH+2:0]  u10_bin;
    wire [WIDTH+2:0]  u10_cin;
    wire [WIDTH+2:0]  u10_din;
    wire [WIDTH+2:0]  u11_ain;
    wire [WIDTH+2:0]  u11_bin;
    wire [WIDTH+2:0]  u11_cin;
    wire [WIDTH+2:0]  u11_din;

    assign u10_ain = {sum0_0[WIDTH+1],sum0_0};
    assign u10_bin = {carry0_0,1'b0};
    assign u10_cin = {sum0_1[WIDTH+1],sum0_1};
    assign u10_din = {carry0_1,1'b0};
    assign u11_ain = {sum0_2[WIDTH+1],sum0_2};
    assign u11_bin = {carry0_2,1'b0};
    assign u11_cin = {sum0_3[WIDTH+1],sum0_3};
    assign u11_din = {carry0_3,1'b0};

    CSA4_2 #(WIDTH+3) U10_CSA4_2(
        .a(u10_ain),
	.b(u10_bin),
	.c(u10_cin),
	.d(u10_din),
	.sum(sum1_0),
	.carry(carry1_0),
	.carry_out()
    );

    CSA4_2 #(WIDTH+3) U11_CSA4_2(
        .a(u11_ain),
	.b(u11_bin),
	.c(u11_cin),
	.d(u11_din),
	.sum(sum1_1),
	.carry(carry1_1),
	.carry_out()
    );


    wire [WIDTH+3: 0]       sum2_0;
    wire [WIDTH+3: 0]     carry2_0;

    wire [WIDTH+3 : 0] u20_ain;
    wire [WIDTH+3 : 0] u20_bin;
    wire [WIDTH+3 : 0] u20_cin;
    wire [WIDTH+3 : 0] u20_din;

    assign u20_ain = {sum1_0[WIDTH+2],sum1_0} ;
    assign u20_bin = {carry1_0,1'b0};
    assign u20_cin = {sum1_1[WIDTH+2],sum1_1};
    assign u20_din = {carry1_1,1'b0};


    CSA4_2 #(WIDTH+4) U20_CSA4_2(
        .a(u20_ain),
	.b(u20_bin),
	.c(u20_cin),
	.d(u20_din),
	.sum(sum2_0),
	.carry(carry2_0),
	.carry_out()
    );
//*************************accumulation********************//
wire [WIDTH+3: 0] csla_in1 = sum2_0;
wire [WIDTH+3: 0] csla_in2 = {carry2_0,1'b0};
wire [WIDTH+4:0] adr; 
csla #(WIDTH+4, 3, 2, 3) u_csla(csla_in1, csla_in2, adr);
assign o_add_result = adr[WIDTH+3:0];
assign o_sum   = csla_in1;
assign o_carry = csla_in2;

endmodule