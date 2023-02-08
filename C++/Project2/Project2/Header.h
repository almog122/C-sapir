#pragma once
#include <iostream>
using namespace std;
class CreateDestroy {
public:
	CreateDestroy() { cout << "create "; }
	~CreateDestroy() { cout << "destroy "; }
};
