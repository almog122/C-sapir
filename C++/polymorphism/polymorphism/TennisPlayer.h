#pragma once
#include "Player.h"
class TennisPlayer :public Player
{
protected:
	char* sponsor;
	int rank;
public:
	TennisPlayer(const char* name = "John", int id = -1, const char* sponsor = "Gillete.", int rank = 9999);
	virtual ~TennisPlayer();
	TennisPlayer(const TennisPlayer& other);
	TennisPlayer& operator=(const TennisPlayer& other);
	virtual void play() const;
	virtual void print() const;
	void set_sponsor(const char* team);
	virtual void increase_rank(int add);
};

