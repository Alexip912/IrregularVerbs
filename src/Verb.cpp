#include "header/Verb.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <vector>

using namespace std;

void read_from_file(
        const string& file_path, vector<FormsOfVerb>& array_of_verbs)
{
    ifstream file(file_path);
    for (auto& array_of_verb : array_of_verbs) {
        getline(file, array_of_verb.infinitive, ' ');
        getline(file, array_of_verb.simple, ' ');
        getline(file, array_of_verb.participle, '\n');
        array_of_verb.simple_flag = true;
        array_of_verb.participle_flag = true;
    }
}

void rand_verbs(int* array, int size)
{
    random_device rd;
    mt19937 g(rd());
    vector<int> rand_array;
    rand_array.resize(121);
    for (int i = 0; i < 121; ++i) {
        rand_array[i] = i;
    }
    shuffle(rand_array.begin(), rand_array.end(), g);
    for (int i = 0; i < size; ++i) {
        array[i] = rand_array[i];
    }
}

void message_right(const FormsOfVerb& verb)
{
    if (verb.simple_flag && verb.participle_flag) {
        cout << "All required forms entered correctly.\n"
             << "Move on to the next.\n";
    }
}

void message_wrong(const FormsOfVerb& verb)
{
    if (!verb.simple_flag && !verb.participle_flag) {
        cout << "You made the mistake in form Past Simple and Past Participle. "
                "Right version: "
             << verb.simple << " and " << verb.participle
             << "\nMove on to the next.\n";
    } else if (!verb.simple_flag && verb.participle_flag) {
        cout << "You made the mistake in form Past Simple. "
             << "Right version: " << verb.simple << "\nMove on to the next.\n";
    } else if (verb.simple_flag && !verb.participle_flag) {
        cout << "You made the mistake in form Past Participle. "
             << "Right version: " << verb.participle
             << "\nMove on to the next.\n";
    }
}

void print_form(int index)
{
    if (index == 1) {
        cout << "Past Simple: ";
    }
    if (index == 2) {
        cout << "Past Participle: ";
    }
}

void print_random_verb(const FormsOfVerb& verb)
{
    if (verb.simple == "was") {
        cout << "\nWrite in the singular\n";
    } else if (verb.simple == "were") {
        cout << "\nWrite in the plural\n";
    }
    cout << "\nYour verb: " << verb.infinitive;
    cout << "\nInput other form\n";
}

bool check_verbs(const string& reference_verb, const string& user_verb)
{
    return reference_verb == user_verb;
}

int result(int number_of_verbs, int right_value)
{
    if (number_of_verbs <= 0) {
        return 0;
    }
    int result = int((float(right_value) / (float(number_of_verbs) * 2)) * 100);
    return result;
}
