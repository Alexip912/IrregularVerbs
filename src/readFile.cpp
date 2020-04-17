#include <cstring>
#include <fstream>
#include <string>
#include <iostream>

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