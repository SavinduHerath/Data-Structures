//=================================================INTERFACE==============================================
#include<iostream>
template<class T>

class DynamicArray
{
public:
	DynamicArray(int size, int stepSize);
	~DynamicArray();

	void addElement(T value, int position);
	T getValue(int position);
	int getArraySize();
	void printArray();
	T & operator [](int i);

private:
	T *arrPtr;
	T *newArray;
	int arrSize;
	int stepSize;
	DynamicArray();
	void resizeArray(int steps);
};

//============================================================IMPLEMENTATION===========================================

template <class T>
DynamicArray<T>::DynamicArray(int size, int stepSize1)
{
	arrPtr = new T[size];
	arrSize = size;
	stepSize = stepSize1;
}


template <class T>
DynamicArray<T>::~DynamicArray()
{
	delete[] arrPtr;
}


template <class T>
T & DynamicArray<T>::operator[](int j)
{
	return arrPtr[j];
}


template <class T>
void DynamicArray<T>::resizeArray(int steps)
{
	int newSize = arrSize + stepSize*steps;
	newArray = new T[newSize];
	memmove(newArray, arrPtr, arrSize*sizeof(T)); 
	//delete[] arrPtr;
	arrSize = newSize;
	arrPtr = newArray;
}


template <class T>
void DynamicArray<T>::addElement(T value, int position)
{
	if (this->arrSize <= position)
	{
		int noOfSteps = ((position - arrSize) / stepSize) + 1;
		resizeArray(noOfSteps);
		arrPtr[position] = value;
	}
	else
	{
		arrPtr[position] = value;
	}
}


template <class T>
T DynamicArray<T>::getValue(int position)
{
	return this->arrPtr[position];
}


template <class T>
int DynamicArray<T>::getArraySize()
{
	return this->arrSize;
}


template <class T>
void DynamicArray<T>::printArray()
{
	int len = this->arrSize;
	for (int i = 0; i < len; ++i)
	{
		std::cout << arrPtr[i];
	}
	std::cout << '\n';
}