#include <iostream>
using namespace std;

//This program gets a address from the user (array), geomatric series with it's length and quotient
//Then it puts the first member of the series in the address and the next member in the address next to
//The previous address until all the member are in adresses next to eth other. 

void calculate_series_2(int a1, int q, int n, int* v);

int main() {
	const int size = 100;
	int v[size];
	int a1, q, n;

	cout << "Enter a1" << endl;
	cin >> a1;		//The first member of the series

	v[0] = a1;

	cout << "Enter q" << endl;
	cin >> q;	//The quotient of the series

	cout << "Enter n" << endl;
	cin >> n;	//The length of the series

	calculate_series_2(a1, q, n, v);

	for (int i = 0; i < n - 1; i++) {	//printing the series (add * to print values)
		cout << (v + i) << endl;
	}

	return 0;
}

void calculate_series_2(int a1, int q, int n, int* v){
	
	int temp = *v; //Temp gets the value inside array[0] which is a1

	for (int i = 0; i < n - 1; i++) {
		
		v[i] = temp; //Puts the member in the array
		
		temp *= q; //Using the series quotient to get the next member in the series
	}
}