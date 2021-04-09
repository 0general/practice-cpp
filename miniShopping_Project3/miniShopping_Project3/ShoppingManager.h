#ifndef SHOPPINGMANAGER_H
#define SHOPPINGMANAGER_H
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
#include "Product.h"


class ShoppingManager
{
private:
	vector<Product> productList;
public:
	ShoppingManager(const string fn);

	//In mainMenu
	void mainMenu();
	void managerMode();
	void customerMode();

	//In managerMenu
	void addProduct();
	void deleteProduct();
	void print(vector<Product> pList);

	//In customerMenu
	void search();
	void cartMode();
	vector<Product> addToCart(vector<Product> &cart);
	void calculate(const vector<Product> &cart);

};

#endif // !SHOPPINGMANAGER_H


