#pragma once
class CPoint
{
private:
	int x, y;
	static int nCount;   // nCount���ڱ����ĸ���
public:
	CPoint(int px = 0, int py = 0);
	CPoint(CPoint&);
	~CPoint();
	int GetX();
	int GetY();
	void SetX(int);
	void SetY(int);
	void ShowPoint();
};

