#include "WaterCompany.h"
#include "House.h"



WaterCompany::WaterCompany()
{
}


WaterCompany::~WaterCompany()
{
}

void WaterCompany::add_usage(House& h, float consumption) {

	h.water_consumption += consumption;
	h.debt += consumption * 10;

}
