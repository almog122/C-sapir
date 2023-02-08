#include "RoofApartment.h"

RoofApartment::RoofApartment() : Apartment()
{
	set_designer(DEF_DESIGNER);
	set_balcony_area(DEF_BALCONY_AREA);
}

RoofApartment::RoofApartment(Address address, int num_rooms, int apartment_area, int floors, const char* designer, int balcony_area) : Apartment(address, num_rooms, apartment_area, floors) {
	set_designer(designer);
	set_balcony_area(balcony_area);
}
RoofApartment::RoofApartment(RoofApartment& other) {

	*this = other;
}

RoofApartment::~RoofApartment()
{
	delete[] designer;
}

void RoofApartment::set_designer(const char* designer) {
	int len;
	len = strlen(designer) + 1;
	this->designer = new char[len];
	assert(this->designer != 0);
	strcpy_s(this->designer, len, designer);
}

void RoofApartment::set_balcony_area(int balcony_area) {
	while (balcony_area > UPPER_BALCONY_AREA || balcony_area < LOWER_BALCONY_AREA) {
		cout << "invalid balcony area , enter a new one" << endl;
		cin >> balcony_area;
	}

	this->balcony_area = balcony_area;
}

RoofApartment& RoofApartment::operator=(RoofApartment& other) {
	if (*this != other) {
		Apartment::operator=(other);
		delete[] designer;
		set_designer(other.designer);
		set_balcony_area(other.balcony_area);
	}

	return *this;
}

bool RoofApartment::operator==(RoofApartment& other) {
	return Apartment::operator==(other) && strcmp(this->designer, other.designer) == 0 && this->balcony_area == other.balcony_area;
}
bool RoofApartment::operator!=(RoofApartment& other) {
	return Apartment::operator!=(other) || strcmp(this->designer, other.designer) != 0 || this->balcony_area != other.balcony_area;

}
int RoofApartment::operator++() {
	return Apartment::operator++();
}
bool RoofApartment::operator>(RoofApartment& other) {
	return Apartment::operator>(other) && this->balcony_area > other.balcony_area;
}

int RoofApartment::operator+(int extra) {
	if(this->balcony_area + extra < UPPER_BALCONY_AREA)
		return this->balcony_area + extra;

	return this->balcony_area;
}

ostream& operator<<(ostream& out, RoofApartment& a) {
	cout << "address : " << a.address 
		<< "number of rooms : " << a.num_rooms << ", "
		<< "apartment area :  : " << a.apartment_area << ", "
		<< "number of floors : " << a.floors << ", "
		<< "designer name : " << a.designer << ", "
		<< "balcony area : " << a.balcony_area << "\n";

	return cout;

}
