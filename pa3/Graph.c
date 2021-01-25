//-----------------------------------------------------------------------------
//
// Chantel Gee, chmagee
// 2021 Winter CSE 101 (updated from pa2)
// 
// Graph.c
// Implementation file for Graph
// 
//-----------------------------------------------------------------------------

#include <stdlib.h>
#include <stdio.h>
#include "List.h"
#include "Graph.h"

#define UNDEF -1
#define NIL 0
#define WHITE 1
#define GRAY 2
#define BLACK 3

// extras ---------------------------------------------------------------------

// structs --------------------------------------------------------------------

// private NodeObj type
typedef struct NodeObj {
	int data;
	struct NodeObj* next;
	struct NodeObj* prev;
} NodeObj;

// private Node type
typedef NodeObj* Node;

// private ListObj type
typedef struct ListObj {
	Node front;
	Node back;
	Node cursor;
	int length;
	int index;
} ListObj;

// private GraphObj type

typedef struct GraphObj {
	int order;	// number of vertices
	int size;	// number of edges
	List *adj; 	// list of neighbors of each vertex
	int *color;	// color for each vertex
	int *p;		// parent of each vertex
	int *dt;	// discover time for each vertex
	int *ft;	// finish time for each vertex
} GraphObj;

/*** Constructors-Destructors ***/

Graph newGraph(int n) {
	Graph G = malloc(sizeof(GraphObj));
	G->order = n;
	G->size = 0;
	G->adj = malloc(sizeof(List)*(n+1));	// list of neighbors of each vertex
	G->color = (int*)calloc(G->order + 1, sizeof(int));	// color for each vertex
	G->p = (int*)calloc(G->order + 1, sizeof(int));		// parent of each vertex
	G->dt = (int*)calloc(G->order + 1, sizeof(int));	// discover time for each vertex
	G->ft = (int*)calloc(G->order + 1, sizeof(int));	// finish time for each vertex
	for (int i = 1; i <= getOrder(G); i++){
		G->adj[i] = newList();
		G->dt[i] = INF;
	}
	return G;
}

void freeGraph(Graph* pG) {
	if(pG != NULL && *pG != NULL) {
		for(int i = 1; i <= getOrder(*pG); i++){
			freeList(&(*pG)->adj[i]);
		}
		free((*pG)->adj);
		free((*pG)->color);
		free((*pG)->p);
		free((*pG)->dt);
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

// pre: 1 <= u <= getOrder(G)
int getParent(Graph G, int u) {
	if(G == NULL){
		printf("Graph Error: calling getParent() on NULL Graph reference\n");
		exit(EXIT_FAILURE);
	}
	if(u < 1 || u > getOrder(G)) {
		printf("Graph Error: calling getParent() out of bounds\n");
		exit(EXIT_FAILURE);
	}
	
	return G->p[u];
}

// pre: 1 <= u <= getOrder(G)
void getDiscover(Graph G, int u) {
	if(G == NULL){
		printf("Graph Error: calling getPath() on NULL Graph reference\n");
		exit(EXIT_FAILURE);
	}
	if(u < 1 || u > getOrder(G)) {
		printf("Graph Error: calling getPath() out of bounds\n");
		exit(EXIT_FAILURE);
	}
	
	if (u == getSource(G)) {
		append(L, u);
	}
	else if (G->p[u] == NIL) {
		append(L, NIL);
	}
	else {
		getPath(L, G, G->p[u]);
		append(L, u);
	}
}

// pre: 1 <= u <= getOrder(G)
void getDiscover(Graph G, int u) {
	if(G == NULL){
		printf("Graph Error: calling getPath() on NULL Graph reference\n");
		exit(EXIT_FAILURE);
	}
	if(u < 1 || u > getOrder(G)) {
		printf("Graph Error: calling getPath() out of bounds\n");
		exit(EXIT_FAILURE);
	}
	return G->disc[u];
}

/*** Manipulation procedures ***/

// pre: 1 <= u <= getOrder(G) and 1 <= v <= getOrder(G)
void addEdge(Graph G, int u, int v) {	// both ways
	if(G == NULL){
		printf("Graph Error: calling addEdge() on NULL Graph reference\n");
		exit(EXIT_FAILURE);
	}
	if((u < 1 && u > getOrder(G)) || (v < 1 && v > getOrder(G))) {
		printf("Graph Error: calling addEdge() out of bounds\n");
		exit(EXIT_FAILURE);
	}
	addArc(G, u, v);
	addArc(G, v, u);
	G->size--;
}

// pre: 1 <= u <= getOrder(G) and 1 <= v <= getOrder(G)
void addArc(Graph G, int u, int v) {	// one way
	if(G == NULL){
		printf("Graph Error: calling addArc() on NULL Graph reference\n");
		exit(EXIT_FAILURE);
	}
	if((u < 1 && u > getOrder(G)) || (v < 1 && v > getOrder(G))) {
		printf("Graph Error: calling addArc() out of bounds\n");
		exit(EXIT_FAILURE);
	}
	G->size++;
	if(length(G->adj[u]) == 0) {
		append(G->adj[u], v);
	}
	else {
		int j = 1;
		for (int i = 0; i < length(G->adj[u]); i++) {
			moveFront(G->adj[u]);
			while (j > i) {
				if (v < get(G->adj[u])) {
					insertBefore(G->adj[u], v);
					break;
				}
				else if (v > get(G->adj[u])) {
					moveNext(G->adj[u]);
					if (index(G->adj[u]) == -1) {
						append(G->adj[u], v);
						break;
					}
				}
				else if (v == get(G->adj[u])) {
					break;
				}
			}
		}
	}
}

void visit(int x) {
	
}

// pre: length(S) == getOrder(G)
void DFS(Graph G, List s) {
	
}

/*** Other operations ***/

Graph transpose(Graph G) {
	
}

Graph copyGraph(Graph G) {
	
}

void printGraph(FILE* out, Graph G) {
	if(G == NULL){
		printf("Graph Error: calling printGraph() on NULL Graph reference\n");
		exit(EXIT_FAILURE);
	}
	for(int i = 1; i <= getOrder(G); i++){
		fprintf(out, "%d: ", i);
		printList(out, G->adj[i]);
		fprintf(out, "\n");
	}
}
