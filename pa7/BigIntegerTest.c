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
	
	BigInteger A = stringToBigInteger("123456789");
	BigInteger B = copy(A);
	BigInteger C = newBigInteger();
	BigInteger D = stringToBigInteger("246913578");
	
	printf("BigInt A =");
	printBigInteger(stdout, A);
	printf("\n");
	printf("BigInt B (copy A) =");
	printBigInteger(stdout, B);
	printf("\n");
	printf("BigInt D =");
	printBigInteger(stdout, D);
	printf("\nmake D zero\n");
	
	makeZero(D);
	
	printf("BigInt D =");
	printBigInteger(stdout, D);
	printf("\n\n");
	
	if (compare(A,B) == 0) {
		printf("comparing A and B\nA and B are equal\n");
	}
	if (compare(A,D) == 1) {
		printf("comparing A and D\nA is greater than D\n");
	}
	
	printf("negate A\n");
	negate(A);
	if (compare(A,B) == -1) {
		printf("comparing A and B\nA is less than B\n\n");
	}
	
	freeBigInteger(&A);
	freeBigInteger(&C);
	freeBigInteger(&B);
	freeBigInteger(&D);
	
	A = stringToBigInteger("+1234");
	B = stringToBigInteger("+5678");
	printf("BigInt A = ");
	printBigInteger(stdout, A);
	printf("\n");
	printf("BigInt B = ");
	printBigInteger(stdout, B);
	printf("\n");
	
	C = sum(A,B);
	printf("sum of A + B = ");
	printBigInteger(stdout, C);
	printf("\n");
	freeBigInteger(&C);
	C = diff(A,B);
	printf("diff of A - B = ");
	printBigInteger(stdout, C);
	printf("\n");
	freeBigInteger(&C);
	C = prod(A,B);
	printf("prod of A * B = ");
	printBigInteger(stdout, C);
	printf("\n\n");
	freeBigInteger(&C);
	
	A = stringToBigInteger("123456789");
	B = stringToBigInteger("987654321");
	
	printf("BigInt A =");
	printBigInteger(stdout, A);
	printf("\n");
	printf("BigInt B =");
	printBigInteger(stdout, B);
	printf("\n\n");
	
	freeBigInteger(&B);
	freeBigInteger(&A);
	
	A = stringToBigInteger("+123456789");
	B = stringToBigInteger("+987654321");
	C = newBigInteger();
	printf("+A + +B = ");
	add(C,A,B);
	printBigInteger(stdout, C);
	printf("\n");
	freeBigInteger(&B);
	freeBigInteger(&A);
	
	A = stringToBigInteger("+123456789");
	B = stringToBigInteger("-987654321");
	printf("+A + -B = ");
	add(C,A,B);
	printBigInteger(stdout, C);
	printf("\n");
	freeBigInteger(&B);
	freeBigInteger(&A);
	
	A = stringToBigInteger("-123456789");
	freeBigInteger(&A);
	A = stringToBigInteger("-123456789");
	B = stringToBigInteger("+987654321");
	printf("-A + +B = ");
	add(C,A,B);
	printBigInteger(stdout, C);
	printf("\n");
	freeBigInteger(&B);
	freeBigInteger(&A);
	
	A = stringToBigInteger("-123456789");
	B = stringToBigInteger("-987654321");
	printf("-A + -B = ");
	add(C,A,B);
	printBigInteger(stdout, C);
	printf("\n");
	
	freeBigInteger(&A);
	freeBigInteger(&C);
	freeBigInteger(&B);
	freeBigInteger(&D);
	
	printf("\n");
	
	A = stringToBigInteger("+123456789");
	B = stringToBigInteger("+987654321");
	C = newBigInteger();
	printf("+A - +B = ");
	subtract(C,A,B);
	printBigInteger(stdout, C);
	printf("\n");
	freeBigInteger(&B);
	freeBigInteger(&A);
	
	A = stringToBigInteger("+123456789");
	B = stringToBigInteger("-987654321");
	printf("+A - -B = ");
	subtract(C,A,B);
	printBigInteger(stdout, C);
	printf("\n");
	freeBigInteger(&B);
	freeBigInteger(&A);
	
	A = stringToBigInteger("-123456789");
	B = stringToBigInteger("+987654321");
	printf("-A - +B = ");
	subtract(C,A,B);
	printBigInteger(stdout, C);
	printf("\n");
	freeBigInteger(&B);
	freeBigInteger(&A);
	
	A = stringToBigInteger("-123456789");
	B = stringToBigInteger("-987654321");
	printf("-A - -B = ");
	subtract(C,A,B);
	printBigInteger(stdout, C);
	printf("\n");
	
	freeBigInteger(&A);
	freeBigInteger(&C);
	freeBigInteger(&B);
	freeBigInteger(&D);
	
	printf("\n");
	
	A = stringToBigInteger("+123456789");
	B = stringToBigInteger("+987654321");
	C = newBigInteger();
	printf("+A * +B = ");
	multiply(C,A,B);
	printBigInteger(stdout, C);
	printf("\n");
	freeBigInteger(&B);
	freeBigInteger(&A);
	
	A = stringToBigInteger("+123456789");
	B = stringToBigInteger("-987654321");
	printf("+A * -B = ");
	multiply(C,A,B);
	printBigInteger(stdout, C);
	printf("\n");
	freeBigInteger(&B);
	freeBigInteger(&A);
	
	A = stringToBigInteger("-123456789");
	B = stringToBigInteger("+987654321");
	printf("-A * +B = ");
	multiply(C,A,B);
	printBigInteger(stdout, C);
	printf("\n");
	freeBigInteger(&B);
	freeBigInteger(&A);
	
	A = stringToBigInteger("-123456789");
	B = stringToBigInteger("-987654321");
	printf("-A * -B = ");
	multiply(C,A,B);
	printBigInteger(stdout, C);
	printf("\n");
	
	freeBigInteger(&A);
	freeBigInteger(&C);
	freeBigInteger(&B);
	freeBigInteger(&D);
	
	return 0;
}
