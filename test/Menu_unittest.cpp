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