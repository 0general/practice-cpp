#ifndef PERSON_H
#define PERSON_H

#include <iostream>
using namespace std;

class Person
{
	string name;
	string id;
	double gpa;
public:
	Person();
	string getName();
	string getId();
	double getGpa();
	void set(string name, string id, double gpa);
};

#endif // !PERSON_H



