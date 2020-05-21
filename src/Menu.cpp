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
    cout << "\n=======================================================\n";
    cout << "| Welcome to IrregularVerbs                           |\n";
    cout << "| It's time to test your knowledge of irregular verbs |\n";
    while (!flag) {
        cout << "=======================================================\n";
        cout << "| 1.Begin to test your knowledge                      |\n";
        cout << "| 2.About program's                                   |\n";
        cout << "| 3.Rules and example of work                         |\n";
        cout << "| 4.Exit                                              |\n";
        cout << "=======================================================\n";
        cout << "\nYour choice: ";
        cin >> choice;
        if (!is_valid_choice(choice)) {
            cout << "\n\tIncorrect input!\n";
            continue;
        }
        switch (choice[0]) {
        case '1':
            if (!check_file(FILE_VERBS)) {
                cout << "\n\tFile missing\n";
            } else {
                start();
            }
            break;
        case '2':
            if (!check_file(FILE_ABOUT)) {
                cout << "\n\tFile missing\n";
            } else {
                txt_output(FILE_ABOUT);
            }
            break;
        case '3':
            if (!check_file(FILE_RULES)) {
                cout << "\n\tFile missing\n";
            } else {
                txt_output(FILE_RULES);
            }
            break;
        case '4':
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
    return !(choice[0] < '1' || choice[0] > '4');
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
    string number_of_verbs;
    cout << "Enter number of verbs to check: ";
    cin >> number_of_verbs;
    int point = string_to_number(number_of_verbs);
    if (point == 0) {
        cout << "\n\tIncorrect input!\n";
    } else {
        int right_value = 0;
        const auto verbs = read_from_file(FILE_VERBS);
        const auto verb_indexes = rand_verbs(verbs.size());
        vector<string> user_verbs;
        string word;
        int temp;
        for (int i = 0; i < point; ++i) {
            user_verbs.clear();
            print_random_verb(verbs[verb_indexes[i]]);
            cout << "Past Simple: ";
            cin >> word;
            user_verbs.emplace_back(word);
            cout << "Past Participle: ";
            cin >> word;
            user_verbs.emplace_back(word);
            temp = check_verbs(user_verbs, verbs[verb_indexes[i]]);
            accrual_of_points(temp, right_value);
            message_right(temp);
            message_wrong(verbs[verb_indexes[i]], temp);
        }
        int percent;
        percent = result(point, right_value);
        message_mark(percent);
    }
}

bool check_file(const string& file)
{
    ifstream fin(file);
    return fin.is_open();
}

void txt_output(const string& file)
{
    cout << "\n";
    ifstream fin(file);
    char ch;
    while (fin.get(ch)) {
        cout << ch;
    }
    fin.close();
}
