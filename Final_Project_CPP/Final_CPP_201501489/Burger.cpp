#include "Burger.h"


Burger::Burger(double price, string name, double diff) : Food(price, name, diff)
{
}

void Burger::option()
{
	string tc; // no tomato check
	cout << "     + Will you exclude tomato?(y or n)";
	cin >> tc;
	if (tc == "y") {
		no_tomato = false;
	}
	else if (tc == "n") {
		no_tomato = true;
	}
	cin.ignore();
}

void Burger::print_option()
{
	if (no_tomato == false) {
		cout << "    Tomatoes are excluded" << endl;
	}
}

Burger::~Burger()
{
}
