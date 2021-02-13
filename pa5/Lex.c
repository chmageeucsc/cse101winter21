//-----------------------------------------------------------------------------
//
// Chantel Gee, chmagee
// 2021 Winter CSE 101 pa5
// 
// Lex.c
// Implementation file for Lex
// 
//-----------------------------------------------------------------------------

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "Dictionary.h"

#define KEY_TYPE char*
#define VAL_TYPE int
#define KEY_UNDEF NULL
#define VAL_UNDEF -1
#define KEY_FORMAT "%s"
#define VAL_FORMAT "%d"
#define KEY_CMP(x,y) strcmp((x),(y))

//-----------------------------------------------------------------------------

int main(){	
	Dictionary D = newDictionary(1);
	insert(D,"A", 1);
	insert(D, "BROSKI", 97);
	insert(D, "B", 9);
	freeDictionary(&D);
	return(0);
}
