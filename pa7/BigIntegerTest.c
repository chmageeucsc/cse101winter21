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
	
	BigInteger A = stringToBigInteger("+111122223333");
	BigInteger B = stringToBigInteger("+222211110000");
	BigInteger C = newBigInteger();
	BigInteger D = stringToBigInteger("+333333333333");
	add(C,A,B);
	
	if (equals(C,D) != 1) {
		printf("test 1\n");
		printBigInteger(stdout, C);
		printf("\n");
		printBigInteger(stdout, D);
		printf("\n");
	}
	
	freeBigInteger(&B);
	freeBigInteger(&D);
	
	B = stringToBigInteger("-111122223333");
	add(C,A,B);
	if (sign(C) != 0) {
		printf("test 2\n");
		printf("sign of C = %d\nC = ", sign(C));
		printBigInteger(stdout, C);
		printf("\n");
	}
	
	freeBigInteger(&B);
	
	B = stringToBigInteger("-110122223333");
	D = stringToBigInteger("1000000000");
	add(C,A,B);
	
	if (sign(C) != 1) {
		printf("test 31\n");
		printf("sign of C = %d\nC = ", sign(C));
		printBigInteger(stdout, C);
		printf("\n");
	}
	
	if (equals(C,D) != 1) {
		printf("test 32\n");
		printBigInteger(stdout, C);
		printf("\n");
		printBigInteger(stdout, D);
		printf("\n");
	}

	freeBigInteger(&B);
	freeBigInteger(&D);
		
	B = stringToBigInteger("-112122223333");
	D = stringToBigInteger("-1000000000");
	
	add(C,A,B);
	
	if (sign(C) != -1) {
		printf("test 41\n");
		printf("sign of C = %d\nC = ", sign(C));
		printBigInteger(stdout, C);
		printf("\n");
	}
	
	if (equals(C,D) != 1) {
		printf("test 42\n");
		printBigInteger(stdout, C);
		printf("\n");
		printBigInteger(stdout, D);
		printf("\n");
	}
	
	freeBigInteger(&D);
	freeBigInteger(&A);
	
	A = stringToBigInteger("-221211110000");
	D = stringToBigInteger("-333333333333");
	
	add(C,A,B);
	
	if (equals(C,D) != 1) {
		printf("test 5\n");
		printBigInteger(stdout, C);
		printf("\n");
		printBigInteger(stdout, D);
		printf("\n");
	}	
	
	freeBigInteger(&A);
	freeBigInteger(&C);
	freeBigInteger(&B);
	freeBigInteger(&D);
	
	A = stringToBigInteger("111122223333");
	B = stringToBigInteger("111122223333");
	C = newBigInteger();
	D = stringToBigInteger("12348148518469129628889");
	subtract(C,A,B);
	
	freeBigInteger(&B);
	
	B = stringToBigInteger("121122223333");

	subtract(C,A,B);
		
	freeBigInteger(&D);
	
	freeBigInteger(&B);
	B = stringToBigInteger("101122223333");
	D = stringToBigInteger("10000000000");
	subtract(C,A,B);
	
	freeBigInteger(&D);
	negate(B);
	D = stringToBigInteger("212244446666");
	subtract(C,A,B);
	
	if (equals(C,D) != 1) {
		printBigInteger(stdout, C);
		printf("\n");
		printBigInteger(stdout, D);
		printf("\n");
	}
	
	freeBigInteger(&A);
	freeBigInteger(&C);
	freeBigInteger(&B);
	freeBigInteger(&D);
	
	A = stringToBigInteger("111122223333");
	B = stringToBigInteger("111122223333");
	C = newBigInteger();
	D = stringToBigInteger("12348148518469129628889");
	
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
	
	multiply(C,A,B);
	
	if (sign(C) != -1) {
		printf("1 2\n");
		printf("sign of C = %d\nC = ", sign(C));
		printBigInteger(stdout, C);
		printf("\n");
	}
	
	if (equals(C,D) != 1) {
		printf("3 4\n");
		printBigInteger(stdout, C);
		printf("\n");
		printBigInteger(stdout, D);
		printf("\n");
	}
	
	makeZero(B);
	
	multiply(C,A,B);
	
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
	
	A = stringToBigInteger("-111122223333");
	B = stringToBigInteger("111122223333");
	D = stringToBigInteger("-12348148518469129628889");
	
	C = prod(A,B);
	
	if (sign(C) != -1) {
		printf("1 2\n");
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
	
	C = prod(A,B);
	
	if (sign(C) != 1) {
		printf("3 4\n");
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
	
	/*BigInteger A = stringToBigInteger("23451531");
	BigInteger B = stringToBigInteger("71082289");
	BigInteger AB = sum(A, B);
	
	//subtract(AB, A, B);
	//multiply(A,A,A);
	printf("23451531 + 71082289 = ");
	printBigInteger(stdout, AB);
	printf("\n");
	
	BigInteger C = stringToBigInteger("-23451531");
	BigInteger D = stringToBigInteger("71082289");
	BigInteger CD = sum(C, D);
	
	//subtract(CD, C, D);
	printf("-23451531 + 71082289 = ");
	printBigInteger(stdout, CD);
	printf("\n");
	
	BigInteger E = stringToBigInteger("23451531");
	BigInteger F = stringToBigInteger("-71082289");
	BigInteger EF = sum(E, F);
	
	//subtract(EF, E, F);
	printf("25137801 + -71082289 = ");
	printBigInteger(stdout, EF);
	printf("\n");
	
	BigInteger G = stringToBigInteger("-23451531");
	BigInteger H = stringToBigInteger("-71082289");
	BigInteger GH = sum(G, H);
	
	//subtract(GH, G, H);
	printf("-23451531 + -71082289 = ");
	printBigInteger(stdout, GH);
	printf("\n");
	
	freeBigInteger(&GH);
	freeBigInteger(&H);
	freeBigInteger(&G);
	freeBigInteger(&EF);
	freeBigInteger(&F);
	freeBigInteger(&E);
	freeBigInteger(&CD);
	freeBigInteger(&D);
	freeBigInteger(&C);
	freeBigInteger(&AB);
	freeBigInteger(&B);
	freeBigInteger(&A);*/
	
	return 0;
}
