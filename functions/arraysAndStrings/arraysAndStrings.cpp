#include "arraysAndStrings.h"
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

bool uniqueStrNoDataStructs(string in)
{
	unsigned long long int firstHalf = 0, secondHalf = 0;
	cout << "input string is '" << in << "'" << endl;

	for(unsigned int idx : in)
	{
		if( (0 <= idx && idx <= 63) && (firstHalf & (1 << idx)) == 0)
			firstHalf += (1 << idx);
		else if( (64 <= idx && idx <= 127) && (secondHalf & (1 << (idx - 64))) == 0)
			secondHalf += (1 << idx);
		else
			return false;
	}

	cout << "can't believe it worked" << endl;
	return true;
}


bool isPermutation(string str1, string str2)
{
	cout << "string 1 is " << str1 << ", string 2 is " << str2 << endl;
	uint len1 = str1.size(), len2 = str2.size();

	if(len1 != len2)
		return false;

	bool arr[len2];
	bool goodStuff;

	for(bool &i : arr)
		i = false;

	for(char i : str1)
	{
		goodStuff = false;

		for(uint j = 0 ; j < len2 ; j++)
		{
			if(i == str2[j] && arr[j] == false)
			{
				arr[j] = true;
				goodStuff = true;
				break;
			}
		}

		if(goodStuff == false)
			return false;
	}

	cout << "hey that was good" << endl;
	return true;
}

string urlIfy(string in, uint len)
{
	cout << "input is: " << in << endl;

	bool started = false;
	string out;
	uint counter = 0, i = 0;

	while(counter < len)
	{
		if(in[i] == ' ' && started == false)
		{
			i++;
			continue;
		}

		else if(in[i] != ' ' && started == false)
			started = true;

		if(started == true && in[i] != ' ')
		{
			out += in[i];
			counter++;
		}

		else if (started == true && in[i] == ' ')
		{
			out += "%20";
			counter++;
		}

		i++;
	}

	cout << "output is: " << out << endl;
	return out;
}

bool palinPerm(string in)
{
	if(in.empty())
	{
		return false;
	}

	uint arr[26], arrLen = 0;

	for(uint &i : arr)
		i = 0;

	for(char i : in)
	{
		if('A' <= i && i <= 'Z')
		{
			arr[i % 'A']++;
			arrLen++;
		}

		else if('a' <= i && i <= 'z')
		{
			arr[i % 'a']++;
			arrLen++;
		}
	}

	uint numEven = 0, numOdd = 0;

	for(uint i : arr)
	{
		if(i != 0)
		{
			if(i % 2 == 0)
				numEven++;
			else
				numOdd++;
		}
	}

	if(arrLen % 2 == 0 && numOdd != 0)
		return false;
	else if(arrLen % 2 == 1 && numOdd != 1)
		return false;
	else
		return true;
}

uint maxVal(uint firstVal, uint secondVal)
{
	if(firstVal > secondVal)
		return firstVal;
	else if(firstVal < secondVal)
		return secondVal;
	else
		return firstVal;
}

uint compareVals(uint firstVal, uint secondVal)
{
	if(firstVal > secondVal)
		return 1;
	else if(firstVal < secondVal)
		return 2;
	else
		return 0;
}

uint absDiff(uint firstLength, uint secondLength)
{
	if(firstLength < secondLength)
		return secondLength - firstLength;
	else if(firstLength > secondLength)
		return firstLength - secondLength;
	else
		return 0;
}

bool oneAway(string str1, string str2)
{
	cout << "inputs are " << str1 << " and " << str2 << endl;
	uint len1 = str1.size(), len2 = str2.size();
	bool oneAwayFlag = false;

	if(absDiff(len1, len2) > 1)
		return false;

	uint whoIsBigger = compareVals(len1, len2);

	for(uint i = 0 ; i < maxVal(len1, len2) ; i++)
	{
		if(!oneAwayFlag)
		{
			if(str1[i] != str2[i])
				oneAwayFlag = true;
		}

		else
		{
			if(whoIsBigger == 0)
			{
				if(str1[i] != str2[i])
					return false;
			}

			else if(whoIsBigger == 1)
			{
				if(str1[i + 1] != str2[i])
					return false;
			}

			else
			{
				if(str1[i] != str2[i + 1])
					return false;
			}
		}
	}

	cout << str1 << " is one away from " << str2 << endl;
	return true;
}
