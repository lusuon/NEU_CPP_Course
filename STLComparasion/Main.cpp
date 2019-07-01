#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
让用户自由地从键盘上输入整数，直到输入数字0时结束。把用户输入的数据保存在模板类Vector<int>定义的对象中，并对用户输入的所有数进行排序输出。在向显示器进行输出时，要求用一下3种方式实现：
a)	仅使用Vector<int>的相关成员函数，不使用迭代器进行输出；
b)	使用迭代器自己编程输出；
c)	使用STL提供的通用算法for_each进行输出。
*/
/*
定义模板类Vector<int>的一个对象，利用该对象进行对用户输入数据的操作。在进行数据输出时，
第一种方式考虑采用类似于数组的随机访问方法，
第二种方式利用Vector<int>的迭代器进行输出，
第二种方式则利用STL通用算法for_each进行实现，也可以才用copy函数进行实现。
*/

void printElement(int t)
{
	cout << t << " ";
}


void main()
{
	vector<int> v;
	int n = -1;
	while (n != 0)
	{
		cin >> n;
		v.push_back(n);
	}
	cout << "using index" << endl;
	for (int i = 0; i < v.size(); i++) {
		printElement(v[i]);
	}
	cout << endl;
	cout << "using iterator" << endl;
	vector<int>::iterator start = v.begin();
	vector<int>::iterator end = v.end();
	while (start != end) {
		printElement(*start);
		start++;
	}
	cout << endl;
	cout << "using foreach" << endl;
	for_each(v.begin(), v.end(), printElement);
	cout << endl;
}