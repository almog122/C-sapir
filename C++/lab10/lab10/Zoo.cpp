#include "Pet.h"
#include "Dog.h"
void main() {
	Pet p; //������� ���� ���� ��� ���� ��� ����� ���� �� �� ����� ��� ���
	cout << p << endl;
	p.eat();
	p.sleep();
	Dog d1("Zoey", 4, true);
	cout << "----------------------------" << endl;
	cout << d1 << endl;
	d1.fetch_ball();
	d1.eat();
	d1.sleep();
	cout << "----------------------------" << endl;

	//!!!!!!!!!!!!!!!!!!!!!!!!!!!

	//Dog d1("charley" , 10 ,true)
	//Dog d2;
	//Dog d3 = d1 can also be Dog d3(d1) ���� ����� ���� ��� �����
	//d2 = d1 ���� ���� ���� ������ (������� =
	//����!!!!
	//������ �� ���� : ���� ����� ,������� ���� , ���� ��������
}
