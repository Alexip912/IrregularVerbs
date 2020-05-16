#include "header/Verb.h"
#include <gtest/gtest.h>
#include <string>

using namespace std;


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
