#include "Yoyo.h"


//constractors:

Yoyo::Yoyo() {   //empty constractor:




}


Yoyo::Yoyo(const char* new_manufacturer, int new_price, float new_length, bool new_is_competition) {

	set_manufacturer(new_manufacturer);
	set_price(new_price);
	set_length(new_length);
	set_is_competition(new_is_competition);
}




//destractors: to add it


//setters:
void Yoyo::set_length(float new_length) {
	if (new_length < MIN_LENGTH || new_length > MAX_LENGTH) {
		cout << "Error length." << endl;
		cout << "Please enter new length in possible length: " << MIN_LENGTH << "-" << MAX_LENGTH << " cm." << endl;
	}
	length = new_length;
}

void Yoyo::set_price(int new_price) {
	if (new_price < MIN_PRICE__NOT_FOR_COM || new_price > MAX_PRICE_FOR_COM) {
		cout << "Error price number. Yoyo price is not in price range for public use and not for competition use." << endl;
		cout << "Please enter a new price: Yoyo price range for competition is: " << MIN_PRICE_FOR_COM << "-" << MAX_PRICE_FOR_COM
			<< "$ and yoyo price range not for competition is: " << MIN_PRICE__NOT_FOR_COM << "-" << MAX_PRICE_NOT_FOR_COM << "$." << endl;
	}
	else {

		if (new_price >= MIN_PRICE_FOR_COM && new_price <= MAX_PRICE_FOR_COM) {
			new_is_competition = true; //need to check if the user enter or it's from the price.
			price = new_price;
			set_is_competition(new_is_competition);
		}
		if (new_price >= MIN_PRICE__NOT_FOR_COM && new_price <= MAX_PRICE_NOT_FOR_COM) {
			new_is_competition = false;
			price = new_price;
			set_is_competition(new_is_competition);
		}

	}

}


void Yoyo::set_is_competition(bool new_is_competition) {

	if (new_is_competition == true) {
		is_competition = new_is_competition;
	}
	else {
		new_is_competition = false;
		is_competition = new_is_competition;
	}
}


void Yoyo::set_manufacturer(const char* new_manufacturer) { //maybe to add new memory and check it


	//YOYOYO company:
	char yoyoyo[] = "YOYOYO";
	int len_str = strlen(new_manufacturer) + 1;
	if (new_manufacturer == yoyoyo) {
		strcpy_s(manufacturer, len_str, yoyoyo);
	}


	if (is_competition(yoyoyo) == false) {
		length = set_length(120); //or length = 120;
		price = set_price(39);//or price = 39;
	}
	else {
		length //add in order time.
			price = set_price(79);//or price = 79;
	}



	//BALIYOYO company:
	char baliyoyo[] = "BALIYOYO";
	if (new_manufacturer == baliyoyo) {
		strcpy_s(manufacturer, len_str, baliyoyo);
	}


	if (is_competition(baliyoyo) == false) {
		length = set_length(118.2); //or length = 118.2;
		price = set_price(89);//or price = 89;
	}
	else {
		length //add in order time.
			price = set_price(99);//or price = 99;
	}

	//CH1NYOYO company: Pay attention: This is fake (num 1 in name instead of all chars):
	char fake_company[] = "CH1NYOYO";
	if (new_manufacturer == fake_company) {

		strcpy_s(manufacturer, len_str, fake_company);
	}

	if (is_competition(fake_company) == false) {
		length = set_length(118.2); //or length = 118.2;
		price = set_price(22);//or price = 22;
	}
	else {
		length = set_length(118.2); //or length = 118.2;
		price = set_price(69);//or price = 69;
	}


}

//functions:

void Yoyo::print() {

	cout << "a. Manufacturer: " << manufacturer << endl;
	cout << "b. Price: " << price << endl;
	cout << "c. Length: " << length << end;
	cout << "d. For Competition : " << is_competition ? "Yes" : "No"; << endl; //if true print Yes, if false print No.


}


//bool is_fake() - if the name of manufecturer include numbers (and not only chars) then it's fake (and return true).
// else: false(means it's not fake).

bool Yoyo::is_fake() {

	int len = strlen(manufacturer) + 1;

	for (int i = 0; i < len; i++) {
		if (manufacturer[i] == '0' || manufacturer[i] == '1' || manufacturer[i] == '2' || manufacturer[i] == '3'
			|| manufacturer[i] == '4' || manufacturer[i] == '5' || manufacturer[i] == '6' || manufacturer[i] == '7'
			|| manufacturer[i] == '8' || manufacturer[i] == '9') {
			//one of the letters is a num and not char. tried == int but it says not allowed.
			return false;
		}
	}
	return true;
}



void Yoyo::reduce_length(float amount) { //to add this

	float short_length_yoyo;
	short_length_yoyo = length / amount;
	set_length(short_length_yoyo); //still need to check if not legal so print message.

	cout << "Impossible to make the length of the yoyo shorter in this way." << endl;

}




void Yoyo::compete(Yoyo other) {

	other = is_competition; //still to check where the other comes from

	if (is_competition != other) { //if true(yes for competition) against false (not for competition):
		cout << "Winner" << end;
		is_competition ? print(is_competition) : print(other)); //print the details of the winner(true for competition).
	}
	else { //or to do only if both true then tie (and not also both false). to ask.
		cout << "It's a tie" << endl;
	}

}