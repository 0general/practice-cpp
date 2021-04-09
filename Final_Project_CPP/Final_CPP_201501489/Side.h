#ifndef SIDE_H
#define SIDE_H
#include <iostream>
#include <string>
using namespace std;
#include "Food.h"

class Side : public Food
{
	bool mustard = false;
public:
	Side(double price, string name, double diff);
	void option() override;
	void print_option() override;
	virtual ~Side();
};

#endif // !SIDE_H


