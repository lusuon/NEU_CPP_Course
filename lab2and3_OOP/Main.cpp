#include "CPoint.h"
#include "CThreePoint.h"
using namespace std;


void main()
{
	/*
	CPoint cp(1, 1);
	CPoint cp2(2, 3);
	CPoint* ptr = &cp;
	CPoint& ref = cp;
	// 对所有方法进行调用
	// 使用引用
	cout << endl << "using reference to call." << endl;
	cout << "using getter to show x and y: " << ref.GetX() << " " << ref.GetY() << endl;
	cout << "using reference to set and show." << endl;
	ref.SetX(0);
	ref.SetY(0);
	ref.ShowPoint();
	// 使用对象本身
	cout << endl << "using object itself to call." << endl;
	cout << "using getter to show x and y: " << cp.GetX() << " " << cp.GetY() << endl;
	cout << "using object itself to set and show." << endl;
	cp.SetX(114);
	cp.SetY(114);
	cp.ShowPoint();
	// 使用对象指针
	cout << endl << "using pointer to call." << endl;
	cout << "using getter to show x and y: " << ptr->GetX() << " " << ptr->GetY() << endl;
	cout << "using pointer to set and show." << endl;
	ptr->SetX(514);
	ptr->SetY(514);
	ptr->ShowPoint();
	cout << "start adding two points" << endl;
	cout << cp;
	CPoint cp3 = (cp + cp2);
	cout << cp << "add with" << cp2 << "equals" << cp3 << "created";
	CPoint cp4 = (cp - cp2);
	cout << cp << "destract with" << cp2 << "equals" << cp4 << "created";
	cout << endl << "input new x,y of cp:" << endl;
	cin >> cp;
	cout << "cp after input:" << endl;
	cout << cp;
	*/
	CThreePoint tcp(1,1,1);
}