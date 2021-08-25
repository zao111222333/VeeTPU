module exp_compare_rf#(parameter WIDTH=11)(
    input [WIDTH-1:0] iexp_00,
    input [WIDTH-1:0] iexp_01,
    input [WIDTH-1:0] iexp_02,
    input [WIDTH-1:0] iexp_03,
    input [WIDTH-1:0] iexp_04,
    input [WIDTH-1:0] iexp_05,
    input [WIDTH-1:0] iexp_06,
    input [WIDTH-1:0] iexp_07,
    input [WIDTH-1:0] iexp_08,
    input [WIDTH-1:0] iexp_09,
    input [WIDTH-1:0] iexp_10,
    input [WIDTH-1:0] iexp_11,
    input [WIDTH-1:0] iexp_12,
    input [WIDTH-1:0] iexp_13,
    input [WIDTH-1:0] iexp_14,
    input [WIDTH-1:0] iexp_15,
    output  [WIDTH-1:0] oexp_max,
    output  [WIDTH-1:0] oshift_00,
    output  [WIDTH-1:0] oshift_01,
    output  [WIDTH-1:0] oshift_02,
    output  [WIDTH-1:0] oshift_03,
    output  [WIDTH-1:0] oshift_04,
    output  [WIDTH-1:0] oshift_05,
    output  [WIDTH-1:0] oshift_06,
    output  [WIDTH-1:0] oshift_07,
    output  [WIDTH-1:0] oshift_08,
    output  [WIDTH-1:0] oshift_09,
    output  [WIDTH-1:0] oshift_10,
    output  [WIDTH-1:0] oshift_11,
    output  [WIDTH-1:0] oshift_12,
    output  [WIDTH-1:0] oshift_13,
    output  [WIDTH-1:0] oshift_14,
    output  [WIDTH-1:0] oshift_15
);

wire [WIDTH-1:0] exp_max_0_0;
wire [WIDTH-1:0] exp_max_1_0;
wire [WIDTH-1:0] exp_max_2_0;
wire [WIDTH-1:0] exp_max_3_0;
wire [WIDTH-1:0] exp_max_4_0;
wire [WIDTH-1:0] exp_max_5_0;
wire [WIDTH-1:0] exp_max_6_0;
wire [WIDTH-1:0] exp_max_7_0;

wire [WIDTH-1:0] exp_max_0_1;
wire [WIDTH-1:0] exp_max_1_1;
wire [WIDTH-1:0] exp_max_2_1;
wire [WIDTH-1:0] exp_max_3_1;

wire [WIDTH-1:0] exp_max_0_2;
wire [WIDTH-1:0] exp_max_1_2;

assign exp_max_0_0 = (iexp_00>iexp_01) ? iexp_00 : iexp_01;
assign exp_max_1_0 = (iexp_02>iexp_03) ? iexp_02 : iexp_03;
assign exp_max_2_0 = (iexp_04>iexp_05) ? iexp_04 : iexp_05;
assign exp_max_3_0 = (iexp_06>iexp_07) ? iexp_06 : iexp_07;
assign exp_max_4_0 = (iexp_08>iexp_09) ? iexp_08 : iexp_09;
assign exp_max_5_0 = (iexp_10>iexp_11) ? iexp_10 : iexp_11;
assign exp_max_6_0 = (iexp_12>iexp_13) ? iexp_12 : iexp_13;
assign exp_max_7_0 = (iexp_14>iexp_15) ? iexp_14 : iexp_15;

assign exp_max_0_1 = (exp_max_0_0>exp_max_1_0) ? exp_max_0_0 : exp_max_1_0;
assign exp_max_1_1 = (exp_max_2_0>exp_max_3_0) ? exp_max_2_0 : exp_max_3_0;
assign exp_max_2_1 = (exp_max_4_0>exp_max_5_0) ? exp_max_4_0 : exp_max_5_0;
assign exp_max_3_1 = (exp_max_6_0>exp_max_7_0) ? exp_max_6_0 : exp_max_7_0;

assign exp_max_0_2 = (exp_max_0_1>exp_max_1_1) ? exp_max_0_1 : exp_max_1_1;
assign exp_max_1_2 = (exp_max_2_1>exp_max_3_1) ? exp_max_2_1 : exp_max_3_1;

assign oexp_max = (exp_max_0_2>exp_max_1_2) ? exp_max_0_2 : exp_max_1_2;

assign oshift_00 = oexp_max - iexp_00;
assign oshift_01 = oexp_max - iexp_01;
assign oshift_02 = oexp_max - iexp_02;
assign oshift_03 = oexp_max - iexp_03;
assign oshift_04 = oexp_max - iexp_04;
assign oshift_05 = oexp_max - iexp_05;
assign oshift_06 = oexp_max - iexp_06;
assign oshift_07 = oexp_max - iexp_07;
assign oshift_08 = oexp_max - iexp_08;
assign oshift_09 = oexp_max - iexp_09;
assign oshift_10 = oexp_max - iexp_10;
assign oshift_11 = oexp_max - iexp_11;
assign oshift_12 = oexp_max - iexp_12;
assign oshift_13 = oexp_max - iexp_13;
assign oshift_14 = oexp_max - iexp_14;
assign oshift_15 = oexp_max - iexp_15;
endmodule
