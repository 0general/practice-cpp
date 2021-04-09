#include "Time.h"
#include <iostream>
using namespace std;

Time::Time() : Time(0, 0, 0){}
Time::Time(int h) : Time(h, 0, 0){}
Time::Time(int h, int m) : Time(h, m, 0) {}
Time::Time(int h, int m, int s) {
	hour = h, minute = m, second = s;
}

void Time::print() {
	cout << "증가 후 시각 : " << "(" << hour << ":" << minute << ":" << second << ")"<< endl;
}

void Time::tick() {
	second = second + 1;
	if (second == 60) {
		second = 0;
		minute = minute + 1;
	}
	if (minute == 60) {
		minute = 0;
		hour = hour + 1;
	}
	if (hour == 24) hour = 0;
}
