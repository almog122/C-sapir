#pragma once
#include "Apartment.h"
#define DEF_DESIGNER "---"
#define DEF_BALCONY_AREA 20
#define UPPER_BALCONY_AREA 100
#define LOWER_BALCONY_AREA 20
class RoofApartment : public Apartment
{
private:
	char* designer;
	int balcony_area;
public:
	//Counstractor and destroyer
	RoofApartment();
	RoofApartment(Address address, int num_rooms, int apartment_area, int floors, const char* designer ,int balcony_area);
	RoofApartment(RoofApartment& other);
	~RoofApartment();

	//Setters
	void set_designer(const char* designer);
	void set_balcony_area(int balcony_area);

	//Getters
	const char* get_designer() const { return designer; }
	const int get_balcony_area() const { return balcony_area; }

	//Operators
	bool operator==(RoofApartment& other);
	bool operator!=(RoofApartment& other);
	int operator++();
	bool operator>(RoofApartment& other);
	RoofApartment& operator=(RoofApartment& other);
	int operator+(int extra);
	friend ostream& operator<<(ostream& out, RoofApartment& a);

};

