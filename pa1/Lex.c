//-----------------------------------------------------------------------------
// Lex.c
// Implementation file for Lex
//
// Chantel Gee
// chmagee
// pa1
// 
//-----------------------------------------------------------------------------

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "List.h"

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

	// read each line of input file, then count and print tokens
	line_count = 0;
	while( fgets(line, MAX_LEN, in) != NULL)  {
		line_count++;
	}
	
	//fprintf(out, "the total number of lines is %d\n", line_count);
	char array [line_count][MAX_LEN];
	int x = 0;
	rewind(in);		// resets fgets to the top of the file
	while( fgets(line, MAX_LEN, in) != NULL)  {	// populates array with lines from input file
		strcpy(array[x], line);
		x++;
	}
	int j = 1;
	List L = newList();
	append(L, 0);
	for (int i = 0; i < line_count; i++) {
		moveFront(L);
		while (j <= i) {
			if(strcmp(array[i], array[get(L)]) < 0) {
				insertBefore(L, i);
				break;
			}
			else if(strcmp(array[i], array[get(L)]) > 0) {
				moveNext(L);
				if(index(L) == -1) {
					append(L,i);
					break;
				}
			}
			else if(strcmp(array[i], array[get(L)]) == 0) {
				insertAfter(L, i);
				break;
			}
		}
	}
	
	//printList(out, L);
	moveFront(L);
	for (int i = 0; i < line_count; i++) {
		fprintf(out, "%s", array[get(L)]);
		moveNext(L);
	}
	
	freeList(&L);

	// close files 
	fclose(in);
	fclose(out);

	return(0);
}
