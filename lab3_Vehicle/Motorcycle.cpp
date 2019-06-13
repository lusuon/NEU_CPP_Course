#include "Motorcycle.h"
#include <iostream>
using namespace std;


Motorcycle::Motorcycle()
{
}

Motorcycle::Motorcycle(double ms, double w, double h, int sn):Motorcar(ms,w,sn),Bicycle(ms,w,h)
{
}


Motorcycle::~Motorcycle()
{
}

void Motorcycle::run()
{
	cout << "Motorcycle is running." << endl;
}

void Motorcycle::stop()
{
	cout << "Motorcycle stopped." << endl;
}

