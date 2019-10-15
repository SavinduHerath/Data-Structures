#pragma once
#include <list>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class HashMap
{
public:
	HashMap(int tableSize);
	void insert(string &key);
	~HashMap();
	void collisionFile();

private:
	int i_TableSize;
	list<string>** listPtrList;
	void GetIndex(unsigned long &ulIndex, const char *zKey1);
};

HashMap::HashMap(int tableSize)
{
	i_TableSize = tableSize;
	listPtrList = new list<string>*[tableSize];
	int i = 0;
	while (i < tableSize)
	{
		listPtrList[i] = nullptr;
		++i;
	}
}

HashMap::~HashMap()
{
	long hashKey = 0;
	while (hashKey < i_TableSize)
	{
		delete listPtrList[hashKey];
		++hashKey;
	}
	delete[] listPtrList;
}

void HashMap::GetIndex(unsigned long &ulIndex, const char *zKey1)
{
	ulIndex = 0;
	char *acIndex = (char*)&ulIndex;

	int i;
	for (i = 0; zKey1[i] != '\0'; i++)
	{
		int n = i % 4;
		acIndex[n] = acIndex[n] ^ zKey1[i];
	}

	ulIndex = ulIndex % i_TableSize;
}

void HashMap::insert(string &key)
{
	unsigned long hashKey = 0;
	GetIndex(hashKey, key.c_str());
	if (listPtrList[hashKey] == nullptr)
	{
		listPtrList[hashKey] = new list<string>;
	}
	listPtrList[hashKey]->push_back(key);
}

void HashMap::collisionFile()
{
	long long hashKey = 0;
	/*cout << listPtrList[hashKey] << endl;
	for (string s : *listPtrList[hashKey])
	{
		cout << s << endl;
	}*/

	ofstream ofile("CollisionFile.txt");
	while (hashKey < i_TableSize)
	{
		//int maxCollisions = 0;

		if (listPtrList[hashKey] != nullptr)
		{
			ofile << hashKey << " : " << (listPtrList[hashKey])->size() << endl;
		}
		else
		{
			ofile << hashKey << " : " << "0" << endl;
		}
		++hashKey;
	}
	ofile.close();
}