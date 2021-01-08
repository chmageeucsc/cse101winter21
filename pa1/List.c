//-----------------------------------------------------------------------------
// List.c
// Implementation file for List
//
// Chantel Gee
// chmagee
// 
//-----------------------------------------------------------------------------

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// structs --------------------------------------------------------------------

// private NodeObj type
typedef struct NodeObj {
	int data;
	struct NodeObj* next;
} NodeObj;

// private Node type
typedef NodeObj* Node;

// private ListObj type
typedef struct ListObj {
	Node front;
	Node back;
	int length;
	int index;
} ListObj;

// Constructors-Destructors ---------------------------------------------------

Node newNode(int data){
	Node N = malloc(sizeof(NodeObj));
	N->data = data;
	N->next = NULL;
	return(N);
}

void freeNode(Node* pN){
	if( pN!=NULL && *pN!=NULL ){
		free(*pN);
		*pN = NULL;
	}
}

List newList(void) {
	List L = malloc(sizeof(ListObj));
	L->front = L->back = NULL;
	L->length = 0;
	L->index = 0;
	return(L);
}

void freeList(List* pL) {
	if(pL != NULL && *pL != NULL) { 
		while(!isEmpty(*pL)) { 
			Node N = NULL;
			N = *pL->front;
			if(length(*pL) > 1) {
				*pL->front = *pL->front->next;
			}
			else {
				*pL->front = *pL->back = NULL;
			}
			*pL->length--;
			freeNode(&N);
		}
	free(*pL);
	*pL = NULL;
	}
}


// Access functions -----------------------------------------------------------
int length(List L) {
	if(L == NULL){
		printf("List Error: calling length() on NULL List reference\n");
		exit(EXIT_FAILURE);
	}
	return(L->length);
}

int index(List L) {
	if(L == NULL){
		printf("List Error: calling index() on NULL List reference\n");
		exit(EXIT_FAILURE);
	}
	return(L->index);
}

int front(List L) {
	if( L==NULL ){
		printf("List Error: calling front() on NULL List reference\n");
		exit(EXIT_FAILURE);
	}
	if( L->length == 0 ){
		printf("List Error: calling front() on an empty List\n");
		exit(EXIT_FAILURE);
	}
	return(L->front->data);
}

int back(List L) {
	if( L==NULL ){
		printf("List Error: calling front() on NULL List reference\n");
		exit(EXIT_FAILURE);
	}
	if( L->length == 0 ){
		printf("List Error: calling front() on an empty List\n");
		exit(EXIT_FAILURE);
	}
	return(L->back->data);
}

int get(List L) {
	
}

int equals(List A, List B) {
	int eq = 0;
	Node N = NULL;
	Node M = NULL;

	if(A == NULL || B == NULL){
		printf("List Error: calling equals() on NULL List reference\n");
		exit(EXIT_FAILURE);
	}

	eq = (A->length == B->length);
	N = A->front;
	M = B->front;
	while(eq && N != NULL){
		eq = (N->data == M->data);
		N = N->next;
		M = M->next;
	}
	return eq;
}

// Manipulation procedures ----------------------------------------------------
void clear(List L) {
	
}

void set(List L, int x) {
	
}

void moveFront(List L) {
	
}

void moveBack(List L) {
	
}

void movePrev(List L) {
	
}

void moveNext(List L) {
	
}

void prepend(List L, int x) {
	
}

// Other operations -----------------------------------------------------------
void printList(FILE* out, List L) {
	
}

List copyList(List L) {
	
}

List concatList(List A, List B){
	
}
