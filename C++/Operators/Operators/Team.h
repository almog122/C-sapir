#pragma once
#include "Player.h"
#define SIZE 3
#define DEF_TEAM "C++"
class Team
{
	char* name;
	Player players[SIZE]; // the array come with default players, not trash.
	friend ostream& operator<<(ostream& out, Team t);
public:
	Team(const char* name = DEF_TEAM, Player players[] = NULL);
	void set_name(const char* name);
	~Team();
};

