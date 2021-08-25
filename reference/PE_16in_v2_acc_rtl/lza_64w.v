module lza_64w #(parameter WIDTH = 53)(
    input [WIDTH-1:0] in_01,
    input [WIDTH-1:0] in_02,
    output reg [5:0] zero_cnt,
    output reg invalid //all num are zero
);
wire [WIDTH-1:0] f_out;
wire [WIDTH-1:0] T;
wire [WIDTH-1:0] G;
wire [WIDTH-1:0] Z;
genvar i;

assign T=in_01^in_02;
assign G=in_01&in_02;
assign Z=(~in_01)&(~in_02);

assign f_out[WIDTH-1] = (~T[WIDTH-1])&T[WIDTH-2];

generate
    for(i=1; i<WIDTH-1; i=i+1) begin: f_gen
    assign f_out[i] = (T[i+1]&((G[i]&(~Z[i-1]))|(Z[i]&(~G[i-1]))))|((~T[i+1])&((Z[i]&(~Z[i-1]))|(G[i]&(~G[i-1]))));
    end
endgenerate
assign f_out[0]=0;


// Leading zero count of f_out
reg [63:0] val64;
reg [31:0] val32;
reg [15:0] val16;
reg [ 7:0] val8 ;
reg [ 3:0] val4 ;

always@(*)begin
    if((f_out == {WIDTH{1'b0}})) begin
        zero_cnt = WIDTH;
        invalid  = 1'b1;
    end
    else begin
        invalid = 1'b0;
        val64 = {f_out,{(64-WIDTH){1'b0}}};
	zero_cnt[5] = (val64[63:32] == 32'b0);
	val32 = zero_cnt[5] ? val64[31:0] : val64[63:32];
        zero_cnt[4] = (val32[31:16] == 16'b0);
        val16 = zero_cnt[4] ? val32[15:0] : val32[31:16];
        zero_cnt[3] = (val16[15:8] == 8'b0);
        val8 = zero_cnt[3] ? val16[7:0] : val16 [15:8];
        zero_cnt[2] = (val8[7:4] == 4'b0);
        val4 = zero_cnt[2] ? val8[3:0] : val8[7:4];
        zero_cnt[1] = (val4[3:2] == 2'b0);
        zero_cnt[0] = zero_cnt[1] ? ~val4[1] : ~val4[3];
    end
end
endmodule
