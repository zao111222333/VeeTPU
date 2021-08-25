module HPS_4x4 (

	input [3:0] x,
	input [3:0] y,
	input  mode,

	output [7:0] mac_out
);

        reg [3:0] pp0, pp1, pp2, pp3;

	always @(*)begin
		case(mode)
			1'b0:begin
				pp0[3:2] <= y[0]?x[3:2]:2'b0;
				pp1[3:2] <= y[1]?x[3:2]:2'b0;
				pp2[1:0] <= y[2]?x[1:0]:2'b0;
				pp3[1:0] <= y[3]?x[1:0]:2'b0;

				pp0[1:0] <= 2'b0;
				pp1[1:0] <= 2'b0;
				pp2[3:2] <= 2'b0;
				pp3[3:2] <= 2'b0;
			end

			1'b1:begin
				pp0[3:0] <= y[0]?x[3:0]:4'b0;
				pp1[3:0] <= y[1]?x[3:0]:4'b0;
				pp2[3:0] <= y[2]?x[3:0]:4'b0;
				pp3[3:0] <= y[3]?x[3:0]:4'b0;
			end

			default:begin
                        	pp0[3:0] <= 4'b0;
				pp1[3:0] <= 4'b0;
				pp2[3:0] <= 4'b0;
				pp3[3:0] <= 4'b0;
			end

		endcase
	end

wire [7:0] sum0, sum1;

assign sum0 = pp0 + {pp0,1'b0};
assign sum1 = {pp2,2'b0} + {pp3,3'b0};

assign mac_out = sum0 + sum1;


endmodule 
