#include <stdlib.h> 
#include <iostream>
#include <ctime>

using namespace std;

int menu(){
	int choice;
	cout<<"Welcome to IrregularVerbs"<<endl;
	cout<<"It's time to test your knowledge of irregular verbs"<<endl;
	cout<<"1.Begin to test your knowledge"<<endl<<"2.Exit"<<endl;
	cin>>choice;
	int number;
	switch (choice) {
		case 1:
			cout<<"Enter the number of verbs"<<endl;
			cin>>number;
			break;
		case 2:
			exit(EXIT_SUCCESS);
            break;
    	}
    return number;
}	


int main(){
	menu();
	return 0;
}