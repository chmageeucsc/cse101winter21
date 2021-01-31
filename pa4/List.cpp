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
	frontDummy = nullptr; 
	backDummy = nullptr;
	beforeCursor = nullptr;
	afterCursor = nullptr;
	pos_cursor = 0;
	num_elements = 0;
}

// Copy constructor.
List::List(const List& L) {
	frontDummy = nullptr; 
	backDummy = nullptr;
	beforeCursor = nullptr;
	afterCursor = nullptr;
	pos_cursor = 0;
	num_elements = 0;
	
	Node* N = L.frontDummy;
	while(N != nullptr) {
		this->/*ENQUEUE*/(N->data);
		N = N->next;
	}
}

// Destructor
List::~List() {
	while(num_elements > 0) {
		/*DEQUEUE*/
	}
}


// Access functions --------------------------------------------------------

// isEmpty()
// Returns true if this List is empty, false otherwise.
bool List::isEmpty() {
	
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
	
}


// Manipulation procedures -------------------------------------------------

// moveFront()
// Moves cursor to position 0 in this List.
void List::moveFront() {
	
}

// moveBack()
// Moves cursor to position size() in this List.
void List::moveBack() {
	
}

// peekNext()
// Returns the element after the cursor.
// pre: position()<size()
int List::peekNext() {
	
}

// peekPrev()
// Returns the element before the cursor.
// pre: position()>0
int List::peekPrev() {
	
} 

// moveNext()
// Advances cursor to next higher position. Returns the List element that
// was passed over. 
// pre: position()<size() 
int List::moveNext() {
	
}

// movePrev()
// Advances cursor to next lower position. Returns the List element that
// was passed over. 
// pre: position()>0
int List::movePrev() {
	
}

// insertAfter()
// Inserts x after cursor.
void List::insertAfter(int x) {
	
}

// insertBefore()
// Inserts x before cursor.
void List::insertBefore(int x) {
	
}

// eraseAfter()
// Deletes element after cursor.
// pre: position()<size()
void List::eraseAfter() {
	
}

// eraseBefore()
// Deletes element before cursor.
// pre: position()>0
void List::eraseBefore() {
	
}

// findNext()
// Starting from the current cursor position, performs a linear search (in 
// the direction front-to-back) for the first occurrence of the element x.
// If x is found, places the cursor immediately after the found element (so 
// eraseBefore() would remove the found element), and returns the final 
// cursor position. If x is not found, places the cursor at position size(),
// and returns -1. 
int List::findNext(int x) {
	
}

// findPrev()
// Starting from the current cursor position, performs a linear search (in 
// the direction back-to-front) for the first occurrence of the element x.
// If x is found, places the cursor immediately before the found element (so 
// eraseAfter() would remove the found element), and returns the final 
// cursor position. If x is not found, places the cursor at position 0, and 
// returns -1. 
int List::findPrev(int x) {
	
}

// cleanup()
// Removes any repeated elements in this List, leaving only unique data
// values. The order of the remaining elements is obtained by retaining
// the frontmost occurrance of each element, and removing all other 
// occurances. The cursor is not moved with respect to the retained 
// elements, i.e. it lies between the same two retained elements that it 
// did before cleanup() was called.
void List::cleanup();

// clear()
// Deletes all elements in this List, setting it to the empty state.
void List::clear() {
	
}

// concat()
// Returns a new List consisting of the elements of this List, followed
// the elements of L. The returned List's cursor will be at its front
// (position 0).
List List::concat(const List& L) {
	
}


// Other Functions ---------------------------------------------------------

// to_string()
// Returns a string representation of this List consisting of a comma 
// separated sequence of elements, surrounded by parentheses.
std::string List::to_string() {
	
}

// equals()
// Returns true if and only if this List is the same integer sequence as R.
// The cursors in this List and in R are unchanged.
bool List::equals(const List& R) {
	
}


// Overriden Operators -----------------------------------------------------

// operator<<()
// Inserts string representation of L into stream.
friend std::ostream& operator<<( std::ostream& stream, List& L ) {
	
}

// operator==()
// Returns true if and only if A is the same integer sequence as B. The 
// cursors in both Lists are unchanged are unchanged.
friend bool operator==( List& A, const List& B ) {
	
}

// operator=()
// Overwrites the state of this List with state of L.
List& List::operator=( const List& L ) {
	
}