module exp_compare_unit_4in#(parameter WIDTH=11)(
    input [WIDTH-1:0] iexp_0,
	 input [WIDTH-1:0] iexp_1,
	 input [WIDTH-1:0] iexp_2,
	 input [WIDTH-1:0] iexp_3,
	 output [WIDTH-1:0] oexp_max,
	 output [WIDTH-1:0] oshift_0,
	 output [WIDTH-1:0] oshift_1,
	 output [WIDTH-1:0] oshift_2,
	 output [WIDTH-1:0] oshift_3
);
wire [WIDTH:0] diff_01; //different between iexp_0 and iexp_1
wire [WIDTH:0] diff_12;
wire [WIDTH:0] diff_23;
wire [WIDTH:0] diff_30;
wire [WIDTH:0] diff_02;
wire [WIDTH:0] diff_13;

wire [WIDTH-1:0] inv_iexp_0;
wire [WIDTH-1:0] inv_iexp_1;
wire [WIDTH-1:0] inv_iexp_2;
wire [WIDTH-1:0] inv_iexp_3;

assign inv_iexp_0 = ~iexp_0;
assign inv_iexp_1 = ~iexp_1;
assign inv_iexp_2 = ~iexp_2;
assign inv_iexp_3 = ~iexp_3;

assign diff_01 = {1'b0,iexp_0}+{1'b1,inv_iexp_1};
assign diff_12 = {1'b0,iexp_1}+{1'b1,inv_iexp_2};
assign diff_23 = {1'b0,iexp_2}+{1'b1,inv_iexp_3};
assign diff_30 = {1'b0,iexp_3}+{1'b1,inv_iexp_0};
assign diff_02 = {1'b0,iexp_0}+{1'b1,inv_iexp_2};
assign diff_13 = {1'b0,iexp_1}+{1'b1,inv_iexp_3};

/*
assign diff_01 = iexp_0-iexp_1;
assign diff_12 = iexp_1-iexp_2;
assign diff_23 = iexp_2-iexp_3;
assign diff_30 = iexp_3-iexp_0;
assign diff_02 = iexp_0-iexp_2;
assign diff_13 = iexp_1-iexp_3;
*/

wire compare_01 = diff_01[WIDTH];
wire compare_12 = diff_12[WIDTH];
wire compare_23 = diff_23[WIDTH];
wire compare_30 = diff_30[WIDTH];
wire compare_02 = diff_02[WIDTH];
wire compare_13 = diff_13[WIDTH];

wire [WIDTH-1:0] pos_diff_01; //postive of the diff_01
wire [WIDTH-1:0] pos_diff_12;
wire [WIDTH-1:0] pos_diff_23;
wire [WIDTH-1:0] pos_diff_30;
wire [WIDTH-1:0] pos_diff_02;
wire [WIDTH-1:0] pos_diff_13;

