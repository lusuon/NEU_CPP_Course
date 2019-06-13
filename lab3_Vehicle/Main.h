#pragma once

void main()
{
	Vehicle v = Vehicle(0, 0);
	Bicycle b = Bicycle(10, 1, 2);
	Motorcar mCar = Motorcar(20, 5, 4);
	Motorcycle mCycle = Motorcycle(30, 10);

	Vehicle* p;
	p = &v;
	cout << "Base class Vehicle:" << endl;
	p->run();
	p->stop();
	cout << "Bicycle:" << endl;
	*v->run();
	*v->stop();
	cout << "Motorcar:" << endl;
	v = &mCar;
	*v->run();
	*v->stop();
	cout << "Motorcycle:" << endl;
	v = &mCycle;
	*v->run();
	*v->stop();
}
