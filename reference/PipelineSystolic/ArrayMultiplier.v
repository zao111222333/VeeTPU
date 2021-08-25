// Generator : SpinalHDL v1.4.3    git head : adf552d8f500e7419fff395b7049228e4bc5de26
// Component : ArrayMultiplier
// Git hash  : 2368832c4bd1bd5d978e8f9ac134b43d87b24256



module ArrayMultiplier (
  input      [3:0]    io_X,
  input      [3:0]    io_Y,
  output reg [7:0]    io_P
);
  wire                _zz_1;
  wire                _zz_2;
  wire                _zz_3;
  wire                _zz_4;
  wire                _zz_5;
  wire                _zz_6;
  wire                _zz_7;
  wire                _zz_8;
  wire                _zz_9;
  wire                _zz_10;
  wire                _zz_11;
  wire                _zz_12;
  wire                _zz_13;
  wire                _zz_14;
  wire                _zz_15;
  wire                _zz_16;
  wire                _zz_17;
  wire                _zz_18;
  wire                _zz_19;
  wire                fullAdder_12_io_sum;
  wire                fullAdder_12_io_cout;
  wire                fullAdder_13_io_sum;
  wire                fullAdder_13_io_cout;
  wire                fullAdder_14_io_sum;
  wire                fullAdder_14_io_cout;
  wire                fullAdder_15_io_sum;
  wire                fullAdder_15_io_cout;
  wire                fullAdder_16_io_sum;
  wire                fullAdder_16_io_cout;
  wire                fullAdder_17_io_sum;
  wire                fullAdder_17_io_cout;
  wire                fullAdder_18_io_sum;
  wire                fullAdder_18_io_cout;
  wire                fullAdder_19_io_sum;
  wire                fullAdder_19_io_cout;
  wire                fullAdder_20_io_sum;
  wire                fullAdder_20_io_cout;
  wire                fullAdder_21_io_sum;
  wire                fullAdder_21_io_cout;
  wire                fullAdder_22_io_sum;
  wire                fullAdder_22_io_cout;
  wire                fullAdder_23_io_sum;
  wire                fullAdder_23_io_cout;

  FullAdder fullAdder_12 (
    .io_a       (_zz_1                 ), //i
    .io_b       (_zz_2                 ), //i
    .io_cin     (_zz_3                 ), //i
    .io_sum     (fullAdder_12_io_sum   ), //o
    .io_cout    (fullAdder_12_io_cout  )  //o
  );
  FullAdder fullAdder_13 (
    .io_a       (fullAdder_16_io_sum   ), //i
    .io_b       (_zz_4                 ), //i
    .io_cin     (fullAdder_12_io_cout  ), //i
    .io_sum     (fullAdder_13_io_sum   ), //o
    .io_cout    (fullAdder_13_io_cout  )  //o
  );
  FullAdder fullAdder_14 (
    .io_a       (fullAdder_17_io_sum   ), //i
    .io_b       (_zz_5                 ), //i
    .io_cin     (fullAdder_13_io_cout  ), //i
    .io_sum     (fullAdder_14_io_sum   ), //o
    .io_cout    (fullAdder_14_io_cout  )  //o
  );
  FullAdder fullAdder_15 (
    .io_a       (fullAdder_18_io_sum   ), //i
    .io_b       (_zz_6                 ), //i
    .io_cin     (fullAdder_14_io_cout  ), //i
    .io_sum     (fullAdder_15_io_sum   ), //o
    .io_cout    (fullAdder_15_io_cout  )  //o
  );
  FullAdder fullAdder_16 (
    .io_a       (_zz_7                 ), //i
    .io_b       (_zz_8                 ), //i
    .io_cin     (_zz_9                 ), //i
    .io_sum     (fullAdder_16_io_sum   ), //o
    .io_cout    (fullAdder_16_io_cout  )  //o
  );
  FullAdder fullAdder_17 (
    .io_a       (fullAdder_20_io_sum   ), //i
    .io_b       (_zz_10                ), //i
    .io_cin     (fullAdder_16_io_cout  ), //i
    .io_sum     (fullAdder_17_io_sum   ), //o
    .io_cout    (fullAdder_17_io_cout  )  //o
  );
  FullAdder fullAdder_18 (
    .io_a       (fullAdder_21_io_sum   ), //i
    .io_b       (_zz_11                ), //i
    .io_cin     (fullAdder_17_io_cout  ), //i
    .io_sum     (fullAdder_18_io_sum   ), //o
    .io_cout    (fullAdder_18_io_cout  )  //o
  );
  FullAdder fullAdder_19 (
    .io_a       (fullAdder_22_io_sum   ), //i
    .io_b       (fullAdder_15_io_cout  ), //i
    .io_cin     (fullAdder_18_io_cout  ), //i
    .io_sum     (fullAdder_19_io_sum   ), //o
    .io_cout    (fullAdder_19_io_cout  )  //o
  );
  FullAdder fullAdder_20 (
    .io_a       (_zz_12                ), //i
    .io_b       (_zz_13                ), //i
    .io_cin     (_zz_14                ), //i
    .io_sum     (fullAdder_20_io_sum   ), //o
    .io_cout    (fullAdder_20_io_cout  )  //o
  );
  FullAdder fullAdder_21 (
    .io_a       (_zz_15                ), //i
    .io_b       (_zz_16                ), //i
    .io_cin     (fullAdder_20_io_cout  ), //i
    .io_sum     (fullAdder_21_io_sum   ), //o
    .io_cout    (fullAdder_21_io_cout  )  //o
  );
  FullAdder fullAdder_22 (
    .io_a       (_zz_17                ), //i
    .io_b       (_zz_18                ), //i
    .io_cin     (fullAdder_21_io_cout  ), //i
    .io_sum     (fullAdder_22_io_sum   ), //o
    .io_cout    (fullAdder_22_io_cout  )  //o
  );
  FullAdder fullAdder_23 (
    .io_a       (_zz_19                ), //i
    .io_b       (fullAdder_19_io_cout  ), //i
    .io_cin     (fullAdder_22_io_cout  ), //i
    .io_sum     (fullAdder_23_io_sum   ), //o
    .io_cout    (fullAdder_23_io_cout  )  //o
  );
  always @ (*) begin
    io_P[0] = (io_X[0] && io_Y[0]);
    io_P[1] = fullAdder_12_io_sum;
    io_P[2] = fullAdder_13_io_sum;
    io_P[3] = fullAdder_14_io_sum;
    io_P[4] = fullAdder_15_io_sum;
    io_P[5] = fullAdder_19_io_sum;
    io_P[6] = fullAdder_23_io_sum;
    io_P[7] = fullAdder_23_io_cout;
  end

  assign _zz_1 = (io_X[1] && io_Y[0]);
  assign _zz_2 = (io_X[0] && io_Y[1]);
  assign _zz_3 = 1'b0;
  assign _zz_7 = (io_X[2] && io_Y[0]);
  assign _zz_8 = (io_X[1] && io_Y[1]);
  assign _zz_9 = 1'b0;
  assign _zz_12 = (io_X[3] && io_Y[0]);
  assign _zz_13 = (io_X[2] && io_Y[1]);
  assign _zz_14 = 1'b0;
  assign _zz_4 = (io_X[0] && io_Y[2]);
  assign _zz_10 = (io_X[1] && io_Y[2]);
  assign _zz_15 = (io_X[3] && io_Y[1]);
  assign _zz_16 = (io_X[2] && io_Y[2]);
  assign _zz_5 = (io_X[0] && io_Y[3]);
  assign _zz_11 = (io_X[1] && io_Y[3]);
  assign _zz_17 = (io_X[3] && io_Y[2]);
  assign _zz_18 = (io_X[2] && io_Y[3]);
  assign _zz_6 = 1'b0;
  assign _zz_19 = (io_X[3] && io_Y[3]);

endmodule

//FullAdder replaced by FullAdder

//FullAdder replaced by FullAdder

//FullAdder replaced by FullAdder

//FullAdder replaced by FullAdder

//FullAdder replaced by FullAdder

//FullAdder replaced by FullAdder

//FullAdder replaced by FullAdder

//FullAdder replaced by FullAdder

//FullAdder replaced by FullAdder

//FullAdder replaced by FullAdder

//FullAdder replaced by FullAdder

module FullAdder (
  input               io_a,
  input               io_b,
  input               io_cin,
  output              io_sum,
  output              io_cout
);

  assign io_sum = ((io_a ^ io_b) ^ io_cin);
  assign io_cout = (((io_a && io_b) || (io_a && io_cin)) || (io_b && io_cin));

endmodule
