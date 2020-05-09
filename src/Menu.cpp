#include "header/Menu.h"
#include "header/Verb.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int join()
{
    bool flag = false;
    string choice;
    cout << "Welcome to IrregularVerbs\n";
    cout << "It's time to test your knowledge of irregular verbs\n";
    while (!flag) {
        cout << "\n1.Begin to test your knowledge\n";
        cout << "2.About program's\n";
        cout << "3.Exit\n";
        cout << "\nYour choice: ";
        cin >> choice;
        if (!is_valid_choice(choice)) {
            cout << "\nIncorrect input!\n";
            continue;
        }
        switch (choice[0]) {
        case '1':
            start();
            break;
        case '2':
            if (!check_file(FILE_ABOUT)) {
                cout << "\tFile missing\n";
            } else {
                cout << "\n";
                about(FILE_ABOUT);
            }
            break;
        case '3':
            flag = true;
        }
    }
    return 0;
}

bool is_valid_choice(const string& choice)
{
    if (choice.length() != 1) {
        return false;
    }
    return !(choice[0] < '1' || choice[0] > '3');
}

bool is_valid_number(const string& number_of_verbs)
{
    for (char number_of_verb : number_of_verbs) {
        if (!isdigit(number_of_verb)) {
            return false;
        }
    }
    return true;
}

int string_to_number(const string& number_of_verbs)
{
    int number;
    if (is_valid_number(number_of_verbs)) {
        number = stoi(number_of_verbs);
        return number;
    }
    return 0;
}

void start()
{
    int right_value = 0;
    string number_of_verbs;
    cout << "Enter number of verbs to check: ";
    cin >> number_of_verbs;
    int point = string_to_number(number_of_verbs);
    if (point == 0) {
        cout << "\nIncorrect input!\n";
    } else if (!read_from_file(FILE_VERBS)) {
        cout << "\n\tFile missing\n";
    } else {
        DataOfCurrentVerb object;
        int array_of_number[point];
        rand_verbs(array_of_number, point);
        right_value = check_verbs(array_of_number, point, object);
        cout << "\nYour result: " << result(point, right_value) << "%\n";
    }
}

bool check_file(const string& file)
{
    ifstream fin;
    fin.open(file);
    return fin.is_open();
}

void about(const string& file)
{
    ifstream fin;
    fin.open(file);
    char ch;
    while (fin.get(ch)) {
        cout << ch;
    }
    fin.close();
}
