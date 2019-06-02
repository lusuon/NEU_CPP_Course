#pragma once
class CPoint
{
private:
	int x, y;
	static int nCount;   // nCount用于保存点的个数
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

