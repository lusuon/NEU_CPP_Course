#include<iostream>
using namespace std;

/*
函数模板的原型可定义为：template<class T> T min(T&, T&)
为了同时要确保正确处理字符串，而字符串不能用“<”来比较，所以还需要特别定义函数：char* min(char* a, char* b)
另外，要在main函数中对自己编写的模板进行测试。
*/

template<typename T>
T Min(T a, T b)
{
	return a < b ? a : b;
}
char* min(char* a, char* b)
{
	return strcmp(a, b) < 0 ? a : b;
}
void main()
{
	int a = 100, b = 200;
	double c = 1.1, d = 2.2;
	char e = 'e', E = 'E';
	cout << Min(a,b) << endl;
	cout << Min(c,d) << endl;
	cout << Min(e,E) << endl;

	const char* p1 = "ZZZ!", *p2 = "What a good day!"; // 顺序：已有函数——模板——强制类型转换
	cout << Min(p1, p2);
}