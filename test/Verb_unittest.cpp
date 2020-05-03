#include "header/Verb.h"
#include <gtest/gtest.h>
#include <string>

using namespace std;

TEST(EQUALITY_RIGHT, IsRight)
{
    int array_for_test[3] = {0, 1, 2};
    Verb test;
    string filePath = "res/verbs.txt";
    test.read_from_file(filePath);
    test.Set_user_verb("arise");
    test.Set_index_i(0);
    test.Set_index_j(0);
    ASSERT_EQ(true, test.equality_right(array_for_test));
    test.Set_user_verb("awake");
    test.Set_index_i(1);
    test.Set_index_j(0);
    ASSERT_EQ(true, test.equality_right(array_for_test));
    test.Set_user_verb("be");
    test.Set_index_i(2);
    test.Set_index_j(0);
    ASSERT_EQ(true, test.equality_right(array_for_test));
}

TEST(EQUALITY_RIGHT, IsNotRight)
{
    int array_for_test[3] = {0, 1, 2};
    Verb test;
    string filePath = "res/verbs.txt";
    test.read_from_file(filePath);
    test.Set_user_verb("hjfhjfhjf");
    test.Set_index_i(0);
    test.Set_index_j(0);
    ASSERT_EQ(false, test.equality_right(array_for_test));
    test.Set_user_verb("");
    test.Set_index_i(1);
    test.Set_index_j(0);
    ASSERT_EQ(false, test.equality_right(array_for_test));
    test.Set_user_verb("1234");
    test.Set_index_i(2);
    test.Set_index_j(0);
    ASSERT_EQ(false, test.equality_right(array_for_test));
}

TEST(EQUALITY_WRONG, IsWrong)
{
    int array_for_test[3] = {0, 1, 2};
    Verb test;
    string filePath = "res/verbs.txt";
    test.read_from_file(filePath);
    test.Set_user_verb("be");
    test.Set_index_i(0);
    test.Set_index_j(0);
    ASSERT_EQ(true, test.equality_wrong(array_for_test));
    test.Set_user_verb("was");
    test.Set_index_i(1);
    test.Set_index_j(0);
    ASSERT_EQ(true, test.equality_wrong(array_for_test));
    test.Set_user_verb("been");
    test.Set_index_i(2);
    test.Set_index_j(0);
    ASSERT_EQ(true, test.equality_wrong(array_for_test));
}

TEST(EQUALITY_WRONG, IsNotWrong)
{
    int array_for_test[3] = {0, 1, 2};
    Verb test;
    string filePath = "res/verbs.txt";
    test.read_from_file(filePath);
    test.Set_user_verb("arose");
    test.Set_index_i(0);
    test.Set_index_j(1);
    ASSERT_EQ(false, test.equality_wrong(array_for_test));
    test.Set_user_verb("awoke");
    test.Set_index_i(1);
    test.Set_index_j(1);
    ASSERT_EQ(false, test.equality_wrong(array_for_test));
    test.Set_user_verb("was");
    test.Set_index_i(2);
    test.Set_index_j(1);
    ASSERT_EQ(false, test.equality_wrong(array_for_test));
}