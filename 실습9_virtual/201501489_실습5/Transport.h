#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <iostream>
using namespace std;
#include <cmath>

class Transport
{
protected:
	int base_fare;
	int perkm;
	double basekm;

public:
	Transport(int new_basefare, int new_perkm=100, double new_basekm=10) : base_fare(new_basefare), perkm(new_perkm), basekm(new_basekm) {};
	virtual void print();
	double cal_fare(double dist = 0);
	virtual ~Transport();
};

#endif // !TRANSPORT_H




