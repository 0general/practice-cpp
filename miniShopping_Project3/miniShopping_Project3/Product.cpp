#include "Product.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

Product::Product(string n, int p, int s) : name(n),price(p),stock(s) {}

string Product::getName() const
{
	return name;
}

int Product::getStock() const
{
	return stock;
}

int Product::getPrice() const
{
	return price;
}

void Product::setStock(int su)
{
	stock -= su;
}

void Product::setCartStock(int su)
{
	stock += su;
}


istream& operator>>(istream& ins, Product& p)
{
	cout << "상품 이름 입력 : ";
	ins.ignore();
	getline(ins, p.name);	
	if (p.name != "no") {
		cout << "상품 가격 입력 : ";
		ins >> p.price;
	}
	else {
		cout << "새로운 상품 추가 종료." << endl;
	}
	return ins;
}

ostream& operator<<(ostream& stream, const Product& p)
{
	// cout.setf(ios::left);
	stream << left << "상품명 : " << setw(20) << p.name;
	// cout.setf(ios::right);
	stream.fill(' ');
	stream << right << " 가격 : " << setw(12)<< p.price << "원 ";
	stream << " 재고/수량 : " << setw(4)<<p.stock << "개" << endl;

	return stream;
}
