#pragma once
#include "KEY.h"
#define MAX_KEYS 101
#define MAX_LANG 3
#define MIN_LANG 1
#define DEF_LANG "English"
#define MAX_SPECIAL_KEY 4
#define MIN_SPECIAL_KEY 0
#define MIN_KEYS 1
#define MIN_SPECIAL_KEY_CODE 200 
#define MAX_SPECIAL_KEY_CODE 203 
#define DEL_LANG "EMPTY"
#define SP_KEY_ENG "123"

class KEYBOARD {

private:

	char** languages;
	const int num_lang;
	KEY** keys;
	int num_keys; //include regular keys and special keys
	const int num_special_keys;


public:

	//constractors:
	KEYBOARD();
	KEYBOARD(int num_lang, int num_special_keys, int num_keys);


	//copy constractor:
	KEYBOARD(const KEYBOARD &other);


	//destractor:
	~KEYBOARD();

	//getters (inline format):

	char** get_languages() const { return this->languages; }
	int get_num_lang() const { return this->num_lang; }
	KEY** get_keys() const { return this->keys; }
	const unsigned int get_num_keys() const { return this->num_keys; }
	const int get_num_special_keys() const { return this->num_special_keys; }

	//setters:

	void set_languages(char** languages);
	void set_keys(KEY** keys);
	void set_num_keys(int num_keys);
	//functions:

	void print_keys() const;
	void print_pressed_keys() const;
	void print_special_keys() const;

	//to check if i need to add const to the next functions:
	bool add_language(const char* language);
	bool remove_language(int index);
	bool add_key(KEY key);
	bool replace_special_key(KEY src, KEY target);
	int find(const unsigned int key_code);

	bool is_key_special(const KEY* key) const;
};