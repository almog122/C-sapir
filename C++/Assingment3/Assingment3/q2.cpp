#include <iostream>
using namespace std;

//This program gets a size of an array, then the user enter numbers to the array and another separate number,
//Then the program will search the array for the separate number and put the index of the number found in the array in a new array.

int* get_array(int& size);

int main() {

	int size;
	int* arr = get_array(size);

	cout << "The array is :" << endl;

	for (int i = 0; i < size; i++) { //Print the array

		cout << *(arr + i) << endl;
	}

	delete[] arr; //Free the memory allocation

	return 0;
}

int* get_array(int& size) {

	int* arr1;
	int num, i, size2, index;

	index = 0;
	size2 = 0;

	cout << "Enter the size of the array " << endl;
	cin >> size;

	arr1 = new int[size];

	if (arr1 == NULL) { //Check memory allocation
		cout << "Error memory allocation" << endl;
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < size; i++) { //Enter the number for the array
		cout << "Enter value for arr[" << i << "] : " << endl;
		cin >> arr1[i];
	}

	cout << "Enter a number " << endl; //The number you want to search in the array
	cin >> num;

	for (i = 0; i < size; i++) { //Checks what the size of the new array should be.
		
		if (arr1[i] == num)
			size2++;
	}

	int* arr2 = new int[size2];

	if (arr2 == NULL) { //Check for memory allocation
		cout << "Error memory allocation" << endl;
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < size; i++) { //Enter the indexs to the new array.

		if ( *(arr1 + i) == num ) {

			arr2[index] = i;
			index++;
		}
		
	}

	delete[] arr1; //Free memory allocation
	
	size = size2;
	return arr2;
}