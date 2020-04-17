#include "printForm.hpp"
#include "equality.hpp"
#include "message.hpp"
#include <iostream>
#include <string>
using namespace std;

void checkVerbs(const int *array, int size, const string verbs_array[121][3], int &wrongValue, int &rightValue) {
    string userVerb, form, word;
    int Simple = 0, Participle = 0, right = 0, wrong = 0;
    for (int i = 0; i < size; ++i) {
        Simple = 0, Participle = 0, right = 0, wrong = 0;
        printRandomVerb(verbs_array, i, array);
        for (int j = 1; j < 3; ++j) {
            printForm(verbs_array, i, j, array);
            cin >> userVerb;
            if (equality_right(verbs_array, i, j, array, userVerb, Simple, Participle, right) == 1) {
                ++rightValue;
            }
            (message_right(j, right));
            if (equality_wrong(verbs_array, i, j, array, userVerb, Simple, Participle, wrong, form, word) == 1) {
                ++wrongValue;
            }
            message_wrong(verbs_array, i, j, array, Simple, Participle, wrong, form, word);
        }
    }
}