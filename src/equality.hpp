#ifndef EQUALITY
#define EQUALITY

int equality_right(const string verbs_array[121][3], int i, int j, const int *array, const string &userVerb, int &Simple, int &Participle, int &right);

int equality_wrong(const string verbs_array[121][3], int i, int j, const int *array, const string &userVerb, int &Simple, int &Participle, int &wrong, string &form, string &word);

#endif