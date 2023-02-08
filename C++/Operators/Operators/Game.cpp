#include "Player.h"
#include "Team.h"

void main() {

	Player p1("Yossi", 10, 8.8);
	Player p2("Mohammad", 20, 9.9);
	if (p1 > p2) {
		cout << "this is bigger" << endl;
	}
	else {
		cout << "other is bigger" << endl;
	}
	Player p3;

	Player* s = new Player[3] {p1,p2,p3};

	

	Team t("brazil",s);

	//this is an address
	cout << t;
}
