#pragma once
#include <iostream>
using namespace std;

#define DEF_NAME "OPEN SEAT"
#define DEF_NUM -1
#define DEF_RANK -1.0
class Player
{
	char* name;
	int num;
	float rank;
	friend ostream& operator<<(ostream& out, const Player& p);
public:
	Player(const char* name = DEF_NAME, int num = DEF_NUM, float rank = DEF_RANK);
	Player(const Player& p);
	~Player();
	//setters
	void set_name(const char* name);
	void set_num(int num);
	void set_rank(float rank);
	//getters inline
	char* get_name()const { return name; }
	int get_num()const { return num; }
	float get_rank()const { return rank; }
	bool operator>(Player &other);
	Player operator--(int i); //postfix because int
};


