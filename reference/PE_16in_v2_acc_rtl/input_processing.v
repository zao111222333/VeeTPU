module input_processing(
    input         clk      ,
    input         rstn     ,
    input [255:0] A        ,
    input [255:0] B        ,
    input [1:0]   mode_sel , //2'b00:FP16; 2'b01:FP32; 2'b10:FP64; 2'b11: set zero
    //output
    output reg [15:0]o_sign_AB ,//sign A of fp16 and fp32; 
    //output reg [15:0]o_sign_B ,//sign B of fp16 and fp32; 
    output reg   o_sign_AB_fp64, //sign AB for FP64
    //output reg   o_sign_B_fp64, //sign B for FP64
    
    output reg [11:0] o_exp_AB_fp64, //exp AB for FP64
    output reg [9:0]  o_exp_AB0    , //exp AB for FP64,FP32,FP16
    output reg [9:0]  o_exp_AB1    , //exp AB for FP64,FP32,FP16
    output reg [9:0]  o_exp_AB2    , //exp AB for FP64,FP32,FP16
    output reg [9:0]  o_exp_AB3    , //exp AB for FP64,FP32,FP16
    output reg [9:0]  o_exp_AB4    , //exp AB for FP64,FP32,FP16
    output reg [9:0]  o_exp_AB5    , //exp AB for FP64,FP32,FP16
    output reg [9:0]  o_exp_AB6    , //exp AB for FP64,FP32,FP16
    output reg [9:0]  o_exp_AB7    , //exp AB for FP64,FP32,FP16
    output reg [9:0]  o_exp_AB8    , //exp AB for FP64,FP32,FP16
    output reg [9:0]  o_exp_AB9    , //exp AB for FP64,FP32,FP16
    output reg [9:0]  o_exp_ABA    , //exp AB for FP64,FP32,FP16
    output reg [9:0]  o_exp_ABB    , //exp AB for FP64,FP32,FP16
    output reg [9:0]  o_exp_ABC    , //exp AB for FP64,FP32,FP16
    output reg [9:0]  o_exp_ABD    , //exp AB for FP64,FP32,FP16
    output reg [9:0]  o_exp_ABE    , //exp AB for FP64,FP32,FP16
    output reg [9:0]  o_exp_ABF    , //exp AB for FP64,FP32,FP16
    /*
    output reg [10:0] o_exp_B_fp64, //exp B for FP64
    output reg [8:0]  o_exp_B0    , //exp B for FP64,FP32,FP16
    output reg [8:0]  o_exp_B1    , //exp B for FP64,FP32,FP16
    output reg [8:0]  o_exp_B2    , //exp B for FP64,FP32,FP16
    output reg [8:0]  o_exp_B3    , //exp B for FP64,FP32,FP16
    output reg [8:0]  o_exp_B4    , //exp B for FP64,FP32,FP16
    output reg [8:0]  o_exp_B5    , //exp B for FP64,FP32,FP16
    output reg [8:0]  o_exp_B6    , //exp B for FP64,FP32,FP16
    output reg [8:0]  o_exp_B7    , //exp B for FP64,FP32,FP16
    output reg [8:0]  o_exp_B8    , //exp B for FP64,FP32,FP16
    output reg [8:0]  o_exp_B9    , //exp A for FP64,FP32,FP16
    output reg [8:0]  o_exp_BA    , //exp A for FP64,FP32,FP16
    output reg [8:0]  o_exp_BB    , //exp A for FP64,FP32,FP16
    output reg [8:0]  o_exp_BC    , //exp A for FP64,FP32,FP16
    output reg [8:0]  o_exp_BD    , //exp A for FP64,FP32,FP16
    output reg [8:0]  o_exp_BE    , //exp A for FP64,FP32,FP16
    output reg [8:0]  o_exp_BF    , //exp A for FP64,FP32,FP16
    */
    output reg [12:0] o_man_A0 , //mantisa A for FP64,FP32,FP16
    output reg [12:0] o_man_A1 , //mantisa A for FP64,FP32,FP16
    output reg [12:0] o_man_A2 , //mantisa A for FP64,FP32,FP16
    output reg [12:0] o_man_A3 , //mantisa A for FP64,FP32,FP16
    output reg [12:0] o_man_A4 , //mantisa A for FP64,FP32,FP16
    output reg [12:0] o_man_A5 , //mantisa A for FP64,FP32,FP16
    output reg [12:0] o_man_A6 , //mantisa A for FP64,FP32,FP16
    output reg [12:0] o_man_A7 , //mantisa A for FP64,FP32,FP16
    output reg [12:0] o_man_A8 , //mantisa A for FP64,FP32,FP16
    output reg [12:0] o_man_A9 , //mantisa A for FP64,FP32,FP16
    output reg [12:0] o_man_AA , //mantisa A for FP64,FP32,FP16
    output reg [12:0] o_man_AB , //mantisa A for FP64,FP32,FP16
    output reg [12:0] o_man_AC , //mantisa A for FP64,FP32,FP16
    output reg [12:0] o_man_AD , //mantisa A for FP64,FP32,FP16
    output reg [12:0] o_man_AE , //mantisa A for FP64,FP32,FP16
    output reg [12:0] o_man_AF , //mantisa A for FP64,FP32,FP16
    output reg        o_fp64_imbitA, 
    output reg [12:0] o_man_B0 , //mantisa B for FP64,FP32,FP16
    output reg [12:0] o_man_B1 , //mantisa B for FP64,FP32,FP16
    output reg [12:0] o_man_B2 , //mantisa B for FP64,FP32,FP16
    output reg [12:0] o_man_B3 , //mantisa B for FP64,FP32,FP16
    output reg [12:0] o_man_B4 , //mantisa B for FP64,FP32,FP16
    output reg [12:0] o_man_B5 , //mantisa B for FP64,FP32,FP16
    output reg [12:0] o_man_B6 , //mantisa B for FP64,FP32,FP16
    output reg [12:0] o_man_B7 , //mantisa B for FP64,FP32,FP16
    output reg [12:0] o_man_B8 , //mantisa B for FP64,FP32,FP16
    output reg [12:0] o_man_B9 , //mantisa B for FP64,FP32,FP16
    output reg [12:0] o_man_BA , //mantisa B for FP64,FP32,FP16
    output reg [12:0] o_man_BB , //mantisa B for FP64,FP32,FP16
    output reg [12:0] o_man_BC , //mantisa B for FP64,FP32,FP16
    output reg [12:0] o_man_BD , //mantisa B for FP64,FP32,FP16
    output reg [12:0] o_man_BE , //mantisa B for FP64,FP32,FP16
    output reg [12:0] o_man_BF , //mantisa B for FP64,FP32,FP16
    output reg        o_fp64_imbitB, 

    output reg [1:0] mode_sel_pip0 //mode sel output
);

