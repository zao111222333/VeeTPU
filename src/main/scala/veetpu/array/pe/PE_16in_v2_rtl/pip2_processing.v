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
//alignment
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

alignment #(52,10) u_alignment(
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
