#include "header/Verb.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <random>
#include <string>

using namespace std;

bool simple{}, participle{};
std::string array_of_verbs[121][3];

bool read_from_file(const string& file_path)
{
    ifstream file(file_path);
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
    }
    return file.is_open();
}

void rand_verbs(int* array, const int& size)
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

void message_right()
{
    if (simple && participle) {
        cout << "All required forms entered correctly.\n"
             << "Move on to the next.\n";
    }
}

void message_wrong(const int& index, const DataOfCurrentVerb& object)
{
    if (!simple && !participle) {
        cout << "You made the mistake in form Past Simple and Past Participle. "
                "Right version: "
             << array_of_verbs[index][1] << " and " << array_of_verbs[index][2]
             << "\nMove on to the next.\n";
    } else if (!simple || !participle) {
        cout << "You made the mistake in form " << object.form
             << ". Right version: " << object.word
             << "\nMove on to the next.\n";
    }
}

void print_form(const int& index)
{
    if (index == 1) {
        cout << "Past Simple: ";
    }
    if (index == 2) {
        cout << "Past Participle: ";
    }
}

void print_random_verb(const int& index)
{
    if (array_of_verbs[index][1] == "was") {
        cout << "\nWrite in the singular\n";
    } else if (array_of_verbs[index][1] == "were") {
        cout << "\nWrite in the plural\n";
    }
    cout << "\nYour verb: " << array_of_verbs[index][0];
    cout << "\nInput other form\n";
}

int check_verbs(const int* array, const int& size, DataOfCurrentVerb& object)
{
    int right_value = 0;
    string user_verb;
    for (int i = 0; i < size; ++i) {
        simple = false, participle = false;
        print_random_verb(array[i]);
        for (int j = 1; j < 3; ++j) {
            print_form(j);
            cin >> user_verb;
            if (array_of_verbs[array[i]][j] == user_verb) {
                if (j == 1)
                    simple = true;
                if (j == 2)
                    participle = true;
                ++right_value;
            } else {
                if (j == 1) {
                    object.form = "Past Simple";
                    object.word = array_of_verbs[array[i]][j];
                }
                if (j == 2) {
                    object.form = "Past Participle";
                    object.word = array_of_verbs[array[i]][j];
                }
            }
        }
        message_right();
        message_wrong(array[i], object);
    }
    return right_value;
}

int result(const int& number_of_verbs, const int& right_value)
{
    if (number_of_verbs <= 0) {
        return 0;
    }
    int result = int((float(right_value) / (float(number_of_verbs) * 2)) * 100);
    return result;
}
