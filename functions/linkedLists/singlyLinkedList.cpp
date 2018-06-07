#ifdef SINGLYLINKEDLIST_H_
#include "singlyLinkedList.h"

template<class T>
singlyLinkedList<T>::singlyLinkedList()
{
	head = new Node();
}

template<class T>
singlyLinkedList<T>::singlyLinkedList(T val)
{
	head = new Node(val);
}

template<class T>
void singlyLinkedList<T>::append(T val)
{
	Node *itr = new Node(val, head);
	head = itr;
}

template<class T>
void singlyLinkedList<T>::remove(T val)
{
	Node* lagPtr = head;
	Node* leadPtr = head;

	if(leadPtr -> getNodeVal() == val)
	{
		if(leadPtr -> getNodeNextPtr() != nullptr)
		{
			leadPtr = leadPtr -> getNodeNextPtr();
			head = leadPtr;
			delete lagPtr;
		}

		else
		{
			delete head;
		}

	}

	// check if the list is only a single element
	while(leadPtr -> getNodeNextPtr() != nullptr)
	{
		leadPtr = leadPtr -> getNodeNextPtr();

		if(leadPtr -> getNodeVal() == val)
		{
			leadPtr = leadPtr -> getNodeNextPtr();
			delete lagPtr -> getNodeNextPtr();
			lagPtr -> setNodeNextPtr(leadPtr);
			break;
		}
		lagPtr = lagPtr -> getNodeNextPtr();
	}
}

template<class T>
void singlyLinkedList<T>::print()
{
	Node* ptr = head;

	while(ptr != nullptr)
	{
		std::cout << ptr -> getNodeVal() << " ";
		ptr = ptr -> getNodeNextPtr();
	}

	std::cout << std::endl;
}

#endif


