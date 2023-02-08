#include <iostream>
using namespace std;

void series_of_3(double* ptr1, double* ptr2, double* ptr3);

int main(){

	double a, b, c;

	cout << "Enter 3 numbers" << endl;
	cin >> a;
	cin >> b;
	cin >> c;

	series_of_3(&a, &b, &c);

	cout << a << endl;
	cout << b << endl;
	cout << c << endl;


	return 0;
	}

void series_of_3(double* ptr1, double* ptr2, double* ptr3) {

	double temp1, temp2, temp3;

	temp1 = *ptr1;
	temp2 = *ptr2;
	temp3 = *ptr3;

	*ptr1 = temp2 - temp1;
	
	*ptr2 = temp1 + temp2 + temp3;
	
	*ptr3 = temp3 + *ptr1;


}