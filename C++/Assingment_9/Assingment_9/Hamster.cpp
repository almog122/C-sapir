#include "Hamster.h"

Hamster::Hamster(const char* name, int age, bool is_trained, bool is_hungry, const char* fur_color, float weight, bool is_clean):Animal(name,age,is_trained,is_hungry)
{
	set_fur_color(fur_color);
	set_weight(weight);
	set_is_clean(is_clean);
}

Hamster::Hamster(Hamster& other) {
	*this = other;
}

Hamster::~Hamster()
{
	delete[] fur_color;
}


void Hamster::set_fur_color(const char* fur_color) {
	int len;
	len = strlen(fur_color) + 1;
	this->fur_color = new char[len];
	assert(this->fur_color != NULL);
	strcpy_s(this->fur_color, len, fur_color);
}

void Hamster::set_weight(float weight) {
	if (weight > MAX_WEIGHT || weight < MIN_WEIGHT) {
		cout << "invalid weight , enter a new weight" << endl;
		cin >> weight;
	}

	this->weight = weight;

}

void Hamster::set_is_clean(bool is_clean) {
	this->is_clean = is_clean;
}

//Function

void Hamster::eat() {
	if (weight + 10 < MAX_WEIGHT) {
		Animal::eat();
		
		if (is_hungry) 
			(*this)++;
		
		if (is_clean)
			is_clean = !is_clean;
	}
	else
		cout << "cannot take another bite" << endl;

}

void Hamster::show(){
	cout << *this << endl;
}

void Hamster::training() {
	cout << name << " is on the wheel...training done" << endl;
	(*this)--;
	if (is_clean)
		is_clean = !is_clean;
}

void  Hamster::brush_fur() {
	cout << "Cleaning " << name << " ...done all nice and clean" << endl;
	is_clean = true;
}

Hamster& Hamster::operator=(const Hamster& other) {
	if (*this != other) {
		Animal& operator=(const Animal& other);
		delete[] fur_color;
		set_fur_color(other.fur_color);
	}

	return *this;
}

Hamster Hamster::operator+(Hamster& other) {
	Hamster::operator+(other);
	if (*this != other) {
		delete[] fur_color;
		set_fur_color(other.fur_color);
	}

	return *this;
}

int Hamster::operator++() {
	return (this->weight + 10);
}

int Hamster::operator--() {
	return (this->weight - 10);
}

ostream& operator<<(ostream& out, Hamster& ham) {
	cout << "Name: " << ham.name
		<< "Age : " << ham.age
		<< "is_trained? :" << ham.is_trained
		<< "is_hungry? :" << ham.is_hungry << "\n"
		<< "fur color: " << ham.fur_color
		<< "Weight : " << ham.weight
		<< "is_clean " << ham.is_clean;
	return out;
}
