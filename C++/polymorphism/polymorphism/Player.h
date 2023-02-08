#pragma once
#include <iostream>
#include <assert.h>
using namespace std;
class Player
{
protected:
	char* name;
	const int id;
public:
	Player(const char* name = "John", int id = -1);
	Player(const Player& other);
	virtual ~Player();
	Player& operator=(const Player& other);
	virtual void play() const = 0; //הופך את המחלקה לאבסטרקיית ,היא טהורה כי אין מימוש של הפונקציה
	virtual void print() const = 0;
	void set_name(const char* name);
	char* get_name()const { return name; }
};

