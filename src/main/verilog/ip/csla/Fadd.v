module Fadd(x,y,Cin,Cout,Sum);
  input x,y,Cin;
  output Cout,Sum;
  wire a,b,c;

  xor(a,x,y);
  xor(Sum,a,Cin);
  and(b,x,y);
  and(c,Cin,a);
  or(Cout,b,c);

endmodule