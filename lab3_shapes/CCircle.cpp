#include "CCircle.h"
#include <iostream>
using namespace std;



CCircle::CCircle(double r, ColorType c) :radius(r), Shape(c)
{
}

CCircle::~CCircle()
{
}

void CCircle::draw()
{
	cout << " This is a circle!" << endl;
}
