#pragma once
#include "vehicle.h"
class Bicycle :
	virtual public Vehicle
{
protected:
	double height;
public:
	Bicycle();
	Bicycle(double ms, double w, double h);
	~Bicycle();
	void run();
	void stop();
};

