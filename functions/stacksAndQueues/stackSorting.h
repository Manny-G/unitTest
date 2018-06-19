#ifndef STACKSANDQUEUES_STACKSORTING_H_
#define STACKSANDQUEUES_STACKSORTING_H_

#include "stack.h"

template <typename T>
void stackSort(Stack<T> &in)
{
	Stack<T> buffer;
	T store;

	while(!in.isEmpty())
	{
		if(in.top() < buffer.top())
		{
			store = in.pop();

			while(buffer.top() >= store && buffer.isEmpty() == false)
			{
				in.push(buffer.pop());
			}
			buffer.push(store);
		}

		else
		{
			buffer.push(in.pop());
		}
	}

	while(!buffer.isEmpty())
	{
		in.push(buffer.pop());
	}
}

#endif /* STACKSANDQUEUES_STACKSORTING_H_ */
