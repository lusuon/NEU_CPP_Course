#include "Motorcar.h"
#include <iostream>
using namespace std;


Motorcar::Motorcar()
{
}

Motorcar::Motorcar(double ms, double w, int sn):Vehicle(ms,w),seatNum(sn)
{
	cout << "A motorCar created." << endl;
}


Motorcar::~Motorcar()
{
}

void Motorcar::run()
{
	cout << "Motorcar stopped." << endl;
}

void Motorcar::stop()
{
	cout << "Motorcar stopped." << endl;
}
