//-----------------------------------------------------------------------------
//
// Chantel Gee, chmagee
// 2021 Winter CSE 101 (updated from pa2)
// 
// Graph.h
// Header file for Graph
// 
//-----------------------------------------------------------------------------

#ifndef __GRAPH_H_INCLUDE_
#define __GRAPH_H_INCLUDE_

#include <stdlib.h>
#include <stdio.h>
#include "List.h"

#define UNDEF -1
#define NIL 0
#define WHITE 1
#define GRAY 2
#define BLACK 3

// extras ---------------------------------------------------------------------

typedef struct GraphObj* Graph;

/*** Constructors-Destructors ***/

Graph newGraph(int n);

void freeGraph(Graph* pG);

/*** Access functions ***/

int getOrder(Graph G);

int getSize(Graph G);

// pre: 1 <= u <= getOrder(G)
int getParent(Graph G, int u);

// pre: 1 <= u <= getOrder(G)
int getDiscover(Graph G, int u);

// pre: 1 <= u <= getOrder(G)
int getFinish(Graph G, int u);

/*** Manipulation procedures ***/

// pre: 1 <= u <= getOrder(G) and 1 <= v <= getOrder(G)
void addEdge(Graph G, int u, int v);

// pre: 1 <= u <= getOrder(G) and 1 <= v <= getOrder(G)
void addArc(Graph G, int u, int v);

// pre: length(S) == getOrder(G)
void DFS(Graph G, List s);

/*** Other operations ***/

Graph transpose(Graph G);

Graph copyGraph(Graph G);

void printGraph(FILE* out, Graph G);

#endif
