#pragma once
#include <iostream>
#include <cassert>
using namespace std;
#define MAX_AGE 25
#define MIN_AGE 1
#define DEF_NAME "Animal"
#define DEF_AGE	2
#define DEF_IS_TRAINED false
#define DEF_IS_HUNGRY false

class Animal
{
protected:
	char* name;
	int age;
	bool is_trained;
	bool is_hungry;

	friend class Contest;
	
public:
	Animal(const char* name = DEF_NAME,int age = DEF_AGE, bool is_trained = DEF_IS_TRAINED, bool is_hungry = DEF_IS_HUNGRY);
	Animal(const Animal& other);
	~Animal();

	//Getter
	const char* get_name() const { return name; }
	int get_age() const { return age; }
	bool get_is_trained() const { return is_trained; }
	bool get_is_hungry() const { return is_hungry; }

	//Setter
	void set_name(const char* name);
	void set_age(int age);
	void set_is_trained(bool is_trained);
	void set_is_hungry(bool is_hungry);

	//Function
	virtual void eat();
	virtual void show();
	virtual void training() = 0;
	Animal& operator=(const Animal& other);
	bool operator==(const Animal& other) const;
	bool operator!=(const Animal& other) const;
	friend ostream& operator<<(ostream& out, Animal& animal);
	
};

