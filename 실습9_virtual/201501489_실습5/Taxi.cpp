#include "Taxi.h"



void Taxi::print()
{
	cout << "Car owner = " << owner << endl;
	cout << "Base fare = " << base_fare << endl;
	cout << "9km fare = " << cal_fare(9) << endl;
}

Taxi::~Taxi()
{
}
