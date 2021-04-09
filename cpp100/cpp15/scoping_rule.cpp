#include <iostream>
using namespace std;

int x = 10; //전역 변수 : 프로그램 어디서나 접근할 수 있다.

// 변수의 유효한 공간 : scope -> 유효 범위를 제한하여 사용하는 것을 스코핑 룰이라 한다. 

int Func1()
{
	int y = x + 10;  //함수 영역 내에 없는 x변수를 사용 -> 상위 범위의 외부 변수 x 참조
	return y; //정수 y 리턴
}

int Func2()
{
	int x = 100; //이 함수 영역 안에서 사용할 x변수 선언
	return x; //정수 x 리턴 -> 함수 영역 내에 x변수가 존재하므로 외부 변수는 사용하지 않는다. 
}

int main()
{
	cout << "y = " << Func1() << endl;
	cout << "x = " << Func2() << endl;
	cout << "x = " << x << endl;

	return 0;
}