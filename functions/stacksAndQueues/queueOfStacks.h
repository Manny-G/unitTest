#ifndef STACKSANDQUEUES_QUEUEOFSTACKS_H_
#define STACKSANDQUEUES_QUEUEOFSTACKS_H_


#include "stack.h"
using uint = unsigned int;

template <typename T>
class MyQueue : public Stack<T>
{
private:
	Stack<T> buffer, queue;

public:
	MyQueue()
	{

	}

	void push(T data)
	{
		while(queue.getSize() > 0)
		{
			buffer.push(queue.pop());
		}

		buffer.push(data);

		while(buffer.getSize() > 0)
		{
			queue.push(buffer.pop());
		}
	}

	T pop()
	{
		return queue.pop();
	}

	T front()
	{
		return queue.top();
	}

	T back()
	{
		while(queue.size() > 0)
		{
			buffer.push(queue.pop());
		}

		T ret = buffer.top();

		while(buffer.size() > 0)
		{
			queue.push(buffer.pop());
		}

		return ret;
	}

	uint getSize()
	{
		return queue.getSize();
	}
};

#endif /* STACKSANDQUEUES_QUEUEOFSTACKS_H_ */
