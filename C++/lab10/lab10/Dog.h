#pragma once
#include "Pet.h"
#define DEF_BRD "Huskey"
class Dog : public Pet
{
	char* breed;
public:
	Dog(const char* name = DEF_NAME, int age = DEF_AGE, bool is_mamal = 0, const char* breed = DEF_BRD);
	Dog(const Dog& other);
	~Dog();
	//operators
	Dog& operator=(const Dog& other);
	friend ostream& operator<<(ostream& out, const Dog& d);

	//setters
	void set_breed(const char* breed);


	//getters
	char* get_breed() const { return breed; }
	//functions
	void eat();
	void fetch_ball();
};

