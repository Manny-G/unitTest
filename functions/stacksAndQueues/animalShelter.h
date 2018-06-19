#ifndef STACKSANDQUEUES_ANIMALSHELTER_H_
#define STACKSANDQUEUES_ANIMALSHELTER_H_

#include <vector>
#include <iostream>
#include <string>
#include "stack.h"

class ShelterNode
{
public:
	std::string name;
	bool isDog;

	ShelterNode() : name(""), isDog(true)
	{

	}

	ShelterNode(std::string n, bool doggo) : name(n), isDog(doggo)
	{

	}
};

class AnimalShelterQueue : public ShelterNode
{
private:
	std::vector <ShelterNode> queue;
public:
	AnimalShelterQueue()
	{
		queue.clear();
	}

	void enqueue(ShelterNode data)
	{
		queue.insert(queue.end(), data);
	}

	void enqueueFront(ShelterNode data)
	{
		queue.insert(queue.begin(), data);
	}

	ShelterNode dequeueAny()
	{
		auto itr = queue.begin();
		ShelterNode ret = *itr;
		queue.erase(itr);
		return ret;
	}

	ShelterNode dequeueDog()
	{
		Stack<ShelterNode> store;

		while(!queue.front().isDog)
		{
			store.push(dequeueAny());
		}

		ShelterNode ret = dequeueAny();

		while(!store.isEmpty())
		{
			enqueueFront(store.pop());
		}

		return ret;
	}

	ShelterNode dequeueCat()
	{
		Stack<ShelterNode> store;

		while(queue.front().isDog)
		{
			store.push(dequeueAny());
		}

		ShelterNode ret = dequeueAny();

		while(!store.isEmpty())
		{
			enqueueFront(store.pop());
		}

		return ret;
	}

	void print()
	{
		std::cout << "size is " << queue.size() << std::endl;
		std::cout << "front <- ";
		for(auto itr = queue.begin() ; itr != queue.end() ; itr++)
			std::cout << itr -> name << " <- ";

		std::cout << "back\n" << std::endl;
	}
};

#endif /* STACKSANDQUEUES_ANIMALSHELTER_H_ */
