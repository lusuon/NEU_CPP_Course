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
	��2��
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
	˼��һ�£����صġ�>>���������͡�<<���������ܷ���ΪCPoint��ĳ�Ա������ʵ�֡�
*/

int CPoint::nCount = 0; // Ϊ��̬��Ա����nCount�����ڴ桢��ʼ��

CPoint::CPoint(int px, int py) :x(px), y(py)
{
	//x = px;
	//y = py;
	nCount++;
	cout << endl << "A new point created.";
	ShowPoint();
	cout << "nCount: " << nCount << endl;
}

CPoint::CPoint(CPoint &cp)
{
	nCount++;
}

CPoint::~CPoint()
{
	cout << endl << "The point following was destroyed." << endl;
	ShowPoint();
	nCount--;
	cout << "nCount: " << nCount << endl;
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
CPoint CPoint::operator+(CPoint cp)
{
	int new_x = x + cp.GetX();
	int new_y = y + cp.GetY();
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


/*

void main()
{
	CPoint cp(1,1);
	CPoint* ptr = &cp;
	CPoint& ref = cp;
	// �����з������е���
	// ʹ������
	cout << endl << "using reference to call." << endl;
	cout << "using getter to show x and y: " << ref.GetX() << " " << ref.GetY() << endl;
	cout << "using reference to set and show." << endl;
	ref.SetX(0);
	ref.SetY(0);
	ref.ShowPoint();
	// ʹ�ö�����
	cout << endl << "using object itself to call." << endl;
	cout << "using getter to show x and y: " << cp.GetX() << " " << cp.GetY() << endl;
	cout << "using object itself to set and show." << endl;
	cp.SetX(114);
	cp.SetY(114);
	cp.ShowPoint();
	// ʹ�ö���ָ��
	cout << endl << "using pointer to call." << endl;
	cout << "using getter to show x and y: " << ptr->GetX() << " " << ptr->GetY() << endl;
	cout << "using pointer to set and show." << endl;
	ptr->SetX(514);
	ptr->SetY(514);
	ptr->ShowPoint();
}
*/
