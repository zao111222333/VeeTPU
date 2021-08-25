
/*
mode:

2'b00:4*2bit*2bit
2'b10:2*4bit*4bit
2'b11:1*8bit*8bit

*/

module HPS_signed (

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

reg [7:0] pp_0, pp_1, pp_2, pp_3, pp_4, pp_5, pp_6, pp_7;

reg [7:0] s_pp0, s_pp1, s_pp2, s_pp3, s_pp4, s_pp5, s_pp6, s_pp7;

//wire [15:0] ex_s_pp_0, ex_s_pp_1, ex_s_pp_2, ex_s_pp_3, ex_s_pp_4, ex_s_pp_5, ex_s_pp_6, ex_s_pp_7;

// partial product generation
always @(*)begin

case(mode)

	2'b00:begin //4*2bit*2bit
      pp_0[7:6] <= y[0]?x[7:6]:2'b0;
    	pp_1[7:6] <= y[1]?x[7:6]:2'b0;
		pp_0[5:0] <= 6'b0;
		pp_1[5:0] <= 6'b0;

    	pp_2[5:4] <= y[2]?x[5:4]:2'b0;
    	pp_3[5:4] <= y[3]?x[5:4]:2'b0;
    	pp_2[7:6] <= {2{y[2]?x[5]:1'b0}};
    	pp_3[7:6] <= {2{y[3]?x[5]:1'b0}};
		pp_2[3:0] <= 4'b0;
		pp_3[3:0] <= 4'b0;
	
		pp_4[3:2] <= y[4]?x[3:2]:2'b0;
    	pp_5[3:2] <= y[5]?x[3:2]:2'b0;
		pp_4[7:4] <= {4{y[4]?x[3]:1'b0}};
		pp_5[7:4] <= {4{y[5]?x[3]:1'b0}};
		pp_4[1:0] <= 2'b0;
		pp_5[1:0] <= 2'b0;

    	pp_6[1:0] <= y[6]?x[1:0]:2'b0;
    	pp_7[1:0] <= y[7]?x[1:0]:2'b0;
		pp_6[7:2] <= {6{y[6]?x[1]:1'b0}};
		pp_7[7:2] <= {6{y[7]?x[1]:1'b0}};
   end
	
   2'b10:begin //2*4bit*4bit 	
		pp_0[7:4] <= y[0]?x[7:4]:4'b0;
		pp_1[7:4] <= y[1]?x[7:4]:4'b0;
		pp_2[7:4] <= y[2]?x[7:4]:4'b0;
		pp_3[7:4] <= y[3]?x[7:4]:4'b0;
		pp_0[3:0] <= 4'b0;
		pp_1[3:0] <= 4'b0;
		pp_2[3:0] <= 4'b0;
		pp_3[3:0] <= 4'b0;
	
		pp_4[3:0] <= y[4]?x[3:0]:4'b0;
		pp_5[3:0] <= y[5]?x[3:0]:4'b0;
		pp_6[3:0] <= y[6]?x[3:0]:4'b0;
		pp_7[3:0] <= y[7]?x[3:0]:4'b0;
		pp_4[7:4] <= {4{y[4]?x[3]:1'b0}};
		pp_5[7:4] <= {4{y[5]?x[3]:1'b0}};
		pp_6[7:4] <= {4{y[6]?x[3]:1'b0}};
		pp_7[7:4] <= {4{y[7]?x[3]:1'b0}};

	end

	2'b11:begin 
		pp_0[7:0] <= y[0]?x[7:0]:8'b0;
		pp_1[7:0] <= y[1]?x[7:0]:8'b0;
		pp_2[7:0] <= y[2]?x[7:0]:8'b0;
		pp_3[7:0] <= y[3]?x[7:0]:8'b0;
		pp_4[7:0] <= y[4]?x[7:0]:8'b0;
		pp_5[7:0] <= y[5]?x[7:0]:8'b0;
		pp_6[7:0] <= y[6]?x[7:0]:8'b0;
		pp_7[7:0] <= y[7]?x[7:0]:8'b0;
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

//inverse and plus one
always @(*)begin

case(mode)
	2'b00: begin  //2bit*2bit
		s_pp0 <= pp_0;
		s_pp2 <= pp_2;
		s_pp4 <= pp_4;
		s_pp6 <= pp_6;
		s_pp1 <= (~pp_1)+1'b1;
		s_pp3 <= (~pp_3)+1'b1;
		s_pp5 <= (~pp_5)+1'b1;
		s_pp7 <= (~pp_7)+1'b1;
	end

	2'b10: begin //4bit*4bit
	   s_pp0 <= pp_0;		      
	   s_pp1 <= pp_1;		      
	   s_pp2 <= pp_2;		      
	   s_pp3 <= (~pp_3)+1'b1;		      
	   s_pp4 <= pp_4;		      
	   s_pp5 <= pp_5;		      
	   s_pp6 <= pp_6;		      
	   s_pp7 <= (~pp_7)+1'b1;		      
	end

	2'b11: begin //8bit*8bit
		s_pp0 <= pp_0;
		s_pp1 <= pp_1;
		s_pp2 <= pp_2;
		s_pp3 <= pp_3;
		s_pp4 <= pp_4;
		s_pp5 <= pp_5;
		s_pp6 <= pp_6;
		s_pp7 <= (~pp_7)+1'b1;
		
	end

	default: begin
		s_pp0 <= pp_0;
		s_pp1 <= pp_1;
		s_pp2 <= pp_2;
		s_pp3 <= pp_3;
		s_pp4 <= pp_4;
		s_pp5 <= pp_5;
		s_pp6 <= pp_6;
		s_pp7 <= pp_7;
	end

endcase
end

//extend bitwise to 16bit
//assign ex_s_pp_0[15:0] = {{8{s_pp0[7]}}, s_pp0[7:0]      };
//assign ex_s_pp_1[15:0] = {{7{s_pp1[7]}}, s_pp1[7:0], 1'b0};
//assign ex_s_pp_2[15:0] = {{6{s_pp2[7]}}, s_pp2[7:0], 2'b0};
//assign ex_s_pp_3[15:0] = {{5{s_pp3[7]}}, s_pp3[7:0], 3'b0};
//assign ex_s_pp_4[15:0] = {{4{s_pp4[7]}}, s_pp4[7:0], 4'b0};
//assign ex_s_pp_5[15:0] = {{3{s_pp5[7]}}, s_pp5[7:0], 5'b0};
//assign ex_s_pp_6[15:0] = {{2{s_pp6[7]}}, s_pp6[7:0], 6'b0};
//assign ex_s_pp_7[15:0] = {{1{s_pp7[7]}}, s_pp7[7:0], 7'b0};


wire [15:0] sum;
wire [15:0] sum0, sum1, sum2, sum3;
wire [15:0] sum01, sum23;

//assign sum0 = ex_s_pp_0 + ex_s_pp_1;
//assign sum1 = ex_s_pp_2 + ex_s_pp_3;
//assign sum2 = ex_s_pp_4 + ex_s_pp_5;
//assign sum3 = ex_s_pp_6 + ex_s_pp_7;

assign sum0 = {{8{s_pp0[7]}}, s_pp0[7:0]      } + {{7{s_pp1[7]}}, s_pp1[7:0], 1'b0};
assign sum1 = {{6{s_pp2[7]}}, s_pp2[7:0], 2'b0} + {{5{s_pp3[7]}}, s_pp3[7:0], 3'b0};
assign sum2 = {{4{s_pp4[7]}}, s_pp4[7:0], 4'b0} + {{3{s_pp5[7]}}, s_pp5[7:0], 5'b0};
assign sum3 = {{2{s_pp6[7]}}, s_pp6[7:0], 6'b0} + {{1{s_pp7[7]}}, s_pp7[7:0], 7'b0};

assign sum01 = sum0 + sum1;
assign sum23 = sum2 + sum3;

assign sum = sum01 + sum23;

//assign sum = ex_s_pp_0 + ex_s_pp_1 + ex_s_pp_2 + ex_s_pp_3 + ex_s_pp_4 + ex_s_pp_5 + ex_s_pp_6 + ex_s_pp_1; 

always @(posedge clk)begin
	
	mac_out <= sum;
	
end

endmodule
