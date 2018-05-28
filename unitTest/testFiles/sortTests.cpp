/*
 * fooTests.cpp
 *
 *  Created on: May 20, 2018
 *      Author: manny
 */

#include "gtest/gtest.h"
#include "insertionSort.h"

namespace
{
	class sortTests : public ::testing::Test
	{

	};

	class diffTests : public ::testing::Test
	{

	};

	bool unitTestInsSortInc()
	{
		std::vector<int> toSort;
		int diceRoll;

		srand(time(NULL));

		for(int i = 0 ; i < 10 ; i++)
		{
			diceRoll = rand() % 11;
			toSort.push_back(diceRoll);
		}

		for(size_t i = 0 ; i < toSort.size() ; i++)
		{
			std::cout << "in position "<< i << ": " << toSort[i] << std::endl;
		}

		std::cout << "\nsorting:" << std::endl;

		insertionSortIncrementing(toSort);

		bool isSorted = true;

		// malicious: uncommenting will cause the test to fail if
		// diceRoll != 9, because it will mess with the order
//		diceRoll = rand() % 10;
//		toSort[diceRoll] = 100;

		for(size_t i = 0 ; i < toSort.size() - 1 ; i++)
		{
			std::cout << "in position "<< i << ": " << toSort[i] << std::endl;

			if(toSort[i] > toSort[i + 1])
				return false;
		}

		return isSorted;
	}


	TEST_F(sortTests, unitTestInsSortInc)
	{
		EXPECT_TRUE(unitTestInsSortInc());
	}

	TEST_F(sortTests, willFail)
	{
		EXPECT_TRUE(false);
	}

	TEST_F(diffTests, willPass)
	{
		EXPECT_TRUE(unitTestInsSortInc());
	}

	TEST_F(diffTests, willFail)
	{
		EXPECT_TRUE(false);
	}
}



