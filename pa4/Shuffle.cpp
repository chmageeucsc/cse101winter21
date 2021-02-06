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
#include<iomanip>
#include<string>
#include"List.h"

using namespace std;

void shuffle(List& D) {
	List B, C;
	D.moveFront();
	C.moveFront();
	B.moveFront();
	if (D.size() > 1) {
		for (D.position(); D.position() < D.size()/2; D.moveNext()){
			B.insertBefore(D.peekNext());
		}
		
		for (D.position(); D.position() < D.size(); D.moveNext()){
			C.insertBefore(D.peekNext());
		}
		
		D.clear();
		C.moveFront();
		B.moveFront();
		while (B.isEmpty() != true) {
			D.insertBefore(C.peekNext());
			D.insertBefore(B.peekNext());
			C.eraseAfter();
			B.eraseAfter();
		}
		if (C.isEmpty() != true) {
			D.insertBefore(C.peekNext());
			C.eraseAfter();
		}
	}
	else {
		D = D;
	}
}

int main(int argc, char** argv) 
{ 
	if (argc == 1) {
		cout << "Error: Only program included." << endl;
	}
	else if (argc == 2) {
		cout << "deck size       shuffle count" << endl;
		cout << "------------------------------" << endl;
		int x = atoi(argv[1]);
		for (int i = 1; i <= x; i++) {
			List D, E;
			int count = 1;
			for (int j = 1; j <= i; j++) {
				D.insertBefore(j);
				E.insertBefore(j);
			}
			shuffle(D);
			while (D.equals(E) == false) {
				shuffle(D);
				count++;
			}
			if (i < 10) {
				std::cout << std::internal << " " << i << setw(15) << " " << count << endl;
			}
			else {
				if (i != x) {
					std::cout << std::internal << " " << i << setw(14) << " " << count << endl;
				}
				else {
					std::cout << std::internal << " " << i << setw(14) << " " << count;
				}
			}
		}
	}
    else {
		cout << "Error: Too many arguments included." << endl;
	}
  
    return 0; 
}
