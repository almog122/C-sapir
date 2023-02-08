#include <iostream>
#define MAXLEN 25
using namespace std;

char** array_of_str(int& size);

int** array_of_index_is_char(char ch, char** str_arr, int& size_str_arr);

int main() {

	int i, j, size_strings;
	char ch;

	char** array_strings = array_of_str(size_strings);

	cout << "The string array : " << endl;

	for (i = 0; i < size_strings; i++) { // Print the words in the string's array

		cout << array_strings[i] << endl;

	}

	cout << "" << endl;
	
	cout << "Enter the character" << endl;
	cin >> ch;

	int** array_index = array_of_index_is_char(ch, array_strings, size_strings);

	cout << "The index's array : " << endl;

	for (i = 0; i < size_strings; i++) {

		if (array_index[i] == NULL) { //If the character didnt appear in the word.

			cout << "not found" << endl;
		}
		
		else {

			for (j = 1; j < array_index[i][0]; j++) { // Print the arrays of index

				cout << array_index[i][j] << ",";
			}

			cout << "" << endl;
		}
		
	}

	//Free memory allocation

	for (i = 0; i < size_strings; i++) { 

		delete[] array_strings[i];

	}

	delete[] array_strings;

	for (i = 0; i < size_strings; i++) { 

		delete[] array_index[i];

	}

	delete[] array_index; 
	
	return 0;
}

char** array_of_str(int& size_strings) {

	int len;

	cout << "how many strings?" << endl;
	cin >> size_strings;

	char** str_arr = new char*[size_strings];

	if (str_arr == NULL) { //Check for memory allocation
		cout << "Error memory allocation" << endl;
		exit(EXIT_FAILURE);
	}

	char tmp[MAXLEN];
	
	for (int i = 0; i < size_strings; i++) { //Enter the word (up to 25 character) in the string and put the string in string's array.
		
		cout << "Enter a word: " << endl;
		cin >> tmp;
		
		len = strlen(tmp); //The size of the word
		
		str_arr[i] = new char[len + 1]; //Make an string("i" means the location in the stirng's array) in size of the word + room for '\0'.
		
		if (str_arr[i] == NULL) { //Check for memory allocation
			cout << "Error memory allocation" << endl;
			exit(EXIT_FAILURE);
		}

		strcpy_s(str_arr[i], len + 1, tmp); //Put it in the string's array
	}

	return str_arr;
}

int** array_of_index_is_char(char ch, char** str_arr, int& size_str_arr) {

	int i, j, size_of_array, index;

	int** array_index_ch = new int*[size_str_arr];

	if (array_index_ch == NULL) { //Check for memory allocation
		cout << "Error memory allocation" << endl;
		exit(EXIT_FAILURE);
	}

	size_of_array = 1;
	index = 1;

	for (i = 0; i < size_str_arr; i++) {

		for (j = 0; j < (int) strlen(str_arr[i]); j++) {

			if (*(str_arr[i] + j) == ch) { //Give you the address of the first character in the word ( in the index i in the string's array) 
											//And forward the address with j (to check every character) ( * is to give the value in the address).
				size_of_array++;

			}
		}

		if (size_of_array == 1) { //If the character didnt appear in the word

			array_index_ch[i] = NULL;

		}

		else {

			array_index_ch[i] = new int[size_of_array];

			if (array_index_ch[i] == NULL) { //Check for memory allocation
				cout << "Error memory allocation" << endl;
				exit(EXIT_FAILURE);
			}

			for (j = 0; j < (int) strlen(str_arr[i]); j++) {

				array_index_ch[i][0] = size_of_array; // Entering the size of the array into the array for later use(index 0).

				if (*(str_arr[i] + j) == ch) { //Give you the address of the first character in the word ( in the index i in the string's array) 
												//And forward the address with j (to check every character) ( * is to give the value in the address).

					array_index_ch[i][index] = j; //Insecrt the index in the array, that the character appeared in the word ,
													  //In the index i in the string's array.
					index++;
				}

			}
		}
	
		index = 1;	//Set to 1 for next array to use.
		size_of_array = 1; 

	}

	return array_index_ch;
}
