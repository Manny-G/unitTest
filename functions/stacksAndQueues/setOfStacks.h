#ifndef STACKSANDQUEUES_SETOFSTACKS_H_
#define STACKSANDQUEUES_SETOFSTACKS_H_

#include "stack.h"

using uint = unsigned int;

template <typename T>
class SetOfStacks : public Stack<T>
{
private:
	uint capacity;
	uint currPile;
	uint numStacks;
	Stack<T> *stackArray;

public:
	SetOfStacks(uint cap, uint stacks)
	{
		capacity = cap;
		currPile = 0;
		numStacks = stacks;
		stackArray = new Stack<T>[numStacks];
	}

	void push(T val)
	{
		if(currPile < numStacks && stackArray[currPile].getSize() < capacity)
		{
			if(stackArray[currPile].getSize() < capacity)
			{
				stackArray[currPile].push(val);

				if(stackArray[currPile].getSize() == capacity && (currPile + 1) != numStacks)
					currPile++;
			}

			else if( (currPile + 1) < numStacks )
			{
				currPile++;
				stackArray[currPile].push(val);

				if(stackArray[currPile].getSize() == capacity)
					currPile++;
			}
		}
	}

	T pop()
	{
		if(stackArray[currPile].getSize() > 0)
		{
			return stackArray[currPile].pop();
		}

		else if(currPile > 0)
		{
			currPile--;
			if(stackArray[currPile].getSize() > 0)
			{
				return stackArray[currPile].pop();
			}
		}
	}

	T popAt(uint stackNum)
	{
		if(stackArray[stackNum].getSize() > 0 && (stackNum > 0 && stackNum < numStacks))
		{
			return stackArray[stackNum].pop();
		}

		else if( (stackNum - 1) > 0)
		{
			stackNum;
			return stackArray[stackNum].pop();
		}
	}

};

#endif /* STACKSANDQUEUES_SETOFSTACKS_H_ */


