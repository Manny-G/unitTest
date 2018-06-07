#ifndef SINGLYLINKEDLIST_H_
#define SINGLYLINKEDLIST_H_

#include <iostream>

template<class T>
class singlyLinkedList
{
public:
	singlyLinkedList();

	singlyLinkedList(T val);

	void append(T val);

	void remove(T val);

	void print();

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

		T getNodeVal()
		{
			return data;
		}

		void setNodeVal(T val)
		{
			data = val;
		}

		Node* getNodeNextPtr()
		{
			return next;
		}

		void setNodeNextPtr(Node* ptr)
		{
			next = ptr;
		}

	private:
		T data;
		Node *next;
	};

	Node *head;
};

#include "singlyLinkedList.cpp"

#endif /* SINGLYLINKEDLIST_H_ */
