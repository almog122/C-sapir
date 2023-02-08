#include <iostream>
using namespace std;

void Set_Char(char* ptr_ch1, char* ptr_ch2);

int main() {

	char ch1, ch2;

	cout << "Enter two characters" << endl;
	
	cin >> ch1;
	cin >> ch2;
	
	Set_Char(&ch1, &ch2);

	cout <<"ch1 = " << ch1 << " ch2 = "<< ch2 << endl;

	return 0;
}

void Set_Char(char* ptr_ch1, char* ptr_ch2) {
	
	int diffrence_ascii = 32;

	if (*ptr_ch1 <= 96)
		*ptr_ch1 = *ptr_ch1 + diffrence_ascii;

	if (*ptr_ch2 >= 97)
		*ptr_ch2 = *ptr_ch2 - diffrence_ascii;
}