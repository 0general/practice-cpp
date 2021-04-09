#include "Suite.h"
#include <iostream>
using namespace std;
#include <fstream>

Suite::Suite(int rm) : Room(rm)
{
	fee = 300;
	addFeePerPerson = 40;
}

double Suite::calculate() const
{
	return fee
		+ ((people > 2) ? addFeePerPerson * (people - 2) : 0)
		+ ((breakfast > 2) ? (breakfast - 2) * breakfastFee : 0);
}
