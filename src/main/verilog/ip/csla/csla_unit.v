module csla_unit #(parameter WIDTH=10)(
   input  [WIDTH-1:0] i_X_0,
   input  [WIDTH-1:0] i_X_1,
   output [WIDTH  :0] o_sum_0,
   output [WIDTH  :0] o_sum_1
);
wire[WIDTH-1:0] i_X_0_xor_i_X_1;
wire[WIDTH-1:0] i_X_0_and_i_X_1;
wire[WIDTH-1:0] i_X_0_or_i_X_1 ;
wire[WIDTH-1:0] carry_0;
wire[WIDTH-1:0] carry_1;

assign i_X_0_xor_i_X_1 = i_X_0^i_X_1;
assign i_X_0_and_i_X_1 = i_X_0&i_X_1;
assign i_X_0_or_i_X_1  = i_X_0|i_X_1;
assign o_sum_0[0] =  i_X_0_xor_i_X_1[0];
assign o_sum_1[0] = ~i_X_0_xor_i_X_1[0];
assign carry_0[0] = i_X_0_and_i_X_1[0];
assign carry_1[0] = i_X_0_or_i_X_1 [0];
genvar i;
generate 
    for(i=0;i<WIDTH-1;i=i+1)begin:get_sum
        assign o_sum_0  [i+1] = carry_0[i] ? ~i_X_0_xor_i_X_1[i+1] : i_X_0_xor_i_X_1[i+1];
	assign o_sum_1  [i+1] = carry_1[i] ? ~i_X_0_xor_i_X_1[i+1] : i_X_0_xor_i_X_1[i+1];
	assign carry_0[i+1] = carry_0[i] ? i_X_0_or_i_X_1  [i+1] : i_X_0_and_i_X_1[i+1];
	assign carry_1[i+1] = carry_1[i] ? i_X_0_or_i_X_1  [i+1] : i_X_0_and_i_X_1[i+1];
    end
endgenerate
assign o_sum_0[WIDTH] = carry_0[WIDTH-1];
assign o_sum_1[WIDTH] = carry_1[WIDTH-1];
endmodule
