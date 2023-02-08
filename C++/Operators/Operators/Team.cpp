#include "Team.h"

Team::Team(const char* name, Player players[])
{
	if (players != NULL) {
		for (int i = 0; i < SIZE; i++) {
			//this->players[i] = players[i];
			this->players[i].set_name(players[i].get_name());
			this->players[i].set_rank(players[i].get_rank());
			this->players[i].set_num(players[i].get_num());
		}
	}
	set_name(name);
}

Team::~Team()
{
	delete[] name;
}

void Team::set_name(const char* name) {
	int len = strlen(name) + 1;
	this->name = new char[len];
	strcpy_s(this->name, len, name);
}

ostream& operator<<(ostream& out, Team t) {
	
	cout << "Team : " << t.name << " : " << endl;
	for (int i = 0; i < SIZE; i++)
		cout << t.players[i];

	return cout;
}