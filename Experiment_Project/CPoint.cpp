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
	(3)
	������Ŀ1�е�CPoint�࣬���ء�>>�������ʹ����cin�������������ܹ�дCPoint�����
		���صġ�>>����������ԭ��Ϊ��istream& operator>>(istream&, CPoint&);
	�����ء�<<�������ʹ����cout������������ܹ����CPoint�����
		���صġ�<<����������ԭ��Ϊ��ostream& operator>>(ostream&, CPoint);
	˼��һ�£����صġ�>>���������͡�<<���������ܷ���ΪCPoint��ĳ�Ա������ʵ�֡�
*/

int CPoint::nCount = 0; // Ϊ��̬��Ա����nCount�����ڴ�

CPoint::CPoint(int px, int py)
{
	x = px;
	y = py;
	nCount++;
	cout << endl << "A new point created.";
	ShowPoint();
	cout << "nCount: " << nCount << endl;
}

CPoint::CPoint(CPoint &cp)
{
	x = cp.GetX();
	y = cp.GetY();
	nCount++;
}

CPoint::~CPoint()
{
	cout << endl << "The point following was destroyed." << endl;
	ShowPoint();
	nCount--;
	cout << "nCount: " << nCount << endl;
}

int CPoint::GetX()
{
	return x;
}

int CPoint::GetY()
{
	return y;
}

void CPoint::SetX(int new_x)
{
	x = new_x;
}

void CPoint::SetY(int new_y)
{
	y = new_y;
}

void CPoint::ShowPoint()
{
	cout << "(" << this->GetX() << "," << this->GetY() << ")" << endl;
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