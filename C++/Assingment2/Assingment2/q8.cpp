#include <iostream>
using namespace std;

//This progrem gets a pointer which point to memory block (array first member), a number and the size
//Of the memory block (array) and uses the pointer to see if the number is in the memory block
//If the number is in the memory block it return the number and the address if not return NULL

unsigned int* is_in(unsigned int* ptr_arr, unsigned int num, unsigned int size);

int main() {

	unsigned int num;
	unsigned int array[] = { 1,2,3,4,5 };
	unsigned int* ptr_arr = array; //The pointer we use to get to the memory block
	
	cout << "Enter num " << endl;
	cin >> num; //The number we search

	cout << is_in(ptr_arr , sizeof(array) / sizeof(array[0]), num) << endl;

	return 0;
}

unsigned int* is_in(unsigned int* ptr_arr, unsigned int size, unsigned int num) {

	for (unsigned int i = 0; i < size; i++) {
		
		if (*ptr_arr == num) //If the value of the member in the address is equel to the number
			return ptr_arr;

		ptr_arr ++; 

	}

	return NULL; 
}