#include "KEYBOARD.h"

void menu();
KEY create_user_key(unsigned int* used_key_codes, int& key_codes_size);

int main() {

	unsigned int* used_key_codes = new unsigned int[MAX_KEY_CODE];
	assert(used_key_codes != NULL);
	char* description = new char;
	assert(description != NULL);
	int num_lang;
	int num_keys_regular; 
	int num_special_keys;
	int sum_keys;
	char ch;
	unsigned int sp_key_code;
	int used_key_codes_index = 0;

	cout << "How many languages would you like in your keyboard?" << endl;
	cin >> num_lang;
	
	while (num_lang > MAX_LANG || num_lang < MIN_LANG) {
		cout << "not a valid number of languages, enter again" << endl;
		cin >> num_lang;
	}

	cout << "How many keys for regular keys (numbers and letters) do you want to add to your keyboard?" << endl;
	cin >> num_keys_regular;
	
	while (num_keys_regular > MAX_KEYS || num_keys_regular < MIN_KEYS) {
		cout << "invalid number of regular keys, enter again" << endl;
		cin >> num_keys_regular;
	}
	cout << "How many special keys do you want to add to your keyboard?" << endl;
	cin >> num_special_keys;

	while (num_special_keys > MAX_SPECIAL_KEY || num_special_keys < MIN_SPECIAL_KEY) {
		cout << "invalid number of special keys , enter again" << endl;
		cin >> num_special_keys;
	}

	sum_keys = num_keys_regular + num_special_keys;

	KEYBOARD user_keyboard(num_lang, num_special_keys, sum_keys);

	char* language = new char;
	assert(language != NULL);

	for (int i = 1; i < num_lang; i++) {
		cout << "Enter a new language" << endl;
		cin >> language;

		user_keyboard.add_language(language);
	}

	cout << "The languages the keyboard support" << endl;
	
	for (int i = 0; i < num_lang; i++) {
		cout << user_keyboard.get_languages()[i] << endl;
	}
	//we add 3 regular keys to total num keys

	user_keyboard.set_num_keys(sum_keys + 3);

	char values[MAXLEN] = "SHIFT";
	unsigned int tmp1 = 1;
	char shift_again[] = "SHIFT";

	char caps_lock1[MAXLEN] = "CAPS LOCK";
	unsigned int tmp2 = 2;
	char caps_lock_again[] = "CAPS LOCK";

	char esc1[MAXLEN] = "ESC";
	unsigned int tmp3 = 3;
	char esc_again[] = "ESC";

	KEY shift(values, tmp1, false, shift_again, false);
	used_key_codes[used_key_codes_index] = 1;
	used_key_codes_index++;

	KEY caps_lock(caps_lock1, tmp2,false, caps_lock_again,false);
	used_key_codes[used_key_codes_index] = 2;
	used_key_codes_index++;

	KEY esc(esc1, tmp3,false, esc_again,false);
	used_key_codes[used_key_codes_index] = 3;
	used_key_codes_index++;
	

	user_keyboard.add_key(shift);
	user_keyboard.add_key(caps_lock);
	user_keyboard.add_key(esc);

	user_keyboard.print_keys();

	cout << "Enter special keys" << endl;

	for (int i = 0; i < num_special_keys; i++) {

		user_keyboard.add_key(create_user_key(used_key_codes, used_key_codes_index));
	}

	user_keyboard.print_special_keys();

	cout << "" << endl;

	cout << "Enter regular keys" << endl;

	for (int i = 0; i < num_special_keys; i++) {

		user_keyboard.add_key(create_user_key(used_key_codes , used_key_codes_index));
	}

	user_keyboard.print_keys();

	do {

		menu();
		cin >> ch;

		if (!(ch == 'a' || ch == 'A' || ch == 's' || ch == 'S' || ch == 'o' || ch == 'O' || ch == 'h' || ch == 'H' || ch == 'r' || ch == 'R' || ch == 'k' || ch == 'K' || ch == 'p' || ch == 'P')) {

			cout << "Error input. Enter a new letter." << endl;
			cin >> ch;

		}

		if (ch == 'a' || ch == 'A') {
			user_keyboard.print_keys();
		}

		if (ch == 's' || ch == 'S') {
			user_keyboard.print_special_keys();
		}

		if (ch == 'o' || ch == 'O') {
			user_keyboard.print_pressed_keys();
		}

		if (ch == 'h' || ch == 'H') {
			menu();
		}




		if (ch == 'r' || ch == 'R') {

			user_keyboard.print_special_keys();

			/*
			cout << "Enter a key code of the special key you want to replace" << endl;
			cin >> new_key_code;

			cout << "Enter values seperated by whitespace " << endl;
			cin >> values[MAXLEN];

			cout << "Enter description " << endl;
			cin >> description;

			KEY temp;
			temp.set_values(values);
			temp.set_key_code(new_key_code);
			temp.set_is_shiftable(0);
			temp.set_description(description);
			temp.set_is_pressed(0);
			*/
			KEY tmp (create_user_key(used_key_codes, used_key_codes_index));

			int src_index = user_keyboard.find(tmp.get_key_code());

			if (src_index != -1) {
				user_keyboard.replace_special_key(*user_keyboard.get_keys()[src_index], tmp);
				user_keyboard.print_special_keys();
			}

			else {
				cout << "Could not find special key with a mathcing key code" << endl;
			}
		}




		if (ch == 'k' || ch == 'K') {

			user_keyboard.print_keys();

			cout << "Enter a key code of the special key you want to print" << endl;
			cin >> sp_key_code;

			int sp_key_index = user_keyboard.find(sp_key_code);

			if (sp_key_index != -1 && sp_key_code > MIN_SPECIAL_KEY_CODE && sp_key_code < MAX_SPECIAL_KEY_CODE) {
				user_keyboard.get_keys()[sp_key_index]->print();
			}

			else {
				cout << "Could not find special key with a mathcing key code" << endl;
			}

		}






		if (ch == 'p' || ch == 'P') {
			user_keyboard.print_keys();

			cout << "Enter a key code of the special key you want to press" << endl;
			cin >> sp_key_code;

			int sp_key_index = user_keyboard.find(sp_key_code);

			if (sp_key_index != -1 && sp_key_code > MIN_SPECIAL_KEY_CODE && sp_key_code < MAX_SPECIAL_KEY_CODE) {

				if (user_keyboard.get_keys()[sp_key_index]->get_is_pressed() == 0) {
					user_keyboard.get_keys()[sp_key_index]->set_is_pressed(1);
				}

				else {
					user_keyboard.get_keys()[sp_key_index]->set_is_pressed(0);
				}

				user_keyboard.get_keys()[sp_key_index]->print();

			}

			else {
				cout << "Could not find special key with a mathcing key code" << endl;
			}
		}


	} while (!(user_keyboard.get_keys()[2]->get_is_pressed()));//[2] because esc is 3 in code key (and before is main we put it in get keys[2]and if it's pressed then we stop program.

	cout << "This is the end of the program! Goodbye (: " << endl;


	return 0;
}



