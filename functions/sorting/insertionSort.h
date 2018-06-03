#ifndef SORTING_INSERTIONSORT_H_
#define SORTING_INSERTIONSORT_H_


#include <vector>
#include <iostream>
#include <stdlib.h>
#include <time.h>

// implementations
void swap(int &a, int &b);

void insertionSortIncrementing(std::vector<int> &arr);

void insertionSortDecrementing(std::vector<int> &arr);

int linearSearch(std::vector<int> &arr, int val);

std::vector<int> convertToBinary(int val);

// unit test functions
bool unitTestInsSortInc();



#endif /* SORTING_INSERTIONSORT_H_ */
