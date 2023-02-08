#include "tree.h"


tree::tree(Node* root) {

	this->root = root;


} //end createTree function

tree::~tree() {
	delete root;
	
}

void tree::insertNodeToTree(Node* parent, Node* child, char location) {

	if (location == 'l') {
		parent->setLeft(child);
	}

	if (location == 'r') {
		parent->setRight(child);
	}

	if (location == 'm') {
		parent->setMid(child);
	}

} //end insertNodeToTree function

int tree::productOfChildren(Node* t) {
	int product = 1;

	if (t->getLeft() != nullptr)
		product *= t->getLeft()->getData();

	if (t->getRight() != nullptr)
		product *= t->getRight()->getData();

	if (t->getMid() != nullptr)
		product *= t->getMid()->getData();

	return product;
}

int tree::findNumOfFullProductiveNodesInTrinaryTree(Node* t) {
	if (t == nullptr || t-> getDegree() == 0)
		return 0;
	
	if (t->getDegree() == 3 && productOfChildren(t) == t->getData())
		return 1 + findNumOfFullProductiveNodesInTrinaryTree(t->getLeft())
		+ findNumOfFullProductiveNodesInTrinaryTree(t->getMid())
		+ findNumOfFullProductiveNodesInTrinaryTree(t->getRight());
	
	return findNumOfFullProductiveNodesInTrinaryTree(t->getLeft())
	+ findNumOfFullProductiveNodesInTrinaryTree(t->getMid())
	+ findNumOfFullProductiveNodesInTrinaryTree(t->getRight());
}


