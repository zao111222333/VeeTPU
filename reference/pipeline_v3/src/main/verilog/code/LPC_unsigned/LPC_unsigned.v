
/* 
mode :
	2'b00: 16*2bit*2bit
	2'b01: 4*4bit*4bit
	2'b10: 1*8bit*8bit
*/

module LPC_unsigned (

input [7:0] x,
input [7:0] y,
input clk,
input [1:0] mode,

output reg [15:0] mac_out
);


reg [7:0] i_x, i_y;

always @(posedge clk)begin
	
	i_x <= x;
	i_y <= y;
	
end

wire [3:0] bb_0, bb_1 ,bb_2, bb_3, bb_4, bb_5, bb_6, bb_7, bb_8, bb_9, bb_10, bb_11, bb_12, bb_13, bb_14, bb_15;

bitbrick U_bb_0  ( .a(i_x[1:0]), .b(i_y[1:0]), .pp(bb_0 ) );
bitbrick U_bb_1  ( .a(i_x[3:2]), .b(i_y[1:0]), .pp(bb_1 ) );
bitbrick U_bb_2  ( .a(i_x[5:4]), .b(i_y[1:0]), .pp(bb_2 ) );
bitbrick U_bb_3  ( .a(i_x[7:6]), .b(i_y[1:0]), .pp(bb_3 ) );
bitbrick U_bb_4  ( .a(i_x[1:0]), .b(i_y[3:2]), .pp(bb_4 ) );
bitbrick U_bb_5  ( .a(i_x[3:2]), .b(i_y[3:2]), .pp(bb_5 ) );
bitbrick U_bb_6  ( .a(i_x[5:4]), .b(i_y[3:2]), .pp(bb_6 ) );
bitbrick U_bb_7  ( .a(i_x[7:6]), .b(i_y[3:2]), .pp(bb_7 ) );
bitbrick U_bb_8  ( .a(i_x[1:0]), .b(i_y[5:4]), .pp(bb_8 ) );
bitbrick U_bb_9  ( .a(i_x[3:2]), .b(i_y[5:4]), .pp(bb_9 ) );
bitbrick U_bb_10 ( .a(i_x[5:4]), .b(i_y[5:4]), .pp(bb_10) );
bitbrick U_bb_11 ( .a(i_x[7:6]), .b(i_y[5:4]), .pp(bb_11) );
bitbrick U_bb_12 ( .a(i_x[1:0]), .b(i_y[7:6]), .pp(bb_12) );
bitbrick U_bb_13 ( .a(i_x[3:2]), .b(i_y[7:6]), .pp(bb_13) );
bitbrick U_bb_14 ( .a(i_x[5:4]), .b(i_y[7:6]), .pp(bb_14) );
bitbrick U_bb_15 ( .a(i_x[7:6]), .b(i_y[7:6]), .pp(bb_15) );


reg [7:0] pp_0, pp_1, pp_2, pp_3;

always @(*)begin
    
case(mode)

2'b00:begin
	pp_0 <= bb_0  + bb_1  + bb_4  + bb_5 ;
	pp_1 <= bb_2  + bb_3  + bb_6  + bb_7 ;
   pp_2 <= bb_8  + bb_9  + bb_12 + bb_13;
	pp_3 <= bb_10 + bb_11 + bb_14 + bb_15;
end

2'b01:begin
	pp_0 <= bb_0+{bb_1,2'b0}+{bb_4,2'b0}+{bb_5,4'b0};
	pp_1 <= bb_2+{bb_3,2'b0}+{bb_6,2'b0}+{bb_7,4'b0};
	pp_2 <= bb_8+{bb_9,2'b0}+{bb_12,2'b0}+{bb_13,4'b0};
	pp_3 <= bb_10+{bb_11,2'b0}+{bb_14,2'b0}+{bb_15,4'b0};
end

2'b10:begin
	pp_0 <= bb_0+{bb_1,2'b0}+{bb_4,2'b0}+{bb_5,4'b0};
	pp_1 <= bb_2+{bb_3,2'b0}+{bb_6,2'b0}+{bb_7,4'b0};
	pp_2 <= bb_8+{bb_9,2'b0}+{bb_12,2'b0}+{bb_13,4'b0};
	pp_3 <= bb_10+{bb_11,2'b0}+{bb_14,2'b0}+{bb_15,4'b0};
end

default:begin
	pp_0 <= 8'b0;
	pp_1 <= 8'b0;
	pp_2 <= 8'b0;
	pp_3 <= 8'b0;
end

endcase

end

//add 4*pp together
reg [15:0] sum;

always @(*)begin

case(mode)

2'b00:begin
	sum <= pp_0+pp_1+pp_2+pp_3;
end

2'b01:begin
	sum <= pp_0+pp_1+pp_2+pp_3;
end

2'b10:begin
	sum <= pp_0+{pp_1,4'b0}+{pp_2,4'b0}+{pp_3,8'b0};
end

default:begin
	sum <= 16'b0;
end

endcase

end


always @(posedge clk)begin
	mac_out <= sum;
end


endmodule
