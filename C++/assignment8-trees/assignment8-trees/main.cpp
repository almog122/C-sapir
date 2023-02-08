#pragma once
#include <iostream>
#include <cassert>
using namespace std;
#include "tree.h"

int main() {

	//Constructing the tree T1

	Node* root = new Node(5040); //root of tree
	assert(root);
	Node* n1 = new Node(24);
	assert(n1);
	Node* n2 = new Node(210);
	assert(n2);
	Node* n3 = new Node(2);
	assert(n3);
	Node* n4 = new Node(3);
	assert(n4);
	Node* n5 = new Node(4);
	assert(n5);
	Node* n6 = new Node(5);
	assert(n6);
	Node* n7 = new Node(6);
	assert(n7);
	Node* n8 = new Node(7);
	assert(n8);

	tree* t = new tree(root);
	assert(t);

	t->insertNodeToTree(root, n1,'l'); //first subtree of root - only left and right
	t->insertNodeToTree(root, n2, 'r');

	t->insertNodeToTree(n1, n3, 'l');
	t->insertNodeToTree(n1, n4, 'm');
	t->insertNodeToTree(n1, n5, 'r');
	
	t->insertNodeToTree(n2, n6, 'l');
	t->insertNodeToTree(n2, n7, 'm');
	t->insertNodeToTree(n2, n8, 'r');

	
	//send the root (t) to the function and put back the answer in the variable.
	

	//prints the answer
	cout << "This trinary tree has " << t->findNumOfFullProductiveNodesInTrinaryTree(t->getRoot()) << " full productive nodes." << endl;


	delete t;
	
	return 0;
}