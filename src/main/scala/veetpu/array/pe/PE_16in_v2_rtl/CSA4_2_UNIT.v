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

