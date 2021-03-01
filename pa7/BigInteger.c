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
#include "BigInteger.h"
#include "List.h"

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
	N->magnitude = malloc(sizeof(long));
	return N;
}

// freeBigInteger()
// Frees heap memory associated with *pN, sets *pN to NULL.
void freeBigInteger(BigInteger* pN) {
	if(pN != NULL && *pN != NULL) { 
		free((*pN)->magnitude);
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
	if (A->sign < B->sign) {
		return -1;
	}
	else if (A->sign > B->sign) {
		return 1;
	}
	else if (A == B) {							// FINISH LATER
		return -1;
	}
	else if (equals(A, B) == 1) {
		return 0;
	}
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
	BigInteger A = newBigInteger();
	return A;
}

// copy()
// Returns a reference to a new BigInteger object in the same state as N.
BigInteger copy(BigInteger N) {
	BigInteger copy = newBigInteger();
	copy->sign = N->sign;
	copy->magnitude = copyList(N->magnitude);
	return copy;
}

// add()
// Places the sum of A and B in the existing BigInteger S, overwriting its
// current state: S = A + B
void add(BigInteger S, BigInteger A, BigInteger B) {
	
}

// sum()
// Returns a reference to a new BigInteger object representing A + B.
BigInteger sum(BigInteger A, BigInteger B) {
	return A;
}

// subtract()
// Places the difference of A and B in the existing BigInteger D, overwriting
// its current state: D = A - B
void subtract(BigInteger D, BigInteger A, BigInteger B) {
	
}

// diff()
// Returns a reference to a new BigInteger object representing A - B.
BigInteger diff(BigInteger A, BigInteger B) {
	return A;
}

// multiply()
// Places the product of A and B in the existing BigInteger P, overwriting
// its current state: P = A*B
void multiply(BigInteger P, BigInteger A, BigInteger B) {
	
}

// prod()
// Returns a reference to a new BigInteger object representing A*B
BigInteger prod(BigInteger A, BigInteger B) {
	return A;
}

// Other operations -----------------------------------------------------------

// printBigInteger()
// Prints a base 10 string representation of N to filestream out.
void printBigInteger(FILE* out, BigInteger N) {
	
}