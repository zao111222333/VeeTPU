module round #(parameter WIDTH=106)(
    input [WIDTH-1:0] data_in,
    input [1:0] precision,
    output reg [51:0] norm_out,
    output reg [1:0] exp_delta
);

localparam FP64 = 2'b10;
localparam FP32 = 2'b01;
localparam FP16 = 2'b00;

wire [105:0] man_64 = data_in[105:0];
wire [47:0]  man_32 = data_in[105:58];
wire [23:0]  man_16 = data_in[105:82];
reg [52:0] norm_64;
reg [23:0] norm_32;
reg [10:0] norm_16;

//man_64 norm
always@(*)begin
    if(man_64[105])begin
        norm_64 = man_64[104:53]+man_64[52];
    end
    else if(man_64[104])begin
        norm_64 = man_64[103:52]+man_64[51];
    end
    else begin
        norm_64 = 53'b0;
    end
end

//man_32 norm
always@(*)begin
    if(man_32[47])begin
        norm_32 = man_32[46:24]+man_32[23];
    end
    else if(man_32[46])begin
        norm_32 = man_32[45:23]+man_32[22];
    end
    else begin
        norm_32 = 24'b0;
    end
end

//man_16 norm
always@(*)begin
    if(man_16[23])begin
        norm_16 = man_16[22:13]+man_16[12];
    end
    else if(man_16[22])begin
        norm_16 = man_16[21:12]+man_16[11];
    end
    else begin
        norm_16 = 11'b0;
    end
end

always@(*)begin
    case(precision)
        FP64: norm_out = norm_64[52] ? norm_64[52:1] : norm_64[51:0];
	FP32: norm_out = norm_32[23] ? {29'b0,norm_32[23:1]} : {29'b0,norm_32[22:0]};
	FP16: norm_out = norm_16[10] ? {42'b0,norm_16[10:1]} : {42'b0,norm_16[ 9:0]};
    endcase
end
// 105 52 exp_delta
// 0   0   00
// 0   1   01
// 1   0   +1
// 1   1   +2
always@(*)begin
    case(precision)
        FP64: exp_delta = {(man_64[105]&norm_64[52]),(man_64[105]|norm_64[52])};
	     FP32: exp_delta = {(man_32[ 47]&norm_32[23]),(man_32[ 47]|norm_32[23])};
	     FP16: exp_delta = {(man_16[ 23]&norm_16[10]),(man_16[ 23]|norm_16[10])};
    endcase
end

endmodule
