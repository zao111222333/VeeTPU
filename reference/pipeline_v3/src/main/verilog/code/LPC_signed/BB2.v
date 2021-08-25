
//signed * signed

module BB2 (
	input [1:0] a,
	input [1:0] b,
	output [3:0] pp

);

    wire [1:0] pp_0, pp_1;
    wire [1:0] s_pp0, s_pp1;
    wire [3:0] ex_s_pp0, ex_s_pp1;

    assign pp_0 = b[0]?a:2'b0;
    assign pp_1 = b[1]?a:2'b0;

    assign s_pp0 = pp_0;
    assign s_pp1 = ~pp_1 + 1'b1;

    assign ex_s_pp0 = { {2{s_pp0[1]}}, s_pp0[1:0]  };
    assign ex_s_pp1 = { {s_pp1[1]},  s_pp1[1:0], 1'b0 };

    assign pp = ex_s_pp0 + ex_s_pp1;

endmodule
