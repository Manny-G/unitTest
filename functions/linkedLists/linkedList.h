#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <iostream>
#include <vector>

using uint = unsigned int;

template<typename T>
class LinkedList
{
private:
	class Node
	{
	public:
		Node() : data(0), next(nullptr), prev(nullptr)
		{

		}

		Node(T val) : data(val), next(nullptr), prev(nullptr)
		{

		}

		Node(T val, Node* nextPtr) : data(val), next(nextPtr), prev(nullptr)
		{

		}

		T data;
		Node *next;
		Node *prev;
	};

	Node *head;
	Node *tail;
	uint size;

public:
	// constructors
	LinkedList();
	LinkedList(T val);

	bool operator==(const LinkedList& rhs) const
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
	void remove(Node *prev, Node *del);
	void remove(Node *del);
	bool findInVec(std::vector<T> vec, T value);

	// extra
	void print();
	void removeDuplicates();
	void removeDuplicatesSelfContained();

	bool palindromeRecursive();
	void palindromeRecursive(Node *&snap, Node *itr, bool &cond, bool &midPt);

};

#include "linkedList.cpp"
#endif /* LINKEDLIST_H_ */
