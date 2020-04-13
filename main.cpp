#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;

void readFromFile(string arr[200][3], string filePath)
{
    ifstream file(filePath);
    for(int i=0;i<200;i++) {
        for(int j=0;j<3;j++) {
            getline(file,arr[i][j], ' ');
            j++;
            getline(file,arr[i][j], ' ');
            j++;
            getline(file,arr[i][j], '\n');
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

int main()
{
    
	return 0;
}