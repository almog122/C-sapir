#pragma once
#include "Node.h" 

class tree {
private:

	Node* root;

public:
	tree(Node* root);
	~tree();

	Node* getRoot() { return root; }
	
	void insertNodeToTree(Node* parent,Node* child, char location);

	int productOfChildren(Node* t);
	
	int findNumOfFullProductiveNodesInTrinaryTree(Node* t);

}; //end class tree



