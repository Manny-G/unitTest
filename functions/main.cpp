#include "linkedList.h"
#include "setOfStacks.h"
#include "insertionSort.h"
#include "arraysAndStrings.h"
#include "linkedListFunctions.h"
#include "stack.h"
#include "queue.h"
#include "minMaxStack.h"
#include "setOfStacks.h"
#include "queueOfStacks.h"
#include "animalShelter.h"
#include "binaryTree.h"
#include "avlTree.h"
#include "graph.h"

using namespace std;
using fPtr = uint (*)(uint);

int main()
{

	BinaryTree<uint> b;
	for(uint i = 0 ; i < 10 ; i++)
		b.append(i);

	b.print();

	cout << "what I don't want happening" << endl;

	BinaryTree<uint> b2;
	std::vector<uint> arr;

	for(uint i = 0 ; i < 10 ; i++)
		arr.push_back(i);

	b2.arrayToTree(arr);
	b2.print();
	cout << "what did I make?" << endl;

	std::vector<LinkedList<uint> *> vec = b2.depthListsPreOrder();

	for(auto i : vec)
	{
		cout << "layer contains:" << endl;
		i->print();

	}

	cout << "please god work this time?" << endl;

	std::vector<LinkedList<uint> *> vec2 = b2.depthListsBFS();
	for(auto i : vec2)
	{
		cout << "layer contains:" << endl;
		i->print();

	}

	cout << "is b balanced? " << b.checkBalanced() << endl;
	cout << "is b2 balanced? " << b2.checkBalanced() << endl;

	b2.append(10);
	cout << "is still b2 balanced? " << b2.checkBalanced() << endl;
	b2.remove(10);
	cout << "is b2 back to balance? " << b2.checkBalanced() << endl;
	b2.remove(9);
	b2.remove(8);
	cout << "is b2 still balanced? " << b2.checkBalanced() << endl;

	cout << "is b a BST? " << b.isBST() << endl;
	cout << "is b2 a BST? " << b2.isBST() << endl;
	b2.append(8);
	b2.remove(7);
	b2.append(7);
	b2.print();
	cout << "is b2 still a BST? " << b2.isBST() << endl;



	return 0;
}

