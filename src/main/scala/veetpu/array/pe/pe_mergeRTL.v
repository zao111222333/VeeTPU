module pe_CSA3_2#(parameter width = 24)
(
input [width-1:0]a,
input [width-1:0]b,
input [width-1:0]c,
output[width-1:0]sum,
output[width-1:0]carry
);


genvar i;
generate
          for(i = 0; i < width; i = i+1) begin: Fulladder
		  pe_Fadd U_Fadd(
			  .x(a[i]), 
			  .y(b[i]), 
			  .Cin(c[i]), 
			  .Cout(carry[i]), 
			  .Sum(sum[i])
		  );
	  end
endgenerate


endmodule
module pe_CSA4_2 #(parameter Width = 24)(
    input [Width-1:0]a,
    input [Width-1:0]b,
    input [Width-1:0]c,
    input [Width-1:0]d,
    output[Width-1:0]sum,
    output[Width-1:0]carry,
    output carry_out
);

    //internal signal
    wire a0_xor_b0   ;
    wire c0_xor_d0   ;
    wire [Width-1:0] c_out ;
    assign a0_xor_b0  = a[0]^b[0] ;
    assign c0_xor_d0  = c[0]^d[0] ;
    assign sum[0]     = a0_xor_b0 ^ c0_xor_d0 ;
    assign c_out[0]   = c0_xor_d0 ? b[0] : d[0];
    assign carry[0] = a[0] & (~sum[0]);
    assign carry_out = c_out[Width-1];
    //output
    genvar i;
    generate
              for(i = 0; i < Width-1; i = i+1) begin: CSA4_2_unit
                  CSA4_2_UNIT U_CSA4_2_UNIT(
			  .a(a[i+1]),
			  .b(b[i+1]),
			  .c(c[i+1]),
			  .d(d[i+1]),
			  .c_in(c_out[i]),
			  .c_out(c_out[i+1]),
			  .carry(carry[i+1]),
			  .sum(sum[i+1])
		  );
	      end
    endgenerate

endmodule

module CSA4_2_UNIT (
    input  a     ,
    input  b     ,
    input  c     ,
    input  d     ,
    input  c_in  ,
    output c_out ,
    output carry ,
    output sum    
);
    //internal signal
    wire a_xor_b   ;
    wire c_xor_d   ;
    wire ab_xor_cd ;
    assign a_xor_b= a^b ;
    assign c_xor_d= c^d ;
    assign ab_xor_cd = a_xor_b ^ c_xor_d ;

    //output
    assign c_out = c_xor_d ? b : d ;
    assign carry = ab_xor_cd ? c_in : a ;
    assign sum   = ab_xor_cd ^ c_in;
endmodule

module pe_Fadd(x,y,Cin,Cout,Sum);
  input x,y,Cin;
  output Cout,Sum;
  wire a,b,c;

  xor(a,x,y);
  xor(Sum,a,Cin);
  and(b,x,y);
  and(c,Cin,a);
  or(Cout,b,c);

endmodule
module pe_Hadd(
input a,
input b,
output sum,
output carry
);

assign carry=a&b;
assign sum=a^b;
endmodule
module PE_16in_top(
    input clk,
    input rstn,
    input [  1:0] mode_sel,
    input [255:0] A,
    input [255:0] B,
    output [63:0] result,
    output [ 1:0] mode_out
    );

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

//input processing
wire [ 15:0]o_sign_AB     ; //sign AB of fp16 and fp32;
wire        o_sign_AB_fp64; //sign AB for FP64
wire [11:0] o_exp_AB_fp64  ; //exp AB for FP64
wire [9:0]  o_exp_AB0      ; //exp AB for FP64,FP32,FP16
wire [9:0]  o_exp_AB1      ; //exp AB for FP64,FP32,FP16
wire [9:0]  o_exp_AB2      ; //exp AB for FP64,FP32,FP16
wire [9:0]  o_exp_AB3      ; //exp AB for FP64,FP32,FP16
wire [9:0]  o_exp_AB4      ; //exp AB for FP64,FP32,FP16
wire [9:0]  o_exp_AB5      ; //exp AB for FP64,FP32,FP16
wire [9:0]  o_exp_AB6      ; //exp AB for FP64,FP32,FP16
wire [9:0]  o_exp_AB7      ; //exp AB for FP64,FP32,FP16
wire [9:0]  o_exp_AB8      ; //exp AB for FP64,FP32,FP16
wire [9:0]  o_exp_AB9      ; //exp AB for FP64,FP32,FP16
wire [9:0]  o_exp_ABA      ; //exp AB for FP64,FP32,FP16
wire [9:0]  o_exp_ABB      ; //exp AB for FP64,FP32,FP16
wire [9:0]  o_exp_ABC      ; //exp AB for FP64,FP32,FP16
wire [9:0]  o_exp_ABD      ; //exp AB for FP64,FP32,FP16
wire [9:0]  o_exp_ABE      ; //exp AB for FP64,FP32,FP16
wire [9:0]  o_exp_ABF      ; //exp AB for FP64,FP32,FP16
wire [12:0] o_man_A0       ; //mantisa A for FP64,FP32,FP16
wire [12:0] o_man_A1       ; //mantisa A for FP64,FP32,FP16
wire [12:0] o_man_A2       ; //mantisa A for FP64,FP32,FP16
wire [12:0] o_man_A3       ; //mantisa A for FP64,FP32,FP16
wire [12:0] o_man_A4       ; //mantisa A for FP64,FP32,FP16
wire [12:0] o_man_A5       ; //mantisa A for FP64,FP32,FP16
wire [12:0] o_man_A6       ; //mantisa A for FP64,FP32,FP16
wire [12:0] o_man_A7       ; //mantisa A for FP64,FP32,FP16
wire [12:0] o_man_A8       ; //mantisa A for FP64,FP32,FP16
wire [12:0] o_man_A9       ; //mantisa A for FP64,FP32,FP16
wire [12:0] o_man_AA       ; //mantisa A for FP64,FP32,FP16
wire [12:0] o_man_AB       ; //mantisa A for FP64,FP32,FP16
wire [12:0] o_man_AC       ; //mantisa A for FP64,FP32,FP16
wire [12:0] o_man_AD       ; //mantisa A for FP64,FP32,FP16
wire [12:0] o_man_AE       ; //mantisa A for FP64,FP32,FP16
wire [12:0] o_man_AF       ; //mantisa A for FP64,FP32,FP16
wire        o_fp64_imbitA  ;
wire [12:0] o_man_B0       ; //mantisa B for FP64,FP32,FP16
wire [12:0] o_man_B1       ; //mantisa B for FP64,FP32,FP16
wire [12:0] o_man_B2       ; //mantisa B for FP64,FP32,FP16
wire [12:0] o_man_B3       ; //mantisa B for FP64,FP32,FP16
wire [12:0] o_man_B4       ; //mantisa B for FP64,FP32,FP16
wire [12:0] o_man_B5       ; //mantisa B for FP64,FP32,FP16
wire [12:0] o_man_B6       ; //mantisa B for FP64,FP32,FP16
wire [12:0] o_man_B7       ; //mantisa B for FP64,FP32,FP16
wire [12:0] o_man_B8       ; //mantisa B for FP64,FP32,FP16
wire [12:0] o_man_B9       ; //mantisa B for FP64,FP32,FP16
wire [12:0] o_man_BA       ; //mantisa B for FP64,FP32,FP16
wire [12:0] o_man_BB       ; //mantisa B for FP64,FP32,FP16
wire [12:0] o_man_BC       ; //mantisa B for FP64,FP32,FP16
wire [12:0] o_man_BD       ; //mantisa B for FP64,FP32,FP16
wire [12:0] o_man_BE       ; //mantisa B for FP64,FP32,FP16
wire [12:0] o_man_BF       ; //mantisa B for FP64,FP32,FP16
wire        o_fp64_imbitB  ;
wire [1:0] mode_sel_pip0   ; //mode sel output


input_processing U_input_processing(
    .clk            (clk            ),
    .rstn           (rstn           ),
    .A              (A              ),
    .B              (B              ),
    .mode_sel       (mode_sel       ), //2'b00:FP16; 2'b01:FP32; 2'b10:FP64; 2'b11: set zero
    .o_sign_AB      (o_sign_AB      ), 
    .o_sign_AB_fp64 (o_sign_AB_fp64 ),
    .o_exp_AB_fp64  (o_exp_AB_fp64  ),
    .o_exp_AB0      (o_exp_AB0      ),
    .o_exp_AB1      (o_exp_AB1      ),
    .o_exp_AB2      (o_exp_AB2      ),
    .o_exp_AB3      (o_exp_AB3      ),
    .o_exp_AB4      (o_exp_AB4      ),
    .o_exp_AB5      (o_exp_AB5      ),
    .o_exp_AB6      (o_exp_AB6      ),
    .o_exp_AB7      (o_exp_AB7      ),
    .o_exp_AB8      (o_exp_AB8      ),
    .o_exp_AB9      (o_exp_AB9      ),
    .o_exp_ABA      (o_exp_ABA      ),
    .o_exp_ABB      (o_exp_ABB      ),
    .o_exp_ABC      (o_exp_ABC      ),
    .o_exp_ABD      (o_exp_ABD      ),
    .o_exp_ABE      (o_exp_ABE      ),
    .o_exp_ABF      (o_exp_ABF      ),
    .o_man_A0       (o_man_A0       ),
    .o_man_A1       (o_man_A1       ),
    .o_man_A2       (o_man_A2       ),
    .o_man_A3       (o_man_A3       ),
    .o_man_A4       (o_man_A4       ),
    .o_man_A5       (o_man_A5       ),
    .o_man_A6       (o_man_A6       ),
    .o_man_A7       (o_man_A7       ),
    .o_man_A8       (o_man_A8       ),
    .o_man_A9       (o_man_A9       ),
    .o_man_AA       (o_man_AA       ),
    .o_man_AB       (o_man_AB       ),
    .o_man_AC       (o_man_AC       ),
    .o_man_AD       (o_man_AD       ),
    .o_man_AE       (o_man_AE       ),
    .o_man_AF       (o_man_AF       ),
    .o_fp64_imbitA  (o_fp64_imbitA  ),          
    .o_man_B0       (o_man_B0       ),
    .o_man_B1       (o_man_B1       ),
    .o_man_B2       (o_man_B2       ),
    .o_man_B3       (o_man_B3       ),
    .o_man_B4       (o_man_B4       ),
    .o_man_B5       (o_man_B5       ),
    .o_man_B6       (o_man_B6       ),
    .o_man_B7       (o_man_B7       ),
    .o_man_B8       (o_man_B8       ),
    .o_man_B9       (o_man_B9       ),
    .o_man_BA       (o_man_BA       ),
    .o_man_BB       (o_man_BB       ),
    .o_man_BC       (o_man_BC       ),
    .o_man_BD       (o_man_BD       ),
    .o_man_BE       (o_man_BE       ),
    .o_man_BF       (o_man_BF       ),
    .o_fp64_imbitB  (o_fp64_imbitB  ),               
    .mode_sel_pip0  (mode_sel_pip0   )
);

