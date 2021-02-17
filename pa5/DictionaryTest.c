//-----------------------------------------------------------------------------
//
// Chantel Gee, chmagee
// 2021 Winter CSE 101 pa5
// 
// DictionaryTest.c
// Test file for Dictionary
// 
//-----------------------------------------------------------------------------
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"Dictionary.h"

int main(){
	
	Dictionary A = newDictionary(0);
	Dictionary B = newDictionary(1);

	insert(A, "d", 10);
	insert(A, "b", 9);
	insert(A, "c", 8);
	insert(A, "a", 7);
	insert(A, "h", 6);
	insert(A, "f", 5);
	insert(A, "g", 4);
	insert(A, "e", 3);
	insert(A, "i", 2);

	insert(B, "d", 1);
	insert(B, "b", 2);
	insert(B, "c", 3);
	insert(B, "a", 4);
	insert(B, "h", 5);
	insert(B, "f", 6);
	insert(B, "g", 7);
	insert(B, "e", 8);
	insert(B, "i", 9);

	printDictionary(stdout, A);
	printDictionary(stdout, B);

	printf("size of A = %d, is A unique? = %d\n", size(A), getUnique(A));
	printf("size of B = %d, is B unique? = %d\n", size(B), getUnique(B));

	beginForward(A);
	next(A);
	next(A);
	next(A);
	prev(A);
	if (lookup(A, "c") != -1) {
		printf("key 'c' exists\n");
	}
	printf("current key = %s, current value = %d\n", currentKey(A), currentVal(A));
	delete(A, "c");
	if (lookup(A, "c") == -1) {
		printf("key 'c' deleted\n");
	}

	printf("cursor deleted\n");
	printf("current key = %s, current value = %d\n", currentKey(A), currentVal(A));

	printDictionary(stdout, A);

	beginReverse(B);
	prev(B);
	prev(B);
	prev(B);
	next(B);
	if (lookup(B, "g") != -1) {
		printf("key 'g' exists\n");
	}
	printf("current key = %s, current value = %d\n", currentKey(B), currentVal(B));
	delete(B, "g");
	if (lookup(B, "g") == -1) {
		printf("key 'g' deleted\n");
	}
	printf("cursor deleted\n");
	printf("current key = %s, current value = %d\n", currentKey(B), currentVal(B));

	printDictionary(stdout, B);

	printf("make Dictionaries empty\n");
	makeEmpty(A);
	makeEmpty(B);

	printDictionary(stdout, A);
	printDictionary(stdout, B);

	printf("size of A = %d\n", size(A));
	printf("size of B = %d\n", size(B));

	freeDictionary(&A);
	freeDictionary(&B);
   return(0);
}
