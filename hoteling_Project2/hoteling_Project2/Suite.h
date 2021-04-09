#ifndef SUITE_H
#define SUITE_H
#include "Room.h"

class Suite : public Room
{
public:
	Suite(int rm);
	virtual double calculate() const override;
	~Suite() {};
};

#endif // !SUITE_H