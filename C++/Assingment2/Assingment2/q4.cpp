#include <iostream>
using namespace std;

float calculate_series_1(float a_2, float a_3, int n, double* ptr_a, double* ptr_b, double* ptr_c);

int main() {
	
	int n;
	float a_2, a_3;
	double a, b, c;

	cout << "Enter n , a_2 , a_3" << endl;

	cin >> n;
	cin >> a_2;
	cin >> a_3;

	cout << " a_1 = " << calculate_series_1(a_2 ,a_3 ,n ,&a , &b, &c) << endl;
	cout << "q = "<< a << endl;
	cout << "an = " << b << endl;
	cout << "Sn = " << c << endl;

	return 0;
}

float calculate_series_1(float a_2, float a_3, int n, double* ptr_a, double* ptr_b, double* ptr_c) {

	float a_1;

	*ptr_a = a_3 / a_2; // q

	a_1 = (float) (a_2 / *ptr_a);

	*ptr_b = a_1;

	*ptr_c = 1;

	for (int i = 1; i < n; i++) {		
		*ptr_b *= *ptr_a; // a1 * q^(n-1)
	}

	for (int i = 1; i <= n ; i++) {

		*ptr_c *= *ptr_a; // q^n
	}

	*ptr_c -= 1; // (q^n -1)

	*ptr_c *= a_1 / (*ptr_a - 1); // (a1 * (q^n - 1)) / (q - 1)

	return a_1;
}