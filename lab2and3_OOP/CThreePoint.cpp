#include "CThreePoint.h"


//定义 “空间中点”类
/*
	完成该类中各成员函数的定义。并利用VC调试工具观察含有继承关系类的构造函数和析构函数的执行情况。
*/
/*
	分析为什么要把ShowPoint()函数设置为虚函数？有什么作用？请在main()函数中做测试。
*/


CThreePoint::CThreePoint() :CPoint(0, 0), z(0)
{
	
}

CThreePoint::CThreePoint(int px, int py, int pz) :CPoint(px, py), z(pz)
{
	cout << "A point in the space: ";
	ShowPoint();
	cout << "created";
}

int CThreePoint::GetZ()
{
	return z;
}

void CThreePoint::SetZ(int pz)
{
	z = pz;
}

void CThreePoint::ShowPoint()
{
	cout << "(" << x << "," << y << "," << z << ")" << endl;
}
