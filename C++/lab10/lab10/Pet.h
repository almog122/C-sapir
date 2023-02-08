#pragma once
#include<iostream>
using namespace std;
#define DEF_NAME "NONAME"
#define DEF_AGE 1
class Pet
{
protected:
	char* name;
	int age;
	const bool is_mamal;
public:
	Pet(const char* name = DEF_NAME, int age = DEF_AGE, bool is_mamal = 0);
	Pet(const Pet& other);
	~Pet();
	//operators
	Pet& operator=(const Pet& other);
	friend ostream& operator<<(ostream& out, const Pet& p);
	//getters
	char* get_name() const { return name; }
	int get_age() const { return age; }
	bool get_is_mamal() const { return is_mamal; }
	//setters
	void set_name(const char* name);
	//functions
	void eat();
	void sleep();
};
