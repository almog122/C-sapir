#include "KEYBOARD.h"


KEY** create_empty_array_keys(int size);
char** create_empty_array_languages(int size);

//constractors:

//empty constractor:
KEYBOARD::KEYBOARD() :num_lang(MIN_LANG), num_special_keys(MIN_SPECIAL_KEY) {

	this->set_languages(create_empty_array_languages(MIN_LANG));
	this->set_keys(create_empty_array_keys(MIN_KEYS));
	this->set_num_keys(MIN_KEYS);
}
//constractor with only 3 parameters:

KEYBOARD::KEYBOARD(int num_lang, int num_special_keys, int num_keys) :num_lang(num_lang), num_special_keys(num_special_keys) {
	
	this->set_num_keys(num_keys);

	this->languages = create_empty_array_languages(num_lang);
	this->keys = create_empty_array_keys(num_keys);

	this->set_languages(this->languages);
	this->set_keys(this->keys);
}

//copy constractor:
KEYBOARD::KEYBOARD(const KEYBOARD &other):num_lang(other.num_lang) ,num_special_keys(other.num_special_keys) {
	set_num_keys(other.num_keys);
}


//destractor:

KEYBOARD::~KEYBOARD() {
	cout << this->languages << " destroyed." << endl;
	for (int i = 0; i < this->num_lang; i++) {
		delete[] this->languages[i];
	}

	delete[] this->languages;

	cout << this->keys << " destroyed." << endl;
	for (int i = 0; i < this->num_keys; i++) {
		delete[] this->keys[i];
	}

	delete[] this->keys;


}

//setters:

void KEYBOARD::set_languages(char** languages) {

	if (this->num_lang > 1) {
		
		if (languages[1]) {
			int len = strlen(languages[1]) + 1;
			this->languages[1] = new char[len];
			assert(languages[1] != NULL);
			strcpy_s(this->languages[1], len, languages[1]);
		}
		
		if (this->num_lang > 2) {
			if (languages[2]){
				int len = strlen(languages[2]) + 1;
				this->languages[2] = new char[len];
				assert(languages[2] != NULL);
				strcpy_s(this->languages[2], len, languages[2]);
			}
		}
	}

}

void KEYBOARD::set_keys(KEY** keys) {

	for (int i = 0; i < this->num_keys; i++) {

		if (this->keys[i]) {

			if (find(keys[i]->get_key_code()) == -1) {
				this->keys[i] = keys[i];
			}

			else {
				cout << "The same key code : " << keys[i]->get_key_code() << " was already in the keyboard and was not added" << endl;
			}
		}
		else {
			this->keys[i] = nullptr;
		}

	}



}

void KEYBOARD::set_num_keys(int num_keys) {

	if (num_keys < MIN_KEYS || num_keys > MAX_KEYS) {

		cout << "Error number of keys." << endl;
		cin >> num_keys;
	}
	
	this->num_keys = num_keys;

}

//functions:

void KEYBOARD::print_keys() const {

	cout << "languages: " << endl;
	for (int i = 0; i < num_lang; i++) {
		if (*this->languages[i])
			cout << this->languages[i] << endl;
	}
	cout << "number of languages: " << this->num_lang << endl;
	
	cout << "keys : " << endl;
	for (int i = 0; i < num_keys; i++) {
		if (this->keys[i])
			cout << "key [" << i << "]"<< this->keys[i] << endl;
	//		this->keys[i]->print();
			cout << endl;
	}

	cout << "number of keys: " << this->num_keys << endl;
	
	cout << "number of special keys: " << this->num_special_keys <<endl;

}

void KEYBOARD::print_pressed_keys() const {

	for (int i = 0; i < num_keys; i++) {

		if (keys[i]->get_is_pressed()) {

			cout << this->keys[i] << endl;
		}

	}

}

void KEYBOARD::print_special_keys() const {

	for (int i = 0; i < num_special_keys; i++) {

		if (keys[i]->get_key_code() > (unsigned int) MIN_SPECIAL_KEY_CODE && keys[i]->get_key_code() < (unsigned int)MAX_SPECIAL_KEY_CODE) { //not finished but start

			cout << this->keys[i] << endl;
		}

		if (is_key_special(this->keys[i])) {
			cout << this->keys[i] << endl;
		}
	}

}

bool KEYBOARD::add_language(const char* language) {

	for (int i = 1; i < this->num_lang; i++) {
		if (!(this->languages[i])) {
			int len = strlen(language) + 1;
			this->languages[i] = new char[len];
			assert(languages[i] != NULL);
			strcpy_s(this->languages[i], len, language);
			return true;
		}

	}

	return false;
}

bool KEYBOARD::remove_language(int index) {

	if (index < MIN_LANG || index >= MAX_LANG) {//if the language is english(index[0]) or out of border (3 or more) then false.
		return false;
	}

	if (this->languages[1] == NULL && index == 1) {
		return false;
	}

	if (this->languages[2] == NULL && index == 2) {
		return false;
	}

	else {
		int len = strlen(DEL_LANG);
		this->languages[index] = new char[len + 1];
		assert(languages[index] != NULL);
		strcpy_s(this->languages[index], len, DEL_LANG);
		return true;
	}

}




bool KEYBOARD::add_key(KEY key) {

	for (int i = 0; i < this->num_keys; i++) {
		if (!&(this->keys[i])) {
			this->keys[i] = &key;
			return true;
		}
	}

	return false;
}




bool KEYBOARD::replace_special_key(KEY src, KEY target) { // src = source , target = new.

	if (src.get_key_code() == target.get_key_code() && is_key_special(&src) && is_key_special(&target)) {
		for (int i = 0; i < num_keys; i++) {
			if (this->keys[i] == &src) {
				this->keys[i] = &target;
				return true;
			}
		}
	}

	return false;
}



int KEYBOARD::find(const unsigned int key_code) {

	for (int i = 0; i < this->num_keys; i++) {
		if (keys[i]->get_key_code() == key_code) {
			return i;
		}
	}

	return -1;
}

KEY** create_empty_array_keys(int size) {
	
	KEY** new_array_keys = new KEY*[size];
	assert(new_array_keys != NULL);

	for (int i = 0; i < size; i++) {
		new_array_keys[i] = nullptr;
	}

	return new_array_keys;
}

char** create_empty_array_languages(int size) {
	
	char** new_array_languages = new char*[size];
	assert(new_array_languages != NULL);

	int len = strlen(DEF_LANG) + 1;

	new_array_languages[0] = new char[len];

	strcpy_s(new_array_languages[0], len, DEF_LANG);

	for (int i = 1; i < size; i++) {
		new_array_languages[i] = nullptr;

	}

	return new_array_languages;
}

bool KEYBOARD::is_key_special(const KEY* key) const {

	if (key->get_key_code() > (unsigned int) MIN_SPECIAL_KEY_CODE && key->get_key_code() < (unsigned int)MAX_SPECIAL_KEY_CODE) {
		return true;
	}

	return false;
}
