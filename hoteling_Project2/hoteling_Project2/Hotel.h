#ifndef HOTEL_H
#define HOTEL_H
#include <fstream>
using namespace std;
#include "Room.h"

enum class RoomType
{
	STANDARD, SUITE, ROYAL
};
class Hotel
{
private:
	Room** rooms;
	int time;
	int size;
	int totalIncome = 0;
	RoomType* roomTypes;
public:
	Hotel(ifstream& setting);
	void open(ifstream& fin);
	~Hotel();
private:
	int room_to_i(const int rn);
};

#endif // !HOTEL_H