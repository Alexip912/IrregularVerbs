#include "checkVerb.hpp"
#include "randVerb.hpp"
#include "readFile.hpp"
	
int main() {
    int number_of_verbs, wrongValue = 0, rightValue = 0;
    cout << "Enter number of verbs to check" << endl;
    cin >> number_of_verbs;
    int *a = new int[number_of_verbs];
    randVerbs(a, number_of_verbs);
    string verbs_array[121][3];
    string filePath = "verbs.txt";
    readFromFile(verbs_array, filePath);
    checkVerbs(a, number_of_verbs, verbs_array, wrongValue, rightValue);
    delete[] a;
    return 0;
}
