#include "Pet.h"
Pet::Pet(const char* name, int age, bool is_mamal)
	:is_mamal(is_mamal), age(age) //this is first שורת אתחול
{
	set_name(name); // then what inside the {} 
}
Pet::Pet(const Pet& other)
	: is_mamal(other.is_mamal)
{
	*this = other;
}
Pet::~Pet() {
	delete[] name;
}
//operators
Pet& Pet::operator=(const Pet& other) {
	if (this != &other) {
		delete[]name;
		set_name(other.name);
		age = other.age;
	}
	return *this;
}
ostream& operator<<(ostream& out, const Pet& p) {
	return out << "Name: " << p.name << ", Age: " << p.age << ", Mamal? " << (p.is_mamal ? "Yes" : "No");
}

//setters
void Pet::set_name(const char* name) {
	int len = strlen(name) + 1;
	this->name = new char[len];
	strcpy_s(this->name, len, name);
}
//functions
void Pet::sleep() {
	cout << name << " is sleeping now ...Do Not Disturb" << endl;
}
void Pet::eat() {
	cout << "Thank you for the food!!!" << endl;
}
