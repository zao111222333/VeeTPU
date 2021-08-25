`timescale 1ns/1ps
module top_tb();
parameter clk_period = 2;
reg clk;
reg [1:0] mode_sel;
reg rstn;

initial begin
    rstn <= 0;
	 clk  <= 0;
	 #clk_period rstn <= 1'b1;
end

initial begin
 forever #(clk_period/2) clk <= ~clk; 
end

reg [1:0] rand_sign;
reg [10:0] rand_expA;
reg [10:0] rand_expB;
reg [31:0] rand_manA;
reg [31:0] rand_manB;

initial begin
    rand_sign <= 0;
    rand_expA <= 0;
    rand_manA <= 0;
    rand_expB <= 0;
    rand_manB <= 0;
end

initial begin
   $dumpfile("wave.vcd");
   $dumpvars(0,top_tb);
end

always@(posedge clk)begin
        rand_sign <= $random;
        rand_expA <= 1+{$random}%2047;
        rand_manA <= $random;
        rand_expB <= 1+{$random}%2047;
        rand_manB <= $random;
end
/*
initial begin
  rand_sign <= $random;
  rand_expA <= $random;
  rand_manA <= $random;
  rand_expB <= $random;
  rand_manB <= $random;
  #10000
  rand_sign <= 2'b0;
  rand_expA <= 11'h4ff;
  rand_manA <= 32'hffffffff;
  rand_expB <= 11'h4ff;
  rand_manB <= 32'hffffffff;
  #10000
  rand_sign <= $random;
  rand_expA <= $random;
  rand_manA <= $random;
  rand_expB <= $random;
  rand_manB <= $random;
		  
end
*/
//FP64
//wire[63:0] A ={rand_sign[0], rand_expA, {rand_manA,rand_manA[19:0]}};
//wire[63:0] B ={rand_sign[1], rand_expB, {rand_manB,rand_manB[19:0]}};
wire[63:0] A ={1'b0, rand_expA, {rand_manA,rand_manA[19:0]}};
wire[63:0] B ={1'b0, rand_expB, {rand_manB,rand_manB[19:0]}};

wire fp64_imbitA = |A[62:52];
wire fp64_imbitB = |B[62:52];
wire fp64Aiszero    = ({fp64_imbitA , A[ 51:  0]} == 53'b0);
wire fp64Biszero    = ({fp64_imbitB , B[ 51:  0]} == 53'b0);
wire [11:0] exp_AB = rand_expA + rand_expB ;
wire [105:0] man_AB= {fp64_imbitA,A[ 51:  0]}*{fp64_imbitB,B[ 51:  0]};

wire sign_AB = 1'b0;//rand_sign[0]^rand_sign[1];
//man_64 norm
reg [52:0] norm_64;
always@(*)begin
    if(man_AB[105])begin
        norm_64 = man_AB[104:53]+man_AB[52];
    end
    else if(man_AB[104])begin
        norm_64 = man_AB[103:52]+man_AB[51];
    end
    else begin
        norm_64 = 53'bx;
    end
end
wire [12:0] exp_norm = exp_AB+man_AB[105]+norm_64[52];

wire [12:0] exp_norm_out = (exp_norm>1023) ? (exp_norm-1023) : 13'h1fff;

wire [63:0] rf_fp64AB = {sign_AB, (exp_norm_out[12:11]==2'b0) ? exp_norm_out[10:0] :11'h7ff, norm_64[52] ? norm_64[52:1] : norm_64[51:0]};

//accmulate of fp64
//clock counter
reg [4:0] acc_cnt;
reg acc_en;
reg acc_out_en;
always@(posedge clk or negedge rstn)begin
    if(!rstn)begin
        acc_cnt <= 1'b0;
        acc_en  <= 1'b0;
        acc_out_en <= 1'b0;
    end
    else if(acc_cnt==2) begin
        acc_cnt <= 1'b0;
        acc_en  <= 1'b0;
        acc_out_en <=1'b1;
    end
    else begin
        acc_cnt <= acc_cnt+1;
        acc_en  <= 1'b1;
        acc_out_en <= 1'b0;
    end
end
reg [63:0]rf_fp64AB_pip0;
wire [63:0] acc_rsult;
wire        sign_A = rf_fp64AB[63];
wire [11:0] exp_A  = rf_fp64AB[62:52];
wire [52:0] man_A  = {1'b1,rf_fp64AB[51:0]};
wire        sign_B = rf_fp64AB_pip0[63];
wire [11:0] exp_B  = rf_fp64AB_pip0[62:52];
wire [52:0] man_B  = {1'b1,rf_fp64AB_pip0[51:0]};
reg  [10:0] exp_max_AaB;
reg  [53:0] man_AaB;
reg         sign_AaB;
wire [11:0] diff0 = exp_A - exp_B;
wire [11:0] diff1 = exp_B - exp_A;
always@(*)begin
    if (exp_A > exp_B)begin
        sign_AaB    <= sign_A;
        exp_max_AaB <= exp_A;
        man_AaB     <= sign_A^sign_B ? man_A - (man_B>>diff0) :  man_A + (man_B>>diff0);  
    end
    else if (exp_B > exp_A)begin
        sign_AaB    <= sign_B;
        exp_max_AaB <= exp_B;
        man_AaB     <= sign_A^sign_B ? man_B - (man_A>>diff1) :  man_B + (man_A>>diff1);  
    end
    else if (man_A > man_B)begin
        sign_AaB    <= sign_A;
        exp_max_AaB <= exp_A;
        man_AaB     <= sign_A^sign_B ? man_A - man_B :  man_A + man_B;  
    end
    else if (man_B > man_A)begin
        sign_AaB    <= sign_B;
        exp_max_AaB <= exp_B;
        man_AaB     <= sign_A^sign_B ? man_B - man_A :  man_A + man_B;  
    end
end

assign acc_rsult = {sign_AaB, (exp_max_AaB==11'h7ff)? 11'h7ff : exp_max_AaB+man_AaB[53],man_AaB[53] ? man_AaB[52:1] : man_AaB[51:0]};

reg [63:0]rf_fp64AB_pip1;
reg [63:0]rf_fp64AB_pip2;
reg [63:0]rf_fp64AB_pip3;
reg [63:0]rf_fp64AB_pip4;
reg [63:0]rf_fp64AB_pip5;

always@(posedge clk)begin
     rf_fp64AB_pip0 <= acc_en ? acc_rsult :rf_fp64AB;
end

always@(posedge clk or negedge rstn)begin
    if (!rstn)begin
     rf_fp64AB_pip0 <= 0;
     rf_fp64AB_pip1 <= 0;
    end
    else if(acc_out_en)begin
     rf_fp64AB_pip1 <= rf_fp64AB_pip0;
    end
end

always@(posedge clk or negedge rstn)begin
    if (!rstn)begin
     rf_fp64AB_pip2 <= 0;
     rf_fp64AB_pip3 <= 0;
     rf_fp64AB_pip4 <= 0;
     rf_fp64AB_pip5 <= 0;
    end
    else begin
     rf_fp64AB_pip2 <= rf_fp64AB_pip1;
     rf_fp64AB_pip3 <= rf_fp64AB_pip2;
     rf_fp64AB_pip4 <= rf_fp64AB_pip3;
     rf_fp64AB_pip5 <= rf_fp64AB_pip4;
    end
end

wire [63:0] r;
wire out_en;
PE_16in_top u_test(
    .clk(clk),
    .rstn(rstn),
    .mode_sel(2'b10),
    .A({192'b0,A}),
    .B({192'b0,B}),
    .acc_num(2),
    .result(r),
    .out_en(out_en)
    );
reg test0, test1, test2, test3, test4;
reg test5;

always@(posedge clk)begin
        test0 <= (r == rf_fp64AB_pip0);
	test1 <= (r == rf_fp64AB_pip1);
	test2 <= (r == rf_fp64AB_pip2);
	test3 <= (r == rf_fp64AB_pip3);
	test4 <= (r == rf_fp64AB_pip4);
	test5 <= (r == rf_fp64AB_pip5);
end
endmodule
