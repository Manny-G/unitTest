/*
 * main.cpp
 *
 *  Created on: May 21, 2018
 *      Author: manny
 */

#include "insertionSort.h"
#include "arraysAndStrings.h"
#include "singlyLinkedList.h"

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

	singlyLinkedList<int> temp;

	for(uint i = 0; i < 10 ; i++)
	{
		temp.append(i);
	}

	temp.print();

	temp.remove(6);

	temp.print();

	temp.remove(3);

	temp.print();

	return 0;

}

