#pragma once
#include <iostream>
using namespace std;

struct msg {
	int msgId;
	int value;
};

class CircularArray
{
public:
	CircularArray(int size);
	~CircularArray();

	void printArray();
	void push(msg newMsg);
	msg pop(); // Delete the value
	msg peekAt(int index);
	msg getNext();

private:
	int front;
	int rear;
	msg* arrPtr;
	int arrSize;
	void moveForwardFR(int& f, int& r);
	void moveBackFR(int& f, int& r);
	void forwardF();
	void forwardR();
	int i = 1;
};

CircularArray::CircularArray(int size)
{
	arrPtr = new msg[size];
	front = 0;
	rear = 0;
	arrSize = size;
}

CircularArray::~CircularArray()
{
}

void CircularArray::push(msg newMsg)
{
	arrPtr[rear] = newMsg;
	moveForwardFR(front,rear);
}

void CircularArray::moveForwardFR(int& f, int& r)
{
	if (r == arrSize-1 && f == 0)
	{
		f = 1; r = 0;
	}
	else if (f == arrSize - 1 && r == arrSize - 2)
	{
		f = 0; r = arrSize - 1;
	}
	else if (f>r)
	{
		f += 1;
		r += 1;
	}
	else
	{
		//f += 1;  
		r += 1;
	}
}

void CircularArray::moveBackFR(int& f, int& r)
{
	if (f == 0 && r == arrSize - 1)
	{
		f = arrSize - 1; r = arrSize - 2;
	}
	else if (f ==  1 && r == 0)
	{
		f = 0; r = arrSize - 1;
	}
	else
	{
		f -= 1; r -= 1;
	}
}

void CircularArray::forwardF()
{
	if (front == rear)
	{
		cout << "There's nothing to pop";
	}
	else
	{
		if (front == arrSize - 1)
		{
			front = 0;
		}
		else
		{
			front += 1;
		}
	}
}

void CircularArray::forwardR()
{
	if (rear == arrSize - 1)
	{
		rear = 0;
	}
	else
	{
		rear += 1;
	}
}

msg CircularArray::pop()
{
	msg temp = arrPtr[front-1];
	msg del = msg();
	del.msgId = 0;
	arrPtr[front - 1] = del;
	forwardF();
	//forwardR();
	return temp;
}

msg CircularArray::peekAt(int index)
{
	msg temp;
	if (index < arrSize)
	{
		if (rear < index)
		{
			int newIndex = index - rear;
			temp = arrPtr[arrSize - newIndex];
		}
		else
		{
			temp = arrPtr[rear - index];
		}
	}
	else
	{
		cout << "Peeking not possible";
	}
	return temp;
}

msg CircularArray::getNext()
{
	msg temp1;
	if (front != i)
	{
		temp1 = peekAt(i);
		++i;
	}
	else
	{
		cout << "End of list" << endl;
	}
	return temp1;
	
}

void CircularArray::printArray()
{
	//int len = this->arrSize;
	for (int i = 0; i < arrSize; ++i)
	{
		std::cout << arrPtr[i].msgId << ", ";
	}
	std::cout << '\n';
}