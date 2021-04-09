#ifndef BURGER_H
#define BURGER_H
#include <iostream>
#include <string>
using namespace std;
#include "Food.h"

class Burger : public Food
{
	bool no_tomato = true;
public:
	Burger(double price, string name, double diff);
	void option() override;
	void print_option() override;
	virtual ~Burger();
};


#endif // !BURGER_H

