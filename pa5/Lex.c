//-----------------------------------------------------------------------------
//
// Chantel Gee, chmagee
// 2021 Winter CSE 101 pa5
// 
// Lex.c
// Implementation file for Lex
// 
//-----------------------------------------------------------------------------

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "Dictionary.h"

#define KEY_TYPE char*
#define VAL_TYPE int
#define KEY_UNDEF NULL
#define VAL_UNDEF -1
#define KEY_FORMAT "%s"
#define VAL_FORMAT "%d"
#define KEY_CMP(x,y) strcmp((x),(y))
#define MAX_LEN 1000

//-----------------------------------------------------------------------------

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
	
	/*array = (char**)malloc(line_count*sizeof(char*)); 
	int x = 0;
	rewind(in);		// resets fgets to the top of the file
	while( fgets(line, MAX_LEN, in) != NULL)  {	// populates array with lines from input file
		strcpy(array[x], line);
		x++;
	}*/
	Dictionary D = newDictionary(0);
	for (int i = 0; i < line_count; i++) {
		insert(D, array[i], i);
	}
	
	// forward iteration over A ----------------------------
	beginForward(D);
	fprintf(out, KEY_FORMAT, currentKey(D));
	next(D);
	for(; currentVal(D)!=VAL_UNDEF; next(D)){
	  fprintf(out, KEY_FORMAT, currentKey(D));
	}
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
