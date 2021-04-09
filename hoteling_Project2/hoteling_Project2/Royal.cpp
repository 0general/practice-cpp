#include "Royal.h"
#include <iostream>
using namespace std;
#include <fstream>

Royal::Royal(int rm) : Room(rm)
{
	fee = 500;
	addFeePerPerson = 50;
}

double Royal::calculate() const
{
	return fee
		+ ((people > 2) ? addFeePerPerson * (people - 2) : 0)
		+ ((breakfast > 2) ? (breakfast - 2) * breakfastFee : 0)
		+ service;
}

double Royal::roomService(int rs)
{
	service += rs;
	return service;
}
