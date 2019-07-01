#include "CPoint.h"
#include <iostream>

using namespace std;

//todo:
//分析对静态成员的调用和一般成员的调用方式有什么不同。
/*
（1）完成该类中各成员函数的定义
	【OK】注意对静态成员nCount的操作，使其能够正确表示程序中点的个数
	【OK】编完该类后，要在main()函数中进行测试，分别定义CPoint类的对象、指针、引用，对各成员函数进行调用。
*/
/*
	（2）【OK】
	以成员函数的方式，重载CPoint类的“+”运算符，返回的CPoint类对象的横纵坐标值分别等于原两点的横纵坐标值之和；
		以成员函数方式重载的“+”操作符的原型为：CPoint CPoint::operator+ (CPoint pt);
	以全局函数的方式重载CPoint类的“-”运算符，返回的CPoint类对象的横纵坐标值分别等于原两点的横纵坐标值之差。
		以全局函数方式重载的“-”操作符的原型为：CPoint operator- (CPoint pt1, CPoint pt2);
	分析以成员函数方式和全局函数方式重载运行符的异同点
*/
/*
	(3)
	对于题目1中的CPoint类，重载“>>”运算符使得像cin等输入流对象能够写CPoint类对象
		重载的“>>”操作符的原型为：istream& operator>>(istream&, CPoint&);
	再重载“<<”运算符使得像cout等输出流对象能够输出CPoint类对象。
		重载的“<<”操作符的原型为：ostream& operator>>(ostream&, CPoint);
	思考一下，重载的“>>”操作符和“<<”操作符能否作为CPoint类的成员函数来实现。不能，否则需要把CPoint类放前面；
*/

int CPoint::nCount = 0; // 为静态成员变量nCount分配内存、初始化

CPoint::CPoint(int px, int py) :x(px), y(py)
{

	nCount++;
	//cout << endl << "A new point created.";
	
	cout << "A new point in plate consructed:";
	ShowPoint();
	cout<<" current nCount: " << nCount << endl;
}

CPoint::CPoint(CPoint &cp):x(cp.x),y(cp.y)
{
	nCount++;
	cout << "A new point consructed by reference, current nCount: " << nCount << endl;
}

CPoint::~CPoint()
{
	cout << endl << "The point following was destroyed." << endl;
	ShowPoint();
	nCount--;
	cout << "After destroting,current nCount: " << nCount << endl;
}

int inline CPoint::GetX()const
{
	return x;
}

int inline CPoint::GetY()const
{
	return y;
}

void inline CPoint::SetX(int new_x)
{
	x = new_x;
}

void inline CPoint::SetY(int new_y)
{
	y = new_y;
}

void CPoint::ShowPoint()
{
	cout << "(" << this->GetX() << "," << this->GetY() << ")" << endl;
}

void CPoint::ShowCount()
{
	cout << nCount;
}

// 重载 + 运算符
CPoint CPoint::operator+(CPoint cp_another)
{
	cout << "this, x is:" << x << ", y is:" << y << endl;
	cout << "another, x is:" << cp_another.x << ", y is:" << cp_another.y << endl;
	int new_x = x + cp_another.x;
	int new_y = y + cp_another.y;
	CPoint added(new_x, new_y);
	return added;
}

CPoint operator-(CPoint p1, CPoint p2)
{
	int new_x = p1.x - p2.x;
	int new_y = p1.y - p2.y;
	CPoint cp(new_x, new_y);
	return cp;
}

istream& operator>>(istream& is, CPoint& cp)
{
	is >> cp.x >> cp.y;
	//int new_x;
	//int new_y;
	//is >> new_x >> new_y;
	//cp.SetX(new_x);
	//cp.SetY(new_y);
	return is;
}

ostream& operator<<(ostream& os, CPoint& cp)
{
	cout << "(" << cp.GetX() << "," << cp.GetY() << ")"<<endl;
	return os;
}



