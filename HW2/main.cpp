#include "structure.h"

void print_binary(FLOAT_UN input);

int main(int argc, char * arg[]) {
	
	FLOAT_UN float_32_s1, float_32_s2, float_32_rslt, fun_arg;
	/******** local helper variables ***********/
	float the_hardware_result;
	int mant_s1, mant_s2, mant_res, exp_s1, exp_s2;
	int i, j, k, shift_count;
	int denom_s1 = true, denom_s2 = true;

	/******** request two floating point numbers ********/
	//printf("please enter your first floating point number and new-line: \n");
	scanf("%g", &float_32_s1.floating_value_in_32_bits);
	//printf("please enter your second floating point number and new-line: \n");
	scanf("%g", &float_32_s2.floating_value_in_32_bits);

	/****** generate the floating point hardware result ********/
	the_hardware_result = float_32_s2.floating_value_in_32_bits +
 	float_32_s1.floating_value_in_32_bits;

	/******* get the mantissa and exponent components ****/
	/******* into the helper variables ****/
	mant_s1 = float_32_s1.f_bits.mantissa;
	mant_s2 = float_32_s2.f_bits.mantissa;
	exp_s1 = float_32_s1.f_bits.exponent;
	exp_s2 = float_32_s2.f_bits.exponent;

	/******* check for normalization and slam in the *****/
	/******* hidden bit if normalized *****/
	if(exp_s1){
 		mant_s1 |= (1 << 23);
 		denom_s1 = false;
	}
	if(exp_s2){
 		mant_s2 |= (1 << 23);
 		denom_s2 = false;
	}

	/******* check exponent diff and who's the smallest ****/
	if((shift_count = exp_s1 - exp_s2) < 0){
 		shift_count = -(shift_count); /* keep diff + */
 		if(shift_count > 24)shift_count = 24;
 		if(shift_count >= 1 && denom_s1){
 			mant_s1 = (mant_s1 >> (shift_count-1));
 		}else{
 			mant_s1 = mant_s1 >> shift_count;}
 		float_32_rslt.f_bits.exponent = exp_s2;
	}else{
		if(shift_count > 24)shift_count = 24;
	 	if(shift_count >= 1 && denom_s2){
 			mant_s2 = (mant_s2 >> (shift_count-1));
 		}else{
			mant_s2 = mant_s2 >> shift_count;}
		float_32_rslt.f_bits.exponent = exp_s1;
	}

	/**** finally ready to add helper mantissa variables ****/
	mant_res = mant_s1 + mant_s2;

	/**** check if the addition overflowed 24 bits, since ****/
	/**** mantissa with hidden bit can only be 24 bits ****/
	/**** if we need to right shift, must increase the exp ****/
	/**** finally clear the slammed hidden bit in the ****/
	/**** mantissa helper to get to 23 bits and put these ****/
	/**** 23 bits into the mantissa bit field of the result ****/
	
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

	if(mant_res & (1<<24)){
 		mant_res >>= 1;
		float_32_rslt.f_bits.exponent++;
 		printf("2 HIDDEN BITS, MUST INCREMENT EXPONENT\n\n");		
		float_32_rslt.f_bits.mantissa = (mant_res & ~(1<<23));
	}else{
 		float_32_rslt.f_bits.mantissa = (mant_res & ~(1<<23));
	}
	/*** check for infinity exponent pattern (0xFF) ****/
	/**** cannot have NAN from addition so clear mantissa ****/
	unsigned z = 2;
	if(float_32_s1.f_bits.sign == 0 && float_32_s2.f_bits.sign == 0) {
		z = 0;
	}
	else if(float_32_s1.f_bits.sign == 1 && float_32_s2.f_bits.sign == 1){
		z = 1;
	}else {
		if(float_32_s1.floating_value_in_32_bits > float_32_s2.floating_value_in_32_bits) {
			z = float_32_s1.f_bits.sign;
		}else{
			z = float_32_s2.f_bits.sign;
		}
	}
	if(float_32_rslt.f_bits.exponent == 255) {
		float_32_rslt.f_bits.mantissa = 0;
		float_32_rslt.f_bits.sign = z;
	}

	//some printf statements to see where we're at from this helper code
	printf("Enter Float 1: %g", float_32_s1.floating_value_in_32_bits);
	printf("\n");
	printf("Enter Float 2: %g", float_32_s2.floating_value_in_32_bits);
	printf("\n\n");
	printf("Original pattern of Float 1: ");
	print_binary(float_32_s1);
	printf("\n");
	printf("Original pattern of Float 2: ");
	print_binary(float_32_s2);
	printf("\n");
	printf("Bit pattern of result:       ");
	print_binary(float_32_rslt);
	printf("\n");
	printf("\n");
	printf("EMULATED FLOATING RESULT FROM PRINTF ==>>> %g", float_32_rslt.floating_value_in_32_bits);
	printf("\n");
	printf("HARDWARE FLOATING RESULT FROM PRINTF ==>>> %g", the_hardware_result);
	printf("\n");
}


void print_binary (FLOAT_UN input) {
        //print sign bit
        printf("%u", input.bit.b31);
	printf(" ");
        //print exponent bits
        printf("%u", input.bit.b30);
        printf("%u", input.bit.b29);
        printf("%u", input.bit.b28);
        printf("%u", input.bit.b27);
	printf(" ");
        printf("%u", input.bit.b26);
        printf("%u", input.bit.b25);
        printf("%u", input.bit.b24);
        printf("%u", input.bit.b23);
	printf(" ");
        //print mantissa bits
        printf("%u", input.bit.b22);
        printf("%u", input.bit.b21);
        printf("%u", input.bit.b20);
	printf(" ");
        printf("%u", input.bit.b19);
        printf("%u", input.bit.b18);
        printf("%u", input.bit.b17);
        printf("%u", input.bit.b16);
	printf(" ");
        printf("%u", input.bit.b15);
        printf("%u", input.bit.b14);
        printf("%u", input.bit.b13);
        printf("%u", input.bit.b12);
	printf(" ");
        printf("%u", input.bit.b11);
        printf("%u", input.bit.b10);
        printf("%u", input.bit.b9);
        printf("%u", input.bit.b8);
	printf(" ");
        printf("%u", input.bit.b7);
        printf("%u", input.bit.b6);
        printf("%u", input.bit.b5);
        printf("%u", input.bit.b4);
	printf(" ");
        printf("%u", input.bit.b3);
        printf("%u", input.bit.b2);
        printf("%u", input.bit.b1);
        printf("%u", input.bit.b0);
}
