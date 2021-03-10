//-----------------------------------------------------------------------------
//
// Chantel Gee, chmagee
// 2021 Winter CSE 101 pa7 
// 
// BigInteger.c
// Implementation file for BigInteger
// 
//-----------------------------------------------------------------------------

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "BigInteger.h"
#include "List.h"

#define BASE 1000000000
#define POWER 9

//#define BASE 100
//#define POWER 2

// structs --------------------------------------------------------------------

// private BigInteger type
typedef struct BigIntegerObj{
	int sign;
	List magnitude;
} BigIntegerObj;

// Constructors-Destructors ---------------------------------------------------

// newBigInteger()
// Returns a reference to a new BigInteger object in the zero state.
BigInteger newBigInteger() {
	BigInteger N = malloc(sizeof(BigIntegerObj));
	N->sign = 0;
	N->magnitude = newList();
	return N;
}

// freeBigInteger()
// Frees heap memory associated with *pN, sets *pN to NULL.
void freeBigInteger(BigInteger* pN) {
	if(pN != NULL && *pN != NULL) { 
		freeList(&(*pN)->magnitude);
		free(*pN);
		*pN = NULL;
	}
}

// Access functions -----------------------------------------------------------

// sign()
// Returns -1 if N is negative, 1 if N is positive, and 0 if N is in the zero
// state.
int sign(BigInteger N) {
	return N->sign;
}

// compare()
// Returns -1 if A<B, 1 if A>B, and 0 if A=B.
int compare(BigInteger A, BigInteger B) {
	if (equals(A, B) == 1) {
		return 0;
	}
	else if ((A->sign < B->sign) || (length(A->magnitude) < length(B->magnitude))) {
		return -1;
	}
	else if ((A->sign > B->sign) || (length(A->magnitude) > length(B->magnitude))) {
		return 1;
	}
	else if (A->sign == 1 && B->sign == 1) {
		moveFront(A->magnitude);
		moveFront(B->magnitude);
		for (int i = 0; i < length(A->magnitude); i++) {
			if (get(A->magnitude) < get(B->magnitude)) {
				return -1;
			}
			else if (get(A->magnitude) > get(B->magnitude)) {
				return 1;
			}
			else {
				moveNext(A->magnitude);
				moveNext(B->magnitude);
			}
		}
	}
	return 0;
}

// equals()
// Return true (1) if A and B are equal, false (0) otherwise.
int equals(BigInteger A, BigInteger B) {
	if (A->sign == B->sign) {
		if (listEquals(A->magnitude, B->magnitude) == 1) {
			return 1;
		}
	}
	return 0;
}

// Manipulation procedures ----------------------------------------------------

// makeZero()
// Re-sets N to the zero state.
void makeZero(BigInteger N) {
	clear(N->magnitude);
	N->sign = 0;
}

// negate()
// Reverses the sign of N: positive <--> negative. Does nothing if N is in the
// zero state.
void negate(BigInteger N) {
	if (N->sign == -1) {
		N->sign = 1;
	}
	else if (N->sign == 1) {
		N->sign = -1;
	}
}

// BigInteger Arithmetic operations -----------------------------------------------

// stringToBigInteger()
// Returns a reference to a new BigInteger object representing the decimal integer
// represented in base 10 by the string s.
// Pre: s is a non-empty string containing only base ten digits {0,1,2,3,4,5,6,7,8,9}
// and an optional sign {+, -} prefix.
BigInteger stringToBigInteger(char* s) {
	int slen, end = 0, j = 0;
	char str [POWER] = "000000000";
	for(slen = 0; s[slen] != '\0'; ++slen);
	BigInteger S = newBigInteger();
	S->sign = 1;
	if (s[0] != '\0') {
		if (s[0] == '+') {
			end = 1;
		}
		else if (s[0] == '-') {
			S->sign = -1;
			end = 1;
		}
		for (int i = slen -1; i >= end; i--){
			if( s[i] >= '0' && s[i] <= '9' ){
				str[POWER-1-j] = s[i];
				j++;
				if ((j == POWER) || (i == end)) {
					prepend(S->magnitude, atol(str));
					j = 0;
					for (int x = 0; x < POWER; x++) {
						str[x] = '0';
					}
				}
			}
		}
	}
	if((length(S->magnitude) == 1) && (front(S->magnitude) == 0)) {
		S->sign = 0;
		return S;
	}
	return S;
}

