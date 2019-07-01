#pragma once
#include "Shape.h"

class CRectangle :
	public Shape
{
private:
	int length;
	int weight;
public:
	CRectangle(double l, double w, ColorType);
	virtual ~CRectangle();
	virtual void draw();

};
