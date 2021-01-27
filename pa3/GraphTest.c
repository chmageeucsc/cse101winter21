//-----------------------------------------------------------------------------
//
// Chantel Gee, chmagee
// 2021 Winter CSE 101 pa3
// 
// GraphTest.c
// Tester file for Graph
// 
//-----------------------------------------------------------------------------

#include <stdlib.h>
#include <stdio.h>
#include "Graph.h"

int main(void) {
	Graph G = newGraph(8);
	Graph T = NULL, C = NULL;
	List S = newList();
	for(int i = 1; i <= 8; i++) append(S, i);
	
	addEdge(G, 2, 5);
	addEdge(G, 5, 6);
	addArc(G, 1, 2);
	addArc(G, 2, 4);
	addArc(G, 5, 3);
	addArc(G, 3, 7);
	addArc(G, 4, 7);
	addArc(G, 6, 8);
	
	printGraph(stdout, G);
	printf("\nBefore DFS\n");
	
	printf("Vertices: %d\n", getOrder(G));
	printf("Edges: %d\n", getSize(G));
	printf("Parent of 3: %d\n", getParent(G, 3));
	printf("Discover time of 3: %d\n", getDiscover(G, 3));
	printf("Finish time of 3: %d\n", getFinish(G, 3));
	
	DFS(G, S);
	
	printf("\nDFS\n\n");
	printf("x:  d  f  p\n");
	for(int i = 1; i <= 8; i++){
		printf("%d: %2d %2d %2d\n", i, getDiscover(G, i), getFinish(G, i), getParent(G, i));
	}
	
	printf("\nTranspose\n");
	T = transpose(G);
	printGraph(stdout, T);
	printf("\nCopy\n");
	C = copyGraph(G);
	printGraph(stdout, C);
	
	DFS(T, S);
	
	printf("\nDFS of Transpose\n\n");
	printf("x:  d  f  p\n");
	for(int i = 1; i <= 8; i++){
		printf("%d: %2d %2d %2d\n", i, getDiscover(T, i), getFinish(T, i), getParent(T, i));
	}
	
	freeGraph(&G);
	freeGraph(&T);
	freeGraph(&C);
	freeList(&S);

	return 0;
}
