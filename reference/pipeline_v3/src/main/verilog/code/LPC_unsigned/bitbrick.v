module bitbrick (

input [1:0] a,
input [1:0] b,

output [3:0] pp
);

wire [1:0] pp_1;
wire [1:0] pp_2;

assign pp_1[0] = b[0]?a[0]:1'b0;
assign pp_1[1] = b[0]?a[1]:1'b0;
assign pp_2[0] = b[1]?a[0]:1'b0;
assign pp_2[1] = b[1]?a[1]:1'b0;

//assign pp = pp_1 + {pp_2,1'b0};

CPA #(3) U_CPA_0 ( .a({1'b0,pp_1}), .b({pp_2,1'b0}), .result(pp) );

endmodule


