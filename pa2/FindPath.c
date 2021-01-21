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
#include <string.h>
#include "List.h"
#include"Graph.h"

 #define MAX_LEN 100

//-----------------------------------------------------------------------------

int main(int argc, char * argv[]){

	//int line_count;
	FILE *in, *out;
	//char line[MAX_LEN];

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
	
	int n, x, y;
	fscanf(in, "%d", &n);
	Graph G = newGraph(n);
	while(!feof (in)) {
		fscanf (in, "%d %d", &x, &y);
		if((x == 0) || (y == 0)) {
			break;
		}
		addEdge(G, x, y);
	}
	printGraph(out, G);
	
	while(!feof (in)) {
		fscanf (in, "%d %d", &x, &y);
		if((x == 0) || (y == 0)) {
			break;
		}
		fprintf(out, "\n");
		BFS(G, x);
		List L = newList();
		if(getDist(G, y) != INF) {
			if(getDist(G, y) == 0) {
				fprintf(out, "The distance from %d to %d is %d\n", x, y, getDist(G, y));
				fprintf(out, "A shortest %d-%d path is: %d\n", x, y, x);
			}
			else {
				getPath(L, G, y);
				fprintf(out, "The distance from %d to %d is %d\n", x, y, getDist(G, y));
				fprintf(out, "A shortest %d-%d path is: ", x, y);
				printList(out, L);
				fprintf(out, "\n");
			}
		}
		else {
			fprintf(out, "The distance from %d to %d is infinity\n", x, y);
			fprintf(out, "No %d-%d path exists\n", x, y);
			
		}
		freeList(&L);
	}
	
	freeGraph(&G);
	// close files 
	fclose(in);
	fclose(out);

	return(0);
}
