#include "KEY.h"

//constractors (one empty and one with parameters):

KEY::KEY():key_code(0) {     //empty constractor:

	this->set_values(STR_WITH_FEW_LINES);
	this->set_is_shiftable(0);
	this->set_description(STR_WITH_FEW_LINES);
	this->set_is_pressed(0);
}

// constractor with parameters:
KEY::KEY(char values[MAXLEN], unsigned int key_code, bool is_shiftable, char* description, bool is_pressed):key_code(key_code) {

	this->set_values(values); //check about const char*
	this->set_is_shiftable(is_shiftable);
	this->set_description(description);
	this->set_is_pressed(is_pressed);

}


//copy constractor: using deep modul
KEY::KEY(const KEY &other):key_code(other.key_code) {
	this->set_values(other.values);
	this->set_is_shiftable(other.is_shiftable);
	this->set_description(other.description);
	this->set_is_pressed(other.is_pressed);
}

//to add here

//destractor:
//free memory of this->values because we gave it new memory allocation in set_values

KEY::~KEY() {
	//cout << this->values << " destroyed." << endl;
}



//setters:

void KEY::set_values(const char values[MAXLEN]) {

	strcpy_s(this->values,MAXLEN, values);

}


void KEY::set_is_shiftable(bool is_shiftable) {
	if (!is_shiftable) { //if false
		if (values == UNSHIFTABLE_KEY_F4 || values == UNSHIFTABLE_KEY_ENTER || values == UNSHIFTABLE_KEY_ALT) {

			cout << "The key is not shiftable." << endl;
			this->is_shiftable = !is_shiftable;
		}

	}
	else {


		this->is_shiftable = is_shiftable;

	}

}



void KEY::set_description(const char* description) {

	int len = strlen(description) + 1;

	this->description = new char[len]; //change something here
	assert(this->description != NULL);

	strcpy_s(this->description, len, description);


}
void KEY::set_is_pressed(bool is_pressed) {

	this->is_pressed = is_pressed; //like new_is_pressed into the old.

}


//functions:

void KEY::print() const {

	cout << "values: " << this->values << endl;    //means it'll print the same this that's in the private field.
	cout << "key code: " << this->key_code << endl;
	cout << "shiftable: " << this->is_shiftable << endl;
	cout << "description: " << this->description << endl;
	cout << "pressed: " << this->is_pressed << endl;

}
