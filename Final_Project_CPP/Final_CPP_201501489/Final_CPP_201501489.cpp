// 201501489 최영진 기말대체 과제
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "Manager.h"


int main() {
	Manager m;
	ifstream menu("menu.txt");
	m.load_menu(menu);
	menu.close();
	while (1) {
		m.order();
		m.receipt();
		char c;
		cout << "New Order? (y or n) ";
		cin >> c;
		if (c == 'n')
			return 0;
		m.clear_cart();
	}
}