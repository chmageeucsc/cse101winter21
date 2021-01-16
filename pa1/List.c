//-----------------------------------------------------------------------------
//
// Chantel Gee, chmagee
// 2021 Winter CSE 101 pa1
// 
// List.c
// Implementation file for List
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
		temp->prev = NULL;
		temp->next = L->front;
		L->front->prev = temp;
		L->front = temp;
		L->length++;
	}
	if (index(L) != -1) {
		L->index++;
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
		temp->next = NULL;
		temp->prev = L->back;
		L->back->next = temp;
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
	if(index(L) == 0) {
		prepend(L,x);
	}
	else {
		Node temp = newNode(x);
		temp->prev = L->cursor->prev;
		L->cursor->prev->next = temp;
		L->cursor->prev = temp;
		temp->next = L->cursor;
		L->length++;
		L->index++;
	}
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
	
	if(index(L) == L->length - 1) {
		append(L,x);
	}
	else {		
		Node temp = newNode(x);
		temp->next = L->cursor->next;
		L->cursor->next->prev = temp;
		L->cursor->next = temp;
		temp->prev = L->cursor;
		L->length++;
	}
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
			if(L->front->next != NULL) {
				L->front = L->front->next;
			}
			if(L->front != NULL) {
				L->front->prev = NULL;
			}
			L->index--;
		}
	}
	else {
		L->front = L->back = L->cursor = NULL;
		L->index = -1;
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
			if(L->cursor != NULL) {
				if(L->cursor == L->back) {
					L->index = -1;
				}
			}
			if (L->back->prev != NULL) {
				L->back = L->back->prev;
			}
			if (L->back != NULL) {
				L->back->next = NULL;
			}
		}
	}
	else {
		L->front = L->back = L->cursor = NULL;
		L->index = -1;
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
	if(L->cursor == L->front) {
		deleteFront(L);
	}
	else if(L->cursor == L->back) {
		deleteBack(L);
	}
	else {
		Node temp = L->cursor;
		L->cursor->prev->next = L->cursor->next;
		free(temp);
		L->length--;
	}
	L->cursor = NULL;
}

// Other operations -----------------------------------------------------------
void printList(FILE* out, List L) {
	if(L == NULL){
		printf("List Error: calling printList() on NULL List reference\n");
		exit(EXIT_FAILURE);
	}
	Node temp = L->front;
	while(temp != NULL) {
		fprintf(out, "%d", temp->data);		// fix to print strings later
		temp = temp->next;
		if(temp != NULL) {
			fprintf(out, " ");
		}
	}
}

List copyList(List L) {	
	List copy = newList();
	Node cursorHold = L->cursor;	// keeps track of L's cursor
	int indexHold = L->index;		// keeps track of L's index
	moveFront(L);
	while(L->cursor != NULL) {
		append(copy, L->cursor->data);
		moveNext(L);
	}
	L->cursor = cursorHold;
	L->index = indexHold;
	copy->cursor = NULL;
	copy->index = 0;
	return copy;
}

List concatList(List A, List B) {
	List C = copyList(A);
	Node cursorHold = B->cursor;	// keeps track of L's cursor
	int indexHold = B->index;		// keeps track of L's index
	moveFront(B);
	while(B->cursor != NULL) {
		append(C, B->cursor->data);
		moveNext(B);
	}
	B->cursor = cursorHold;
	B->index = indexHold;
	C->cursor = NULL;
	C->index = 0;
	return C;
}
