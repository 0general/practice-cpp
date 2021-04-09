#include "Side.h"
#include <iostream>
#include <string>
using namespace std;

Side::Side(double price, string name, double diff) : Food(price, name, diff)
{
}

void Side::option()
{
	string mc; // mustard check
	cout << "     + Is ketchup sauce ok?(y or n)";
	cin >> mc;
	if (mc == "y") {
		mustard = false;
	}
	else if (mc == "n") {
		mustard = true;
	}
	cin.ignore();
}

void Side::print_option()
{
	if (mustard == false) {
		cout << "    + ketchup sauce" << endl;
	}
	else {
		cout << "    + mustard sauce" << endl;
	}
}

Side::~Side()
{
}
