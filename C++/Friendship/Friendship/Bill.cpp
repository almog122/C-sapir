#include "House.h"
#include "CreditCard.h"
#include "WaterCompany.h"

int main() {

	House h1;
	House h2(0,55.5);
	House h3(12.4,300);

	WaterCompany w;

	w.add_usage(h1);
	w.add_usage(h2);
	w.add_usage(h3);

	CreditCard c;
	c.pay(h1);
	c.pay(h2);
	c.pay(h3);

	h1.print();
	h2.print();
	h3.print();

	return 0;
}