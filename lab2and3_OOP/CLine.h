#include "CPoint.h"
#pragma once


class CLine
{
private:
	CPoint pt1, pt2;  //pt1��pt2�ֱ������߶ε������յ�
public:
	CLine();
	CLine(int x1, int y1, int x2, int y2);
	CLine(CPoint p1, CPoint p2);
	double Distance();  //������߶γ��ȵĳ�Ա����
	void ShowLine();
};

