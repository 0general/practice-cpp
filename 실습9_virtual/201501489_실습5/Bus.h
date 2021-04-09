#ifndef BUS_H
#define BUS_H

#include <iostream>
using namespace std;
#include "Transport.h"

class Bus : public Transport
{
protected:
	int number;
public:
	Bus(int number, int base_fare=1200);
	virtual void print();
	virtual ~Bus();
};

#endif // !BUS_H





