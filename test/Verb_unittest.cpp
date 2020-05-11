#include "header/Verb.h"
#include <gtest/gtest.h>
#include <string>

using namespace std;

TEST(CHECK, IsRight)
{
    ASSERT_EQ(true, check_verbs("be", "be"));
    ASSERT_EQ(true, check_verbs("was", "was"));
    ASSERT_EQ(true, check_verbs("been", "been"));
}

TEST(CHECK, IsWrong)
{
    ASSERT_EQ(false, check_verbs("be", "can"));
    ASSERT_EQ(false, check_verbs("be", "was"));
    ASSERT_EQ(false, check_verbs("been", "was"));
}

TEST(RESULT, IsResult)
{
    ASSERT_EQ(1, result(100, 2));
    ASSERT_EQ(100, result(25, 50));
    ASSERT_EQ(25, result(20, 10));
}

TEST(RESULT, IsNotResult)
{
    ASSERT_EQ(0, result(0, 0));
    ASSERT_EQ(0, result(-5, 2));
    ASSERT_EQ(0, result(-25, 7));
}
