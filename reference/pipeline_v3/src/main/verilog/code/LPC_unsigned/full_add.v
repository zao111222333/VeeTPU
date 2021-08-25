module full_add(

input x,
input y,
input cin,
output cout,
output sum
);


wire 		h;
wire 		h_not;

xor(h,x,y);
xnor(h_not,x,y);
xor(sum,h,cin);
assign cout=h?cin:x;

endmodule