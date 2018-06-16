#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <iostream>
#include <vector>

using uint = unsigned int;

template <typename T>
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

template<typename T>
class LinkedList : public Node<T>
{
private:
	Node<T> *head;
	Node<T> *tail;
	uint size;

public:
	// constructors
	LinkedList();
	LinkedList(T val);

	void clear();
	~LinkedList();
	LinkedList(const LinkedList &rhs);
	LinkedList& operator=(const LinkedList &rhs);
	bool operator==(const LinkedList &rhs) const;

	// base linked list functionality
	void append(T val);
	void append(Node<T> *ptr);
	void remove(Node<T> *prev, Node<T> *del);
	void remove(Node<T> *del);
	Node<T> *returnHead();
	Node<T> *returnTail();
	bool findInVec(std::vector<T> vec, T value);

	// extra
	void print();
	void removeDuplicates();
	void removeDuplicatesSelfContained();

	bool palindromeRecursive();
	void palindromeRecursive(Node<T> *&snap, Node<T> *itr, bool &cond, bool &midPt);

	uint findKthToLast(uint k);
	uint findKthToLastRecursive(uint k);
	Node<T>* findKthToLastRecursive(Node<T>* itr, uint k, uint &count);

	uint intersectingLists(LinkedList a, LinkedList b);

	Node<T> loopDetection();

};

#include "linkedList.cpp"
#endif /* LINKEDLIST_H_ */
