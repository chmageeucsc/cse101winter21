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

void shuffle(List& D) {
	List B, C;
	
	D.moveFront();
	if (D.size() > 1) {
		for (int i = 1; i <= D.size()/2; i++){
			B.insertBefore(i);
		}
		
		cout << endl;
		
		for (int i = D.size()/2+1; i <= D.size(); i++){
			C.insertBefore(i);
		}
		cout << "B = " << B << endl;
		cout << "C = " << C << endl;
	}
	else {
		B.insertBefore(1);
		cout << "B = " << B << endl;
		cout << "C = " << endl;
	}
}

int main(int argc, char** argv) 
{ 
	List D;
	
	for(int i=1; i<=5; i++){
      D.insertBefore(i);
   }
	shuffle(D);
  
    return 0; 
}
