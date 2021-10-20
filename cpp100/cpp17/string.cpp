#include <iostream>
#include <string>
using namespace std;

int main() {
	string my_country = "korea";
	string my_jop = "developer";

	cout << "Country : " << my_country << endl;
	cout << "Job : " << my_jop << endl;

	string my_info = my_country + ", " + my_jop;

	cout << "My Info : " << my_info << endl;

	return 0;
}