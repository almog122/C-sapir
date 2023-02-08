#include "Monkey.h"
#define MAXLEN 10

//Setters

void Monkey::setWeight(double newWeight) {

	if (newWeight < 3 || newWeight > 200) {

		cout << "Error : Weight" << endl;
		weight = 100;
	}

	else {

		weight = newWeight;
	}
}

void Monkey::setName(const char* newName) {

	if (strlen(newName) > MAXLEN) {

		cout << "Error : Name" << endl;
		
		char temp[] = "Kofiko";
		strcpy_s(name, strlen(temp) + 1, temp);

	}

	else {
		strcpy_s(name, strlen(newName) + 1, newName);
	}

}

void Monkey::setAge(int newAge) {
	
	if (newAge < 0 || newAge > 100) {

		age = 40;
	}
	
	else {
		age = newAge;
	}
}

//Builders

Monkey::Monkey()
{
	int age = 0;
	char temp[] = "noName";
	strcpy_s(name, strlen(temp) + 1, temp);
	double weight = 0;
}

Monkey::Monkey(int newAge, const char newName[MAXLEN], double newWeight)
{

	//Age

	if (newAge < 0 || newAge > 100) {

		age = 40;
	}

	else {
		age = newAge;
	}

	//Name

	if (strlen(newName) > MAXLEN) {

		char temp[] = "Kofiko";
		strcpy_s(name, strlen(temp) + 1, temp);

	}

	else {
		strcpy_s(name, strlen(newName) + 1, newName);
	}
	
	//Weight

	if (newWeight < 3 || newWeight > 200) {

		weight = 100;
	}

	else {

		weight = newWeight;
	}

	
}

//functions

void Monkey::print() {

	cout << "The age is : " << age << endl;
	cout << "The name is : " << name << endl;
	cout << "The Weight is : " << weight << endl;
}

void Monkey::eat(const char* food) {

	setWeight(weight + 10);

	cout << name << " eats " << food << endl;
}

void Monkey::poop() {

	setWeight(weight - 15);
}
