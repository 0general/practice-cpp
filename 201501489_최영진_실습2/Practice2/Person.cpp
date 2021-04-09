#include "Person.h"
#include <iostream>
using namespace std;

Person::Person() {
	name = "";
	id = "";
	gpa = 0.0;
}
string Person::getName() { return name; }
string Person::getId() { return id; }
double Person::getGpa() { return gpa; }
void Person::set(string name, string id, double gpa) {
	this->name = name;
	this->id = id;
	this->gpa = gpa;
}