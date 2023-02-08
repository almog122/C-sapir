#include "CreditCard.h"



CreditCard::CreditCard()
{
}


CreditCard::~CreditCard()
{
}

void CreditCard::pay(House& h) {
	h.debt = 0;
}