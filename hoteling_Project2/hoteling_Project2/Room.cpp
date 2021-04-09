#include "Room.h"
#include <string>
#include <iostream>
using namespace std;
#include <fstream>

Room::Room(int rm)
{
	roomNumber = rm;
}

void Room::checkin(string n, int p, int b)
{	
	name = n;
	people = p;
	addPeople = p - 1;
	breakfast = b;
	state = State::OCCUPIED;	
}

void Room::checkout()
{
	name = "";
	people = 0;
	addPeople = 0;
	breakfast = 0;
	state = State::PREPARING;
	remainTime = 4;
}

double Room::roomService(int rs)
{
	service += rs;
	return service;
}

void Room::prepare()
{
	if (state == State::PREPARING) {
		remainTime -= 1;
		if (remainTime == 0) {
			state = State::EMPTY;
		}
	}
}

string Room::getName()
{
	return name;
}

int Room::getRoomNumber()
{
	return roomNumber;
}

int Room::getRemainTime()
{
	return remainTime;
}

State Room::getState()
{
	return state;
}

Room::~Room()
{
}

ofstream& operator<<(ofstream& fout, const Room& r)
{
	if (r.state == State::EMPTY) {
		fout << "Room " << r.roomNumber << " Empty ";
	}
	if (r.state == State::OCCUPIED) {
		if (r.people > 1) {
			fout << "Room " << r.roomNumber << " Occupied(" << r.name << " and " << r.addPeople << " others) ";
			;
		}
		else {
			fout << "Room " << r.roomNumber << " Occupied(" << r.name << " ";
			;
		}

	}
	if (r.state == State::PREPARING) {
		fout << "Room " << r.roomNumber << " Preparing(" <<r.remainTime<<"hours left) ";
	}

	return fout;
}
