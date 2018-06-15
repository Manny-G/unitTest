/*
 * main.cpp
 *
 *  Created on: May 21, 2018
 *      Author: manny
 */

#include <linkedList.h>
#include "insertionSort.h"
#include "arraysAndStrings.h"
#include "linkedListFunctions.h"

using namespace std;
//typedef uint (*fPtr)(uint);
using fPtr = uint (*)(uint);

uint printNum(uint x)
{
	cout << "x is " << x << endl;
	return x;
}

uint otherPrintNum(uint y)
{
	cout << "y is " << y << endl;
	return y;
}

void printCallerFcn(uint val, fPtr printFunc = printNum)
{
	uint temp = printFunc(val);
	cout << "temp got " << temp << endl;
}

int main()
{
	// testing function pointers
	/*uint t = 12;
	fPtr f = &otherPrintNum;
	printCallerFcn(t, f);
	f = &printNum;
	f(t);
	auto trick = &otherPrintNum;
	trick(t);*/


	// testing zero matrix and rotate matrix
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


	// testing l.l. remove duplicates
	LinkedList<int> temp1 = genBaseListTest1();
	LinkedList<int> temp2 = genSolutionListTest1();
	temp1.print();
	temp2.print();

	std::cout << "what is == " << (temp1 == temp2) << std::endl;

	temp1.removeDuplicatesSelfContained();
	temp1.print();

	std::cout << "what is == " << (temp1 == temp2) << std::endl;

	temp1.append(3);
	temp1.print();
	std::cout << "what is == " << (temp1 == temp2) << std::endl;


	// Testing l.l. recursive palindrome
	/*LinkedList<int> temp3 = genBaseListTest2();
	temp3.print();
	bool cond = temp3.palindromeRecursive();

	std::cout << "what is cond? " << cond << std::endl;*/

	return 0;

}

