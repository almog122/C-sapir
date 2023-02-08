#include "Apartment.h"



Apartment::Apartment()
{
	set_address(Address());
	set_num_rooms(DEF_NUM_ROOMS);
	set_apartment_area(DEF_APARTMENT_AREA);
	set_floors(DEF_FLOORS);
}

Apartment::Apartment(Address address, int num_rooms, int apartment_area, int floors) {
	set_address(address);
	set_num_rooms(num_rooms);
	set_apartment_area(apartment_area);
	set_floors(floors);
}


Apartment::~Apartment()
{
}

void Apartment::set_address(Address address) {
	this->address = address;
}

void Apartment::set_num_rooms(int num_rooms) {

	while (num_rooms > UPPER_NUM_ROOMS || num_rooms < LOWER_NUM_ROOMS) {
		cout << "invalid number of rooms , enter a new one" << endl;
		cin >> num_rooms;
	}

	this->num_rooms = num_rooms;
}

void Apartment::set_apartment_area(int apartment_area) {

	while (apartment_area > UPPER_APARTMENT_AREA || apartment_area < LOWER_APARTMENT_AREA) {
		cout << "invalid apartment area , enter a new one" << endl;
		cin >> apartment_area;
	}

	this->apartment_area = apartment_area;

}

void Apartment::set_floors(int floors) {

	while (floors > UPPER_FLOORS || floors < LOWER_FLOORS) {
		cout << "invalid number of floors , enter a new one" << endl;
		cin >> floors;
	}

	this->floors = floors;

}

bool Apartment::operator==(const Apartment& other) const {
	return this->address == other.address && this->num_rooms == other.num_rooms && this->apartment_area == other.apartment_area && this->floors == other.floors;
}

bool Apartment::operator!=(const Apartment& other) const {
	return this->address != other.address || this->num_rooms != other.num_rooms || this->apartment_area != other.apartment_area || this->floors != other.floors;
}
int Apartment::operator++(){
	
	return (this->num_rooms)++;  //return the number before the change
}

bool Apartment::operator>(const Apartment& other) const {
	return this->apartment_area > other.apartment_area;
}

ostream& operator<<(ostream& out, Apartment& a) {
	cout << "Apartment: address : " << a.address 
		<< "number of rooms : " << a.num_rooms << ", "
		<< "apartment area : " << a.apartment_area << ", "
		<< "number of floors : " << a.floors << " \n ";

	return cout;
}