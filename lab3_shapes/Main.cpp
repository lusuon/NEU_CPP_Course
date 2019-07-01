#include "CRectangle.h"
#include "Shape.h"
#include "CCircle.h"
#include "ShapeLine.h"
using namespace std;
/*
使用Shape类和CPoint类设计一个可在屏幕上作图简单实例；如：画一个矩形，不必真正画出矩形，只需输出一句话：“This is a rectangle！”即可。
要求可画线段、矩形和圆形。要用到继承，虚函数，多态，数据的封装，构造函数的实现等等各种面向对象程序设计的特性。
*/
void main()
{
	Shape* sp;
	CRectangle cr(1, 2, (ColorType)1);
	CCircle cc(1, (ColorType)1);
	ShapeLine sl(10, 20, (ColorType)1);
	sp = &cr;
	sp->draw();
	sp = &cc;
	sp->draw();
	sp = &sl;
	sp->draw();
}