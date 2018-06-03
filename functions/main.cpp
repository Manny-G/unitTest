/*
 * main.cpp
 *
 *  Created on: May 21, 2018
 *      Author: manny
 */

#include "insertionSort.h"
#include "arraysAndStrings.h"

using namespace std;

int main()
{
	uint myArr[arrayDim][arrayDim];
	uint **arrPtr;
	genSqrArr(myArr);
	printArr(myArr);

	cout << "rotate" << endl;
	rotate(arrPtr,myArr);

	printArr(arrPtr);

	cout << "rotateSwap" << endl;
	rotateSwap(myArr);

	printArr(myArr);

	return 0;

}

