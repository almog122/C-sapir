#include "Student.h"

//Setters

void Student::setName(const char* new_name) {
	int len = strlen(new_name) + 1;
	name = new char[len];
	assert(name != NULL);
	strcpy_s(name, len, new_name);

}

void Student::setStudNum(int new_stud_num) {
	if (new_stud_num < 0)
		new_stud_num *= -1;
	
	stud_num = new_stud_num;
}

//print

void Student::print() const {
	cout << "Name: " << name << "| Number of students :" << stud_num << endl;

}

//Builders

Student::Student() {
	setName(DEFSTR);
	setStudNum(1);

}

Student::Student(const char* new_name, int new_stud_num) {
	setName(new_name);
	setStudNum(new_stud_num);
}

//Destroyer

Student::~Student() {
	cout << name << " destroyed" << endl;
	delete[] name;
}
