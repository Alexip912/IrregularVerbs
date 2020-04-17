#include <iostream>
#include <string>
using namespace std;

void printRandomVerb(string const verbs_array[121][3], int i, int const *array) {
    cout << "Your verb: " << verbs_array[array[i]][0];
    cout << endl
         << "Input other form" << endl;
}

void printForm(string const verbs_array[121][3], int i, int j, int const *array) {
    if (j == 1) cout << "Past Simple: ";
    if (j == 2) cout << "Past Participle: ";
}