//-----------------------------------------------------------------------------
//
// Chantel Gee, chmagee
// 2021 Winter CSE 101 pa5
// 
// Dictionary.c
// Implementation file for Dictionary
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

// structs --------------------------------------------------------------------

// private NodeObj type
typedef struct NodeObj {
	KEY_TYPE key;
	VAL_TYPE val;
	struct NodeObj* parent;			// prev node
	struct NodeObj* left;		// next node
	struct NodeObj* right;	// next node
} NodeObj;

// private Node type
typedef NodeObj* Node;

// private DictionaryObj type
typedef struct DictionaryObj {
	Node root;
	Node NIL;
	Node cursor;
	int size;
	int unique;
} DictionaryObj;

// Constructors-Destructors ---------------------------------------------------

Node newNode(KEY_TYPE k, VAL_TYPE v){
	Node N = malloc(sizeof(NodeObj));
	N->key = k;
	N->val = v;
	N->parent = NULL;
	N->left = NULL;
	N->right = NULL;
	return(N);
}

void freeNode(Node* pN){
	if( pN!=NULL && *pN!=NULL ){
		free(*pN);
		*pN = NULL;
	}
}

// newDictionary()
// Creates a new empty Dictionary. If unique==false (0), then the Dictionary 
// will accept duplicate keys, i.e. distinct pairs with identical keys. If 
// unique==true (1 or any non-zero value), then duplicate keys will not be 
// accepted. In this case, the operation insert(D, k) will enforce the 
// precondition: lookup(D, k)==VAL_UNDEF
Dictionary newDictionary(int unique) {
	Dictionary D = malloc(sizeof(DictionaryObj));
	D->NIL = NULL;
	D->NIL->parent = D->NIL;
	D->NIL->left = D->NIL;
	D->NIL->right = D->NIL;
	D->NIL->key = "%";
	D->NIL->val = -70;
	D->root = NULL;
	D->root->parent = D->NIL;
	D->size = 0;
	D->cursor = NULL;
	D->unique = unique;
	return(D);
}

// freeDictionary()
// Frees heap memory associated with *pD, sets *pD to NULL.
void freeDictionary(Dictionary* pD) {
	makeEmpty(* pD);
	free(*pD);
	*pD = NULL;
}


// Access functions -----------------------------------------------------------

// size()
// Returns the number of (key, value) pairs in Dictionary D.
int size(Dictionary D) {
	return (D->size);
}

// getUnique()
// Returns true (1) if D requires that all pairs have unique keys. Returns
// false (0) if D accepts distinct pairs with identical keys.
int getUnique(Dictionary D) {
	return (D->unique);
}

// treeSearch()
// helper function for finding the node of key k
Node treeSearch(Dictionary D, Node x, KEY_TYPE k) {
	if ((x == D->NIL) || (k == x->key)) {
		return x;
		}
	if (k < x->key) {
		return (treeSearch(D, x->left, k));
	}
	else {return (treeSearch(D, x->right, k));}
}

// lookup()
// If Dictionary D contains a (key, value) pair whose key matches k (i.e. if
// KEY_CMP(key, k)==0), then returns value. If D contains no such pair, then
// returns VAL_UNDEF.
VAL_TYPE lookup(Dictionary D, KEY_TYPE k) {
	Node x;
	x = D->root;
	if ((x == D->NIL) || (k == x->key)) {
		if (KEY_CMP(x->key, k) == 0) {
			return x->val;
		}
		else {
			return VAL_UNDEF;
		}
	}
	if (k < x->key) {
		return ((treeSearch(D, x->left, k))->val);
	}
	else {return ((treeSearch(D, x->right, k))->val);}
}

// treeMinimum()
// helper function
KEY_TYPE treeMinimum(Dictionary D, KEY_TYPE k) {
	Node x = D->root;
	x = treeSearch(D, x, k);
	if (x != D->NIL) {
		while (x->left != D->NIL) {
			x = x->left;
		}
		return x->key;
	}
	return D->NIL->key;
}

// treeMaximum()
// helper function
KEY_TYPE treeMaximum(Dictionary D, KEY_TYPE k) {
	Node x = D->root;
	x = treeSearch(D, x, k);
	if (x != D->NIL) {
		while (x->right != D->NIL) {
			x = x->right;
		}
		return x->key;
	}
	return D->NIL->key;
}

// Manipulation procedures ----------------------------------------------------

// insert()
// Insert the pair (k,v) into Dictionary D. 
// If getUnique(D) is false (0), then there are no preconditions.
// If getUnique(D) is true (1), then the precondition lookup(D, k)==VAL_UNDEF
// is enforced. 
void insert(Dictionary D, KEY_TYPE k, VAL_TYPE v) {
	if (getUnique(D) == 1) {
		
	}
}

// transplant()
// helper function for delete
void transplant(Dictionary D, Node k, Node l) {
	
}

// delete()
// Remove the pair whose key is k from Dictionary D.
// Pre: lookup(D,k)!=VAL_UNDEF (i.e. D contains a pair whose key is k.)
void delete(Dictionary D, KEY_TYPE k) {
	
}

// postOrderTreeWalk()
// for deleting the nodes
void postOrderTreeWalk(KEY_TYPE k) {
	
}

// makeEmpty()
// Reset Dictionary D to the empty state, containing no pairs.
void makeEmpty(Dictionary D) {
	
}

// beginForward()
// If D is non-empty, starts a forward iteration over D at the first key 
// (as defined by the order operator KEY_CMP()), then returns the first
// value. If D is empty, returns VAL_UNDEF. 
VAL_TYPE beginForward(Dictionary D) {
	return 1;
}

// beginReverse()
// If D is non-empty, starts a reverse iteration over D at the last key 
// (as defined by the order operator KEY_CMP()), then returns the last
// value. If D is empty, returns VAL_UNDEF.
VAL_TYPE beginReverse(Dictionary D) {
	return 1;
}

// currentKey()
// If an iteration (forward or reverse) over D has started, returns the 
// the current key. If no iteration is underway, returns KEY_UNDEF.
KEY_TYPE currentKey(Dictionary D) {
	return "%";
}

// currentVal()
// If an iteration (forward or reverse) over D has started, returns the 
// value corresponding to the current key. If no iteration is underway, 
// returns VAL_UNDEF.
VAL_TYPE currentVal(Dictionary D) {
	return 1;
}

// next()
// If an iteration (forward or reverse) over D has started, and has not
// reached the last pair, moves to the next key in D (as defined by the 
// order operator KEY_CMP()), and returns the value corresponding to the 
// new key. If an iteration has started, and has reached the last pair,
// ends the iteration and returns VAL_UNDEF. If no iteration is underway, 
// returns VAL_UNDEF.
VAL_TYPE next(Dictionary D) {
	return 1;
}


// prev()
// If an iteration (forward or reverse) over D has started, and has not
// reached the first pair, moves to the previous key in D (as defined by the 
// order operator KEY_CMP()), and returns the value corresponding to the 
// new key. If an iteration has started, and has reached the first pair,
// ends the iteration and returns VAL_UNDEF. If no iteration is underway, 
// returns VAL_UNDEF. 
VAL_TYPE prev(Dictionary D) {
	return 1;
}


// Other operations -----------------------------------------------------------

// printDictionary()
// Prints a text representation of D to the file pointed to by out. Each key-
// value pair is printed on a single line, with the two items separated by a
// single space.  The pairs are printed in the order defined by the operator
// KEY_CMP().
void printDictionary(FILE* out, Dictionary D) {
	return;
}

