#include "Card.h"
#include <iostream>
using namespace std;

Card::Card() {
	color = 'b';
	number = 0;
}

Card::Card(int n) 
{ 
	//n이 카드 앞면의 숫자
	number = n;
	//n이 짝수면 color는 b, n이 홀수면 color는 w
	if (n % 2 == 0) {
		color = 'b';
	}
	else {
		color = 'w';
	}
}

const int Card::front() const
{
	//getNumber()에 해당하는 getter함수
	return number;
}

const char Card::back() const
{
	//getColor()에 해당하는 getter함수
	return color;
}
