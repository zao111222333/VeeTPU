module pp_gen #(parameter WIDTH = 26)(mpb,code,pp);
input[WIDTH-1:0] mpb;
input[2:0] code;
output[WIDTH-1:0] pp;
reg [WIDTH-1:0] pp;

always@(*) begin
case(code)
	3'b000 : pp = 0;
	3'b001 : pp = mpb;
	3'b010 : pp = mpb;
	3'b011 : pp = mpb<<1;
	3'b100 : pp = (~mpb+1)<<1;
	3'b101 : pp = ~mpb+1;
	3'b110 : pp = ~mpb+1;
	3'b111 : pp = 0;
endcase
end
 endmodule