//implicit leading processing
    //FP16
    wire fp16_imbitA0;
    wire fp16_imbitA1;
    wire fp16_imbitA2;
    wire fp16_imbitA3;
    wire fp16_imbitA4;
    wire fp16_imbitA5;
    wire fp16_imbitA6;
    wire fp16_imbitA7;
    wire fp16_imbitA8;
    wire fp16_imbitA9;
    wire fp16_imbitAA;
    wire fp16_imbitAB;
    wire fp16_imbitAC;
    wire fp16_imbitAD;
    wire fp16_imbitAE;
    wire fp16_imbitAF;
    wire fp16_imbitB0;
    wire fp16_imbitB1;
    wire fp16_imbitB2;
    wire fp16_imbitB3;
    wire fp16_imbitB4;
    wire fp16_imbitB5;
    wire fp16_imbitB6;
    wire fp16_imbitB7;
    wire fp16_imbitB8;
    wire fp16_imbitB9;
    wire fp16_imbitBA;
    wire fp16_imbitBB;
    wire fp16_imbitBC;
    wire fp16_imbitBD;
    wire fp16_imbitBE;
    wire fp16_imbitBF;
    assign fp16_imbitA0 = |A[ 14: 10];
    assign fp16_imbitA1 = |A[ 30: 26];
    assign fp16_imbitA2 = |A[ 46: 42];
    assign fp16_imbitA3 = |A[ 62: 58];
    assign fp16_imbitA4 = |A[ 78: 74];
    assign fp16_imbitA5 = |A[ 94: 90];
    assign fp16_imbitA6 = |A[110:106];
    assign fp16_imbitA7 = |A[126:122];
    assign fp16_imbitA8 = |A[142:138];
    assign fp16_imbitA9 = |A[158:154];
    assign fp16_imbitAA = |A[174:170];
    assign fp16_imbitAB = |A[190:186];
    assign fp16_imbitAC = |A[206:202];
    assign fp16_imbitAD = |A[222:218];
    assign fp16_imbitAE = |A[238:234];
    assign fp16_imbitAF = |A[254:250];
    assign fp16_imbitB0 = |B[ 14: 10];
    assign fp16_imbitB1 = |B[ 30: 26];
    assign fp16_imbitB2 = |B[ 46: 42];
    assign fp16_imbitB3 = |B[ 62: 58];
    assign fp16_imbitB4 = |B[ 78: 74];
    assign fp16_imbitB5 = |B[ 94: 90];
    assign fp16_imbitB6 = |B[110:106];
    assign fp16_imbitB7 = |B[126:122];
    assign fp16_imbitB8 = |B[142:138];
    assign fp16_imbitB9 = |B[158:154];
    assign fp16_imbitBA = |B[174:170];
    assign fp16_imbitBB = |B[190:186];
    assign fp16_imbitBC = |B[206:202];
    assign fp16_imbitBD = |B[222:218];
    assign fp16_imbitBE = |B[238:234];
    assign fp16_imbitBF = |B[254:250];

    //FP32
    wire fp32_imbitA0;
    wire fp32_imbitA1;
    wire fp32_imbitA2;
    wire fp32_imbitA3;
    wire fp32_imbitB0;
    wire fp32_imbitB1;
    wire fp32_imbitB2;
    wire fp32_imbitB3;
    assign fp32_imbitA0 = |A[ 30: 23];
    assign fp32_imbitA1 = |A[ 62: 55];
    assign fp32_imbitA2 = |A[ 94: 87];
    assign fp32_imbitA3 = |A[126:119];
    assign fp32_imbitB0 = |B[ 30: 23];
    assign fp32_imbitB1 = |B[ 62: 55];
    assign fp32_imbitB2 = |B[ 94: 87];
    assign fp32_imbitB3 = |B[126:119];

    //FP32
    wire fp64_imbitA;
    wire fp64_imbitB;
    assign fp64_imbitA = |A[62:52];
    assign fp64_imbitB = |B[62:52];

