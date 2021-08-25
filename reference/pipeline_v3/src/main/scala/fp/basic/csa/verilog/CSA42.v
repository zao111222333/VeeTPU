module CSA42 #(parameter dataWidth = 4)(
    input [dataWidth-1:0]i_X_0,
    input [dataWidth-1:0]i_X_1,
    input [dataWidth-1:0]i_X_2,
    input [dataWidth-1:0]i_X_3,
    output[dataWidth-1:0]o_sum,
    output[dataWidth-1:0]o_carry,
    output o_carry_out,
    input               rst,
    input               clk
);

    //internal signal
    wire a0_xor_b0   ;
    wire c0_xor_d0   ;
    wire [dataWidth-1:0] c_out ;
    assign a0_xor_b0  = i_X_0[0]^i_X_1[0] ;
    assign c0_xor_d0  = i_X_2[0]^i_X_3[0] ;
    assign o_sum[0]     = a0_xor_b0 ^ c0_xor_d0 ;
    assign c_out[0]   = c0_xor_d0 ? i_X_1[0] : i_X_3[0];
    assign o_carry[0] = i_X_0[0] & (~o_sum[0]);
    assign o_carry_out = c_out[dataWidth-1];
    //output
    genvar i;
    generate
              for(i = 0; i < dataWidth-1; i = i+1) begin: CSA42_unit
                  CSA42_UNIT U_CSA42_UNIT(
			  .i_X_0(i_X_0[i+1]),
			  .i_X_1(i_X_1[i+1]),
			  .i_X_2(i_X_2[i+1]),
			  .i_X_3(i_X_3[i+1]),
			  .i_c_in(c_out[i]),
			  .o_c_out(c_out[i+1]),
			  .o_carry(o_carry[i+1]),
			  .o_sum(o_sum[i+1])
		  );
	      end
    endgenerate

endmodule

