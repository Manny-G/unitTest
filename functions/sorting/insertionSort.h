#ifndef SORTING_INSERTIONSORT_H_
#define SORTING_INSERTIONSORT_H_


#include <vector>
#include <iostream>
#include <stdlib.h>
#include <time.h>

using uint = unsigned int;

// implementations
void swap(int &a, int &b);

template<typename T>
void insertionSortIncrementing(std::vector<T> &arr);

template<typename T>
void insertionSortIncrementingRecursion(std::vector<T> &arr, uint itr);

void insertionSortDecrementing(std::vector<int> &arr);

int linearSearch(std::vector<int> &arr, int val);

std::vector<int> convertToBinary(int val);

// unit test functions
bool unitTestInsSortInc();
bool unitTestInsSortIncRec();



#endif /* SORTING_INSERTIONSORT_H_ */
