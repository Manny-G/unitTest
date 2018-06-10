#include "linkedListFunctions.h"

// Test 1
singlyLinkedList<int> genBaseListTest1()
{
	singlyLinkedList<int> genList;
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

singlyLinkedList<int> genSolutionListTest1()
{
	singlyLinkedList<int> genList;
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

