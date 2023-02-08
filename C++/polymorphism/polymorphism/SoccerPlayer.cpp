#include "SoccerPlayer.h"

SoccerPlayer::SoccerPlayer(const char* name, int id, const char* team, int shirt_num)
	:Player(name, id), shirt_num(shirt_num)
{
	set_team(team);
}
SoccerPlayer::SoccerPlayer(const SoccerPlayer& other) : Player(other) {
	this->team = NULL;
	*this = other;
}
SoccerPlayer::~SoccerPlayer()
{
	cout << "~SoccerPlayer" << endl;
	delete[] team;
}
SoccerPlayer& SoccerPlayer::operator=(const SoccerPlayer& other) {
	if (this != &other) {
		Player::operator=(other);
		delete[] this->team;
		set_team(other.team);
		this->shirt_num = other.shirt_num;
	}
	return *this;
}

void SoccerPlayer::set_team(const char* team) {
	int len = strlen(team) + 1;
	this->team = new char[len];
	assert(team);
	strcpy_s(this->team, len, team);
}

void SoccerPlayer::play() const {
	cout << "Team " << team << " presents player number " << shirt_num << " " << name << endl;
}
void SoccerPlayer::print() const {
	Player::print();
	cout << "Team: " << team << ", Shirt number " << shirt_num << endl;
}
