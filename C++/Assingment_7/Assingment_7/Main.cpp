#include "Button.h"
using namespace std;

int main() {
	List<Button> my_list;
	my_list.insert_at_back(Button("Red", 3, 5.5f));
	my_list.insert_at_front(Button("Blue", 5, 15.5f));
	my_list.insert_at_back(Button("Yellow", 4, 3.3f));
	my_list.insert_at_back(Button("Green", 2, 1.3f));
	my_list.insert_at_front(Button("Gold", 2, 0.6f));
	my_list.print();
	cout << "--------------------------" << endl;
	cout << "-------SORT-------" << endl;

	my_list.sort();
	my_list.print();
	cout << "--------------------------" << endl;
	int location = my_list.get_location(Button("Yellow", 4, 3.3f));
	cout << "The node in location " << location << " is " << endl;
	my_list.print_location(location);
	cout << "--------------------------" << endl;
	location = my_list.get_location(Button("Gold", 4, 3.3f));
	cout << "The node in location " << location << " is " << endl;
	my_list.print_location(location);
	cout << "--------------------------" << endl;

	return 0;
}
