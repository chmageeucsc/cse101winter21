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
	
	BigInteger A = stringToBigInteger("111122223333");
	BigInteger B = stringToBigInteger("111122223333");
	BigInteger C = newBigInteger();
	BigInteger D = stringToBigInteger("12348148518469129628889");
	
	printf("multiply test 1 2\n\n");

	multiply(C,A,B);
	
	if (sign(C) != 1) {
		printf("sign of C = %d\nC = ", sign(C));
		printBigInteger(stdout, C);
		printf("\n");
	}
	
	if (equals(C,D) != 1) {
		printBigInteger(stdout, C);
		printf("\n");
		printBigInteger(stdout, D);
		printf("\n");
	}
	
	negate(B);
	negate(D);
	
	printf("multiply test 3 4\n\n");
	
	multiply(C,A,B);
	
	if (sign(C) != -1) {
		printf("sign of C = %d\nC = ", sign(C));
		printBigInteger(stdout, C);
		printf("\n");
	}
	
	if (equals(C,D) != 1) {
		printBigInteger(stdout, C);
		printf("\n");
		printBigInteger(stdout, D);
		printf("\n");
	}
	
	makeZero(B);
	
	printf("multiply test 5\n\n");
	
	multiply(C,A,B);
	
	if (sign(C) != 0) {
		printf("sign of C = %d\nC = ", sign(C));
		printBigInteger(stdout, C);
		printf("\n");
	}
	
	freeBigInteger(&A);
	freeBigInteger(&C);
	freeBigInteger(&B);
	freeBigInteger(&D);
	
	A = stringToBigInteger("-111122223333");
	B = stringToBigInteger("111122223333");
	D = stringToBigInteger("-12348148518469129628889");
	
	printf("prod test 1 2\n\n");
	
	C = prod(A,B);
	
	if (sign(C) != -1) {
		printf("sign of C = %d\nC = ", sign(C));
		printBigInteger(stdout, C);
		printf("\n");
	}
	
	if (equals(C,D) != 1) {
		printBigInteger(stdout, C);
		printf("\n");
		printBigInteger(stdout, D);
		printf("\n");
	}
	
	freeBigInteger(&C);
	
	negate(B);
	negate(D);
	
	printf("prod test 3 4\n\n");
	
	C = prod(A,B);
	
	if (sign(C) != 1) {
		printf("sign of C = %d\nC = ", sign(C));
		printBigInteger(stdout, C);
		printf("\n");
	}
	
	if (equals(C,D) != 1) {
		printBigInteger(stdout, C);
		printf("\n");
		printBigInteger(stdout, D);
		printf("\n");
	}
	
	makeZero(B);
	freeBigInteger(&C);
	
	printf("prod test 5\n\n");
	
	C = prod(A,B);
	
	if (sign(C) != 0) {
		printf("5\n");
		printf("sign of C = %d\nC = ", sign(C));
		printBigInteger(stdout, C);
		printf("\n");
	}
	
	freeBigInteger(&A);
	freeBigInteger(&C);
	freeBigInteger(&B);
	freeBigInteger(&D);
	
	return 0;
}
