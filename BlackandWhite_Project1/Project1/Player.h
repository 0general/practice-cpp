#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "Card.h"
using namespace std;

class Player
{
private:
	Card* deck;
	int num_card;
	int history[9];
public:
	Player();
	void randomShuffle();
	Card choose(int a);
	int search(int b);
	const void printFront() const;
	const void printBack()const;
	const void printHistory() const;
	~Player();
};

#endif // !PLAYER_H


