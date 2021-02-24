//-----------------------------------------------------------------------------
//
// Chantel Gee, chmagee
// 2021 Winter CSE 101 pa6 (some functions taken from pa5)
// 
// Dictionary.c
// Implementation file for Dictionary
// 
//-----------------------------------------------------------------------------

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include "Dictionary.h"

#define KEY_TYPE char*
#define VAL_TYPE int*
#define KEY_UNDEF NULL
#define VAL_UNDEF NULL
#define KEY_FORMAT "%s"
#define VAL_FORMAT "%p"
#define KEY_CMP(x,y) strcmp(x,y)
#define RED 0
#define BLACK 1

// extras ---------------------------------------------------------------------

bool forwardOn = false;		// check for forward iteration
bool reverseOn = false;		// check for reverse iteration

// structs --------------------------------------------------------------------

// private NodeObj type
typedef struct NodeObj {
	int color;
	KEY_TYPE key;
	VAL_TYPE val;
	struct NodeObj* parent;			// prev node
	struct NodeObj* left;			// next node
	struct NodeObj* right;			// next node
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
	N->color = RED;
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
	D->NIL = newNode(KEY_UNDEF, VAL_UNDEF);
	D->NIL->parent = D->NIL;
	D->NIL->left = D->NIL;
	D->NIL->right = D->NIL;
	D->NIL->color = BLACK;
	D->root = D->NIL;
	D->root->color = BLACK;
	D->size = 0;
	D->cursor = NULL;
	D->unique = unique;
	return(D);
}

// freeDictionary()
// Frees heap memory associated with *pD, sets *pD to NULL.
void freeDictionary(Dictionary* pD) {
	if(pD != NULL && *pD != NULL) {
		makeEmpty(*pD);
	}
	free((*pD)->NIL);
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
	return D->unique;
}

// treeSearch()
// helper function for lookup
Node treeSearch(Dictionary D, Node x, KEY_TYPE k) {
	while ((x != D->NIL) && (k != x->key)) {
		if (KEY_CMP(k, x->key) < 0) {
			x = x->left;
		}
		else {
			x = x->right;
		}
	}
	return x;
}

// lookup()
// If Dictionary D contains a (key, value) pair whose key matches k (i.e. if
// KEY_CMP(key, k)==0), then returns value. If D contains no such pair, then
// returns VAL_UNDEF.
VAL_TYPE lookup(Dictionary D, KEY_TYPE k) {
	if (D->root == D->NIL) {
		return VAL_UNDEF;
	}
	Node x;
	x = treeSearch(D, D->root, k);
	if (x->key == NULL) {
		return VAL_UNDEF;
	}
	if (KEY_CMP(x->key, k) == 0) {
		return x->val;
	}
	else {
		return VAL_UNDEF;
	}
}

// treeMinimum()
// helper function
Node treeMinimum(Dictionary D, Node x) {
	if (x != D->NIL) {
		while (x->left != D->NIL) {
			x = x->left;
		}
		return x;
	}
	return D->NIL;
}

// treeMaximum()
// helper function
Node treeMaximum(Dictionary D, Node x) {
	if (x != D->NIL) {
		while (x->right != D->NIL) {
			x = x->right;
		}
		return x;
	}
	return D->NIL;
}

// Manipulation procedures ----------------------------------------------------

// leftRotate()
// helper function for fixup functions
void leftRotate(Dictionary D, Node x) {
	Node y;
	y= x->right;
	x->right = y->left;
	if (y->left != D->NIL) {
		y->left->parent = x;
	}
	y->parent = x->parent;
	if (x->parent == D->NIL) {
		D->root = y;
	}
	else if (x == x->parent->left) {
		x->parent->left = y;
	}
	else {x->parent->right = y;}
	y->left = x;
	x->parent = y;
}

// rightRotate()
// helper function for fixup functions
void rightRotate(Dictionary D, Node x) {
	Node y;
	y= x->left;
	x->left = y->right;
	if (y->right != D->NIL) {
		y->right->parent = x;
	}
	y->parent = x->parent;
	if (x->parent == D->NIL) {
		D->root = y;
	}
	else if (x == x->parent->right) {
		x->parent->right = y;
	}
	else {x->parent->left = y;}
	y->right = x;
	x->parent = y;
}

