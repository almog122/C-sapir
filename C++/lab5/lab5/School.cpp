#include"Student.h"

int main() {

	Student s1("Dina" , 123);
	Student s2;
	Student* ps1 = new Student;
	Student* ptr = new Student("You" , 1234);

	assert(ps1 != NULL);

	s1.print();
	s2.print();
	(*ps1).print();

	s1.setName("Almog");
	s2.setName("Almog");
	(*ps1).setName("Almog");

	s1.setStudNum(2344);
	s2.setStudNum(2344);
	(*ps1).setStudNum(2344);

	s1.print();
	s2.print();
	(*ps1).print();
	(*ptr).print();

	delete ps1;
	delete ptr;

	return 0;
}