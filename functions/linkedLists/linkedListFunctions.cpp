#include "linkedListFunctions.h"

// Test 1
LinkedList<int> genBaseListTest1()
{
	LinkedList<int> genList;
	genList.append(5);
	genList.append(3);
	genList.append(10);
	genList.append(5);
	genList.append(7);
	genList.append(4);
	genList.append(2);
	genList.append(9);
	genList.append(9);
	genList.append(1);
	genList.append(6);
	genList.append(8);
	genList.append(0);

	return genList;
}

LinkedList<int> genSolutionListTest1()
{
	LinkedList<int> genList;
	genList.append(3);
	genList.append(10);
	genList.append(5);
	genList.append(7);
	genList.append(4);
	genList.append(2);
	genList.append(9);
	genList.append(1);
	genList.append(6);
	genList.append(8);
	genList.append(0);

	return genList;
}

// Test 2
LinkedList<int> genBaseListTest2()
{
	LinkedList<int> genList;
	genList.append('d');
	genList.append('a');
	genList.append('m');
	genList.append('m');
	genList.append('i');
	genList.append('t');
	genList.append('i');
	genList.append('m');
	genList.append('m');
	genList.append('a');
	genList.append('d');

	return genList;
}
