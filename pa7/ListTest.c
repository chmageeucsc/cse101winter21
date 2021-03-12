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
	prepend(A, 456);
	append(A, 123);
	prepend(A, 890);
	append(A, 777);
	
	List B = copyList(A);
	if (listEquals(A,B) == 1) {
		printf("List A == List B\n");
		printf("List A = ");
		printList(stdout, A);
		printf("\n");
		printf("List B (copy A) = ");
		printList(stdout, B);
		printf("\n\n");
	}
	
	moveFront(A);
	insertBefore(A, 9009);
	insertAfter(A, 404);
	
	printf("added 9009 and 404 to A\n");
	
	printf("List A = ");
	printList(stdout, A);
	printf("\n\n");
	
	moveBack(B);
	insertBefore(B, 365);
	insertAfter(B, 129);
	
	printf("added 365 and 129 to B\n");
	
	printf("List B = ");
	printList(stdout, B);
	printf("\n\n");
	
	printf("front of A = %ld\n", front(A));
	printf("back of A = %ld\n", back(A));
	printf("front of B = %ld\n", front(B));
	printf("back of B = %ld\n\n", back(B));
	
	deleteFront(B);
	deleteBack(A);
	
	printf("deleted back of A and front of B\n");
	printf("List A = ");
	printList(stdout, A);
	printf("\n");
	printf("List B = ");
	printList(stdout, B);
	printf("\n\n");
	
	List C = concatList(A,B);
	printf("List C (concat of A&B) = ");
	printList(stdout, C);
	printf("\n");
	printf("length of A = %ld\n", length(A));
	printf("length of B = %ld\n", length(B));
	printf("length of C (A&B) = %ld\n\n", length(C));
	
	printf("print C in order\n");
	for(moveFront(C); index(C) != -1; moveNext(C)) {
		printf("at index %ld the number is %ld\n", index(C), get(C));
		if (index(C) == 4) {
			printf("\nsetting index 4 to 543\n");
			set(C, 543);
			printf("at index %ld the number is now %ld\n", index(C), get(C));
		}
		if(index(C) == 7) {
			printf("\ndeleting index 7\n");
			delete(C);
			for(moveFront(C); index(C) < 7; moveNext(C)) {}
			printf("at index %ld the number is now %ld\n", index(C), get(C));
		}
	}
	
	printf("\nprint C in reverse order\n");
	for(moveBack(C); index(C) != -1; movePrev(C)) {
		printf("at index %ld the number is %ld\n", index(C), get(C));
	}
	
	printf("\n");
	clear(C);
	printf("clear C\nprint C\n");
	printList(stdout, C);
	printf("\n");
	printf("length of C = %ld\n", length(C));

	freeList(&A);
	freeList(&B);
	freeList(&C);
	return 0;
}
