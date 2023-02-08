#include "Animal.h"

Animal::Animal(const char* name, int age, bool is_trained, bool is_hungry)
{
	set_name(name);
	set_age(age);
	set_is_trained(is_trained);
	set_is_hungry(is_hungry);
}


Animal::~Animal()
{
	delete[] name;
}

Animal::Animal(const Animal& other) {
	*this = other;
}

void Animal::set_name(const char* name) {
	int len;
	len = strlen(name) + 1;
	this->name = new char[len];
	assert(this->name != NULL);
	strcpy_s(this->name, len, name);
}

void Animal::set_age(int age) {
	while (age > MAX_AGE || age < MIN_AGE) {
		cout << "invalid age , enter a new age " << endl;
		cin >> age;
	}
	this->age = age;
}

void Animal::set_is_trained(bool is_trained) {
	this->is_trained = is_trained;
}

void Animal::set_is_hungry(bool is_hungry) {
	this->is_hungry = is_hungry;
}

void Animal::eat() {
	if (is_hungry) {
		cout << name << " is eating..." << endl;
		is_hungry = false;
	}

}

void Animal::show(){
	cout << *this << endl;
}

bool Animal::operator==(const Animal& other) const {
	return strcmp(name, other.name) == 0 && age == other.age && is_trained == other.is_trained && is_hungry == other.is_hungry;
}

bool Animal::operator!=(const Animal& other) const {
	return !(Animal::operator==(other));
}

Animal& Animal::operator=(const Animal& other) {
	if (*this != other) {
		delete[] name;
		set_name(other.name);
		set_age(other.age);
		set_is_trained(other.is_trained);
		set_is_hungry(other.is_hungry);
	}

	return *this;
}

ostream& operator<<(ostream& out, Animal& animal) {
	cout << "Name: " << animal.name
		<< "Age : " << animal.age
		<< "is_trained? :" << animal.is_trained
		<< "is_hungry? :" << animal.is_hungry;
	return out;
}