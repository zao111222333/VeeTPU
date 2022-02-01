module compare16#(parameter dataWidth=11)(
    input [dataWidth-1:0] i_exp_0,
    input [dataWidth-1:0] i_exp_1,
    input [dataWidth-1:0] i_exp_2,
    input [dataWidth-1:0] i_exp_3,
    input [dataWidth-1:0] i_exp_4,
    input [dataWidth-1:0] i_exp_5,
    input [dataWidth-1:0] i_exp_6,
    input [dataWidth-1:0] i_exp_7,
    input [dataWidth-1:0] i_exp_8,
    input [dataWidth-1:0] i_exp_9,
    input [dataWidth-1:0] i_exp_10,
    input [dataWidth-1:0] i_exp_11,
    input [dataWidth-1:0] i_exp_12,
    input [dataWidth-1:0] i_exp_13,
    input [dataWidth-1:0] i_exp_14,
    input [dataWidth-1:0] i_exp_15,
    output  [dataWidth-1:0] o_exp_max,
    output  [dataWidth-1:0] o_shift_0,
    output  [dataWidth-1:0] o_shift_1,
    output  [dataWidth-1:0] o_shift_2,
    output  [dataWidth-1:0] o_shift_3,
    output  [dataWidth-1:0] o_shift_4,
    output  [dataWidth-1:0] o_shift_5,
    output  [dataWidth-1:0] o_shift_6,
    output  [dataWidth-1:0] o_shift_7,
    output  [dataWidth-1:0] o_shift_8,
    output  [dataWidth-1:0] o_shift_9,
    output  [dataWidth-1:0] o_shift_10,
    output  [dataWidth-1:0] o_shift_11,
    output  [dataWidth-1:0] o_shift_12,
    output  [dataWidth-1:0] o_shift_13,
    output  [dataWidth-1:0] o_shift_14,
    output  [dataWidth-1:0] o_shift_15,
    input rst,
    input clk
);

wire [dataWidth-1:0] exp_max_0_0;
wire [dataWidth-1:0] exp_max_1_0;
wire [dataWidth-1:0] exp_max_2_0;
wire [dataWidth-1:0] exp_max_3_0;
wire [dataWidth-1:0] exp_max_4_0;
wire [dataWidth-1:0] exp_max_5_0;
wire [dataWidth-1:0] exp_max_6_0;
wire [dataWidth-1:0] exp_max_7_0;

wire [dataWidth-1:0] exp_max_0_1;
wire [dataWidth-1:0] exp_max_1_1;
wire [dataWidth-1:0] exp_max_2_1;
wire [dataWidth-1:0] exp_max_3_1;

wire [dataWidth-1:0] exp_max_0_2;
wire [dataWidth-1:0] exp_max_1_2;

assign exp_max_0_0 = (i_exp_0>i_exp_1) ? i_exp_0 : i_exp_1;
assign exp_max_1_0 = (i_exp_2>i_exp_3) ? i_exp_2 : i_exp_3;
assign exp_max_2_0 = (i_exp_4>i_exp_5) ? i_exp_4 : i_exp_5;
assign exp_max_3_0 = (i_exp_6>i_exp_7) ? i_exp_6 : i_exp_7;
assign exp_max_4_0 = (i_exp_8>i_exp_9) ? i_exp_8 : i_exp_9;
assign exp_max_5_0 = (i_exp_10>i_exp_11) ? i_exp_10 : i_exp_11;
assign exp_max_6_0 = (i_exp_12>i_exp_13) ? i_exp_12 : i_exp_13;
assign exp_max_7_0 = (i_exp_14>i_exp_15) ? i_exp_14 : i_exp_15;

assign exp_max_0_1 = (exp_max_0_0>exp_max_1_0) ? exp_max_0_0 : exp_max_1_0;
assign exp_max_1_1 = (exp_max_2_0>exp_max_3_0) ? exp_max_2_0 : exp_max_3_0;
assign exp_max_2_1 = (exp_max_4_0>exp_max_5_0) ? exp_max_4_0 : exp_max_5_0;
assign exp_max_3_1 = (exp_max_6_0>exp_max_7_0) ? exp_max_6_0 : exp_max_7_0;

assign exp_max_0_2 = (exp_max_0_1>exp_max_1_1) ? exp_max_0_1 : exp_max_1_1;
assign exp_max_1_2 = (exp_max_2_1>exp_max_3_1) ? exp_max_2_1 : exp_max_3_1;

assign o_exp_max = (exp_max_0_2>exp_max_1_2) ? exp_max_0_2 : exp_max_1_2;

assign o_shift_0 = o_exp_max - i_exp_0;
assign o_shift_1 = o_exp_max - i_exp_1;
assign o_shift_2 = o_exp_max - i_exp_2;
assign o_shift_3 = o_exp_max - i_exp_3;
assign o_shift_4 = o_exp_max - i_exp_4;
assign o_shift_5 = o_exp_max - i_exp_5;
assign o_shift_6 = o_exp_max - i_exp_6;
assign o_shift_7 = o_exp_max - i_exp_7;
assign o_shift_8 = o_exp_max - i_exp_8;
assign o_shift_9 = o_exp_max - i_exp_9;
assign o_shift_10 = o_exp_max - i_exp_10;
assign o_shift_11 = o_exp_max - i_exp_11;
assign o_shift_12 = o_exp_max - i_exp_12;
assign o_shift_13 = o_exp_max - i_exp_13;
assign o_shift_14 = o_exp_max - i_exp_14;
assign o_shift_15 = o_exp_max - i_exp_15;
endmodule
