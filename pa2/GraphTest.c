//-----------------------------------------------------------------------------
//
// Chantel Gee, chmagee
// 2021 Winter CSE 101 pa2
// 
// GraphTest.c
// Tester file for Graph
// 
// {printf("inf >:( \n");}
//-----------------------------------------------------------------------------

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "List.h"
#include "Graph.h"

int main(void) {
	Graph A = newGraph(100);
	List C = newList();
	List L = newList();
	
	/*addArc(A, 64, 4);
	addArc(A, 64, 3);
	addArc(A, 42, 2);
	addArc(A, 2, 64);
	addArc(A, 4, 2);
	addArc(A, 3, 42);
	BFS(A, 3);
	getPath(L, A, 64);
	printList(stdout, L);
	printf("\n");
	append(C, 3);
	append(C, 42);
	append(C, 2);
	append(C, 64);
	if (!equals(L, C)) {printf("equal 1 \n");}
	moveFront(L);
	BFS(A, 2);
	getPath(L, A, 2);
	append(C, 2);
	if (!equals(L, C)) {printf("equal 2 \n");}
	getPath(L, A, 99);
	if (equals(L, C)) {printf("equal 3 \n");}
	clear(L);
	clear(C);
	append(C, NIL);
	BFS(A, 99);
	getPath(L, A, 2);
	if (!equals(C, L)) {printf("equal 4 \n");}*/
	
	for (int i = 1; i <= 100; i++){
		if (getDist(A, i) != INF) {printf("inf >:( \n");}
		addArc(A, 64, 4);
		addArc(A, 64, 3);
		addArc(A, 42, 2);
		addArc(A, 2, 64);
		addArc(A, 4, 2);
		addArc(A, 3, 42);
		BFS(A, 64);
		if (getDist(A, 64) != 0) {printf("0 >:( \n");}
		if (getDist(A, 2) != 2) {printf("2 >:( \n");}
		BFS(A, 4);
		if (getDist(A, 42) != 4) {printf("4 >:( \n");}
		if (getDist(A, 43) != INF) {printf("inf >:( \n");}
		BFS(A, 99);
		if (getDist(A, 64) != INF) {printf("inf >:( \n");}
	}

	freeList(&L);
	freeList(&C);
	freeGraph(&A);
	return 0;
}
