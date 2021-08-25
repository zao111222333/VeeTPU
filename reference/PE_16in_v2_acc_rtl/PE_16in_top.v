module PE_16in_top #(parameter ACC_CNT_WIDTH = 5)(
    input clk,
    input rstn,
    input [  1:0] mode_sel,
    input [255:0] A,
    input [255:0] B,
    input [ACC_CNT_WIDTH-1:0] acc_num,
    output reg [63:0] result,
    output reg out_en
    );
//clock counter
reg [ACC_CNT_WIDTH-1:0] acc_cnt;
reg acc_en;
always@(posedge clk or negedge rstn)begin
    if(!rstn)begin
        acc_cnt <= 1'b0;
        acc_en  <= 1'b0;
    end
    else if(acc_cnt==acc_num) begin
        acc_cnt <= 1'b0;
        acc_en  <= 1'b0;
    end
    else begin
        acc_cnt <= acc_cnt+1;
        acc_en  <= 1;
    end
end

//acc_en pipline
reg acc_en_pip0;
reg acc_en_pip1;
reg acc_en_pip2;
reg acc_en_pip3;
always@(posedge clk or negedge rstn)begin
    if(!rstn)begin
        acc_en_pip0 <= 1'b0;
        acc_en_pip1 <= 1'b0;
        acc_en_pip2 <= 1'b0;
        acc_en_pip3 <= 1'b0;
    end
    else begin
        acc_en_pip0 <= acc_en     ;
        acc_en_pip1 <= acc_en_pip0;
        acc_en_pip2 <= acc_en_pip1;
        acc_en_pip3 <= acc_en_pip2;
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

//fp accumulate
wire [63:0] o_fp_acc;
reg  [63:0] acc_restult;

fp_acc u_fp_acc(
    .i_A     (o_norm_result), 
    .i_B     (acc_restult  ),
    .mode_sel(mode_sel_pip3),
    .o_r     (o_fp_acc     )
);

always@(posedge clk or negedge rstn)begin
    if(!rstn)begin
        acc_restult <= 0;
    end
    else begin
        acc_restult <= acc_en_pip3 ? o_fp_acc : o_norm_result;
    end
end

//output processign
reg [1:0] mode_sel_pip4;
always@(posedge clk or negedge rstn)begin
    if(!rstn)begin
        mode_sel_pip4 <= 2'b11;
    end
    else begin
        mode_sel_pip4 <= mode_sel_pip3;
    end
end

wire acc_out_en;
assign acc_out_en = (~acc_en_pip3)&&(mode_sel_pip3!=2'b11);
always@(posedge clk or negedge rstn)begin
    if(!rstn)begin
        out_en <= 0;
    end
    else if(mode_sel_pip4!=2'b11)begin
        out_en <= ~acc_en_pip3;
    end
end

always@(posedge clk or negedge rstn)begin
    if(!rstn)begin
        result <= 0;
    end
    else if(acc_out_en)begin
        result <= acc_restult;
    end
end

endmodule
