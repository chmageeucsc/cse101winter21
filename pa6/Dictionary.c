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

#define KEY_TYPE char*
#define VAL_TYPE int*
#define KEY_UNDEF NULL
#define VAL_UNDEF NULL
#define KEY_FORMAT "%s"
#define VAL_FORMAT "%p"
#define KEY_CMP(x,y) strcmp(x,y)
#define RED 123456789
#define BLACK 987654321


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
	N->color = BLACK;
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
	D->root = D->NIL;
	D->size = 0;
	D->cursor = NULL;
	D->unique = unique;
	return(D);
}

// freeDictionary()
// Frees heap memory associated with *pD, sets *pD to NULL.
void freeDictionary(Dictionary* pD) {
	
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

// insert()
// Insert the pair (k,v) into Dictionary D. 
// If getUnique(D) is false (0), then there are no preconditions.
// If getUnique(D) is true (1), then the precondition lookup(D, k)==VAL_UNDEF
// is enforced. 
void insert(Dictionary D, KEY_TYPE k, VAL_TYPE v) {
	
}

// delete()
// Remove the pair whose key is k from Dictionary D.
// Pre: lookup(D,k)!=VAL_UNDEF (i.e. D contains a pair whose key is k.)
void delete(Dictionary D, KEY_TYPE k) {
	
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
	if (forwardOn == true) {
		D->cursor = treeSuccessor(D, D->cursor);
		if (D->cursor == D->NIL) {
			return VAL_UNDEF;
		}
		return (D->cursor->val);
	}
	else if (reverseOn == true) {
		D->cursor = treePredecessor(D, D->cursor);
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
	if (forwardOn == true) {
		D->cursor = treePredecessor(D, D->cursor);
		if (D->cursor == D->NIL) {
			return VAL_UNDEF;
		}
		return (D->cursor->val);
	}
	else if (reverseOn == true) {
		D->cursor = treeSuccessor(D, D->cursor);
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
void print_pre(Dictionary D, Node x) {
	if(D == NULL) {
		printf("Dictionary Error: calling print_pre() on NULL Dictionary reference\n");
		exit(EXIT_FAILURE);
	}
	if (x != D->NIL) {
		printf("%s\n", x->key);
		print_pre(D, x->left);
		print_pre(D, x->right);
	}
}

// print_in()
// helper function for printDictionary
void print_in(Dictionary D, Node x) {
	if(D == NULL) {
		printf("Dictionary Error: calling print_in() on NULL Dictionary reference\n");
		exit(EXIT_FAILURE);
	}
	if (x != D->NIL) {
		print_in(D, x->left);
		printf("%s\n", x->key);
		print_in(D, x->right);
	}
}

// print_post()
// helper function for printDictionary
void print_post(Dictionary D, Node x) {
	if(D == NULL) {
		printf("Dictionary Error: calling print_post() on NULL Dictionary reference\n");
		exit(EXIT_FAILURE);
	}
	if (x != D->NIL) {
		print_post(D, x->left);
		print_post(D, x->right);
		printf("%s\n", x->key);
	}
}

// printDictionary()
// Prints the keys (only) of D in an order determined by the parameter ord.
// If ord is "pre", "in" or "post", executes the corresponding tree traversal
// on the underlying RBT, printing keys only (no values).  If ord is some
// other string, prints nothing.
void printDictionary(FILE* out, Dictionary D, const char* ord) {
	if (D->size != 0) {
		if (ord == "pre") {
			print_pre(D, D->root);
		}
		else if (ord == "in") {
			print_in(D, D->root);
		}
		else if (ord == "post") {
			print_post(D, D->root);
		}
	}
}
