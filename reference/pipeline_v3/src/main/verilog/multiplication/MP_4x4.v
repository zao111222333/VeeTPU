// syn MP_4x4 -pl src/main/verilog/multiplication/MP_4x4.v src/main/verilog/multiplication/HPS_4x4.v
module MP_4x4 (
    input [7:0] x,
    input [7:0] y,
    input [1:0] mode,
    input clk,

   output reg [15:0] mac_out 
);

reg [7:0] i_x, i_y;
wire mode_4x4;
wire [7:0] bb0, bb1, bb2, bb3;

always @(posedge clk)begin
	
	i_x <= x;
	i_y <= y;

end

HPS_4x4 U_HPS_4x4_0 (

	.x(i_x[3:0]),
	.y(i_y[3:0]),
	.mode(mode_4x4),
	.mac_out(bb0)
);

HPS_4x4 U_HPS_4x4_1 (

	.x(i_x[7:4]),
	.y(i_y[3:0]),
	.mode(mode_4x4),
	.mac_out(bb1)
);

HPS_4x4 U_HPS_4x4_2 (

	.x(i_x[3:0]),
	.y(i_y[7:4]),
	.mode(mode_4x4),
	.mac_out(bb2)
);

HPS_4x4 U_HPS_4x4_3 (

	.x(i_x[7:4]),
	.y(i_y[7:4]),
	.mode(mode_4x4),
	.mac_out(bb3)
);

assign mode_4x4 = mode[1] ;

reg [15:0] sum0, sum1;
wire [15:0] sum;

always @(*)begin
	case(mode)
		2'b00:begin
			sum0 <= bb0 + bb1;
			sum1 <= bb2 + bb3;
		end

		2'b10:begin
			sum0 <= bb0 + bb1;
			sum1 <= bb2 + bb3;
		end

		2'b11:begin
			sum0 <= bb0 + {bb1,4'b0} ;
			sum1 <= {bb2,4'b0} + {bb3,8'b0} ;
		end

		default:begin
			sum0 <= 8'b0;
			sum1 <= 8'b0;
		end


	endcase
end

assign sum = sum0 + sum1;

always @(*)begin
	mac_out <= sum;
end


endmodule 
