#include "header/Verb.h"
#include <gtest/gtest.h>
#include <string>

using namespace std;

TEST(CHECK, IsRight)
{
    const auto verbs = read_from_file("res/verbs.txt");
    vector<string> user_verbs;
    string word = "was";
    user_verbs.emplace_back(word);
    word = "been";
    user_verbs.emplace_back(word);
    ASSERT_EQ(2, check_verbs(user_verbs, verbs[2]));
    user_verbs.clear();
    word = "became";
    user_verbs.emplace_back(word);
    word = "become";
    user_verbs.emplace_back(word);
    ASSERT_EQ(2, check_verbs(user_verbs, verbs[6]));
    user_verbs.clear();
    word = "wound";
    user_verbs.emplace_back(word);
    word = "wount";
    user_verbs.emplace_back(word);
    ASSERT_EQ(1, check_verbs(user_verbs, verbs[119]));
}

TEST(CHECK, IsNotRight)
{
    const auto verbs = read_from_file("res/verbs.txt");
    vector<string> user_verbs;
    string word = "been";
    user_verbs.emplace_back(word);
    word = "was";
    user_verbs.emplace_back(word);
    ASSERT_EQ(0, check_verbs(user_verbs, verbs[2]));
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