//pipline1 processing
wire [ 1:0] mode_sel_pip1      ;
wire [15:0] o_sign_AB_pip1     ;
wire        o_sign_AB_fp64_pip1;
wire [11:0] o_exp_AB_fp64_pip1 ;
wire [ 9:0] o_exp_max          ;
wire [ 9:0] o_shift0           ;
wire [ 9:0] o_shift1           ;
wire [ 9:0] o_shift2           ;
wire [ 9:0] o_shift3           ;
wire [ 9:0] o_shift4           ;
wire [ 9:0] o_shift5           ;
wire [ 9:0] o_shift6           ;
wire [ 9:0] o_shift7           ;
wire [ 9:0] o_shift8           ;
wire [ 9:0] o_shift9           ;
wire [ 9:0] o_shiftA           ;
wire [ 9:0] o_shiftB           ;
wire [ 9:0] o_shiftC           ;
wire [ 9:0] o_shiftD           ;
wire [ 9:0] o_shiftE           ;
wire [ 9:0] o_shiftF           ;
wire [25:0] o_man_AB0          ;
wire [25:0] o_man_AB1          ;
wire [25:0] o_man_AB2          ;
wire [25:0] o_man_AB3          ;
wire [25:0] o_man_AB4          ;
wire [25:0] o_man_AB5          ;
wire [25:0] o_man_AB6          ;
wire [25:0] o_man_AB7          ;
wire [25:0] o_man_AB8          ;
wire [25:0] o_man_AB9          ;
wire [25:0] o_man_ABA          ;
wire [25:0] o_man_ABB          ;
wire [25:0] o_man_ABC          ;
wire [25:0] o_man_ABD          ;
wire [25:0] o_man_ABE          ;
wire [25:0] o_man_ABF          ;
wire [52:0] o_man_A_53b        ; 
wire [52:0] o_man_B_53b        ;


pip1_processing U_pip1_processing(
    .clk            (clk            ),
    .rstn           (rstn           ),
    .mode_sel_pip0  (mode_sel_pip0  ),
    .i_sign_AB      (o_sign_AB      ), //sign AB of fp16 and fp32; 
    .i_sign_AB_fp64 (o_sign_AB_fp64 ), //sign AB for FP64
    .i_exp_AB_fp64  (o_exp_AB_fp64  ), //exp AB for FP64
    .i_exp_AB0      (o_exp_AB0      ), //exp AB for FP64,FP32,FP16
    .i_exp_AB1      (o_exp_AB1      ), //exp AB for FP64,FP32,FP16
    .i_exp_AB2      (o_exp_AB2      ), //exp AB for FP64,FP32,FP16
    .i_exp_AB3      (o_exp_AB3      ), //exp AB for FP64,FP32,FP16
    .i_exp_AB4      (o_exp_AB4      ), //exp AB for FP64,FP32,FP16
    .i_exp_AB5      (o_exp_AB5      ), //exp AB for FP64,FP32,FP16
    .i_exp_AB6      (o_exp_AB6      ), //exp AB for FP64,FP32,FP16
    .i_exp_AB7      (o_exp_AB7      ), //exp AB for FP64,FP32,FP16
    .i_exp_AB8      (o_exp_AB8      ), //exp AB for FP64,FP32,FP16
    .i_exp_AB9      (o_exp_AB9      ), //exp AB for FP64,FP32,FP16
    .i_exp_ABA      (o_exp_ABA      ), //exp AB for FP64,FP32,FP16
    .i_exp_ABB      (o_exp_ABB      ), //exp AB for FP64,FP32,FP16
    .i_exp_ABC      (o_exp_ABC      ), //exp AB for FP64,FP32,FP16
    .i_exp_ABD      (o_exp_ABD      ), //exp AB for FP64,FP32,FP16
    .i_exp_ABE      (o_exp_ABE      ), //exp AB for FP64,FP32,FP16
    .i_exp_ABF      (o_exp_ABF      ), //exp AB for FP64,FP32,FP16
    .i_man_A0       (o_man_A0       ), //mantisa A for FP64,FP32,FP16
    .i_man_A1       (o_man_A1       ), //mantisa A for FP64,FP32,FP16
    .i_man_A2       (o_man_A2       ), //mantisa A for FP64,FP32,FP16
    .i_man_A3       (o_man_A3       ), //mantisa A for FP64,FP32,FP16
    .i_man_A4       (o_man_A4       ), //mantisa A for FP64,FP32,FP16
    .i_man_A5       (o_man_A5       ), //mantisa A for FP64,FP32,FP16
    .i_man_A6       (o_man_A6       ), //mantisa A for FP64,FP32,FP16
    .i_man_A7       (o_man_A7       ), //mantisa A for FP64,FP32,FP16
    .i_man_A8       (o_man_A8       ), //mantisa A for FP64,FP32,FP16
    .i_man_A9       (o_man_A9       ), //mantisa A for FP64,FP32,FP16
    .i_man_AA       (o_man_AA       ), //mantisa A for FP64,FP32,FP16
    .i_man_AB       (o_man_AB       ), //mantisa A for FP64,FP32,FP16
    .i_man_AC       (o_man_AC       ), //mantisa A for FP64,FP32,FP16
    .i_man_AD       (o_man_AD       ), //mantisa A for FP64,FP32,FP16
    .i_man_AE       (o_man_AE       ), //mantisa A for FP64,FP32,FP16
    .i_man_AF       (o_man_AF       ), //mantisa A for FP64,FP32,FP16
    .i_fp64_imbitA  (o_fp64_imbitA  ), 
    .i_man_B0       (o_man_B0       ), //mantisa B for FP64,FP32,FP16
    .i_man_B1       (o_man_B1       ), //mantisa B for FP64,FP32,FP16
    .i_man_B2       (o_man_B2       ), //mantisa B for FP64,FP32,FP16
    .i_man_B3       (o_man_B3       ), //mantisa B for FP64,FP32,FP16
    .i_man_B4       (o_man_B4       ), //mantisa B for FP64,FP32,FP16
    .i_man_B5       (o_man_B5       ), //mantisa B for FP64,FP32,FP16
    .i_man_B6       (o_man_B6       ), //mantisa B for FP64,FP32,FP16
    .i_man_B7       (o_man_B7       ), //mantisa B for FP64,FP32,FP16
    .i_man_B8       (o_man_B8       ), //mantisa B for FP64,FP32,FP16
    .i_man_B9       (o_man_B9       ), //mantisa B for FP64,FP32,FP16
    .i_man_BA       (o_man_BA       ), //mantisa B for FP64,FP32,FP16
    .i_man_BB       (o_man_BB       ), //mantisa B for FP64,FP32,FP16
    .i_man_BC       (o_man_BC       ), //mantisa B for FP64,FP32,FP16
    .i_man_BD       (o_man_BD       ), //mantisa B for FP64,FP32,FP16
    .i_man_BE       (o_man_BE       ), //mantisa B for FP64,FP32,FP16
    .i_man_BF       (o_man_BF       ), //mantisa B for FP64,FP32,FP16
    .i_fp64_imbitB  (o_fp64_imbitB  ), 
    .mode_sel_pip1  (mode_sel_pip1  ),
    .o_sign_AB      (o_sign_AB_pip1 ),
    .o_sign_AB_fp64 (o_sign_AB_fp64_pip1 ),
    .o_exp_AB_fp64  (o_exp_AB_fp64_pip1  ),
    .o_exp_max      (o_exp_max      ),
    .o_shift0       (o_shift0       ),
    .o_shift1       (o_shift1       ),
    .o_shift2       (o_shift2       ),
    .o_shift3       (o_shift3       ),
    .o_shift4       (o_shift4       ),
    .o_shift5       (o_shift5       ),
    .o_shift6       (o_shift6       ),
    .o_shift7       (o_shift7       ),
    .o_shift8       (o_shift8       ),
    .o_shift9       (o_shift9       ),
    .o_shiftA       (o_shiftA       ),
    .o_shiftB       (o_shiftB       ),
    .o_shiftC       (o_shiftC       ),
    .o_shiftD       (o_shiftD       ),
    .o_shiftE       (o_shiftE       ),
    .o_shiftF       (o_shiftF       ),
    .o_man_AB0      (o_man_AB0      ),
    .o_man_AB1      (o_man_AB1      ),
    .o_man_AB2      (o_man_AB2      ),
    .o_man_AB3      (o_man_AB3      ),
    .o_man_AB4      (o_man_AB4      ),
    .o_man_AB5      (o_man_AB5      ),
    .o_man_AB6      (o_man_AB6      ),
    .o_man_AB7      (o_man_AB7      ),
    .o_man_AB8      (o_man_AB8      ),
    .o_man_AB9      (o_man_AB9      ),
    .o_man_ABA      (o_man_ABA      ),
    .o_man_ABB      (o_man_ABB      ),
    .o_man_ABC      (o_man_ABC      ),
    .o_man_ABD      (o_man_ABD      ),
    .o_man_ABE      (o_man_ABE      ),
    .o_man_ABF      (o_man_ABF      ),
    .o_man_A_53b    (o_man_A_53b    ), 
    .o_man_B_53b    (o_man_B_53b    )
);

//pipline2 processing
wire [  1:0] mode_sel_pip2      ;
wire         o_sign_pip2        ;
wire         o_sign_AB_fp64_pip2;
wire [ 11:0] o_exp_AB_fp64_pip2 ;
wire [  9:0] o_exp_max_pip2     ;
wire [106:0] o_result_pip2      ;
wire [  6:0] o_lza_cnt          ;
wire         o_lza_invalid      ;
pip2_processing U_pip2_processing(
    .clk           (clk           ),
    .rstn          (rstn          ),
    .mode_sel_pip1 (mode_sel_pip1 ), 
    .i_sign_AB_pip1     (o_sign_AB_pip1 ), //sign for fp32 and fp16
    .i_sign_AB_fp64_pip1(o_sign_AB_fp64_pip1), //sign for fp64
    .i_exp_AB_fp64_pip1 (o_exp_AB_fp64_pip1 ), //exp for fp64
    .i_exp_max     (o_exp_max     ), 
    .i_shift0      (o_shift0      ), 
    .i_shift1      (o_shift1      ), 
    .i_shift2      (o_shift2      ), 
    .i_shift3      (o_shift3      ), 
    .i_shift4      (o_shift4      ), 
    .i_shift5      (o_shift5      ), 
    .i_shift6      (o_shift6      ), 
    .i_shift7      (o_shift7      ), 
    .i_shift8      (o_shift8      ), 
    .i_shift9      (o_shift9      ), 
    .i_shiftA      (o_shiftA      ), 
    .i_shiftB      (o_shiftB      ), 
    .i_shiftC      (o_shiftC      ), 
    .i_shiftD      (o_shiftD      ), 
    .i_shiftE      (o_shiftE      ), 
    .i_shiftF      (o_shiftF      ), 
    .i_man_AB0     (o_man_AB0     ), 
    .i_man_AB1     (o_man_AB1     ), 
    .i_man_AB2     (o_man_AB2     ), 
    .i_man_AB3     (o_man_AB3     ), 
    .i_man_AB4     (o_man_AB4     ), 
    .i_man_AB5     (o_man_AB5     ), 
    .i_man_AB6     (o_man_AB6     ), 
    .i_man_AB7     (o_man_AB7     ), 
    .i_man_AB8     (o_man_AB8     ), 
    .i_man_AB9     (o_man_AB9     ), 
    .i_man_ABA     (o_man_ABA     ), 
    .i_man_ABB     (o_man_ABB     ), 
    .i_man_ABC     (o_man_ABC     ), 
    .i_man_ABD     (o_man_ABD     ), 
    .i_man_ABE     (o_man_ABE     ), 
    .i_man_ABF     (o_man_ABF     ),
    .i_man_A_53b   (o_man_A_53b   ),
    .i_man_B_53b   (o_man_B_53b   ),
    .mode_sel_pip2      (mode_sel_pip2 ),
    .o_sign_AB_fp64_pip2(o_sign_AB_fp64_pip2),
    .o_sign_pip2        (o_sign_pip2        ),
    .o_exp_AB_fp64_pip2 (o_exp_AB_fp64_pip2 ),
    .o_exp_max_pip2     (o_exp_max_pip2     ),
    .o_result_pip2      (o_result_pip2      ),
    .o_lza_cnt          (o_lza_cnt          ),
    .o_lza_invalid      (o_lza_invalid)
);

//pipline3 processing
wire [ 1:0] mode_sel_pip3 ;
wire [63:0] o_norm_result ; 
pip3_processing U_pip3_processing(
    .clk           (clk           ),
    .rstn          (rstn          ),
    .mode_sel_pip2      (mode_sel_pip2 ),
    .i_sign_pip2        (o_sign_pip2        ),
    .i_sign_AB_fp64_pip2(o_sign_AB_fp64_pip2),
    .i_exp_AB_fp64_pip2 (o_exp_AB_fp64_pip2 ),
    .i_exp_max_pip2     (o_exp_max_pip2     ),
    .i_result_pip2      (o_result_pip2      ),
    .i_lza_cnt          (o_lza_cnt          ),
    .mode_sel_pip3      (mode_sel_pip3 ),
    .o_norm_result      (o_norm_result )
);


