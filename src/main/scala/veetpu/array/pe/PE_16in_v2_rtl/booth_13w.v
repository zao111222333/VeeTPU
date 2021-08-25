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

CSA4_2 #(26) CSA4_2_1(.a(shifttempProd00), .b(shifttempProd01), .c(shifttempProd02), .d(shifttempProd03), .sum(sum_42_0), .carry(carry_42_0));

CSA3_2 #(26) CSA3_2_1(.a(shifttempProd04), .b(shifttempProd05), .c(shifttempProd06), .sum(sum_32_0), .carry(carry_32_0));

wire[25:0] a_in=sum_42_0[25:0];
wire[25:0] b_in={carry_42_0[24:0],1'b0};
wire[25:0] c_in=sum_32_0[25:0];
wire[25:0] d_in={carry_32_0[24:0],1'b0};
wire[25:0] sum_42_1;
wire[25:0] carry_42_1;

CSA4_2 #(26) CSA4_2_2(.a(a_in), .b(b_in), .c(c_in), .d(d_in), .sum(sum_42_1), .carry(carry_42_1));
	
//assign r = sum_42_1+{carry_42_1[24:0],1'b0};

wire [26:0] result;
csla #(26,5,5,1) csla_0(.in_01(sum_42_1), .in_02({carry_42_1[24:0],1'b0}), .out(result));
assign r=result[25:0];

endmodule
