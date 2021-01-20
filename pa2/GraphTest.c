//-----------------------------------------------------------------------------
//
// Chantel Gee, chmagee
// 2021 Winter CSE 101 pa2
// 
// GraphTest.c
// Tester file for Graph
// 
//-----------------------------------------------------------------------------

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "List.h"
#include "Graph.h"

int main(void) {
	Graph G = newGraph(4);
	addEdge(G, 1, 2);
	addEdge(G, 1, 3);
	addEdge(G, 2, 3);
	addEdge(G, 3, 4);
	addEdge(G, 4, 1);
	
	printGraph(stdout, G);

	freeGraph(&G);
	return 0;
}
