#pragma once
class WaterCompany
{
public:
	WaterCompany();
	~WaterCompany();
	void add_usage(House& h, float consumption = 100);
};

