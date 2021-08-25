This is designed based on 16 inputs of 14+13+13+13 
/*********************RTL Structure*********************/
>PE_16in_top.v
      -The top module, which have 4 instance: input_processing, pip1_processing, pip2_processing, pip3_processing. 
    > input_processing.v
          -The pair of 256-bit inputs and the 2-bit precision mode are sent to the input_processing module to generate the outputs for multiple-term dot-product operation including sign calculation, exponent comparison and multiplication.
    >pip1_processing.v
          -The piplin1 module, which have 2 instance: exp_compare_16in, mul_array.
        >exp_compare_16in.v
              -Using to exponent comparison and difference generation, including 5 exp_compare_unit_4in.
            >exp_compare_unit_4in.v
                  -The comparison and difference of 4 inputs of exponent.  The compare_logic_4in is used in it.
                >compare_logic_4in.v
                      -The LUT logic of comparison and difference result of 4 inputs of exponent
        >mul_array.v
              -The multiplier array include 16 booth_13w.
            >booth_13w.v
                  -The conventional radix-4 booth multiplier with the 13 bit-width. Using 1 of CSA3_2, 2 of CSA4_2, 1 of 26-bit-width csla and the Five_to_One module to build the booth multiplier.
                >pp_gen.v
                      -The code selection of radix-4 booth multiplier with the 13-bit-width.
    >pip2_processing.v
          -The piplin2 module, which have 3 instance: alignment, add_tree_10in_signed, lza.
        >alignment.v
              -Each partial products are shifted and aligned according to the exponential difference.
        >add_tree_16in.v
              -The shifted results which are signed (2’s complement) and sent to the 16-input signed adder tree, which employs four 4:2 CSAs, two 4:2 CSAs, one 4:2 CSA in three levels. The sum and carry are added up by 96-bit-width CSLA.
        >lza.v
              -The module is leading zero anticipator unit. The bit-width of leading zero anticipator unit indicator architecture for each input is 107-bit and the bit-width of output is 7, which is definitely compatible with different precision.
    >pip3_processing.v
          -The piplin3 module, which is used to do normlization with different precision and have 1 instance: round.
        >round.v
              -The mantissa is round in this module.

/*********************General Module*********************/
>cpa.v
    -ripple-carryadder
>CSA3_2.v
    -3:2 carry-save adder
>CSA4_2_UNIT.v
    -The unit of 4:2 carry-save adder
>CSA4_2.v
    -4:2 carry-save adder
>csla_unit.v
    -The unit of carry-select adder
>csla.v
    -carry-select adder
>Fadd.v
    -full adder
>Hadd.v
    -half adder


/*********************Simulation File*********************/
>PE10intest.v
    -This file are use to do FP64 random test. This is not a complete testing. Except for the case where the exponent is all zero, the other test cases in random are all pass. For the case where the exponent is all zero, the manual verification is passed.


