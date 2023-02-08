#pragma once
#include "Apartment.h"
#define DEF_GARDEN_AREA 20
#define UPPER_GARDEN_AREA 100
#define LOWER_GARDEN_AREA 20

class GardenApartment :public Apartment
{
private:
	int garden_area;

public:
	//Constructors
	GardenApartment();
	GardenApartment(Address address, int num_rooms, int apartment_area, int floors, int garden_area);
	~GardenApartment();

	//Setters
	void set_garden_area(int garden_area);

	//Getters
	const int get_garden_area() const { return garden_area; }

	//Operators

	bool operator==(const GardenApartment& other) const;
	bool operator!=(const GardenApartment& other) const;
	int operator++();
	bool operator>(const GardenApartment& other) const;
	friend ostream& operator<<(ostream& out, GardenApartment& a);
};

