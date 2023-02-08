//Almog Fadida, ID 315544437. Moran Arzi, ID 200244945.

#pragma once 
#include <iostream> 
using namespace std;
#include "BST.h" //???not sure

int main() {

	cout << "Almog Fadida, ID 315544437. Moran Arzi, ID 200244945." << endl;

	//First option for creating the binary search tree

	//depend on the constructor we choose
	//but possible without insert function
	//and just put to root->left->left and so on.




	//Second option for creating the binary search tree
	//using insert function

	//int ourRoot = 

	//first creating the new nodes and then insert all to place using insert function

	int num;

	BST* E9 = new BST(8);
	assert(E9);
	E9->insert(E9,3);
	E9->insert(E9,1);
	E9->insert(E9,6);
	E9->insert(E9,4);
	E9->insert(E9,7);
	E9->insert(E9,10);
	E9->insert(E9,14);
	E9->insert(E9,13);

	cout << "Enter a number to search in our binary search tree." << endl;
	cout << "You will get his path details and if he exist in BST or not."<< endl;
	cin >> num;

	E9->search(num); //sends user number that he wants to search into E9 tree.
	//it's a void function so only prints result (path and final answer if exist or not)


	return 0;

}