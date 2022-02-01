module Hadd(
input a,
input b,
output sum,
output carry
);

assign carry=a&b;
assign sum=a^b;
endmodule
