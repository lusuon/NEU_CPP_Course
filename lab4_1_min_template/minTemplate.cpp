#include<iostream>
using namespace std;

/*
����ģ���ԭ�Ϳɶ���Ϊ��template<class T> T min(T&, T&)
Ϊ��ͬʱҪȷ����ȷ�����ַ��������ַ��������á�<�����Ƚϣ����Ի���Ҫ�ر��庯����char* min(char* a, char* b)
���⣬Ҫ��main�����ж��Լ���д��ģ����в��ԡ�
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

	const char* p1 = "ZZZ!", *p2 = "What a good day!"; // ˳�����к�������ģ�塪��ǿ������ת��
	cout << Min(p1, p2);
}