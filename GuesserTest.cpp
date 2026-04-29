/**
 * Unit Tests for the class
**/

#include <gtest/gtest.h>
#include "Guesser.h"

class GuesserTest : public ::testing::Test
{
	protected:
		GuesserTest(){} //constructor runs before each test
		virtual ~GuesserTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(GuesserTest, DistIsZero)
{
	Guesser object("Secret");
	ASSERT_EQ(object.distance("Secret"), 0);
}

TEST(GuesserTest, DistCount_DiffChar)
{
	Guesser object("Secret");
	ASSERT_EQ(object.distance("SecRet"), 1);
}

TEST(GuesserTest, DistCount_ExtChar)
{
	Guesser object("Secret");
	ASSERT_EQ(object.distance("Secrets"), 1);
}

TEST(GuesserTest, DistCount_MissedChar)
{
  Guesser object("Secret");
  ASSERT_EQ(object.distance("Secre"), 1);
}

TEST(GuesserTest, DistCap_SLength)
{
  Guesser object("Secret");
  ASSERT_EQ(object.distance("CompletelyDifferent"), 6);
}


