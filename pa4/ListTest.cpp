//-----------------------------------------------------------------------------
// ListTest.cpp
// A test client for List ADT
//-----------------------------------------------------------------------------
#include<iostream>
#include<string>
#include"List.h"

using namespace std;

int main(){
	
	int i;
	List A, B, C, D, E;

	for(i=1; i<=10; i++){
		A.insertAfter(i);
		B.insertAfter(11-i);
		C.insertBefore(i);
		D.insertBefore(11-i);
	}
	
	B.moveBack();

	cout << endl << "B: ";
	for(i=1; i<=7; i++){
		cout << B.movePrev() << " ";
	}
	cout << endl << "B.position() = " << B.position() << endl;

	return(0);
}
