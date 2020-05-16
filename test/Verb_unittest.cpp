#include "header/Verb.h"
#include <gtest/gtest.h>
#include <string>

using namespace std;

TEST(READ, IsRead)
{
    const auto verbs = read_from_file("res/verbs.txt");
    VerbForms forms;
    forms.infinitive = "arise";
    forms.simple = "arose";
    forms.participle = "arisen";
    ASSERT_EQ(forms.infinitive, verbs[0].infinitive);
    ASSERT_EQ(forms.simple, verbs[0].simple);
    ASSERT_EQ(forms.participle, verbs[0].participle);
    forms.infinitive = "stand";
    forms.simple = "stood";
    forms.participle = "stood";
    ASSERT_EQ(forms.infinitive, verbs[100].infinitive);
    ASSERT_EQ(forms.simple, verbs[100].simple);
    ASSERT_EQ(forms.participle, verbs[100].participle);
    forms.infinitive = "bet";
    forms.simple = "bet";
    forms.participle = "bet";
    ASSERT_EQ(forms.infinitive, verbs[9].infinitive);
    ASSERT_EQ(forms.simple, verbs[9].simple);
    ASSERT_EQ(forms.participle, verbs[9].participle);
    forms.infinitive = "write";
    forms.simple = "wrote";
    forms.participle = "written";
    ASSERT_EQ(forms.infinitive, verbs[120].infinitive);
    ASSERT_EQ(forms.simple, verbs[120].simple);
    ASSERT_EQ(forms.participle, verbs[120].participle);
}

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
    user_verbs.clear();
    word = "clang";
    user_verbs.emplace_back(word);
    word = "clung";
    user_verbs.emplace_back(word);
    ASSERT_EQ(-1, check_verbs(user_verbs, verbs[21]));
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
    user_verbs.clear();
    word = ".";
    user_verbs.emplace_back(word);
    word = "132";
    user_verbs.emplace_back(word);
    ASSERT_EQ(0, check_verbs(user_verbs, verbs[3]));
    user_verbs.clear();
    word = "";
    user_verbs.emplace_back(word);
    word = "writt n";
    user_verbs.emplace_back(word);
    ASSERT_EQ(0, check_verbs(user_verbs, verbs[120]));
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
