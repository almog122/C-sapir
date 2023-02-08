//Almog Fadida, ID 315544437. Moran Arzi, ID 200244945.
#include "BST.h"

//constructor

BST::BST(int info) {

	this->info = info;
	this->left = nullptr;
	this->right = nullptr;

}

//copy constructor

BST::BST(const BST* newRoot) {

	this->info = newRoot->info;
	this->left = newRoot->left;
	this->right = newRoot->right;

}


//destructor

BST::~BST() {

	delete left;
	delete right;

}

//Insert a new node to the tree by getting a tree and a new info , and using the new info to determinte the location of the new node

void BST::insert(BST* root, int x) {
	
	if (root == nullptr) { //If the tree is empty at the beginning so fill it or we got to the end (after a leaf) so fill it.
		BST* newNode = new BST(x);
		assert(newNode);
		root = newNode;
	}
	else {
		if (x < root->info) {   //means go to the left subtree
			
			if (root->left == nullptr) { //check if this node has a left subtree and create one for it if not
				BST* newNode = new BST(x);
				assert(newNode);
				root->left = newNode;
			}

			else
				insert(root->left, x); //recursion if it already has a left subtree
		}

		else {  //means go to the right subtree

			if (root->right == nullptr) { //check if this node has a right subtree and create one for it if not
				BST* newNode = new BST(x);
				assert(newNode);
				root->right = newNode;
			}

			else
				insert(root->right, x); //recursion if it already has a right subtree
		}

	}
	
} //end insert function


//search for a number in BST and print the path to the number

void BST::search(int y) {                 //recursion if we got a root from function
	
	if (this == nullptr) {
		cout << "The number " << y << " was not found" << endl; // if we got to a nullptr it means the number is not in th BST
	}
		
	else { //we are still in the BST tree

		if (y == info) { //we found the number in the BST tree and we print it
			cout << y;
			cout << " The number " << y << " was found" << endl;
		}

		else {//we didn't find the number but we are still in BST so we print the current node and countinue searching

			if (y < info) { //we countinue to search left subtree of the current node
				cout << info << " ";
				left->search(y);

			}
			else { //we countinue to search right subtree of the current node
				cout << info << " ";
				right->search(y);
			}
		}
	}
} //end search_one function



