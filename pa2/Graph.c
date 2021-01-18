//-----------------------------------------------------------------------------
//
// Chantel Gee, chmagee
// 2021 Winter CSE 101 pa2
// 
// List.h
// Header file for List
// 
//-----------------------------------------------------------------------------

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "List.h"

// private GraphObj type

typedef struct GraphObj {
	int order;	// number of vertices
	int size;	// number of edges
	int source;	// most recent vertex as source
	int *adj = (int*)calloc(order + 1, sizeof(int));	// neighbors of each vertex
	int *color = (int*)calloc(order + 1, sizeof(int));		// color for each vertex
	int *p = (int*)calloc(order + 1, sizeof(int));		// parent of each vertex
	int *d = (int*)calloc(order + 1, sizeof(int));	// distance from source to each vertex
	
} GraphObj;

/*** Constructors-Destructors ***/

Graph newGraph(int n) {
	Graph G = malloc(sizeof(GraphObj));
	G->order = 0;
	G->size = 0;
	return G;
}

void freeGraph(Graph* pG) {
	if(pG != NULL && *pG != NULL) {
		free(G->adj);
		free(G->color);
		free(G->p);
		free(G->d);
	}
	free(*pG);
	*pG = NULL;
}

/*** Access functions ***/

int getOrder(Graph G) {
	if(G == NULL){
		printf("Graph Error: calling getOrder() on NULL Graph reference\n");
		exit(EXIT_FAILURE);
	}
	return G->order;
}
int getSize(Graph G) {
	if(G == NULL){
		printf("Graph Error: calling getSize() on NULL Graph reference\n");
		exit(EXIT_FAILURE);
	}
	return G->size;
}
int getSource(Graph G) {
	
}
int getParent(Graph G, int u) {
	
}
int getDist(Graph G, int u) {
	
}
void getPath(List L, Graph G, int u) {
	
}

/*** Manipulation procedures ***/

void makeNull(Graph G) {
	
}
void addEdge(Graph G, int u, int v) {
	
}
void addArc(Graph G, int u, int v) {
	
}
void BFS(Graph G, int s) {
	
}

/*** Other operations ***/

void printGraph(FILE* out, Graph G) {
	
}

