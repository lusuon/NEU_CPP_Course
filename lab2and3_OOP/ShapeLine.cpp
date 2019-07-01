#include <iostream>
#include "ShapeLine.h"
using namespace std;

ShapeLine::ShapeLine(ColorType c, double s, double e):ColorType(c),start(s),end(e)
{
}


ShapeLine::~ShapeLine()
{
}

void ShapeLine::draw()
{
	cout << " This is a line!" << endl;
}