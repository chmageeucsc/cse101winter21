//-----------------------------------------------------------------------------
//
// Chantel Gee, chmagee
// 2021 Winter CSE 101 pa6 
// 
// DictionaryTest.c
// Tester file for Dictionary
// 
//-----------------------------------------------------------------------------

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include "Dictionary.h"
#define VAL_UNDEF NULL

int main () {
	int n = 10;
	int a = 1, b = 2, c = 3, d = 4, e = 5;
	Dictionary A = newDictionary(0);
	if (getUnique(A) == 1) {
		printf("A is non-unique\n");
	}

	insert(A, "a", &a);
	insert(A, "b", &b);
	insert(A, "c", &c);
	insert(A, "d", &d);
	insert(A, "e", &e);
	
	printf("size of A = %d\n", size(A));
	printf("\n");
	
	beginForward(A);
	printf("currentKey(A) = %s\n", currentKey(A));
	printf("currentVal(A) = %d\n", *currentVal(A));
	next(A);
	printf("currentKey(A) = %s\n", currentKey(A));
	printf("currentVal(A) = %d\n", *currentVal(A));
	if (lookup(A, "a") != VAL_UNDEF) {
		printf("\ndelete a\n\n");
		delete(A, "a");
	}
	printf("size of A = %d\n", size(A));
	
	printf("\n");
	Dictionary B = newDictionary(1);
	if (getUnique(B) == 0) {
		printf("B is unique\n");
	}
	insert(B, "a", &n);
	insert(B, "b", &n);
	insert(B, "c", &n);
	insert(B, "d", &n);
	insert(B, "e", &n);
	
	printf("size of B = %d\n", size(B));
	printf("\n");
	beginReverse(B);
	printf("currentKey(B) = %s\n", currentKey(B));
	printf("currentVal(B) = %d\n", *currentVal(B));
	prev(B);
	printf("currentKey(B) = %s\n", currentKey(B));
	printf("currentVal(B) = %d\n", *currentVal(B));
	
	makeEmpty(B);
	printf("size of B = %d\n", size(B));
	
	printf("\nPRE: A\n");
	printDictionary(stdout, A, "pre");
	printf("\n\nIN: A\n");
	printDictionary(stdout, A, "in");
	printf("\n\nPOST: A\n");
	printDictionary(stdout, A, "post");
	printf("\n\nPRE: B\n\n");
	printDictionary(stdout, B, "pre");
	printf("IN: B\n\n");
	printDictionary(stdout, B, "in");
	printf("POST: B\n\n");
	printDictionary(stdout, B, "post");
	printf("\n");
	 
	freeDictionary(&B);
	freeDictionary(&A);
	
	return 0;
}
