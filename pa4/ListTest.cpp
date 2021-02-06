//-----------------------------------------------------------------------------
//
// Chantel Gee, chmagee
// 2021 Winter CSE 101 pa4
// 
// ListTest.cpp
// Test file for List ADT
// 
/*{
		cout << "Error : A = B" << endl;
	}
*/
//-----------------------------------------------------------------------------
#include<iostream>
#include<string>
#include"List.h"

using namespace std;

int main() 
{ 
	List A, B, C;
	A.clear();
	B.clear();
	C.clear();
	
	cout << "Empty_size:" << endl;
	if (A.size() != 0) {
	cout << "Error : size 0" << endl;
	}
	cout << "InsertAfter_size:" << endl;
	A.insertAfter(1);
	A.insertAfter(2);
	A.insertAfter(3);
	A.insertAfter(5);
	A.insertAfter(12);
	if (A.size() != 5) {
	cout << "Error : size 5" << endl;
	}
	A.clear();
	B.clear();
	C.clear();
	cout << "InsertBefore_size:" << endl;

	A.insertBefore(1);
	A.insertBefore(2);
	A.insertBefore(3);
	A.insertBefore(5);
	A.insertBefore(12);
	if (A.size() != 5) {
	cout << "Error : size 5" << endl;
	}
	A.clear();
	B.clear();
	C.clear();
	cout << "EraseAfter_size:" << endl;
	A.insertBefore(1);
	A.insertBefore(2);
	A.insertBefore(3);
	A.insertBefore(5);
	A.insertBefore(12);

	A.movePrev();
	A.eraseAfter();
	if (A.size() != 4) {
	cout << "Error : size 4" << endl;
	}
	A.findPrev(2);
	A.eraseAfter();
	if (A.size() != 3) {
	cout << "Error : size 3" << endl;
	}
	A.clear();
	B.clear();
	C.clear();
	cout << "EraseBefore_size:" << endl;
	A.insertAfter(1);
	A.insertAfter(2);
	A.insertAfter(3);
	A.insertAfter(5);
	A.insertAfter(12);

	A.moveNext();
	A.eraseBefore();
	if (A.size() != 4) {
	cout << "Error : size 4" << endl;
	}
	A.findNext(2);
	A.eraseBefore();
	if (A.size() != 3) {
		cout << "Error : size 3" << endl;
	}
	A.clear();
	B.clear();
	C.clear();
	cout << "Concat_size:" << endl;
	A.insertAfter(1);
	A.insertAfter(2);
	A.insertAfter(3);
	B.insertAfter(4);
	B.insertAfter(5);
	B.insertAfter(6);

	C = A.concat(B);
	if (C.size() != 6) {
		cout << "Error : size 6" << endl;
	}
	A.clear();
	B.clear();
	C.clear();
	cout << "Cleanup_size:" << endl;
	A.insertAfter(1);
	A.insertAfter(2);
	A.insertAfter(3);
	A.insertAfter(1);
	A.insertAfter(2);
	A.insertAfter(1);
	A.cleanup();
	if (A.size() != 3) {
		cout << "Error : size 3" << endl;
	}
	A.clear();
	B.clear();
	C.clear();
	cout << "EmptyList_position:" << endl;
	if (A.position() != 0) {
		cout << "Error : position 0" << endl;
	}
	A.clear();
	B.clear();
	C.clear();
	cout << "MoveFront_position:" << endl;
	A.insertBefore(1);
	A.insertBefore(5);
	A.insertBefore(16);
	A.insertBefore(176);
	A.insertBefore(3214);
	A.moveFront();
	if (A.position() != 0) {
		cout << "Error : position 0" << endl;
	}
	A.clear();
	B.clear();
	C.clear();
	cout << "MoveBack_position:" << endl;
	A.insertAfter(1);
	A.insertAfter(5);
	A.insertAfter(16);
	A.insertAfter(176);
	A.insertAfter(3214);
	A.moveBack();
	if (A.position() != 5) {
		cout << "Error : position 5" << endl;
	}
	A.clear();
	B.clear();
	C.clear();
	cout << "MoveNext_position:" << endl;
	A.insertAfter(3214);
	A.insertAfter(176);
	A.insertAfter(16);
	A.insertAfter(5);
	A.insertAfter(1);
	A.moveNext();
	A.moveNext();
	if (A.position() != 2) {
		cout << "Error : position 2" << endl;
	}
	A.moveNext();
	A.moveNext();
	A.moveNext();
	if (A.position() != 5) {
		cout << "Error : position 5" << endl;
	}
	A.clear();
	B.clear();
	C.clear();
	cout << "MovePrev_position:" << endl;
	A.insertBefore(1);
	A.insertBefore(5);
	A.insertBefore(16);
	A.insertBefore(176);
	A.insertBefore(3214);
	A.movePrev();
	A.movePrev();
	if (A.position() != 3) {
		cout << "Error : position 3" << endl;
	}
	A.movePrev();
	A.movePrev();
	A.movePrev();
	if (A.position() != 0) {
		cout << "Error : position 0" << endl;
	}
	A.clear();
	B.clear();
	C.clear();
	cout << "InsertAfter_position:" << endl;
	A.insertAfter(200);
	A.insertAfter(176);
	A.insertAfter(16);
	A.insertAfter(5);
	A.insertAfter(1);
	if (A.position() != 0) {
		cout << "Error : position 0" << endl;
	}
	A.moveBack();
	A.insertAfter(225);
	if (A.position() != 5) {
		cout << "Error : position 5" << endl;
	}
	A.insertAfter(255);
	A.moveBack();
	if (A.position() != 7) {
		cout << "Error : position 7" << endl;
	}
	A.clear();
	B.clear();
	C.clear();
	cout << "InsertBefore_position:" << endl;
	A.insertBefore(1);
	A.insertBefore(5);
	A.insertBefore(16);
	A.insertBefore(176);
	A.insertBefore(200);
	if (A.position() != 5) {
		cout << "Error : position 5" << endl;
	}

	A.moveFront();
	A.insertBefore(225);
	if (A.position() != 1) {
		cout << "Error : position 1" << endl;
	}
	A.insertBefore(255);
	A.moveFront();
	if (A.position() != 0) {
		cout << "Error : position 0" << endl;
	}
	A.clear();
	B.clear();
	C.clear();
	cout << "FindNext_position:" << endl;
	A.insertAfter(16);
	A.insertAfter(200);
	A.insertAfter(176);
	A.insertAfter(16);
	A.insertAfter(5);
	A.insertAfter(1);
	A.findNext(16);
	if (A.position() != 3) {
		cout << "Error : position 3" << endl;
	}
	A.movePrev();
	A.insertBefore(225);
	if (A.position() != 3) {
		cout << "Error : position 3" << endl;
	}
	A.moveNext();
	A.findNext(16);
	if (A.position() != 7) {
		cout << "Error : position 7" << endl;
	}
	A.moveFront();
	A.findNext(16);
	if (A.position() != 4) {
		cout << "Error : position 4" << endl;
	}
	A.clear();
	B.clear();
	C.clear();
	cout << "FindPrev_position:" << endl;
	A.insertBefore(1);
	A.insertBefore(5);
	A.insertBefore(16);
	A.insertBefore(176);
	A.insertBefore(200);
	A.insertBefore(16);
	A.findPrev(16);
	if (A.position() != 5) {
		cout << "Error : position 5" << endl;
	}
	A.moveNext();
	A.insertAfter(225);
	if (A.position() != 6) {
		cout << "Error : position 6" << endl;
	}
	A.movePrev();
	A.findPrev(16);
	if (A.position() != 2) {
		cout << "Error : position 2" << endl;
	}
	A.moveBack();
	A.findPrev(16);
	if (A.position() != 5) {
		cout << "Error : position 5" << endl;
	}
	A.clear();
	B.clear();
	C.clear();
	cout << "EraseAfter_position:" << endl;
	A.insertAfter(200);
	A.insertAfter(176);
	A.insertAfter(15);
	A.insertAfter(10);
	A.insertAfter(5);
	A.findNext(15);
	A.eraseAfter();
	if (A.position() != 3) {
		cout << "Error : position 3" << endl;
	}
	A.insertAfter(175);
	A.eraseAfter();
	if (A.position() != 3) {
		cout << "Error : position 3" << endl;
	}
	A.insertBefore(50);
	A.insertBefore(15);
	if (A.position() != 5) {
		cout << "Error : position 5" << endl;
	}
	A.findPrev(15);
	A.eraseAfter();
	if (A.position() != 4) {
		cout << "Error : position 4" << endl;
	}
	A.findPrev(15);
	if (A.position() != 2) {
		cout << "Error : position 2" << endl;
	}
	A.moveFront();
	A.eraseAfter();
	A.eraseAfter();
	A.eraseAfter();
	A.eraseAfter();
	A.eraseAfter();
	if (A.position() != 0) {
		cout << "Error : position 0" << endl;
	}
	A.clear();
	B.clear();
	C.clear();
	cout << "EraseBefore_position:" << endl;
	A.insertBefore(5);
	A.insertBefore(10);
	A.insertBefore(15);
	A.insertBefore(176);
	A.insertBefore(200);
	A.findPrev(15);
	A.eraseBefore();
	if (A.position() != 1) {
		cout << "Error : position 1" << endl;
	}
	A.insertAfter(175);
	A.eraseBefore();
	if (A.position() != 0) {
		cout << "Error : position 0" << endl;
	}
	A.insertBefore(15);
	A.insertBefore(50);
	if (A.position() != 2) {
		cout << "Error : position 2" << endl;
	}
	A.findNext(15);
	A.eraseBefore();
	if (A.position() != 3) {
		cout << "Error : position 3" << endl;
	}
	A.findPrev(15);
	if (A.position() != 0) {
		cout << "Error : position 0" << endl;
	}
	A.moveBack();
	if (A.position() != 5) {
		cout << "Error : position 5" << endl;
	}
	A.eraseBefore();
	A.eraseBefore();
	A.eraseBefore();
	A.eraseBefore();
	A.eraseBefore();
	if (A.position() != 0) {
		cout << "Error : position 0" << endl;
	}
	A.clear();
	B.clear();
	C.clear();
	cout << "Cleanup_position:" << endl;
	A.insertBefore(1);
	A.insertBefore(2);
	A.insertBefore(2);
	A.insertBefore(1);
	A.insertBefore(2);
	A.insertBefore(3);
	A.insertBefore(1);
	A.findPrev(3);
	A.cleanup();
	if (A.position() != 2) {
		cout << "Error : position 2" << endl;
	}
	B.insertBefore(1);
	B.insertBefore(2);
	B.insertBefore(2);
	B.insertBefore(1);
	B.insertBefore(2);
	B.insertBefore(3);
	B.insertBefore(1);
	B.findPrev(3);
	B.movePrev();
	B.cleanup();
	if (B.position() != 2) {
		cout << "Error : position 2" << endl;
	}
	A.clear();
	B.clear();
	C.clear();
	cout << "Concat_position:" << endl;
	A.insertBefore(1);
	A.insertBefore(2);
	A.insertBefore(3);
	B.insertBefore(4);
	B.insertBefore(5);
	B.insertBefore(6);

	C = A.concat(B);
	if (C.position() != 0) {
		cout << "Error : position 0" << endl;
	}
	A.clear();
	B.clear();
	C.clear();
	cout << "Assign_equals:" << endl;
	A.insertAfter(2);
	A.insertAfter(1);
	B = A;
	if (!A.equals(B)) {
		cout << "Error : A = B" << endl;
	}
	A.clear();
	B.clear();
	C.clear();
	cout << "InsertAfter_equals:" << endl;
	A.insertAfter(2);
	A.insertAfter(1);
	B.insertAfter(2);
	if (A.equals(B)) {
		cout << "Error : A != B" << endl;
	}
	if (A == B) {
		cout << "Error : A != B" << endl;
	}
	B.insertAfter(1);
	if (!A.equals(B)) {
		cout << "Error : A = B" << endl;
	}
	A.clear();
	B.clear();
	C.clear();
	cout << "InsertBefore_equals:" << endl;
	A.insertBefore(2);
	A.insertBefore(1);
	B.insertAfter(2);
	if (A.equals(B)) {
		cout << "Error : A != B" << endl;
	}
	B.moveBack();
	B.insertBefore(1);
	if (!A.equals(B)) {
		cout << "Error : A = B" << endl;
	}
	A.clear();
	B.clear();
	C.clear();
	cout << "EraseAfter_equals:" << endl;
	A.insertBefore(1);
	A.insertAfter(2);
	B.insertBefore(1);
	B.insertBefore(2);
	A.eraseAfter();
	if (A.equals(B)) {
		cout << "Error : A != B" << endl;
	}
	B.movePrev();
	B.eraseAfter();
	if (!A.equals(B)) {
		cout << "Error : A = B" << endl;
	}
	A.insertAfter(5);
	B.insertAfter(5);
	A.eraseAfter();
	B.eraseAfter();
	if (!A.equals(B)) {
		cout << "Error : A = B" << endl;
	}
	A.clear();
	B.clear();
	C.clear();
	cout << "EraseBefore_equals:" << endl;
	A.insertBefore(1);
	A.insertAfter(2);
	B.insertBefore(1);
	B.insertBefore(2);
	A.eraseBefore();
	if (A.equals(B)) {
		cout << "Error : A != B" << endl;
	}
	B.movePrev();
	B.eraseBefore();
	if (!A.equals(B)) {
		cout << "Error : A = B" << endl;
	}
	A.insertBefore(5);
	B.insertBefore(5);
	A.eraseBefore();
	B.eraseBefore();
	if (!A.equals(B)) {
		cout << "Error : A = B" << endl;
	}

	A.clear();
	B.clear();
	C.clear();
	cout << "Cleanup_equals:" << endl;
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
	A.cleanup();
	if (A.equals(B)) {
		cout << "Error : A != B" << endl;
	}
	A.moveBack();
	A.eraseBefore();
	if (!A.equals(B)) {
		cout << "Error : A = B" << endl;
	}
	A.clear();
	B.clear();
	C.clear();
	cout << "Concat_equals:" << endl;
	A.insertBefore(1);
	A.insertAfter(3);
	A.insertAfter(2);
	B.insertBefore(3);
	B.insertBefore(2);
	B.insertBefore(1);
	C.insertAfter(1);
	C.insertAfter(2);
	C.insertAfter(3);
	C.insertAfter(3);
	C.insertAfter(2);
	C.insertAfter(1);
	if (!C.equals(A.concat(B))) {
		cout << "Error : C = AB" << endl;
	}
	A.clear();
	B.clear();
	C.clear();
	cout << "Empty_clear:" << endl;
	A.clear();
	if (A.size() != 0 || A.position() != 0) {
		cout << "Error : size 0, position 0" << endl;
	}
	A.clear();
	B.clear();
	C.clear();
	cout << "NonEmpty_clear:" << endl;
	A.insertAfter(1);
	A.insertAfter(2);
	A.insertAfter(3);
	A.insertBefore(5);
	A.insertBefore(12);
	A.clear();
	if (A.size() != 0 || A.position() != 0) {
		cout << "Error : size 0, position 0" << endl;
	}
	A.clear();
	B.clear();
	C.clear();
	cout << "MoveNext_value:" << endl;
	A.insertAfter(3215);
	A.insertAfter(176);
	A.insertAfter(22);
	A.insertAfter(5);
	A.insertAfter(1);
	A.moveNext();
	if (A.moveNext() != 5) {
		cout << "Error : moveNext 5" << endl;
	}
	A.eraseBefore();
	A.eraseBefore();
	A.moveNext();
	A.moveNext();
	if (A.moveNext() != 3215) {
		cout << "Error : moveNext 3215" << endl;
	}
	A.moveFront();
	if (A.moveNext() != 22) {
		cout << "Error : moveNext 22" << endl;
	}
	A.clear();
	B.clear();
	C.clear();
	cout << "MovePrev_value:" << endl;
	A.insertBefore(1);
	A.insertBefore(5);
	A.insertBefore(22);
	A.insertBefore(176);
	A.insertBefore(3215);
	A.movePrev();
	if (A.movePrev() != 176) {
		cout << "Error : movePrev 176" << endl;
	}
	A.eraseAfter();
	A.eraseAfter();
	A.movePrev();
	A.movePrev();
	if (A.movePrev() != 1) {
		cout << "Error : movePrev 1" << endl;
	}
	A.moveBack();
	if (A.movePrev() != 22) {
		cout << "Error : movePrev 22" << endl;
	}
	A.clear();
	B.clear();
	C.clear();
	cout << "PeekNext_value:" << endl;
	A.insertAfter(60);
	A.insertAfter(50);
	A.insertAfter(40);
	A.insertBefore(10);
	A.insertBefore(20);
	A.insertBefore(30);
	if (A.peekNext() != 40) {
		cout << "Error : peekNext 40" << endl;
	}
	A.eraseAfter();
	if (A.peekNext() != 50) {
		cout << "Error : peekNext 50" << endl;
	}
	A.moveFront();
	if (A.peekNext() != 10) {
		cout << "Error : peekNext 10" << endl;
	}
	A.clear();
	B.clear();
	C.clear();
	cout << "PeekPrev_value:" << endl;
	A.insertAfter(60);
	A.insertAfter(50);
	A.insertAfter(40);
	A.insertBefore(10);
	A.insertBefore(20);
	A.insertBefore(30);
	if (A.peekPrev() != 30) {
		cout << "Error : peekPrev 30" << endl;
	}
	A.eraseBefore();
	if (A.peekPrev() != 20) {
		cout << "Error : peekPrev 20" << endl;
	}
	A.moveBack();
	if (A.peekPrev() != 60) {
		cout << "Error : peekPrev 60" << endl;
	}
	A.clear();
	B.clear();
	C.clear();
	cout << "FindNext_value:" << endl;
	A.insertAfter(77);
	A.insertAfter(55);
	A.insertAfter(1);
	A.insertAfter(34);
	A.insertAfter(1);
	A.insertAfter(77);
	A.insertAfter(77);
	A.insertAfter(34);
	if (A.findNext(99) != -1) {
		cout << "Error : findNext -1" << endl;
	}
	if (A.position() != A.size()) {
		cout << "Error : position = size" << endl;
	}
	A.moveFront();
	if (A.findNext(1) != 4) {
		cout << "Error : findNext 4" << endl;
	}
	if (A.findNext(1) != 6) {
		cout << "Error : findNext 6" << endl;
	}
	if (A.findNext(1) != -1) {
		cout << "Error : findNext -1" << endl;
	}
	A.moveFront();
	A.cleanup();
	if (A.findNext(1) != 3) {
		cout << "Error : findNext 3" << endl;
	}
	if (A.findNext(1) != -1) {
		cout << "Error : findNext -1" << endl;
	}
	A.clear();
	B.clear();
	C.clear();
	cout << "FindPrev_value:" << endl;
	A.insertBefore(34);
	A.insertBefore(77);
	A.insertBefore(77);
	A.insertBefore(1);
	A.insertBefore(34);
	A.insertBefore(1);
	A.insertBefore(55);
	A.insertBefore(77);
	if (A.findPrev(99) != -1) {
		cout << "Error : findPrev -1" << endl;
	}
	if (A.position() != 0) {
		cout << "Error : findPrev 0" << endl;
	}
	A.moveBack();
	if (A.findPrev(1) != 5) {
		cout << "Error : findPrev 5" << endl;
	}
	if (A.findPrev(1) != 3) {
		cout << "Error : findPrev 3" << endl;
	}
	if (A.findPrev(1) != -1) {
		cout << "Error : findPrev -1" << endl;
	}
	A.moveBack();
	A.cleanup();
	if (A.findPrev(1) != 2) {
		cout << "Error : findPrev 2" << endl;
	}
	if (A.findPrev(1) != -1) {
		cout << "Error : findPrev -1" << endl;
	}
    return 0; 
}
