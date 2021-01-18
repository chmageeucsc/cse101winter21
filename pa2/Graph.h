//-----------------------------------------------------------------------------
//
// Chantel Gee, chmagee
// 2021 Winter CSE 101 pa2
// 
// Graph.h
// Header file for Graph
// 
//-----------------------------------------------------------------------------

#ifndef __GRAPH_H_INCLUDE_
#define __GRAPH_H_INCLUDE_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "List.h"

#define INF -1
#define NIL 0
#define WHITE 1
#define GRAY 2
#define BLACK 3

// extras ---------------------------------------------------------------------

extern int bfs_source;
extern bool bfs_on;

typedef struct GraphObj* Graph;

/*** Constructors-Destructors ***/

Graph newGraph(int n);

void freeGraph(Graph* pG);

/*** Access functions ***/

int getOrder(Graph G);

int getSize(Graph G);

int getSource(Graph G);

// pre: 1 <= u <= getOrder(G)
int getParent(Graph G, int u);

// pre: 1 <= u <= getOrder(G)
int getDist(Graph G, int u);

// pre: 1 <= u <= getOrder(G)
void getPath(List L, Graph G, int u);

/*** Manipulation procedures ***/

void makeNull(Graph G);

void addEdge(Graph G, int u, int v);

void addArc(Graph G, int u, int v);

void BFS(Graph G, int s);

/*** Other operations ***/

void printGraph(FILE* out, Graph G);

#endif
