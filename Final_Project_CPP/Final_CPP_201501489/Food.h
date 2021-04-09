#ifndef FOOD_H
#define FOOD_H
#include <iostream>
#include <string>
using namespace std;

enum class Size
{
	SMALL, MEDIUM, LARGE
};

class Food
{
	double base_price;
	string name;
	double size_diff;
	Size size = Size(1);
public:
	Food(const double price,const string name,const double diff);
	void set_size(int i);
	double get_price() const;
	string get_name()const;
	virtual void option() = 0;
	virtual void print_option() = 0;
	virtual ~Food();

	friend ostream& operator<<(ostream& os, Food& f);
};

#endif // !FOOD_H
