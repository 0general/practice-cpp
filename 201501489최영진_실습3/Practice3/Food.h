#ifndef FOOD_H
#define FOOD_H

#include <string>
using namespace std;

class Food
{
	string name;
	int quantity;
	double price;
public:
	Food();
	Food(string name, int quantity, double price);
	string getName();
	int getQuantity();
	double getPrice();
	void setQuantity(int quantity);
	void setName(string name);
	void setPrice(double price);
	double getTotal();
};
#endif

