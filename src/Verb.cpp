#include "header/Verb.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <random>
#include <string>

using namespace std;

bool Verb::read_from_file(const string& filePath)
{
    ifstream file(filePath);
    if (file.is_open()) {
        for (auto& array_of_verb : array_of_verbs) {
            for (int j = 0; j < 3; j++) {
                getline(file, array_of_verb[j], ' ');
                j++;
                getline(file, array_of_verb[j], ' ');
                j++;
                getline(file, array_of_verb[j], '\n');
            }
        }
        return true;
    } else {
        return false;
    }
}
void Verb::rand_verbs(int* array, int size)
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

bool Verb::equality_right(const int* array)
{
    if (array_of_verbs[array[index_i]][index_j] == userVerb) {
        ++right;
        if (index_j == 1)
            simple = true;
        if (index_j == 2)
            participle = true;
        return true;
    } else {
        return false;
    }
}
bool Verb::equality_wrong(const int* array)
{
    if (array_of_verbs[array[index_i]][index_j] != userVerb) {
        ++wrong;
        if (!simple) {
            form = "Past Simple";
            word = array_of_verbs[array[index_i]][1];
        }
        if (!participle && index_j == 2) {
            form = "Past Participle";
            word = array_of_verbs[array[index_i]][2];
        }
        return true;
    } else {
        return false;
    }
}
void Verb::message_right() const
{
    if (index_j == 2 && right == 2) {
        cout << "All required forms entered correctly." << endl
             << "Move on to the next." << endl;
    }
}
void Verb::message_wrong(const int* array)
{
    if (index_j == 2 && !simple && !participle && wrong == 2) {
        cout << "You made the mistake in form Past Simple and Past Participle. "
                "Right version: "
             << array_of_verbs[array[index_i]][1] << " and "
             << array_of_verbs[array[index_i]][2] << endl
             << "Move on to the next." << endl;
    } else if (index_j == 2 && (!simple || !participle)) {
        cout << "You made the mistake in form " << form
             << ". Right version: " << word << endl
             << "Move on to the next." << endl;
    }
}

void Verb::print_form() const
{
    if (index_j == 1) {
        cout << "Past Simple: ";
    }
    if (index_j == 2) {
        cout << "Past Participle: ";
    }
}
void Verb::print_random_verb(const int* array)
{
    if (array_of_verbs[array[index_i]][1] == "was") {
        cout << endl << "Write in the singular" << endl;
    } else if (array_of_verbs[array[index_i]][1] == "were") {
        cout << endl << "Write in the plural" << endl;
    }
    cout << endl << "Your verb: " << array_of_verbs[array[index_i]][0];
    cout << endl << "Input other form" << endl;
}
void Verb::check_verbs(const int* array, int size)
{
    for (int i = 0; i < size; ++i) {
        index_i = i;
        simple = false, participle = false, right = 0, wrong = 0;
        print_random_verb(array);
        for (int j = 1; j < 3; ++j) {
            index_j = j;
            print_form();
            cin >> userVerb;
            if (equality_right(array)) {
                ++right_value;
            }
            message_right();
            equality_wrong(array);
            message_wrong(array);
        }
    }
}

int Verb::result(int number_of_verbs) const
{
    if (number_of_verbs == 0) {
        return 0;
    } else {
        int result_right = int(
                (float(right_value) / (float(number_of_verbs) * 2)) * 100);
        return result_right;
    }
}