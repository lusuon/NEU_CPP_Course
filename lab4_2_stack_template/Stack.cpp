#include "Stack.h"
#include <iostream>
using namespace std;
/*
编写一个栈的类模板（包括其成员函数定义），以便为任何类型的对象提供栈结构数据操作。
并在应用程序中创建整数栈、字符栈和浮点数栈，提供一些数据进行进栈、退栈和打印操作的测试。
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