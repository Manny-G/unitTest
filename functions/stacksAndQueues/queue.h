#ifndef STACKSANDQUEUES_QUEUE_H_
#define STACKSANDQUEUES_QUEUE_H_

#include <vector>
#include <iostream>
using uint = unsigned int;

template <typename T>
class Queue
{
private:
	std::vector<T> queueArray;

public:
	Queue();
	Queue(const Queue &rhs);
	~Queue();
	const Queue &operator=(const Queue &rhs);
	bool operator==(const Queue &rhs) const;

	void clear();
	void push(const T &data);
	T pop();
	T front();
	T back();
	uint getSize();
	bool isEmpty();
	void print();
};

#include "queue.cpp"
#endif /* STACKSANDQUEUES_QUEUE_H_ */
