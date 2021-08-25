
//unsigned * unsigned

module BB0 (
    input [1:0] a,
    input [1:0] b,
    output [3:0] pp

);

    wire [1:0] pp_0, pp_1;

    assign pp_0 = b[0]?a:2'b0;
    assign pp_1 = b[1]?a:2'b0;

    assign pp = pp_1 + {pp_0,1'b0};


endmodule 
