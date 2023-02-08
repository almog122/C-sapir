#include "Door.h"

int main() {
	Door d1(1000,210,"Green");
	d1.print();
	d1.lock();
	//cout << d1.price << endl;
	d1.addHeight(10);
	d1.print();

	return 0;
}