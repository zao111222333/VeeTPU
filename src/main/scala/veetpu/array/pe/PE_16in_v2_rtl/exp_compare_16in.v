module exp_compare_16in #(parameter WIDTH=11)(
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

wire [WIDTH-1:0] shift_00;
wire [WIDTH-1:0] shift_01;
wire [WIDTH-1:0] shift_02;
wire [WIDTH-1:0] shift_03;
wire [WIDTH-1:0] exp_max_0;

wire [WIDTH-1:0] shift_04;
wire [WIDTH-1:0] shift_05;
wire [WIDTH-1:0] shift_06;
wire [WIDTH-1:0] shift_07;
wire [WIDTH-1:0] exp_max_1;

wire [WIDTH-1:0] shift_08;
wire [WIDTH-1:0] shift_09;
wire [WIDTH-1:0] shift_10;
wire [WIDTH-1:0] shift_11;
wire [WIDTH-1:0] exp_max_2;

wire [WIDTH-1:0] shift_12;
wire [WIDTH-1:0] shift_13;
wire [WIDTH-1:0] shift_14;
wire [WIDTH-1:0] shift_15;
wire [WIDTH-1:0] exp_max_3;

wire [WIDTH-1:0] max_shift_0;
wire [WIDTH-1:0] max_shift_1;
wire [WIDTH-1:0] max_shift_2;
wire [WIDTH-1:0] max_shift_3;

exp_compare_unit_4in #(WIDTH)u_compare_0(
   .iexp_0(iexp_00),
	.iexp_1(iexp_01),
	.iexp_2(iexp_02),
	.iexp_3(iexp_03),
	.oexp_max(exp_max_0),
	.oshift_0(shift_00),
	.oshift_1(shift_01),
	.oshift_2(shift_02),
	.oshift_3(shift_03)
);


exp_compare_unit_4in #(WIDTH)u_compare_1(
   .iexp_0(iexp_04),
	.iexp_1(iexp_05),
	.iexp_2(iexp_06),
	.iexp_3(iexp_07),
	.oexp_max(exp_max_1),
	.oshift_0(shift_04),
	.oshift_1(shift_05),
	.oshift_2(shift_06),
	.oshift_3(shift_07)
);

exp_compare_unit_4in #(WIDTH)u_compare_2(
   .iexp_0(iexp_08),
	.iexp_1(iexp_09),
	.iexp_2(iexp_10),
	.iexp_3(iexp_11),
	.oexp_max(exp_max_2),
	.oshift_0(shift_08),
	.oshift_1(shift_09),
	.oshift_2(shift_10),
	.oshift_3(shift_11)
);


exp_compare_unit_4in #(WIDTH)u_compare_3(
   .iexp_0(iexp_12),
	.iexp_1(iexp_13),
	.iexp_2(iexp_14),
	.iexp_3(iexp_15),
	.oexp_max(exp_max_3),
	.oshift_0(shift_12),
	.oshift_1(shift_13),
	.oshift_2(shift_14),
	.oshift_3(shift_15)
);

exp_compare_unit_4in #(WIDTH)u_compare_4(
   .iexp_0(exp_max_0),
	.iexp_1(exp_max_1),
	.iexp_2(exp_max_2),
	.iexp_3(exp_max_3),
	.oexp_max(oexp_max),
	.oshift_0(max_shift_0),
	.oshift_1(max_shift_1),
	.oshift_2(max_shift_2),
	.oshift_3(max_shift_3)
);

assign oshift_00 = shift_00 + max_shift_0;
assign oshift_01 = shift_01 + max_shift_0;
assign oshift_02 = shift_02 + max_shift_0;
assign oshift_03 = shift_03 + max_shift_0;

assign oshift_04 = shift_04 + max_shift_1;
assign oshift_05 = shift_05 + max_shift_1;
assign oshift_06 = shift_06 + max_shift_1;
assign oshift_07 = shift_07 + max_shift_1;

assign oshift_08 = shift_08 + max_shift_2;
assign oshift_09 = shift_09 + max_shift_2;
assign oshift_10 = shift_10 + max_shift_2;
assign oshift_11 = shift_11 + max_shift_2;

assign oshift_12 = shift_12 + max_shift_3;
assign oshift_13 = shift_13 + max_shift_3;
assign oshift_14 = shift_14 + max_shift_3;
assign oshift_15 = shift_15 + max_shift_3;

endmodule
