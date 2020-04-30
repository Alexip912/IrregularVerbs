#include "Verb.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

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
        if (!is_valid_choice()) {
            cout << "Incorrect input!" << endl;
            continue;
        }
        switch (choice[0]) {
        case '1':
            start();
            break;
        case '2':
            about();
            break;
        case '3':
            flag = true;
        }
    }
    return 0;
}
