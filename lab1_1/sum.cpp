#include<iostream>
using namespace std;

int add(int a,int b);
int add(int a, int b)
{
	int c;
	c=a + b;
	return c;
}

int main()
{
	int x, y, sum;
	cout << "Enter two numbers:\n";
	cin >> x;
	cin >> y;
	sum = add(x, y);
	cout << "The sum is£º" << sum << endl;
	return 0;
}