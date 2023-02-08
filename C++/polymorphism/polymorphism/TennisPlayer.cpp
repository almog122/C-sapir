#include "TennisPlayer.h"

TennisPlayer::TennisPlayer(const char* name, int id, const char* sponsor, int rank)
	:Player(name, id), rank(rank)
{
	set_sponsor(sponsor);
}
TennisPlayer::TennisPlayer(const TennisPlayer& other) : Player(other) {
	this->sponsor = NULL;
	*this = other;
}
TennisPlayer::~TennisPlayer()
{
	cout << "~TennisPlayer" << endl;
	delete[] sponsor;
}
TennisPlayer& TennisPlayer::operator=(const TennisPlayer& other) {
	if (this != &other) {
		Player::operator=(other);
		delete[] this->sponsor;
		set_sponsor(other.sponsor);
		this->rank = other.rank;
	}
	return *this;
}

void TennisPlayer::set_sponsor(const char* sponsor) {
	int len = strlen(sponsor) + 1;
	this->sponsor = new char[len];
	assert(sponsor);
	strcpy_s(this->sponsor, len, sponsor);
}

void TennisPlayer::play() const {
	cout << sponsor << " is annanoucing that " << name << " rank has increased to " << rank << endl;
}
void TennisPlayer::print() const {
	Player::print();
	cout << "Sponsor: " << sponsor << ", rank " << rank << endl;
}
void TennisPlayer::increase_rank(int add) {
	rank -= add;
}
