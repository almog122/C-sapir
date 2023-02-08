#include "Yoyo.h"
#include <iostream>
#include <cassert>
using namespace std;


Yoyo::Yoyo(const char* new_manufacturer, int new_price, float new_length, bool new_is_competition) {
	set_manufacturer(new_manufacturer);
	set_price(new_price);
	set_length(new_length);
	set_is_competition(new_is_competition);
}

Yoyo::Yoyo() {
	char no_name[] = "NoName";
	set_manufacturer(no_name);
	set_price(0);
	set_length(0);
	set_is_competition(false);
}

Yoyo::~Yoyo()
{
}

void Yoyo::compete(Yoyo other) {
	if ((is_competition == true && other.get_is_competition() == true) || (is_competition == false && other.get_is_competition() == false))
		cout << "it's a tie" << endl;
	else if (is_competition == true && other.get_is_competition() == false) {
		cout << "Winner " << endl;
		this->print();
	}
	else {
		cout << "Winner " << endl;
		other.print();
	}
}

bool Yoyo::is_fake() {

	int length = strlen(manufacturer);
	for (int i = 0; i < length; i++) {
		if (manufacturer[i] >= ASCII_ZERO && manufacturer[i] <= ASCII_NINE) {
			cout << "Manufacturer is fake" << endl;
			return true;
		}
	}
	cout << "Manufacturer is original" << endl;
	return false;
}

void Yoyo::reduce_length(float amount) {
	if ((length - amount) < 0) {
		cout << "Error length" << endl;
	}
	else (length -= amount);
}

void Yoyo::print() {
	cout << "Manufacturer: " << manufacturer << endl;
	cout << "Price: " << price << endl;
	cout << "Length:" << length << endl;
	cout << "For Competition: ";
	if (is_competition) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}


void Yoyo::set_manufacturer(const char* new_manufacturer) {

	if (new_manufacturer == "YOYOYO" && is_competition == true) {
		float yoyo_length_yoyoyo;
		cout << "Enter length of yoyo: " << endl;
		cin >> yoyo_length_yoyoyo;
		set_length(yoyo_length_yoyoyo);
		set_price(YOYOYO_COMP_PRICE);
	}
	else if (new_manufacturer == "YOYOYO" && is_competition == false) {
		set_length(YOYOYO_NOTCOMP_LENGTH);
		set_price(YOYOYO_NOTCOMP_PRICE);
	}
	if (new_manufacturer == "BALIYOYO" && is_competition == true) {
		float yoyo_length_baliyoyo;
		cout << "Enter length of yoyo: " << endl;
		cin >> yoyo_length_baliyoyo;
		set_length(yoyo_length_baliyoyo);
		set_price(BALIYOYO_COMP_PRICE);
	}
	else if (new_manufacturer == "BALIYOYO" && is_competition == false) {
		set_length(BALIYOYO_NOTCOMP_LENGTH);
		set_price(BALIYOYO_NOTCOMP_PRICE);
	}
	if (new_manufacturer == "CH1NYOYO" && is_competition == true) {
		set_length(CH1NYOYO_LENGTH_PRICE);
		set_price(CH1NYOYO_COMP_PRICE);
	}
	else if (new_manufacturer == "CH1NYOYO" && is_competition == false) {
		set_length(CH1NYOYO_NOTCOMP_LENGTH_PRICE);
		set_price(CH1NYOYO_NOTCOMP_PRICE);
	}
	manufacturer = new char[strlen(new_manufacturer) + 1];
	assert(manufacturer != 0);
	strcpy_s(manufacturer, strlen(new_manufacturer) + 1, new_manufacturer);
}

void Yoyo::set_price(int new_price) {


	if (new_price < MINPRICE || new_price > MAXPRICE) {
		cout << "Error: Price" << endl;
	}
	else {
		price = new_price;
	}
}

void Yoyo::set_length(float new_length) {

	if (new_length < MINLENGTH || new_length > MAXLENGTH) {
		cout << "Error: Length" << endl;
	}
	else {
		length = new_length;
	}
}

void Yoyo::set_is_competition(bool new_is_competition) {
	is_competition = new_is_competition;
}