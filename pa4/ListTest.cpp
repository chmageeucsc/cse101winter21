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
	List A, B, C, D;
	A.clear();
	B.clear();
	C.clear();
	D.clear();
	
	cout << "A.size() = " << A.size() << endl;
	cout << "A.position() = " << A.position() << endl;
	
	if (A.isEmpty() == true) {
		cout << "A is empty ! " << endl;
	}
	
	cout << endl;
	
	A.insertBefore(1);
	A.insertBefore(5);
	A.insertBefore(16);
	A.insertBefore(176);
	A.insertBefore(3214);
	A.insertAfter(1);
	A.insertAfter(5);
	A.insertAfter(16);
	A.insertAfter(176);
	A.insertAfter(3214);
	
	cout << "A = " << A << endl;
	cout << "A.size() = " << A.size() << endl;
	cout << "A.position() = " << A.position() << endl;
	A.eraseBefore();
	A.eraseAfter();
	
	cout << endl;
	
	cout << "A = " << A << endl;
	cout << "A.size() = " << A.size() << endl;
	cout << "A.position() = " << A.position() << endl;
	
	cout << endl;
	
	A.cleanup();
	
	cout << "A = " << A << endl;
	cout << "A.size() = " << A.size() << endl;
	cout << "A.position() = " << A.position() << endl;
	
	cout << endl;
	
	B.insertBefore(1);
	B.insertBefore(5);
	B.insertBefore(16);
	B.insertBefore(176);
	B.insertBefore(3214);
	
	C = B;
	cout << "Does C = B ? " << endl;
	cout << "B = " << B << endl;
	cout << "C = " << C << endl;
	
	if (C.equals(B) == true) {
		cout << "C = B ! correct ! " << endl;
	}
	
	cout << endl;
	
	A.moveFront();
	cout << "A's first value is " << A.peekNext() << endl;
	A.moveNext();
	cout << "A's second value is " << A.peekNext() << endl;
	A.moveBack();
	cout << "A's last value is " << A.peekPrev() << endl;
	A.movePrev();
	cout << "A's second to last value is " << A.peekPrev() << endl;
	
	cout << endl;
	
	A.clear();
	
	A.insertBefore(1);
	A.insertBefore(5);
	A.insertBefore(16);
	A.insertBefore(176);
	A.insertBefore(3214);
	A.insertAfter(1);
	A.insertAfter(5);
	A.insertAfter(16);
	A.insertAfter(176);
	A.insertAfter(3214);
	
	cout << "A = " << A << endl;
	cout << "findNext(1) = " << A.findNext(1) << endl;
	cout << "findPrev(16) = " << A.findPrev(16) << endl;
	
	cout << endl;
	
	cout << "B = " << B << endl;
	cout << "C = " << C << endl;
	
	D = C.concat(B);
	
	cout << "D is C concat B = " << D << endl;
	
    return 0; 
}
