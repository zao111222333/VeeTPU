module CSA42_UNIT (
    input  i_X_0     ,
    input  i_X_1     ,
    input  i_X_2     ,
    input  i_X_3     ,
    input  i_c_in  ,
    output o_c_out ,
    output o_carry ,
    output o_sum    
);
    //internal signal
    wire a_xor_b   ;
    wire c_xor_d   ;
    wire ab_xor_cd ;
    assign a_xor_b= i_X_0^i_X_1 ;
    assign c_xor_d= i_X_2^i_X_3 ;
    assign ab_xor_cd = a_xor_b ^ c_xor_d ;

    //output
    assign o_c_out = c_xor_d ? i_X_1 : i_X_3 ;
    assign o_carry = ab_xor_cd ? i_c_in : i_X_0 ;
    assign o_sum   = ab_xor_cd ^ i_c_in;
endmodule

