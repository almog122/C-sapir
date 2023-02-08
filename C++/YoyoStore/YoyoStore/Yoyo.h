#pragma once
#include <iostream>
using namespace std;
#include <cassert>
#define MIN_LENGTH 90
#define MAX_LENGTH 122.5
#define MIN_PRICE_FOR_COM 50
#define MAX_PRICE_FOR_COM 100
#define MIN_PRICE__NOT_FOR_COM 20
#define MAX_PRICE_NOT_FOR_COM 40


class Yoyo
{

private:

	char* manufacturer;
	int price;
	float length;
	bool is_competition;



public:

	//constractors:
	Yoyo();  //empty constractor. This time is for 4 yoyos.
	Yoyo(const char* new_manufacturer, int new_price, float new_length, bool new_is_competition); //for 2 costum made yoyos.

	//destractors:


	//getters(inline):

	char* get_manufacturer() { return manufacturer; }
	int get_price() { return price; }
	float get_length() { return length; }
	bool get_is_competition() { return is_competition; }
}

void set_manufacturer(char* new_manufacturer);
void set_price(int new_price);
void set_length(float new_length);
void set_is_competition(bool new_is_competition);



//functions:

void print();
bool is_fake();
void reduce_length(float amount);
void compete(Yoyo other);
};

