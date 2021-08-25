module CSLA #(parameter WIDTH=29, PRE_WIDTH=6, PRE_UNIT_NUM=4,RCA_WIDTH=5)(
    input [WIDTH-1:0] i_X_0,
    input [WIDTH-1:0] i_X_1,
    output [WIDTH  :0] o_S,
    input               rst,
    input               clk
);
wire [RCA_WIDTH:0] o_sum_rca;
cpa #(RCA_WIDTH) u_cpa(.a(i_X_0[RCA_WIDTH-1:0]), .b(i_X_1[RCA_WIDTH-1:0]), .sum(o_sum_rca));

wire[PRE_WIDTH:0] o_sum_0 [PRE_UNIT_NUM-1:0];
wire[PRE_WIDTH:0] o_sum_1 [PRE_UNIT_NUM-1:0];
genvar i;
generate
    for(i=0;i<PRE_UNIT_NUM;i=i+1)begin:csla_unit
        csla_unit #(PRE_WIDTH) u_csla_unit(
	    .i_X_0(i_X_0[((i+1)*PRE_WIDTH+RCA_WIDTH-1):i*PRE_WIDTH+RCA_WIDTH]),
	    .i_X_1(i_X_1[((i+1)*PRE_WIDTH+RCA_WIDTH-1):i*PRE_WIDTH+RCA_WIDTH]),
	    .o_sum_0(o_sum_0[i]),
	    .o_sum_1(o_sum_1[i])
	);
    end
endgenerate
wire[PRE_WIDTH:0] o_sum_sel [PRE_UNIT_NUM-1:0];
assign o_sum_sel[0] = o_sum_rca[RCA_WIDTH] ? o_sum_1[0] : o_sum_0[0];
generate
    for(i=0;i<PRE_UNIT_NUM-1;i=i+1)begin:o_sum_sel_check
        assign o_sum_sel[i+1] = o_sum_sel[i][PRE_WIDTH] ? o_sum_1[i+1] : o_sum_0[i+1];
    end
endgenerate
wire [PRE_WIDTH*PRE_UNIT_NUM-1:0] out_sel;
generate
    for(i=0;i<PRE_UNIT_NUM;i=i+1)begin:output_sel
        assign out_sel[((i+1)*PRE_WIDTH-1):i*PRE_WIDTH] = o_sum_sel[i][PRE_WIDTH-1:0];
    end
endgenerate
assign o_S = {o_sum_sel[PRE_UNIT_NUM-1][PRE_WIDTH], out_sel, o_sum_rca[RCA_WIDTH-1:0]};

endmodule
