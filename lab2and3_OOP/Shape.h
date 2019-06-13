#pragma once
enum ColorType { White, Black, Red, Green, Blue, Yellow, Magenta, Cyan };

/*
ʹ��Shape���CPoint�����һ��������Ļ����ͼ��ʵ�����磺��һ�����Σ����������������Σ�ֻ�����һ�仰����This is a rectangle�������ɡ�
Ҫ��ɻ��߶Ρ����κ�Բ�Ρ�Ҫ�õ��̳У��麯������̬�����ݵķ�װ�����캯����ʵ�ֵȵȸ���������������Ƶ����ԡ�

*/
class Shape
{
protected:
	ColorType  color;

public:
	Shape(); // ���캯���������麯��
	virtual ~Shape(); //��������һ�����麯��
	Shape(ColorType c);
	virtual void draw();

};

