//-----------------------------------------------------------------------------
//
// Chantel Gee, chmagee
// 2021 Winter CSE 101 pa4
// 
// ListTest.cpp
// Test file for List ADT
// 
//-----------------------------------------------------------------------------
#include<iostream>
#include<string>
#include"List.h"

using namespace std;

int main() 
{ 
	List A;
	
	A.insertAfter(200);
    A.insertAfter(176);
	A.insertAfter(15);
	A.insertAfter(10);
	A.insertAfter(5);
	A.findNext(15);
	A.eraseAfter();
	if (A.position() != 3) {
		cout << "Error: Position should be 3." << endl;
	}
	A.insertAfter(175);
	A.eraseAfter();
	if (A.position() != 3) {
		cout << "Error: Position should be 3." << endl;
	}
	A.insertBefore(50);
	A.insertBefore(15);
	if (A.position() != 5) {
		cout << "Error: Position should be 5." << endl;
	}
	A.findPrev(15);
	A.eraseAfter();
	if (A.position() != 4) {
		cout << "Error: Position should be 4." << endl;
	}
	A.findPrev(15);
	if (A.position() != 2) {
		cout << "Error: Position should be 2." << endl;
	}
	A.moveFront();
	A.eraseAfter();
	A.eraseAfter();
	A.eraseAfter();
	A.eraseAfter();
	A.eraseAfter();
	if (A.position() != 0) {
		cout << "Error: Position should be 0." << endl;
	}
    return 0; 
}
