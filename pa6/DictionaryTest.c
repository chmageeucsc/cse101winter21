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
	int* pI = calloc(10, sizeof(int));
    for (int i=0; i < 10; i++) {
		pI[i]=i+10;
	}
	Dictionary B = newDictionary(0);
	insert(B, "d", &pI[0]);
	insert(B, "d", &pI[1]);
	insert(B, "d", &pI[2]);
	insert(B, "d", &pI[3]);
	insert(B, "d", &pI[4]);
	insert(B, "d", &pI[5]);
	insert(B, "d", &pI[6]);
	insert(B, "d", &pI[7]);
	
	if (*beginReverse(B) != pI[7] && *currentVal(B) != pI[7]) {
		printf("val should be pI[7]\n");
	}
	prev(B);
	prev(B);
	prev(B);
	if (*prev(B) != pI[3] && *currentVal(B) != pI[3]) {
		printf("val should be pI[3]\n");
	}
	
	free(pI);
	freeDictionary(&B);
	
	return 0;
}
