//-----------------------------------------------------------------------------
//
// Chantel Gee, chmagee
// 2021 Winter CSE 101 pa4
// 
// Shuffle.cpp
// Implementation file for Shuffle
// 
//-----------------------------------------------------------------------------
#include<iostream>
#include<string>
#include"List.h"

using namespace std;

void shuffle(List& D) {
	List A, B, C;

	for(int i=1; i<=17; i++){
		A.insertBefore(i);
	}
	A.moveFront();

	for (int i = 1; i <= A.size()/2; i++){
		B.insertBefore(i);
	}
	
	cout << endl;
	
	for (int i = A.size()/2+1; i <= A.size(); i++){
		C.insertBefore(i);
	}
	
	cout << "B = " << B << endl;
	cout << "C = " << C << endl;
}

int main(int argc, char** argv) 
{ 
	if (argc == 1) {
		cout << "Error: Only program included." << endl;
	}
	else if (argc == 2) {
		cout << argv[1] << endl;
	}
    else {
		cout << "Error: Too many arguments included." << endl;
	}
  
    return 0; 
}
