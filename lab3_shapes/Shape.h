#pragma once
enum ColorType { White, Black, Red, Green, Blue, Yellow, Magenta, Cyan };


class Shape
{
protected:
	ColorType  color;
public:
	Shape(ColorType); // ���캯���������麯��
	virtual ~Shape(); //��������һ�����麯��
	virtual void draw();

};

