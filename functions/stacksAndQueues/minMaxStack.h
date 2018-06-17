#ifndef STACKSANDQUEUES_MINMAXSTACK_H_
#define STACKSANDQUEUES_MINMAXSTACK_H_

#include <iostream>
#include <vector>
using uint = unsigned int;

template <typename T>
class StackNode
{
public:
	T data;
	T min;
	T max;

//public:
	StackNode() : data(0), min(0), max(0)
	{

	}

	StackNode(T dataVal) : data(dataVal), min(0), max(0)
	{

	}

	StackNode(T dataVal, T minVal, T maxVal) : data(dataVal), min(minVal), max(maxVal)
	{

	}
};

template <typename T>
class MinMaxStack : public StackNode<T>
{
private:
	std::vector<StackNode<T>> stackArray;

public:
	MinMaxStack()
	{
		stackArray.clear();
	}

	void push(T data)
	{
		StackNode<T> node(data);
		if(getSize() == 0)
		{
			node.min = data;
			node.max = data;
		}

		else
		{
			auto itr = (stackArray.end() - 1);

			if(data < itr -> min)
				node.min = data;
			else
				node.min = itr -> min;

			if(data > itr -> max)
				node.max = data;
			else
				node.max = itr -> max;
		}

		stackArray.insert(stackArray.end(), node);
	}

	T pop()
	{
		auto itr = (stackArray.end() - 1);
		T ret = itr -> data;
		stackArray.erase(itr);
		return ret;
	}

	T peekTop()
	{
		auto itr = (stackArray.end() - 1);
		return itr -> data;
	}

	T peekMin()
	{
		auto itr = (stackArray.end() - 1);
		return itr -> min;
	}

	T peeMax()
	{
		auto itr = (stackArray.end() - 1);
		return itr -> max;
	}

	uint getSize()
	{
		return stackArray.size();
	}

};

#endif /* STACKSANDQUEUES_MINMAXSTACK_H_ */
