#include <iostream>
using namespace std;

void power_up(float* a, float* b);

int main() {
	float a, b;

	cout << "Enter two numbers" << endl;
	
	cin >> a;
	
	cin >> b;

	power_up(&a, &b);

	cout << "a^b =  " << a << endl;
	cout << "b^a =  " << b << endl;

	return 0;
}

void power_up(float* a, float* b) {

	float temp_a , temp_b;

	temp_a = *a;
	temp_b = *b;

	for (int i = 1; i < temp_b; i++)
		*a *= temp_a;

	for (int i = 1; i < temp_a; i++)
		*b *= temp_b;

}
