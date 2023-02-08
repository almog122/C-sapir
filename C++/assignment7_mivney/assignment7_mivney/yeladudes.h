//Almog Fadida ID 315544437, Moran Arzi ID 200244945

#pragma once
#include <iostream>
#include <cassert>
using namespace std;
#define SIZE 3   //size of the queue

class yeladudes {

private:

	int head; //point to the head of the queue
	int end;  //point to the end of the queue
	int* arrq;  //the arr that we use as a queue
	int size; //The number of elements that we obtain currently inside the queue

public:

	//constractor, copy constractor and destractor

	yeladudes();
	yeladudes(const yeladudes& other);
	~yeladudes();
	
	

	//implements queue functions with an array

	void initQ();
	void enqueue(const int ID_patient);
	int dequeue();
	bool empty();
	int front();

	//Functions especially for this program 

	void biggerQueue(yeladudes other);
	void removePatientFromQueue();
	void printQ();
	int popchild();
	
};