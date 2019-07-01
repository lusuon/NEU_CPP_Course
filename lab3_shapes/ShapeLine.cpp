#include "ShapeLine.h"
#include <iostream>
using namespace std;


ShapeLine::ShapeLine(double start, double end,ColorType c):start(start), end(end), Shape(c)
{
}


ShapeLine::~ShapeLine()
{
}

void ShapeLine::draw()
{
	cout << " This is a line!" << endl;
}