void menu() {
	cout << "----------TESTER MENU---------- - :\n"
		<< "[a | A] - Show all keys information \n"
		<< "[s | S] - Show only special keys information \n"
		<< "[r | R] - Replace a special key \n"
		<< "[p | P] - Press on a key \n"
		<< "[k | K] - Show key information \n"
		<< "[o | O] - Show currently pressed keys \n"
		<< "[H | h] - Print this Menu again \n" << endl;
}

KEY create_user_key(unsigned int* used_key_codes, int& key_codes_size) {

	char new_values[MAXLEN];
	unsigned int new_key_code;
	bool new_is_shiftable;
	char* new_description = new char;
	assert(new_description != NULL);
	bool new_is_pressed;

	cout << "Enter a key code " << endl;
	cin >> new_key_code;

	for (int i = 0; i <= key_codes_size; i++) {
		if (used_key_codes[i] == new_key_code) {
			cout << "Key code already in use, please enter a new key code " << endl;
			cin >> new_key_code;
			i = 0;
		}
	}

	cout << "Enter values seperated by whitespace " << endl;
	cin >> new_values[MAXLEN];

	cout << "is the key shiftable? " << endl;
	cin >> new_is_shiftable;

	cout << "Enter description " << endl;
	cin >> new_description;

	cout << "is the key pressed? " << endl;
	cin >> new_is_pressed;

	used_key_codes[key_codes_size] = new_key_code;
	key_codes_size++;

	KEY temp(new_values, new_key_code, new_is_shiftable, new_description , new_is_pressed);
	
	return temp;
}
