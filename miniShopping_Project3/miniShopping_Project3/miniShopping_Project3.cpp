// 201501489 최영진
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
#include "ShoppingManager.h"

int main(void)
{
	ShoppingManager sm("product.txt");
	sm.mainMenu();
	return 0;
}
