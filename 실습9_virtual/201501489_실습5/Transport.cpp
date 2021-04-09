#include "Transport.h"
#include <iostream>
using namespace std;
#include <cmath>


void Transport::print()
{
}


double Transport::cal_fare(double dist)
{
	if (dist < basekm) {
		return base_fare;
	}
	else {
		return (dist - basekm) * perkm + base_fare;
	}
}

Transport::~Transport()
{
}
