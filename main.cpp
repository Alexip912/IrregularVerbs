#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;

void readFromFile(string arr[121][3], const string &filePath) {
    ifstream file(filePath);
    for (int i = 0; i < 121; i++) {
        for (int j = 0; j < 3; j++) {
            getline(file, arr[i][j], ' ');
            j++;
            getline(file, arr[i][j], ' ');
            j++;
            getline(file, arr[i][j], '\n');
        }
    }
}

void printInfinitiveForm(string const arr[200][3], const int &n)
{
    if(n<200&&n>=0) {
        cout << "Infinitive form: ";
        cout << arr[n][0] << endl;
    }
    else cout << "Something was wrong.";
}

void fillrand(int *array, int size) {
    srand(time(nullptr));
    bool there;
    int element;
    for (int i = 0; i < size;) {
        there = false;
        element = rand() % 121;
        for (int j = 0; j < i; ++j) {
            if (array[j] == element) {
                there = true;
                break;
            }
        }
        if (!there) {
            array[i] = element;
            ++i;
        }
    }
}

void printRandomVerbs(const int *array, int size, const string verbs_array[121][3]) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << " " << verbs_array[array[i]][j];
        }
        cout << endl;
    }
}

int equality_right(const string verbs_array[121][3], int i, int j, const int *array, const string &userVerb, int &Simple, int &Participle, int &right) {
    if (verbs_array[array[i]][j] == userVerb) {
        ++right;
        if (j == 1) Simple = 1;
        if (j == 2) Participle = 1;
        return 1;
    } else
        return -1;
}

int equality_wrong(const string verbs_array[121][3], int i, int j, const int *array, const string &userVerb, int &Simple, int &Participle, int &wrong, string &form, string &word) {
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

void printForm(const string verbs_array[121][3], int i, int j, const int *array) {
    if (j == 1) cout << "Past Simple: ";
    if (j == 2) cout << "Past Participle: ";
}

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

int main()
{	
    int number_of_verbs;
    cout << "Enter number of verbs to check" << endl;
    cin >> number_of_verbs;
    int *a = new int[number_of_verbs];
    string verbs_array[121][3];
    delete[] a;
	return 0;
}