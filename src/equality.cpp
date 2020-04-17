#include <string>
using namespace std;

int equality_right(string const verbs_array[121][3], int i, int j, int const *array, string const &userVerb, int &Simple, int &Participle, int &right) {
    if (verbs_array[array[i]][j] == userVerb) {
        ++right;
        if (j == 1) Simple = 1;
        if (j == 2) Participle = 1;
        return 1;
    } else
        return -1;
}

int equality_wrong(string const verbs_array[121][3], int i, int j, int const *array, string const &userVerb, int &Simple, int &Participle, int &wrong, string &form, string &word) {
    if (verbs_array[array[i]][j] != userVerb) {
        ++wrong;
        if (Simple != 1) {
            form = "Past Simple";
            word = verbs_array[array[i]][1];
        }
        if (Participle != 1 && j == 2) {
            form = "Past Participle";
            word = verbs_array[array[i]][2];
        }
        return 1;
    } else
        return -1;
}