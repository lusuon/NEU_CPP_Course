#pragma once
enum ColorType { White, Black, Red, Green, Blue, Yellow, Magenta, Cyan };

/*
使用Shape类和CPoint类设计一个可在屏幕上作图简单实例；如：画一个矩形，不必真正画出矩形，只需输出一句话：“This is a rectangle！”即可。
要求可画线段、矩形和圆形。要用到继承，虚函数，多态，数据的封装，构造函数的实现等等各种面向对象程序设计的特性。

*/
class Shape
{
protected:
	ColorType  color;

public:
	Shape(); // 构造函数不能做虚函数
	virtual ~Shape(); //析构函数一般作虚函数
	Shape(ColorType c);
	virtual void draw();

};

