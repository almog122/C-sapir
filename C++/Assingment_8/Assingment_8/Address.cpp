#include "Address.h"

Address::Address(const char* name,const int num_building ,const int num_apartment): num_building(num_building), num_apartment(num_apartment)
{
	set_name(name);
	
}

Address::Address(const Address& other): num_building(other.num_building), num_apartment(other.num_apartment) {
	set_name(other.name);
}


Address::~Address()
{
	delete[] name;
}

void Address::set_name(const char* name) {
	int len;
	len = strlen(name) + 1;
	this->name = new char[len];
	assert(this->name != 0);
	strcpy_s(this->name, len, name);
}


Address& Address::operator=(const Address& other) {
	if (*this != other) {
		delete[] name;
		set_name(other.name);
	}

	return *this;

}

bool Address::operator==(const Address& other) const {
	return strcmp(this->name, other.name) == 0 && this->num_building == other.num_building && this->num_apartment == other.num_apartment;
}

bool Address::operator!=(const Address& other) const {
	return strcmp(this->name, other.name) != 0 || this->num_building != other.num_building || this->num_apartment != other.num_apartment;
}

Address Address::operator+(const Address& other) const {
	
	int max_num_building;
	int min_num_apartment;
	int len;

	len = strlen(this->name) + 1;
	char* combined_name = new char[len];
	assert(combined_name != 0);
	strcpy_s(combined_name, len , this->name); // Put the name of the one calling the function into new string

	len = strlen(this->name) + strlen(other.name) + 1;
	strcat_s(combined_name, len, other.name); // concatenating the new string with the one from the parmater of the function

	max_num_building = this->num_building > other.num_building ? this->num_building : other.num_building; // Check who got the highest number building
	min_num_apartment = this->num_apartment > other.num_apartment ? this->num_apartment : other.num_apartment; // Check who got the smallest number apartment

	Address new_address(combined_name, max_num_building, min_num_apartment);
	
	return new_address;

}

ostream& operator<<(ostream& out, Address& a) {
	cout << "Address: street name : " << a.name << ", "
		<< "building number : " << a.num_building << ", "
		<< "apartment number : " << a.num_apartment <<"\n ";

	return cout;
}
