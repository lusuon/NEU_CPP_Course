#include "Vehicle.h"
#include <iostream>
using namespace std;


Vehicle::Vehicle()
{
}

Vehicle::Vehicle(double ms, double w) :maxSpeed(ms), weight(w)
{
}


Vehicle::~Vehicle()
{
}

void Vehicle::run()
{
	cout << "Vehicle is running." << endl;
}

void Vehicle::stop()
{
	cout << "Vehicle stopped." << endl;
}

void Vehicle::showDetails()
{
	cout << "The vehicle's max spped is: " << maxSpeed << " ,weight is: " << weight << endl;
}

