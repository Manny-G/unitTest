#include "commonUnitTestHeader.h"
using namespace std;

namespace testFixture
{
	TEST_F(unitTests, removeDuplicates)
	{
		LinkedList<int> base = genBaseListTest1();
		LinkedList<int> soln = genSolutionListTest1();
		base.removeDuplicates();
		EXPECT_EQ(base, soln);
	}
}

