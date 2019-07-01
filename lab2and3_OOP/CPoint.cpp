#include "CPoint.h"
#include <iostream>

using namespace std;

//todo:
//�����Ծ�̬��Ա�ĵ��ú�һ���Ա�ĵ��÷�ʽ��ʲô��ͬ��
/*
��1����ɸ����и���Ա�����Ķ���
	��OK��ע��Ծ�̬��ԱnCount�Ĳ�����ʹ���ܹ���ȷ��ʾ�����е�ĸ���
	��OK����������Ҫ��main()�����н��в��ԣ��ֱ���CPoint��Ķ���ָ�롢���ã��Ը���Ա�������е��á�
*/
/*
	��2����OK��
	�Գ�Ա�����ķ�ʽ������CPoint��ġ�+������������ص�CPoint�����ĺ�������ֵ�ֱ����ԭ����ĺ�������ֵ֮�ͣ�
		�Գ�Ա������ʽ���صġ�+����������ԭ��Ϊ��CPoint CPoint::operator+ (CPoint pt);
	��ȫ�ֺ����ķ�ʽ����CPoint��ġ�-������������ص�CPoint�����ĺ�������ֵ�ֱ����ԭ����ĺ�������ֵ֮�
		��ȫ�ֺ�����ʽ���صġ�-����������ԭ��Ϊ��CPoint operator- (CPoint pt1, CPoint pt2);
	�����Գ�Ա������ʽ��ȫ�ֺ�����ʽ�������з�����ͬ��
*/
/*
	(3)
	������Ŀ1�е�CPoint�࣬���ء�>>�������ʹ����cin�������������ܹ�дCPoint�����
		���صġ�>>����������ԭ��Ϊ��istream& operator>>(istream&, CPoint&);
	�����ء�<<�������ʹ����cout������������ܹ����CPoint�����
		���صġ�<<����������ԭ��Ϊ��ostream& operator>>(ostream&, CPoint);
	˼��һ�£����صġ�>>���������͡�<<���������ܷ���ΪCPoint��ĳ�Ա������ʵ�֡����ܣ�������Ҫ��CPoint���ǰ�棻
*/

int CPoint::nCount = 0; // Ϊ��̬��Ա����nCount�����ڴ桢��ʼ��

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

// ���� + �����
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