//output processign
assign result = o_norm_result;
assign mode_out = mode_sel_pip3;

endmodule
//signed
module add_tree_16in #(parameter WIDTH=53)(
    input [1      : 0] mode_sel_pip1,
    input [WIDTH-1: 0] data_in0 ,
    input [WIDTH-1: 0] data_in1 ,
    input [WIDTH-1: 0] data_in2 ,
    input [WIDTH-1: 0] data_in3 ,
    input [WIDTH-1: 0] data_in4 ,
    input [WIDTH-1: 0] data_in5 ,
    input [WIDTH-1: 0] data_in6 ,
    input [WIDTH-1: 0] data_in7 ,
    input [WIDTH-1: 0] data_in8 ,
    input [WIDTH-1: 0] data_in9 ,
    input [WIDTH-1: 0] data_inA ,
    input [WIDTH-1: 0] data_inB ,
    input [WIDTH-1: 0] data_inC ,
    input [WIDTH-1: 0] data_inD ,
    input [WIDTH-1: 0] data_inE ,
    input [WIDTH-1: 0] data_inF ,
    input [52     : 0] i_man_A_53b   , 
    input [52     : 0] i_man_B_53b   , 
    output[108    : 0] sum_out  ,
    output[108    : 0] carry_out,
    output[108    : 0] add_result
);

    wire [WIDTH+1 : 0]       sum0_0;
    wire [WIDTH+1 : 0]     carry0_0;
    wire [WIDTH+1 : 0]       sum0_1;
    wire [WIDTH+1 : 0]     carry0_1;
    wire [WIDTH+1 : 0]       sum0_2;
    wire [WIDTH+1 : 0]     carry0_2;
    wire [WIDTH+1 : 0]       sum0_3;
    wire [WIDTH+1 : 0]     carry0_3;

    pe_CSA4_2 #(WIDTH+2) U00_CSA4_2(
        .a({{2{data_in0[WIDTH-1]}},data_in0}),
	.b({{2{data_in1[WIDTH-1]}},data_in1}),
	.c({{2{data_in2[WIDTH-1]}},data_in2}),
	.d({{2{data_in3[WIDTH-1]}},data_in3}),
	.sum(sum0_0),
	.carry(carry0_0),
	.carry_out()
    );

    pe_CSA4_2 #(WIDTH+2) U01_CSA4_2(
        .a({{2{data_in4[WIDTH-1]}},data_in4}),
	.b({{2{data_in5[WIDTH-1]}},data_in5}),
	.c({{2{data_in6[WIDTH-1]}},data_in6}),
	.d({{2{data_in7[WIDTH-1]}},data_in7}),
	.sum(sum0_1),
	.carry(carry0_1),
	.carry_out()
    );

    pe_CSA4_2 #(WIDTH+2) U02_CSA4_2(
        .a({{2{data_in8[WIDTH-1]}},data_in8}),
	.b({{2{data_in9[WIDTH-1]}},data_in9}),
	.c({{2{data_inA[WIDTH-1]}},data_inA}),
	.d({{2{data_inB[WIDTH-1]}},data_inB}),
	.sum(sum0_2),
	.carry(carry0_2),
	.carry_out()
    );

    pe_CSA4_2 #(WIDTH+2) U03_CSA4_2(
        .a({{2{data_inC[WIDTH-1]}},data_inC}),
	.b({{2{data_inD[WIDTH-1]}},data_inD}),
	.c({{2{data_inE[WIDTH-1]}},data_inE}),
	.d({{2{data_inF[WIDTH-1]}},data_inF}),
	.sum(sum0_3),
	.carry(carry0_3),
	.carry_out()
    );


    wire [WIDTH+2:0]    sum1_0;
    wire [WIDTH+2:0]  carry1_0;
    wire [WIDTH+2:0]    sum1_1;
    wire [WIDTH+2:0]  carry1_1;

    wire [WIDTH+2:0]  u10_cin;
    wire [WIDTH+2:0]  u10_din;
    wire a4b4 = i_man_A_53b[52]&i_man_B_53b[52];
    wire [51:0] a4b3210 = i_man_A_53b[52] ? i_man_A_53b[51:0] : 52'b0;
    wire [51:0] b4a3210 = i_man_B_53b[52] ? i_man_B_53b[51:0] : 52'b0;
    assign u10_cin = mode_sel_pip1[1] ? {3'b0, a4b4, a4b3210} : {sum0_3[WIDTH+1],sum0_3};
    assign u10_din = mode_sel_pip1[1] ? {4'b0, b4a3210} : {carry0_3,1'b0};

    pe_CSA4_2 #(WIDTH+3) U10_CSA4_2(
        .a({sum0_0[WIDTH+1],sum0_0}),
	.b({carry0_0,1'b0}),
	.c(u10_cin),
	.d(u10_din),
	.sum(sum1_0),
	.carry(carry1_0),
	.carry_out()
    );

    pe_CSA4_2 #(WIDTH+3) U11_CSA4_2(
        .a({sum0_1[WIDTH+1],sum0_1}),
	.b({carry0_1,1'b0}),
	.c({sum0_2[WIDTH+1],sum0_2}),
	.d({carry0_2,1'b0}),
	.sum(sum1_1),
	.carry(carry1_1),
	.carry_out()
    );


    wire [WIDTH+3+26: 0]       sum2_0;
    wire [WIDTH+3+26: 0]     carry2_0;

    wire [WIDTH+29 : 0] u20_ain;
    wire [WIDTH+29 : 0] u20_bin;
    wire [WIDTH+29 : 0] u20_cin;
    wire [WIDTH+29 : 0] u20_din;

    assign u20_ain = mode_sel_pip1[1] ? {sum1_0[WIDTH+2],sum1_0,sum0_3[51:26]} : {sum1_0[WIDTH+2],sum1_0,26'b0} ;
    assign u20_bin = mode_sel_pip1[1] ? {carry1_0,1'b0,carry0_3[50:25]}        : {carry1_0,1'b0,26'b0}     ;
    assign u20_cin = mode_sel_pip1[1] ? {26'b0,sum1_1[WIDTH+2],sum1_1} : {sum1_1[WIDTH+2],sum1_1,26'b0};
    assign u20_din = mode_sel_pip1[1] ? {26'b0,carry1_1,1'b0} : {carry1_1,1'b0,26'b0};


    pe_CSA4_2 #(WIDTH+30) U20_CSA4_2(
        .a(u20_ain),
	.b(u20_bin),
	.c(u20_cin),
	.d(u20_din),
	.sum(sum2_0),
	.carry(carry2_0),
	.carry_out()
    );
//*************************accumulation********************//

assign add_result[12:0] = data_inF[12:0];
//assign add_result[108:13] = {sum2_0,sum0_3[25:13]} + {carry2_0[WIDTH+28:0], 1'b0, carry0_3[24:12]};
wire [96:0] adr; 
csla #(96, 9, 10, 6) u_csla({sum2_0,sum0_3[25:13]}, {carry2_0[WIDTH+28:0], 1'b0, carry0_3[24:12]}, adr);
assign add_result[108:13] = adr[95:0];
assign sum_out = {sum2_0, sum0_3[25:0]};
assign carry_out = {carry2_0[WIDTH+28:0], 1'b0, carry0_3[24:0],1'b0};

endmodule
module pe_alignment #(parameter WIDTH=52, EXP_W=10)(
    input  [WIDTH  :0] idata0 ,        
    input  [WIDTH  :0] idata1 ,        
    input  [WIDTH  :0] idata2 ,        
    input  [WIDTH  :0] idata3 ,        
    input  [WIDTH  :0] idata4 ,        
    input  [WIDTH  :0] idata5 ,        
    input  [WIDTH  :0] idata6 ,        
    input  [WIDTH  :0] idata7 ,        
    input  [WIDTH  :0] idata8 ,        
    input  [WIDTH  :0] idata9 ,
    input  [WIDTH  :0] idataA ,
    input  [WIDTH  :0] idataB ,
    input  [WIDTH  :0] idataC ,
    input  [WIDTH  :0] idataD ,
    input  [WIDTH  :0] idataE ,
    input  [WIDTH  :0] idataF ,
    input  [EXP_W-1:0] ishift0,    
    input  [EXP_W-1:0] ishift1,    
    input  [EXP_W-1:0] ishift2,    
    input  [EXP_W-1:0] ishift3,    
    input  [EXP_W-1:0] ishift4,    
    input  [EXP_W-1:0] ishift5,    
    input  [EXP_W-1:0] ishift6,    
    input  [EXP_W-1:0] ishift7,    
    input  [EXP_W-1:0] ishift8,    
    input  [EXP_W-1:0] ishift9,
    input  [EXP_W-1:0] ishiftA,
    input  [EXP_W-1:0] ishiftB,
    input  [EXP_W-1:0] ishiftC,
    input  [EXP_W-1:0] ishiftD,
    input  [EXP_W-1:0] ishiftE,
    input  [EXP_W-1:0] ishiftF,
    output [WIDTH  :0] odata0 ,        
    output [WIDTH  :0] odata1 ,        
    output [WIDTH  :0] odata2 ,        
    output [WIDTH  :0] odata3 ,        
    output [WIDTH  :0] odata4 ,        
    output [WIDTH  :0] odata5 ,        
    output [WIDTH  :0] odata6 ,        
    output [WIDTH  :0] odata7 ,        
    output [WIDTH  :0] odata8 ,        
    output [WIDTH  :0] odata9 ,
    output [WIDTH  :0] odataA ,
    output [WIDTH  :0] odataB ,
    output [WIDTH  :0] odataC ,
    output [WIDTH  :0] odataD ,
    output [WIDTH  :0] odataE ,
    output [WIDTH  :0] odataF    
);
assign odata0 = idata0 >>> ishift0;
assign odata1 = idata1 >>> ishift1;
assign odata2 = idata2 >>> ishift2;
assign odata3 = idata3 >>> ishift3;
assign odata4 = idata4 >>> ishift4;
assign odata5 = idata5 >>> ishift5;
assign odata6 = idata6 >>> ishift6;
assign odata7 = idata7 >>> ishift7;
assign odata8 = idata8 >>> ishift8;
assign odata9 = idata9 >>> ishift9;
assign odataA = idataA >>> ishiftA;
assign odataB = idataB >>> ishiftB;
assign odataC = idataC >>> ishiftC;
assign odataD = idataD >>> ishiftD;
assign odataE = idataE >>> ishiftE;
assign odataF = idataF >>> ishiftF;
endmodule              
module booth_13w(
input[12:0] a,
input[12:0] b,
output[25:0] r
);
wire [25:0] mc={13'b0,  a};
wire [14:0] mp={2'b0, b, 1'b0};

genvar i;
wire [25:0] pp_pord [6:0];
generate
          for(i = 0; i < 7; i = i+1) begin: FtoOne
		  pp_gen #(26) u_pp_gen(.mpb(mc), .code(mp[2*(i+1):2*i]), .pp(pp_pord[i]));
	  end
endgenerate

wire[25:0] shifttempProd00={pp_pord[0]};
wire[25:0] shifttempProd01={pp_pord[1]<<2};
wire[25:0] shifttempProd02={pp_pord[2]<<4};
wire[25:0] shifttempProd03={pp_pord[3]<<6};
wire[25:0] shifttempProd04={pp_pord[4]<<8};
wire[25:0] shifttempProd05={pp_pord[5]<<10};
wire[25:0] shifttempProd06={pp_pord[6]<<12};

wire [25:0] sum_42_0;
wire [25:0] carry_42_0;
wire [25:0] sum_32_0;
wire [25:0] carry_32_0;

pe_CSA4_2 #(26) CSA4_2_1(.a(shifttempProd00), .b(shifttempProd01), .c(shifttempProd02), .d(shifttempProd03), .sum(sum_42_0), .carry(carry_42_0));

pe_CSA3_2 #(26) CSA3_2_1(.a(shifttempProd04), .b(shifttempProd05), .c(shifttempProd06), .sum(sum_32_0), .carry(carry_32_0));

wire[25:0] a_in=sum_42_0[25:0];
wire[25:0] b_in={carry_42_0[24:0],1'b0};
wire[25:0] c_in=sum_32_0[25:0];
wire[25:0] d_in={carry_32_0[24:0],1'b0};
wire[25:0] sum_42_1;
wire[25:0] carry_42_1;

pe_CSA4_2 #(26) CSA4_2_2(.a(a_in), .b(b_in), .c(c_in), .d(d_in), .sum(sum_42_1), .carry(carry_42_1));
	
//assign r = sum_42_1+{carry_42_1[24:0],1'b0};

wire [26:0] result;
csla #(26,5,5,1) csla_0(.in_01(sum_42_1), .in_02({carry_42_1[24:0],1'b0}), .out(result));
assign r=result[25:0];

endmodule
module compare_logic_4in #(parameter WIDTH=11)(
input [3:0] compare,
input [WIDTH-1:0] iexp_0,
input [WIDTH-1:0] iexp_1,
input [WIDTH-1:0] iexp_2,
input [WIDTH-1:0] iexp_3,
input [WIDTH-1:0] pos_diff_01,
input [WIDTH-1:0] pos_diff_12,
input [WIDTH-1:0] pos_diff_23,
input [WIDTH-1:0] pos_diff_30,
input [WIDTH-1:0] pos_diff_02,
input [WIDTH-1:0] pos_diff_13,
input compare_02,
input compare_13,
output reg [WIDTH-1:0] oexp_max,
output reg [WIDTH-1:0] oshift_0,
output reg [WIDTH-1:0] oshift_1,
output reg [WIDTH-1:0] oshift_2,
output reg [WIDTH-1:0] oshift_3
);
always@(*)begin
    case(compare)
	     4'b0000:begin
		      oexp_max = iexp_0; //any input exp
				oshift_0 = 0;
				oshift_1 = 0;
				oshift_2 = 0;
				oshift_3 = 0;
		  end
		  4'b0001:begin
		      oexp_max = iexp_0;
				oshift_0 = 0;
				oshift_1 = pos_diff_01;
				oshift_2 = pos_diff_02;
				oshift_3 = pos_diff_30;
		  end
		  4'b0010:begin
		      oexp_max = iexp_3;
				oshift_0 = pos_diff_30;
				oshift_1 = pos_diff_13;
				oshift_2 = pos_diff_23;
				oshift_3 = 0;
		  end
		  4'b0011:begin
		      oexp_max = iexp_0;
				oshift_0 = 0;
				oshift_1 = pos_diff_01;
				oshift_2 = pos_diff_02;
				oshift_3 = pos_diff_30;
		  end
		  4'b0100:begin
		      oexp_max = iexp_2;
				oshift_0 = pos_diff_02;
				oshift_1 = pos_diff_12;
				oshift_2 = 0;
				oshift_3 = pos_diff_23;
		  end
		  4'b0101:begin
		      oexp_max = compare_02 ? iexp_2      : iexp_0      ;
				oshift_0 = compare_02 ? pos_diff_02 : 0           ;
				oshift_1 = compare_02 ? pos_diff_12 : pos_diff_01 ;
				oshift_2 = compare_02 ? 0           : pos_diff_02 ;
				oshift_3 = compare_02 ? pos_diff_23 : pos_diff_30 ;
		  end
		  4'b0110:begin
		      oexp_max = iexp_3;
				oshift_0 = pos_diff_30;
				oshift_1 = pos_diff_13;
				oshift_2 = pos_diff_23;
				oshift_3 = 0;
		  end
		  4'b0111:begin
		      oexp_max = iexp_0;
				oshift_0 = 0;
				oshift_1 = pos_diff_01;
				oshift_2 = pos_diff_02;
				oshift_3 = pos_diff_30;
		  end
		  4'b1000:begin
		      oexp_max = iexp_1;
				oshift_0 = pos_diff_01;
				oshift_1 = 0;
				oshift_2 = pos_diff_12;
				oshift_3 = pos_diff_13;
		  end
		  4'b1001:begin
		      oexp_max = iexp_1;
				oshift_0 = pos_diff_01;
				oshift_1 = 0;
				oshift_2 = pos_diff_12;
				oshift_3 = pos_diff_13;
		  end
		  4'b1010:begin
		      oexp_max = compare_13 ? iexp_3      : iexp_1      ;
				oshift_0 = compare_13 ? pos_diff_30 : pos_diff_01 ;
				oshift_1 = compare_13 ? pos_diff_13 : 0           ;
				oshift_2 = compare_13 ? pos_diff_23 : pos_diff_12 ;
				oshift_3 = compare_13 ? 0           : pos_diff_13 ;
		  end
		  4'b1011:begin
		      oexp_max = iexp_1;
				oshift_0 = pos_diff_01;
				oshift_1 = 0;
				oshift_2 = pos_diff_12;
				oshift_3 = pos_diff_13;
		  end
		  4'b1100:begin
		      oexp_max = iexp_2;
				oshift_0 = pos_diff_02;
				oshift_1 = pos_diff_12;
				oshift_2 = 0;
				oshift_3 = pos_diff_23;
		  end
		  4'b1101:begin
		      oexp_max = iexp_2;
				oshift_0 = pos_diff_02;
				oshift_1 = pos_diff_12;
				oshift_2 = 0;
				oshift_3 = pos_diff_23;
		  end
		  4'b1110:begin
		      oexp_max = iexp_3;
				oshift_0 = pos_diff_30;
				oshift_1 = pos_diff_13;
				oshift_2 = pos_diff_23;
				oshift_3 = 0;
		  end
		  default:begin
		      oexp_max = iexp_0;
				oshift_0 = 0;
				oshift_1 = 0;
				oshift_2 = 0;
				oshift_3 = 0;
		  end		  
	 endcase
end
endmodule
module pe_cpa#(parameter WIDTH = 64)
(
//input clk,
//input rstn,
input [WIDTH-1:0]a,
input [WIDTH-1:0]b,
output [WIDTH:0]sum
);

//wire [WIDTH:0]sum;
genvar i;
wire [WIDTH-1:0] sum_pord;
wire [WIDTH-1:0] carry_pord;
pe_Hadd Hadd_1(.a(a[0]), .b(b[0]), .sum(sum_pord[0]), .carry(carry_pord[0]));
generate
          for(i = 1; i < WIDTH; i = i+1) begin: FullAdd
		  pe_Fadd Fadd_1(.x(a[i]), .y(b[i]), .Cin(carry_pord[i-1]), .Cout(carry_pord[i]), .Sum(sum_pord[i]));
	  end
endgenerate

assign sum={carry_pord[WIDTH-1],sum_pord};
/*
always@(posedge clk or negedge rstn)begin
    if(rstn==0)begin
        sum_out <= 0;
    end
    else begin
        sum_out <= sum;
    end
end
*/
endmodule
module csla #(parameter WIDTH=29, PRE_WIDTH=6, PRE_UNIT_NUM=4,RCA_WIDTH=5)(
    input [WIDTH-1:0] in_01,
    input [WIDTH-1:0] in_02,
    output [WIDTH  :0] out 
);
wire [RCA_WIDTH:0] sum_rca;
pe_cpa #(RCA_WIDTH) u_cpa(.a(in_01[RCA_WIDTH-1:0]), .b(in_02[RCA_WIDTH-1:0]), .sum(sum_rca));

wire[PRE_WIDTH:0] sum_0 [PRE_UNIT_NUM-1:0];
wire[PRE_WIDTH:0] sum_1 [PRE_UNIT_NUM-1:0];
genvar i;
generate
    for(i=0;i<PRE_UNIT_NUM;i=i+1)begin:pe_csla_unit
        pe_csla_unit #(PRE_WIDTH) u_csla_unit(
	    .in_01(in_01[((i+1)*PRE_WIDTH+RCA_WIDTH-1):i*PRE_WIDTH+RCA_WIDTH]),
	    .in_02(in_02[((i+1)*PRE_WIDTH+RCA_WIDTH-1):i*PRE_WIDTH+RCA_WIDTH]),
	    .sum_0(sum_0[i]),
	    .sum_1(sum_1[i])
	);
    end
endgenerate
wire[PRE_WIDTH:0] sum_sel [PRE_UNIT_NUM-1:0];
assign sum_sel[0] = sum_rca[RCA_WIDTH] ? sum_1[0] : sum_0[0];
generate
    for(i=0;i<PRE_UNIT_NUM-1;i=i+1)begin:sum_sel_check
        assign sum_sel[i+1] = sum_sel[i][PRE_WIDTH] ? sum_1[i+1] : sum_0[i+1];
    end
endgenerate
wire [PRE_WIDTH*PRE_UNIT_NUM-1:0] out_sel;
generate
    for(i=0;i<PRE_UNIT_NUM;i=i+1)begin:output_sel
        assign out_sel[((i+1)*PRE_WIDTH-1):i*PRE_WIDTH] = sum_sel[i][PRE_WIDTH-1:0];
    end
endgenerate
assign out = {sum_sel[PRE_UNIT_NUM-1][PRE_WIDTH], out_sel, sum_rca[RCA_WIDTH-1:0]};

endmodule
module pe_csla_unit #(parameter WIDTH=10)(
   input  [WIDTH-1:0] in_01,
   input  [WIDTH-1:0] in_02,
   output [WIDTH  :0] sum_0,
   output [WIDTH  :0] sum_1
);
wire[WIDTH-1:0] in_01_xor_in_02;
wire[WIDTH-1:0] in_01_and_in_02;
wire[WIDTH-1:0] in_01_or_in_02 ;
wire[WIDTH-1:0] carry_0;
wire[WIDTH-1:0] carry_1;

assign in_01_xor_in_02=in_01^in_02;
assign in_01_and_in_02=in_01&in_02;
assign in_01_or_in_02 =in_01|in_02;
assign sum_0[0] =  in_01_xor_in_02[0];
assign sum_1[0] = ~in_01_xor_in_02[0];
assign carry_0[0] = in_01_and_in_02[0];
assign carry_1[0] = in_01_or_in_02 [0];
genvar i;
generate 
    for(i=0;i<WIDTH-1;i=i+1)begin:get_sum
        assign sum_0  [i+1] = carry_0[i] ? ~in_01_xor_in_02[i+1] : in_01_xor_in_02[i+1];
	assign sum_1  [i+1] = carry_1[i] ? ~in_01_xor_in_02[i+1] : in_01_xor_in_02[i+1];
	assign carry_0[i+1] = carry_0[i] ? in_01_or_in_02  [i+1] : in_01_and_in_02[i+1];
	assign carry_1[i+1] = carry_1[i] ? in_01_or_in_02  [i+1] : in_01_and_in_02[i+1];
    end
endgenerate
assign sum_0[WIDTH] = carry_0[WIDTH-1];
assign sum_1[WIDTH] = carry_1[WIDTH-1];
endmodule
module exp_compare_16in #(parameter WIDTH=11)(
    input [WIDTH-1:0] iexp_00,
    input [WIDTH-1:0] iexp_01,
    input [WIDTH-1:0] iexp_02,
    input [WIDTH-1:0] iexp_03,
    input [WIDTH-1:0] iexp_04,
    input [WIDTH-1:0] iexp_05,
    input [WIDTH-1:0] iexp_06,
    input [WIDTH-1:0] iexp_07,
    input [WIDTH-1:0] iexp_08,
    input [WIDTH-1:0] iexp_09,
    input [WIDTH-1:0] iexp_10,
    input [WIDTH-1:0] iexp_11,
    input [WIDTH-1:0] iexp_12,
    input [WIDTH-1:0] iexp_13,
    input [WIDTH-1:0] iexp_14,
    input [WIDTH-1:0] iexp_15,
    output  [WIDTH-1:0] oexp_max,
    output  [WIDTH-1:0] oshift_00,
    output  [WIDTH-1:0] oshift_01,
    output  [WIDTH-1:0] oshift_02,
    output  [WIDTH-1:0] oshift_03,
    output  [WIDTH-1:0] oshift_04,
    output  [WIDTH-1:0] oshift_05,
    output  [WIDTH-1:0] oshift_06,
    output  [WIDTH-1:0] oshift_07,
    output  [WIDTH-1:0] oshift_08,
    output  [WIDTH-1:0] oshift_09,
    output  [WIDTH-1:0] oshift_10,
    output  [WIDTH-1:0] oshift_11,
    output  [WIDTH-1:0] oshift_12,
    output  [WIDTH-1:0] oshift_13,
    output  [WIDTH-1:0] oshift_14,
    output  [WIDTH-1:0] oshift_15
);

wire [WIDTH-1:0] shift_00;
wire [WIDTH-1:0] shift_01;
wire [WIDTH-1:0] shift_02;
wire [WIDTH-1:0] shift_03;
wire [WIDTH-1:0] exp_max_0;

wire [WIDTH-1:0] shift_04;
wire [WIDTH-1:0] shift_05;
wire [WIDTH-1:0] shift_06;
wire [WIDTH-1:0] shift_07;
wire [WIDTH-1:0] exp_max_1;

wire [WIDTH-1:0] shift_08;
wire [WIDTH-1:0] shift_09;
wire [WIDTH-1:0] shift_10;
wire [WIDTH-1:0] shift_11;
wire [WIDTH-1:0] exp_max_2;

wire [WIDTH-1:0] shift_12;
wire [WIDTH-1:0] shift_13;
wire [WIDTH-1:0] shift_14;
wire [WIDTH-1:0] shift_15;
wire [WIDTH-1:0] exp_max_3;

wire [WIDTH-1:0] max_shift_0;
wire [WIDTH-1:0] max_shift_1;
wire [WIDTH-1:0] max_shift_2;
wire [WIDTH-1:0] max_shift_3;

exp_compare_unit_4in #(WIDTH)u_compare_0(
   .iexp_0(iexp_00),
	.iexp_1(iexp_01),
	.iexp_2(iexp_02),
	.iexp_3(iexp_03),
	.oexp_max(exp_max_0),
	.oshift_0(shift_00),
	.oshift_1(shift_01),
	.oshift_2(shift_02),
	.oshift_3(shift_03)
);


exp_compare_unit_4in #(WIDTH)u_compare_1(
   .iexp_0(iexp_04),
	.iexp_1(iexp_05),
	.iexp_2(iexp_06),
	.iexp_3(iexp_07),
	.oexp_max(exp_max_1),
	.oshift_0(shift_04),
	.oshift_1(shift_05),
	.oshift_2(shift_06),
	.oshift_3(shift_07)
);

exp_compare_unit_4in #(WIDTH)u_compare_2(
   .iexp_0(iexp_08),
	.iexp_1(iexp_09),
	.iexp_2(iexp_10),
	.iexp_3(iexp_11),
	.oexp_max(exp_max_2),
	.oshift_0(shift_08),
	.oshift_1(shift_09),
	.oshift_2(shift_10),
	.oshift_3(shift_11)
);


