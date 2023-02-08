#include "GardenApartment.h"

GardenApartment::GardenApartment() : Apartment()
{
	set_garden_area(DEF_GARDEN_AREA);
}

GardenApartment::GardenApartment(Address address, int num_rooms, int apartment_area, int floors, int garden_area): Apartment(address, num_rooms, apartment_area, floors) {
	set_garden_area(garden_area);
}

GardenApartment::~GardenApartment()
{
}

void GardenApartment::set_garden_area(int garden_area) {

	while (garden_area > UPPER_GARDEN_AREA || garden_area < LOWER_GARDEN_AREA) {
		cout << "invalid garden area , enter a new one" << endl;
		cin >> garden_area;
	}

	this->garden_area = garden_area;

}

bool GardenApartment::operator==(const GardenApartment& other) const {
	return Apartment::operator==(other) && this->garden_area == other.garden_area; // using the operator== from apartment
}
bool GardenApartment::operator!=(const GardenApartment& other) const {
	return Apartment::operator!=(other) || this->garden_area != other.garden_area;  // using the operator!= from apartment
}

int GardenApartment::operator++() {
	return Apartment::operator++();
}
bool GardenApartment::operator>(const GardenApartment& other) const {
	return Apartment::operator>(other) && this->garden_area > other.garden_area;  // using the operator> from apartment
}
ostream& operator<<(ostream& out, GardenApartment& a)
{
	cout << "address : " << a.address 
		<< "number of rooms : " << a.num_rooms << ", "
		<< "apartment area :  : " << a.apartment_area << ", "
		<< "number of floors : " << a.floors << ", "
		<< "garden area : " << a.garden_area << "\n ";

	return cout;

}
