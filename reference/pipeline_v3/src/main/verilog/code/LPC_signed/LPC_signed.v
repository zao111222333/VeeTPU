
/* 
mode :
	2'b00: 16*2bit*2bit
	2'b01: 4*4bit*4bit
	2'b10: 1*8bit*8bit
*/

module LPC_signed (

input [7:0] i_x,
input [7:0] i_y,
input [1:0] mode,
input clk,

output reg [15:0] mac_out
);

reg [7:0] x, y;

always @(posedge clk)begin
	
	x <= i_x;
	y <= i_y;

end



wire [3:0] bb_0, bb_1 ,bb_2, bb_3, bb_4, bb_5, bb_6, bb_7, bb_8, bb_9, bb_10, bb_11, bb_12, bb_13, bb_14, bb_15;

wire [3:0] bb0_0, bb0_1 ,bb0_2, bb0_3, bb0_4, bb0_5, bb0_6, bb0_7, bb0_8, bb0_9, bb0_10, bb0_11, bb0_12, bb0_13, bb0_14, bb0_15;

wire [3:0] bb1_0, bb1_1 ,bb1_2, bb1_3, bb1_4, bb1_5, bb1_6, bb1_7, bb1_8, bb1_9, bb1_10, bb1_11, bb1_12, bb1_13, bb1_14, bb1_15;

wire [3:0] bb2_0, bb2_1 ,bb2_2, bb2_3, bb2_4, bb2_5, bb2_6, bb2_7, bb2_8, bb2_9, bb2_10, bb2_11, bb2_12, bb2_13, bb2_14, bb2_15;

BB0 U_BB0_0  ( .a(x[1:0]), .b(y[1:0]), .pp(bb0_0 ) );
BB0 U_BB0_1  ( .a(x[3:2]), .b(y[1:0]), .pp(bb0_1 ) );
BB0 U_BB0_2  ( .a(x[5:4]), .b(y[1:0]), .pp(bb0_2 ) );
BB0 U_BB0_3  ( .a(x[7:6]), .b(y[1:0]), .pp(bb0_3 ) );
BB0 U_BB0_4  ( .a(x[1:0]), .b(y[3:2]), .pp(bb0_4 ) );
BB0 U_BB0_5  ( .a(x[3:2]), .b(y[3:2]), .pp(bb0_5 ) );
BB0 U_BB0_6  ( .a(x[5:4]), .b(y[3:2]), .pp(bb0_6 ) );
BB0 U_BB0_7  ( .a(x[7:6]), .b(y[3:2]), .pp(bb0_7 ) );
BB0 U_BB0_8  ( .a(x[1:0]), .b(y[5:4]), .pp(bb0_8 ) );
BB0 U_BB0_9  ( .a(x[3:2]), .b(y[5:4]), .pp(bb0_9 ) );
BB0 U_BB0_10 ( .a(x[5:4]), .b(y[5:4]), .pp(bb0_10) );
BB0 U_BB0_11 ( .a(x[7:6]), .b(y[5:4]), .pp(bb0_11) );
BB0 U_BB0_12 ( .a(x[1:0]), .b(y[7:6]), .pp(bb0_12) );
BB0 U_BB0_13 ( .a(x[3:2]), .b(y[7:6]), .pp(bb0_13) );
BB0 U_BB0_14 ( .a(x[5:4]), .b(y[7:6]), .pp(bb0_14) );
BB0 U_BB0_15 ( .a(x[7:6]), .b(y[7:6]), .pp(bb0_15) );

BB1 U_BB1_0  ( .a(x[1:0]), .b(y[1:0]), .pp(bb1_0 ) );
BB1 U_BB1_1  ( .a(x[3:2]), .b(y[1:0]), .pp(bb1_1 ) );
BB1 U_BB1_2  ( .a(x[5:4]), .b(y[1:0]), .pp(bb1_2 ) );
BB1 U_BB1_3  ( .a(x[7:6]), .b(y[1:0]), .pp(bb1_3 ) );
BB1 U_BB1_4  ( .b(x[1:0]), .a(y[3:2]), .pp(bb1_4 ) );
BB1 U_BB1_5  ( .b(x[3:2]), .a(y[3:2]), .pp(bb1_5 ) );
BB1 U_BB1_6  ( .a(x[5:4]), .b(y[3:2]), .pp(bb1_6 ) );
BB1 U_BB1_7  ( .a(x[7:6]), .b(y[3:2]), .pp(bb1_7 ) );
BB1 U_BB1_8  ( .a(x[1:0]), .b(y[5:4]), .pp(bb1_8 ) );
BB1 U_BB1_9  ( .a(x[3:2]), .b(y[5:4]), .pp(bb1_9 ) );
BB1 U_BB1_10 ( .a(x[5:4]), .b(y[5:4]), .pp(bb1_10) );
BB1 U_BB1_11 ( .a(x[7:6]), .b(y[5:4]), .pp(bb1_11) );
BB1 U_BB1_12 ( .b(x[1:0]), .a(y[7:6]), .pp(bb1_12) );
BB1 U_BB1_13 ( .b(x[3:2]), .a(y[7:6]), .pp(bb1_13) );
BB1 U_BB1_14 ( .b(x[5:4]), .a(y[7:6]), .pp(bb1_14) );
BB1 U_BB1_15 ( .a(x[7:6]), .b(y[7:6]), .pp(bb1_15) );

