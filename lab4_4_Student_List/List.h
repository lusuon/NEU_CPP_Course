#pragma once
template<class T>
class List
{
public:
	List();  //构造函数
	void add(T&);//在Link表头添加新结点
	void remove(T&); //在Link中删除含有特定值的元素
	T* find(T&);  //查找含有特定值的结点
	void printList();  // 打印输出整个链表
	~List();
protected:
	struct Node {
		Node* pNext;
		T* pT;
	};
	Node* pFirst;        //链首结点指针


};

template<class T>
bool operator==(T& t1, T& t2); 


