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
	List A, B;
	
	A.insertBefore(3);
	A.insertBefore(3);
	A.insertBefore(1);
	A.insertBefore(3);
	A.insertBefore(2);
	A.insertBefore(2);
	A.insertBefore(1);
	A.insertBefore(4);
	B.insertBefore(3);
	B.insertBefore(1);
	B.insertBefore(2);
	if (A.equals(B)) {
		cout << "Error : A != B" << endl;
	}
	cout << "A = " << A << endl;
	cout << "B = " << B << endl;
	A.cleanup();
	cout << "A = " << A << endl;
	cout << "B = " << B << endl;
	if (A.equals(B)) {
		cout << "Error : A != B" << endl;
	}
	A.moveBack();
	A.eraseBefore();
	if (!A.equals(B)) {
		cout << "Error : A = B" << endl;
	}
    return 0; 
}
