/*
 * Insertion_Sort.cpp
 *
 *  Created on: May 21, 2018
 *      Author: manny
 */
#include "insertionSort.h"
using namespace std;

void swap(int &a, int &b)
{
	int swapStore = b;
	b = a;
	a = swapStore;
}

void insertionSortIncrementing(vector<int> &arr)
{
	for(unsigned int i = 1 ; i < arr.size() ; i++)
	{
		int j = i - 1;

		while(j >= 0 && arr[j] > arr[j + 1])
		{
			swap(arr[j], arr[j + 1]);
			j--;
		}
	}
}

void insertionSortDecrementing(vector<int> &arr)
{
	for(auto i = arr.size() - 2 ; i < arr.size() ; i--)
	{
		auto j = i + 1;

		while(j < arr.size() && arr[j] > arr[j - 1])
		{
			swap(arr[j-1], arr[j]);
			j++;
		}
	}
}

int linearSearch(vector<int> &arr, int val)
{
	for(unsigned int i = 0 ; i < arr.size() ; i++)
	{
		if(arr[i] == val)
		{
			return i;
		}
	}

	return -1;
}

vector<int> convertToBinary(int val)
{
	vector<int> binArr;

	for(unsigned int i = 0 ; i < sizeof(val) * 8 ; i++)
	{
		int shiftVal = val & (0x0001 << i);
		binArr.push_back(shiftVal);
	}

	return binArr;
}
