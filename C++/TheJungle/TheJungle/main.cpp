#include "Monkey.h"
#define SIZE 3
using namespace std;

int oldest_monkey(Monkey arr[], int size);

int main() {

	int index_Oldest;
	
	Monkey mon1(10, "Maxmiliuans", 50);
	Monkey mon2(190, "Max", 60);
	Monkey mon3(20, "Lolo", 2);

	Monkey* mon_arr = new Monkey[SIZE];

	mon_arr[0] = mon1;
	mon_arr[1] = mon2;
	mon_arr[2] = mon3;
	
	for (int i = 0; i < SIZE; i++) {
		cout << "Monkey number " << i + 1 << endl;
		mon_arr[i].print();
	}

	index_Oldest = oldest_monkey(mon_arr, SIZE);

	cout << "Age of the oldest monkey : " << mon_arr[index_Oldest].getAge() << endl;

	for (int i = 1; i <= 20; i++) {
		mon1.eat("Banana");
	}

	cout << "new weight of the first monkey " << mon1.getWeight() << endl;

	for (int i = 1; i <= 15; i++) {
		mon1.poop();
	}

	cout << "new weight of the second monkey " << mon2.getWeight() << endl;
	
	return 0;
}

int oldest_monkey(Monkey arr[], int size) {
	int index_oldest;

	index_oldest = 0;

	for (int i = 0; i < SIZE; i++) {

		index_oldest = index_oldest < arr[i].getAge() ? index_oldest : arr[i].getAge();
	}

	return index_oldest;
}