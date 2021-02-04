//-----------------------------------------------------------------------------
//
// Chantel Gee, chmagee
// 2021 Winter CSE 101
// 
// List.cpp
// Implementation file for List ADT
// 
//-----------------------------------------------------------------------------

#include<iostream>
#include<string>
#include"List.h"

using namespace std;

// Exported type --------------------------------------------------------------



// Private Constructor --------------------------------------------------------

// private Node struct

// Node constructor
List::Node::Node(int x){
   data = x;
   next = nullptr;
   prev = nullptr;
}

// Class Constructors & Destructors -------------------------------------------

// Creates new List in the empty state.
List::List() {
	frontDummy = new Node(-1);
	backDummy = new Node(-1);
	frontDummy->next = backDummy;
	backDummy->prev = frontDummy;
	beforeCursor = frontDummy;
	afterCursor = backDummy;
	pos_cursor = 0;
	num_elements = 0;
}

// Copy constructor.
List::List(const List& L) {
	frontDummy = new Node(-1);
	backDummy = new Node(-1);
	beforeCursor = frontDummy;
	afterCursor = backDummy;
	pos_cursor = 0;
	num_elements = 0;
	
	Node* N = L.frontDummy->next;
	while (N != backDummy) {
		this->insertBefore(N->data);
		N = N->next;
	}
}

// Destructor
List::~List() {
	this->clear();
	this->eraseBefore();
	this->eraseAfter();
}


// Access functions --------------------------------------------------------

// isEmpty()
// Returns true if this List is empty, false otherwise.
bool List::isEmpty() {
	if(size() == 0) { return true;}
	else {return false;}
}

// size()
// Returns the size of this List.
int List::size() {
	return (num_elements);
}

// position()
// Returns the position of the cursor in this List. The value returned
// will be in the range 0 to size().
int List::position() {
	return (pos_cursor);
}


// Manipulation procedures -------------------------------------------------

// moveFront()
// Moves cursor to position 0 in this List.
void List::moveFront() {
	if (num_elements >= 0) {
		beforeCursor = frontDummy;
		afterCursor = frontDummy->next;
		pos_cursor = 0;
	}
}

// moveBack()
// Moves cursor to position size() in this List.
void List::moveBack() {
	if (num_elements >= 0) {
		afterCursor = backDummy;
		beforeCursor = backDummy->prev;
		pos_cursor = size();
	}
}

// peekNext()
// Returns the element after the cursor.
// pre: position()<size()
int List::peekNext() {
	if (position() > size()) {
		cout << "List Error: calling peekNext() out of bounds" << endl;
		exit(-1);
	}
	return afterCursor->data;
}

// peekPrev()
// Returns the element before the cursor.
// pre: position()>0
int List::peekPrev() {
	if (position() < 0) {
		cout << "List Error: calling peekPrev() out of bounds" << endl;
		exit(-1);
	}
	return beforeCursor->data;
} 

// moveNext()
// Advances cursor to next higher position. Returns the List element that
// was passed over. 
// pre: position()<size() 
int List::moveNext() {
	if (position() > size()) {
		cout << "List Error: calling moveNext() out of bounds" << endl;
		exit(-1);
	}
	beforeCursor = beforeCursor->next;
	afterCursor = afterCursor->next;
	pos_cursor++;
	return beforeCursor->data;
}

// movePrev()
// Advances cursor to next lower position. Returns the List element that
// was passed over. 
// pre: position()>0
int List::movePrev() {
	if (position() < 0) {
		cout << "List Error: calling movePrev() out of bounds" << endl;
		exit(-1);
	}
	afterCursor = beforeCursor;
	beforeCursor = beforeCursor->prev;
	pos_cursor--;
	return afterCursor->data;
}

// insertAfter()
// Inserts x after cursor.
void List::insertAfter(int x) {
	Node* N = new Node(x);
	afterCursor->prev = N;
	N->next = afterCursor;
	N->prev = beforeCursor;
	beforeCursor->next = N;
	afterCursor = N;
	num_elements++;
}

// insertBefore()
// Inserts x before cursor.
void List::insertBefore(int x) {
	Node* N = new Node(x);
	beforeCursor->next = N;
	N->prev = beforeCursor;
	N->next = afterCursor;
	afterCursor->prev = N;
	beforeCursor = N;
	num_elements++;
	pos_cursor++;
}

// eraseAfter()
// Deletes element after cursor.
// pre: position()<size()
void List::eraseAfter() {
	if (position() < size()) {
		Node* N = afterCursor;
		afterCursor = afterCursor->next;
		afterCursor->prev = beforeCursor;
		beforeCursor->next = afterCursor;
		delete N;
		num_elements--;
	}
}

