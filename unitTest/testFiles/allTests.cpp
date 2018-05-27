/*
 * allTests.cpp
 *
 *  Created on: May 20, 2018
 *      Author: manny
 */

#include "gtest/gtest.h"

#include "sortTests.cpp"

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}


