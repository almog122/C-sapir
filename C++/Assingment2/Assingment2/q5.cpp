#include <iostream>
using namespace std;

void count_dividable(int arr[] ,int size , int* ptr_a, int* ptr_b);

int main() {

	int a, b;

	int arr[] = { 1,2,3,4,5,6 };

	cin >> a;
	cin >> b;

	count_dividable(arr, sizeof(arr) / sizeof(arr[0]), &a, &b);

	cout <<"a = " << a <<endl;
	cout << "b = " << b <<endl;
}

void count_dividable(int arr[], int size, int* ptr_a, int* ptr_b) {

	int count_divide_a, count_divide_b;

	count_divide_a = 0;
	count_divide_b = 0;

	for (int i = 0; i < size; i++) {
		
		if (arr[i] % *ptr_a == 0)
			count_divide_a++;

		if (arr[i] % *ptr_b == 0)
			count_divide_b++;

	}

	*ptr_a = count_divide_b;
	*ptr_b = count_divide_a;
}