// RB_InsertFixUp()
// helper function for insert()
void RB_InsertFixUp(Dictionary D, Node z) {
	Node y;
	while (z->parent->color == RED) {
		if (z->parent == z->parent->parent->left) {
			y = z->parent->parent->right;
			if (y->color == RED) {
				z->parent->color = BLACK;
				y->color = BLACK;
				z->parent->parent->color = RED;
				z = z->parent->parent;
			}
			else {
				if (z == z->parent->right) {
					z = z->parent;
					leftRotate(D, z);
				}
				z->parent->color = BLACK;
				z->parent->parent->color = RED;
				rightRotate(D, z->parent->parent);
			}
		}
		else {
			y = z->parent->parent->left;
			if (y->color == RED) {
				z->parent->color = BLACK;
				y->color = BLACK;
				z->parent->parent->color = RED;
				z = z->parent->parent;
			}
			else {
				if (z == z->parent->left) {
					z = z->parent;
					rightRotate(D, z);
				}
				z->parent->color = BLACK;
				z->parent->parent->color = RED;
				leftRotate(D, z->parent->parent);
			}
		}
	}
	D->root->color = BLACK;
}

// insert()
// Insert the pair (k,v) into Dictionary D. 
// If getUnique(D) is false (0), then there are no preconditions.
// If getUnique(D) is true (1), then the precondition lookup(D, k)==VAL_UNDEF
// is enforced. 
void insert(Dictionary D, KEY_TYPE k, VAL_TYPE v) {
	if (getUnique(D) == 1) {
		if (lookup(D, k) != VAL_UNDEF) {
			return;
		}
	}
	Node x, y, z;
	y = D->NIL;
	x = D->root;
	z = newNode(k, v);
	while (x != D->NIL) {
		y = x;
		if (KEY_CMP(z->key, x->key) < 0) {
			x = x->left;
		}
		else { x = x->right;}
	}
	z->parent = y;
	if (y == D->NIL) {
		D->root = z;
	}
	else if (KEY_CMP(z->key, y->key) < 0) {
		y->left = z; 
	}
	else { y->right = z;}
	z->left = D->NIL;
	z->right = D->NIL;
	z->color = RED;
	RB_InsertFixUp(D, z);
	D->size ++;
}

// transplant()
// helper function for delete
void transplant(Dictionary D, Node u, Node v) {
	if (u->parent == D->NIL) {			// if parent is NIL, u is the root
		D->root = v;
	}
	else if (u == u->parent->left) {
		u->parent->left = v;
	}
	else {
		u->parent->right = v;
	}
	v->parent = u->parent;
}

// RB_DeleteFixUp()
// helper function for delete
void RB_DeleteFixUp(Dictionary D, Node x) {
	Node w;
	while ((x != D->root) && (x->color == BLACK)) {
		if (x == x->parent->left) {
			w = x->parent->right;
			if (w->color == RED) {
				w->color = BLACK;
				x->parent->color = RED;
				leftRotate(D, x->parent);
				w = x->parent->right;
			}
			if ((w->left->color == BLACK) && (w->right->color == BLACK)) {
				w->color = RED;
				x = x->parent;
			}
			else {
				if (w->right->color == BLACK) {
					w->left->color = BLACK;
					w->color = RED;
					rightRotate(D, w);
					w = x->parent->right;
				}
				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->right->color = BLACK;
				leftRotate(D, x->parent);
				x = D->root;
			}
		}
		else {
			w = x->parent->left;
			if (w->color == RED) {
				w->color = BLACK;
				x->parent->color = RED;
				rightRotate(D, x->parent);
				w = x->parent->left;
			}
			if ((w->right->color == BLACK) && (w->left->color == BLACK)) {
				w->color = RED;
				x = x->parent;
			}
			else {
				if (w->left->color == BLACK) {
					w->right->color = BLACK;
					w->color = RED;
					leftRotate(D, w);
					w = x->parent->left;
				}
				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->left->color = BLACK;
				rightRotate(D, x->parent);
				x = D->root;
			}
		}
	}
	x->color = BLACK;
}

