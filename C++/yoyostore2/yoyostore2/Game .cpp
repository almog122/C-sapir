#include "Yoyo.h"
#include <iostream>
#include <cassert>
using namespace std;
#define SIZE 6

int main() {
	char str[MAXLEN];
	int price;
	float length;
	bool competition;

	cout << "Enter the name of manufacturer of the yoyo y1" << endl;
	cin >> str;
	cout << "Enter the price for yoyo y1" << endl;
	cin >> price;
	cout << "Enter the length for yoyo y1" << endl;
	cin >> length;
	cout << "Is yoyo y1 for competition? Enter 1 for true and 0 for false" << endl;
	cin >> competition;
	
	Yoyo y1(str, price, length, competition);
	y1.print();
	y1.is_fake();

	cout << endl;

	cout << "Enter the name of manufacturer of the yoyo y2" << endl;
	cin >> str;
	cout << "Enter the price for yoyo y2" << endl;
	cin >> price;
	cout << "Enter the length for yoyo y2" << endl;
	cin >> length;
	cout << "Is yoyo y2 for competition? Enter 1 for true and 0 for false" << endl;
	cin >> competition;

	Yoyo y2(str, price, length, competition);
	y2.print();
	y2.is_fake();

	cout << endl; 

	Yoyo y3(STR_YOYOYO, 39, 120, true);
	Yoyo y4(STR_BALIYOYO, 89, 118.2f, false);
	Yoyo y5(STR_CH1NYOYO, 22, 118.2f, false);
	Yoyo y6(STR_CH1NYOYO, 47, 110.5f, false);
	

	Yoyo **yoyos = new Yoyo*[SIZE];
	yoyos[0] = &y1;
	yoyos[1] = &y2;
	yoyos[2] = &y3;
	yoyos[3] = &y4;
	yoyos[4] = &y5;
	yoyos[5] = &y6;

	cout << endl;
	
	//printing yoyos from the array
	for (int i = 0; i < SIZE; i++) {
		cout << "printing " << i+1 << " of " << SIZE << endl; 
		yoyos[i][0].print();
		cout << endl; 
	}

	//printing yoyos only for competition
	for (int j = 0; j < SIZE; j++) {
		if (yoyos[j][0].get_is_competition() == true) {
			cout << "printing " << j + 1 << " for competition: " << endl;
			yoyos[j][0].print();
			cout << endl;
		}
	}

	// its a tie 
	y5.compete(y6);

	// its a win
	y3.compete(y4);

	//half size of y4

	cout <<"The length of y4 before reducing half " << y4.get_length() << endl;
	y4.reduce_length((y4.get_length() * 0.5f));
	cout << "The length of y4 after reducing half " << y4.get_length() << endl;
	
	//tenth size of y5
	cout << "The length of y5 before reducing tenth " << y5.get_length() << endl;
	y5.reduce_length((y5.get_length() * 0.1f));
	cout << "The length of y5 after reducing tenth " << y5.get_length() << endl;

	delete[] yoyos;
	return 0;
}