#pragma once
#include <iostream>
#include <cassert>
using namespace std;
#define DEF_NAME "HARZEL"
#define DEF_NUM_BUILDING 10
#define DEF_NUM_APARTMENT 9
#define UPPER_NUM_BUILDING 100
#define LOWER_NUM_BUILDING 1
#define UPPER_NUM_APARTMENT 100
#define LOWER_NUM_APARTMENT 1

class Address
{
private:
	char* name;
	const int num_building;
	const int num_apartment;

public:
	
	//Builder, destroyer and copy counstractor

	Address(const char* name = DEF_NAME,const int num_building = DEF_NUM_BUILDING,const int num_apartment = DEF_NUM_APARTMENT);
	Address(const Address& other);
	~Address();
	
	//Getters
	const char* get_name() const { return name; }
	const int get_num_building() const { return  num_building; }
	const int get_num_apartment() const { return num_apartment; }

	//Setters
	void set_name(const char* name);

	//Operators
	Address& operator=(const Address& other);
	bool operator==(const Address& other) const;
	bool operator!=(const Address& other) const;
	Address operator+(const Address& other) const;
	friend ostream& operator<<(ostream& out, Address& a);
};

