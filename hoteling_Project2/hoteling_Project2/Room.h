#ifndef ROOM_H
#define ROOM_H
#include <fstream>
#include <string>
using namespace std;

enum class State
{
	EMPTY, PREPARING, OCCUPIED
};


class Room
{
private:
	string name="";
	int roomNumber;
	int remainTime=0;
protected:
	double fee = 0;
	int people = 0;
	int addPeople = 0;
	int addFeePerPerson = 0;
	int breakfast = 0;
	static const int breakfastFee = 30;
	double service = 0;
	State state = State::EMPTY;
public:
	Room(int rm);
	virtual double calculate() const = 0;
	void checkin(string n, int p, int b = 0);
	void checkout();
	virtual double roomService(int rs);
	void prepare();
	string getName();
	int getRoomNumber();
	int getRemainTime();
	State getState();
	friend ofstream& operator << (ofstream& fout, const Room& r);
	virtual ~Room();

};
#endif // !ROOM_H