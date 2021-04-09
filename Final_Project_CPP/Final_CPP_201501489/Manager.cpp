#include "Manager.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

Manager::Manager()
{
}

void Manager::load_menu(ifstream& menu)
{
	string line;
	string fd_line;
	string type;
	string name;
	string pc_line;
	string price;
	string diff;
	int k;
	int select = 0;
	while (getline(menu, line)) {
		k = line.find(";");
		fd_line = line.substr(0, k);
		pc_line = line.substr(k + 2);
		type = fd_line.substr(0, 1);
		name = fd_line.substr(2);
		k = pc_line.find(" ");
		price = pc_line.substr(0, k);
		diff = pc_line.substr(k + 1);
		if (type == "b") { select = 0; }
		else if (type == "s") { select = 1; }
		else if (type == "d") { select = 2; }
		switch (select)
		{
		case 0: {
			//Burger
			Burger burger((double)stod(price), name, (double)stod(diff));
			burger_list.push_back(burger);
			break; 
		}
		case 1: {
			//Side
			Side side((double)stod(price), name, (double)stod(diff));
			side_list.push_back(side);
			break;
		}
		case 2: {
			//Drink
			Drink drink((double)stod(price), name, (double)stod(diff));
			drink_list.push_back(drink);
			break;
		}
		}
	}
}

void Manager::order()
{
	int cn; // 메뉴 선택용
	int sub; // 서브 메뉴 선택용
	int ss; // 사이즈 선택용

	cout << "Welcome to my Burger shop!!! " << endl;
	while (1) {
		cout << "Choose the menu you want to see. " << endl;
		cout << "0 : to payment \n1 : burgers \n2 : sides \n3 : drinks \nChoose num : ";
		cin >> cn;
		switch (cn)
		{
		case 0:
			return;
		case 1: {
			cout << " -- Burger Menu -- \n";
			print_vector(burger_list);
			cout << "    Choose num : ";
			cin >> sub;
			Food* bg = new Burger(burger_list[sub-1]);
			cout << "    What size do you want? \n    0: cancel order    1: small    2: medium    3: large \n";
			cout << "    Choose num : ";
			cin >> ss;
			switch (ss)
			{
			case 0:
				break;
			case 1:
				bg->set_size(0);
				bg->option();
				cart.push_back(bg);
				break;
			case 2:
				bg->set_size(1);
				bg->option();
				cart.push_back(bg);
				break;
			case 3:
				bg->set_size(2);
				bg->option();
				cart.push_back(bg);
				break;
			}
			break;
		}
		case 2: {
			cout << " -- Side Menu -- \n";
			print_vector(side_list);
			cout << "    Choose num : ";
			cin >> sub;
			Food* sd = new Side(side_list[sub-1]);
			cout << "    What size do you want? \n    0: cancel order    1: small    2: medium    3: large \n";
			cout << "    Choose num : ";
			cin >> ss;
			switch (ss)
			{
			case 0:
				break;
			case 1:
				sd->set_size(0);
				sd->option();
				cart.push_back(sd);
				break;
			case 2:
				sd->set_size(1);
				sd->option();
				cart.push_back(sd);
				break;
			case 3:
				sd->set_size(2);
				sd->option();
				cart.push_back(sd);
				break;
			}
			break;
		}
		case 3: {
			cout << " -- Drink Menu -- \n";
			print_vector(drink_list);
			cout << "    Choose num : ";
			cin >> sub;
			Food* dr = new Drink(drink_list[sub-1]);
			cout << "    What size do you want? \n    0: cancel order    1: small    2: medium    3: large \n";
			cout << "    Choose num : ";
			cin >> ss;
			switch (ss)
			{
			case 0:
				break;
			case 1:
				dr->set_size(0);
				dr->option();
				cart.push_back(dr);
				break;
			case 2:
				dr->set_size(1);
				dr->option();
				cart.push_back(dr);
				break;
			case 3:
				dr->set_size(2);
				dr->option();
				cart.push_back(dr);
				break;
			}
			break;
		}
		default:
			cout << "You've entered something wrong. \n";
			break;
		}
	}
}

void Manager::receipt()
{
	double total = 0;
	if (cart.empty() == true) {
		cout << "No item is in the cart!" << endl;
	}
	else {
		cout << "\n \n \n               == Order list == \n \n";
		cout << "        description            price \n";
		cout << "----------------------------------------------" << endl;
		for (int i = 0; i < cart.size(); i++) {
			cout << *cart[i];
			total += cart[i]->get_price();
		}
		cout << "----------------------------------------------" << endl;
		cout.fill(' ');
		cout.width(30);
		cout << right << "Total :" << "\\" << total <<endl;
	}
}

void Manager::clear_cart()
{
	cart.clear();
}

Manager::~Manager()
{ 
	for (vector<Food*>::iterator it = cart.begin(); it!= cart.end(); )
	{
		delete (*it);
		it = cart.erase(it);
	}
	cart.clear(); // 혹시 모르니까 한번 더.
	burger_list.clear();
	side_list.clear();
	drink_list.clear();
}
