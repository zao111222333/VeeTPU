
/*
mode:

2'b00:4*2bit*2bit
2'b10:2*4bit*4bit
2'b11:1*8bit*8bit

*/

module HPS_unsigned (

input [7:0] x,
input [7:0] y,
input [1:0] mode,
input clk,

output reg [15:0] mac_out 
);

reg [7:0] i_x, i_y;

always @(posedge clk)begin
	
	i_x <= x;
	i_y <= y;

end

reg [7:0] pp_0, pp_1, pp_2, pp_3, pp_4, pp_5, pp_6, pp_7;

always @(*)begin

case(mode)

	2'b00:begin //4*2bit*2bit
      pp_0[7:6] <= i_y[0]?i_x[7:6]:2'b0;
    	pp_1[7:6] <= i_y[1]?i_x[7:6]:2'b0;
    	pp_2[5:4] <= i_y[2]?i_x[5:4]:2'b0;
    	pp_3[5:4] <= i_y[3]?i_x[5:4]:2'b0;
    	pp_4[3:2] <= i_y[4]?i_x[3:2]:2'b0;
    	pp_5[3:2] <= i_y[5]?i_x[3:2]:2'b0;
    	pp_6[1:0] <= i_y[6]?i_x[1:0]:2'b0;
    	pp_7[1:0] <= i_y[7]?i_x[1:0]:2'b0;
		
		pp_0[5:0] <= 6'b0;
    	pp_1[5:0] <= 6'b0;
    	{ {pp_2[3:0]}, {pp_2[7:6]} } <= 6'b0;
		{ {pp_3[3:0]}, {pp_3[7:6]} } <= 6'b0;
		{ {pp_4[7:4]}, {pp_4[1:0]} } <= 6'b0;
		{ {pp_5[7:4]}, {pp_5[1:0]} } <= 6'b0;
		pp_6[7:2] <= 6'b0;
		pp_7[7:2] <= 6'b0;

   end
	
   2'b10:begin //2*4bit*4bit 	
		pp_0[7:4] <= i_y[0]?i_x[7:4]:4'b0;
		pp_1[7:4] <= i_y[1]?i_x[7:4]:4'b0;
		pp_2[7:4] <= i_y[2]?i_x[7:4]:4'b0;
		pp_3[7:4] <= i_y[3]?i_x[7:4]:4'b0;
		pp_4[3:0] <= i_y[4]?i_x[3:0]:4'b0;
		pp_5[3:0] <= i_y[5]?i_x[3:0]:4'b0;
		pp_6[3:0] <= i_y[6]?i_x[3:0]:4'b0;
		pp_7[3:0] <= i_y[7]?i_x[3:0]:4'b0;
		
		pp_0[3:0] <= 4'b0;
		pp_1[3:0] <= 4'b0;
		pp_2[3:0] <= 4'b0;
		pp_3[3:0] <= 4'b0;
		pp_4[7:4] <= 4'b0;
		pp_5[7:4] <= 4'b0;
		pp_6[7:4] <= 4'b0;
		pp_7[7:4] <= 4'b0;
	end

	2'b11:begin 
		pp_0[7:0] <= i_y[0]?i_x[7:0]:8'b0;
		pp_1[7:0] <= i_y[1]?i_x[7:0]:8'b0;
		pp_2[7:0] <= i_y[2]?i_x[7:0]:8'b0;
		pp_3[7:0] <= i_y[3]?i_x[7:0]:8'b0;
		pp_4[7:0] <= i_y[4]?i_x[7:0]:8'b0;
		pp_5[7:0] <= i_y[5]?i_x[7:0]:8'b0;
		pp_6[7:0] <= i_y[6]?i_x[7:0]:8'b0;
		pp_7[7:0] <= i_y[7]?i_x[7:0]:8'b0;
   end

	default:begin
		pp_0[7:0] <= 8'b0;
		pp_1[7:0] <= 8'b0;
		pp_2[7:0] <= 8'b0;
		pp_3[7:0] <= 8'b0;
		pp_4[7:0] <= 8'b0;
		pp_5[7:0] <= 8'b0;
		pp_6[7:0] <= 8'b0;
		pp_7[7:0] <= 8'b0;
	end

endcase

end

wire [15:0] sum;
wire [15:0] sum0, sum1, sum2, sum3;
wire [15:0] sum01, sum23;

assign sum0 = pp_0+{pp_1,1'b0};
assign sum1 = {pp_2,2'b0}+{pp_3,3'b0};
assign sum2 = {pp_4,4'b0}+{pp_5,5'b0};
assign sum3 = {pp_6,6'b0}+{pp_7,7'b0};

assign sum01 = sum0 + sum1;
assign sum23 = sum2 + sum3;

assign sum = sum01 + sum23;

//assign sum = pp_0+{pp_1,1'b0}+{pp_2,2'b0}+{pp_3,3'b0}+{pp_4,4'b0}+{pp_5,5'b0}+{pp_6,6'b0}+{pp_7,7'b0};

always @(posedge clk)begin
	
	mac_out <= sum;

end


endmodule
