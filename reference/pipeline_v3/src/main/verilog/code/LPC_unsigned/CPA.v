module CPA#(parameter High=8)
 (
    input [High-1:0] a,
    input [High-1:0] b,
    output [High:0] result
 );


genvar i;

wire [High-1:0] sum;
wire [High-1:0] cin;
wire [High-1:0] cout;

full_add U_full_add_0(.x(a[0]), .y(b[0]), .cin(1'b0), .cout(cout[0]), .sum(sum[0]) );

generate
    for(i=1; i<High; i = i+1) begin:Fadd4CPA
        full_add U_full_add_1(.x(a[i]), .y(b[i]), .cin(cout[i-1]), .cout(cout[i]), .sum(sum[i]) );
    end 
endgenerate

assign result = {cout[High-1], sum};


endmodule
