#pragma once
#include <iostream>
using namespace std;
#include "Node.h"
template<typename T>
class List
{
private:
	Node<T> *head; // pointer to first node
	Node<T> *tail; // pointer to last node
	// utility function to allocate new node
	Node <T>* create_node(const T&);
public:
	List(); // constructor
	~List(); // destructor
	void insert_at_front(const T&);
	void insert_at_back(const T&);
	bool remove_from_front();
	bool remove_from_back();
	bool is_empty() const;
	void print() const;
	void swap(Node<T>*& a, Node<T>*& b);
	void sort();
	int get_location(const T& node);
	void print_location(int location);

}; // end class List

// default constructor
template< typename T>
List<T>::List()
	: head(NULL), tail(NULL) {} // end List constructor

// is List empty?
template<typename T>
bool List<T>::is_empty() const
{
	return head == NULL;
} // end function isEmpty

template<typename T>
void List<T>::insert_at_back(const T& value)
{
	Node<T>* new_node = create_node(value); // new node
	if (is_empty()) // List is empty
		head = tail = new_node; // new list has only one node
	else // List is not empty
	{
		tail->next_ptr = new_node; // update previous last node
		tail = new_node; // new last node
	} // end else
} // end function insert_at_back

template <typename T>
Node<T>* List<T>::create_node(const T& value)
{
	return new Node<T>(value);
} // end function create_node

// display contents of List
template<typename T>
void List<T>::print() const
{
	if (is_empty()) // List is empty
	{
		cout << "The list is empty\n\n";
		return;
	} // end if
	Node<T> *current_ptr = head;
	cout << "The list is: ";
	while (current_ptr != NULL) // get element data
	{
		current_ptr->data.print();
		current_ptr = current_ptr->next_ptr;
		
	} // end while
	cout << "\n\n";
} // end function print

// destructor
template< typename T>
List<T>::~List()
{
	if (!is_empty()) // List is not empty
	{
		cout << "Destroying nodes ...\n";
		Node<T> *current_ptr = head;
		Node<T> *tmp;
		while (current_ptr != NULL) // delete remaining nodes
		{
			tmp = current_ptr;
			tmp->data.print();
			current_ptr = current_ptr->next_ptr;
			delete tmp;
		} // end while
	} // end if
} // end destructor

// delete node from back of list
template< typename T>
bool List<T>::remove_from_back()
{
	if (is_empty()) // List is empty
		return false; // delete unsuccessful
	else
	{
		Node<T> *tmp = tail; // hold tmp to delete
		if (head == tail) // List has one element
			head = tail = NULL; // no nodes remain after removal
		else
		{
			Node<T> *current_ptr = head;
			// locate second-to-last element
			while (current_ptr->next_ptr != tail)
				current_ptr = current_ptr->next_ptr; // move to next node
			tail = current_ptr; // remove last node
			current_ptr->next_ptr = NULL; // this is now the last node
		} // end else
		delete tmp; // reclaim former last node
		return true; // delete successful
	} // end else
} // end function remove_from_back

// insert node at front of list
template<typename T>
void List<T>::insert_at_front(const T& value)
{
	Node< T > *ptr = create_node(value); // new node
	if (is_empty()) // List is empty
		head = tail = ptr; // new list has only one node
	else // List is not empty
	{
		ptr->next_ptr = head; // point new node to previous 1st node
		head = ptr; // aim head at new node
	} // end else
} // end function insert_at_front

// delete node from front of list
template< typename T >
bool List< T >::remove_from_front()
{
	if (is_empty()) // List is empty
		return false; // delete unsuccessful
	else
	{
		Node<T> *tmp = head; // hold tmp to delete
		if (head == tail)
			head = tail = NULL; // no nodes remain after removal
		else
			head = head->next_ptr; // point to previous 2nd node
		delete tmp; // reclaim previous front node
		return true; // delete successful
	} // end else
} // end function remove_from_front

template<typename T>
void List<T>::swap(Node<T>*& a, Node<T>*& b) {
	
	if (a == head) {

		a->next_ptr = b->next_ptr; // a point to what b is pointing
		b->next_ptr = a; // b now point to a
		head = b; 
	}

	if (b == head) {

		b->next_ptr = a->next_ptr; // b point to what a is pointing
		a->next_ptr = b; // a now point to b
		head = a;
	}

	if (a == tail) {

		Node<T>* temp1 = head; 

		while (temp1->next_ptr != b) { // to get the node before b
			temp1 = temp1->next_ptr;
		}

		temp1->next_ptr = a; // the node before b point to a
		a->next_ptr = b; // a point to b
		b->next_ptr = nullptr; //b point to null
		tail = b;
	}

	if (b == tail) {

		Node<T>* temp1 = head;

		while (temp1->next_ptr != a) { // to get the node before a
			temp1 = temp1->next_ptr;
		}

		temp1->next_ptr = b; //the node before a point to a
		b->next_ptr = a; // b point to a
		a->next_ptr = nullptr; // a point to null
		tail = a;
	}

	if (a != head && a != tail && b != head && b != tail && a->next_ptr == b) {

		Node<T>* temp1 = head;
		Node<T>* temp2 = b->next_ptr;

		while(temp1->next_ptr != a ){ // to get the node before a
			temp1 = temp1->next_ptr;
		}

		temp1->next_ptr = b; // the node before a point to b
		b->next_ptr = a; // b point to a
		a->next_ptr = temp2; // a point to the node b pointed previously

	}

	if (a != head && a != tail && b != head && b != tail && b->next_ptr == a) {

		Node<T>* temp1 = head;
		Node<T>* temp2 = a->next_ptr;

		while (temp1->next_ptr != b) { // to get the node before b
			temp1 = temp1->next_ptr;
		}
	
		(temp1->next_ptr) = a; // the node before a point to b
		a->next_ptr = b; // a point to b
		b->next_ptr = temp2; // b point to the node a pointed previously


	}
	
}

template<typename T>
void List<T>::sort() {

	Node<T>* temp1 = head; // micro , check the list with the node he was given.
	Node<T>* temp2 = head; // macro , make it so we check all the node on by one after etc change. 

	do {

		while (temp1->next_ptr != nullptr) { 

			if (temp1->data.is_bigger(temp1->next_ptr->data) > 0) { // Check if the node temp1 pointing to has a bigger diameter then the node after temp1
				swap(temp1, temp1->next_ptr); // swap between the node temp1 pointing to , to the one after the node temp1.
			}
			
			else {
				temp1 = temp1->next_ptr; // forward on the list in a micro 
			}

		}

		temp2 = temp2->next_ptr; // forward on the list in a macro 
		temp1 = head; //reset temp1 to the start

	} while (temp2->next_ptr != nullptr);
}

template<typename T>
int List<T>::get_location(const T& node) {

	Node<T>* temp = head;
	int index = 0; //start the first node

	while (temp->next_ptr != NULL) {
		
		if (temp->data.is_equal(node)){ // Check if the data in temp is the same as in the node.
			return index; //return the location of the node on the list
		}

		temp = temp->next_ptr; //forward the list
		index++;
	}

	return -1; //return -1 if not on the node not in list
}

template<typename T>
void List<T>::print_location(int location) {

	Node<T>* temp = head;

	if (location < 0) { //Check if the location given is not on the list
		cout << "Error when locating Node" << endl;
	}
	
	else {

		for (int i = 0; i < location; i++) { //forward in the list until we reach the location
			temp = temp->next_ptr;
		}

		temp->data.print(); //print the node in the location
	}
}