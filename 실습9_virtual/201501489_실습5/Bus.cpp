#include "Bus.h"



Bus::Bus(int number, int base_fare) : Transport(base_fare)
{
	this->number = number; 
	this->base_fare = base_fare;
}

void Bus::print()
{
	cout << number << endl;
}

Bus::~Bus()
{
}

