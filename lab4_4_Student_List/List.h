#pragma once
template<class T>
class List
{
public:
	List();  //���캯��
	void add(T&);//��Link��ͷ����½��
	void remove(T&); //��Link��ɾ�������ض�ֵ��Ԫ��
	T* find(T&);  //���Һ����ض�ֵ�Ľ��
	void printList();  // ��ӡ�����������
	~List();
protected:
	struct Node {
		Node* pNext;
		T* pT;
	};
	Node* pFirst;        //���׽��ָ��


};

template<class T>
bool operator==(T& t1, T& t2); 


