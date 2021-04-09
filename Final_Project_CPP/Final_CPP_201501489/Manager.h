#ifndef MANAGER_H
#define MANAGER_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;
#include "Food.h"
#include "Burger.h"
#include "Side.h"
#include "Drink.h"

class Manager
{
	vector <Food*> cart;
	vector<Burger> burger_list;
	vector<Side> side_list;
	vector<Drink> drink_list;
public:
	Manager();
	void load_menu(ifstream& menu);
	void order();
	void receipt();
	void clear_cart();
	template <typename V> void print_vector(vector <V>& v); //함수템플릿으로 구현
	virtual ~Manager();
};

#endif // !MANAGER_H

template<typename V>
inline void Manager::print_vector(vector<V>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << "    " << i+1 << " : " << v[i].get_name() << endl; 
	}
}
