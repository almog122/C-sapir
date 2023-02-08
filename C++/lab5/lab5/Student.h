#include <iostream>
#include <cassert>
#define DEFSTR ""
using namespace std;

class Student
{
private:

	char* name;
	int stud_num;

public:
	
	//Builders
	Student();
	Student(const char* new_name, int new_stud_num);

	//Getters
	char* getName() const { return name; }
	int getStudNum() const { return stud_num; }


	//Setters
	void setName(const char* new_name);
	void setStudNum(int new_stud_num);

	//print
	void print() const;

	//Destructor
	~Student();
};

