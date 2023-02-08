//Almog Fadida ID 315544437, Moran Arzi ID 200244945


#include "yeladudes.h"

//We chose switch case inside do while in order to appley this program.
//The user choice will get in showMenuGetNumChoice function after showing him the menu there (after each choice)
//until he'll press 5 (to exit the program). showMenuGetNumChoice function is located after the main function.

int main() {

	cout << "Almog Fadida ID 315544437, Moran Arzi ID 200244945" << endl;

	cout << "" << endl;

	int showMenuGetNumChoice();

	yeladudes* queue = new yeladudes();

	int choice;

	do {
		choice = showMenuGetNumChoice();

		switch (choice) {
		
		case 1:

			int ID_patient;
			cout << "Please enter your ID number" << endl;
			cin >> ID_patient;
			queue->enqueue(ID_patient);
			break;

		case 2:

			queue->removePatientFromQueue();
			break;

		case 3:
			int child;
			child = queue->popchild(); //remove the first child in queue

			if (child == 0) 
				cout << "no children in queue " << endl;

			else 
				cout << "The child ID is : " << child << endl; //print first child ID
			

			break;

		case 4:

			queue->printQ();
			break;

		}

	} while (choice != 5); //case 5 doesn't exist so it's the exit number from the menu and program.

	delete queue;

	return 0;
}

int showMenuGetNumChoice() {

	int choice;
	//show menu
	cout << "" << endl;
	cout << "1. Add a patient to the queue" << endl;
	cout << "2. Remove a patient from queue" << endl;
	cout << "3. Remove a child from queue" << endl;
	cout << "4. Print the queues' ID numbers" << endl;
	cout << "5. Exit the program" << endl;

	cout << "" << endl;
	//get choice
	cout << "Enter choice: " << endl;
	cin >> choice;

	return choice;
}