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
	BigInteger N = stringToBigInteger("123");
	
	//printf("sign: %d\n", sign(N));
	
	/*BigInteger M = stringToBigInteger("+1234");
	
	if (compare(N, M) == 0) {
		printf("equal\n");
	}
	else if (compare(N, M) == 1) {
		printf("N > M\n");
	}
	else if (compare(N, M) == -1) {
		printf("N < M\n");
	}
	
	freeBigInteger(&M);*/
	
	char s [9] = "7302740";
	atol(s);
	for (int i = 0; i < 9; i++) {
		printf("%ld\n", s[9-1-i]);
	}
	
	freeBigInteger(&N);
	
	return 0;
}
