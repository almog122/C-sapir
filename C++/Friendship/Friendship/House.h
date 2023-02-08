#pragma once
#include <iostream>
#include "CreditCard.h"
using namespace std;

class House
{
private:
	float water_consumption;
	int debt;
	friend class WaterCompany;
	friend void CreditCard::pay(House& h);
public:
	House(int water_consumption = 0,int debt = 0);
	void print();
};

