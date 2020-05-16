#include "header/Verb.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <vector>

using namespace std;

vector<VerbForms> read_from_file(const string& file_path)
{
    vector<VerbForms> verbs;
    VerbForms forms;
    ifstream file(file_path);
    while (!file.eof()) {
        getline(file, forms.infinitive, ' ');
        getline(file, forms.simple, ' ');
        getline(file, forms.participle, '\n');
        verbs.emplace_back(forms);
    }
    file.close();
    return verbs;
}

vector<int> rand_verbs(int size)
{
    random_device rd;
    mt19937 g(rd());
    vector<int> verb_indexes;
    verb_indexes.reserve(size);
    for (int i = 0; i < size; ++i) {
        verb_indexes.emplace_back(i);
    }
    shuffle(verb_indexes.begin(), verb_indexes.end(), g);
    return verb_indexes;
}

int check_verbs(const vector<string>& user_verbs, const VerbForms& reference)
{
    if (user_verbs[0] == reference.simple) {
        if (user_verbs[1] == reference.participle) {
            return 2;
        }
        return 1;
    }
    if (user_verbs[1] == reference.participle) {
        return -1;
    }
    return 0;
}

int result(int number_of_verbs, int right_value)
{
    if (number_of_verbs <= 0) {
        return 0;
    }
    int result = int((float(right_value) / (float(number_of_verbs) * 2)) * 100);
    return result;
}

void accrual_of_points(int temp, int& right_value)
{
    if (temp == 2) {
        right_value += 2;
    }
    if (temp == 1) {
        right_value += 1;
    }
    if (temp == -1) {
        right_value += 1;
    }
}

void message_right(int result)
{
    if (result == 2) {
        cout << "All required forms entered correctly.\n"
             << "Move on to the next.\n";
    }
}

void message_wrong(const VerbForms& verb, int result)
{
    if (result == 0) {
        cout << "You made the mistake in form Past Simple and Past Participle. "
                "Right version: "
             << verb.simple << " and " << verb.participle
             << "\nMove on to the next.\n";
    } else if (result == -1) {
        cout << "You made the mistake in form Past Simple. "
             << "Right version: " << verb.simple << "\nMove on to the next.\n";
    } else if (result == 1) {
        cout << "You made the mistake in form Past Participle. "
             << "Right version: " << verb.participle
             << "\nMove on to the next.\n";
    }
}

void print_random_verb(const VerbForms& verb)
{
    if (verb.simple == "was") {
        cout << "\nWrite in the singular\n";
    } else if (verb.simple == "were") {
        cout << "\nWrite in the plural\n";
    }
    cout << "\nYour verb: " << verb.infinitive;
    cout << "\nInput other form\n";
}
