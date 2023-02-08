#include <iostream>
using namespace std;

//This program gets length of a series and an address, and puts the member's of Fibonacci series
//In the address given one after another , next to etc other.

void calculate_series_3(int n, int* v);

int main() {
	const int size = 100;
	const int a1 = 1;
	int n;
	int v[size];

	cout << "Enter n " << endl;
	cin >> n;	//The length of the Fibonacci series.

	calculate_series_3(n, v);

	for (int i = 0; i < n; i++) { //Using the address to print the members of the Fibonacci series.
		cout << "v[" << i << "] " << (v + i) << endl; //add the * if values needed
	}

	return 0;
}

void calculate_series_3(int n, int* v) {
	
	*v = 1; //The first member of the Fibonacci series is 1 so we put it in the first address
	
	int temp = *v + *v; //Fibonacci series is the sum of the member's next to etc other.

	for (int i = 1; i < n; i++) {

		v[i] = temp; //Puting the members in the addresses next to etc other.

		temp += v[i - 1]; //We sum up the current member with the previous one.
	}
		


}
