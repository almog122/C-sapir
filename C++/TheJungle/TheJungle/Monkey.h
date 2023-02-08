#include <iostream>
#define MAXLEN 10
using namespace std;

class Monkey {
private:

	int age;
	char name[MAXLEN];
	double weight;


public:

	void print();
	void eat(const char* food);
	void poop();


	//Getters

	int getAge() { return age; }
	char* getName() { return name; }
	double getWeight() { return weight; }

	//Setters

	void setAge(int newAge);
	void setName(const char* newName);
	void setWeight(double newWeight);

	//Builders

	Monkey();
	Monkey(int newAge, const char newName[MAXLEN], double newWeight);

};

