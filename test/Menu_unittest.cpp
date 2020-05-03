#include "header/Menu.h"
#include <gtest/gtest.h>
#include <string>

using namespace std;

TEST(ABOUT, IsAbout)
{
    string file_about = "res/about.txt";
    ASSERT_EQ(true, check_file(file_about));
}