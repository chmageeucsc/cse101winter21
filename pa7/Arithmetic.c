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
#define MAX_LEN 15000

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
	char *array [200000];
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
	
	//A-B
	subtract(C,A,B);
	printBigInteger(out, C);
	fprintf(out, "\n\n");
	
	//A-A
	subtract(C,A,A);
	printBigInteger(out, C);
	fprintf(out, "\n\n");
	
	//3A-2B
	BigInteger D = stringToBigInteger("00000000003");
	BigInteger E = stringToBigInteger("00000000002");
	
	multiply(A,A,D);
	multiply(B,B,E);
	
	subtract(C,A,B);
	printBigInteger(out, C);
	fprintf(out, "\n\n");
	
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