// 201501489 최영진

#include <iostream>
#include <string>
#include "Vector3.h"
using namespace std;

int main() {
	Vector3 vec0(1, 1, 0), vec1(0, 0, 1), vec2(1, 0, 1), vec3(1, 1, 1);
	vec0.print();
	vec1.print();
	vec2.print();
	vec3.print();
	cout << "vec0 + vec3 ";
	(vec0 + vec3).print();
	cout << "vec1 - vec2 ";
	(vec1 - vec2).print();
	cout << "dist(vec0, vec3) " << vec0.distance(vec3) << endl;
	cout << boolalpha;
	cout << "vec0 == vec0 " << (vec0 == vec0) << endl;
	cout << "vec1 != vec2 " << (vec1 != vec2) << endl;
	cout << "vec1 < vec2 " << (vec1 < vec2) << endl;
	cout << "vec1 <= vec2 " << (vec1 <= vec2) << endl;
	cout << "vec3 > vec2 " << (vec3 > vec2) << endl;
	cout << "vec3 >= vec3 " << (vec3 >= vec3) << endl;
	return 0;
}

