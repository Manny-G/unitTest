#ifndef STACKSANDQUEUES_STACK_H_
#define STACKSANDQUEUES_STACK_H_

#include <vector>
#include <iostream>
using uint = unsigned int;

template <typename T>
class Stack
{
private:
	std::vector<T> stackArray;

public:
	Stack();
	Stack(const Stack &rhs);
	~Stack();
	const Stack &operator=(const Stack &rhs);
	bool operator==(const Stack &rhs) const;

	void clear();
	void push(const T &data);
	T pop();
	T top();
	uint getSize();
	bool isEmpty();
	void print();
};

#include "stack.cpp"
#endif /* STACKSANDQUEUES_STACK_H_ */
