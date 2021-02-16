//-----------------------------------------------------------------------------
// DictionaryClient.c
// Test client for Dictionary ADT
//-----------------------------------------------------------------------------
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"Dictionary.h"

int main(){
	
	Dictionary A = newDictionary(0);
	/*insert(A, "a", 1);
	insert(A, "b", 5);
	insert(A, "c", 16);
	insert(A, "d", 176);
	insert(A, "e", 3214);
	beginForward(A);
	next(A);
	next(A);
	if (strcmp(currentKey(A), "c") != 0 || currentVal(A) != 16) {
		printf("key is c, val is 16");
	}
	next(A);
	next(A);
	next(A);
	if (currentKey(A) != KEY_UNDEF || currentVal(A) != VAL_UNDEF) {
		printf("key is undef, val is undef\n");
	}
	printf("key %s\n", currentKey(A));
	printf("val %d\n", currentVal(A));
	
	insert(A, "a", 1);
	insert(A, "b", 5);
	insert(A, "e", 3214);
	beginReverse(A);
	prev(A);
	if (strcmp(currentKey(A), "b") != 0 || currentVal(A) != 5) {
		printf("key is b, val is 5\n");
	}
	printf("key %s\n", currentKey(A));
	printf("val %d\n", currentVal(A));
	prev(A);
	prev(A);
	if (currentKey(A) != KEY_UNDEF || currentVal(A) != VAL_UNDEF) {
		printf("key is undef, val is undef\n");
	}
	printf("key %s\n", currentKey(A));
	printf("val %d\n", currentVal(A));*/
	insert(A, "c", 3);
	insert(A, "b", 2);
	insert(A, "a", 1);
	beginForward(A);
	makeEmpty(A);
	if (currentKey(A) != KEY_UNDEF || currentVal(A) != VAL_UNDEF || size(A) != 0) {
		printf("key is undef, val is undef, size is 0\n");
		printf("size %d\n", size(A));
		printf("key %s\n", currentKey(A));
		printf("val %d\n", currentVal(A));
	}
	/*insert(A, "d", 1);
	insert(A, "b", 5);
	insert(A, "a", 10);
	insert(A, "c", 15);
	insert(A, "f", 20);
	insert(A, "e", 25);
	insert(A, "g", 30);
	beginForward(A);
	printf("key %s\n", currentKey(A));
	printf("val %d\n", currentVal(A));
	delete(A, "a");
	if (currentKey(A) != KEY_UNDEF || currentVal(A) != VAL_UNDEF) {
		printf("key is undef, val is undef\n");
		printf("key %s\n", currentKey(A));
		printf("val %d\n", currentVal(A));
	}
	beginReverse(A);
	delete(A, "d");
	if (strcmp(currentKey(A), "g") != 0 || currentVal(A) != 30) {
		printf("key is g, val is 30\n");
		printf("key %s\n", currentKey(A));
		printf("val %d\n", currentVal(A));
	}*/
	freeDictionary(&A);
   return(0);
}
