
//unsigned * signed

module BB1 (
	input [1:0] a,  //signed
	input [1:0] b,  //unsigned
	output [3:0] pp
); 

    wire [1:0] pp_0, pp_1;
    wire [3:0] ex_pp0, ex_pp1;

    assign pp_0 = b[0]?a:2'b0;
    assign pp_1 = b[1]?a:2'b0;

    assign ex_pp0 = { {2{pp_0[1]}}, pp_0 };
    assign ex_pp1 = { pp_1[1], pp_1, 1'b0};

    assign pp = ex_pp0 + ex_pp1; 

endmodule



