#include "Apartment.h"
#include "GardenApartment.h"
#include "RoofApartment.h"

int main() {

	Address address_aprt1;
	Address address_aprt2;
	Address address_garden_aprt1("Bengoreon" ,5 , 11);
	Address address_garden_aprt2("Mazata" , 6, 8);
	Address address_roof_aprt1("Mazot" , 11, 30);
	Address address_roof_aprt2("Lariva", 21 , 4);
	
	Apartment aprt1(address_aprt1 ,9, 6, 10);
	Apartment aprt2(address_aprt2, 4, 5, 8);
	 
	GardenApartment garden_aprt1(address_garden_aprt2, 7, 10, 9, 24);
	GardenApartment garden_aprt2(address_garden_aprt2 , 5, 7, 2, 46);
	
	RoofApartment roof_aprt1(address_roof_aprt1, 5, 8, 2 ,"Leblnc", 23);
	RoofApartment roof_aprt2(address_roof_aprt2, 5, 11, 4, "Legrench", 40);

	bool flag;

	//Address operators

	flag = address_aprt1 == address_aprt2; 
	cout << "address of apartment1 == address of apartment2 ? : " << flag << endl;

	cout << "\n";
	
	flag = address_aprt1 != address_garden_aprt1; 
	cout << "address of apartment1 != address of garden apartment1 ? : " << flag << endl;

	cout << "\n";

	Address new_address = (address_roof_aprt1 + address_garden_aprt1); 
	cout << "The new address : " << endl;
	cout << new_address << endl;

	//Apartment operators

	flag = aprt1 == aprt2;
	cout << "apartment1 == apartment2 ? : " << flag << endl;

	cout << "\n";

	flag = aprt1 != aprt2;
	cout << "apartment1 != apartment2 ? : " << flag << endl;

	cout << "\n";

	cout << "before the +prefix of apartment1 " << ++aprt1 << endl;
	
	cout << "after the +prefix of apartment1 " << aprt1.get_num_rooms() << endl;

	cout << "\n";

	flag = aprt1 > aprt2;
	cout << "apartment1 > apartment2 ? : " << flag << endl;

	//GardenApartment

	flag = garden_aprt1 == garden_aprt2;
	cout << "garden apartment1 == garden apartment2 ? : " << flag << endl;

	cout << "\n";

	flag = garden_aprt1 != garden_aprt2;
	cout << "garden apartment1 != garden apartment2 ? : " << flag << endl;

	cout << "\n";

	cout << "before the +prefix of garden apartment1 " << ++garden_aprt1 << endl;
	
	cout << "after the +prefix of garden apartment1 " << garden_aprt1.get_num_rooms() << endl;

	cout << "\n";

	flag = garden_aprt1 > garden_aprt2;
	cout << "garden apartment1 > garden apartment2 ? : " << flag << endl;


	//RoofApartment

	flag = roof_aprt1 == roof_aprt2;
	cout << "garden apartment1 == garden apartment2 ? : " << flag << endl;

	cout << "\n";

	flag = roof_aprt1 != roof_aprt2;
	cout << "garden apartment1 != garden apartment2 ? : " << flag << endl;

	cout << "\n";

	cout << "before the +prefix of garden apartment1 " << ++roof_aprt1 << endl;
	
	cout << "after the +prefix of garden apartment1 " << roof_aprt1.get_num_rooms() << endl;

	cout << "\n";

	flag = roof_aprt1 > roof_aprt2;
	cout << "garden apartment1 > garden apartment2 ? : " << flag << endl;

	return 0;
}