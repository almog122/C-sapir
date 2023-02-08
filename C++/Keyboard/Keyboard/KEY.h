#pragma once
#include <iostream>
using namespace std;
#include <cassert>
#include <cctype>
#define MAXLEN 30
#define STR_WITH_FEW_LINES "---" //for the empty constractor
#define UNSHIFTABLE_KEY_F4 "f4"
#define UNSHIFTABLE_KEY_ENTER "enter"
#define UNSHIFTABLE_KEY_ALT "alt"
#define MAX_KEY_CODE 255
#define MIN_KEY_CODE 3




class KEY {

	friend class KEYBOARD;

private:

	char values[MAXLEN];
	const unsigned int key_code;
	bool is_shiftable;
	char* description;
	bool is_pressed;

public:

	//constractors (one empty and one with parameters):


	KEY(); //empty constractor
	KEY(char values[MAXLEN], unsigned int key_code, bool is_shiftable, char* description, bool is_pressed); //like new_values because it's not with this->values.

	//copy constractor:
	KEY(const KEY &other);

	//destractor:
	~KEY();

	//getters (inline format):
	const char get_values() const { return this->values[MAXLEN]; }
	const unsigned int get_key_code() const { return this->key_code; }
	bool get_is_shiftable() const { return this->is_shiftable; }
	char* get_description() const { return this->description; }
	bool get_is_pressed() const { return this->is_pressed; }

	//setters:

	void set_values(const char values[MAXLEN]);
	void set_is_shiftable(bool is_shiftable);
	void set_description(const char* description);
	void set_is_pressed(bool is_pressed);


	//functions:

	void print() const;
};
