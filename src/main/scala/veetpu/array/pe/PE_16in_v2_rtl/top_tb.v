`timescale 1ns/1ps
module PE_16intest();
reg clk;
reg [1:0] mode_sel;
reg rstn;

initial begin
    rstn <= 0;
	 clk  <= 0;
	 #20 rstn <= 1'b1;
end

initial begin
 forever #10 clk <= ~clk; 
end

reg [1:0] rand_sign;
reg [10:0] rand_expA;
reg [10:0] rand_expB;
reg [31:0] rand_manA;
reg [31:0] rand_manB;

initial begin
 forever #10 clk <= ~clk; 
end

initial begin
 	     rand_sign <= 0;
		  rand_expA <= 0;
		  rand_manA <= 0;
		  rand_expB <= 0;
		  rand_manB <= 0;
end

         initial begin
		 $dumpfile("wave.vcd");
		 $dumpvars(0,PE_16intest);
          end
//clock counter
reg clk_cnt;
always@(posedge clk or negedge rstn)begin
    if(!rstn)begin
        clk_cnt <= 0;
    end
    else begin
        clk_cnt <= ~clk_cnt;
    end
end

always@(posedge clk)begin
    if(clk_cnt)begin
	     rand_sign <= $random;
		  rand_expA <= $random;
		  rand_manA <= $random;
		  rand_expB <= $random;
		  rand_manB <= $random;
	 end
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
wire[63:0] A ={rand_sign[0], rand_expA, {rand_manA,rand_manA[19:0]}};
wire[63:0] B ={rand_sign[1], rand_expB, {rand_manB,rand_manB[19:0]}};
wire fp64_imbitA = |A[62:52];
wire fp64_imbitB = |B[62:52];
wire fp64Aiszero    = ({fp64_imbitA , A[ 51:  0]} == 53'b0);
wire fp64Biszero    = ({fp64_imbitB , B[ 51:  0]} == 53'b0);
wire [11:0] exp_AB = rand_expA + rand_expB ;
wire [105:0] man_AB= {fp64_imbitA,A[ 51:  0]}*{fp64_imbitB,B[ 51:  0]};

wire sign_AB = rand_sign[0]^rand_sign[1];
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

reg [63:0]rf_fp64AB_pip0;
reg [63:0]rf_fp64AB_pip1;
reg [63:0]rf_fp64AB_pip2;
reg [63:0]rf_fp64AB_pip3;
reg [63:0]rf_fp64AB_pip4;
reg [63:0]rf_fp64AB_pip5;
reg [63:0]rf_fp64AB_pip6;
reg [63:0]rf_fp64AB_pip7;
reg [63:0]rf_fp64AB_pip8;
reg [63:0]rf_fp64AB_pip9;
reg [63:0]rf_fp64AB_pip10;
reg [63:0]rf_fp64AB_pip11;
reg [63:0]rf_fp64AB_pip12;

always@(posedge clk)begin
    rf_fp64AB_pip0 <= rf_fp64AB;
	 rf_fp64AB_pip1 <= rf_fp64AB_pip0;
	 rf_fp64AB_pip2 <= rf_fp64AB_pip1;
	 rf_fp64AB_pip3 <= rf_fp64AB_pip2;
	 rf_fp64AB_pip4 <= rf_fp64AB_pip3;
	 rf_fp64AB_pip5 <= rf_fp64AB_pip4;
	 rf_fp64AB_pip6 <= rf_fp64AB_pip5;
	 rf_fp64AB_pip7 <= rf_fp64AB_pip6;
	 rf_fp64AB_pip8 <= rf_fp64AB_pip7;
	 rf_fp64AB_pip9 <= rf_fp64AB_pip8;
	 rf_fp64AB_pip10 <= rf_fp64AB_pip9;
	 rf_fp64AB_pip11 <= rf_fp64AB_pip10;
	 rf_fp64AB_pip12 <= rf_fp64AB_pip11;
	 
end

/*
initial begin
    fp64_A <= {1'b0, 11'd1025, 52'hffff_ffff_ffff_f};
	 fp64_B <= {1'b0, 11'd1025, 52'hffff_ffff_ffff_f};
end
wire [10:0] exp = 1025+1025-1023;
wire [105:0] man = 53'h1fffffffffffff * 53'h1fffffffffffff;
wire [63:0] r;
wire test_exp = (exp == r[62:52]);
*/
wire [63:0] r;
PE_16in_top u_test(
    .clk(clk),
    .rstn(rstn),
    .mode_sel(2'b10),
    .A({192'b0,A}),
    .B({192'b0,B}),
    .result(r)
    );
reg test0, test1, test2, test3, test4;
reg test5;
reg test6;
reg test7;
reg test8;
reg test9;
reg test10;
reg test11;
reg test12;

always@(posedge clk)begin
   test0 <= (r == rf_fp64AB_pip0);
	test1 <= (r == rf_fp64AB_pip1);
	test2 <= (r == rf_fp64AB_pip2);
	test3 <= (r == rf_fp64AB_pip3);
	test4 <= (r == rf_fp64AB_pip4);
	test5 <= (r == rf_fp64AB_pip5);
	test6 <= (r == rf_fp64AB_pip6);
	test7 <= (r == rf_fp64AB_pip7);
	test8 <= (r == rf_fp64AB_pip8);
	test9 <= (r == rf_fp64AB_pip9);
	test10<= (r == rf_fp64AB_pip10);
	test11<= (r == rf_fp64AB_pip11);
	test12<= (r == rf_fp64AB_pip12);
end
endmodule
