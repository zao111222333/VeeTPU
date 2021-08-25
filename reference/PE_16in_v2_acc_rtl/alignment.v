module alignment #(parameter WIDTH=49, EXP_W=10)(
    input  [WIDTH-1:0] idata0 ,        
    input  [WIDTH-1:0] idata1 ,        
    input  [WIDTH-1:0] idata2 ,        
    input  [WIDTH-1:0] idata3 ,        
    input  [WIDTH-1:0] idata4 ,        
    input  [WIDTH-1:0] idata5 ,        
    input  [WIDTH-1:0] idata6 ,        
    input  [WIDTH-1:0] idata7 ,        
    input  [WIDTH-1:0] idata8 ,        
    input  [WIDTH-1:0] idata9 ,
    input  [WIDTH-1:0] idataA ,
    input  [WIDTH-1:0] idataB ,
    input  [WIDTH-1:0] idataC ,
    input  [WIDTH-1:0] idataD ,
    input  [WIDTH-1:0] idataE ,
    input  [WIDTH-1:0] idataF ,
    input  [EXP_W-1:0] ishift0,    
    input  [EXP_W-1:0] ishift1,    
    input  [EXP_W-1:0] ishift2,    
    input  [EXP_W-1:0] ishift3,    
    input  [EXP_W-1:0] ishift4,    
    input  [EXP_W-1:0] ishift5,    
    input  [EXP_W-1:0] ishift6,    
    input  [EXP_W-1:0] ishift7,    
    input  [EXP_W-1:0] ishift8,    
    input  [EXP_W-1:0] ishift9,
    input  [EXP_W-1:0] ishiftA,
    input  [EXP_W-1:0] ishiftB,
    input  [EXP_W-1:0] ishiftC,
    input  [EXP_W-1:0] ishiftD,
    input  [EXP_W-1:0] ishiftE,
    input  [EXP_W-1:0] ishiftF,
    output [WIDTH-1:0] odata0 ,        
    output [WIDTH-1:0] odata1 ,        
    output [WIDTH-1:0] odata2 ,        
    output [WIDTH-1:0] odata3 ,        
    output [WIDTH-1:0] odata4 ,        
    output [WIDTH-1:0] odata5 ,        
    output [WIDTH-1:0] odata6 ,        
    output [WIDTH-1:0] odata7 ,        
    output [WIDTH-1:0] odata8 ,        
    output [WIDTH-1:0] odata9 ,
    output [WIDTH-1:0] odataA ,
    output [WIDTH-1:0] odataB ,
    output [WIDTH-1:0] odataC ,
    output [WIDTH-1:0] odataD ,
    output [WIDTH-1:0] odataE ,
    output [WIDTH-1:0] odataF    
);
assign odata0 = idata0 >>> ishift0;
assign odata1 = idata1 >>> ishift1;
assign odata2 = idata2 >>> ishift2;
assign odata3 = idata3 >>> ishift3;
assign odata4 = idata4 >>> ishift4;
assign odata5 = idata5 >>> ishift5;
assign odata6 = idata6 >>> ishift6;
assign odata7 = idata7 >>> ishift7;
assign odata8 = idata8 >>> ishift8;
assign odata9 = idata9 >>> ishift9;
assign odataA = idataA >>> ishiftA;
assign odataB = idataB >>> ishiftB;
assign odataC = idataC >>> ishiftC;
assign odataD = idataD >>> ishiftD;
assign odataE = idataE >>> ishiftE;
assign odataF = idataF >>> ishiftF;
endmodule              