exp_compare_unit_4in #(WIDTH)u_compare_3(
   .iexp_0(iexp_12),
	.iexp_1(iexp_13),
	.iexp_2(iexp_14),
	.iexp_3(iexp_15),
	.oexp_max(exp_max_3),
	.oshift_0(shift_12),
	.oshift_1(shift_13),
	.oshift_2(shift_14),
	.oshift_3(shift_15)
);

exp_compare_unit_4in #(WIDTH)u_compare_4(
   .iexp_0(exp_max_0),
	.iexp_1(exp_max_1),
	.iexp_2(exp_max_2),
	.iexp_3(exp_max_3),
	.oexp_max(oexp_max),
	.oshift_0(max_shift_0),
	.oshift_1(max_shift_1),
	.oshift_2(max_shift_2),
	.oshift_3(max_shift_3)
);

assign oshift_00 = shift_00 + max_shift_0;
assign oshift_01 = shift_01 + max_shift_0;
assign oshift_02 = shift_02 + max_shift_0;
assign oshift_03 = shift_03 + max_shift_0;

assign oshift_04 = shift_04 + max_shift_1;
assign oshift_05 = shift_05 + max_shift_1;
assign oshift_06 = shift_06 + max_shift_1;
assign oshift_07 = shift_07 + max_shift_1;

