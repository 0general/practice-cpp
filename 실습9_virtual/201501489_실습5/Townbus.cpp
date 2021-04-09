#include "Townbus.h"


Townbus::Townbus(int number, string town_name) : Bus(number)
{
	this->number = number;
	this->town_name = town_name;
	base_fare = 900;
}

void Townbus::print()
{
	cout << town_name << number << endl;
}

Townbus::~Townbus()
{
}
