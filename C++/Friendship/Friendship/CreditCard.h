#pragma once
class House;
class CreditCard
{
public:
	CreditCard();
	~CreditCard();
	void pay(House& h);
};

