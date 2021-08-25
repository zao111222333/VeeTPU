module compare_logic_4in #(parameter WIDTH=11)(
input [3:0] compare,
input [WIDTH-1:0] iexp_0,
input [WIDTH-1:0] iexp_1,
input [WIDTH-1:0] iexp_2,
input [WIDTH-1:0] iexp_3,
input [WIDTH-1:0] pos_diff_01,
input [WIDTH-1:0] pos_diff_12,
input [WIDTH-1:0] pos_diff_23,
input [WIDTH-1:0] pos_diff_30,
input [WIDTH-1:0] pos_diff_02,
input [WIDTH-1:0] pos_diff_13,
input compare_02,
input compare_13,
output reg [WIDTH-1:0] oexp_max,
output reg [WIDTH-1:0] oshift_0,
output reg [WIDTH-1:0] oshift_1,
output reg [WIDTH-1:0] oshift_2,
output reg [WIDTH-1:0] oshift_3
);
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
endmodule
