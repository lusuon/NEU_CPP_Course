#include "List.h"
#include <iostream>
#include "Student.h"
using namespace std;
//完成对上述List类模板含有的各成员函数的定义。
//然后定义一个简单的Student类，并利用编写的List类模板对一个班级的学生进行动态管理

template<class T>
inline bool operator==(T& t1, T& t2)
{
	return (&t1 == &t2) ? true : false;
}

template<class T>
List<T>::List()
{
}

template<class T>
void List<T>::add(T& t)
{
	if (pFirst == NULL) {
		pFirst = new Node();
		pFirst->pNext = NULL;
		pFirst->pT = &t;
	}else{
		Node* new_head = new Node();
		new_head->pT = &t;
		new_head->pNext = pFirst;
		pFirst = new_head;
	}
}

template<class T>
void List<T>::remove(T& t)
{
	Node* p = pFirst;
	if (&(p->pT) == t) {
		Node* toDelete = pFirst;
		pFirst = p->pNext;
		delete toDelete;
		return;
	}
	while (p->pNext != NULL) {
		if (&(p->pNext->pT) == t) {
			p.pNext = p.pNext.pNext;
			delete p.pNext;
			return;
		}
	}
	cout << "Remove nothing.";
}

template<class T>
T* List<T>::find(T&)
{
	Node* p = pFirst;
	while ((*p).pT != T) {
		p = (*p).pNext;
	}
	return ((*p).pT == T)? (*p).pT :NULL;
}

template<class T>
void List<T>::printList()
{
	Node* p = pFirst;
	while ((*p).pNext != NULL) {
		cout<<(*p).pT<<" ";
		p = (*p).pNext;
	}
}

template<class T>
List<T>::~List()
{
}

void main() {
	List<Student>* ls = new List<Student>();
	Student* s;
	for (int i = 0; i < 5; i++) {
		s = new Student(i, "a", "a");
		ls->add((*s));
	}
	ls->printList();
	ls->remove((*s));
	ls->printList();

}