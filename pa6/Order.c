//-----------------------------------------------------------------------------
//
// Chantel Gee, chmagee
// 2021 Winter CSE 101 pa6
// 
// Order.c
// Client file that uses Dictionary ADT
// 
//-----------------------------------------------------------------------------

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include "Dictionary.h"
#define MAX_LEN 1000

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
	//char array [line_count][MAX_LEN];		// old method used from pa1 (less efficient)
	char *array [200000];
	
	// read each line of input file
	while( fgets(line, MAX_LEN, in) != NULL)  {
		array[line_count] = calloc(strlen(line) + 1, sizeof(char*));
		strcpy(array[line_count], line);
		line_count++;
	}
	
	Dictionary D = newDictionary(0);
	for (int i = 0; i < line_count; i++) {
		insert(D, array[i], &i);
	}
	
	fprintf(out, "******************************************************\n");
	fprintf(out, "PRE-ORDER:\n");
	fprintf(out, "******************************************************\n");
	printDictionary(out, D, "pre");
	fprintf(out, "\n");
	fprintf(out, "\n");
	
	fprintf(out, "******************************************************\n");
	fprintf(out, "IN-ORDER:\n");
	fprintf(out, "******************************************************\n");
	printDictionary(out, D, "in");
	fprintf(out, "\n");
	fprintf(out, "\n");
	
	fprintf(out, "******************************************************\n");
	fprintf(out, "POST-ORDER:\n");
	fprintf(out, "******************************************************\n");
	printDictionary(out, D, "post");
	fprintf(out, "\n");
	fprintf(out, "\n");
	
	freeDictionary(&D);
	
	for (int i = 0; i < line_count; i++) {
		free(array[i]);
	}
	//free(array);

	// close files 
	fclose(in);
	fclose(out);

	return(0);
}
