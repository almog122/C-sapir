#include <iostream>
using namespace std;

//This program gets a size from the user and make and array of this size and the user then input the values for the array
//Then the program return the array.

int* create_arr(int& size);

//This program gets two arrays and their size from the user ,then it combine them to one array and return the array and its size.

int* combine_arr(int* arr1, int& size_arr1, int* arr2, int& size_arr2);

int main() {

	int size_arr1, size_arr2;

	int* arr1 = create_arr(size_arr1);

	int* arr2 = create_arr(size_arr2);

	int* arr_comb = combine_arr(arr1, size_arr1, arr2, size_arr2);

	for (int i = 0; i < size_arr1; i++) { // Print the combined array
		cout << *(arr_comb + i)<< ",";
	}

	delete[] arr_comb; //Free memory allocation

	return 0;
}

int* combine_arr(int* arr1, int& size_arr1, int* arr2, int& size_arr2) {

	int comb_size = size_arr1 + size_arr2;

	int* arr_comb = new int[comb_size];

	if (arr_comb == NULL) { // check memory allocation
		cout << "Error memory allocation" << endl;
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < size_arr1; i++) { //Puts the first array in the combined array.
		*(arr_comb + i) = *(arr1 + i);
	}


	for (int i = 0; i < size_arr2; i++) { //Puts the seconed array in the combined array.
		*(arr_comb + size_arr1 + i) = *(arr2 + i);
	}

	size_arr1 = comb_size;

	return arr_comb;
}

int* create_arr(int& size) {
	
	int* arr;
	
	cout << "please enter array size: " << endl;
	cin >> size;
	
	arr = new int[size];
	
	if (!arr) {
		exit(1);
	}
	
	for (int i = 0; i < size; i++) {
		cout << "Enter value for arr[" << i << "] : ";
		cin >> arr[i];
	}
	
	cout << endl;
	
	return arr;
}