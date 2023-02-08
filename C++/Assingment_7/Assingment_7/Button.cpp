#include "Button.h"

//Builders and destroyer

Button::Button(const char* color, int num_holes, float diameter) {
	
	set_color(color);
	set_num_holes(num_holes);
	set_diameter(diameter);

}

//Copy counstructor 

Button::Button(const Button &other) {

	set_color(other.color);
	set_num_holes(other.num_holes);
	set_diameter(other.diameter);

}


Button::~Button()
{

	delete[] color;
}

//Setters

void Button::set_color(const char* color) {

	int len = strlen(color) + 1;
	
	this->color = new char[len];
	assert(this->color != NULL);
	strcpy_s(this->color, len, color);

}

void Button::set_num_holes(int num_holes) {
	if (num_holes < MIN_NUM_HOLES || num_holes > MAX_NUM_HOLES) {
		num_holes = DEF_NUM_HOLES;
	}
	
	this->num_holes = num_holes;

}

void Button::set_diameter(float diameter) {
	if (diameter < MIN_DIAMETER || diameter > MAX_DIAMETER) {
		diameter = DEF_DIAMETER;
	}

	this->diameter = diameter;

}

void Button::print() const {
	cout << "Color : " << color << " "
	"Holes : " << num_holes << " "
	"Diameter : " << diameter << endl;

}

float Button::is_bigger(const Button& other) {

	return this->diameter - other.diameter;

}

bool Button::is_equal(const Button& other) {

	if (strcmp(this->color, other.color) == 0 && this->num_holes == other.num_holes && this->diameter == other.diameter) {
		return true;
	}

	return false;
}
	 