#pragma once
#include "Player.h"
class SoccerPlayer :public Player
{
protected:
	int shirt_num;
	char* team;
public:
	SoccerPlayer(const char* name = "John", int id = -1, const char* team = "N.A.", int shirt_num = -1);
	virtual ~SoccerPlayer();
	SoccerPlayer(const SoccerPlayer& other);
	SoccerPlayer& operator=(const SoccerPlayer& other);
	virtual void play() const;
	virtual void print() const;
	virtual void set_team(const char* team);
};

