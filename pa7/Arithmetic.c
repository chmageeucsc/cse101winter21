//-----------------------------------------------------------------------------
//
// Chantel Gee, chmagee
// 2021 Winter CSE 101 pa7 
// 
// Arithmetic.c
// Client file for List and BigInteger ADT
// 
//-----------------------------------------------------------------------------

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include "BigInteger.h"
#define MAX_LEN 10005

int main(int argc, char * argv[]){

	int line_count;
	FILE *in, *out;
	char line[MAX_LEN];

	// check command line for correct number of arguments
	if( argc != 3 ){
		printf("Usage: %s <input file> <output file>\n", argv[0]);
		exit(1);
	}

	// open files for reading and writing 
	in = fopen(argv[1], "r");
	if( in==NULL ){
		printf("Unable to open file %s for reading\n", argv[1]);
		exit(1);
	}

	out = fopen(argv[2], "w");
	if( out==NULL ){
		printf("Unable to open file %s for writing\n", argv[2]);
		exit(1);
	}
	
	line_count = 0;
	char *array [MAX_LEN];
	// read each line of input file
	while( fgets(line, MAX_LEN, in) != NULL)  {
		array[line_count] = calloc(strlen(line) + 1, sizeof(char*));
		strcpy(array[line_count], line);
		line_count++;
	}

	BigInteger A = stringToBigInteger(array[1]);
	BigInteger B = stringToBigInteger(array[3]);
	BigInteger C = newBigInteger();
	
	//A
	printBigInteger(out, A);
	fprintf(out, "\n\n");
	
	//B
	printBigInteger(out, B);
	fprintf(out, "\n\n");
	
	//A+B
	add(C,A,B);
	printBigInteger(out, C);
	fprintf(out, "\n\n");
	freeBigInteger(&C);
	freeBigInteger(&B);
	freeBigInteger(&A);
	
	//A-B
	A = stringToBigInteger(array[1]);
	B = stringToBigInteger(array[3]);
	C = newBigInteger();
	subtract(C,A,B);
	printBigInteger(out, C);
	fprintf(out, "\n\n");
	freeBigInteger(&C);
	freeBigInteger(&B);
	freeBigInteger(&A);
	
	//A-A
	A = stringToBigInteger(array[1]);
	B = stringToBigInteger(array[3]);
	C = newBigInteger();
	subtract(C,A,A);
	printBigInteger(out, C);
	fprintf(out, "\n\n");
	freeBigInteger(&C);
	freeBigInteger(&B);
	freeBigInteger(&A);
	
	//3A-2B
	A = stringToBigInteger(array[1]);
	B = stringToBigInteger(array[3]);
	C = newBigInteger();
	BigInteger D = stringToBigInteger("000000003");
	BigInteger E = stringToBigInteger("000000002");
	BigInteger AD = newBigInteger();
	BigInteger BE = newBigInteger();
	
	multiply(AD,A,D);
	multiply(BE,B,E);
	
	subtract(C,AD,BE);
	printBigInteger(out, C);
	fprintf(out, "\n\n");
	freeBigInteger(&C);
	freeBigInteger(&B);
	freeBigInteger(&A);
	freeBigInteger(&BE);
	freeBigInteger(&AD);
	
	//AB
	A = stringToBigInteger(array[1]);
	B = stringToBigInteger(array[3]);
	C = newBigInteger();
	multiply(C,A,B);
	printBigInteger(out, C);
	fprintf(out, "\n\n");
	freeBigInteger(&C);
	freeBigInteger(&B);
	freeBigInteger(&A);
	
	//A^2
	A = stringToBigInteger(array[1]);
	B = stringToBigInteger(array[3]);
	C = newBigInteger();
	multiply(C,A,A);
	printBigInteger(out, C);
	fprintf(out, "\n\n");
	freeBigInteger(&C);
	freeBigInteger(&B);
	freeBigInteger(&A);
	
	//B^2
	A = stringToBigInteger(array[1]);
	B = stringToBigInteger(array[3]);
	C = newBigInteger();
	multiply(C,B,B);
	printBigInteger(out, C);
	fprintf(out, "\n\n");
	freeBigInteger(&C);
	freeBigInteger(&B);
	freeBigInteger(&A);
	
	//9A^4 + 16B^5
	A = stringToBigInteger(array[1]);
	B = stringToBigInteger(array[3]);
	C = newBigInteger();
	BigInteger A9 = stringToBigInteger("000000009");
	BigInteger B16 = stringToBigInteger("000000016");
	BigInteger A2A = prod(A,A);
	BigInteger A4 = prod(A2A,A2A);
	BigInteger Aa = prod(A9,A4);
	BigInteger B2B = prod(B,B);
	BigInteger B4B = prod(B2B,B2B);
	BigInteger B5 = prod(B4B,B);
	BigInteger Bb = prod(B16,B5);
	
	add(C,Aa,Bb);
	printBigInteger(out, C);
	fprintf(out, "\n");
	
	freeBigInteger(&A2A);
	freeBigInteger(&A4);
	freeBigInteger(&A9);
	freeBigInteger(&Aa);
	freeBigInteger(&B2B);
	freeBigInteger(&B4B);
	freeBigInteger(&B5);
	freeBigInteger(&B16);
	freeBigInteger(&Bb);
	
	freeBigInteger(&E);
	freeBigInteger(&D);
	freeBigInteger(&C);
	freeBigInteger(&B);
	freeBigInteger(&A);
	
	for (int i = 0; i < line_count; i++) {
		free(array[i]);
	}
	// close files 
	fclose(in);
	fclose(out);

	return(0);
}