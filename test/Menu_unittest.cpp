#include "header/Menu.h"
#include <gtest/gtest.h>
#include <string>

using namespace std;

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

TEST(NUMBER, IsNumber)
{
    ASSERT_EQ(true, is_valid_number("0"));
    ASSERT_EQ(true, is_valid_number("12345"));
    ASSERT_EQ(true, is_valid_number("8"));
}

TEST(NUMBER, IsNotNumber)
{
    ASSERT_EQ(false, is_valid_number(""));
    ASSERT_EQ(false, is_valid_number("-1"));
    ASSERT_EQ(false, is_valid_number("fd"));
    ASSERT_EQ(false, is_valid_number("4gfjf"));
    ASSERT_EQ(false, is_valid_number("!"));
    ASSERT_EQ(false, is_valid_number("."));
}

TEST(CHECK_FILE, IsRead)
{
    ASSERT_EQ(true, check_file("res/about.txt"));
}

TEST(CHECK_FILE, IsNotRead)
{
    ASSERT_EQ(false, check_file(""));
    ASSERT_EQ(false, check_file("hfjhfjhf.txt"));
    ASSERT_EQ(false, check_file("1234.txt"));
    ASSERT_EQ(false, check_file("home/verbs.txt"));
}

TEST(STONUM, IsNotNull)
{
    ASSERT_EQ(1, string_to_number("1"));
    ASSERT_EQ(2222, string_to_number("2222"));
    ASSERT_EQ(33584, string_to_number("33584"));
}

TEST(STONUM, IsNull)
{
    ASSERT_EQ(0, string_to_number(""));
    ASSERT_EQ(0, string_to_number("-1"));
    ASSERT_EQ(0, string_to_number("fd"));
    ASSERT_EQ(0, string_to_number("4gfjf"));
    ASSERT_EQ(0, string_to_number("!"));
    ASSERT_EQ(0, string_to_number("."));
    ASSERT_EQ(0, string_to_number("0"));
}