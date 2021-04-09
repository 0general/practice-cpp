#include "Food.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

ostream& operator<<(ostream& os, Food& f)
{
	os << left;
	os.fill(' ');
	os.width(18);
	os << f.get_name();
	if (f.size == Size::LARGE) {
		os.fill(' ');
		os.width(12);
		os << "L";
	}
	else if (f.size == Size::MEDIUM) {
		os.fill(' ');
		os.width(12);
		os << "M";
	}
	else {
		os.fill(' ');
		os.width(12);
		os << "S";
	}
	os << "\\" << f.get_price() << endl;
	f.print_option();
	return os;
}

Food::Food(const double price, const string name,const double diff) : base_price(price), name(name), size_diff(diff)
{
}

void Food::set_size(int i)
{
	size = Size(i);
}

double Food::get_price() const
{
	double price;
	if (size == Size::SMALL)
	{
		price = base_price - size_diff;
	}
	else if (size == Size::MEDIUM)
	{
		price = base_price;
	}
	else
	{
		price = base_price + size_diff;
	}
	return price;
}

string Food::get_name() const
{
	return name;
}


Food::~Food()
{
}


