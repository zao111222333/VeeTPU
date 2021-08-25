module CSA3_2#(parameter width = 24)
(
input [width-1:0]a,
input [width-1:0]b,
input [width-1:0]c,
output[width-1:0]sum,
output[width-1:0]carry
);


genvar i;
generate
          for(i = 0; i < width; i = i+1) begin: Fulladder
		  Fadd U_Fadd(
			  .x(a[i]), 
			  .y(b[i]), 
			  .Cin(c[i]), 
			  .Cout(carry[i]), 
			  .Sum(sum[i])
		  );
	  end
endgenerate


endmodule
