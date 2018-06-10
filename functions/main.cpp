/*
 * main.cpp
 *
 *  Created on: May 21, 2018
 *      Author: manny
 */

#include "insertionSort.h"
#include "arraysAndStrings.h"
#include "singlyLinkedList.h"
#include "linkedListFunctions.h"

using namespace std;

int main()
{
	/*uint myArr[arrayDim][arrayDim];
	uint **arrPtr;
	genSqrArr(myArr);
	printArr(myArr);

	cout << "rotate" << endl;
	rotate(arrPtr,myArr);

	printArr(arrPtr);

	cout << "rotateSwap" << endl;
	rotateSwap(myArr);

	printArr(myArr);

	cout << "my rand matrix is:" << endl;
	uint **randArrPtr;
	genRandMatrix(randArrPtr);
	printRandMatrix(randArrPtr);

	cout << "after zeroMAtrix call:" << endl;
	zeroMatrix(randArrPtr);
	printRandMatrix(randArrPtr);*/

	singlyLinkedList<int> temp1 = genBaseListTest1();
	singlyLinkedList<int> temp2 = genSolutionListTest1();
	temp1.print();
	temp2.print();

	std::cout << "what is == " << (temp1 == temp2) << std::endl;

	temp1.removeDuplicates();
	temp1.print();

	std::cout << "what is == " << (temp1 == temp2) << std::endl;

	temp1.append(3);
	temp1.print();
	std::cout << "what is == " << (temp1 == temp2) << std::endl;

	return 0;

}

