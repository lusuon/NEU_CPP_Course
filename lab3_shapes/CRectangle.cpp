#include "CRectangle.h"
#include <iostream>
using namespace std;


CRectangle::CRectangle(double l, double w, ColorType c):length(l),weight(w),Shape(c)
{
}

void CRectangle::draw()
{
	cout << "A rectangle drew." << endl;
}
