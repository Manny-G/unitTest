#include "commonUnitTestHeader.h"
using namespace std;

namespace testFixture
{
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

	TEST_F(unitTests, checkPermutations)
	{
		EXPECT_TRUE(isPermutation("loleh", "hello"));
		EXPECT_TRUE(isPermutation("fycbzaedx", "abcdefxyz"));
		EXPECT_FALSE(isPermutation("fycbzaedx", "abcdefoxyz"));
	}

	TEST_F(unitTests, urlIfy)
	{
		EXPECT_EQ("Mr%20John%20Smith", urlIfy("Mr John Smith    ", 13));
		EXPECT_EQ("Mr%20John%20Smith", urlIfy("    Mr John Smith    ", 13));
		EXPECT_EQ("Mr%20John%20Smith", urlIfy("Mr John Smith", 13));
	}

	TEST_F(unitTests, palinPerm)
	{
		EXPECT_TRUE(palinPerm("Tact coa"));
		EXPECT_TRUE(palinPerm("taco cat"));
		EXPECT_TRUE(palinPerm("atco cta"));
		EXPECT_TRUE(palinPerm("Red rum, sir, is murder"));
		EXPECT_TRUE(palinPerm("Eva, can I see bees in a cave?"));
		EXPECT_TRUE(palinPerm("A Toyota’s a Toyota."));
	}

	TEST_F(unitTests, oneAway)
	{
		EXPECT_TRUE(oneAway("pale", "ple"));
		EXPECT_TRUE(oneAway("pale", "pales"));
		EXPECT_TRUE(oneAway("pale", "bale"));
		EXPECT_FALSE(oneAway("pale", "bae"));
	}

	TEST_F(unitTests, stringCompression)
	{
		EXPECT_EQ("a2bcd3e", stringCompression("aabcddde"));
		EXPECT_EQ("a3bc2de3", stringCompression("aaabccdeee"));
		EXPECT_EQ("ba3bc2ade3ad", stringCompression("baaabccadeeead"));
		EXPECT_EQ("abcdefdefab", stringCompression("abcdefdefab"));
	}
}

