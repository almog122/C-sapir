#include "Player.h"
Player::Player(const char* name, int id) :id(id)
{
	set_name(name);
}
Player::Player(const Player& other) : id(other.id) {
	this->name = NULL;
	*this = other;
}

Player::~Player()
{
	cout << "~Player" << endl;
	delete[] name;
}
Player& Player::operator=(const Player& other) {
	if (this != &other) {
		delete[] this->name;
		set_name(other.name);
	}
	return *this;
}
void Player::set_name(const char* name) {
	int len = strlen(name) + 1;
	this->name = new char[len];
	assert(name);
	strcpy_s(this->name, len, name);
}
/*
void Player::play() const {
	cout << "Player " << name << " is in the game zone" << endl;
}
*/
void Player::print() const {
	cout << "Name: " << name << ", ID " << id << endl;
}
