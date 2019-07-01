#pragma once
enum ColorType { White, Black, Red, Green, Blue, Yellow, Magenta, Cyan };


class Shape
{
protected:
	ColorType  color;
public:
	Shape(ColorType); // 构造函数不能做虚函数
	virtual ~Shape(); //析构函数一般作虚函数
	virtual void draw();

};

