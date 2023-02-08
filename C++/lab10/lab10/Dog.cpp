#include "Dog.h"

Dog::Dog(const char* name, int age, bool is_mamal, const char* breed)
	:Pet(name, age, is_mamal) //Make it so it get the value that was entered from counstructor dog נקרא שורשור בנאים
{
	set_breed(breed);
}
Dog::Dog(const Dog& other)
{
	*this = other; //using operator= 
}
Dog::~Dog()
{
	delete[] breed;
}
//operators
Dog& Dog::operator=(const Dog& other) {
	if (this != &other) {
		Pet::operator=(other);//it does the same function as in here``````````````````
	//	delete[]name;
		delete[]breed;
	//	set_name(other.name);
		set_breed(other.breed);
	//	age = other.age;
	}
	return *this;
}
ostream& operator<<(ostream& out, const Dog& d) { //must reapet because it is friend function so it doesnt come from Pet
	return out << "Breed: " << d.breed << ", Name: " << d.name << ", Age: " << d.age << ", Mamal? " << (d.is_mamal ? "Yes" : "No");
}

//setters

void Dog::set_breed(const char* breed) {
	int len = strlen(breed) + 1;
	this->breed = new char[len];
	strcpy_s(this->breed, len, breed);
}
//functions

void Dog::eat() {
	cout << "Wooff!! Not again I want a steak!!!" << endl;
	Pet::eat(); //we activate the function from Pet that is: eat
}
void Dog::fetch_ball() {
	cout << "On may way .... I'm back!!" << endl;
}
