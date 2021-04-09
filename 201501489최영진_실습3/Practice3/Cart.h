#ifndef CART_H
#define CART_H

#include <string>
using namespace std;
#include "Food.h"

class Cart
{
	Food *content;
	int n;
public:
	Cart(int n);
	Cart(const Cart&);
	~Cart();
	int getN();
	void input();
	void print();
	void updateQuantity();
	double compute();
};

#endif // !CART_H



