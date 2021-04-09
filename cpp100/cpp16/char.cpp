#include <iostream>
using namespace std;

int main()
{
	char ch1 = 'c';
	char ch2 = 200; // char 범위 -127 ~ +127

	unsigned char ch3 = 'c';
	unsigned char ch4 = 200; // unsigned char 범위 0 ~ +255 
	//unsigned -> 기호가 없어, 양수만 저장 

	/*
	아스키 코드 : 컴퓨터 문자 값
	숫자 - 48~57
	대문자 - 65 ~90
	소문자 - 97 ~ 122	
	*/

	printf("char ch1 = %c, %d\n", ch1, ch1); // c = 아스키 코드 99
	printf("char ch2 = %c, %d\n", ch2, ch2); // 변수 범위 초과 값 -> 보수 취함 (128-200=-72) -> 최소범위 -127에서 72만큼 증가한 -56 출력
	printf("char ch3 = %c, %d\n", ch3, ch3); // 정상 범위
	printf("char ch4 = %c, %d\n", ch4, ch4); // 숫자만 정상 출력, 200에 해당하는 아스키 값은 없으므로 ?출력
}