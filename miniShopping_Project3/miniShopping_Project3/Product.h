#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Product
{
private:
	string name;
	int price;
	int stock;
public:
	Product(string n, int p, int s = 100);
	string getName() const;
	int getStock() const;
	int getPrice() const;
	void setStock(int su);
	void setCartStock(int su);
	friend istream& operator>>(istream& ins, Product& p);
	friend ostream& operator<<(ostream& stream, const Product& p);
};

#endif // !PRODUCT_H



