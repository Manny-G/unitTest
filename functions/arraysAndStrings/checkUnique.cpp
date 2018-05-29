/*
 * checkUnique.cpp
 *
 *  Created on: May 28, 2018
 *      Author: manny
 */
#include "checkUnique.h"
using namespace std;

bool uniqueString(string in)
{
	bool array[128];
	cout << "input string is '" << in << "'" << endl;

	for(bool &i : array)
		i = false;

	for(unsigned int idx : in)
	{
		if(array[idx] == false)
			array[idx] = true;
		else
			return false;
	}

	cout << "we're happy" << endl;
	return true;
}

bool uniqueStrNoDataStructs(std::string in)
{
	unsigned long long int firstHalf = 0, secondHalf = 0;
	cout << "input string is '" << in << "'" << endl;

	for(unsigned int idx : in)
	{
		if( (0 <= idx && idx <= 63) && (firstHalf & (1 << idx)) == 0)
			firstHalf += (1 << idx);
		else if( (64 <= idx && idx <= 127) && (secondHalf & (1 << idx)) == 0)
			secondHalf += (1 << idx);
		else
			return false;
	}

	cout << "can't believe it worked" << endl;
	return true;
}
