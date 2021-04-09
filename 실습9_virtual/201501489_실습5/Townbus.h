#ifndef TOWNBUS_H
#define TOWNBUS_H


#include <iostream>
using namespace std;
#include "Bus.h"
#include <string>

class Townbus : virtual public Bus
{
	string town_name;
public:
	Townbus(int number, string town_name);
	virtual void print();
	virtual ~Townbus();
};

#endif // !TOWNBUS_H
