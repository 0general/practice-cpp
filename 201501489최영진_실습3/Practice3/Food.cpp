#include "Food.h"
#include <string>
#include <iostream>
using namespace std;

Food::Food() {
	quantity = 1;
	name = "";
	price = 0;
}
Food::Food(string name, int quantity, double price) {
	this->quantity = quantity;
	this->name = name;
	this->price = price;
}
string Food::getName() { return name; }
int Food::getQuantity() { return quantity; }
double Food::getPrice() { return price; }
void Food::setQuantity(int quantity) {
	this->quantity = quantity;
}
void Food::setName(string name) {
	this->name = name;
}
void Food::setPrice(double price) {
	this->price = price;
}
double Food::getTotal() {
	return quantity * price;
}
