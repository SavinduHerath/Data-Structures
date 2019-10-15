//=========================================== INTERFACE ==========================================
#include<iostream>

template<class T>
struct Node {
	Node *nextNode;
	T dataValue;
};

template<class T>
class singleLinkedList
{
public:
	singleLinkedList();
	~singleLinkedList();

	void addElement(T value);
	void addElementAt(T insertValue, int insertPosition);
	void removeElementAt(int removePosition);
	void updateElementAt(T updateValue, int updatePosition);
	void empty();
	void printList();

private:
	Node<T> *head;
	int listCounter();
};

//===================================== IMPLEMENTATION ===========================================
template<class T>
singleLinkedList<T>::singleLinkedList()
{
	head = nullptr;
}

template<class T>
singleLinkedList<T>::~singleLinkedList()
{
}

template<class T>
void singleLinkedList<T>::addElement(T value)
{
	if (head == nullptr)
	{
		head = new Node<T>;
		head->dataValue = value;
		head->nextNode = nullptr;
	}
	else
	{
		Node<T> *temp1 = head;
		while (temp1->nextNode != nullptr)
		{
			temp1 = temp1->nextNode;
		}
		temp1->nextNode = new Node<T>;
		temp1->nextNode->dataValue = value;
		temp1->nextNode->nextNode = nullptr;
	}
}

template<class T>
void singleLinkedList<T>::addElementAt(T insertValue, int insertPosition)
{
	if (listCounter() >= insertPosition)
	{
		if (insertPosition == 1)
		{
			Node<T> *temp7 = new Node<T>;
			temp7->dataValue = insertValue;
			temp7->nextNode = head;
			head = temp7;
		}
		else if (insertPosition == 2)
		{
			Node<T> *temp8 = new Node<T>;
			temp8->dataValue = insertValue;
			temp8->nextNode = head->nextNode;
			head->nextNode = temp8;
		}
		else
		{
			Node<T> *temp5 = head;
			for (int i = insertPosition; i > 2; --i)
			{
				temp5 = temp5->nextNode;
			}
			Node<T> *temp6 = new Node<T>;
			temp6->dataValue = insertValue;
			temp6->nextNode = temp5->nextNode;
			temp5->nextNode = temp6;
		}
	}
	else
	{
		cout << "invalid position" << endl;
	}
}

template<class T>
void singleLinkedList<T>::removeElementAt(int removePosition)
{
	if (listCounter() >= removePosition)
	{
		if (removePosition == 1)
		{
			Node<T> *temp3 = head;
			head = head->nextNode;
			delete temp3;
		}
		else if (removePosition == 2)
		{
			Node<T> *temp4 = head->nextNode;
			head->nextNode = head->nextNode->nextNode;
			delete temp4;
		}
		else
		{
			Node<T> *temp5 = head;
			for (int i = removePosition; i > 2; --i)
			{
				temp5 = temp5->nextNode;
			}
			Node<T> *temp6 = temp5->nextNode;
			temp5->nextNode = temp5->nextNode->nextNode;
			delete temp6;
		}
	}
	else
	{
		cout << "invalid position" << endl;
	}
}

template<class T>
void singleLinkedList<T>::updateElementAt(T updateValue, int updatePosition)
{
	if (listCounter() >= updatePosition)
	{
		if (updatePosition == 1)
		{
			head->dataValue = updateValue;
		}
		else
		{
			Node<T> *temp9 = head;
			for (int i = updatePosition; i > 1; --i)
			{
				temp9 = temp9->nextNode;
			}
			temp9->dataValue = updateValue;
		}
	}
	else
	{
		cout << "invalid position" << endl;
	}
}

template<class T>
void singleLinkedList<T>::empty()
{
	Node<T> *newHead = head;
	while (newHead!= nullptr)
	{
		newHead = head->nextNode;
		delete head;
		head = newHead;
	}
}

template<class T>
void singleLinkedList<T>::printList()
{
	Node<T> *temp2 = head;
	while (temp2 != nullptr)
	{
		std::cout << temp2->dataValue;
		temp2 = temp2->nextNode;
	}
	std::cout <<'\n';
}

template<class T>
int singleLinkedList<T>::listCounter()
{
	Node<T> *temp2 = head;
	int count = 0;
	while (temp2 != nullptr)
	{
		count += 1;
		temp2 = temp2->nextNode;
	}
	return count;
}