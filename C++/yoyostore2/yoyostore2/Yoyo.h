#pragma once
class Yoyo

#define MAXLEN 25
#define STR_YOYOYO "YOYOYO"
#define STR_BALIYOYO "BALIYOYO"
#define STR_CH1NYOYO "CH1NYOYO"
#define YOYOYO_COMP_PRICE 79
#define YOYOYO_NOTCOMP_PRICE 39
#define YOYOYO_NOTCOMP_LENGTH 120
#define BALIYOYO_COMP_PRICE 99
#define BALIYOYO_NOTCOMP_PRICE 89
#define BALIYOYO_NOTCOMP_LENGTH 118.2f
#define CH1NYOYO_COMP_PRICE 69
#define CH1NYOYO_LENGTH_PRICE 118.2f
#define CH1NYOYO_NOTCOMP_PRICE 22
#define CH1NYOYO_NOTCOMP_LENGTH_PRICE 118.2fA
#define MINLENGTH 90
#define MAXLENGTH 122.5
#define MINPRICE 20
#define MAXPRICE 100
#define ASCII_ZERO 48
#define ASCII_NINE 57
{
private:
	char* manufacturer;
	int price;
	float length;
	bool is_competition;

public:
	Yoyo(const char* new_manufacturer, int new_price, float new_length, bool new_is_competition);
	Yoyo();
	~Yoyo();

	//functions
	void print();
	bool is_fake();
	void reduce_length(float amount);
	void compete(Yoyo other);


	//getters 
	char* get_manufacturer() { return manufacturer; }
	int get_price() { return price; }
	float get_length() { return length; }
	bool get_is_competition() { return is_competition; }

	//setters
	void set_manufacturer(const char* new_manufacturer);
	void set_price(int new_price);
	void set_length(float new_length);
	void set_is_competition(bool new_is_competition);
};

