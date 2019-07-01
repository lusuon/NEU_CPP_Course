#include "Vehicle.h"
#include <iostream>
using namespace std;


Vehicle::Vehicle()
{
}

Vehicle::Vehicle(double ms, double w) :maxSpeed(ms), weight(w)
{
	cout << "A vehicle created." << endl;
}


Vehicle::~Vehicle()
{
}
