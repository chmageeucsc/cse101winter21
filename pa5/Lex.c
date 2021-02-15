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
	insert(D, "a", 9);
	insert(D, "b", 12);
	insert(D, "c", 5);
	insert(D, "d", 7);
	insert(D, "e", 10);
	insert(D, "f", 15);
	insert(D, "g", 23);
	insert(D, "h", 13);
	insert(D, "i", 4);
	insert(D, "j", 24);
	insert(D, "k", 3);
	insert(D, "l", 6);
	insert(D, "m", 17);
	insert(D, "n", 0);
	insert(D, "o", 20);
	insert(D, "p", 22);
	insert(D, "q", 25);
	insert(D, "r", 19);
	insert(D, "s", 16);
	insert(D, "t", 8);
	insert(D, "u", 21);
	insert(D, "v", 14);
	insert(D, "w", 2);
	insert(D, "x", 18);
	insert(D, "y", 11);
	insert(D, "z", 1);
	freeDictionary(&D);
	return(0);
}
