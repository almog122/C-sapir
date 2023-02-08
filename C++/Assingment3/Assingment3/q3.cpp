#include <iostream>
using namespace std;

//This program gets a array from the user and return it.

char* get_str();

//This progran gets array and a character , and count how many time the characer appear in the array and make a new array of the size
//Of the appearance and puts in every index the character and return said array and its size.

char* str_char(char* arr, char& ch);

int main() {

	char ch;

	char* str = get_str();

	char* ch_str = new char;
	
	if (ch_str == NULL) { // Check memory allocation
		cout << "Error memory allocation" << endl;
		exit(EXIT_FAILURE);
	}

	cout << "Enter a character" << endl; //The character you wanna search
	cin >> ch;
	
	 ch_str = str_char(str, ch);

	 for (int i = 0; i < (int) strlen(ch_str); i++) { //Print the character array
		
		 cout << *(ch_str + i);
		
	 }

	 delete[] ch_str;

	return 0;
}

char* str_char(char* str, char& ch) {

	int size, size2;

	size2 = 0;

	size = strlen(str);

	for (int i = 0; i < size; i++) { //Check the amount of appearnce the character have in the array.

		if ( *(str + i) == ch) {
			
			size2++;
		}
	}

	char* str2 = new char[size2 + 1];

	if (str2 == NULL) { // Check memory allocation
		cout << "Error memory allocation" << endl;
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < size2; i++) { //Put the character in the array 

		str2[i] = ch;

	}

	str2[size2] = '\0';

	return str2;

}

char* get_str() {

	char tmp[20];
	
	cout << "enter word" << endl; //Enter the word for the array
	cin >> tmp;
	
	int len = strlen(tmp);
	char* str = new char[len + 1];
	
	if (str == NULL) { // check memory allocation
		cout << "Error memory allocation" << endl;
		exit(EXIT_FAILURE);
	}
	
	strcpy_s(str, len + 1, tmp);
	
	return str;
}