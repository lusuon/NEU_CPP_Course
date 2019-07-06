#pragma once
#include <map>
#include <string>
using namespace std;
class TreeNode
{
private:
	// ���ڲ��ڵ㣬��ʾ��ǰ��Ϊ�������ݵ�����������Ҷ�ڵ㣬���ʾ���վ��ߵĽ��
	string decision;
	// ���ڲ��ڵ��У��洢��������ֵ����һ�ڵ��ӳ�䣻��Ҷ�ڵ��У�����Ϊ��
	map<string, TreeNode*> childs; 
public:
	TreeNode();
	TreeNode(string); // ����������ݻ���߽��
	void addChild(string, TreeNode*); // ����ӽڵ�
	~TreeNode();
	friend ostream& operator<<(ostream&, TreeNode);
	map<string, TreeNode*> getChilds();
	string getDecision();
};



