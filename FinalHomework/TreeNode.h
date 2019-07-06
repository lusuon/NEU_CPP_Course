#pragma once
#include <map>
#include <string>
using namespace std;
class TreeNode
{
private:
	// 在内部节点，表示当前作为决策依据的特征名；在叶节点，则表示最终决策的结果
	string decision;
	// 在内部节点中，存储特征属性值到下一节点的映射；在叶节点中，容器为空
	map<string, TreeNode*> childs; 
public:
	TreeNode();
	TreeNode(string); // 定义决策依据或决策结果
	void addChild(string, TreeNode*); // 添加子节点
	~TreeNode();
	friend ostream& operator<<(ostream&, TreeNode);
	map<string, TreeNode*> getChilds();
	string getDecision();
};



