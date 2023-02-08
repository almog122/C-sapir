#pragma once
#include "Animal.h"
#define DEF_FUR_COLOR "BLACK"
#define MAX_WEIGHT 60
#define MIN_WEIGHT 3
#define DEF_WEIGHT 3.2f
#define DEF_IS_CLEAN true

class Hamster : public Animal
{
private:
	char* fur_color;
	float weight;
	bool is_clean;

public:
	Hamster(const char* name, int age, bool is_trained, bool is_hungry,const char* fur_color = DEF_FUR_COLOR, float weight = DEF_WEIGHT, bool is_clean = DEF_IS_CLEAN);
	Hamster(Hamster& other);
	~Hamster();

	//Getter

	const char* get_fur_color() const { return fur_color; }
	float get_weight() const { return weight; }
	bool get_is_clean() const {return is_clean; }

	//Setter

	void set_fur_color(const char* fur_color);
	void set_weight(float weight);
	void set_is_clean(bool is_clean);

	//Function

	virtual void eat();
	virtual void show();
	virtual void training();
	void brush_fur();

	Hamster& operator=(const Hamster& other);
	Hamster operator+(Hamster& other);
	int operator++();
	int operator--();
	friend ostream& operator<<(ostream& out, Hamster& ham);

};

