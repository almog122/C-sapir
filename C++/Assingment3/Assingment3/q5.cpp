#include <iostream>
using namespace std;

//This program gets a size of an array form the user and set its inner values to 0, then the program gets values from the user ,
//If the size of the array is not enogth it will create a new array with double the size and put the values frome the prevoius array
//To the new one and continue to get new values for the new array until a negtive number entered,
//The program then return the array and its size.

int* arr_til_negtive(int& size);

int main() {

	char values[30];

	delete[] values;






	int size;

	cout << "Enter size " << endl; //The intial size of the array
	cin >> size;

	int* arr = arr_til_negtive(size);

	cout << "The size of the array is : " << size << endl;


	for (int i = 0; i < size; i++) { //Print the array.
		cout << arr[i] << ",";
	}

	delete[] arr; //Free memory allocation

	return 0;
}

int* arr_til_negtive(int& size) {

	int i, temp;

	int* arr1 = new int[size] {0}; // allocate all the values in the array to 0.

	if (arr1 == NULL) { // check memory allocation
		cout << "Error memory allocation" << endl;
		exit(EXIT_FAILURE);
	}


	for (i = 0; i < size; i++) { //Enter the values for the array until negative number enter.

		cout << "Enter value for arr[" << i << "] : ";
		cin >> arr1[i];

		if (arr1[i] < 0) { // End if a negative number entered
			
			return arr1;
		}
	}

	do {
		temp = size;

		size *= 2; // double the size

		int* arr2 = new int[size] {0};

		if (arr2 == NULL) { // check memory allocation
			cout << "Error memory allocation" << endl;
			exit(EXIT_FAILURE);
		}


		for (i = 0; i < temp; i++) { // Puts the previous array in the new one
			
			arr2[i] = arr1[i];

		}

		for (i = temp; i < size; i++) { // Continue the process

			cout << "Enter value for arr[" << i << "] : ";
			cin >> arr2[i];

			if (arr2[i] < 0) { //Stop if negative number given
				return arr2;
			}

			arr1 = arr2;
		}
	} while (arr1[i] < 0); //Continue until a negative number given

	return arr1;
}


