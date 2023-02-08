#include "SoccerPlayer.h"
#include "TennisPlayer.h"

int main() {
	
	/*------This is not polymorphism!!!------*/
	/*
	Player* ptr = NULL;
	SoccerPlayer* messi = NULL;
	TennisPlayer* agassi = NULL;
	cout << "enter 1 for Tennis or 2 for Soccer\n";
	int choice;
	cin >> choice;
	if (choice == 1) {
		ptr = new TennisPlayer("Agassi", 123, "Nike", 11);
		//agassi = new TennisPlayer("Agassi", 123, "Nike", 11);
	}
	else {
		ptr = new SoccerPlayer("Messi", 123, "Barcelona", 10);
		//messi = new SoccerPlayer("Messi", 123, "Barcelona", 10);
	}

	//add your code here:

	
	if (choice == 1) {
		//agassi->set_name("Andere Agassi");
		//agassi->print();
	}
	else {
		//messi->set_name("Leonel Messi");
		//messi->print();
	}
	

	ptr->print();
	ptr->play();
	delete ptr;
	*/
	
	Player* players[2];

	players[0] = new TennisPlayer("Agassi", 123, "Nike", 11);
	players[1] = new SoccerPlayer("Messi", 123, "Barcelona", 10);

	for (int i = 0; i < 2; i++) {
		players[i]->play();
		players[i]->print();
	}

	for (int i = 0; i < 2; i++) {
		delete players[i];
	}
}
