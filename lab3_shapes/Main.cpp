#include "CRectangle.h"
#include "Shape.h"
#include "CCircle.h"
#include "ShapeLine.h"
using namespace std;
/*
ʹ��Shape���CPoint�����һ��������Ļ����ͼ��ʵ�����磺��һ�����Σ����������������Σ�ֻ�����һ�仰����This is a rectangle�������ɡ�
Ҫ��ɻ��߶Ρ����κ�Բ�Ρ�Ҫ�õ��̳У��麯������̬�����ݵķ�װ�����캯����ʵ�ֵȵȸ���������������Ƶ����ԡ�
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