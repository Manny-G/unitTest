#include "arraysAndStrings.h"
using namespace std;

/********************
*** Unique String ***
*********************/

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

/*********************
*** Is Permutation ***
**********************/

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

/**************
*** URL-ify ***
***************/

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

/*****************************
*** Palindrome Permutation ***
******************************/

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

/***************
*** One Away ***
****************/

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

/*************************
*** String Compression ***
**************************/

string stringCompression(string in)
{
	cout << "input is " << in << endl;
	if(in.empty() or in.size() < 2)
		return in;
	string out;
	cout << "what is the size of out? " << out.size()
		 << ", is it empty? " << out.empty() << endl;
	uint consCount = 0;

	for(uint i = 0 ; i < in.size() ; i++)
	{
		if(i == 0)
			consCount ++;

		else if( i == (in.size() - 1) )
		{
			if(in[i - 1] != in[i])
			{
				out += static_cast<char>(in[i - 1]);

				if(consCount > 1)
					// assume that no consecutive count is greater than 9
					out += static_cast<char>(consCount) + 0x30;

				out += static_cast<char>(in[i]);
			}

			else
			{
				consCount++;
				out += static_cast<char>(in[i]);

				// assume that no consecutive count is greater than 9
				out += static_cast<char>(consCount) + 0x30;
			}
		}

		else
		{
			if(in[i - 1] == in[i])
				consCount++;

			else if(in[i - 1] != in[i] && consCount > 1)
			{
				out += static_cast<char>(in[i - 1]);

				// assume that no consecutive count is greater than 9
				out += static_cast<char>(consCount) + 0x30;
				consCount = 1;
			}

			else
				out += static_cast<char>(in[i - 1]);
		}
	}

	cout << "out looks like this: " << out << endl;

	return out;

}

/********************
*** Rotate Matrix ***
*********************/

void swap(uint &a, uint &b)
{
	uint swapStore = b;
	b = a;
	a = swapStore;
}

void printArr(uint (&arr)[arrayDim][arrayDim])
{
	for(uint i = 0 ; i < arrayDim ; i++)
	{
		for(uint j = 0 ; j < arrayDim ; j++)
		{
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}

	cout << endl;
}

void printArr(uint **(&ptr))
{
	for(uint i = 0 ; i < arrayDim ; i++)
	{
		for(uint j = 0 ; j < arrayDim ; j++)
		{
			cout << ptr[i][j] << ' ';
		}
		cout << endl;
	}

	cout << endl;
}

void genSqrArr(uint (&arr)[arrayDim][arrayDim])
{
	uint count = 0;

	for(uint i = 0 ; i < arrayDim ; i++)
	{
		for(uint j = 0 ; j < arrayDim ; j++)
		{
			arr[i][j] = count;
			count++;
		}
	}
}

void rotate(uint **(&ptr), uint arr[arrayDim][arrayDim])
{
	ptr = new uint*[arrayDim];

	for(uint i = 0 ; i < arrayDim ; i++)
		ptr[i] = new uint[arrayDim];

	for(uint i = 0 ; i < arrayDim ; i++)
	{
		for(uint j = 0 ; j < arrayDim ; j++)
		{
			ptr[arrayDim - 1 - j][i] = arr[i][j];
		}
	}
}

void rotateSwap(uint (&arr)[arrayDim][arrayDim])
{
	uint count = 1;

	for(uint i = 0 ; i < arrayDim / 2; i++)
	{
		for(uint j = i ; j < arrayDim - count ; j++)
		{
			swap(arr[i][j], arr[arrayDim - 1 - j][i]);
			swap(arr[i][j], arr[j][arrayDim - 1 - i]);
			swap(arr[j][arrayDim - 1 - i], arr[arrayDim - 1 - i][arrayDim - 1 - j]);
		}

		count++;
	}
}

/******************
*** Zero Matrix ***
*******************/
void printRandMatrix(uint **ptr)
{
	for(uint i = 0 ; i < numRandArrRows ; i++)
	{
		for(uint j = 0 ; j < numRandArrCols ; j++)
		{
			cout << ptr[i][j] << " ";
		}
		cout << endl;
	}
}

void genRandMatrix(uint **(&ptr))
{
	uint diceRoll;
	srand(time(NULL));

	ptr = new uint*[numRandArrRows];
	for(uint i = 0 ; i < numRandArrRows ; i++)
		ptr[i] = new uint[numRandArrCols];

	for(uint i = 0 ; i < numRandArrRows ; i++)
	{
		for(uint j = 0 ; j < numRandArrCols ; j++)
		{
			ptr[i][j] = rand() % 10;
		}
	}
}

void zeroMatrix(uint **(&ptr))
{
	bool arrRows[numRandArrRows], arrCols[numRandArrCols];

	for(bool &i : arrRows)
		i = false;

	for(bool &i : arrCols)
		i = false;

	for(uint i = 0 ; i < numRandArrRows ; i++)
	{
		for(uint j = 0 ; j < numRandArrCols ; j++)
		{
			if(ptr[i][j] == 0)
			{
				arrRows[i] = true;
				arrCols[j] = true;
			}
		}
	}

	for(uint i = 0 ; i < numRandArrRows ; i++)
	{
		for(uint j = 0 ; j < numRandArrCols ; j++)
		{
			if(arrRows[i] == true || arrCols[j] == true)
				ptr[i][j] = 0;
		}
	}
}