//subnorm processing
wire [15:0] fp16Aiszero;
wire [15:0] fp16Biszero;
wire [ 3:0] fp32Aiszero;
wire [ 3:0] fp32Biszero;
wire        fp64Aiszero;
wire        fp64Biszero;

assign fp16Aiszero[ 0] = ({fp16_imbitA0, A[  9:  0]} == 11'b0);
assign fp16Aiszero[ 1] = ({fp16_imbitA1, A[ 25: 16]} == 11'b0);
assign fp16Aiszero[ 2] = ({fp16_imbitA2, A[ 41: 32]} == 11'b0);
assign fp16Aiszero[ 3] = ({fp16_imbitA3, A[ 57: 48]} == 11'b0);
assign fp16Aiszero[ 4] = ({fp16_imbitA4, A[ 73: 64]} == 11'b0);
assign fp16Aiszero[ 5] = ({fp16_imbitA5, A[ 89: 80]} == 11'b0);
assign fp16Aiszero[ 6] = ({fp16_imbitA6, A[105: 96]} == 11'b0);
assign fp16Aiszero[ 7] = ({fp16_imbitA7, A[121:112]} == 11'b0);
assign fp16Aiszero[ 8] = ({fp16_imbitA8, A[137:128]} == 11'b0);
assign fp16Aiszero[ 9] = ({fp16_imbitA9, A[153:144]} == 11'b0);
assign fp16Aiszero[10] = ({fp16_imbitAA, A[169:160]} == 11'b0);
assign fp16Aiszero[11] = ({fp16_imbitAB, A[185:176]} == 11'b0);
assign fp16Aiszero[12] = ({fp16_imbitAC, A[201:192]} == 11'b0);
assign fp16Aiszero[13] = ({fp16_imbitAD, A[217:208]} == 11'b0);
assign fp16Aiszero[14] = ({fp16_imbitAE, A[233:224]} == 11'b0);
assign fp16Aiszero[15] = ({fp16_imbitAF, A[249:240]} == 11'b0);

assign fp16Biszero[ 0] = ({fp16_imbitB0, B[  9:  0]} == 11'b0);
assign fp16Biszero[ 1] = ({fp16_imbitB1, B[ 25: 16]} == 11'b0);
assign fp16Biszero[ 2] = ({fp16_imbitB2, B[ 41: 32]} == 11'b0);
assign fp16Biszero[ 3] = ({fp16_imbitB3, B[ 57: 48]} == 11'b0);
assign fp16Biszero[ 4] = ({fp16_imbitB4, B[ 73: 64]} == 11'b0);
assign fp16Biszero[ 5] = ({fp16_imbitB5, B[ 89: 80]} == 11'b0);
assign fp16Biszero[ 6] = ({fp16_imbitB6, B[105: 96]} == 11'b0);
assign fp16Biszero[ 7] = ({fp16_imbitB7, B[121:112]} == 11'b0);
assign fp16Biszero[ 8] = ({fp16_imbitB8, B[137:128]} == 11'b0);
assign fp16Biszero[ 9] = ({fp16_imbitB9, B[153:144]} == 11'b0);
assign fp16Biszero[10] = ({fp16_imbitBA, B[169:160]} == 11'b0);
assign fp16Biszero[11] = ({fp16_imbitBB, B[185:176]} == 11'b0);
assign fp16Biszero[12] = ({fp16_imbitBC, B[201:192]} == 11'b0);
assign fp16Biszero[13] = ({fp16_imbitBD, B[217:208]} == 11'b0);
assign fp16Biszero[14] = ({fp16_imbitBE, B[233:224]} == 11'b0);
assign fp16Biszero[15] = ({fp16_imbitBF, B[249:240]} == 11'b0);

assign fp32Aiszero[0] = ({fp32_imbitA0, A[ 22:  0]} == 24'b0);
assign fp32Aiszero[1] = ({fp32_imbitA1, A[ 54: 32]} == 24'b0);
assign fp32Aiszero[2] = ({fp32_imbitA2, A[ 86: 64]} == 24'b0);
assign fp32Aiszero[3] = ({fp32_imbitA3, A[118: 96]} == 24'b0);

assign fp32Biszero[0] = ({fp32_imbitB0, B[ 22:  0]} == 24'b0);
assign fp32Biszero[1] = ({fp32_imbitB1, B[ 54: 32]} == 24'b0);
assign fp32Biszero[2] = ({fp32_imbitB2, B[ 86: 64]} == 24'b0);
assign fp32Biszero[3] = ({fp32_imbitB3, B[118: 96]} == 24'b0);

assign fp64Aiszero    = ({fp64_imbitA , A[ 51:  0]} == 53'b0);
assign fp64Biszero    = ({fp64_imbitB , B[ 51:  0]} == 53'b0);





//sign processing
always@(posedge clk)begin
    case(mode_sel)
        2'b00:begin
                  o_sign_AB[ 0] <= fp16Biszero[ 0]|fp16Aiszero[ 0] ? 1'b0 : A[ 15]^B[ 15];
                  o_sign_AB[ 1] <= fp16Biszero[ 1]|fp16Aiszero[ 1] ? 1'b0 : A[ 31]^B[ 31];
                  o_sign_AB[ 2] <= fp16Biszero[ 2]|fp16Aiszero[ 2] ? 1'b0 : A[ 47]^B[ 47];
                  o_sign_AB[ 3] <= fp16Biszero[ 3]|fp16Aiszero[ 3] ? 1'b0 : A[ 63]^B[ 63];
                  o_sign_AB[ 4] <= fp16Biszero[ 4]|fp16Aiszero[ 4] ? 1'b0 : A[ 79]^B[ 79];
                  o_sign_AB[ 5] <= fp16Biszero[ 5]|fp16Aiszero[ 5] ? 1'b0 : A[ 95]^B[ 95];
                  o_sign_AB[ 6] <= fp16Biszero[ 6]|fp16Aiszero[ 6] ? 1'b0 : A[111]^B[111];
                  o_sign_AB[ 7] <= fp16Biszero[ 7]|fp16Aiszero[ 7] ? 1'b0 : A[127]^B[127];
                  o_sign_AB[ 8] <= fp16Biszero[ 8]|fp16Aiszero[ 8] ? 1'b0 : A[143]^B[143];
                  o_sign_AB[ 9] <= fp16Biszero[ 9]|fp16Aiszero[ 9] ? 1'b0 : A[159]^B[159];
                  o_sign_AB[10] <= fp16Biszero[10]|fp16Aiszero[10] ? 1'b0 : A[175]^B[175];
                  o_sign_AB[11] <= fp16Biszero[11]|fp16Aiszero[11] ? 1'b0 : A[191]^B[191];
                  o_sign_AB[12] <= fp16Biszero[12]|fp16Aiszero[12] ? 1'b0 : A[207]^B[207];
                  o_sign_AB[13] <= fp16Biszero[13]|fp16Aiszero[13] ? 1'b0 : A[223]^B[223];
                  o_sign_AB[14] <= fp16Biszero[14]|fp16Aiszero[14] ? 1'b0 : A[239]^B[239];
                  o_sign_AB[15] <= fp16Biszero[15]|fp16Aiszero[15] ? 1'b0 : A[255]^B[255];
                  o_sign_AB_fp64 <= 1'b0;
                 // o_sign_A <= {A[255],A[239],A[223],A[207],A[191],A[175],A[159],A[143],A[127],A[111],A[95],A[79],A[63],A[47],A[31],A[15]};
                 // o_sign_B <= {B[255],B[239],B[223],B[207],B[191],B[175],B[159],B[143],B[127],B[111],B[95],B[79],B[63],B[47],B[31],B[15]};
                 // o_sign_A_fp64 <= 1'b0;
                 // o_sign_B_fp64 <= 1'b0;
              end
        2'b01:begin
                  o_sign_AB[ 0] <= fp32Biszero[0]|fp32Aiszero[0] ? 1'b0 : A[ 31]^B[ 31];
                  o_sign_AB[ 1] <= fp32Biszero[0]|fp32Aiszero[0] ? 1'b0 : A[ 31]^B[ 31];
                  o_sign_AB[ 2] <= fp32Biszero[0]|fp32Aiszero[0] ? 1'b0 : A[ 31]^B[ 31];
                  o_sign_AB[ 3] <= fp32Biszero[0]|fp32Aiszero[0] ? 1'b0 : A[ 31]^B[ 31];
                  o_sign_AB[ 4] <= fp32Biszero[1]|fp32Aiszero[1] ? 1'b0 : A[ 63]^B[ 63];
                  o_sign_AB[ 5] <= fp32Biszero[1]|fp32Aiszero[1] ? 1'b0 : A[ 63]^B[ 63];
                  o_sign_AB[ 6] <= fp32Biszero[1]|fp32Aiszero[1] ? 1'b0 : A[ 63]^B[ 63];
                  o_sign_AB[ 7] <= fp32Biszero[1]|fp32Aiszero[1] ? 1'b0 : A[ 63]^B[ 63];
                  o_sign_AB[ 8] <= fp32Biszero[2]|fp32Aiszero[2] ? 1'b0 : A[ 95]^B[ 95];
                  o_sign_AB[ 9] <= fp32Biszero[2]|fp32Aiszero[2] ? 1'b0 : A[ 95]^B[ 95];
                  o_sign_AB[10] <= fp32Biszero[2]|fp32Aiszero[2] ? 1'b0 : A[ 95]^B[ 95];
                  o_sign_AB[11] <= fp32Biszero[2]|fp32Aiszero[2] ? 1'b0 : A[ 95]^B[ 95];
                  o_sign_AB[12] <= fp32Biszero[3]|fp32Aiszero[3] ? 1'b0 : A[127]^B[127];
                  o_sign_AB[13] <= fp32Biszero[3]|fp32Aiszero[3] ? 1'b0 : A[127]^B[127];
                  o_sign_AB[14] <= fp32Biszero[3]|fp32Aiszero[3] ? 1'b0 : A[127]^B[127];
                  o_sign_AB[15] <= fp32Biszero[3]|fp32Aiszero[3] ? 1'b0 : A[127]^B[127];
                  o_sign_AB_fp64 <= 1'b0;
              end
        2'b10:begin
                  o_sign_AB <= 15'b0;
                  o_sign_AB_fp64 <= fp64Aiszero|fp64Biszero ? 1'b0 : A[63]^B[63];
              end
      default:begin
                  o_sign_AB <= 15'b0;
                  o_sign_AB_fp64 <= 1'b0;
              end
    endcase
end

//exp processign
always@(posedge clk)begin
    case(mode_sel)
        2'b00:begin
                  o_exp_AB_fp64<= 12'b0; 
                  o_exp_AB0    <= fp16Biszero[ 0]|fp16Aiszero[ 0] ? 10'b0 :  A[ 14: 10] + B[ 14: 10];
                  o_exp_AB1    <= fp16Biszero[ 1]|fp16Aiszero[ 1] ? 10'b0 :  A[ 30: 26] + B[ 30: 26];
                  o_exp_AB2    <= fp16Biszero[ 2]|fp16Aiszero[ 2] ? 10'b0 :  A[ 46: 42] + B[ 46: 42];
                  o_exp_AB3    <= fp16Biszero[ 3]|fp16Aiszero[ 3] ? 10'b0 :  A[ 62: 58] + B[ 62: 58];
                  o_exp_AB4    <= fp16Biszero[ 4]|fp16Aiszero[ 4] ? 10'b0 :  A[ 78: 74] + B[ 78: 74];
                  o_exp_AB5    <= fp16Biszero[ 5]|fp16Aiszero[ 5] ? 10'b0 :  A[ 94: 90] + B[ 94: 90];
                  o_exp_AB6    <= fp16Biszero[ 6]|fp16Aiszero[ 6] ? 10'b0 :  A[110:106] + B[110:106];
                  o_exp_AB7    <= fp16Biszero[ 7]|fp16Aiszero[ 7] ? 10'b0 :  A[126:122] + B[126:122];
                  o_exp_AB8    <= fp16Biszero[ 8]|fp16Aiszero[ 8] ? 10'b0 :  A[142:138] + B[142:138];
                  o_exp_AB9    <= fp16Biszero[ 9]|fp16Aiszero[ 9] ? 10'b0 :  A[158:154] + B[158:154];
                  o_exp_ABA    <= fp16Biszero[10]|fp16Aiszero[10] ? 10'b0 :  A[174:170] + B[174:170];
                  o_exp_ABB    <= fp16Biszero[11]|fp16Aiszero[11] ? 10'b0 :  A[190:186] + B[190:186];
                  o_exp_ABC    <= fp16Biszero[12]|fp16Aiszero[12] ? 10'b0 :  A[206:202] + B[206:202];
                  o_exp_ABD    <= fp16Biszero[13]|fp16Aiszero[13] ? 10'b0 :  A[222:218] + B[222:218];
                  o_exp_ABE    <= fp16Biszero[14]|fp16Aiszero[14] ? 10'b0 :  A[238:234] + B[238:234];
                  o_exp_ABF    <= fp16Biszero[15]|fp16Aiszero[15] ? 10'b0 :  A[254:250] + B[254:250];
              end
        2'b01:begin
                  o_exp_AB_fp64<= 12'b0;
                  o_exp_AB0    <= fp32Biszero[0]|fp32Aiszero[0] ? 10'b0 :  A[ 30: 23] + B[ 30: 23] +26;
                  o_exp_AB1    <= fp32Biszero[0]|fp32Aiszero[0] ? 10'b0 :  A[ 30: 23] + B[ 30: 23] +13;
                  o_exp_AB2    <= fp32Biszero[0]|fp32Aiszero[0] ? 10'b0 :  A[ 30: 23] + B[ 30: 23] +13;
                  o_exp_AB3    <= fp32Biszero[0]|fp32Aiszero[0] ? 10'b0 :  A[ 30: 23] + B[ 30: 23] +0 ;
                  o_exp_AB4    <= fp32Biszero[1]|fp32Aiszero[1] ? 10'b0 :  A[ 62: 55] + B[ 62: 55] +26;
                  o_exp_AB5    <= fp32Biszero[1]|fp32Aiszero[1] ? 10'b0 :  A[ 62: 55] + B[ 62: 55] +13;
                  o_exp_AB6    <= fp32Biszero[1]|fp32Aiszero[1] ? 10'b0 :  A[ 62: 55] + B[ 62: 55] +13;
                  o_exp_AB7    <= fp32Biszero[1]|fp32Aiszero[1] ? 10'b0 :  A[ 62: 55] + B[ 62: 55] +0 ;
                  o_exp_AB8    <= fp32Biszero[2]|fp32Aiszero[2] ? 10'b0 :  A[ 94: 87] + B[ 94: 87] +26;
                  o_exp_AB9    <= fp32Biszero[2]|fp32Aiszero[2] ? 10'b0 :  A[ 94: 87] + B[ 94: 87] +13;
                  o_exp_ABA    <= fp32Biszero[2]|fp32Aiszero[2] ? 10'b0 :  A[ 94: 87] + B[ 94: 87] +13;
                  o_exp_ABB    <= fp32Biszero[2]|fp32Aiszero[2] ? 10'b0 :  A[ 94: 87] + B[ 94: 87] +0 ;
                  o_exp_ABC    <= fp32Biszero[3]|fp32Aiszero[3] ? 10'b0 :  A[126:119] + B[126:119] +26;
                  o_exp_ABD    <= fp32Biszero[3]|fp32Aiszero[3] ? 10'b0 :  A[126:119] + B[126:119] +13;
                  o_exp_ABE    <= fp32Biszero[3]|fp32Aiszero[3] ? 10'b0 :  A[126:119] + B[126:119] +13;
                  o_exp_ABF    <= fp32Biszero[3]|fp32Aiszero[3] ? 10'b0 :  A[126:119] + B[126:119] +0 ;
              end
        2'b10:begin
                  o_exp_AB_fp64<= fp64Biszero|fp64Aiszero ? 12'b0 : A[62:52]+ B[62:52];
                  o_exp_AB0    <=26; 
                  o_exp_AB1    <=13;
                  o_exp_AB2    <=13;
                  o_exp_AB3    <=0 ;
                  o_exp_AB4    <=26;
                  o_exp_AB5    <=13;
                  o_exp_AB6    <=13;
                  o_exp_AB7    <=0 ;
                  o_exp_AB8    <=26;
                  o_exp_AB9    <=13;
                  o_exp_ABA    <=13;
                  o_exp_ABB    <=0 ;
                  o_exp_ABC    <=26;
                  o_exp_ABD    <=13;
                  o_exp_ABE    <=13;
                  o_exp_ABF    <=0 ;
               end
      default:begin
                  o_exp_AB_fp64<=12'b0;
                  o_exp_AB0    <=10'b0; 
                  o_exp_AB1    <=10'b0;
                  o_exp_AB2    <=10'b0;
                  o_exp_AB3    <=10'b0;
                  o_exp_AB4    <=10'b0;
                  o_exp_AB5    <=10'b0;
                  o_exp_AB6    <=10'b0;
                  o_exp_AB7    <=10'b0;
                  o_exp_AB8    <=10'b0;
                  o_exp_AB9    <=10'b0;
                  o_exp_ABA    <=10'b0;
                  o_exp_ABB    <=10'b0;
                  o_exp_ABC    <=10'b0;
                  o_exp_ABD    <=10'b0;
                  o_exp_ABE    <=10'b0;
                  o_exp_ABF    <=10'b0;
              end
    endcase
end

//mantisa processign
always@(posedge clk)begin
    case(mode_sel)
        2'b00:begin
                  o_man_A0    <= {1'b0, fp16_imbitA0, A[  9:  0]};
                  o_man_A1    <= {1'b0, fp16_imbitA1, A[ 25: 16]};
                  o_man_A2    <= {1'b0, fp16_imbitA2, A[ 41: 32]};
                  o_man_A3    <= {1'b0, fp16_imbitA3, A[ 57: 48]};
                  o_man_A4    <= {1'b0, fp16_imbitA4, A[ 73: 64]};
                  o_man_A5    <= {1'b0, fp16_imbitA5, A[ 89: 80]};
                  o_man_A6    <= {1'b0, fp16_imbitA6, A[105: 96]};
                  o_man_A7    <= {1'b0, fp16_imbitA7, A[121:112]};
                  o_man_A8    <= {1'b0, fp16_imbitA8, A[137:128]};
                  o_man_A9    <= {1'b0, fp16_imbitA9, A[153:144]};
                  o_man_AA    <= {1'b0, fp16_imbitA9, A[169:160]};
                  o_man_AB    <= {1'b0, fp16_imbitA9, A[185:176]};
                  o_man_AC    <= {1'b0, fp16_imbitA9, A[201:192]};
                  o_man_AD    <= {1'b0, fp16_imbitA9, A[217:208]};
                  o_man_AE    <= {1'b0, fp16_imbitA9, A[233:224]};
                  o_man_AF    <= {1'b0, fp16_imbitA9, A[249:240]};
                  o_fp64_imbitA <= 1'b0;         
                  o_man_B0    <= {1'b0, fp16_imbitB0, B[  9:  0]}; 
                  o_man_B1    <= {1'b0, fp16_imbitB1, B[ 25: 16]};
                  o_man_B2    <= {1'b0, fp16_imbitB2, B[ 41: 32]};
                  o_man_B3    <= {1'b0, fp16_imbitB3, B[ 57: 48]};
                  o_man_B4    <= {1'b0, fp16_imbitB4, B[ 73: 64]};
                  o_man_B5    <= {1'b0, fp16_imbitB5, B[ 89: 80]};
                  o_man_B6    <= {1'b0, fp16_imbitB6, B[105: 96]};
                  o_man_B7    <= {1'b0, fp16_imbitB7, B[121:112]};
                  o_man_B8    <= {1'b0, fp16_imbitB8, B[137:128]};
                  o_man_B9    <= {1'b0, fp16_imbitB9, B[153:144]};
                  o_man_BA    <= {1'b0, fp16_imbitB9, B[169:160]};
                  o_man_BB    <= {1'b0, fp16_imbitB9, B[185:176]};
                  o_man_BC    <= {1'b0, fp16_imbitB9, B[201:192]};
                  o_man_BD    <= {1'b0, fp16_imbitB9, B[217:208]};
                  o_man_BE    <= {1'b0, fp16_imbitB9, B[233:224]};
                  o_man_BF    <= {1'b0, fp16_imbitB9, B[249:240]};
                  o_fp64_imbitB <= 1'b0;
              end
        2'b01:begin
                  o_man_A0    <= {2'b0, fp32_imbitA0, A[ 22: 13]};
                  o_man_A1    <= {2'b0, fp32_imbitA0, A[ 22: 13]};
                  o_man_A2    <= A[ 12:  0];
                  o_man_A3    <= A[ 12:  0];
                  o_man_A4    <= {2'b0, fp32_imbitA1, A[ 54: 45]};  
                  o_man_A5    <= {2'b0, fp32_imbitA1, A[ 54: 45]};
                  o_man_A6    <= A[ 44: 32];
                  o_man_A7    <= A[ 44: 32];
                  o_man_A8    <= {2'b0, fp32_imbitA2, A[ 86: 77]};
                  o_man_A9    <= {2'b0, fp32_imbitA2, A[ 86: 77]};
                  o_man_AA    <= A[ 76: 64];
                  o_man_AB    <= A[ 76: 64];
                  o_man_AC    <= {2'b0, fp32_imbitA3, A[118:109]};
                  o_man_AD    <= {2'b0, fp32_imbitA3, A[118:109]};
                  o_man_AE    <= A[108: 96];
                  o_man_AF    <= A[108: 96];
                  o_fp64_imbitA <= 1'b0;  
                            
                  o_man_B0    <= {2'b0, fp32_imbitB0, B[ 22: 13]}; 
                  o_man_B1    <= B[ 12:  0];
                  o_man_B2    <= {2'b0, fp32_imbitB0, B[ 22: 13]};   
                  o_man_B3    <= B[ 12:  0];
                  o_man_B4    <= {2'b0, fp32_imbitB1, B[ 54: 45]}; 
                  o_man_B5    <= B[ 44: 32];
                  o_man_B6    <= {2'b0, fp32_imbitB1, B[ 54: 45]}; 
                  o_man_B7    <= B[ 44: 32];
                  o_man_B8    <= {2'b0, fp32_imbitB2, B[ 86: 77]}; 
                  o_man_B9    <= B[ 76: 64];
                  o_man_BA    <= {2'b0, fp32_imbitB2, B[ 86: 77]};
                  o_man_BB    <= B[ 76: 64];
                  o_man_BC    <= {2'b0, fp32_imbitB3, B[118:109]};
                  o_man_BD    <= B[108: 96];
                  o_man_BE    <= {2'b0, fp32_imbitB3, B[118:109]};
                  o_man_BF    <= B[108: 96];
                  o_fp64_imbitB <= 1'b0;  
              end
        2'b10:begin
                  o_man_A0    <= A[51:39]; //a3
                  o_man_A1    <= A[51:39]; //a3
                  o_man_A2    <= A[38:26]; //a2 
                  o_man_A3    <= A[38:26]; //a2
                  o_man_A4    <= A[51:39]; //a3
                  o_man_A5    <= A[51:39]; //a3
                  o_man_A6    <= A[38:26]; //a2
                  o_man_A7    <= A[38:26]; //a2
                  o_man_A8    <= A[25:13]; //a1
                  o_man_A9    <= A[12: 0]; //a0
                  o_man_AA    <= A[25:13]; //a1
                  o_man_AB    <= A[12: 0]; //a0
                  o_man_AC    <= A[25:13]; //a1
                  o_man_AD    <= A[12: 0]; //a0
                  o_man_AE    <= A[25:13]; //a1
                  o_man_AF    <= A[12: 0]; //a0
                  o_fp64_imbitA <= fp64_imbitA;  
                            
                  o_man_B0    <= B[51:39]; //b3 
                  o_man_B1    <= B[38:26]; //b2
                  o_man_B2    <= B[51:39]; //b3
                  o_man_B3    <= B[38:26]; //b2
                  o_man_B4    <= B[25:13]; //b1
                  o_man_B5    <= B[12: 0]; //b0
                  o_man_B6    <= B[25:13]; //b1
                  o_man_B7    <= B[12: 0]; //b0
                  o_man_B8    <= B[51:39]; //b3
                  o_man_B9    <= B[51:39]; //b3
                  o_man_BA    <= B[38:26]; //b2
                  o_man_BB    <= B[38:26]; //b2
                  o_man_BC    <= B[25:13]; //b1
                  o_man_BD    <= B[25:13]; //b1
                  o_man_BE    <= B[12: 0]; //b0
                  o_man_BF    <= B[12: 0]; //b0
                  o_fp64_imbitB <= fp64_imbitB;  
              end
      default:begin
                  o_man_A0    <=0; 
                  o_man_A1    <=0; 
                  o_man_A2    <=0; 
                  o_man_A3    <=0; 
                  o_man_A4    <=0; 
                  o_man_A5    <=0; 
                  o_man_A6    <=0; 
                  o_man_A7    <=0; 
                  o_man_A8    <=0; 
                  o_man_A9    <=0; 
                  o_man_AA    <=0; 
                  o_man_AB    <=0; 
                  o_man_AC    <=0; 
                  o_man_AD    <=0; 
                  o_man_AE    <=0; 
                  o_man_AF    <=0; 
                           
                  o_man_B0    <=0;  
                  o_man_B1    <=0; 
                  o_man_B2    <=0; 
                  o_man_B3    <=0; 
                  o_man_B4    <=0; 
                  o_man_B5    <=0; 
                  o_man_B6    <=0; 
                  o_man_B7    <=0; 
                  o_man_B8    <=0; 
                  o_man_B9    <=0; 
                  o_man_BA    <=0; 
                  o_man_BB    <=0; 
                  o_man_BC    <=0; 
                  o_man_BD    <=0; 
                  o_man_BE    <=0; 
                  o_man_BF    <=0; 
              end
    endcase
end


//mode output
always@(posedge clk or negedge rstn)begin
    if(!rstn)begin
        mode_sel_pip0<= 2'b11;
    end
    else begin
        mode_sel_pip0<= mode_sel;
    end
end

/*
assign clk_cnt_pip0  = clk_cnt ;
assign mode_sel_pip0 = mode_sel;
*/
endmodule
