module cpa#(parameter WIDTH = 64)
(
//input clk,
//input rstn,
input [WIDTH-1:0]a,
input [WIDTH-1:0]b,
output [WIDTH:0]sum
);

//wire [WIDTH:0]sum;
genvar i;
wire [WIDTH-1:0] sum_pord;
wire [WIDTH-1:0] carry_pord;
Hadd Hadd_1(.a(a[0]), .b(b[0]), .sum(sum_pord[0]), .carry(carry_pord[0]));
generate
          for(i = 1; i < WIDTH; i = i+1) begin: FullAdd
		  Fadd Fadd_1(.x(a[i]), .y(b[i]), .Cin(carry_pord[i-1]), .Cout(carry_pord[i]), .Sum(sum_pord[i]));
	  end
endgenerate

assign sum={carry_pord[WIDTH-1],sum_pord};
/*
always@(posedge clk or negedge rstn)begin
    if(rstn==0)begin
        sum_out <= 0;
    end
    else begin
        sum_out <= sum;
    end
end
*/
endmodule
