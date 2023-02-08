#include "Player.h"
Player::Player(const char* name, int num, float rank)
{
	set_name(name);
	set_num(num);
	set_rank(rank);
}
Player::Player(const Player& p)
{
	set_name(p.name);
	set_num(p.num);
	set_rank(p.rank);
}
Player::~Player()
{
	delete[] name;
}
void Player::set_name(const char* name) {
	int len = strlen(name) + 1;
	this->name = new char[len];
	strcpy_s(this->name, len, name);
}
void Player::set_num(int num) {
	if (num < 0)
		num *= -1;
	this->num = num;
}
void Player::set_rank(float rank) {
	if (rank > 10)
		rank = 6.0;
	this->rank = rank;
}

bool Player::operator>(Player &other) {
	return this->rank > other.rank; // (somthing > somthing) is  a bool 
}

ostream& operator<<(ostream& out, const Player& p) {
	cout << "Number " << p.num << ": " << p.name << ", rank: " << p.rank;
	return cout; //ostream -> (cout << p1)
}

Player Player::operator--(int i) {
	Player tmp(*this); // copy the one calling the function to tmp
	this->rank -= 0.1; // decressing 
	return tmp;
}