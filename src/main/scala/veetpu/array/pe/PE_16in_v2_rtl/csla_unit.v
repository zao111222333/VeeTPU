module csla_unit #(parameter WIDTH=10)(
   input  [WIDTH-1:0] in_01,
   input  [WIDTH-1:0] in_02,
   output [WIDTH  :0] sum_0,
   output [WIDTH  :0] sum_1
);
wire[WIDTH-1:0] in_01_xor_in_02;
wire[WIDTH-1:0] in_01_and_in_02;
wire[WIDTH-1:0] in_01_or_in_02 ;
wire[WIDTH-1:0] carry_0;
wire[WIDTH-1:0] carry_1;

assign in_01_xor_in_02=in_01^in_02;
assign in_01_and_in_02=in_01&in_02;
assign in_01_or_in_02 =in_01|in_02;
assign sum_0[0] =  in_01_xor_in_02[0];
assign sum_1[0] = ~in_01_xor_in_02[0];
assign carry_0[0] = in_01_and_in_02[0];
assign carry_1[0] = in_01_or_in_02 [0];
genvar i;
generate 
    for(i=0;i<WIDTH-1;i=i+1)begin:get_sum
        assign sum_0  [i+1] = carry_0[i] ? ~in_01_xor_in_02[i+1] : in_01_xor_in_02[i+1];
	assign sum_1  [i+1] = carry_1[i] ? ~in_01_xor_in_02[i+1] : in_01_xor_in_02[i+1];
	assign carry_0[i+1] = carry_0[i] ? in_01_or_in_02  [i+1] : in_01_and_in_02[i+1];
	assign carry_1[i+1] = carry_1[i] ? in_01_or_in_02  [i+1] : in_01_and_in_02[i+1];
    end
endgenerate
assign sum_0[WIDTH] = carry_0[WIDTH-1];
assign sum_1[WIDTH] = carry_1[WIDTH-1];
endmodule
