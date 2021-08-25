/******input declare***********/
//i_A[63] is the input A's sign bit of fp16, fp32 and fp64
//i_A[62:52] including input A's 5-bit([56:52]) exp of fp16, 8-bit([59:52]) exp of fp32 and 11-bit exp of fp64
//i_A[51: 0] including input A's 10-bit([9:0]) mantissa of fp16, 23-bit([22:0]) mantissa of fp32 and 52-bit mantissa of fp64

//i_B[63] is the input B's sign bit of fp16, fp32 and fp64
//i_B[62:52] including input B's 5-bit([56:52]) exp of fp16, 8-bit([59:52]) exp of fp32 and 11-bit of fp64
//i_B[51: 0] including input B's 10-bit([9:0]) mantissa of fp16, 23-bit([22:0]) mantissa of fp32 and 52-bit mantissa of fp64

module fp_acc(
    input  [63:0] i_A     , 
    input  [63:0] i_B     ,
    input  [ 1:0] mode_sel,
    output [63:0] o_r
);

//input pre-process
reg sign_A;
reg sign_B;
reg [11:0] exp_A;
reg [11:0] exp_B;
reg [51:0] man_A;
reg [51:0] man_B;
always@(*)begin
    case(mode_sel)
        2'b00: begin
                   sign_A = i_A[15];
                   sign_B = i_B[15];
                   exp_A  = {6'b0,i_A[14:10]};
                   exp_B  = {6'b0,i_B[14:10]};
                   man_A = {i_A[9:0],42'b0};
                   man_B = {i_B[9:0],42'b0};
               end
        2'b01: begin
                   sign_A = i_A[31];
                   sign_B = i_B[31];
                   exp_A  = {3'b0,i_A[30:23]};
                   exp_B  = {3'b0,i_B[30:23]};
                   man_A = {i_A[22:0],29'b0};
                   man_B = {i_B[22:0],29'b0};
               end

        2'b10: begin
                   sign_A = i_A[63];
                   sign_B = i_B[63];
                   exp_A  = i_A[62:52];
                   exp_B  = i_B[62:52];
                   man_A = i_A[51:0];
                   man_B = i_B[51:0];
               end
        default:begin
                   sign_A = 1'b0;
                   sign_B = 1'b0;
                   exp_A  = 11'b0;
                   exp_B  = 11'b0;
                    man_A = 0;
                    man_B = 0;
                end
    endcase
end

//exp compare
wire [10:0] exp_max;
wire [10:0] exp_diff0;
wire [10:0] exp_diff1;
assign exp_max = exp_A > exp_B ? exp_A : exp_B;
assign exp_diff0 = exp_max-exp_A;
assign exp_diff1 = exp_max-exp_B;

//mantissa process
wire fp_imbitA; //implicit leading bit of A for fp16, fp32 and fp64
wire fp_imbitB; //implicit leading bit of A for fp16, fp32 and fp64
assign fp_imbitA = |exp_A;
assign fp_imbitB = |exp_B;
wire [53:0] neg_man_A;
wire [53:0] neg_man_B;
csla #(53, 7, 7, 4) u_csla00(~{fp_imbitA,man_A}, 53'b1, neg_man_A);
csla #(53, 7, 7, 4) u_csla01(~{fp_imbitB,man_B}, 53'b1, neg_man_B);

wire [52:0] com_man_A;
wire [52:0] com_man_B;
assign com_man_A = sign_A? neg_man_A[52:0]:{fp_imbitA,man_A};
assign com_man_B = sign_B? neg_man_B[52:0]:{fp_imbitB,man_B};

//mantissa accumulate
wire [55:0] add_result;
wire [54:0] acc_in0;
wire [54:0] acc_in1;
assign acc_in0 = {{2{sign_A}},com_man_A}>>>exp_diff0;
assign acc_in1 = {{2{sign_B}},com_man_B}>>>exp_diff1;
csla #(55, 7, 7, 6) u_csla02(acc_in0, acc_in1, add_result);

//leading zaro counter (lza)
wire [5:0] zero_cnt;
wire invalid;
lza_64w #(55) u_lza_64w(acc_in0,acc_in1,zero_cnt,invalid);
//get sign of A add B
wire sign_AaddB = add_result[54];

//calcaulate negtive add_result
wire [55:0] neg_add_result;
csla #(55, 7, 7, 6) u_csla03(~add_result[54:0],55'b1, neg_add_result);

//chose add_result
wire [54:0] sc_add_result;
assign sc_add_result = sign_AaddB ? neg_add_result[54:0] : add_result[54:0];

//norm shift
wire [54:0] norm_man_shift;
assign norm_man_shift = sc_add_result << zero_cnt;

//exp shift add according zero cnount
reg [11:0] exp_adjs;
always@(*)begin
    if(exp_max==11'h7ff)begin
        exp_adjs =12'h800;
    end
    else if(exp_max==11'h000)begin
        exp_adjs =12'h000;
    end
    else begin
        exp_adjs = (exp_max+1>zero_cnt)? (exp_max+1-zero_cnt) : 12'h800;
    end
end

//mantissa round
wire [51:0] man_round_fp64;
wire [22:0] man_round_fp32;
wire [ 9:0] man_round_fp16;
assign man_round_fp64 = norm_man_shift[54] ?  norm_man_shift[53:2] : norm_man_shift[52:1];
assign man_round_fp32 = man_round_fp64[51:29];
assign man_round_fp16 = man_round_fp64[51:42];

//exp corrext
wire [11:0] exp_cort;
assign exp_cort = exp_adjs + norm_man_shift[54];

reg [63:0] norm_result;
always@(*)begin
    case(mode_sel)
        2'b00: norm_result = {48'b0,sign_AaddB, (exp_cort[11:5]==8'b0) ? exp_cort[4:0] : 5'h1f         , man_round_fp16};
        2'b01: norm_result = {32'b0,sign_AaddB, (exp_cort[11:8]==5'b0) ? exp_cort[7:0] : 8'hff         , man_round_fp32};
        2'b10: norm_result = {      sign_AaddB,  exp_cort[11]          ? 11'h7ff       : exp_cort[10:0], man_round_fp64};
      default: norm_result = 0;
    endcase
end

assign o_r = norm_result;

endmodule
