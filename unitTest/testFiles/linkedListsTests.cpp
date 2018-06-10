#include "commonUnitTestHeader.h"
using namespace std;

namespace testFixture
{
	TEST_F(unitTests, removeDuplicates)
	{
		singlyLinkedList<int> base = genBaseListTest1();
		singlyLinkedList<int> soln = genSolutionListTest1();
		base.removeDuplicates();
		EXPECT_EQ(base, soln);
	}
}

