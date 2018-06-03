#ifndef ARRAYSANDSTRINGS_ARRAYSANDSTRINGS_H_
#define ARRAYSANDSTRINGS_ARRAYSANDSTRINGS_H_

#include <iostream>
#include <string>

using uint = unsigned int;

// functions
bool uniqueString(std::string in);

bool uniqueStrNoDataStructs(std::string in);

bool isPermutation(std::string a, std::string b);

std::string urlIfy(std::string in, unsigned int len);

bool palinPerm(std::string in);

uint maxVal(uint firstVal, uint secondVal);
uint compareVals(uint firstVal, uint secondVal);
uint absDiff(uint firstLength, uint secondLength);
bool oneAway(std::string str1, std::string str2);

std::string stringCompression(std::string in);

const uint arrayDim = 5;
void swap(uint &a, uint &b);
void printArr(uint (&arr)[arrayDim][arrayDim]);
void printArr(uint **(&ptr));
void genSqrArr(uint (&arr)[arrayDim][arrayDim]);
void rotate(uint **(&ptr), uint arr[arrayDim][arrayDim]);
void rotateSwap(uint (&arr)[arrayDim][arrayDim]);

#endif /* ARRAYSANDSTRINGS_ARRAYSANDSTRINGS_H_ */
