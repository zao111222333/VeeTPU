module CSA4_2_UNIT (
    input  a     ,
    input  b     ,
    input  c     ,
    input  d     ,
    input  c_in  ,
    output c_out ,
    output carry ,
    output sum    
);
    //internal signal
    wire a_xor_b   ;
    wire c_xor_d   ;
    wire ab_xor_cd ;
    assign a_xor_b= a^b ;
    assign c_xor_d= c^d ;
    assign ab_xor_cd = a_xor_b ^ c_xor_d ;

    //output
    assign c_out = c_xor_d ? b : d ;
    assign carry = ab_xor_cd ? c_in : a ;
    assign sum   = ab_xor_cd ^ c_in;
endmodule

module CSA4_2 #(parameter Width = 24)(
    input [Width-1:0]a,
    input [Width-1:0]b,
    input [Width-1:0]c,
    input [Width-1:0]d,
    output[Width-1:0]sum,
    output[Width-1:0]carry,
    output carry_out
);

    //internal signal
    wire a0_xor_b0   ;
    wire c0_xor_d0   ;
    wire [Width-1:0] c_out ;
    assign a0_xor_b0  = a[0]^b[0] ;
    assign c0_xor_d0  = c[0]^d[0] ;
    assign sum[0]     = a0_xor_b0 ^ c0_xor_d0 ;
    assign c_out[0]   = c0_xor_d0 ? b[0] : d[0];
    assign carry[0] = a[0] & (~sum[0]);
    assign carry_out = c_out[Width-1];
    //output
    genvar i;
    generate
              for(i = 0; i < Width-1; i = i+1) begin: CSA4_2_unit
                  CSA4_2_UNIT U_CSA4_2_UNIT(
			  .a(a[i+1]),
			  .b(b[i+1]),
			  .c(c[i+1]),
			  .d(d[i+1]),
			  .c_in(c_out[i]),
			  .c_out(c_out[i+1]),
			  .carry(carry[i+1]),
			  .sum(sum[i+1])
		  );
	      end
    endgenerate

endmodule

