#include <iostream>
using namespace std;

//The program gets two arrays of characters and checks if the second array is a substring
//Of the first array and return the location of the first index of the appearance 
//If its not it return -1.

int str_str(char s1[], char s2[]);

int main() {

	char s1[] = {"HelloWorld"};
	
	char s2[] = {"ll"};

	cout << "The first appers is at " << str_str(s1, s2) << endl;

	return 0;
}

int str_str(char s1[], char s2[]) {

	int count_substing = strlen(s2); //The count is equel to the second array length to see if all the
									//Character are in the first array and not just the first

	for (int i = 0; i < (int) (strlen(s1)); i++) {

		if ( *(s1 + i) == *(s2) ) { //Checks if the Character at the index i of the first array
									//Is equel to the first character in the second array

			for (int j = 0; j < (int) (strlen(s2)); j++) {

				if ( *(s1 + i + j) == *(s2 + j) ) { //Check if all the Charcters of the first array are present in the									
													//Right order using the values in the address

					count_substing--; //If they does we remove the Character from the count
				}

			}

			if (count_substing == 0) { //If all the Character are present in the right order in the first array
										//Then the count will go down to 0 which means the second array 
										//Is a substring of the first array

				return i;
			}

			count_substing = strlen(s2); // If its not reach 0 means they are not in the right order or missing
										//A characters so we reset the count to its original value and keep
										//searching until we get to the last index of the first array
		}
	}

	return -1;

}