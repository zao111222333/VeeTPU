module csla #(parameter WIDTH=29, PRE_WIDTH=6, PRE_UNIT_NUM=4,RCA_WIDTH=5)(
    input [WIDTH-1:0] in_01,
    input [WIDTH-1:0] in_02,
    output [WIDTH  :0] out 
);
wire [RCA_WIDTH:0] sum_rca;
cpa #(RCA_WIDTH) u_cpa(.a(in_01[RCA_WIDTH-1:0]), .b(in_02[RCA_WIDTH-1:0]), .sum(sum_rca));

wire[PRE_WIDTH:0] sum_0 [PRE_UNIT_NUM-1:0];
wire[PRE_WIDTH:0] sum_1 [PRE_UNIT_NUM-1:0];
genvar i;
generate
    for(i=0;i<PRE_UNIT_NUM;i=i+1)begin:csla_unit
        csla_unit #(PRE_WIDTH) u_csla_unit(
	    .in_01(in_01[((i+1)*PRE_WIDTH+RCA_WIDTH-1):i*PRE_WIDTH+RCA_WIDTH]),
	    .in_02(in_02[((i+1)*PRE_WIDTH+RCA_WIDTH-1):i*PRE_WIDTH+RCA_WIDTH]),
	    .sum_0(sum_0[i]),
	    .sum_1(sum_1[i])
	);
    end
endgenerate
wire[PRE_WIDTH:0] sum_sel [PRE_UNIT_NUM-1:0];
assign sum_sel[0] = sum_rca[RCA_WIDTH] ? sum_1[0] : sum_0[0];
generate
    for(i=0;i<PRE_UNIT_NUM-1;i=i+1)begin:sum_sel_check
        assign sum_sel[i+1] = sum_sel[i][PRE_WIDTH] ? sum_1[i+1] : sum_0[i+1];
    end
endgenerate
wire [PRE_WIDTH*PRE_UNIT_NUM-1:0] out_sel;
generate
    for(i=0;i<PRE_UNIT_NUM;i=i+1)begin:output_sel
        assign out_sel[((i+1)*PRE_WIDTH-1):i*PRE_WIDTH] = sum_sel[i][PRE_WIDTH-1:0];
    end
endgenerate
assign out = {sum_sel[PRE_UNIT_NUM-1][PRE_WIDTH], out_sel, sum_rca[RCA_WIDTH-1:0]};

endmodule
