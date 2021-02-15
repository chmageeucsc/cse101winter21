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
	/*insert(D, "a", 9);
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
	insert(D, "z", 1);*/
	
	int i, n=26;
   Dictionary A = newDictionary(0);
   Dictionary B = newDictionary(1);
   char* word[] = { "n","z","w","k","i","c","l","d","t","a", 
                    "e","y","b","h","v","f","s","m","x","r",
                    "o","u","p","g","j","q" };
   VAL_TYPE x;
   VAL_TYPE y;

   // add pairs to A --------------------------------------
   for(i=0; i<n; i++){
      insert(A, word[i], i);
   }

   // add pairs to B
   for(i=n-1; i>=0; i--){
      insert(B, word[i], i);
   }


   // forward iteration over A ----------------------------
   printf("forward A:\n");
   for(x=beginForward(A); currentVal(A)!=VAL_UNDEF; x=next(A)){
      printf("key: "KEY_FORMAT" value: "VAL_FORMAT"\n", currentKey(A), x);
   }
   printf("\n\n");

   // reverse iteratation over B 
   printf("reverse B:\n");
   for(y=beginReverse(B); currentVal(B)!=VAL_UNDEF; y=prev(B)){
      printf("key: "KEY_FORMAT" value: "VAL_FORMAT"\n", currentKey(B), y);
   }
   printf("\n\n");
   
   freeDictionary(&A);
   freeDictionary(&B);
	return(0);
}
