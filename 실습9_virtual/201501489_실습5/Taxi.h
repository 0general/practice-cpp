#ifndef TAXI_H
#define TAXI_H

#include <iostream>
using namespace std;
#include "Transport.h"
#include <string>

class Taxi : public Transport
{
	string owner;
public:
	Taxi(string owner) : Transport(3800, 750, 2.0), owner(owner) {};
	Taxi(int base_fare, int perkm, double basekm, string owner) : Transport(base_fare, perkm, basekm), owner(owner){};
	virtual void print();
	virtual ~Taxi();
};


#endif // !TAXI_H

