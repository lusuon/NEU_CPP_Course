#include "CThreePoint.h"


//���� ���ռ��е㡱��
/*
	��ɸ����и���Ա�����Ķ��塣������VC���Թ��߹۲캬�м̳й�ϵ��Ĺ��캯��������������ִ�������
*/
/*
	����ΪʲôҪ��ShowPoint()��������Ϊ�麯������ʲô���ã�����main()�����������ԡ�
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
