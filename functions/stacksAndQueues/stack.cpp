#ifdef STACKSANDQUEUES_STACK_H_
#include "stack.h"

template <typename T>
Stack<T>::Stack()
{
	stackArray.erase(stackArray.begin(), stackArray.end());
}

template <typename T>
Stack<T>::Stack(const Stack<T> &rhs)
{
	stackArray = rhs.stackArray;
}

template <typename T>
Stack<T>::~Stack()
{
	clear();
}

template <typename T>
const Stack<T> &Stack<T>::operator=(const Stack<T> &rhs)
{
	clear();
	stackArray = rhs.stackArray;
	return *this;
}

template <typename T>
bool Stack<T>::operator==(const Stack<T> &rhs) const
{
	if(stackArray == rhs.stackArray)
		return true;
	else
		return false;
}

template <typename T>
void Stack<T>::clear()
{
	stackArray.erase(stackArray.begin(), stackArray.end());
}

template <typename T>
void Stack<T>::push(const T &data)
{
	auto itr = stackArray.end();
	stackArray.insert(itr, data);
}

template <typename T>
T Stack<T>::pop()
{
	if(getSize() > 0)
	{
		auto itr = stackArray.end();
		T ret = *itr;
		stackArray.erase(stackArray.end() - 1);
		return ret;
	}
}

template <typename T>
T Stack<T>::top()
{
	if(getSize() > 0)
	{
		auto itr = (stackArray.end() - 1);
		return *itr;
	}
}

template <typename T>
uint Stack<T>::getSize()
{
	return stackArray.size();
}

template <typename T>
bool Stack<T>::isEmpty()
{
	if(getSize() == 0)
		return true;

	else
		return 0;
}

template <typename T>
void Stack<T>::print()
{
	std::cout << "Size is: " << getSize() << std::endl;

	if(getSize() == 0)
		return;

	for(auto itr : stackArray)
	{
		std::cout << itr << " <- ";
	}

	std::cout << "top\n" << std::endl;
}

#endif
