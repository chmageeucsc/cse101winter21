//-----------------------------------------------------------------------------
//
// Chantel Gee, chmagee
// 2021 Winter CSE 101 pa7 (used from pa1)
// 
// ListTest.c
// Test file for List
// 
//-----------------------------------------------------------------------------

#include <stdlib.h>
#include <stdio.h>
#include "List.h"

int main() {
	List A = newList();
	prepend(A, 5);
	prepend(A, 65);
	prepend(A, 43);
	moveBack(A);
	delete(A);
	if (index(A) != -1) {printf("index should be -1\n");}
	prepend(A, 2);
	prepend(A, 8);
	prepend(A, 1);
	moveBack(A);
	if (index(A) != 4) {printf("index should be 4\n");}
	delete(A);
	moveBack(A);
	if (index(A) != 3) {printf("index should be 3\n");}
	moveFront(A);
	delete(A);
	moveFront(A);
	if (index(A) != 0) {printf("index should be 0\n");}
	delete(A);
	if (index(A) != -1) {printf("index should be -1\n");}
	else {printf("winner !\n");}
	
	//printf("length: %d\n", length(A));
	//printf("prepend 99\n");
	//prepend(A, 99);
	//printf("length: %d\n", length(A));
	//printf("front: %d\n", front(A));
	//printf("back: %d\n", back(A));
	//printf("prepend 101\n");
	//prepend(A, 101);
	//printf("length: %d\n", length(A));
	//printf("front: %d\n", front(A));
	//printf("back: %d\n", back(A));
	//printf("append 42\n");
	//append(A, 42);
	//printf("length: %d\n", length(A));
	//printf("front: %d\n", front(A));
	//printf("back: %d\n", back(A));
	//printf("append 17\n");
	//append(A, 17);
	//printf("length: %d\n", length(A));
	//printf("front: %d\n", front(A));
	//printf("back: %d\n", back(A));
	
	/*List B = copyList(A);
	List C = concatList(A,B);
	
	if(equals(A,B) == 1) {
		printf("equal !!\n");
	}
	else {
		printf("not equal\n");
	}
	
	List B = newList();
	B = copyList(A);
	prepend(B, 99);
	append(B, 42);
	append(B, 16);
	
	if(equals(A,B) == 1) {
		printf("equal !!\n");
	}
	else {
		printf("not equal\n");
	}
	
	//deleteFront(A);
	//printf("deleted front\n");
	//deleteBack(A);
	//printf("deleted back\n");
	
	//moveFront(A);
	
	moveFront(A);
	moveNext(A);
	insertBefore(A,111);
	//moveBack(A);
	insertAfter(A,222);
	moveNext(A);
	delete(A);
	
	moveFront(A);
	while(index(A) >= 0){
		int x = get(A);
		printf("number: %d\n", x);
		moveNext(A);
	}
	
	FILE *out;
	out = fopen("file.txt", "w+");
	printList(out, A);
	
	fclose(out);*/
	
	freeList(&A);
	//freeList(&B);
	//freeList(&C);
	return 0;
}
