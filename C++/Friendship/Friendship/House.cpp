#include "House.h"

void House::print() {
	cout << "Water consumption : " << water_consumption << endl;
	cout << "Debt : " << debt << endl;

}


House::House(int water_consumption, int debt) :debt(debt), water_consumption(water_consumption) 
{}


