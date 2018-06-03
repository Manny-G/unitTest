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

#endif /* ARRAYSANDSTRINGS_ARRAYSANDSTRINGS_H_ */
