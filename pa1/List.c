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
#include "List.h"

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

// Constructors-Destructors ---------------------------------------------------

Node newNode(int data){
	Node N = malloc(sizeof(NodeObj));
	N->data = data;
	N->next = NULL;
	N->prev = NULL;
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
	L->cursor = NULL;
	L->length = 0;
	L->index = 0;
	return(L);
}

void freeList(List* pL) {
	if(pL != NULL && *pL != NULL) { 
		clear(*pL);
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
	if (L->cursor != NULL) {
		return L->index;
	}
	else {
		return -1;
	}
}

// pre: length() > 0
int front(List L) {
	if(L == NULL) {
		printf("List Error: calling front() on NULL List reference\n");
		exit(EXIT_FAILURE);
	}
	if(L->length <= 0) {
		printf("List Error: calling front() on an empty List\n");
		exit(EXIT_FAILURE);
	}
	return(L->front->data);
}

// pre: length() > 0
int back(List L) {
	if(L == NULL){
		printf("List Error: calling back() on NULL List reference\n");
		exit(EXIT_FAILURE);
	}
	if(L->length <= 0){
		printf("List Error: calling back() on an empty List\n");
		exit(EXIT_FAILURE);
	}
	return(L->back->data);
}

// pre: length() > 0 and index() >= 0
int get(List L) {
	if(L == NULL){
		printf("List Error: calling get() on NULL List reference\n");
		exit(EXIT_FAILURE);
	}
	if(L->length <= 0){
		printf("List Error: calling get() on an empty List\n");
		exit(EXIT_FAILURE);
	}
	if(L->index < 0) {
		printf("List Error: calling get() on an undefined index\n");
		exit(EXIT_FAILURE);
	}
	
	return L->cursor->data;
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
	if(L == NULL){
		printf("List Error: calling clear() on NULL List reference\n");
		exit(EXIT_FAILURE);
	}
	while(L->front != NULL) { 
		deleteFront(L);
	}
	L->cursor = NULL;
}

// pre: length() > 0 and index() >= 0
void set(List L, int x) {
	if(L == NULL){
		printf("List Error: calling get() on NULL List reference\n");
		exit(EXIT_FAILURE);
	}
	if(L->length <= 0){
		printf("List Error: calling get() on an empty List\n");
		exit(EXIT_FAILURE);
	}
	if(L->index < 0) {
		printf("List Error: calling get() on an undefined index\n");
		exit(EXIT_FAILURE);
	}
	
	L->cursor->data = x;
}

void moveFront(List L) {
	if (length(L) >= 0) {
		L->cursor = L->front;
		L->index = 0;
	}
}

void moveBack(List L) {
	if (length(L) >= 0) {
		L->cursor = L->back;
		L->index = length(L)-1;
	}
}

void movePrev(List L) {
	if (L->cursor != NULL && L->cursor == L->front) {
		L->cursor = NULL;
	}
	else if(L->cursor != NULL && L->cursor != L->front) {
		L->cursor = L->cursor->prev;
		L->index--;
	}
}

void moveNext(List L) {
	if (L->cursor != NULL && L->cursor == L->back) {
		L->cursor = NULL;
	}
	else if(L->cursor != NULL && L->cursor != L->back) {
		L->cursor = L->cursor->next;
		L->index++;
	}
}

void prepend(List L, int x) {
	Node temp = newNode(x);
	if (L->front == NULL) {
		L->front = temp;
		L->back = temp;
		temp->next = NULL;
		L->length++;
	}
	else {
		L->front->prev = temp;
		L->front->next = L->front;
		L->front = temp;
		L->length++;
	}
}

void append(List L, int x) {
	Node temp = newNode(x);
	if (L->front == NULL) {
		L->front = temp;
		L->back = temp;		
		temp->next = NULL;
		L->length++;
	}
	else {
		L->back->next = temp;
		L->back->prev = L->back;
		L->back = temp;
		L->length++;
	}
}

// pre: length() > 0 and index() >= 0
void insertBefore(List L, int x) {
	if(L == NULL){
		printf("List Error: calling insertBefore() on NULL List reference\n");
		exit(EXIT_FAILURE);
	}
	if(L->length <= 0){
		printf("List Error: calling insertBefore() on an empty List\n");
		exit(EXIT_FAILURE);
	}
	if(L->index < 0) {
		printf("List Error: calling insertBefore() on an undefined index\n");
		exit(EXIT_FAILURE);
	}
	
	Node temp = newNode(x);
	L->cursor->prev = temp;
	temp->next = L->cursor;
	L->length++;
}

// pre: length() > 0 and index() >= 0
void insertAfter(List L, int x) {
	if(L == NULL){
		printf("List Error: calling insertAfter() on NULL List reference\n");
		exit(EXIT_FAILURE);
	}
	if(L->length <= 0){
		printf("List Error: calling insertAfter() on an empty List\n");
		exit(EXIT_FAILURE);
	}
	if(L->index < 0) {
		printf("List Error: calling insertAfter() on an undefined index\n");
		exit(EXIT_FAILURE);
	}
	
	Node temp = newNode(x);
	L->cursor->next = temp;
	temp->prev = L->cursor;
	L->length++;
}

// pre: length() > 0
void deleteFront(List L) {
	if(L == NULL){
		printf("List Error: calling deleteFront() on NULL List reference\n");
		exit(EXIT_FAILURE);
	}
	if(L->length <= 0){
		printf("List Error: calling deleteFront() on an empty List\n");
		exit(EXIT_FAILURE);
	}
	
	Node temp = L->front;
	if(length(L) > 1) {
		if(L->front != NULL) {
			printf("front not null\n");
			if(L->front->next != NULL) {
				printf("front next not null\n");
				L->front = L->front->next;
				printf("front is front next\n");
			}
			if(L->front != NULL) {
				printf("front not null\n");
				L->front->prev = NULL;
				printf("front prev null\n");
			}
		}
	}
	else {
		L->front = L->back = L->cursor = NULL;
	}
	freeNode(&temp);
	L->length--;
}

// pre: length() > 0
void deleteBack(List L) {
	if(L == NULL){
		printf("List Error: calling deleteBack() on NULL List reference\n");
		exit(EXIT_FAILURE);
	}
	if(L->length <= 0){
		printf("List Error: calling deleteBack() on an empty List\n");
		exit(EXIT_FAILURE);
	}
	
	Node temp = L->back;
	if(length(L) > 1) {
		if (L->back != NULL) {
			printf("back not null\n");
			if (L->back->prev != NULL) {
				printf("back prev not null\n");
				L->back = L->back->prev;
				printf("back is back prev\n");
			}
			if (L->back != NULL) {
				printf("back not null\n");
				L->back->next = NULL;
				printf("back next null\n");
			}
		}
	}
	else {
		L->front = L->back = L->cursor = NULL;
	}
	freeNode(&temp);
	L->length--;
}

// pre: length() > 0 and index() >= 0
void delete(List L) {
	if(L == NULL){
		printf("List Error: calling delete() on NULL List reference\n");
		exit(EXIT_FAILURE);
	}
	if(L->length <= 0){
		printf("List Error: calling delete() on an empty List\n");
		exit(EXIT_FAILURE);
	}
	if(L->index < 0) {
		printf("List Error: calling delete() on an undefined index\n");
		exit(EXIT_FAILURE);
	}
	
	Node temp = L->cursor;
	L->cursor->prev->next = L->cursor->next;
	free(temp);
	L->length--;
}

// Other operations -----------------------------------------------------------
void printList(FILE* out, List L) {
	if(L == NULL){
		printf("List Error: calling printList() on NULL List reference\n");
		exit(EXIT_FAILURE);
	}
	out = fopen("file.txt", "w+");
	Node temp = L->front;
	if(temp != NULL) {
		fprintf(out, "%d", temp->data);		// fix to print strings later
		temp = temp->next;
		if(temp != NULL) {
			fprintf(out, " ");
		}
	}
}

List copyList(List L) {
	List copy = L;
	copy->cursor = NULL;
	copy->index = 0;
	return copy;
}

List concatList(List A, List B){
	List C = A;
	List D = B;
	C->back->next = D->front;
	C->cursor = NULL;
	C->index = 0;
	return C;
}
