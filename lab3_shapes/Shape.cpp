#include "Shape.h"
#include <iostream>
using namespace std;

Shape::~Shape()
{
}

Shape::Shape(ColorType c):color(c)
{
}

void Shape::draw()
{
	// Do nothing
	cout << "Can not draw a shape." << endl;
}
