// DynamicArray.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "DynamicArray.h"
#include<cstdio>
#include<string>
#include<iostream>

using namespace std;

int main()
{
	DynamicArray<string> myArray(3, 5);
	myArray.printArray();				//empty array
	std::cout << "Array size: " << myArray.getArraySize() << endl;
	std::cout << '\n';
	std::cout << myArray.getValue(0);	//get the 1st element
	std::cout << '\n';
	myArray.addElement("S", 0);			//adding elements
	myArray.addElement("a", 1);
	myArray.addElement("v", 2);
	myArray.printArray();
	myArray.addElement("i", 3);
	myArray.addElement("n", 4);
	myArray.printArray();
	std::cout << '\n';
	std::cout << "5th element: " << myArray.getValue(4)<<std::endl;
	std::cout << '\n';
	myArray.addElement("d", 5);
	myArray.addElement("u", 6);
	std::cout << "Array size: " << myArray.getArraySize() << endl;
	myArray.addElement("H", 11);
	myArray.printArray();
	std::cout << '\n';
	std::cout << "Array size: " << myArray.getArraySize() << endl;				//get array size
	std::cout << '\n';
	std::cout << "3rd element: " << myArray[2] << endl;			//operator overloading
	return 0;
}