// delete()
// Remove the pair whose key is k from Dictionary D.
// Pre: lookup(D,k)!=VAL_UNDEF (i.e. D contains a pair whose key is k.)
void delete(Dictionary D, KEY_TYPE k) {
	if (lookup(D,k) != VAL_UNDEF) {
		Node x, y, z;
		int y_origin_color;
		z = treeSearch(D, D->root, k);
		y = z;
		y_origin_color = y->color;
		if (z->left == D->NIL) {
			x = z->right;
			transplant(D, z, z->right);
		}
		else if (z->right == D->NIL) {
			x = z->left;
			transplant(D, z, z->left);
		}
		else {
			y = treeMinimum(D, z->right);
			y_origin_color = y->color;
			x = y->right;
			if (y->parent == z) {
				x->parent = y;
			}
			else {
				transplant(D, y, y->right);
				y->right = z->right;
				y->right->parent = y;
			}
			transplant(D, z, y);
			y->left = z->left;
			y->left->parent = y;
			y->color = z->color;
		}
		if (y_origin_color == BLACK) {
			RB_DeleteFixUp(D, x);
		}
		
		if ((forwardOn == true) || (reverseOn == true)) {
			if (D->cursor == z) {
				D->cursor = D->NIL;
			}
		}
			
		freeNode(&z);
		D->size--;
	}
}

// postOrderTreeWalk()
// helper function for makeEmpty
void postOrderTreeWalk(Dictionary D, Node x) {
	if(D == NULL) {
		printf("Dictionary Error: calling postOrderTreeWalk() on NULL Dictionary reference\n");
		exit(EXIT_FAILURE);
	}
	if (x != D->NIL) {
		postOrderTreeWalk(D, x->left);
		postOrderTreeWalk(D, x->right);
		//delete(D, x->key);
		freeNode(&x);
		D->size--;
	}
}

// makeEmpty()
// Reset Dictionary D to the empty state, containing no pairs.
void makeEmpty(Dictionary D) {
	if(D == NULL) {
		printf("Dictionary Error: calling makeEmpty() on NULL Dictionary reference\n");
		exit(EXIT_FAILURE);
	}
	if (D->size > 0) {
		Node x = D->root;
		postOrderTreeWalk(D, x);
		D->cursor = D->NIL;
		D->cursor->key = KEY_UNDEF;
		D->cursor->val = VAL_UNDEF;
		D->cursor->color = BLACK;
	}
}

// beginForward()
// If D is non-empty, starts a forward iteration over D at the first key 
// (as defined by the order operator KEY_CMP()), then returns the first
// value. If D is empty, returns VAL_UNDEF. 
VAL_TYPE beginForward(Dictionary D) {
	if (D->size != 0) {
		forwardOn = true;
		D->cursor = treeMinimum(D, D->root);
		D->cursor->parent = treeMinimum(D, D->root)->parent;
		D->cursor->left = treeMinimum(D, D->root)->left;
		D->cursor->right = treeMinimum(D, D->root)->right;
		return (treeMinimum(D, D->root)->val);
	}
	return VAL_UNDEF;
}

// beginReverse()
// If D is non-empty, starts a reverse iteration over D at the last key 
// (as defined by the order operator KEY_CMP()), then returns the last
// value. If D is empty, returns VAL_UNDEF.
VAL_TYPE beginReverse(Dictionary D) {
	if (D->size != 0) {
		reverseOn = true;
		D->cursor = treeMaximum(D, D->root);
		D->cursor->parent = treeMaximum(D, D->root)->parent;
		D->cursor->left = treeMaximum(D, D->root)->left;
		D->cursor->right = treeMaximum(D, D->root)->right;
		return (treeMaximum(D, D->root)->val);
	}
	return VAL_UNDEF;
}

// currentKey()
// If an iteration (forward or reverse) over D has started, returns the 
// the current key. If no iteration is underway, returns KEY_UNDEF.
KEY_TYPE currentKey(Dictionary D) {
	if ((forwardOn == true) || (reverseOn == true)) {
		return D->cursor->key;
	}
	return KEY_UNDEF;
}

// currentVal()
// If an iteration (forward or reverse) over D has started, returns the 
// value corresponding to the current key. If no iteration is underway, 
// returns VAL_UNDEF.
VAL_TYPE currentVal(Dictionary D) {
	if ((forwardOn == true) || (reverseOn == true)) {
		return D->cursor->val;
	}
	return VAL_UNDEF;
}

