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
#include "Graph.h"

#define INF -1
#define NIL 0
#define WHITE 1
#define GRAY 2
#define BLACK 3

// private GraphObj type

typedef struct GraphObj {
	int order;	// number of vertices
	int size;	// number of edges
	int source;	// most recent vertex as source
	List adj; 	// list of neighbors of each vertex
	int *color;	// color for each vertex
	int *p;		// parent of each vertex
	int *d;		// distance from source to each vertex
} GraphObj;

/*** Constructors-Destructors ***/

Graph newGraph(int n) {
	Graph G = malloc(sizeof(GraphObj));
	G->order = n;
	G->size = 0;
	G->source = NIL;
	G->adj = (List*)calloc(G->order + 1, sizeof(List));	// list of neighbors of each vertex
	for (int i = 1; i < G->order + 1; i++){
		G->adj[i] = newList();
	}
	G->color = (int*)calloc(G->order + 1, sizeof(int));	// color for each vertex
	G->p = (int*)calloc(G->order + 1, sizeof(int));		// parent of each vertex
	G->d = (int*)calloc(G->order + 1, sizeof(int));		// distance from source to each vertex
	return G;
}

void freeGraph(Graph* pG) {
	if(pG != NULL && *pG != NULL) {
		freeList(*pG->adj);
		free(*pG->color);
		free(*pG->p);
		free(*pG->d);
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
	printf("filler text");
	return 1;
}

// pre: 1 <= u <= getOrder(G)
int getParent(Graph G, int u) {
	if(u < 1 || u > getOrder(G)) {
		printf("Graph Error: calling getParent() out of bounds\n");
		exit(EXIT_FAILURE);
	}
	printf("filler text");
	return 1;
}
// pre: 1 <= u <= getOrder(G)
int getDist(Graph G, int u) {
	if(u < 1 || u > getOrder(G)) {
		printf("Graph Error: calling getParent() out of bounds\n");
		exit(EXIT_FAILURE);
	}
	printf("filler text");
	return 1;
}

// pre: 1 <= u <= getOrder(G)
void getPath(List L, Graph G, int u) {
	if(u < 1 || u > getOrder(G)) {
		printf("Graph Error: calling getParent() out of bounds\n");
		exit(EXIT_FAILURE);
	}
	printf("filler text");
	return 1;
}

/*** Manipulation procedures ***/

void makeNull(Graph G) {
	printf("filler text");
}

void addEdge(Graph G, int u, int v) {
	printf("filler text");
}

void addArc(Graph G, int u, int v) {
	printf("filler text");
}

void BFS(Graph G, int s) {
	for(int i = 1; i < G->size; i++) {	// how to check if i is not s ?
		if (i != s){
			G->color[i] = WHITE;
			G->d[i] = INF;
			G->p[i] = NIL;
		}
	}
	G->color[s] = GRAY;
	G->d[s] = 0;
	G->p[s] = NIL;
	List L = newList();
	append(L,s);
	while(L != NULL) {
		int x = front(L);
		deleteFront(L);
		int adjx = sizeof(G->adj) / sizeof(G->adj[x];
		for(int y = 0; y < adjx; y++) {
			if(color[y] == WHITE) {
				color[y] = GRAY;
				G->d[y] = G->d[x] + 1;
				G->p[y] = x;
				append(L,y);
			}
		}
		G->color[x] = BLACK;
	}
}

/*** Other operations ***/

void printGraph(FILE* out, Graph G) {
	printf("filler text");
}
