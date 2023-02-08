
#include "Node.h"


//empty constructor
Node::Node(const int data) {
	this->setData(data);
	this->degree = 0;
	this->left = nullptr;
	this->right = nullptr;
	this->mid = nullptr;
}

// constructor. maybe need copy cons?

Node::~Node() {
	delete left;
	delete right;
	delete mid;
}

//setters

void Node::setData(int data) {
	this->data = data;

}

void Node::setLeft(Node* left) {
	this->left = left;
	
	if (left != nullptr)
		degree++;
}

void Node::setRight(Node* right) {
	this->right = right;

	if (right != nullptr)
		degree++;
}

void Node::setMid(Node* mid) {

	this->mid = mid;

	if (mid != nullptr)
		degree++;
}

