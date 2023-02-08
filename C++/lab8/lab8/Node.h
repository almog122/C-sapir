#pragma once
// forward declaration of class List required to announce that class
// List exists so it can be used in the friend declaration at line 13
template< typename T > class List;

template <typename T>
class Node
{
private:
	T data; // data
	Node<T>* next_ptr; // next node in list

	friend class List<T>; // make List a friend
public:
	Node(const T&); // constructor (copy)
	T get_data() const; // return data in node

}; // end class Node

// constructor
template< typename T >
Node< T >::Node(const T& data) :
	data(data), next_ptr(NULL) {} // end Node constructor

   // return copy of data in node
template< typename T >
T Node< T >::get_data() const
{
	return data;
} // end function get_data
