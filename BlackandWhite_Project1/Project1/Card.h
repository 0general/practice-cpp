#ifndef CARD_H
#define CARD_H

#include <iostream>
using namespace std;

class Card
{
private:
	char color;
	int number;
public:
	Card();
	Card(int n);
	const int front() const;
	const char back() const;
};

#endif // !CARD_H


