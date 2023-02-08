#pragma once
#include "Address.h"
#define DEF_NUM_ROOMS 1
#define DEF_APARTMENT_AREA 1
#define DEF_FLOORS 1
#define UPPER_NUM_ROOMS 10
#define LOWER_NUM_ROOMS 0
#define UPPER_APARTMENT_AREA 200
#define LOWER_APARTMENT_AREA 0
#define UPPER_FLOORS 20
#define LOWER_FLOORS 0

class Apartment
{
protected:
	Address address;
	int num_rooms;
	int apartment_area;
	int floors;

public:
	//counstractors
	Apartment();
	Apartment(Address address , int num_rooms, int apartment_area, int floors);
	~Apartment();

	//setters
	void set_address(Address address);
	void set_num_rooms(int num_rooms);
	void set_apartment_area(int apartment_area);
	void set_floors(int floors);

	//getters

	const Address get_address() const { return address; }
	const int get_num_rooms() const { return num_rooms; }
	const int get_apartment_area() const { return apartment_area; }
	const int get_floors() const { return floors; }

	//operators
	bool operator==(const Apartment& other) const;
	bool operator!=(const Apartment& other) const;
	int operator++();
	bool operator>(const Apartment& other) const;
	friend ostream& operator<<(ostream& out, Apartment& a);

};

