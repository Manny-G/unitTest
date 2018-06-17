#include <linkedList.h>
#include "insertionSort.h"
#include "arraysAndStrings.h"
#include "linkedListFunctions.h"
#include "stack.h"
#include "queue.h"
#include "binaryTree.h"

using namespace std;
using fPtr = uint (*)(uint);

int main()
{
	Stack<int> s1;
	s1.push(1);
	s1.print();
	cout << "peeking at " << s1.top() << endl;
	s1.push(7);
	s1.print();
	cout << "peeking at " << s1.top() << endl;
	cout << "popping " << s1.pop() << endl;
	s1.print();
	cout << "peeking at " << s1.top() << endl;
	cout << "popping " << s1.pop() << endl;
	s1.print();
	cout << "peeking at " << s1.top() << endl;
	cout << "popping " << s1.pop() << endl;

	return 0;
}

