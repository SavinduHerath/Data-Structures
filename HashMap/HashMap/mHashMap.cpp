#include "mHashMap.h"
#include <iostream>
#include <fstream>
#include <ctime>

int main()
{
	HashMap* MyHashMap = new HashMap(50000);
	//static char buffer[255];
	string s;
	ifstream infile("Dictionary(2).txt");
	clock_t startTime = clock();
	while (infile.good())
	{
		infile >> s;
		MyHashMap->insert(s); 
	}
	clock_t endTime = clock();

	/*string str = "Savindu";
	MyHashMap->insert(str);*/
	
	float timeTaken = float (endTime - startTime) / CLOCKS_PER_SEC;  //calculating the time taken
	cout << fixed <<"Time: " << timeTaken << endl;

	MyHashMap->collisionFile();   //writing the number of collisions for each index
	MyHashMap->~HashMap();			//calling the destructor
	return 0;
}