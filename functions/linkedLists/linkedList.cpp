
#ifdef LINKEDLIST_H_
#include "linkedList.h"

template<typename T>
LinkedList<T>::LinkedList()
{
	head = nullptr;
	tail = nullptr;
	size = 0;
}

template<typename T>
LinkedList<T>::LinkedList(T val)
{
	head = new Node<T>(val);
	tail = head;
	size = 1;
}

template<typename T>
void LinkedList<T>::append(T val)
{
	Node<T> *itr = new Node<T>(val);
	if(head != nullptr)
	{
		itr -> next = head;
		head -> prev = itr;
	}

	else
		tail = itr;

	head = itr;
	size++;
}

template<typename T>
void LinkedList<T>::remove(Node<T> *prev, Node<T> *del)
{
	if(del == head)
	{
		if(del -> next != nullptr)
		{
			prev = del -> next;
			del -> next = nullptr;
			delete del;
			del = nullptr;
			head = prev;
			head -> prev = nullptr;
		}

		else
		{
			head -> next = nullptr;
			head -> prev = nullptr;
			delete head;
			head = nullptr;
			tail = head;
		}
	}

	else if(del == tail)
	{
		prev = del -> prev;
		prev -> next = del -> next;
		del -> prev = nullptr;
		delete del;
		del = nullptr;
		tail = prev;
	}

	else
	{
		prev -> next = del -> next;
		del -> next -> prev = prev;
		del -> next = nullptr;
		del -> prev = nullptr;
		delete del;
		del = nullptr;
	}

	size--;
	return;
}

template<typename T>
void LinkedList<T>::remove(Node<T> *del)
{
	Node<T> *prev = head;
	if(del == head)
	{
		if(del -> next != nullptr)
		{
			prev = del -> next;
			del -> next = nullptr;
			delete del;
			del = nullptr;
			head = prev;
			head -> prev = nullptr;
		}

		else
		{
			head -> next = nullptr;
			head -> prev = nullptr;
			delete head;
			head = nullptr;
			tail = head;
		}
	}

	else if(del == tail)
	{
		prev = del -> prev;
		prev -> next = del -> next;
		del -> prev = nullptr;
		delete del;
		del = nullptr;
		tail = prev;
	}

	else
	{
		prev = del -> prev;
		prev -> next = del -> next;
		del -> next -> prev = prev;
		del -> next = nullptr;
		del -> prev = nullptr;
		delete del;
		del = nullptr;
	}

	size--;
	return;
}

template <typename T>
Node<T> *LinkedList<T>::returnHead()
{
	return head;
}

template <typename T>
Node<T> *LinkedList<T>::returnTail()
{
	return tail;
}

template<typename T>
void LinkedList<T>::print()
{
	Node<T>* ptr = head;

	std::cout << "Current size: " << size << std::endl;
	std::cout << "Forward:" << std::endl;

	while(ptr != nullptr)
	{
		std::cout << ptr -> data << " -> ";
		ptr = ptr -> next;
	}

	std::cout << "x" << std::endl;

	ptr = tail;
	std::cout << "Backward:" << std::endl;
	while(ptr != nullptr)
	{
		std::cout << ptr -> data << " -> ";
		ptr = ptr -> prev;
	}
	std::cout << "x\n" << std::endl;
}

template<typename T>
bool LinkedList<T>::findInVec(std::vector<T> vec, T value)
{
	for(auto i : vec)
	{
		if(i == value)
			return true;
	}

	return false;
}

template<typename T>
void LinkedList<T>::removeDuplicates()
{
	Node<T> *lead = head, *lag = lead;
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

template <typename T>
void LinkedList<T>::removeDuplicatesSelfContained()
{
	Node<T> *itr = head, *loop, *decoy;
	while(itr != nullptr)
	{
		loop = itr;
		while (loop != nullptr)
		{
			if(itr != loop)
			{
				if(itr -> data == loop -> data)
				{
					decoy = loop;
					loop = loop -> next;
					remove(decoy);
					continue;
				}
			}

			loop = loop -> next;
		}

		itr = itr -> next;
	}
}

template <typename T>
bool LinkedList<T>::palindromeRecursive()
{
	bool midPt = false, cond = true;
	Node<T> *itr = head, *snap = head;
	palindromeRecursive(snap, itr, cond, midPt);
	return cond;
}

template <typename T>
void LinkedList<T>::palindromeRecursive(Node<T> *&snap, Node<T> *itr, bool &cond, bool &midPt)
{
	if(itr != nullptr && itr -> next != nullptr)
		palindromeRecursive(snap, itr -> next, cond, midPt);

	if(cond == false || midPt == true)
		return;

	if(snap == itr || snap -> next == itr)
		midPt = true;

	if(midPt == true)
	{
		if(itr == snap)
			return;

		else if(itr -> data != snap -> data)
			cond = false;
	}

	else
	{
		if(itr -> data != snap -> data)
			cond = false;
		else
			snap = snap -> next;
	}

	return;
}

template <typename T>
uint LinkedList<T>::findKthToLast(uint k)
{
	Node<T> *ret = head, *loop = head;
	uint size = 0;

	while(loop != nullptr)
	{
		size++;
		loop = loop -> next;
	}

	for(uint i = 0 ; i < (size - k); i++)
		ret = ret -> next;

	return ret -> data;
}

template <typename T>
uint LinkedList<T>::findKthToLastRecursive(uint k)
{
	uint count = 0;
	Node<T> *itr = head;
	Node<T> *ret = findKthToLastRecursive(itr, k, count);
	return ret -> data;
}

template <typename T>
Node<T>* LinkedList<T>::findKthToLastRecursive(Node<T>* itr, uint k, uint &count)
{
	if(itr == nullptr)
		return nullptr;

	Node<T> *ret = findKthToLastRecursive(itr -> next, k, count);

	count++;
	if(count == k)
		ret = itr;

	return ret;
}

template <typename T>
uint LinkedList<T>::intersectingLists(LinkedList a, LinkedList b)
{
	Node<T> *aPtr = a.head, *bPtr = b.head;

	if(aPtr == nullptr || bPtr == nullptr)
		return 0;

	while(aPtr != nullptr)
	{
		bPtr = b.head;

		while(bPtr != nullptr)
		{
			if(&(*aPtr) == &(*bPtr))
				return aPtr -> data;

			bPtr = bPtr -> next;
		}

		aPtr = aPtr -> next;
	}

	return 0;
}

template <typename T>
Node<T> LinkedList<T>::loopDetection()
{
	Node<T> *slow = head, *fast = head;
	if (slow == nullptr)
		return nullptr;

	while(fast != nullptr && fast -> next != nullptr)
	{
			slow = slow -> next;
			fast = fast -> next -> next;
			if(slow == fast)
				break;
	}

	if(fast == nullptr || fast -> next == nullptr)
		return nullptr;

	slow = head;

	while(slow != fast)
	{
		slow = slow -> next;
		fast = fast -> next;
	}

	return slow;
}



#endif


