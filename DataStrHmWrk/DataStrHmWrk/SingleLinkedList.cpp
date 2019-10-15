//====================================== USAGE (MAIN) ==============================================
//
#include "stdafx.h"
#include "singleLinkedList.h"
#include<iostream>
#include<string>

using namespace std;

int main()
{
	singleLinkedList<char> list1;
	list1.printList();
	char s1[] = "Hello Single Linked List";
	for (char c:s1)
	{
		list1.addElement(c);			//adding elements
	}
	/*for (int i = 1; i < 10; i++)      **USE THIS PART FOR INTEGER LINKED LIST
	{
		list1.addElement(i);
		//list1.printList();
	}*/
	list1.printList();
	list1.updateElementAt('X',3);		//updating element @ 3
	list1.printList();
	list1.addElementAt('Y', 5);			//adding element @ 5
	list1.printList();
	list1.removeElementAt(6);
	list1.printList();
	list1.empty();		//empty the list
	list1.printList();	//print the empty list
	return 0;
}
