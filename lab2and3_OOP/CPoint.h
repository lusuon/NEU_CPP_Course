#pragma once

#include<iostream>
using namespace std;

class CPoint
{
protected:
	int x, y;
	static int nCount;   // nCount���ڱ����ĸ���
public:
	CPoint(int px = 0, int py = 0);
	CPoint(CPoint&);
	CPoint(const CPoint&);
	~CPoint();
	int GetX()const;
	int GetY()const;
	void SetX(int);
	void SetY(int);
	void ShowPoint();
	static void ShowCount();
	friend class CLine; // ��Ԫ�ܹ�����˽�г�Ա
	friend CPoint operator-(CPoint p1, CPoint p2);
	CPoint operator+(CPoint pt);
	friend istream& operator>>(istream& is, CPoint& cp);
	friend ostream& operator<<(ostream& os, CPoint& cp);
};



//ȫ�ֺ���
CPoint operator-(CPoint, CPoint);

istream& operator>>(istream&, CPoint&);
ostream& operator<<(ostream&, CPoint&);