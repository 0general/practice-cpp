#ifndef STANDARD_H
#define STANDARD_H
#include "Room.h"

class Standard : public Room
{
public:
	Standard(int rm);
	virtual double calculate() const override;
	~Standard() {};
};

#endif // !STANDARD_H