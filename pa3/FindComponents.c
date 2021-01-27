//-----------------------------------------------------------------------------
//
// Chantel Gee, chmagee
// 2021 Winter CSE 101 pa3
// 
// FindComponents.c
// Implementation file for FindComponents
// 
//-----------------------------------------------------------------------------

#include <stdlib.h>
#include <stdio.h>
#include "List.h"
#include"Graph.h"
#define NIL 0

 #define MAX_LEN 100

//-----------------------------------------------------------------------------

int main(int argc, char * argv[]){

	FILE *in, *out;

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
	Graph G = newGraph(n);		// initial graph
	Graph T = NULL;				// for transpose
	List S = newList();			// for DFS vertices order of G
	
	while(!feof (in)) {
		fscanf (in, "%d %d", &x, &y);
		if((x == 0) || (y == 0)) {
			break;
		}
		addArc(G, x, y);
	}
	fprintf(out, "Adjacency list representation of G:\n");
	printGraph(out, G);
	fprintf(out, "\n");
	
	for(int i = 1; i <= n; i++) append(S, i);
	
	DFS(G,S);
	T = transpose(G);
	DFS(T,S);
	
	int scc = 0;
	for(int i = 1; i <= getOrder(G); i++) {
		if(getParent(T, i) == NIL) {
			scc++;
		}
	}
	
	fprintf(out, "G contains %d strongly connected components:\n", scc);
	for(int i = 1; i <= scc; i++) {
		fprintf(
	}
	
	freeGraph(&G);
	// close files 
	fclose(in);
	fclose(out);

	return(0);
}
