/*
lab1.cpp: data types, warnings  and debugger
*/
#include <iostream>

int main()
{
	int num1 = 100;
	std::cout << "num1= " << num1 << std::endl;
	int num2;
	num2 = 200'555'111;
	std::cout << "num2= " << num2 << std::endl;
	int num3(3);
	std::cout << "num3= " << num3 << std::endl;
	int num4{ 4 };
	std::cout << "num4= " << num4 << std::endl;

	double dnum1 = 2.2;
	float fnum1 = 123.456;
	double dnum2 = 2.4565f;
	int num5 = dnum1;
	std::cout << "dnum1= " << dnum1 << std::endl;
	std::cout << "dnum2= " << dnum2 << std::endl;
	std::cout << "num5= " << num5 << std::endl;

	char c1 = 'a';
	char c2 = 'b';
	int cnum1 = c1;
	std::cout << "c1= " << c1 << std::endl;
	std::cout << "c2= " << c2 << std::endl;
	std::cout << "cnum1= " << cnum1 << std::endl;

	bool flag = false;
	std::cout << "flag= " << flag << std::endl;
	flag = num1;
	std::cout << "flag= " << flag << std::endl;
	flag = -dnum1;
	std::cout << "flag= " << flag << std::endl;


	unsigned char n1 = 128;
	char n2 = 128;
	std::cout << "n1= " << n1 << std::endl;
	std::cout << "n2= " << n2 << std::endl;
	n1 = 254;
	n2 = 254;
	std::cout << "n1= " << n1 << std::endl;
	std::cout << "n2= " << n2 << std::endl;
	n1 = 300;
	n2 = 300;
	std::cout << "n1= " << n1 << std::endl;
	std::cout << "n2= " << n2 << std::endl;

	system("pause");
	return 0;
}