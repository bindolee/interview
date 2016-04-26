// countBits.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string.h>

/* 
this is initial counting bit version.. consider faster version than below
*/
int countSetBits(int num) {
	int countedBits = 0;
	while (num) {
		num &= (num - 1);
		countedBits++;
	}
	return countedBits;
}

/*
this is java version of faster couting bit

private int count[] = new int[256];
void preCalculate() {
	for (int i = 0; i < 256; i++) {
		count[i] = countBits(i);
	}
}

public int countBitsFaster(int num) {
	//get 8 bits at a time and check count from count array
	int total = 0;
	int mask = (1 << 8) - 1;
	for (int i = 0; i < 4; i++) {
		total += count[num & mask];
		num = num >> >8;
	}
	return total;
}

//http://bits.stephan-brumme.com/countBits.html
public int countBitsEvenFaster(int x) {
	// count bits of each 2-bit chunk
	x = x - ((x >> 1) & 0x55555555);
	// count bits of each 4-bit chunk
	x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
	// count bits of each 8-bit chunk
	x = x + (x >> 4);
	// mask out junk
	x &= 0xF0F0F0F;
	// add all four 8-bit chunks
	return (x * 0x01010101) >> 24;
}
*/

int countSetBitsFaster(int num) {
	int countedBits = 0;
	return countedBits;
}

int main()
{
	int a = 0;
	for (int i = 0; i < 5; i++) {
		printf("\n Enter integer number to count set bits:");
		scanf_s("%d", &a);
		printf("\n The counted set bits of the entered number is %d", countSetBits(a));
	}
    return 0;
}

