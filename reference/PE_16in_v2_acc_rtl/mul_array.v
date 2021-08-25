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