assign oshift_08 = shift_08 + max_shift_2;
assign oshift_09 = shift_09 + max_shift_2;
assign oshift_10 = shift_10 + max_shift_2;
assign oshift_11 = shift_11 + max_shift_2;

assign oshift_12 = shift_12 + max_shift_3;
assign oshift_13 = shift_13 + max_shift_3;
assign oshift_14 = shift_14 + max_shift_3;
assign oshift_15 = shift_15 + max_shift_3;

endmodule
module exp_compare_unit_4in#(parameter WIDTH=11)(
    input [WIDTH-1:0] iexp_0,
	 input [WIDTH-1:0] iexp_1,
	 input [WIDTH-1:0] iexp_2,
	 input [WIDTH-1:0] iexp_3,
	 output [WIDTH-1:0] oexp_max,
	 output [WIDTH-1:0] oshift_0,
	 output [WIDTH-1:0] oshift_1,
	 output [WIDTH-1:0] oshift_2,
	 output [WIDTH-1:0] oshift_3
);
wire [WIDTH:0] diff_01; //different between iexp_0 and iexp_1
wire [WIDTH:0] diff_12;
wire [WIDTH:0] diff_23;
wire [WIDTH:0] diff_30;
wire [WIDTH:0] diff_02;
wire [WIDTH:0] diff_13;

wire [WIDTH-1:0] inv_iexp_0;
wire [WIDTH-1:0] inv_iexp_1;
wire [WIDTH-1:0] inv_iexp_2;
wire [WIDTH-1:0] inv_iexp_3;

assign inv_iexp_0 = ~iexp_0;
assign inv_iexp_1 = ~iexp_1;
assign inv_iexp_2 = ~iexp_2;
assign inv_iexp_3 = ~iexp_3;

assign diff_01 = {1'b0,iexp_0}+{1'b1,inv_iexp_1};
assign diff_12 = {1'b0,iexp_1}+{1'b1,inv_iexp_2};
assign diff_23 = {1'b0,iexp_2}+{1'b1,inv_iexp_3};
assign diff_30 = {1'b0,iexp_3}+{1'b1,inv_iexp_0};
assign diff_02 = {1'b0,iexp_0}+{1'b1,inv_iexp_2};
assign diff_13 = {1'b0,iexp_1}+{1'b1,inv_iexp_3};

/*
assign diff_01 = iexp_0-iexp_1;
assign diff_12 = iexp_1-iexp_2;
assign diff_23 = iexp_2-iexp_3;
assign diff_30 = iexp_3-iexp_0;
assign diff_02 = iexp_0-iexp_2;
assign diff_13 = iexp_1-iexp_3;
*/

wire compare_01 = diff_01[WIDTH];
wire compare_12 = diff_12[WIDTH];
wire compare_23 = diff_23[WIDTH];
wire compare_30 = diff_30[WIDTH];
wire compare_02 = diff_02[WIDTH];
wire compare_13 = diff_13[WIDTH];

wire [WIDTH-1:0] pos_diff_01; //postive of the diff_01
wire [WIDTH-1:0] pos_diff_12;
wire [WIDTH-1:0] pos_diff_23;
wire [WIDTH-1:0] pos_diff_30;
wire [WIDTH-1:0] pos_diff_02;
wire [WIDTH-1:0] pos_diff_13;

