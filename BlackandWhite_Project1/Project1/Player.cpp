#include "Player.h"
#include <cstdlib>
#include <iostream>
using namespace std;

Player::Player()
{
	deck = new Card[9]{ Card(0),Card(1),Card(2),Card(3),Card(4),Card(5),Card(6),Card(7),Card(8) };
	num_card = 9;
	fill_n(history, 9, -1);
}

void Player::randomShuffle()
{
	int nansu = 0;
	Card change;
	for (int i = 0; i < 9; i++) {		
		change = deck[i];
		nansu = rand() % 9;
		deck[i] = deck[nansu];
		deck[nansu] = change;
	}
}

Card Player::choose(int a) //a는 배열의 인덱스 
{
	Card ans;
	ans = deck[a];
	for (int i = a; i < num_card - 1; i++) {
		deck[i] = deck[i + 1];
	}
	history[9 - num_card] = ans.front();
	num_card -= 1;
	Card* p = new Card[num_card];
	for (int j = 0; j < num_card; j++) {
		p[j] = deck[j];
	}
	delete [] deck;
	deck = p;
	return ans;
}

int Player::search(int b) //b는 카드의 숫자 front값, user만 사용하는 함수
{
	for (int i = 0; i < num_card; i++) {
		if (deck[i].front() == b) {
			return i;
		}
		if (i == num_card - 1) {
			if (deck[i].front() != b) {
				cout << "No " << b << " in deck!!" << endl;
				return -1;  // 다시 search할 매개변수 입력받도록 
			}
		}
	}
}

const void Player::printFront() const
{
	for (int i = 0; i < num_card; i++) {
		cout << "  _  " ;
	}
	cout << endl;
	for (int i = 0; i < num_card; i++) {
		cout << " |" << deck[i].front() << "| ";
	}
	cout << endl;
	for (int i = 0; i < num_card; i++) {
		cout << "  -  " ;
	}
	cout << endl;
}

const void Player::printBack() const
{
	for (int i = 0; i < num_card; i++) {
		cout << "  _  " ;
	}
	cout << endl;
	for (int i = 0; i < num_card; i++) {
		cout << " |" << deck[i].back() << "| ";
	}
	cout << endl;
	for (int i = 0; i < num_card; i++) {
		cout << "  -  " ;
	}
	cout << endl;
}

const void Player::printHistory() const
{
	for (int i = 0; i < 9; i++) {
		cout << history[i] << " ";
	}
	cout << endl;
}

Player::~Player()
{
	if (deck) {
		delete[] deck;
	}
}
