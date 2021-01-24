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
#include <stdbool.h>
#include <stdint.h>
#include "List.h"
#include "Graph.h"

int main(void) {
	Graph G = newGraph(10);
	List L = newList();
	
	addEdge(G, 9, 10);
	addEdge(G, 5, 6);
	addEdge(G, 2, 5);
	addArc(G, 1, 2);
	addArc(G, 2, 4);
	addArc(G, 5, 3);
	addArc(G, 3, 7);
	addArc(G, 4, 7);
	addArc(G, 6, 8);
	
	printGraph(stdout, G);
	
	printf("\nBefore BFS\n\n");
	
	printf("Vertices: %d\n", getOrder(G));
	printf("Edges: %d\n", getSize(G));
	printf("Most Recent Source: %d\n", getSource(G));
	printf("Parent of 3: %d\n", getParent(G, 3));
	printf("Distance from Source %d to 3: %d\n", getSource(G), getDist(G, 3));
	
	if(getDist(G, 3) != INF) {
		if(getDist(G, 3) == 0) {
			printf("The distance from %d to %d is %d\n", getSource(G), 3, getDist(G, 3));
			printf("A shortest %d-%d path is: %d\n", getSource(G), 3, getSource(G));
		}
		else {
			getPath(L, G, 3);
			printf("The distance from %d to %d is %d\n", getSource(G), 3, getDist(G, 3));
			printf("A shortest %d-%d path is: ", getSource(G), 3);
			printList(stdout, L);
			printf("\n");
		}
	}
	else {
		printf("The distance from %d to %d is infinity\n", getSource(G), 3);
		printf("No %d-%d path exists\n", getSource(G), 3);
		
	}
	
	if(getDist(G, 10) != INF) {
		if(getDist(G, 10) == 0) {
			printf("The distance from %d to %d is %d\n", getSource(G), 10, getDist(G, 10));
			printf("A shortest %d-%d path is: %d\n", getSource(G), 10, getSource(G));
		}
		else {
			getPath(L, G, 10);
			printf("The distance from %d to %d is %d\n", getSource(G), 10, getDist(G, 10));
			printf("A shortest %d-%d path is: ", getSource(G), 10);
			printList(stdout, L);
			printf("\n");
		}
	}
	else {
		printf("The distance from %d to %d is infinity\n", getSource(G), 10);
		printf("No %d-%d path exists\n", getSource(G), 10);
		
	}
	
	if(getDist(G, 6) != INF) {
		if(getDist(G, 6) == 0) {
			printf("The distance from %d to %d is %d\n", getSource(G), 6, getDist(G, 6));
			printf("A shortest %d-%d path is: %d\n", getSource(G), 6, getSource(G));
		}
		else {
			getPath(L, G, 6);
			printf("The distance from %d to %d is %d\n", getSource(G), 6, getDist(G, 6));
			printf("A shortest %d-%d path is: ", getSource(G), 6);
			printList(stdout, L);
			printf("\n");
		}
	}
	else {
		printf("The distance from %d to %d is infinity\n", getSource(G), 6);
		printf("No %d-%d path exists\n", getSource(G), 6);
		
	}
	
	BFS(G, 6);
	
	printf("\nAfter BFS\n\n");
	
	printf("Vertices: %d\n", getOrder(G));
	printf("Edges: %d\n", getSize(G));
	printf("Most Recent Source: %d\n", getSource(G));
	printf("Parent of 3: %d\n", getParent(G, 3));
	printf("Distance from Source %d to 3: %d\n", getSource(G), getDist(G, 3));
	
	if(getDist(G, 3) != INF) {
		if(getDist(G, 3) == 0) {
			printf("The distance from %d to %d is %d\n", getSource(G), 3, getDist(G, 3));
			printf("A shortest %d-%d path is: %d\n", getSource(G), 3, getSource(G));
		}
		else {
			getPath(L, G, 3);
			printf("The distance from %d to %d is %d\n", getSource(G), 3, getDist(G, 3));
			printf("A shortest %d-%d path is: ", getSource(G), 3);
			printList(stdout, L);
			printf("\n");
		}
	}
	else {
		printf("The distance from %d to %d is infinity\n", getSource(G), 3);
		printf("No %d-%d path exists\n", getSource(G), 3);
		
	}
	
	if(getDist(G, 10) != INF) {
		if(getDist(G, 10) == 0) {
			printf("The distance from %d to %d is %d\n", getSource(G), 10, getDist(G, 10));
			printf("A shortest %d-%d path is: %d\n", getSource(G), 10, getSource(G));
		}
		else {
			getPath(L, G, 10);
			printf("The distance from %d to %d is %d\n", getSource(G), 10, getDist(G, 10));
			printf("A shortest %d-%d path is: ", getSource(G), 10);
			printList(stdout, L);
			printf("\n");
		}
	}
	else {
		printf("The distance from %d to %d is infinity\n", getSource(G), 10);
		printf("No %d-%d path exists\n", getSource(G), 10);
		
	}
	
	if(getDist(G, 6) != INF) {
		if(getDist(G, 6) == 0) {
			printf("The distance from %d to %d is %d\n", getSource(G), 6, getDist(G, 6));
			printf("A shortest %d-%d path is: %d\n", getSource(G), 6, getSource(G));
		}
		else {
			getPath(L, G, 6);
			printf("The distance from %d to %d is %d\n", getSource(G), 6, getDist(G, 6));
			printf("A shortest %d-%d path is: ", getSource(G), 6);
			printList(stdout, L);
			printf("\n");
		}
	}
	else {
		printf("The distance from %d to %d is infinity\n", getSource(G), 6);
		printf("No %d-%d path exists\n", getSource(G), 6);
		
	}
	
	makeNull(G);
	
	printf("\nAfter makeNull\n\n");
	
	printf("Edges: %d\n", getSize(G));
	printGraph(stdout, G);
	

	freeList(&L);
	freeGraph(&G);
	return 0;
}
