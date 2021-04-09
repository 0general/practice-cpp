#include "Standard.h"
#include <iostream>
using namespace std;
#include <fstream>

Standard::Standard(int rm) : Room(rm)
{
	fee = 100;
	addFeePerPerson = 30;
}

double Standard::calculate() const
{
	return fee
		+ ((people > 2) ? addFeePerPerson * (people - 2) : 0)
		+ breakfast * breakfastFee;
}
