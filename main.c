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

int main()
{
    
	return 0;
}