// treeSuccessor()
// helper function for next() and prev()
Node treeSuccessor(Dictionary D, Node x) {
	Node y;
	if (x->right != D->NIL) {
		return treeMinimum(D, x->right);
	}
	y = x->parent;
	while ((y != D->NIL) && (x == y->right)) {
		x = y;
		y = y->parent;
	}
	return y;
}

// treePredecessor()
// helper function for next() and prev()
Node treePredecessor(Dictionary D, Node x) {
	Node y;
	if (x->left != D->NIL) {
		return treeMaximum(D, x->left);
	}
	y = x->parent;
	while ((y != D->NIL) && (KEY_CMP(x->key, y->key) < 0)) {
		y = y->parent;
	}
	if ((y != D->NIL) && (KEY_CMP(x->key, y->key) == 0)) {
		if (x->val < y->val) {
			y = y->parent;
		}
	}
	return y;
}

// next()
// If an iteration (forward or reverse) over D has started, and has not
// reached the last pair, moves to the next key in D (as defined by the 
// order operator KEY_CMP()), and returns the value corresponding to the 
// new key. If an iteration has started, and has reached the last pair,
// ends the iteration and returns VAL_UNDEF. If no iteration is underway, 
// returns VAL_UNDEF.
VAL_TYPE next(Dictionary D) {
	if (forwardOn == true || reverseOn == true) {
		D->cursor = treeSuccessor(D, D->cursor);
		if (D->cursor == D->NIL) {
			return VAL_UNDEF;
		}
		return (D->cursor->val);
	}
	return VAL_UNDEF;
}


// prev()
// If an iteration (forward or reverse) over D has started, and has not
// reached the first pair, moves to the previous key in D (as defined by the 
// order operator KEY_CMP()), and returns the value corresponding to the 
// new key. If an iteration has started, and has reached the first pair,
// ends the iteration and returns VAL_UNDEF. If no iteration is underway, 
// returns VAL_UNDEF. 
VAL_TYPE prev(Dictionary D) {
	if (forwardOn == true || reverseOn == true) {
		D->cursor = treePredecessor(D, D->cursor);
		if (D->cursor == D->NIL) {
			return VAL_UNDEF;
		}
		return (D->cursor->val);
	}
	return VAL_UNDEF;
}


// Other operations -----------------------------------------------------------

// print_pre()
// helper function for printDictionary
void print_pre(FILE* out, Dictionary D, Node x) {
	if(D == NULL) {
		printf("Dictionary Error: calling print_pre() on NULL Dictionary reference\n");
		exit(EXIT_FAILURE);
	}
	if (x != D->NIL) {
		fprintf(out, "%s", x->key);
		print_pre(out, D, x->left);
		print_pre(out, D, x->right);
	}
}

// print_in()
// helper function for printDictionary
void print_in(FILE* out, Dictionary D, Node x) {
	if(D == NULL) {
		printf("Dictionary Error: calling print_in() on NULL Dictionary reference\n");
		exit(EXIT_FAILURE);
	}
	if (x != D->NIL) {
		print_in(out, D, x->left);
		fprintf(out, "%s", x->key);
		print_in(out, D, x->right);
	}
}

// print_post()
// helper function for printDictionary
void print_post(FILE* out, Dictionary D, Node x) {
	if(D == NULL) {
		printf("Dictionary Error: calling print_post() on NULL Dictionary reference\n");
		exit(EXIT_FAILURE);
	}
	if (x != D->NIL) {
		print_post(out, D, x->left);
		print_post(out, D, x->right);
		fprintf(out, "%s", x->key);
	}
}

// printDictionary()
// Prints the keys (only) of D in an order determined by the parameter ord.
// If ord is "pre", "in" or "post", executes the corresponding tree traversal
// on the underlying RBT, printing keys only (no values).  If ord is some
// other string, prints nothing.
void printDictionary(FILE* out, Dictionary D, const char* ord) {
	if (D->size != 0) {
		if (strcmp(ord, "pre") == 0) {
			print_pre(out, D, D->root);
		}
		else if (strcmp(ord, "in") == 0) {
			print_in(out, D, D->root);
		}
		else if (strcmp(ord, "post") == 0) {
			print_post(out, D, D->root);
		}
	}
}
