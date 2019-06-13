#include "Bicycle.h"
#include <iostream>
using namespace std;


Bicycle::Bicycle()
{
}

Bicycle::Bicycle(double ms, double w, double h) :Vehicle(ms, w), height(h)
{
}


Bicycle::~Bicycle()
{
}

void Bicycle::run()
{
	cout << "Bicycle is running." << endl;
}

void Bicycle::stop()
{

	cout << "Bicycle stopped." << endl;
}
