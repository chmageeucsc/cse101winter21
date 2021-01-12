#include "List.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// NOTE TO SELF: FIX CURSOR AND INDEX STUFF FOR LIST.C (APPEND, PREPEND, INSERTBEFORE, INSERTAFTER)

int main() {
	List A = newList();
	//printf("length: %d\n", length(A));
	//printf("prepend 99\n");
	prepend(A, 99);
	//printf("length: %d\n", length(A));
	//printf("front: %d\n", front(A));
	//printf("back: %d\n", back(A));
	//printf("prepend 101\n");
	prepend(A, 101);
	//printf("length: %d\n", length(A));
	//printf("front: %d\n", front(A));
	//printf("back: %d\n", back(A));
	//printf("append 42\n");
	append(A, 42);
	//printf("length: %d\n", length(A));
	//printf("front: %d\n", front(A));
	//printf("back: %d\n", back(A));
	//printf("append 17\n");
	append(A, 17);
	//printf("length: %d\n", length(A));
	//printf("front: %d\n", front(A));
	//printf("back: %d\n", back(A));
	
	List B = copyList(A);
	List C = concatList(A,B);
	
	if(equals(A,B) == 1) {
		printf("equal !!\n");
	}
	else {
		printf("not equal\n");
	}
	
	/*List B = newList();
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
	delete(A);*/
	
	moveFront(C);
	while(index(C) >= 0){
		//if(index(A) == 1) { 
		//	set(A, 100); 
		//}
		int x = get(C);
		printf("number: %d\n", x);
		moveNext(C);
	}
	
	FILE *out;
	out = fopen("file.txt", "w+");
	printList(out, A);
	
	fclose(out);
	
	freeList(&A);
	freeList(&B);
	freeList(&C);
	return 0;
}
