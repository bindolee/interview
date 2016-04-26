// AddTwoNumberInBinaryRepresentation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

/* 
Add 2 integer numbers using only bit manupulation. << >> ~ ^
*/

int AddTwoNumberInBinaryRepresentation(int first, int second) {
	int result, carry_in, carry_out, temp_f, temp_s, bit_f, bit_s;
	result = carry_in = carry_out = bit_f = bit_s = 0;
	temp_f = first;
	temp_s = second;
	int i = 0;
	// carry_in = the carried bit which needs to be added in the current bit addtion
	// carry_out = this is carried bit which needs to be added for next bit position
	while (temp_s || temp_f) {
		bit_f = (temp_f & 1) ;
		bit_s = (temp_s & 1) ;


		
		if (carry_in) {
			if (bit_f || bit_s)
				carry_out = 1;
		}
		else {
			if (bit_f && bit_s) // this means 1 + 1, so next 1 bit has to be carried over to the next bit addition.
				carry_out = 1;
		}
		
		result |= (bit_f ^ bit_s ^ carry_in) << i;

		/*
		Another version of detecting carry bit... -> this is alot simpler.. no need to check if above..and change value between carry out and in
		carry  = bit_f & carry  | bit_s & carry | bit_f & bit_s;

		*/

		temp_s >>= 1; temp_f >>= 1; 
		carry_in = carry_out; i++;
		carry_out = 0;
	}

	
	return result | (carry_in<<i);
}

int main()
{
	int a, b;
	for (int i = 0; i < 10;i++) {
		printf("Add 2 interger numbers by bit representation\n");
		printf("Enter 1st int Number: ");
		scanf_s("%d", &a);
		printf("Enter 2nd int Number: ");
		scanf_s("%d", &b);

		printf("the sum of first number:%d and second number:%d     is      %d\n", a, b, AddTwoNumberInBinaryRepresentation(a, b));
	}
    return 0;
}

