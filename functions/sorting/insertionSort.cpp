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

bool unitTestInsSortInc()
{
	vector<int> toSort;
	int diceRoll;

	srand(time(NULL));

	for(int i = 0 ; i < 10 ; i++)
	{
		diceRoll = rand() % 11;
		toSort.push_back(diceRoll);
	}

	for(size_t i = 0 ; i < toSort.size() ; i++)
	{
		cout << "in position "<< i << ": " << toSort[i] << endl;
	}

	cout << "\nsorting:" << endl;

	insertionSortIncrementing(toSort);

	bool isSorted = true;

	// malicious: uncommenting will cause the test to fail if
	// diceRoll != 9, because it will mess with the order
//		diceRoll = rand() % 10;
//		toSort[diceRoll] = 100;

	for(size_t i = 0 ; i < toSort.size() - 1 ; i++)
	{
		cout << "in position "<< i << ": " << toSort[i] << endl;

		if(toSort[i] > toSort[i + 1])
			return false;
	}

	return isSorted;
}
