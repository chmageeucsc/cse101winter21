//-----------------------------------------------------------------------------
//
// Chantel Gee, chmagee
// 2021 Winter CSE 101 pa2
// 
// FindPath.c
// Implementation file for FindPath
// 
//-----------------------------------------------------------------------------

#include <stdlib.h>
#include <stdio.h>
#include "List.h"
#include"Graph.h"

 #define MAX_LEN 100

//-----------------------------------------------------------------------------

int main(int argc, char * argv[]){

	//int line_count;
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
	
	char* x;
	x = fgets(line, MAX_LEN, in);
	fprintf(out, "%s", x);

	// close files 
	fclose(in);
	fclose(out);

	return(0);
}
