#pragma once
#include "Shape.h"
class ShapeLine :
	public Shape
{
private:
	double start, end;
public:
	ShapeLine(double start, double end, ColorType c);
	~ShapeLine();
	virtual void draw();
};

