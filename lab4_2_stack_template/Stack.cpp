#include "Stack.h"
#include <iostream>
using namespace std;
/*
��дһ��ջ����ģ�壨�������Ա�������壩���Ա�Ϊ�κ����͵Ķ����ṩջ�ṹ���ݲ�����
����Ӧ�ó����д�������ջ���ַ�ջ�͸�����ջ���ṩһЩ���ݽ��н�ջ����ջ�ʹ�ӡ�����Ĳ��ԡ�
*/

const int SIZE = 100;

template<class T>
class Stack
{
public:
	Stack();
	void Push(T n);
	T Pop();
private:
	T array[SIZE];
	int tos;
};

template<class T>
Stack<T>::Stack():tos(0)
{
}



template<class T>
void Stack<T>::Push(T t)
{
	array[tos] = t;
	tos++;
}

template<class T>
T Stack<T>::Pop()
{
	return array[--tos];
}


void main()
{
	cout << "Create a int stack.";
	Stack<int> si = Stack<int>();
	for (int i = 0; i < 5; i++) si.Push(i);
	for (int i = 0; i < 5; i++) cout<<si.Pop()<<endl;
	cout << "Create a float stack.";
	Stack<double> sd = Stack<double>();
	for (double i = 1.1; i < 5; i++) sd.Push(i);
	for (int i = 0; i < 4; i++) cout << sd.Pop() << endl;
}