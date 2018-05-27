#include <vector>
#include <iostream>
#include <stdlib.h>
#include <time.h>

class sortingClass
{
public:
	void swap(int &a, int &b);

	void insertionSortIncrementing(std::vector<int> &arr);

	void insertionSortDecrementing(std::vector<int> &arr);

	int linearSearch(std::vector<int> &arr, int val);

	std::vector<int> convertToBinary(int val);

};
