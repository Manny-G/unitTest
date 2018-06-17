#include <linkedList.h>
#include <setOfStacks.h>
#include "insertionSort.h"
#include "arraysAndStrings.h"
#include "linkedListFunctions.h"
#include "stack.h"
#include "queue.h"
#include "minMaxStack.h"
#include "setOfStacks.h"
#include "binaryTree.h"

using namespace std;
using fPtr = uint (*)(uint);

int main()
{
	MinMaxStack<int> s1;
	for(uint i = 2; i < 7 ; i++)
	{
		cout << ">>pushing " << i << endl;
		s1.push(i);
		cout << "top: " << s1.peekTop() << ", min: " << s1.peekMin() << ", max: " << s1.peeMax() << endl;
	}

	for(uint i = 0; i < 2 ; i++)
	{
		cout << "<<popping " << s1.pop() << endl;
		cout << "top: " << s1.peekTop() << ", min: " << s1.peekMin() << ", max: " << s1.peeMax() << endl;
	}

	for(uint i = 10; i < 12 ; i++)
	{
		cout << ">>pushing " << i << endl;
		s1.push(i);
		cout << "top: " << s1.peekTop() << ", min: " << s1.peekMin() << ", max: " << s1.peeMax() << endl;
	}

	cout << ">>pushing " << 0 << endl;
	s1.push(0);
	cout << "top: " << s1.peekTop() << ", min: " << s1.peekMin() << ", max: " << s1.peeMax() << endl;


	cout << "hi" << endl;
}

