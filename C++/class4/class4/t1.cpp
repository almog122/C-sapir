#include <iostream>
using namespace std;
int main() {
	int** mat;
	int size, tmp;
	cout << "enter num of arrays: " << endl;
	cin >> size;
	mat = new int*[size];
	for (int i = 0; i < size; i++) {

		cout << "enter num of elements: " << endl;
		cin >> tmp;
		mat[i] = new int[tmp] {0};
	}
	return 0;
}
