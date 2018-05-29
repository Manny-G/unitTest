#include "gtest/gtest.h"
#include "insertionSort.h"
#include "checkUnique.h"
using namespace std;

namespace
{
	class unitTests : public ::testing::Test
	{

	};

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

	TEST_F(unitTests, unitTestInsSortInc)
	{
		EXPECT_TRUE(unitTestInsSortInc());
	}

	TEST_F(unitTests, uniqueString)
	{
		EXPECT_FALSE(uniqueString("not my car"));
		EXPECT_TRUE(uniqueString("notMy car"));
		EXPECT_FALSE(uniqueString("Hello World"));
		EXPECT_TRUE(uniqueString("abcdEfG"));
		EXPECT_FALSE(uniqueString("abcdEaG"));
	}

	TEST_F(unitTests, uniqueStrNoDataStructs)
	{
		EXPECT_FALSE(uniqueStrNoDataStructs("not my car"));
		EXPECT_TRUE(uniqueStrNoDataStructs("notMy car"));
		EXPECT_FALSE(uniqueStrNoDataStructs("Hello World"));
		EXPECT_TRUE(uniqueStrNoDataStructs("abcdEfG"));
		EXPECT_FALSE(uniqueStrNoDataStructs("abcdEaG"));
	}
}