// copy()
// Returns a reference to a new BigInteger object in the same state as N.
BigInteger copy(BigInteger N) {
	BigInteger copy = newBigInteger();
	copy->sign = N->sign;
	free(copy->magnitude);
	copy->magnitude = copyList(N->magnitude);
	return copy;
}

// normalizeList()
// helper function for add, subtract, and multiply
int normalizeList(List L) {
	moveBack(L);
	while(index(L) != 0) {
		if (get(L) > BASE-1) {
			long sub = 0, subCarry = 0;
			subCarry = get(L)/BASE;	// number to add previous node by
			sub = subCarry * BASE; // number to subtract current node by
			set(L, get(L) - sub);
			movePrev(L);
			set(L, get(L) + subCarry);
		}
		else if (get(L) < 0) {
			long ad = 0, adCarry = 0;
			adCarry = get(L)/BASE + 1; // number to subtract previous node by
			ad = adCarry * BASE; // number to add current node by
			set(L, get(L) + ad);
			movePrev(L);
			set(L, get(L) - adCarry);
		}
		else { movePrev(L);}
	}
	if (front(L) > BASE-1) {
		moveFront(L);
		int carry = 0;
		while (front(L) > BASE-1) {
			set(L, get(L) - BASE);
			carry++;
		}
		prepend(L, carry);
		return 1;
	}
	else if (front(L) < 0) {
		moveBack(L);
		while (index(L) != 0) {
			set(L, get(L)*(-1));
			movePrev(L);
		}
		set(L, get(L)*(-1));
		moveBack(L);
		while(index(L) != 0) {
			if (get(L) < 0) {
				long ad = 0, adCarry = 0;
				adCarry = get(L)/BASE + 1;
				ad = adCarry * BASE;
				set(L, get(L) + ad);
				movePrev(L);
				set(L, get(L) - adCarry);
			}
			else { movePrev(L);}
		}
		return -1;
	}
	while (front(L) == 0) {
		deleteFront(L);
	}
	return 1;
}

/*// scalar()
// helper function for mult and add
void scalar(BigInteger temp, BigInteger A, long num) {
	for (moveBack(A->magnitude); index(A->magnitude) != -1; movePrev(A->magnitude)) {
		long ans;
		ans = get(A->magnitude) * num;
		prepend(temp->magnitude, ans);
	}
}*/

// add()
// Places the sum of A and B in the existing BigInteger S, overwriting its
// current state: S = A + B
void add(BigInteger S, BigInteger A, BigInteger B) {
	if (((sign(A) == 1) && (sign(B) == -1)) || ((sign(A) == -1) && (sign(B) == 1))) {
		if (listEquals(A->magnitude, B->magnitude) == 1) {
			makeZero(S);
			prepend(S->magnitude, 0);
			return;
		}
	}
	if ((equals(S, A) != 1) && (equals(S, B) != 1)) {
		if (length(S->magnitude) != 0) {
			makeZero(S);
		}
	}
	int same = 0;
	if ((equals(S, A) == 1) || (equals(S,B) == 1)) {
		same = 1;
	}
	while (length(A->magnitude) < length(B->magnitude)) {
		prepend(A->magnitude, 0);
	}
	while (length(B->magnitude) < length(A->magnitude)) {
		prepend(B->magnitude, 0);
	}
	moveBack(A->magnitude);
	moveBack(B->magnitude);
	while (index(B->magnitude) != -1) {
		long ans;
		if ((sign(A) == 1) && (sign(B) == 1)) {
			ans = get(A->magnitude) + get(B->magnitude);
			//printf("A + B = %ld\n", ans);
		}
		else if ((sign(A) == -1) && (sign(B) == 1)) {
			ans = (get(B->magnitude) - get(A->magnitude));
			//printf("-A + B = %ld\n", ans);
		}
		else if ((sign(A) == 1) && (sign(B) == -1)) {
			ans = get(A->magnitude) - get(B->magnitude);
			//printf("A + -B = %ld\n", ans);
		}
		else if ((sign(A) == -1) && (sign(B) == -1)) {
			ans = (get(A->magnitude)*(-1)) - (get(B->magnitude));
			//printf("-A + -B = %ld\n", ans);
		}
		prepend(S->magnitude, ans);
		movePrev(A->magnitude);
		movePrev(B->magnitude);
		if (same == 1) {
			deleteBack(S->magnitude);
		}
	}
	S->sign = normalizeList(S->magnitude);
}

