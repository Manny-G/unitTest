#include "commonUnitTestHeader.h"
using namespace std;

namespace testFixture
{
	TEST_F(unitTests, unitTestInsSortInc)
	{
		EXPECT_TRUE(unitTestInsSortInc());
	}

	TEST_F(unitTests, unitTestInsSortIncRec)
	{
		EXPECT_TRUE(unitTestInsSortIncRec());
	}
}

