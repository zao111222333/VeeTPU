module pip3_processing (
     input          clk                ,
     input          rstn               ,
     input  [  1:0] mode_sel_pip2      ,
     input          i_sign_pip2        ,
     input          i_sign_AB_fp64_pip2,
     input  [ 11:0] i_exp_AB_fp64_pip2 ,
     input  [  9:0] i_exp_max_pip2     ,
     input  [106:0] i_result_pip2      , //0000011001
     input  [  6:0] i_lza_cnt          ,
     output reg [ 1:0] mode_sel_pip3   ,
     output reg [63:0] o_norm_result   
);

//clock count output
always@(posedge clk or negedge rstn)begin
    if(!rstn)begin
        mode_sel_pip3<= 2'b11;
    end
    else begin
        mode_sel_pip3<= mode_sel_pip2;
    end
end
//neg result
wire [56:0] neg_result;
assign neg_result = i_result_pip2[106] ? ~i_result_pip2[106:50]+1 : i_result_pip2[106:50];
wire [106:0] pre_shift;
assign pre_shift = {neg_result,i_result_pip2[49:0]};
//norm shift
wire [106:0] norm_shift;
wire [51:0] norm_out;
wire [1:0] exp_delta;
//assign  norm_shift = mode_sel_pip2[1] ? i_result_pip2 : i_result_pip2 << i_lza_cnt;
assign  norm_shift =pre_shift << i_lza_cnt;
//rounding
round #(106) u_round(
    .data_in(norm_shift[106:1]),
    .precision(mode_sel_pip2),
    .norm_out(norm_out),
    .exp_delta(exp_delta)
);

//exp shift add according to lza cnt 1.1121   11111.11111 0.00001.111.010110 1.1*1.1+xx 105 10.xxx
wire [ 9:0] shift_exp;
wire [11:0] shift_exp_fp64;
assign shift_exp = (i_exp_max_pip2+9>i_lza_cnt) ? (i_exp_max_pip2+9 - i_lza_cnt) : 10'h3ff;  //fp32:+9 //fp16:+9
assign shift_exp_fp64 = (i_exp_AB_fp64_pip2+1>i_lza_cnt)?(i_exp_AB_fp64_pip2+1-i_lza_cnt) : 12'hfff;

//exp correction
wire [ 9:0] cort_exp;
wire [11:0] cort_exp_fp64;
assign cort_exp =  shift_exp+exp_delta;
assign cort_exp_fp64 = shift_exp_fp64+exp_delta;

//exp normlization processing
reg [ 9:0] norm_exp_fp16;
reg [ 9:0] norm_exp_fp32;
reg [11:0] norm_exp_fp64;
always@(*)begin
    if(i_exp_max_pip2==10'b0)begin
        norm_exp_fp16 = 5'b0;
        norm_exp_fp32 = 8'b0;
    end
    else begin
        case(mode_sel_pip2)
            2'b00: norm_exp_fp16 =(cort_exp > 15) ? (cort_exp - 15) : 10'h3ff;
            2'b01: norm_exp_fp32 =(cort_exp >153) ? (cort_exp -153) : 10'h3ff; //127+26=153
        endcase
    end
end

always@(*)begin
    if(i_exp_AB_fp64_pip2==11'b0)begin
        norm_exp_fp64 = 11'b0;
    end
    else begin
        norm_exp_fp64 =(cort_exp_fp64>1023) ? (cort_exp_fp64-1023) : 12'hfff;
    end
end

//output normlization
reg [63:0] norm_result;
always@(*)begin
    case(mode_sel_pip2)
        2'b00: norm_result = {48'b0, i_sign_pip2, (norm_exp_fp16[9:5]==5'b0) ? norm_exp_fp16[4:0] : 5'h1f, norm_out[ 9:0]};
        2'b01: norm_result = {32'b0,i_sign_pip2, (norm_exp_fp32[9:8]==2'b0) ? norm_exp_fp32[7:0] : 8'hff, norm_out[22:0]};
        //2'b01: norm_result = {i_sign_pip2, (norm_exp_fp32[9:8]==2'b0) ? norm_exp_fp32[7:0] : 8'hff, norm_out[22:0], 32'b0};
        2'b10: norm_result = {i_sign_AB_fp64_pip2, norm_exp_fp64[11]? 11'h7ff : norm_exp_fp64[10:0], norm_out};
    endcase
end

//reg [63:0] o_norm_result;
always@(posedge clk or negedge rstn)begin
    if(!rstn)begin
        o_norm_result <= 64'b0; 
    end
    else begin
        o_norm_result <= norm_result;
    end
end


/*
reg [31:0] o_norm_result2;
always@(posedge clk or negedge rstn)begin
    if(!rstn)begin
        o_norm_result1 <= 32'b0; 
    end
    else if(mode_sel_pip2==2'b00)begin
        o_norm_result1 <= norm_result[31:0];
    end
    else if(clk_cnt_pip2)begin
        o_norm_result1 <= norm_result[63:32];
        o_norm_result2 <= norm_result[31:0];
    end
    else if(~clk_cnt_pip2)begin
        o_norm_result1 <= o_norm_result2;
    end
end
*/
endmodule