// sum()
// Returns a reference to a new BigInteger object representing A + B.
BigInteger sum(BigInteger A, BigInteger B) {
	BigInteger S = newBigInteger();
	add(S, A, B);
	return S;
}

// subtract()
// Places the difference of A and B in the existing BigInteger D, overwriting
// its current state: D = A - B
void subtract(BigInteger D, BigInteger A, BigInteger B) {
	if (equals(A,B) == 1) {
		makeZero(D);
		prepend(D->magnitude, 0);
		return;
	}
	negate(B);
	add(D, A, B);
	negate(B);
}

// diff()
// Returns a reference to a new BigInteger object representing A - B.
BigInteger diff(BigInteger A, BigInteger B) {
	BigInteger D = newBigInteger();
	subtract(D, A, B);
	return D;
}

// multiply()
// Places the product of A and B in the existing BigInteger P, overwriting
// its current state: P = A*B
void multiply(BigInteger P, BigInteger A, BigInteger B) {
	if ((length(A->magnitude) == 0) || (length(B->magnitude) == 0)) {
		if (length(P->magnitude) > 0) {
			makeZero(P);
		}
		else {
			append(P->magnitude, 0);
			P->sign = 0;
		}
		return;
	}
	BigInteger tempA = copy(A);
	BigInteger tempB = copy(B);
	makeZero(P);
	int shift = 0, newshift = 0;
	while (length(tempA->magnitude) < length(tempB->magnitude)) {
		prepend(tempA->magnitude, 0);
	}
	while (length(tempB->magnitude) < length(tempA->magnitude)) {
		prepend(tempB->magnitude, 0);
	}
	long ans;
	if (length(P->magnitude) == 0) {
		append(P->magnitude, 0);
		while (length(P->magnitude) < length(tempB->magnitude)) {
		prepend(P->magnitude, 0);
		}
		while (length(P->magnitude) < length(tempA->magnitude)) {
			prepend(P->magnitude, 0);
		}
	}
	for (moveBack(tempB->magnitude); index(tempB->magnitude) != -1; movePrev(tempB->magnitude)) {
		for (moveBack(tempA->magnitude); index(tempA->magnitude) != -1; movePrev(tempA->magnitude)) {
			moveBack(P->magnitude);
			ans = get(tempA->magnitude) * get(tempB->magnitude);
			for (int i = 0; i < shift; i++) {
				movePrev(P->magnitude);
			}
			//prepend(P->magnitude, ans);
			set(P->magnitude, get(P->magnitude) + ans);
			//normalizeList(P->magnitude);
			shift++;
		}
		newshift++;
		shift = newshift;
		normalizeList(P->magnitude);
	}
	if (((sign(tempA) == -1) && (sign(tempB) == 1)) || ((sign(tempA) == 1) && (sign(tempB) == -1))) {
		P->sign = -1;
	}
	else if (((sign(tempA) == 1) && (sign(tempB) == 1)) || ((sign(tempA) == -1) && (sign(tempB) == -1))) {
		P->sign = 1;
	}
	freeBigInteger(&tempA);
	freeBigInteger(&tempB);
}

// prod()
// Returns a reference to a new BigInteger object representing A*B
BigInteger prod(BigInteger A, BigInteger B) {
	BigInteger P = newBigInteger();
	multiply(P, A, B);
	return P;
}

// Other operations -----------------------------------------------------------

// printBigInteger()
// Prints a base 10 string representation of N to filestream out.
void printBigInteger(FILE* out, BigInteger N) {
	if (length(N->magnitude) > 1) {
		while (front(N->magnitude) == 0) {
			deleteFront(N->magnitude);
		}
	}
	if (N->sign == -1) {
		fprintf(out, "-");
	}
	moveFront(N->magnitude);
	fprintf(out, "%ld", get(N->magnitude));
	moveNext(N->magnitude);
	while (index(N->magnitude) != -1) {
		//fprintf(out, "%ld", get(N->magnitude));
		fprintf(out, "%0*ld", POWER, get(N->magnitude));
		moveNext(N->magnitude);
		//fprintf(out, " ");
	}
}
