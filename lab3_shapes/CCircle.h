#pragma once
#include "Shape.h"

class CCircle :
	public Shape
{
private:
	double radius;
public:
	CCircle(double,ColorType);
	~CCircle();
	virtual void draw();
};

