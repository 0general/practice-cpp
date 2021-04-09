#ifndef PERSONMANEGER_H
#define PERSONMANEGER_H

#include "Person.h"

class PersonManager
{
	Person *p;
	int size;
public :
	PersonManager(int n);
	~PersonManager();
	void input();
	void show();
	void search();
	void sort();
};

#endif
