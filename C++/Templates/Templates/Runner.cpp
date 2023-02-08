#include < iostream>
using namespace std;

template <class T>
T my_add(T x, T y){
	return x + y;
}

int main() {
	cout << my_add(10, 2) << endl;
	cout << my_add(2.5, 2.8) << endl;
	cout << my_add <char>('A', 3) << endl;
}

