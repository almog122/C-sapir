#include "Bird.h"

Bird::Bird(const char* name, int age, bool is_trained, bool is_hungry, const char* type, const float wing_length = DEF_WING_LENGTH): Animal(name, age, is_trained, is_hungry), wing_length(wing_length){
	set_type(type);
}

Bird::Bird(const Bird& other) : wing_length(wing_length) {
	*this = other;
}

Bird::~Bird() {
	delete[] type;
}

void Bird::set_type(const char* type) {
	int len;
	len = strlen(type) + 1;
	this->type = new char[len];
	assert(this->type != NULL);
	strcpy_s(this->type, len, type);
}


void Bird::eat() {

}

void Bird::show() {

}

void Bird::training() {

}

Bird& Bird::operator=(const Bird& other) {
	if (*this != other) {
		*this = other;
		delete[] type;
		set_type(other.type);
	}

	return *this;
}

bool Bird::operator==(const Bird& other) const {

}

bool Bird::operator!=(const Bird& other) const {

}

ostream& operator<<(ostream& out, Bird& bird) {

}

