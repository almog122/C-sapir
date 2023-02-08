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
	Node <T>* create_node(const T &);
public:
	List(); // constructor
	~List(); // destructor
	void insert_at_front(const T &);
	void insert_at_back(const T &);
	bool remove_from_front(T &);
	bool remove_from_back(T &);
	bool is_empty() const;
	void print() const; 

}; // end class List

// default constructor
template<typename T>
List<T>::List()
	: head(NULL), tail(NULL) {} // end List constructor

template <typename T>
Node<T>* List<T>::create_node(const T& value)
{
	return new Node<T>(value);
} // end function create_node

template <typename T>
bool List<T>::is_empty() const {
	return head == NULL;
}

template<typename T>
void List<T>::insert_at_back(const T& value)
{
	Node<T>* new_node = create_node(value); // new node
	if (is_empty()) // List is empty
		head = tail = new_node; // new list has only one node
	else // List is not empty
	{
		tail->next_ptr = new_node; // update previous last node, tail-> = (*tail).
		tail = new_node; // new last node
	} // end else
} // end function insert_at_back

template<typename T>
void List<T>::print() const
{
	if (is_empty()) // List is empty
	{
		cout << "The list is empty\n\n";
		return;
	} // end if
	Node<T>* current_ptr = head;
	cout << "The list is: ";
	while (current_ptr != NULL) // get element data
	{
		cout << current_ptr->data << endl;
		current_ptr = current_ptr->next_ptr;
	} // end while
	cout << "\n\n";
} // end function print

// destructor
template< typename T >
List< T >::~List()
{
	if (!is_empty()) // List is not empty
	{
		cout << "Destroying nodes ...\n";
		Node<T> *current_ptr = head;
		Node<T> *tmp;
		while (current_ptr != NULL) // delete remaining nodes
		{
			tmp = current_ptr;
			cout << tmp->data << '\n';
				current_ptr = current_ptr->next_ptr;
			delete tmp;
		} // end while
	} // end if
} // end destructor

// delete node from back of list
template< typename T>
bool List<T>::remove_from_back(T& value)
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
		value = tmp->data; // return value from old last node
		delete tmp; // reclaim former last node
		return true; // delete successful
	} // end else
} // end function remove_from_back

// insert node at front of list
template<typename T>
void List<T>::insert_at_front(const T& value)
{
	Node<T> *ptr = create_node(value); // new node
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
bool List< T >::remove_from_front(T &value)
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
		value = tmp->data; // return data being removed
		delete tmp; // reclaim previous front node
		return true; // delete successful
	} // end else
} // end function remove_from_front


