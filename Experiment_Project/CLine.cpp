#include "CLine.h"
#include <math.h>
#include <iostream>
using namespace std;

/*
todo:
	(1)����ɸ����и���Ա�����Ķ��塣������VC���Թ��߹۲캬����Ϲ�ϵ��Ĺ��캯��������������ִ�����
	(2)˼����ζ�����3�����캯��CLine()��CLine(int x1,int y1,int x2,int y2)��CLine(CPoint p1,CPoint p2);�ı�д������ʲô�ǳ�ʼ���б���ɺ�Ҫ��main()�н��в��ԡ�
*/


CLine::CLine()
{
}

CLine::CLine(int x1, int y1, int x2, int y2)
{
	pt1 = CPoint(x1, y1);
	pt2 = CPoint(x2, y2);
}

CLine::CLine(CPoint p1, CPoint p2)
{
	pt1 = p1;
	pt2 = p2;
}

double CLine::Distance()
{
	int dx = pt1.GetX() - pt2.GetX();
	int dy = pt1.GetY() - pt2.GetY();
	return sqrt(dx ^ 2 + dy ^ 2);
}

void CLine::ShowLine()
{
	cout << "from (" << pt1.GetX() << " , " << pt1.GetY() << ") to " << "(" << pt2.GetX() << " , " << pt2.GetY() << ")" << endl;
}

