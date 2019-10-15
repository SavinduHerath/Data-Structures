
#include "CircularArray.h"
#include<cstdio>
#include<string>
#include<iostream>

using namespace std;

int main()
{
	CircularArray myArray(10);
	msg m1 = { 1,1 };
	msg m2 = { 2,2 };
	msg m3 = { 3,3 };
	msg m4 = { 4,4 };
	msg m5 = { 5,5 };
	msg m6 = { 6,6 };
	msg m7 = { 7,7 };
	msg m8 = { 8,8 };
	msg m9 = { 9,9 };
	msg m10 = { 10,10 };
	msg m11 = { 11,11 };
	//msg m7 = { 7,7 };
	//myArray.printArray();

	myArray.push(m1); //pushing messages to the msg array
	myArray.push(m2);
	myArray.push(m3);
	myArray.push(m4);
	myArray.push(m5);
	myArray.printArray();
	myArray.push(m6);
	myArray.push(m7);
	myArray.push(m8);
	myArray.push(m9);
	myArray.push(m10);
	myArray.push(m11);
	myArray.printArray();
	
	cout << endl;
	std::cout << myArray.pop().msgId <<endl; //poping the oldest message
	std::cout << myArray.pop().msgId << endl;
	myArray.printArray();

	std::cout << "PeekAt(3)" << myArray.peekAt(3).msgId << endl; //3rd latest message

	std::cout << myArray.getNext().msgId << endl;
	std::cout << myArray.getNext().msgId << endl;
	std::cout << myArray.getNext().msgId << endl;
	//std::cout << myArray.getNext().msgId << endl;
	/*std::cout << myArray.getNext().msgId << endl;
	std::cout << myArray.getNext().msgId << endl;
	std::cout << myArray.getNext().msgId << endl;*/
	return 0;
}