#include "Yoyo.h"
#define SIZE_PTR_ARR_YOYOS 6

int main() {

	Yoyo** yoyo;

	yoyo = new yoyo*[SIZE_PTR_ARR_YOYOS];

	assert(yoyo != 0); // check for memory allocation. need to add delete or destractor.

	//for (int i = 0; i < SIZE_PTR_ARR_YOYOS; i++) { maybe to put all inside for

	//	Yoyo* yoyo[i];

	//}


	//Monkey* mon_arr = new Monkey[SIZE];

	//mon_arr[0] = mon1;
	//mon_arr[1] = mon2;
	//mon_arr[2] = mon3;

	Yoyo* yoyo1; //static
	Yoyo* yoyo2;           //for competition
	Yoyo* yoyo3; //static
	Yoyo* yoyo4;		      //for competition
	Yoyo* yoyo5; //static
	Yoyo* yoyo6; //static

	//Yoyo* yoyo[0] = yoyo1; maybe more like this

	//yoyo2, yoyo4 are costum made and need to ask user for details. all the rest go to empty constractor.

	cout << "Enter manufacturer: " << endl;
	yoyo2.set_manufacturer("manufacturer name");
	cout << "Enter price for yoyo: " << endl;
	yoyo2.set_price();
	cout << "Enter length of yoyo: " << endl;
	yoyo2.set_length();
	cout << "Enter yes or no for competition: " << endl;
	yoyo2.set_is_competition();

	cout << "Enter manufacturer: " << endl;
	yoyo4.set_manufacturer("manufacturer name");
	cout << "Enter price for yoyo: " << endl;
	yoyo4.set_price();
	cout << "Enter length of yoyo: " << endl;
	yoyo4.set_length();
	cout << "Enter yes or no for competition: " << endl;
	yoyo4.set_is_competition();


	for (int i = 0; i < SIZE_PTR_ARR_YOYOS; i++) { //print all information about yoyos

		Yoyo* yoyo[i].print(); //print all information for every yoyo
		Yoyo* yoyo[i].set_is_competition ? print(); //if true for competition then print only their information.
	}

	//void SquatreMatrix::print() {
	//	for (int i = 0; i < size; i++) {
	//		for (int j = 0; j < size; j++) {
	//			cout << "[" << mat[i][j] << "]";
	//		}
	//		cout << endl;
	//	}
	//}


	// 7-10 in assignment (main)
	yoyo2.compete(yoyo4); //cometition that end with a tie (because both in competition level).
	yoyo2.compete(yoyo1);//cometition that end with a win (of yoyo2).

	cout << yoyo1.get_length << endl; //make length of yoyo shorter by half and print length before and after.
	yoyo1.reduce_length(2);
	cout << yoyo1.get_length << endl;

	cout << yoyo3.get_length << endl;//make length of yoyo shorter by 10 and print length before and after.
	yoyo3.reduce_length(10);
	cout << yoyo3.get_length << endl;

	return 0;
}