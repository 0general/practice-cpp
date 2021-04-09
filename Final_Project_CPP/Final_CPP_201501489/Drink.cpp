#include "Drink.h"
#include <iostream>
#include <string>
using namespace std;

Drink::Drink(double price, string name, double diff) : Food(price, name, diff)
{
}

void Drink::option()
{
	string ic; // ice no check
	cout << "     + Do you want drink no ice?(y or n)";
	cin >> ic;
	if (ic == "y") {
		no_ice = true;
	}
	else if (ic == "n") {
		no_ice = false;
	}
	cin.ignore();
}

void Drink::print_option()
{
	if (no_ice == true) {
		cout << "    + No Ice" << endl;
	}
}

Drink::~Drink()
{
}
