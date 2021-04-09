#include "Hotel.h"
#include "Standard.h"
#include "Suite.h"
#include "Royal.h"
#include <string>
using namespace std;
#include <fstream>

ofstream& operator <<(ofstream& fout, const RoomType& rt) {
	if (rt == RoomType::STANDARD) {
		fout << "Standard ";
	}
	if (rt == RoomType::SUITE) {
		fout << "Suite ";
	}
	if (rt == RoomType::ROYAL) {
		fout << "Royal ";
	}
	return fout;
}

char t;
int rn;
int rs;

Hotel::Hotel(ifstream& setting)
{
	setting >> time >> size;
	roomTypes = new RoomType[size];
	rooms = new Room * [size];
	for (int i = 0; i < size; i++) {
		setting >> t >> rn;
		if (t == 's') {
			rooms[i] = new Standard(rn);
			roomTypes[i] = RoomType::STANDARD;
		}
		if (t == 'u') {
			rooms[i] = new Suite(rn);
			roomTypes[i] = RoomType::SUITE;
		}
		if (t == 'r') {
			rooms[i] = new Royal(rn);
			roomTypes[i] = RoomType::ROYAL;
		}
	}
}

void Hotel::open(ifstream& fin)
{
	ofstream fout("log.txt");
	fout << "Time: " << time << ":00" <<"\n";
	fout << "Hotel opened. \n" << "\n";

	while (!fin.eof()) {
		int j = 0;
		char choice = ' ';
		char t = ' ';
		string nm ="";
		int ap = 0;
		int bp = 0;
		fin >> choice;
		switch (choice) {
		case('i') :
			fin >> t >> nm >> ap >> bp;
			switch (t)
			{
			case('s'): {
				for (int k = 0; k <= size; k++) {
					if (roomTypes[k] == RoomType::STANDARD) {
						if (rooms[k]->getState() == State::EMPTY) {
							rooms[k]->checkin(nm, ap, bp);
							fout << roomTypes[k] << *rooms[k] << endl;
							break;
						}
						else {
							continue;
						}
					}
					if (k == size) {
						fout << "들어갈 수 있는 방이 없습니다. \n";
					}
				}
				break; }
			case('u'): {
				for (int k = 0; k <= size; k++) {
					if (roomTypes[k] == RoomType::SUITE) {
						if (rooms[k]->getState() == State::EMPTY) {
							rooms[k]->checkin(nm, ap, bp);
							fout << roomTypes[k] << *rooms[k] << endl;
							break;
						}
						else {
							continue;
						}
					}
					if (k == size) {
						fout << "들어갈 수 있는 방이 없습니다. \n";
					}
				}
				break; }
			case('r'): {
				for (int k = 0; k <= size; k++) {
					if (roomTypes[k] == RoomType::ROYAL) {
						if (rooms[k]->getState() == State::EMPTY) {
							rooms[k]->checkin(nm, ap, bp);
							fout << roomTypes[k] << *rooms[k] << endl;
							break;
						}
						else {
							continue;
						}
					}
					if (k == size) {
						fout << "들어갈 수 있는 방이 없습니다. \n";
					}
				}
				break;
			}

			}
			break;
		case('o'): {
			fin >> rn;
			int o = room_to_i(rn);
			fout << roomTypes[o] << *rooms[o] << "checked out. \n";
			
			totalIncome += rooms[o]->calculate();
			rooms[o]->checkout();
			fout << "$" << totalIncome << " added to the total income \n";
			break; }
		case('p'): {
			for (int i = 0; i < size; i++) {
				if (rooms[i]->getState() == State::OCCUPIED) {
					fout << roomTypes[i] << *rooms[i] << " $" << rooms[i]->calculate() << " expected \n";
				}
				else {
					fout << roomTypes[i] << *rooms[i] << endl;
				}

			}
			fout << endl;
			break; }
		case('a'): {
			if (time != 23) {
				time += 1;
			}
			else {
				time = 0;
			}
			fout << "Time: " << time << ":00" << "\n";
			for (int i = 0; i < size; i++) {
				rooms[i]->prepare();
			}
			fout << endl;
			break; }
		case('s'): {
			fin >> rn >> rs;
			int s = room_to_i(rn);
			rooms[s]->roomService(rs);
			fout << roomTypes[s] << *rooms[s] << " called rooom service($" << rs << ")\n";
			fout << endl;
			break; }
		case('q'):
			fout << "Hotel closed \n";
			fout << "Total income is $"<<totalIncome << ". \n";
			return;
		}

	}

}

Hotel::~Hotel()
{
}

int Hotel::room_to_i(const int rn)
{
	for (int i = 0; i < size; i++) {
		if (rooms[i]->getRoomNumber() == rn)
			return i;
	}
}

