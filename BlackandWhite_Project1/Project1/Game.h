#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include <iostream>
using namespace std;

class Game
{
	Player computer;
	Player user;
	int round;
	bool comp_first;
	int user_wins;
	int comp_wins;
public:
	Game();
	void play();
	void advanceRound();
};

#endif // !GAME_H



