//Almog Fadida, ID 315544437. Moran Arzi, ID 200244945.
#pragma once
#include <iostream> 
#include <cassert>
using namespace std;

class BST {

private:

	int info;
	BST* left;
	BST* right;

public:

	//constructor and destractor
	BST(int info);
	BST(const BST* newRoot);
	~BST();

	//Functions for BST

	void insert(BST* root, int x); //not sure if needed at all
	void search(int y);   //iterative vertion and root is inside
	
};
