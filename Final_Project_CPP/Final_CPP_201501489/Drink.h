#ifndef DRINK_H
#define DRINK_H
#include <iostream>
#include <string>
using namespace std;
#include "Food.h"

class Drink : public Food
{
	bool no_ice = false;
public:
	Drink(double price, string name, double diff);
	void option() override;
	void print_option() override;
	virtual ~Drink();
};

#endif // !DRINK_H
