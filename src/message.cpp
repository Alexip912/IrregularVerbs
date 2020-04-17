#include <iostream>
#include <string>
using namespace std;

void message_right(int j, int &right) {
    if (j == 2 && right == 2) {
        cout << "All required forms entered correctly." << endl
             << "Move on to the next." << endl;
    }
}

void message_wrong(const string verbs_array[121][3], int i, int j, const int *array, int &Simple, int &Participle, int &wrong, string &form, string &word) {
    if (j == 2 && Simple != 1 && Participle != 1 && wrong == 2) {
        cout << "You made the mistake in form Past Simple and Past Participle. Right version: " << verbs_array[array[i]][1] << " and " << verbs_array[array[i]][2] << endl
             << "Move on to the next." << endl;
    } else if (j == 2 && (Simple != 1 || Participle != 1)) {
        cout << "You made the mistake in form " << form << ". Right version: " << word << endl
             << "Move on to the next." << endl;
    }
}