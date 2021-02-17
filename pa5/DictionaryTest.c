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
	insert(A, "d", 1);
	insert(A, "b", 5);
	insert(A, "a", 10);
	insert(A, "c", 15);
	insert(A, "f", 20);
	insert(A, "e", 25);
	insert(A, "g", 30);
	beginForward(A);
	delete(A, "a");
	if (currentKey(A) != KEY_UNDEF || currentVal(A) != VAL_UNDEF ){
		printf("key should be undef, val should be undef\n");
	}
	beginReverse(A);
	printf("delete 'd'\n");
	delete(A, "d");
	printf("deleted 'd'\n");
	if (strcmp(currentKey(A), "g") != 0 || currentVal(A) != 30) {
		printf("key should be g, val should be 30\n");
	}
	freeDictionary(&A);
   return(0);
}
