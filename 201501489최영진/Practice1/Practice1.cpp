// Practice1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//201501489 최영진

#include "Time.h"
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	cout << "시간을 입력하세요 : ";
	char timein[9];
	cin >> timein;
	int t = 0;
	cout << "몇 초의 시간을 증가시키겠습니까? ";
	cin >> t;

	char* context = NULL;
	if (strlen(timein) == 8) {
		int h = atoi(strtok_s(timein, ":", &context));
		int m = atoi(strtok_s(NULL, ":", &context));
		int s = atoi(strtok_s(NULL, "\n", &context));
		Time Time(h, m, s);
		for (int i = 0; i < t; i++) {
			Time.tick();
		}
		Time.print();
	}
	else if (strlen(timein) == 5) {
		int h = atoi(strtok_s(timein, ":", &context));
		int m = atoi(strtok_s(NULL, "\n", &context));
		Time Time(h, m);
		for (int i = 0; i < t; i++) {
			Time.tick();
		}
		Time.print();
	}
	else if (strlen(timein) == 2) {
		int h = atoi(strtok_s(timein, "\n", &context));
		Time Time(h);
		for (int i = 0; i < t; i++) {
			Time.tick();
		}
		Time.print();
	}
	else {
		Time Time;
		for (int i = 0; i < t; i++) {
			Time.tick();
		}
		Time.print();
	}
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
