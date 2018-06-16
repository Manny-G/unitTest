#ifdef STACKSANDQUEUES_QUEUE_H_
#include "queue.h"

template <typename T>
Queue<T>::Queue()
{
	queueArray.erase(queueArray.begin(), queueArray.end());
}

template <typename T>
Queue<T>::Queue(const Queue<T> &rhs)
{
	queueArray = rhs.queueArray;
}

template <typename T>
Queue<T>::~Queue()
{
	clear();
}

template <typename T>
const Queue<T> &Queue<T>::operator=(const Queue<T> &rhs)
{
	clear();
	queueArray = rhs.queueArray;
	return *this;
}

template <typename T>
bool Queue<T>::operator==(const Queue<T> &rhs) const
{
	if(queueArray == rhs.queueArray)
		return true;
	else
		return false;
}

template <typename T>
void Queue<T>::clear()
{
	queueArray.erase(queueArray.begin(), queueArray.end());
}

template <typename T>
void Queue<T>::push(const T &data)
{
	auto itr = queueArray.end();
	queueArray.insert(itr, data);
}

template <typename T>
T Queue<T>::pop()
{
	auto itr = queueArray.begin();
	T ret = *itr;
	queueArray.erase(queueArray.begin());
	return ret;
}

template <typename T>
T Queue<T>::front()
{
	auto itr = (queueArray.begin());
	return *itr;
}

template <typename T>
T Queue<T>::back()
{
	auto itr = (queueArray.end() - 1);
	return *itr;
}

template <typename T>
uint Queue<T>::getSize()
{
	return queueArray.size();
}

template <typename T>
bool Queue<T>::isEmpty()
{
	if(getSize() == 0)
		return true;

	else
		return 0;
}

template <typename T>
void Queue<T>::print()
{
	std::cout << "Size is: " << getSize() << std::endl;

	if(getSize() == 0)
		return;

	std::cout << "front <- ";

	for(auto itr : queueArray)
	{
		std::cout << itr << " <- ";
	}

	std::cout << "back\n" << std::endl;
}

#endif




