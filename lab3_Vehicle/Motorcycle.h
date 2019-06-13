#pragma once
#include "Bicycle.h"
#include "Motorcar.h"
class Motorcycle :
	virtual public Bicycle, virtual public Motorcar
{
public:
	Motorcycle();
	Motorcycle(double ms, double w, double h, int sn);
	~Motorcycle();
	void run();
	void stop();
};

