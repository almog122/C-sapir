//Almog Fadida ID 315544437, Moran Arzi ID 200244945

#include "yeladudes.h"

//constractor, copy constractor and destractor

yeladudes::yeladudes() {
	initQ();
	
}//end constractor yeladudes()


yeladudes::yeladudes(const yeladudes& other){

	delete[] arrq;
	arrq = other.arrq;
	head = other.head;
	end = other.end;
	size = other.size;

}//end copy constractor yeladudes()


yeladudes::~yeladudes() {
	delete[] arrq;
	
}//end destractor ~yeladudes()



//implements queue functions with an array

void yeladudes::initQ() {
	
	arrq = new int[SIZE] {NULL};  //initilazing the arr (as queue) with size 20 and each one will be NULL at the beginning

	assert(arrq);

	head = 0; //In the beginning head and end are at the same place, the start.
	
	end = 0;

	size = 0; //no elements are inside at first

}

void yeladudes::biggerQueue(yeladudes other) {
	
	int* temp = new int[other.size + SIZE];

	assert(temp);

	for (int i = 0; i < other.size; i++) {
		temp[i] = other.arrq[i];
	}
	
	delete[] other.arrq;
	
	other.arrq = temp;

}


void yeladudes::enqueue(const int ID_patient) {

	if (ID_patient <= 0)
		cout << "not a valid ID" << endl; //ID must be bigger than 0.

	else {
		if (size == SIZE) { //The queue is full and there's no place to enqueue
			biggerQueue(*this);
		}

		else { //if (end != head) - there's room in queue
			arrq[end] = ID_patient;  //we put ID at the value of the end
			
			end = (end + 1) ; //and than change end place one step more in the queue (mod because it's circular queue,
			//means if we're at the 20 box (the end) so it goes to the beginning again after that.
			
			size++; //increase size because we enqueue one
		}
	}
} //end enqueue(const int ID_patient)


int yeladudes::dequeue() { //dequeue will remove the first element in queue and increase the head

	int temp;
	
	if (!(this->empty())) { //if queue isn't empty
		temp = arrq[head]; //put the value of the first element in queue inside temp
		arrq[head] = NULL; //and delete the value now
		
		head = (head + 1); //increase head like before (in mod for a circular manner)

		size--; //decrease size

		return temp; //return the value that was in the head
	}

	return NULL; //if queue is empty so return null and don't remove anything.

} //end dequeue()


bool yeladudes::empty() {
	
	if (arrq[head] == NULL) { //if the first element is null it means the queue is empty
		return true;
	}
	else {
		return false;
	}

} //end empty()

int yeladudes::front() {

	if (!(this->empty())) { //if queue isn't empty pick at the head (value).
	
		return arrq[head]; 
	}

	return NULL; //if queue is empty show Null because this is the element head  

} //end front()




//Functions especially for this program

void yeladudes::removePatientFromQueue() { 
	if (!this->empty()) { // Check if a parient in the queue
		cout << "The patient has been removed from the queue." << endl;
		cout << "His details were: " << endl;
		cout << this->dequeue() << endl;  // We print the patient details and remove him from the queue
		
	}
	else { //If the queue is empty
		cout << "ERROR: There are no patients in the queue so we can't remove from queue." << endl;
		cout << "You must enter a patient into the queue and only then remove him from queue."<< endl;
	}
	
} //end removePatientFromQueue function



int yeladudes::popchild() { 
	
	int firstChild;
	yeladudes* temp = new yeladudes(); // Make a new queue

	assert(temp);
	
	while (!(this->empty()) && (this->front()) < 1000 ) { //Until we encounter a patient with ID bigger then 999 (child)
		temp->enqueue(this->dequeue());					//we take the head of the main queue (adult) and put him in a temp queue
	}													//and we remove him from the main queue.

	if (!this->empty()) //We found a child
		firstChild = this->dequeue();
	else				//We did not find a child
		firstChild = 0;

	while (!this->empty()) { // We countinue to remove from main queue and add it to the temp queue
		temp->enqueue(this->dequeue()); //so that all the main queue is in the temp without the child (we save the main queue order).
	}


	while (!temp->empty()) { //We return the main queue to its original order without the child.
		this->enqueue(temp->dequeue());
	}

	delete temp;

	return firstChild;

	
} //end popchild function



void yeladudes::printQ() {
	
	yeladudes* temp = new yeladudes(); //we use a second arr as queue in order to implements print function without damaging the main
										//queue order.
	assert(temp);

	while(!this->empty()){ 
		temp->enqueue(this->front()); //we add the head of the main queue without removing it and we add it to the temp queue
		cout << "The patient: " << this->dequeue() << " is in the queue" << endl; //we print the patient that in the queue.
	}
	
	while (!temp->empty()) { //We return the main queue to its original order.
		this->enqueue(temp->dequeue());
	}


} //end printQ function