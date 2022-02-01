module compare2#(parameter dataWidth=11)(
    input [dataWidth-1:0] i_X_0,
    input [dataWidth-1:0] i_X_1,
    output  [dataWidth-1:0] o_Max
    //input rst,
    //input clk
);
assign o_Max = (i_X_0>i_X_1) ? i_X_0 : i_X_1;
endmodule
