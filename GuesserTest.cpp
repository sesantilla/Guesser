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

TEST(GuesserTest, Constr_ScrtLngr_32Char)
{
  Guesser object("12345678901234567890123456789012EXTRA");
  ASSERT_TRUE(object.match("12345678901234567890123456789012"));
}

TEST(GuesserTest, MatchRtrn_T_CrrtGuess)
{
  Guesser object("Secret");
  ASSERT_TRUE(object.match("Secret"));
}

TEST(GuesserTest, MatchRtrn_F_WrngGuess)
{
  Guesser object("Secret");
  ASSERT_FALSE(object.match("Secrex"));
}

TEST(GuesserTest, ThreeWrng_Guess_Close)
{
  Guesser object("Secret");

  ASSERT_FALSE(object.match("Secrex"));
  ASSERT_FALSE(object.match("Secrey"));
  ASSERT_FALSE(object.match("Secrez"));

  ASSERT_FALSE(object.match("Secret"));
}

TEST(GuesserTest, BigDist_LocksGuesser)
{
  Guesser object("Secret");

  ASSERT_FALSE(object.match("Wrong"));
  ASSERT_FALSE(object.match("Secret"));
}

TEST(GuesserTest, CorrGuess_NoUse_RmainGuess)
{
  Guesser object("Secret");

  ASSERT_TRUE(object.match("Secret"));
  ASSERT_TRUE(object.match("Secret"));
  ASSERT_TRUE(object.match("Secret"));
  ASSERT_TRUE(object.match("Secret"));
}