/*
assign pos_diff_01 = compare_01 ? (~diff_01[WIDTH-1:0]+1'b1) : (diff_01[WIDTH-1:0]);
assign pos_diff_12 = compare_12 ? (~diff_12[WIDTH-1:0]+1'b1) : (diff_12[WIDTH-1:0]);
assign pos_diff_23 = compare_23 ? (~diff_23[WIDTH-1:0]+1'b1) : (diff_23[WIDTH-1:0]);
assign pos_diff_30 = compare_30 ? (~diff_30[WIDTH-1:0]+1'b1) : (diff_30[WIDTH-1:0]);
assign pos_diff_02 = compare_02 ? (~diff_02[WIDTH-1:0]+1'b1) : (diff_02[WIDTH-1:0]);
assign pos_diff_13 = compare_13 ? (~diff_13[WIDTH-1:0]+1'b1) : (diff_13[WIDTH-1:0]);
*/
assign pos_diff_01 = compare_01 ? (~diff_01[WIDTH-1:0]) : (diff_01[WIDTH-1:0]+1'b1);
assign pos_diff_12 = compare_12 ? (~diff_12[WIDTH-1:0]) : (diff_12[WIDTH-1:0]+1'b1);
assign pos_diff_23 = compare_23 ? (~diff_23[WIDTH-1:0]) : (diff_23[WIDTH-1:0]+1'b1);
assign pos_diff_30 = compare_30 ? (~diff_30[WIDTH-1:0]) : (diff_30[WIDTH-1:0]+1'b1);
assign pos_diff_02 = compare_02 ? (~diff_02[WIDTH-1:0]) : (diff_02[WIDTH-1:0]+1'b1);
assign pos_diff_13 = compare_13 ? (~diff_13[WIDTH-1:0]) : (diff_13[WIDTH-1:0]+1'b1);

wire[3:0] compare = {compare_01,compare_12,compare_23,compare_30};
/*
always@(*)begin
    case(compare)
	     4'b0000:begin
		      oexp_max = iexp_0; //any input exp
				oshift_0 = 0;
				oshift_1 = 0;
				oshift_2 = 0;
				oshift_3 = 0;
		  end
		  4'b0001:begin
		      oexp_max = iexp_0;
				oshift_0 = 0;
				oshift_1 = pos_diff_01;
				oshift_2 = pos_diff_02;
				oshift_3 = pos_diff_30;
		  end
		  4'b0010:begin
		      oexp_max = iexp_3;
				oshift_0 = pos_diff_30;
				oshift_1 = pos_diff_13;
				oshift_2 = pos_diff_23;
				oshift_3 = 0;
		  end
		  4'b0011:begin
		      oexp_max = iexp_0;
				oshift_0 = 0;
				oshift_1 = pos_diff_01;
				oshift_2 = pos_diff_02;
				oshift_3 = pos_diff_30;
		  end
		  4'b0100:begin
		      oexp_max = iexp_2;
				oshift_0 = pos_diff_02;
				oshift_1 = pos_diff_12;
				oshift_2 = 0;
				oshift_3 = pos_diff_23;
		  end
		  4'b0101:begin
		      oexp_max = compare_02 ? iexp_2      : iexp_0      ;
				oshift_0 = compare_02 ? pos_diff_02 : 0           ;
				oshift_1 = compare_02 ? pos_diff_12 : pos_diff_01 ;
				oshift_2 = compare_02 ? 0           : pos_diff_02 ;
				oshift_3 = compare_02 ? pos_diff_23 : pos_diff_30 ;
		  end
		  4'b0110:begin
		      oexp_max = iexp_3;
				oshift_0 = pos_diff_30;
				oshift_1 = pos_diff_13;
				oshift_2 = pos_diff_23;
				oshift_3 = 0;
		  end
		  4'b0111:begin
		      oexp_max = iexp_0;
				oshift_0 = 0;
				oshift_1 = pos_diff_01;
				oshift_2 = pos_diff_02;
				oshift_3 = pos_diff_30;
		  end
		  4'b1000:begin
		      oexp_max = iexp_1;
				oshift_0 = pos_diff_01;
				oshift_1 = 0;
				oshift_2 = pos_diff_12;
				oshift_3 = pos_diff_13;
		  end
		  4'b1001:begin
		      oexp_max = iexp_1;
				oshift_0 = pos_diff_01;
				oshift_1 = 0;
				oshift_2 = pos_diff_12;
				oshift_3 = pos_diff_13;
		  end
		  4'b1010:begin
		      oexp_max = compare_13 ? iexp_3      : iexp_1      ;
				oshift_0 = compare_13 ? pos_diff_30 : pos_diff_01 ;
				oshift_1 = compare_13 ? pos_diff_13 : 0           ;
				oshift_2 = compare_13 ? pos_diff_23 : pos_diff_12 ;
				oshift_3 = compare_13 ? 0           : pos_diff_13 ;
		  end
		  4'b1011:begin
		      oexp_max = iexp_1;
				oshift_0 = pos_diff_01;
				oshift_1 = 0;
				oshift_2 = pos_diff_12;
				oshift_3 = pos_diff_13;
		  end
		  4'b1100:begin
		      oexp_max = iexp_2;
				oshift_0 = pos_diff_02;
				oshift_1 = pos_diff_12;
				oshift_2 = 0;
				oshift_3 = pos_diff_23;
		  end
		  4'b1101:begin
		      oexp_max = iexp_2;
				oshift_0 = pos_diff_02;
				oshift_1 = pos_diff_12;
				oshift_2 = 0;
				oshift_3 = pos_diff_23;
		  end
		  4'b1110:begin
		      oexp_max = iexp_3;
				oshift_0 = pos_diff_30;
				oshift_1 = pos_diff_13;
				oshift_2 = pos_diff_23;
				oshift_3 = 0;
		  end
		  default:begin
		      oexp_max = iexp_0;
				oshift_0 = 0;
				oshift_1 = 0;
				oshift_2 = 0;
				oshift_3 = 0;
		  end		  
	 endcase
end
*/
compare_logic_4in #(WIDTH) u_CL(
.compare    (compare    ),
.iexp_0     (iexp_0     ),
.iexp_1     (iexp_1     ),
.iexp_2     (iexp_2     ),
.iexp_3     (iexp_3     ),
.pos_diff_01(pos_diff_01),
.pos_diff_12(pos_diff_12),
.pos_diff_23(pos_diff_23),
.pos_diff_30(pos_diff_30),
.pos_diff_02(pos_diff_02),
.pos_diff_13(pos_diff_13),
.compare_02 (compare_02 ),
.compare_13 (compare_13 ),
.oexp_max   (oexp_max   ),
.oshift_0   (oshift_0   ),
.oshift_1   (oshift_1   ),
.oshift_2   (oshift_2   ),
.oshift_3   (oshift_3   )
);


endmodule

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
    wire fp16_imbitB;
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
module lza #(parameter WIDTH = 107)(
    input [WIDTH-1:0] in_01,
    input [WIDTH-1:0] in_02,
    output reg [6:0] zero_cnt,
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


// Leading zero count of f_out
reg [63:0] val64;
reg [31:0] val32;
reg [15:0] val16;
reg [ 7:0] val8 ;
reg [ 3:0] val4 ;

always@(*)begin
    if((f_out == 107'b0)) begin
        zero_cnt = 107;
        invalid  = 1'b1;
    end
    else begin
        invalid = 1'b0;
        zero_cnt[6] = (f_out[WIDTH-1:WIDTH-64]==64'b0);
        val64 = zero_cnt[6] ? {f_out[WIDTH-65:0],21'b0} : (f_out[WIDTH-1:WIDTH-64]);
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
module mul_array #(parameter WIDTH = 13)(
    input  [WIDTH-1:0] i_man_A00     ,
    input  [WIDTH-1:0] i_man_A01     ,
    input  [WIDTH-1:0] i_man_A02     ,
    input  [WIDTH-1:0] i_man_A03     ,
    input  [WIDTH-1:0] i_man_A04     ,
    input  [WIDTH-1:0] i_man_A05     ,
    input  [WIDTH-1:0] i_man_A06     ,
    input  [WIDTH-1:0] i_man_A07     ,
    input  [WIDTH-1:0] i_man_A08     ,
    input  [WIDTH-1:0] i_man_A09     ,
    input  [WIDTH-1:0] i_man_A10     ,
    input  [WIDTH-1:0] i_man_A11     ,
    input  [WIDTH-1:0] i_man_A12     ,
    input  [WIDTH-1:0] i_man_A13     ,
    input  [WIDTH-1:0] i_man_A14     ,
    input  [WIDTH-1:0] i_man_A15     ,
    input  [WIDTH-1:0] i_man_B00     ,
    input  [WIDTH-1:0] i_man_B01     ,
    input  [WIDTH-1:0] i_man_B02     ,
    input  [WIDTH-1:0] i_man_B03     ,
    input  [WIDTH-1:0] i_man_B04     ,
    input  [WIDTH-1:0] i_man_B05     ,
    input  [WIDTH-1:0] i_man_B06     ,
    input  [WIDTH-1:0] i_man_B07     ,
    input  [WIDTH-1:0] i_man_B08     ,
    input  [WIDTH-1:0] i_man_B09     ,
    input  [WIDTH-1:0] i_man_B10     ,
    input  [WIDTH-1:0] i_man_B11     ,
    input  [WIDTH-1:0] i_man_B12     ,
    input  [WIDTH-1:0] i_man_B13     ,
    input  [WIDTH-1:0] i_man_B14     ,
    input  [WIDTH-1:0] i_man_B15     ,
    output [2*WIDTH-1:0] oman_AB00   , 
    output [2*WIDTH-1:0] oman_AB01   , 
    output [2*WIDTH-1:0] oman_AB02   , 
    output [2*WIDTH-1:0] oman_AB03   , 
    output [2*WIDTH-1:0] oman_AB04   , 
    output [2*WIDTH-1:0] oman_AB05   , 
    output [2*WIDTH-1:0] oman_AB06   , 
    output [2*WIDTH-1:0] oman_AB07   , 
    output [2*WIDTH-1:0] oman_AB08   , 
    output [2*WIDTH-1:0] oman_AB09   , 
    output [2*WIDTH-1:0] oman_AB10   , 
    output [2*WIDTH-1:0] oman_AB11   , 
    output [2*WIDTH-1:0] oman_AB12   , 
    output [2*WIDTH-1:0] oman_AB13   , 
    output [2*WIDTH-1:0] oman_AB14   , 
    output [2*WIDTH-1:0] oman_AB15    
);

//mul array
booth_13w u_booth00(.a(i_man_A00),.b(i_man_B00), .r(oman_AB00));
booth_13w u_booth01(.a(i_man_A01),.b(i_man_B01), .r(oman_AB01));
booth_13w u_booth02(.a(i_man_A02),.b(i_man_B02), .r(oman_AB02));
booth_13w u_booth03(.a(i_man_A03),.b(i_man_B03), .r(oman_AB03));
booth_13w u_booth04(.a(i_man_A04),.b(i_man_B04), .r(oman_AB04));
booth_13w u_booth05(.a(i_man_A05),.b(i_man_B05), .r(oman_AB05));
booth_13w u_booth06(.a(i_man_A06),.b(i_man_B06), .r(oman_AB06));
booth_13w u_booth07(.a(i_man_A07),.b(i_man_B07), .r(oman_AB07));
booth_13w u_booth08(.a(i_man_A08),.b(i_man_B08), .r(oman_AB08));
booth_13w u_booth09(.a(i_man_A09),.b(i_man_B09), .r(oman_AB09));
booth_13w u_booth10(.a(i_man_A10),.b(i_man_B10), .r(oman_AB10));
booth_13w u_booth11(.a(i_man_A11),.b(i_man_B11), .r(oman_AB11));
booth_13w u_booth12(.a(i_man_A12),.b(i_man_B12), .r(oman_AB12));
booth_13w u_booth13(.a(i_man_A13),.b(i_man_B13), .r(oman_AB13));
booth_13w u_booth14(.a(i_man_A14),.b(i_man_B14), .r(oman_AB14));
booth_13w u_booth15(.a(i_man_A15),.b(i_man_B15), .r(oman_AB15));

endmodule
module pip1_processing (
    input         clk             ,
    input         rstn            ,
    input  [ 1:0] mode_sel_pip0   , //mode sel input
    input  [15:0] i_sign_AB      , //sign AB of fp16 and fp32; 
    input         i_sign_AB_fp64 , //sign AB for FP64
    input  [11:0] i_exp_AB_fp64  , //exp AB for FP64
    input  [ 9:0] i_exp_AB0      , //exp AB for FP64,FP32,FP16
    input  [ 9:0] i_exp_AB1      , //exp AB for FP64,FP32,FP16
    input  [ 9:0] i_exp_AB2      , //exp AB for FP64,FP32,FP16
    input  [ 9:0] i_exp_AB3      , //exp AB for FP64,FP32,FP16
    input  [ 9:0] i_exp_AB4      , //exp AB for FP64,FP32,FP16
    input  [ 9:0] i_exp_AB5      , //exp AB for FP64,FP32,FP16
    input  [ 9:0] i_exp_AB6      , //exp AB for FP64,FP32,FP16
    input  [ 9:0] i_exp_AB7      , //exp AB for FP64,FP32,FP16
    input  [ 9:0] i_exp_AB8      , //exp AB for FP64,FP32,FP16
    input  [ 9:0] i_exp_AB9      , //exp AB for FP64,FP32,FP16
    input  [ 9:0] i_exp_ABA      , //exp AB for FP64,FP32,FP16
    input  [ 9:0] i_exp_ABB      , //exp AB for FP64,FP32,FP16
    input  [ 9:0] i_exp_ABC      , //exp AB for FP64,FP32,FP16
    input  [ 9:0] i_exp_ABD      , //exp AB for FP64,FP32,FP16
    input  [ 9:0] i_exp_ABE      , //exp AB for FP64,FP32,FP16
    input  [ 9:0] i_exp_ABF      , //exp AB for FP64,FP32,FP16
    input  [12:0] i_man_A0      , //mantisa A for FP64,FP32,FP16
    input  [12:0] i_man_A1      , //mantisa A for FP64,FP32,FP16
    input  [12:0] i_man_A2      , //mantisa A for FP64,FP32,FP16
    input  [12:0] i_man_A3      , //mantisa A for FP64,FP32,FP16
    input  [12:0] i_man_A4      , //mantisa A for FP64,FP32,FP16
    input  [12:0] i_man_A5      , //mantisa A for FP64,FP32,FP16
    input  [12:0] i_man_A6      , //mantisa A for FP64,FP32,FP16
    input  [12:0] i_man_A7      , //mantisa A for FP64,FP32,FP16
    input  [12:0] i_man_A8      , //mantisa A for FP64,FP32,FP16
    input  [12:0] i_man_A9      , //mantisa A for FP64,FP32,FP16
    input  [12:0] i_man_AA      , //mantisa A for FP64,FP32,FP16
    input  [12:0] i_man_AB      , //mantisa A for FP64,FP32,FP16
    input  [12:0] i_man_AC      , //mantisa A for FP64,FP32,FP16
    input  [12:0] i_man_AD      , //mantisa A for FP64,FP32,FP16
    input  [12:0] i_man_AE      , //mantisa A for FP64,FP32,FP16
    input  [12:0] i_man_AF      , //mantisa A for FP64,FP32,FP16
    input         i_fp64_imbitA , 
    input  [12:0] i_man_B0      , //mantisa B for FP64,FP32,FP16
    input  [12:0] i_man_B1      , //mantisa B for FP64,FP32,FP16
    input  [12:0] i_man_B2      , //mantisa B for FP64,FP32,FP16
    input  [12:0] i_man_B3      , //mantisa B for FP64,FP32,FP16
    input  [12:0] i_man_B4      , //mantisa B for FP64,FP32,FP16
    input  [12:0] i_man_B5      , //mantisa B for FP64,FP32,FP16
    input  [12:0] i_man_B6      , //mantisa B for FP64,FP32,FP16
    input  [12:0] i_man_B7      , //mantisa B for FP64,FP32,FP16
    input  [12:0] i_man_B8      , //mantisa B for FP64,FP32,FP16
    input  [12:0] i_man_B9      , //mantisa B for FP64,FP32,FP16
    input  [12:0] i_man_BA      , //mantisa B for FP64,FP32,FP16
    input  [12:0] i_man_BB      , //mantisa B for FP64,FP32,FP16
    input  [12:0] i_man_BC      , //mantisa B for FP64,FP32,FP16
    input  [12:0] i_man_BD      , //mantisa B for FP64,FP32,FP16
    input  [12:0] i_man_BE      , //mantisa B for FP64,FP32,FP16
    input  [12:0] i_man_BF      , //mantisa B for FP64,FP32,FP16
    input         i_fp64_imbitB , 
    output reg [ 1:0] mode_sel_pip1 ,
    output reg [15:0] o_sign_AB     ,
    output reg        o_sign_AB_fp64,
    output reg [11:0] o_exp_AB_fp64 ,
    output reg [ 9:0] o_exp_max     ,
    output reg [ 9:0] o_shift0      ,
    output reg [ 9:0] o_shift1      ,
    output reg [ 9:0] o_shift2      ,
    output reg [ 9:0] o_shift3      ,
    output reg [ 9:0] o_shift4      ,
    output reg [ 9:0] o_shift5      ,
    output reg [ 9:0] o_shift6      ,
    output reg [ 9:0] o_shift7      ,
    output reg [ 9:0] o_shift8      ,
    output reg [ 9:0] o_shift9      ,
    output reg [ 9:0] o_shiftA      ,
    output reg [ 9:0] o_shiftB      ,
    output reg [ 9:0] o_shiftC      ,
    output reg [ 9:0] o_shiftD      ,
    output reg [ 9:0] o_shiftE      ,
    output reg [ 9:0] o_shiftF      ,
    output reg [25:0] o_man_AB0     ,
    output reg [25:0] o_man_AB1     ,
    output reg [25:0] o_man_AB2     ,
    output reg [25:0] o_man_AB3     ,
    output reg [25:0] o_man_AB4     ,
    output reg [25:0] o_man_AB5     ,
    output reg [25:0] o_man_AB6     ,
    output reg [25:0] o_man_AB7     ,
    output reg [25:0] o_man_AB8     ,
    output reg [25:0] o_man_AB9     ,
    output reg [25:0] o_man_ABA     ,
    output reg [25:0] o_man_ABB     ,
    output reg [25:0] o_man_ABC     ,
    output reg [25:0] o_man_ABD     ,
    output reg [25:0] o_man_ABE     ,
    output reg [25:0] o_man_ABF     ,
    output reg [52:0] o_man_A_53b   , 
    output reg [52:0] o_man_B_53b   
);
//clock count output
always@(posedge clk or negedge rstn)begin
    if(!rstn)begin
        mode_sel_pip1<= 2'b11;
    end
    else begin
        mode_sel_pip1<= mode_sel_pip0;
    end
end

//sign processing
always@(posedge clk)begin
    o_sign_AB <= i_sign_AB;
    o_sign_AB_fp64 <= i_sign_AB_fp64;
end

//exp copmare
 
wire [9:0] oexp_max ;
wire [9:0] oshift_00;
wire [9:0] oshift_01;
wire [9:0] oshift_02;
wire [9:0] oshift_03;
wire [9:0] oshift_04;
wire [9:0] oshift_05;
wire [9:0] oshift_06;
wire [9:0] oshift_07;
wire [9:0] oshift_08;
wire [9:0] oshift_09;
wire [9:0] oshift_10;
wire [9:0] oshift_11;
wire [9:0] oshift_12;
wire [9:0] oshift_13;
wire [9:0] oshift_14;
wire [9:0] oshift_15;

exp_compare_16in #(10)u_exp_compare(
        .iexp_00(i_exp_AB0),
	.iexp_01(i_exp_AB1),
	.iexp_02(i_exp_AB2),
	.iexp_03(i_exp_AB3),
	.iexp_04(i_exp_AB4),
	.iexp_05(i_exp_AB5),
	.iexp_06(i_exp_AB6),
	.iexp_07(i_exp_AB7),
	.iexp_08(i_exp_AB8),
	.iexp_09(i_exp_AB9),
	.iexp_10(i_exp_ABA),
	.iexp_11(i_exp_ABB),
	.iexp_12(i_exp_ABC),
	.iexp_13(i_exp_ABD),
	.iexp_14(i_exp_ABE),
	.iexp_15(i_exp_ABF),
	.oexp_max(oexp_max),
	.oshift_00(oshift_00),
	.oshift_01(oshift_01),
	.oshift_02(oshift_02),
	.oshift_03(oshift_03),
	.oshift_04(oshift_04),
	.oshift_05(oshift_05),
	.oshift_06(oshift_06),
	.oshift_07(oshift_07),
	.oshift_08(oshift_08),
	.oshift_09(oshift_09),
	.oshift_10(oshift_10),
	.oshift_11(oshift_11),
	.oshift_12(oshift_12),
	.oshift_13(oshift_13),
	.oshift_14(oshift_14),
	.oshift_15(oshift_15)
	);

always@(posedge clk)begin
    o_exp_AB_fp64 <= i_exp_AB_fp64 ; //fp64 output
    o_exp_max     <= oexp_max ;
    o_shift0      <= oshift_00;
    o_shift1      <= oshift_01;
    o_shift2      <= oshift_02;
    o_shift3      <= oshift_03;
    o_shift4      <= oshift_04;
    o_shift5      <= oshift_05;
    o_shift6      <= oshift_06;
    o_shift7      <= oshift_07;
    o_shift8      <= oshift_08;
    o_shift9      <= oshift_09;
    o_shiftA      <= oshift_10;
    o_shiftB      <= oshift_11;
    o_shiftC      <= oshift_12;
    o_shiftD      <= oshift_13;
    o_shiftE      <= oshift_14;
    o_shiftF      <= oshift_15;
end

//mul array
wire [25:0] oman_AB0;     
wire [25:0] oman_AB1;     
wire [25:0] oman_AB2;     
wire [25:0] oman_AB3;     
wire [25:0] oman_AB4;     
wire [25:0] oman_AB5;     
wire [25:0] oman_AB6;     
wire [25:0] oman_AB7;     
wire [25:0] oman_AB8;     
wire [25:0] oman_AB9;     
wire [25:0] oman_ABA;     
wire [25:0] oman_ABB;     
wire [25:0] oman_ABC;     
wire [25:0] oman_ABD;     
wire [25:0] oman_ABE;     
wire [25:0] oman_ABF;     

mul_array #(13) u_mul_array(
    .i_man_A00     (i_man_A0     ), 
    .i_man_A01     (i_man_A1     ), 
    .i_man_A02     (i_man_A2     ),  
    .i_man_A03     (i_man_A3     ),  
    .i_man_A04     (i_man_A4     ),  
    .i_man_A05     (i_man_A5     ),  
    .i_man_A06     (i_man_A6     ),  
    .i_man_A07     (i_man_A7     ),  
    .i_man_A08     (i_man_A8     ),  
    .i_man_A09     (i_man_A9     ),  
    .i_man_A10     (i_man_AA     ),  
    .i_man_A11     (i_man_AB     ),  
    .i_man_A12     (i_man_AC     ),  
    .i_man_A13     (i_man_AD     ),  
    .i_man_A14     (i_man_AE     ),  
    .i_man_A15     (i_man_AF     ),  
    .i_man_B00     (i_man_B0     ),  
    .i_man_B01     (i_man_B1     ),  
    .i_man_B02     (i_man_B2     ),  
    .i_man_B03     (i_man_B3     ),  
    .i_man_B04     (i_man_B4     ),  
    .i_man_B05     (i_man_B5     ),  
    .i_man_B06     (i_man_B6     ),  
    .i_man_B07     (i_man_B7     ),  
    .i_man_B08     (i_man_B8     ),  
    .i_man_B09     (i_man_B9     ),  
    .i_man_B10     (i_man_BA     ),  
    .i_man_B11     (i_man_BB     ),  
    .i_man_B12     (i_man_BC     ),  
    .i_man_B13     (i_man_BD     ),  
    .i_man_B14     (i_man_BE     ),  
    .i_man_B15     (i_man_BF     ), 
    .oman_AB00     (oman_AB0     ), 
    .oman_AB01     (oman_AB1     ), 
    .oman_AB02     (oman_AB2     ), 
    .oman_AB03     (oman_AB3     ), 
    .oman_AB04     (oman_AB4     ), 
    .oman_AB05     (oman_AB5     ), 
    .oman_AB06     (oman_AB6     ), 
    .oman_AB07     (oman_AB7     ), 
    .oman_AB08     (oman_AB8     ), 
    .oman_AB09     (oman_AB9     ), 
    .oman_AB10     (oman_ABA     ), 
    .oman_AB11     (oman_ABB     ), 
    .oman_AB12     (oman_ABC     ),
    .oman_AB13     (oman_ABD     ), 
    .oman_AB14     (oman_ABE     ), 
    .oman_AB15     (oman_ABF     ) 
);
wire [26:0] inv_man_AB0;
wire [26:0] inv_man_AB1;
wire [26:0] inv_man_AB2;
wire [26:0] inv_man_AB3;
wire [26:0] inv_man_AB4;
wire [26:0] inv_man_AB5;
wire [26:0] inv_man_AB6;
wire [26:0] inv_man_AB7;
wire [26:0] inv_man_AB8;
wire [26:0] inv_man_AB9;
wire [26:0] inv_man_ABA;
wire [26:0] inv_man_ABB;
wire [26:0] inv_man_ABC;
wire [26:0] inv_man_ABD;
wire [26:0] inv_man_ABE;
wire [26:0] inv_man_ABF;
/*
assign inv_man_AB0 = ~oman_AB0+1'b1;
assign inv_man_AB1 = ~oman_AB1+1'b1;
assign inv_man_AB2 = ~oman_AB2+1'b1;
assign inv_man_AB3 = ~oman_AB3+1'b1;
assign inv_man_AB4 = ~oman_AB4+1'b1;
assign inv_man_AB5 = ~oman_AB5+1'b1;
assign inv_man_AB6 = ~oman_AB6+1'b1;
assign inv_man_AB7 = ~oman_AB7+1'b1;
assign inv_man_AB8 = ~oman_AB8+1'b1;
assign inv_man_AB9 = ~oman_AB9+1'b1;
assign inv_man_ABA = ~oman_ABA+1'b1;
assign inv_man_ABB = ~oman_ABB+1'b1;
assign inv_man_ABC = ~oman_ABC+1'b1;
assign inv_man_ABD = ~oman_ABD+1'b1;
assign inv_man_ABE = ~oman_ABE+1'b1;
assign inv_man_ABF = ~oman_ABF+1'b1;
*/
csla #(26,5,5,1) csla_0(.in_01(~oman_AB0), .in_02(26'b1), .out(inv_man_AB0));
csla #(26,5,5,1) csla_1(.in_01(~oman_AB1), .in_02(26'b1), .out(inv_man_AB1));
csla #(26,5,5,1) csla_2(.in_01(~oman_AB2), .in_02(26'b1), .out(inv_man_AB2));
csla #(26,5,5,1) csla_3(.in_01(~oman_AB3), .in_02(26'b1), .out(inv_man_AB3));
csla #(26,5,5,1) csla_4(.in_01(~oman_AB4), .in_02(26'b1), .out(inv_man_AB4));
csla #(26,5,5,1) csla_5(.in_01(~oman_AB5), .in_02(26'b1), .out(inv_man_AB5));
csla #(26,5,5,1) csla_6(.in_01(~oman_AB6), .in_02(26'b1), .out(inv_man_AB6));
csla #(26,5,5,1) csla_7(.in_01(~oman_AB7), .in_02(26'b1), .out(inv_man_AB7));
csla #(26,5,5,1) csla_8(.in_01(~oman_AB8), .in_02(26'b1), .out(inv_man_AB8));
csla #(26,5,5,1) csla_9(.in_01(~oman_AB9), .in_02(26'b1), .out(inv_man_AB9));
csla #(26,5,5,1) csla_A(.in_01(~oman_ABA), .in_02(26'b1), .out(inv_man_ABA));
csla #(26,5,5,1) csla_B(.in_01(~oman_ABB), .in_02(26'b1), .out(inv_man_ABB));
csla #(26,5,5,1) csla_C(.in_01(~oman_ABC), .in_02(26'b1), .out(inv_man_ABC));
csla #(26,5,5,1) csla_D(.in_01(~oman_ABD), .in_02(26'b1), .out(inv_man_ABD));
csla #(26,5,5,1) csla_E(.in_01(~oman_ABE), .in_02(26'b1), .out(inv_man_ABE));
csla #(26,5,5,1) csla_F(.in_01(~oman_ABF), .in_02(26'b1), .out(inv_man_ABF));
always@(posedge clk)begin
    o_man_AB0 <= i_sign_AB[ 0] ? inv_man_AB0[25:0] : oman_AB0;
    o_man_AB1 <= i_sign_AB[ 1] ? inv_man_AB1[25:0] : oman_AB1;
    o_man_AB2 <= i_sign_AB[ 2] ? inv_man_AB2[25:0] : oman_AB2;
    o_man_AB3 <= i_sign_AB[ 3] ? inv_man_AB3[25:0] : oman_AB3;
    o_man_AB4 <= i_sign_AB[ 4] ? inv_man_AB4[25:0] : oman_AB4;
    o_man_AB5 <= i_sign_AB[ 5] ? inv_man_AB5[25:0] : oman_AB5;
    o_man_AB6 <= i_sign_AB[ 6] ? inv_man_AB6[25:0] : oman_AB6;
    o_man_AB7 <= i_sign_AB[ 7] ? inv_man_AB7[25:0] : oman_AB7;
    o_man_AB8 <= i_sign_AB[ 8] ? inv_man_AB8[25:0] : oman_AB8;
    o_man_AB9 <= i_sign_AB[ 9] ? inv_man_AB9[25:0] : oman_AB9;
    o_man_ABA <= i_sign_AB[10] ? inv_man_ABA[25:0] : oman_ABA;
    o_man_ABB <= i_sign_AB[11] ? inv_man_ABB[25:0] : oman_ABB;
    o_man_ABC <= i_sign_AB[12] ? inv_man_ABC[25:0] : oman_ABC;
    o_man_ABD <= i_sign_AB[13] ? inv_man_ABD[25:0] : oman_ABD;
    o_man_ABE <= i_sign_AB[14] ? inv_man_ABE[25:0] : oman_ABE;
    o_man_ABF <= i_sign_AB[15] ? inv_man_ABF[25:0] : oman_ABF;
    o_man_A_53b <= {i_fp64_imbitA, i_man_A1, i_man_A2, i_man_AE, i_man_AF};                
    o_man_B_53b <= {i_fp64_imbitB, i_man_B9, i_man_BA, i_man_B6, i_man_B7};                
end

endmodule

module pip2_processing (
    input         clk               ,
    input         rstn              ,
    input [ 1:0] mode_sel_pip1      ,
    input [15:0] i_sign_AB_pip1     ,
    input        i_sign_AB_fp64_pip1,
    input [11:0] i_exp_AB_fp64_pip1 ,
    input [ 9:0] i_exp_max     ,
    input [ 9:0] i_shift0      ,
    input [ 9:0] i_shift1      ,
    input [ 9:0] i_shift2      ,
    input [ 9:0] i_shift3      ,
    input [ 9:0] i_shift4      ,
    input [ 9:0] i_shift5      ,
    input [ 9:0] i_shift6      ,
    input [ 9:0] i_shift7      ,
    input [ 9:0] i_shift8      ,
    input [ 9:0] i_shift9      ,
    input [ 9:0] i_shiftA      ,
    input [ 9:0] i_shiftB      ,
    input [ 9:0] i_shiftC      ,
    input [ 9:0] i_shiftD      ,
    input [ 9:0] i_shiftE      ,
    input [ 9:0] i_shiftF      ,
    input [25:0] i_man_AB0     ,
    input [25:0] i_man_AB1     ,
    input [25:0] i_man_AB2     ,
    input [25:0] i_man_AB3     ,
    input [25:0] i_man_AB4     ,
    input [25:0] i_man_AB5     ,
    input [25:0] i_man_AB6     ,
    input [25:0] i_man_AB7     ,
    input [25:0] i_man_AB8     ,
    input [25:0] i_man_AB9     ,
    input [25:0] i_man_ABA     ,
    input [25:0] i_man_ABB     ,
    input [25:0] i_man_ABC     ,
    input [25:0] i_man_ABD     ,
    input [25:0] i_man_ABE     ,
    input [25:0] i_man_ABF     ,
    input [52:0] i_man_A_53b   , 
    input [52:0] i_man_B_53b   , 
    output reg [  1:0] mode_sel_pip2      , 
    output reg         o_sign_pip2        ,
    output reg         o_sign_AB_fp64_pip2,
    output reg [ 11:0] o_exp_AB_fp64_pip2 ,
    output reg [  9:0] o_exp_max_pip2     ,
    output reg [106:0] o_result_pip2      ,
    output reg [  6:0] o_lza_cnt          ,
    output reg         o_lza_invalid
);

//clock count output
always@(posedge clk or negedge rstn)begin
    if(!rstn)begin
        mode_sel_pip2<= 2'b11;
    end
    else begin
        mode_sel_pip2<= mode_sel_pip1;
    end
end

always@(posedge clk)begin
    o_sign_AB_fp64_pip2 <=i_sign_AB_fp64_pip1; 
    o_exp_AB_fp64_pip2  <=i_exp_AB_fp64_pip1 ;
    o_exp_max_pip2      <=i_exp_max          ; 
end
//pe_alignment
wire [52:0] idata0;
wire [52:0] idata1;
wire [52:0] idata2;
wire [52:0] idata3;
wire [52:0] idata4;
wire [52:0] idata5;
wire [52:0] idata6;
wire [52:0] idata7;
wire [52:0] idata8;
wire [52:0] idata9;
wire [52:0] idataA;
wire [52:0] idataB;
wire [52:0] idataC;
wire [52:0] idataD;
wire [52:0] idataE;
wire [52:0] idataF;
assign idata0 ={i_sign_AB_pip1[ 0], i_man_AB0, 26'b0};
assign idata1 ={i_sign_AB_pip1[ 1], i_man_AB1, 26'b0};
assign idata2 ={i_sign_AB_pip1[ 2], i_man_AB2, 26'b0};
assign idata3 ={i_sign_AB_pip1[ 3], i_man_AB3, 26'b0};
assign idata4 ={i_sign_AB_pip1[ 4], i_man_AB4, 26'b0};
assign idata5 ={i_sign_AB_pip1[ 5], i_man_AB5, 26'b0};
assign idata6 ={i_sign_AB_pip1[ 6], i_man_AB6, 26'b0};
assign idata7 ={i_sign_AB_pip1[ 7], i_man_AB7, 26'b0};
assign idata8 ={i_sign_AB_pip1[ 8], i_man_AB8, 26'b0};
assign idata9 ={i_sign_AB_pip1[ 9], i_man_AB9, 26'b0};
assign idataA ={i_sign_AB_pip1[10], i_man_ABA, 26'b0};
assign idataB ={i_sign_AB_pip1[11], i_man_ABB, 26'b0};
assign idataC ={i_sign_AB_pip1[12], i_man_ABC, 26'b0};
assign idataD ={i_sign_AB_pip1[13], i_man_ABD, 26'b0};
assign idataE ={i_sign_AB_pip1[14], i_man_ABE, 26'b0};
assign idataF ={i_sign_AB_pip1[15], i_man_ABF, 26'b0};

wire [52:0] odata0;
wire [52:0] odata1;
wire [52:0] odata2;
wire [52:0] odata3;
wire [52:0] odata4;
wire [52:0] odata5;
wire [52:0] odata6;
wire [52:0] odata7;
wire [52:0] odata8;
wire [52:0] odata9;
wire [52:0] odataA;
wire [52:0] odataB;
wire [52:0] odataC;
wire [52:0] odataD;
wire [52:0] odataE;
wire [52:0] odataF;

pe_alignment #(52,10) u_alignment(
    .idata0 (idata0),
    .idata1 (idata1),
    .idata2 (idata2),
    .idata3 (idata3),
    .idata4 (idata4),
    .idata5 (idata5),
    .idata6 (idata6),
    .idata7 (idata7),
    .idata8 (idata8),
    .idata9 (idata9),
    .idataA (idataA),
    .idataB (idataB),
    .idataC (idataC),
    .idataD (idataD),
    .idataE (idataE),
    .idataF (idataF),
    .ishift0(i_shift0), 
    .ishift1(i_shift1), 
    .ishift2(i_shift2), 
    .ishift3(i_shift3), 
    .ishift4(i_shift4), 
    .ishift5(i_shift5), 
    .ishift6(i_shift6), 
    .ishift7(i_shift7), 
    .ishift8(i_shift8), 
    .ishift9(i_shift9),
    .ishiftA(i_shiftA),
    .ishiftB(i_shiftB),
    .ishiftC(i_shiftC),
    .ishiftD(i_shiftD),
    .ishiftE(i_shiftE),
    .ishiftF(i_shiftF),
    .odata0 (odata0),  
    .odata1 (odata1),  
    .odata2 (odata2),
    .odata3 (odata3),
    .odata4 (odata4),
    .odata5 (odata5),
    .odata6 (odata6),
    .odata7 (odata7),
    .odata8 (odata8),
    .odata9 (odata9),
    .odataA (odataA),
    .odataB (odataB),
    .odataC (odataC),
    .odataD (odataD),
    .odataE (odataE),
    .odataF (odataF) 
);                    
                      
//adder tree
wire [108:0] sum_out   ;
wire [108:0] carry_out ;
wire [108:0] add_result;

add_tree_16in #(53) u_add_tree_16in(
    .mode_sel_pip1(mode_sel_pip1),
    .data_in0     (odata0),
    .data_in1     (odata1),
    .data_in2     (odata2),
    .data_in3     (odata3),
    .data_in4     (odata4),
    .data_in5     (odata5),
    .data_in6     (odata6),
    .data_in7     (odata7),
    .data_in8     (odata8),
    .data_in9     (odata9),
    .data_inA     (odataA),
    .data_inB     (odataB),
    .data_inC     (odataC),
    .data_inD     (odataD),
    .data_inE     (odataE),
    .data_inF     (odataF),
    .i_man_A_53b  (i_man_A_53b  ), 
    .i_man_B_53b  (i_man_B_53b  ), 
    .sum_out      (sum_out      ),
    .carry_out    (carry_out    ),
    .add_result   (add_result   )
   );

//lza
wire [106:0] i_lza0;
wire [106:0] i_lza1;
wire [ 6:0] zero_cnt;
wire invalid;


assign i_lza0 = (mode_sel_pip1[1]) ?  sum_out[106:0] : {sum_out[108:52],50'b0} ; 
assign i_lza1 = (mode_sel_pip1[1]) ?  carry_out[106:0] : {carry_out[108:52],50'b0};

lza #(107) u_lza(
    .in_01(i_lza0),
    .in_02(i_lza1),
    .zero_cnt(zero_cnt),
    .invalid(invalid)
);

always@(posedge clk)begin
    o_lza_cnt <= zero_cnt; 
    o_lza_invalid <= invalid;
end

//output processing
always@(posedge clk)begin
        case(mode_sel_pip1)
            2'b10:begin
                      o_result_pip2 <= add_result[106:0];
                      o_sign_pip2 <= 1'b0;
                  end
          default:begin
                      o_result_pip2 <= {add_result[108:52],50'b0};
                      o_sign_pip2 <= add_result[108];
                  end
        endcase
end

endmodule                      
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
