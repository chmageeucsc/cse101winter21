//-----------------------------------------------------------------------------
//
// Chantel Gee, chmagee
// 2021 Winter CSE 101 pa7
// 
// BigIntegerTest.c
// Tester file for BigInteger ADT
// 
//-----------------------------------------------------------------------------

#include <stdlib.h>
#include <stdio.h>
#include "List.h"
#include "BigInteger.h"

int main() {
	BigInteger N = stringToBigInteger("10000");
	
	printBigInteger(stdout, N);
	printf("\n");
	
	BigInteger M = stringToBigInteger("20000");
	
	printBigInteger(stdout, M);
	printf("\n");
	
	BigInteger NN = copy(N);
	
	if (compare(N, NN) == 0) {
		printf("equal\n");
	}
	else if (compare(N, NN) == 1) {
		printf("N > NN\n");
	}
	else if (compare(N, NN) == -1) {
		printf("N < NN\n");
	}
	
	printf("sign: %d\n", sign(N));
	
	if (compare(N, M) == 0) {
		printf("equal\n");
	}
	else if (compare(N, M) == 1) {
		printf("N > M\n");
	}
	else if (compare(N, M) == -1) {
		printf("N < M\n");
	}	
	
	freeBigInteger(&NN);
	freeBigInteger(&M);
	freeBigInteger(&N);
	
	return 0;
}
