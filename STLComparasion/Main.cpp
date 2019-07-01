#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
���û����ɵشӼ���������������ֱ����������0ʱ���������û���������ݱ�����ģ����Vector<int>����Ķ����У������û�������������������������������ʾ���������ʱ��Ҫ����һ��3�ַ�ʽʵ�֣�
a)	��ʹ��Vector<int>����س�Ա��������ʹ�õ��������������
b)	ʹ�õ������Լ���������
c)	ʹ��STL�ṩ��ͨ���㷨for_each���������
*/
/*
����ģ����Vector<int>��һ���������øö�����ж��û��������ݵĲ������ڽ����������ʱ��
��һ�ַ�ʽ���ǲ��������������������ʷ�����
�ڶ��ַ�ʽ����Vector<int>�ĵ��������������
�ڶ��ַ�ʽ������STLͨ���㷨for_each����ʵ�֣�Ҳ���Բ���copy��������ʵ�֡�
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