BB2 U_BB2_0  ( .a(x[1:0]), .b(y[1:0]), .pp(bb2_0 ) );
BB2 U_BB2_1  ( .a(x[3:2]), .b(y[1:0]), .pp(bb2_1 ) );
BB2 U_BB2_2  ( .a(x[5:4]), .b(y[1:0]), .pp(bb2_2 ) );
BB2 U_BB2_3  ( .a(x[7:6]), .b(y[1:0]), .pp(bb2_3 ) );
BB2 U_BB2_4  ( .a(x[1:0]), .b(y[3:2]), .pp(bb2_4 ) );
BB2 U_BB2_5  ( .a(x[3:2]), .b(y[3:2]), .pp(bb2_5 ) );
BB2 U_BB2_6  ( .a(x[5:4]), .b(y[3:2]), .pp(bb2_6 ) );
BB2 U_BB2_7  ( .a(x[7:6]), .b(y[3:2]), .pp(bb2_7 ) );
BB2 U_BB2_8  ( .a(x[1:0]), .b(y[5:4]), .pp(bb2_8 ) );
BB2 U_BB2_9  ( .a(x[3:2]), .b(y[5:4]), .pp(bb2_9 ) );
BB2 U_BB2_10 ( .a(x[5:4]), .b(y[5:4]), .pp(bb2_10) );
BB2 U_BB2_11 ( .a(x[7:6]), .b(y[5:4]), .pp(bb2_11) );
BB2 U_BB2_12 ( .a(x[1:0]), .b(y[7:6]), .pp(bb2_12) );
BB2 U_BB2_13 ( .a(x[3:2]), .b(y[7:6]), .pp(bb2_13) );
BB2 U_BB2_14 ( .a(x[5:4]), .b(y[7:6]), .pp(bb2_14) );
BB2 U_BB2_15 ( .a(x[7:6]), .b(y[7:6]), .pp(bb2_15) );

assign bb_0  = (mode==2'b11) ? 4'b0 : ( (mode==2'b00)?bb2_0 :bb0_0 ) ;
assign bb_1  = (mode==2'b11) ? 4'b0 : ( (mode==2'b00)?bb2_1 :((mode==2'b01)?bb1_1:bb0_1) ) ;
assign bb_2  = (mode==2'b11) ? 4'b0 : ( (mode==2'b00)?bb2_2 :bb0_2 ) ;
assign bb_3  = (mode==2'b11) ? 4'b0 : ( (mode==2'b00)?bb2_3 :bb1_3 ) ;
assign bb_4  = (mode==2'b11) ? 4'b0 : ( (mode==2'b00)?bb2_4 :((mode==2'b01)?bb1_4:bb0_4) ) ;
assign bb_5  = (mode==2'b11) ? 4'b0 : ( (mode==2'b10)?bb0_5 :bb2_5 ) ;
assign bb_6  = (mode==2'b11) ? 4'b0 : ( (mode==2'b00)?bb2_6 :((mode==2'b01)?bb1_6:bb0_6) ) ;
assign bb_7  = (mode==2'b11) ? 4'b0 : ( (mode==2'b10)?bb0_7 :bb2_7 ) ;
assign bb_8  = (mode==2'b11) ? 4'b0 : ( (mode==2'b00)?bb2_8 :bb0_8 ) ;
assign bb_9  = (mode==2'b11) ? 4'b0 : ( (mode==2'b00)?bb2_9 :((mode==2'b01)?bb1_9:bb0_9) ) ;
assign bb_10 = (mode==2'b11) ? 4'b0 : ( (mode==2'b00)?bb2_10:bb0_10 ) ;
assign bb_11 = (mode==2'b11) ? 4'b0 : ( (mode==2'b00)?bb2_11:bb1_11 ) ;
assign bb_12 = (mode==2'b11) ? 4'b0 : ( (mode==2'b00)?bb2_12:bb1_12 ) ;
assign bb_13 = (mode==2'b11) ? 4'b0 : ( (mode==2'b10)?bb0_13:bb2_13 ) ;
assign bb_14 = (mode==2'b11) ? 4'b0 : ( (mode==2'b00)?bb2_14:bb1_14 ) ;
assign bb_15 = (mode==2'b11) ? 4'b0 : ( bb2_15 ) ;

//extend pp for shift
reg [7:0] pp_0, pp_1, pp_2, pp_3;

always @(*)begin
    
case(mode)

2'b00:begin //16*2bit*2bit
	pp_0 <= bb_0  + bb_1  + bb_4  + bb_5 ;
	pp_1 <= bb_2  + bb_3  + bb_6  + bb_7 ;
   pp_2 <= bb_8  + bb_9  + bb_12 + bb_13;
	pp_3 <= bb_10 + bb_11 + bb_14 + bb_15;
end

2'b01:begin //4*4bit*4bit
	pp_0 <= bb_0+{bb_1,2'b0}+{bb_4,2'b0}+{bb_5,4'b0};
	pp_1 <= bb_2+{bb_3,2'b0}+{bb_6,2'b0}+{bb_7,4'b0};
	pp_2 <= bb_8+{bb_9,2'b0}+{bb_12,2'b0}+{bb_13,4'b0};
	pp_3 <= bb_10+{bb_11,2'b0}+{bb_14,2'b0}+{bb_15,4'b0};
end

2'b10:begin //1*8bit*8bit
	pp_0 <= bb_0+{bb_1,2'b0}+{bb_4,2'b0}+{bb_5,4'b0};
	pp_1 <= bb_2+{bb_3,2'b0}+{bb_6,2'b0}+{bb_7,4'b0};
	pp_2 <= bb_8+{bb_9,2'b0}+{bb_12,2'b0}+{bb_13,4'b0};
	pp_3 <= bb_10+{bb_11,2'b0}+{bb_14,2'b0}+{bb_15,4'b0};
end

default:begin //
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

default:begin //
	sum <= 16'b0;
end

endcase

end


always @(posedge clk)begin
	
	mac_out <= sum;
end


endmodule
