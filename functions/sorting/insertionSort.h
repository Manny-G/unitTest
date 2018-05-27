/*
 * insertionSort.h
 *
 *  Created on: May 27, 2018
 *      Author: manny
 */

#ifndef SORTING_INSERTIONSORT_H_
#define SORTING_INSERTIONSORT_H_


#include <vector>
#include <iostream>
#include <stdlib.h>
#include <time.h>

void swap(int &a, int &b);

void insertionSortIncrementing(std::vector<int> &arr);

void insertionSortDecrementing(std::vector<int> &arr);

int linearSearch(std::vector<int> &arr, int val);

std::vector<int> convertToBinary(int val);



#endif /* SORTING_INSERTIONSORT_H_ */
