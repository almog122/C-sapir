#include "Door.h"

void   Door::lock() {
	cout << "Door is Locked" << endl;
}

void   Door::unlock() {
	cout << "Door is Unlocked" << endl;
}

void   Door::addHeight(float addition) {
	height += addition;
}

void   Door::print() {
	cout << "color " << color << endl;
	cout << "price " << price << endl;
	cout << "height " << height << endl;
}

Door::Door(int newPrice, float newHeight, const char newColor[MAXLEN]) {
	price = newPrice;
	height = newHeight;
	strcpy_s(color, strlen(newColor) + 1, newColor);
}

Door::Door() {
	price = 100;
	height = 212.8;
	strcpy_s(color, 5 ,"Blue");
}

void Door::setPrice(int newPrice) {
	if (newPrice <= 0) {
		newPrice = 1000;
	}

	price = newPrice;
}