/*
assign pos_diff_01 = compare_01 ? (~diff_01[WIDTH-1:0]+1'b1) : (diff_01[WIDTH-1:0]);
assign pos_diff_12 = compare_12 ? (~diff_12[WIDTH-1:0]+1'b1) : (diff_12[WIDTH-1:0]);
assign pos_diff_23 = compare_23 ? (~diff_23[WIDTH-1:0]+1'b1) : (diff_23[WIDTH-1:0]);
assign pos_diff_30 = compare_30 ? (~diff_30[WIDTH-1:0]+1'b1) : (diff_30[WIDTH-1:0]);
assign pos_diff_02 = compare_02 ? (~diff_02[WIDTH-1:0]+1'b1) : (diff_02[WIDTH-1:0]);
assign pos_diff_13 = compare_13 ? (~diff_13[WIDTH-1:0]+1'b1) : (diff_13[WIDTH-1:0]);
*/
assign pos_diff_01 = compare_01 ? (~diff_01[WIDTH-1:0]) : (diff_01[WIDTH-1:0]+1'b1);
assign pos_diff_12 = compare_12 ? (~diff_12[WIDTH-1:0]) : (diff_12[WIDTH-1:0]+1'b1);
assign pos_diff_23 = compare_23 ? (~diff_23[WIDTH-1:0]) : (diff_23[WIDTH-1:0]+1'b1);
assign pos_diff_30 = compare_30 ? (~diff_30[WIDTH-1:0]) : (diff_30[WIDTH-1:0]+1'b1);
assign pos_diff_02 = compare_02 ? (~diff_02[WIDTH-1:0]) : (diff_02[WIDTH-1:0]+1'b1);
assign pos_diff_13 = compare_13 ? (~diff_13[WIDTH-1:0]) : (diff_13[WIDTH-1:0]+1'b1);

wire[3:0] compare = {compare_01,compare_12,compare_23,compare_30};
/*
always@(*)begin
    case(compare)
	     4'b0000:begin
		      oexp_max = iexp_0; //any input exp
				oshift_0 = 0;
				oshift_1 = 0;
				oshift_2 = 0;
				oshift_3 = 0;
		  end
		  4'b0001:begin
		      oexp_max = iexp_0;
				oshift_0 = 0;
				oshift_1 = pos_diff_01;
				oshift_2 = pos_diff_02;
				oshift_3 = pos_diff_30;
		  end
		  4'b0010:begin
		      oexp_max = iexp_3;
				oshift_0 = pos_diff_30;
				oshift_1 = pos_diff_13;
				oshift_2 = pos_diff_23;
				oshift_3 = 0;
		  end
		  4'b0011:begin
		      oexp_max = iexp_0;
				oshift_0 = 0;
				oshift_1 = pos_diff_01;
				oshift_2 = pos_diff_02;
				oshift_3 = pos_diff_30;
		  end
		  4'b0100:begin
		      oexp_max = iexp_2;
				oshift_0 = pos_diff_02;
				oshift_1 = pos_diff_12;
				oshift_2 = 0;
				oshift_3 = pos_diff_23;
		  end
		  4'b0101:begin
		      oexp_max = compare_02 ? iexp_2      : iexp_0      ;
				oshift_0 = compare_02 ? pos_diff_02 : 0           ;
				oshift_1 = compare_02 ? pos_diff_12 : pos_diff_01 ;
				oshift_2 = compare_02 ? 0           : pos_diff_02 ;
				oshift_3 = compare_02 ? pos_diff_23 : pos_diff_30 ;
		  end
		  4'b0110:begin
		      oexp_max = iexp_3;
				oshift_0 = pos_diff_30;
				oshift_1 = pos_diff_13;
				oshift_2 = pos_diff_23;
				oshift_3 = 0;
		  end
		  4'b0111:begin
		      oexp_max = iexp_0;
				oshift_0 = 0;
				oshift_1 = pos_diff_01;
				oshift_2 = pos_diff_02;
				oshift_3 = pos_diff_30;
		  end
		  4'b1000:begin
		      oexp_max = iexp_1;
				oshift_0 = pos_diff_01;
				oshift_1 = 0;
				oshift_2 = pos_diff_12;
				oshift_3 = pos_diff_13;
		  end
		  4'b1001:begin
		      oexp_max = iexp_1;
				oshift_0 = pos_diff_01;
				oshift_1 = 0;
				oshift_2 = pos_diff_12;
				oshift_3 = pos_diff_13;
		  end
		  4'b1010:begin
		      oexp_max = compare_13 ? iexp_3      : iexp_1      ;
				oshift_0 = compare_13 ? pos_diff_30 : pos_diff_01 ;
				oshift_1 = compare_13 ? pos_diff_13 : 0           ;
				oshift_2 = compare_13 ? pos_diff_23 : pos_diff_12 ;
				oshift_3 = compare_13 ? 0           : pos_diff_13 ;
		  end
		  4'b1011:begin
		      oexp_max = iexp_1;
				oshift_0 = pos_diff_01;
				oshift_1 = 0;
				oshift_2 = pos_diff_12;
				oshift_3 = pos_diff_13;
		  end
		  4'b1100:begin
		      oexp_max = iexp_2;
				oshift_0 = pos_diff_02;
				oshift_1 = pos_diff_12;
				oshift_2 = 0;
				oshift_3 = pos_diff_23;
		  end
		  4'b1101:begin
		      oexp_max = iexp_2;
				oshift_0 = pos_diff_02;
				oshift_1 = pos_diff_12;
				oshift_2 = 0;
				oshift_3 = pos_diff_23;
		  end
		  4'b1110:begin
		      oexp_max = iexp_3;
				oshift_0 = pos_diff_30;
				oshift_1 = pos_diff_13;
				oshift_2 = pos_diff_23;
				oshift_3 = 0;
		  end
		  default:begin
		      oexp_max = iexp_0;
				oshift_0 = 0;
				oshift_1 = 0;
				oshift_2 = 0;
				oshift_3 = 0;
		  end		  
	 endcase
end
*/
compare_logic_4in #(WIDTH) u_CL(
.compare    (compare    ),
.iexp_0     (iexp_0     ),
.iexp_1     (iexp_1     ),
.iexp_2     (iexp_2     ),
.iexp_3     (iexp_3     ),
.pos_diff_01(pos_diff_01),
.pos_diff_12(pos_diff_12),
.pos_diff_23(pos_diff_23),
.pos_diff_30(pos_diff_30),
.pos_diff_02(pos_diff_02),
.pos_diff_13(pos_diff_13),
.compare_02 (compare_02 ),
.compare_13 (compare_13 ),
.oexp_max   (oexp_max   ),
.oshift_0   (oshift_0   ),
.oshift_1   (oshift_1   ),
.oshift_2   (oshift_2   ),
.oshift_3   (oshift_3   )
);


endmodule

