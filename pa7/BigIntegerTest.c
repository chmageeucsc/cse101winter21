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
	BigInteger A = stringToBigInteger("23451531");
	BigInteger B = stringToBigInteger("71082289");
	BigInteger AB = sum(A, B);
	
	//subtract(AB, A, B);
	//multiply(A,A,A);
	printf("23451531 * 71082289 = ");
	printBigInteger(stdout, AB);
	printf("\n");
	
	BigInteger C = stringToBigInteger("-23451531");
	BigInteger D = stringToBigInteger("71082289");
	BigInteger CD = sum(C, D);
	
	//subtract(CD, C, D);
	printf("-23451531 * 71082289 = ");
	printBigInteger(stdout, CD);
	printf("\n");
	
	BigInteger E = stringToBigInteger("23451531");
	BigInteger F = stringToBigInteger("-71082289");
	BigInteger EF = sum(E, F);
	
	//subtract(EF, E, F);
	printf("25137801 * -71082289 = ");
	printBigInteger(stdout, EF);
	printf("\n");
	
	BigInteger G = stringToBigInteger("-23451531");
	BigInteger H = stringToBigInteger("-71082289");
	BigInteger GH = sum(G, H);
	
	//subtract(GH, G, H);
	printf("-23451531 * -71082289 = ");
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
	freeBigInteger(&A);
	
	return 0;
}
