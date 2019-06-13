#include "Bicycle.h"
#include "Vehicle.h"
#include "Motorcar.h"
#include "Motorcycle.h"
#include <iostream>
using namespace std;
void main() 
{
	Vehicle v = Vehicle(0, 0);
	Bicycle b = Bicycle(10,1,2);
	Motorcar mCar = Motorcar(20,5,4);
	Motorcycle mCycle = Motorcycle(30,10,2,2);

	Vehicle* p;

	p = &v;
	cout << "Base class Vehicle:" << endl;
	p->run();
	p->stop();

	p = &b;
	cout << "Bicycle:" << endl;
	p->run();
	p->stop();

	p = &mCar;
	cout << "Motorcar:" << endl;
	p->run();
	p->stop();

	p = &mCycle;
	cout << "Motorcycle:" << endl;
	p->run();
	p->stop();
}