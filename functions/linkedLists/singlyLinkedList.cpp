#ifdef SINGLYLINKEDLIST_H_
#include "singlyLinkedList.h"

template<class T>
singlyLinkedList<T>::singlyLinkedList()
{
	head = nullptr;
	tail = nullptr;
	size = 0;
}

template<class T>
singlyLinkedList<T>::singlyLinkedList(T val)
{
	head = new Node(val);
	tail = head;
	size = 1;
}

template<class T>
void singlyLinkedList<T>::append(T val)
{
	Node *itr = new Node(val, head);
	head = itr;
	size++;
}

template<class T>
void singlyLinkedList<T>::remove(T val)
{
	Node* lagPtr = head;
	Node* leadPtr = head;

	if(leadPtr -> data == val)
	{
		if(leadPtr -> next != nullptr)
		{
			leadPtr = leadPtr -> next;
			head = leadPtr;
			delete lagPtr;
		}

		else
		{
			delete head;
			head = nullptr;
			tail = head;
		}

		size--;
		return;
	}

	// check if the list is only a single element
	while(leadPtr -> next != nullptr)
	{
		leadPtr = leadPtr -> next;

		if(leadPtr -> data == val)
		{
			if(leadPtr == tail)
			{
				tail = lagPtr;
			}

			leadPtr = leadPtr -> next;
			delete lagPtr -> next;
			lagPtr -> next = leadPtr;
			size --;
			return;
		}
		lagPtr = lagPtr -> next;
	}
}

template<class T>
void singlyLinkedList<T>::remove(Node *prev, Node *del)
{
	if(del == head)
	{
		if(del -> next != nullptr)
		{
			prev = del -> next;
			delete del;
			del = nullptr;
			head = prev;
		}

		else
		{
			delete head;
			head = nullptr;
			tail = head;
		}
	}

	else
	{
		prev -> next = del -> next;
		del -> next = nullptr;
		delete del;
		del = nullptr;
	}

	size--;
	return;
}

template<class T>
void singlyLinkedList<T>::print()
{
	Node* ptr = head;

	std::cout << "Current size: " << size << std::endl;

	while(ptr != nullptr)
	{
		std::cout << ptr -> data << " -> ";
		ptr = ptr -> next;
	}

	std::cout << "x" << std::endl;
}

template<class T>
bool singlyLinkedList<T>::findInVec(std::vector<T> vec, T value)
{
	for(auto i : vec)
	{
		if(i == value)
			return true;
	}

	return false;
}

template<class T>
void singlyLinkedList<T>::removeDuplicates()
{
	Node *lead = head, *lag = lead;
	std::vector<T> vec;

	if(lead == nullptr)
		return;
	else
	{
		vec.push_back(lead -> data);
		lead = lead -> next;
	}

	while(lead != nullptr)
	{
		if(!findInVec(vec, lead -> data))
		{
			vec.push_back(lead -> data);
			lead = lead -> next;
			lag = lag -> next;
		}

		else
		{
			remove(lag, lead);
			lead = lag -> next;
		}
	}
}

#endif


