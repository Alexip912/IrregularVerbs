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