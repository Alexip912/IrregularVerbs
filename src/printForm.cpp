#include <iostream>
using namespace std;

void printRandomVerb(const string verbs_array[121][3], int i, const int *array) {
    cout << "Your verb: " << verbs_array[array[i]][0];
    cout << endl
         << "Input other form" << endl;
}

void printForm(const string verbs_array[121][3], int i, int j, const int *array) {
    if (j == 1) cout << "Past Simple: ";
    if (j == 2) cout << "Past Participle: ";
}