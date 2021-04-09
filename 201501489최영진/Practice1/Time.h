#ifndef TIME_H
#define TIME_H

class Time {
	int hour, minute, second;

public:
	Time();
	Time(int h);
	Time(int h, int m);
	Time(int h, int m, int s);
	void print();
	void tick();
};

#endif // !TIME_H
#pragma once