#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <iostream>
#include <vector>

using uint = unsigned int;

namespace LL
{
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
}

template<typename T>
class LinkedList : public LL::Node<T>
{
private:
	LL::Node<T> *head;
	LL::Node<T> *tail;
	uint size;

public:
	// constructors
	LinkedList();
	LinkedList(T val);

	void clear();
	~LinkedList();
	LinkedList(const LinkedList &rhs);
	const LinkedList &operator=(const LinkedList &rhs);
	bool operator==(const LinkedList &rhs) const;

	// base linked list functionality
	void append(T val);
	void append(LL::Node<T> *ptr);
	void remove(LL::Node<T> *prev, LL::Node<T> *del);
	void remove(LL::Node<T> *del);
	LL::Node<T> *returnHead();
	LL::Node<T> *returnTail();
	bool findInVec(std::vector<T> vec, T value);
	uint getSize();

	// extra
	void print();
	void removeDuplicates();
	void removeDuplicatesSelfContained();

	bool palindromeRecursive();
	void palindromeRecursive(LL::Node<T> *&snap, LL::Node<T> *itr, bool &cond, bool &midPt);

	uint findKthToLast(uint k);
	uint findKthToLastRecursive(uint k);
	LL::Node<T>* findKthToLastRecursive(LL::Node<T>* itr, uint k, uint &count);

	uint intersectingLists(LinkedList a, LinkedList b);

	LL::Node<T> loopDetection();

};

#include "linkedList.cpp"
#endif /* LINKEDLIST_H_ */
