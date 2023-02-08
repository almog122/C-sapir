#include <iostream>
#include <cassert>
using namespace std;

class Date
{
	Date(int d, int m, int y) { day = d; month = m; year = y; }
	~Date() { cout << day << '/' << month << '/' << year << endl; }
private:
	int day;
	int month;
	int year;
};

class Employee
{
public:
	Employee(const char *name, int d, int m, int y) :startDate(d,m,y)
	{
		fName = new char[strlen(name) + 1];
		assert(fName != NULL);
		strcpy_s(fName, strlen(name) + 1 ,name);
	}

	~Employee()
	{
		delete[] fName;
	}
private:
	char *fName;
	Date startDate;
};

class Administrator : public Employee
{
public:
	Administrator(): Employee("asf",1,1,1)
	{
		position = NULL;
	}
	Administrator(char *s): Employee("asf", 1, 1, 1)
	{
		position = new char[strlen(s) + 1];
		assert(position != NULL);
		strcpy_s(position, strlen(s) + 1, s);
	}
	~Administrator()
	{
		delete[] position;
	}
private:
	char *position;
};int main()
{
	Administrator admin;
	return 0;
}