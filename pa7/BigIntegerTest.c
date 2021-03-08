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
	BigInteger A = stringToBigInteger("25137801");
	BigInteger B = stringToBigInteger("482231");
	BigInteger AB = sum(A, B);
	
	//subtract(AB, A, B);
	//add(A,A,B);
	printf("25137801 + 482231 = ");
	printBigInteger(stdout, AB);
	printf("\n");
	
	/*BigInteger C = stringToBigInteger("-25137801");
	BigInteger D = stringToBigInteger("482231");
	BigInteger CD = sum(C, D);
	
	//subtract(CD, C, D);
	printf("-25137801 + 482231 = ");
	printBigInteger(stdout, CD);
	printf("\n");
	
	BigInteger E = stringToBigInteger("25137801");
	BigInteger F = stringToBigInteger("-482231");
	BigInteger EF = sum(E, F);
	
	//subtract(EF, E, F);
	printf("25137801 + -482231 = ");
	printBigInteger(stdout, EF);
	printf("\n");
	
	BigInteger G = stringToBigInteger("-25137801");
	BigInteger H = stringToBigInteger("-482231");
	BigInteger GH = sum(G, H);
	
	//subtract(GH, G, H);
	printf("-25137801 + -482231 = ");
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
	freeBigInteger(&C);*/
	freeBigInteger(&AB);
	freeBigInteger(&B);
	freeBigInteger(&A);
	
	return 0;
}
