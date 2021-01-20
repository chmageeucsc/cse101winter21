//-----------------------------------------------------------------------------
//
// Chantel Gee, chmagee
// 2021 Winter CSE 101 pa2
// 
// Graph.c
// Implementation file for List
// 
//-----------------------------------------------------------------------------

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "List.h"
#include "Graph.h"

#define INF -1
#define NIL 0
#define WHITE 1
#define GRAY 2
#define BLACK 3

// extras ---------------------------------------------------------------------

int bfs_source = NIL;
bool bfs_on = false;

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
	int source;	// most recent vertex as source
	List *adj; 	// list of neighbors of each vertex
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
	G->adj = malloc(sizeof(List)*(n+1));	// list of neighbors of each vertex
	for (int i = 1; i <= getOrder(G); i++){
		G->adj[i] = newList();
	}
	G->color = (int*)calloc(G->order + 1, sizeof(int));	// color for each vertex
	G->p = (int*)calloc(G->order + 1, sizeof(int));		// parent of each vertex
	G->d = (int*)calloc(G->order + 1, sizeof(int));		// distance from source to each vertex
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
		free((*pG)->d);
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
	if(G == NULL){
		printf("Graph Error: calling getSource() on NULL Graph reference\n");
		exit(EXIT_FAILURE);
	}
	if(bfs_on == true) {
		return bfs_source;
	}
	return NIL;
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
	if(bfs_on == true) {
		return G->p[u];
	}
	return NIL;
}
// pre: 1 <= u <= getOrder(G)
int getDist(Graph G, int u) {
	if(G == NULL){
		printf("Graph Error: calling getDist() on NULL Graph reference\n");
		exit(EXIT_FAILURE);
	}
	if(u < 1 || u > getOrder(G)) {
		printf("Graph Error: calling getDist() out of bounds\n");
		exit(EXIT_FAILURE);
	}
	if(bfs_on == true) {
		return G->d[u];
	}
	return INF;
}

// pre: getSource(G) != NIL
// pre: 1 <= u <= getOrder(G)
void getPath(List L, Graph G, int u) {
	if(G == NULL){
		printf("Graph Error: calling getPath() on NULL Graph reference\n");
		exit(EXIT_FAILURE);
	}
	if(getSource(G) == NIL) {
		printf("Graph Error: calling getPath() with no source\n");
		exit(EXIT_FAILURE);
	}
	if(u < 1 || u > getOrder(G)) {
		printf("Graph Error: calling getPath() out of bounds\n");
		exit(EXIT_FAILURE);
	}
	while(G->p[u] != getSource(G)) {
		if(G->p[u] == NIL) {
			append(L, -1);
			break;
		}
		else{
			append(L, G->p[u]);
			getPath(L, G, G->p[u]);
		}
	}
}

/*** Manipulation procedures ***/

void makeNull(Graph G) {
	if(G == NULL){
		printf("Graph Error: calling makeNULL() on NULL Graph reference\n");
		exit(EXIT_FAILURE);
	}
	for (int i = 1; i <= getOrder(G); i++){
		clear(G->adj[i]);
	}
}

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
			while (j <= i) {
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
					insertAfter(G->adj[u], v);
					break;
				}
			}
		}
	}
}

void BFS(Graph G, int s) {
	bfs_source = s;
	for(int i = 1; i <= getOrder(G); i++) {
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
		for(int y = 1; y <= getOrder(G); y++) {
			if(G->color[y] == WHITE) {
				G->color[y] = GRAY;
				G->d[y] = G->d[x] + 1;
				G->p[y] = x;
				append(L,y);
			}
		}
		G->color[x] = BLACK;
	}
	freeList(&L);
	bfs_on = true;
}

/*** Other operations ***/

void printGraph(FILE* out, Graph G) {
	if(G == NULL){
		printf("Graph Error: calling printGraph() on NULL Graph reference\n");
		exit(EXIT_FAILURE);
	}
	for(int i = 1; i <= getOrder(G); i++){
		fprintf(out, "%d: ", i);
		for(int j = 1; j <= length(G->adj[i]); j++) {
			printList(out, G->adj[j]);
		}
	}
}
