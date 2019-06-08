#include "CLine.h"
#include <math.h>
#include <iostream>
using namespace std;

/*
todo:
	(1)请完成该类中各成员函数的定义。并利用VC调试工具观察含有组合关系类的构造函数和析构函数的执行情况
	(2)思考如何编写类中3个构造函数:
		CLine()
		CLine(int x1,int y1,int x2,int y2)
		CLine(CPoint p1,CPoint p2)
		分析什么是初始化列表。完成后要在main()中进行测试。
*/


CLine::CLine()
{
}

// 使用初始化列表，避免二次赋值（开辟空间的初值+之后构造函数的显式赋值）
// 初始化顺序与初始化列表内顺序无关，以定义的为准
CLine::CLine(int x1, int y1, int x2, int y2):pt1(x1,y1),pt2(x2,y2)
{
}

CLine::CLine(CPoint p1, CPoint p2):pt1(p1),pt2(p2)
{
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

