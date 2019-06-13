#pragma once
#include "vehicle.h"
class Motorcar :
	virtual public Vehicle
{
protected:
	int seatNum;
public:
	Motorcar();
	Motorcar(double ms,double w,int);
	~Motorcar();
	void run();
	void stop();
};