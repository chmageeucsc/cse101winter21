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

int main () {
	int num = 10;
	Dictionary D = newDictionary(1);
	printf("size = %d\n", size(D));
	printf("unique = %d\n", getUnique(D));
	insert(D, "c", &num);
	insert(D, "d", &num);
	insert(D, "a", &num);
	insert(D, "b", &num);
	insert(D, "e", &num);
	
	printDictionary(stdout, D, "pre");
	printf("\n");
	printDictionary(stdout, D, "in");
	printf("\n");
	printDictionary(stdout, D, "post");
	printf("\n");
	
	freeDictionary(&D);
	
	return 0;
}
