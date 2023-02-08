#include <iostream>
using namespace std;

//This program gets a number from the user , and make an array in the size of the digits of the number and put it's digits in the array
//Then it return the array and it's size.

int* int_to_arr(int& num);

int main() {

	int num;
	int* arr;

	cout << "Enter a number " << endl;
	cin >> num;

	arr = int_to_arr(num);

	for (int i = 0; i < num; i++) { //Print the array

		cout << *(arr + i) << endl;
	}

	delete[] arr; //Free memory allocation

	return 0;
}

int* int_to_arr(int& num) {

	int* arr;
	int temp, size;

	temp = num;
	size = 0;

	while (temp > 0) { // Get size of num

		size++;

		temp /= 10;
	}

	arr = new int[size];

	if (arr == NULL) { //Check for memory allocation
		cout << "Error memory allocation" << endl;
		exit(EXIT_FAILURE);
	}

	for (int i = size - 1; i >= 0; i--) { //Put the num in the array

		arr[i] = num % 10;

		num /= 10;
	}

	num = size;

	return arr;
}