// eraseBefore()
// Deletes element before cursor.
// pre: position()>0
void List::eraseBefore() {
	if (position() > 0) {
		Node* N = beforeCursor;
		beforeCursor = beforeCursor->prev;
		afterCursor->prev = beforeCursor;
		beforeCursor->next = afterCursor;
		delete N;
		num_elements--;
		pos_cursor--;
	}
}

// findNext()
// Starting from the current cursor position, performs a linear search (in 
// the direction front-to-back) for the first occurrence of the element x.
// If x is found, places the cursor immediately after the found element (so 
// eraseBefore() would remove the found element), and returns the final 
// cursor position. If x is not found, places the cursor at position size(),
// and returns -1. 
int List::findNext(int x) {
	while(afterCursor != backDummy) {
		if (moveNext() == x) {
			return (pos_cursor);
		}
	}
	return -1;
}

// findPrev()
// Starting from the current cursor position, performs a linear search (in 
// the direction back-to-front) for the first occurrence of the element x.
// If x is found, places the cursor immediately before the found element (so 
// eraseAfter() would remove the found element), and returns the final 
// cursor position. If x is not found, places the cursor at position 0, and 
// returns -1. 
int List::findPrev(int x) {
	while(beforeCursor != frontDummy) {
		if (movePrev() == x) {
			return (pos_cursor);
		}
	}
	return -1;
}

// cleanup()
// Removes any repeated elements in this List, leaving only unique data
// values. The order of the remaining elements is obtained by retaining
// the frontmost occurrance of each element, and removing all other 
// occurances. The cursor is not moved with respect to the retained 
// elements, i.e. it lies between the same two retained elements that it 
// did before cleanup() was called.
void List::cleanup() {
	
	for (int i = 1; i < size(); i++) {
		moveFront();
		if (findNext(i) != -1) {
			eraseBefore();
		}
	}
}

// clear()
// Deletes all elements in this List, setting it to the empty state.
void List::clear() {
	this->moveFront();
	while (afterCursor != backDummy) {
		eraseAfter();
	}
}

// concat()
// Returns a new List consisting of the elements of this List, followed
// the elements of L. The returned List's cursor will be at its front
// (position 0).
List List::concat(const List& L) {
	List C;
	Node* N = this->frontDummy;
	Node* M = L.frontDummy->next;
	while (N != backDummy) {
		C.insertBefore(N->data);
		N = N->next;
	}
	while (M != backDummy) {
		C.insertBefore(M->data);
		M = M->next;
	}
	C.pos_cursor = 0;
	C.beforeCursor = frontDummy;
	C.afterCursor = frontDummy->next;
	return C;
}


// Other Functions ---------------------------------------------------------

// to_string()
// Returns a string representation of this List consisting of a comma 
// separated sequence of elements, surrounded by parentheses.
std::string List::to_string() {
	Node* N = nullptr;
	string s = "(";
	N=frontDummy->next;
	s += std::to_string(N->data);
	for(N=frontDummy->next->next; N!=backDummy; N=N->next){
		s += ", "+std::to_string(N->data);
	}
	s += ")";

	return s;
}

// equals()
// Returns true if and only if this List is the same integer sequence as R.
// The cursors in this List and in R are unchanged.
bool List::equals(const List& R) {
	bool eq = false;
	Node* N = nullptr;
	Node* M = nullptr;

	eq = ( this->num_elements == R.num_elements );
	N = this->frontDummy;
	M = R.frontDummy;
	while( eq && N!=nullptr){
		eq = (N->data==M->data);
		N = N->next;
		M = M->next;
	}
	return eq;
}


// Overriden Operators -----------------------------------------------------

// operator<<()
// Inserts string representation of L into stream.
std::ostream& operator<<( std::ostream& stream, List& L ) {
	return stream << L.List::to_string();
}

// operator==()
// Returns true if and only if A is the same integer sequence as B. The 
// cursors in both Lists are unchanged are unchanged.
bool operator==( List& A, const List& B ) {
	return A.List::equals(B);
}

// operator=()
// Overwrites the state of this List with state of L.
List& List::operator=( const List& L ) {
	if( this != &L ){ // not self assignment
		// make a copy of L
		List temp = L;

		// then swap the copy's fields with fields of this
		std::swap(frontDummy, temp.frontDummy);
		std::swap(backDummy, temp.backDummy);
		std::swap(beforeCursor, temp.beforeCursor);
		std::swap(afterCursor, temp.afterCursor);
		std::swap(pos_cursor, temp.pos_cursor);
		std::swap(num_elements, temp.num_elements);
   }

   // return this with the new data installed
   return *this;

   // the copy, if there is one, is deleted upon return
}
