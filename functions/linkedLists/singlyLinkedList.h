#ifndef SINGLYLINKEDLIST_H_
#define SINGLYLINKEDLIST_H_

#include <iostream>
#include <vector>

using uint = unsigned int;

template<class T>
class singlyLinkedList
{
private:
	class Node
	{
	public:
		Node() : data(0), next(nullptr)
		{

		}

		Node(T val) : data(val), next(nullptr)
		{

		}

		Node(T val, Node* nextPtr) : data(val), next(nextPtr)
		{

		}

		T data;
		Node *next;
	};

	Node *head;
	Node *tail;
	uint size;

public:
	// constructors
	singlyLinkedList();
	singlyLinkedList(T val);

	bool operator==(const singlyLinkedList& rhs) const
	{
		Node *rPtr = rhs.head, *tPtr = this -> head;

		if( (rPtr == nullptr && tPtr != nullptr) || (rPtr != nullptr && tPtr == nullptr) )
			return false;

		while(rPtr != nullptr && tPtr != nullptr)
		{
			if(rPtr -> data != tPtr -> data)
				return false;

			rPtr = rPtr -> next;
			tPtr = tPtr -> next;

			if( (rPtr == nullptr && tPtr != nullptr) || (rPtr != nullptr && tPtr == nullptr) )
				return false;
		}

		return true;
	}

	// base linked list functionality
	void append(T val);
	void remove(T val);
	void remove(Node *prev, Node *del);
	bool findInVec(std::vector<T> vec, T value);

	// extra
	void print();
	void removeDuplicates();
};

#include "singlyLinkedList.cpp"

#endif /* SINGLYLINKEDLIST_H_ */
