#ifndef STRUCTURE_H
#define STRUCTURE_H
#include <stdio.h>
#include <stdbool.h>
	typedef union{
                float floating_value_in_32_bits;
                struct  sign_exp_mantissa{
                        unsigned  mantissa:23;
                        unsigned  exponent:8;
                        unsigned      sign:1;
                }f_bits;
                struct single_bits{
                        unsigned  b0 :1;
                        unsigned  b1 :1;
                        unsigned  b2 :1;
                        unsigned  b3 :1;
                        unsigned  b4 :1;
                        unsigned  b5 :1;
                        unsigned  b6 :1;
                        unsigned  b7 :1;
                        unsigned  b8 :1;
                        unsigned  b9 :1;
                        unsigned  b10:1;
                        unsigned  b11:1;
                        unsigned  b12:1;
                        unsigned  b13:1;
                        unsigned  b14:1;
                        unsigned  b15:1;
                        unsigned  b16:1;
                        unsigned  b17:1;
                        unsigned  b18:1;
                        unsigned  b19:1;
                        unsigned  b20:1;
                        unsigned  b21:1;
                        unsigned  b22:1;
                        unsigned  b23:1;
                        unsigned  b24:1;
                        unsigned  b25:1;
                        unsigned  b26:1;
                        unsigned  b27:1;
                        unsigned  b28:1;
                        unsigned  b29:1;
                        unsigned  b30:1;
                        unsigned  b31:1;
                }bit;
        }FLOAT_UN;
#endif
