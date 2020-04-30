#include "Verb.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

Verb irregular_verbs;

string filePath = "res/verbs.txt";

bool read = irregular_verbs.read_from_file(filePath);

int Join()
{
    bool flag = false;
    string choice;
    cout << "Welcome to IrregularVerbs" << endl;
    cout << "It's time to test your knowledge of irregular verbs" << endl;
    while (!flag) {
        cout << std::endl << "1.Begin to test your knowledge" << endl;
        cout << "2.About program's" << endl;
        cout << "3.Exit" << endl;
        cout << endl << "Your choice: ";
        getline(cin, choice);
        if (!is_valid_choice(choice)) {
            cout << "Incorrect input!" << endl;
            continue;
        }
        switch (choice[0]) {
        case '1':
            Start();
            break;
        case '2':
            About();
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

void Start()
{
    string number_of_verbs;
    cout << "Enter number of verbs to check: ";
    getline(cin, number_of_verbs);
    int point = is_valid_number(number_of_verbs);
    if (point == 0) {
        return;
    } else {
        if (read) {
            int* array_of_number = new int[point];
            Verb::rand_verbs(array_of_number, point);
            irregular_verbs.check_verbs(array_of_number, point);
            cout << endl
                 << "Your result: " << irregular_verbs.result(point) << "%"
                 << endl;
            delete[] array_of_number;
            getline(cin, choice);
        } else {
            cout << endl << "\tFile missing" << endl;
            return;
        }
    }
}

int is_valid_number(const string& number_of_verbs)
{
    int i = 0, number = 0;
    while (isdigit(number_of_verbs[i])) {
        i++;
    }
    if (i == int(number_of_verbs.length())) {
        number = atoi(number_of_verbs.c_str());
        return number;
    } else {
        cout << endl << "Incorrect input!" << endl;
        return 0;
    }
}

bool About(const string& file_about)
{
    cout << endl;
    ifstream fin;
    fin.open(file_about);
    if (!fin.is_open()) {
        return false;
    } else {
        char ch;
        while (fin.get(ch)) {
            cout << ch;
        }
    }
    fin.close();
    return true;
}
