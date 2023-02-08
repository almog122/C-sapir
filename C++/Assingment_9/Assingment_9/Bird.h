#pragma once
#include "Animal.h"
#define DEF_WING_LENGTH 0.8 

class Bird : public Animal
{
private:
	char* type;
	const float wing_length;

public:
	Bird(const char* name, int age, bool is_trained, bool is_hungry, const char* type, const float wing_length = DEF_WING_LENGTH);
	Bird(const Bird& other);
	~Bird();

	//Getter

	const char* get_type() const { return type; }
	const float get_wing_length() const { return wing_length; }

	//Setter

	void set_type(const char* type);
	
	//
	virtual void eat();
	virtual void show();
	virtual void training();

	Bird& operator=(const Bird& other);
	bool operator==(const Bird& other) const;
	bool operator!=(const Bird& other) const;
	friend ostream& operator<<(ostream& out, Bird& bird);
};

