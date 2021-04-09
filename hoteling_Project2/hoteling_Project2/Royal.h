#ifndef ROYAL_H
#define ROYAL_H
#include "Room.h"

class Royal : public Room
{
public:
	Royal(int rm);
	virtual double calculate() const override;
	virtual double roomService(int rs);
	~Royal() {};
};

#endif // !ROYAL_H