#include "header/Menu.h"
#include <gtest/gtest.h>
#include <string>

using namespace std;

TEST(ABOUT, IsAbout)
{
    ASSERT_EQ(true, check_file("res/about.txt"));
}

TEST(ABOUT, IsNotAbout)
{
    ASSERT_EQ(false, check_file(""));
    ASSERT_EQ(false, check_file("fhhfhjfjf.txt"));
    ASSERT_EQ(false, check_file("235456.txt"));
    ASSERT_EQ(false, check_file("home/about.txt"));
}

TEST(CHOICE, IsChoice)
{
    ASSERT_EQ(true, is_valid_choice("1"));
    ASSERT_EQ(true, is_valid_choice("2"));
    ASSERT_EQ(true, is_valid_choice("3"));
}

TEST(CHOICE, IsNotChoice)
{
    ASSERT_EQ(false, is_valid_choice(""));
    ASSERT_EQ(false, is_valid_choice("222"));
    ASSERT_EQ(false, is_valid_choice("fghfghfh"));
    ASSERT_EQ(false, is_valid_choice("f"));
    ASSERT_EQ(false, is_valid_choice("2d"));
    ASSERT_EQ(false, is_valid_choice("1235448"));
    ASSERT_EQ(false, is_valid_choice("!"));
    ASSERT_EQ(false, is_valid_choice("."));
}