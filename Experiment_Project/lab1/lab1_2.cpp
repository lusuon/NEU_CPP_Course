# include<iostream>
using namespace std;
//编写重载函数Maxl可分别求取两个整数，三个整数，两个双精度数，三个双精度数的最大值

double maxl(double a, double b)
{
	return a > b ? a : b;
}

int maxl(int a, int b)
{
	return a > b ? a : b;
}

double maxl(double a, double b, double c)
{
	return maxl(a, b) >= maxl(a, c) ? maxl(a, b) : maxl(a, c);
}

int maxl(int a, int b, int c)
{
	return maxl(a, b) >= maxl(a, c) ? maxl(a, b) : maxl(a,c);
}

/*

void main()
{
	int a = 1;
	int b = 2;
	int c = 3;
	cout << "input: 1, 2, 3 " << "for 1 and 3, the bigger is " << maxl(a, c) << endl;
	cout << "input: 1, 2, 3 " << "for 1, 2 and 3 the bigger is " << maxl(a, b, c) << endl;
	double d = 1.1;
	double e = 2.2;
	double f = 3.3;
	cout << "input: 1.1, 3.3 " << "for 1.1 and 3.3, the bigger is " << maxl(d, f) << endl;
	cout << "input: 1.1, 2.2, 3.3 " << "for 1.1, 2.2 and 3.3 , the bigger is " << maxl(d, e, f) << endl;
}

*/

