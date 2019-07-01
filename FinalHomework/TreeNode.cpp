#include "TreeNode.h"
#include <map>
#include <iostream>
using namespace std;


TreeNode::TreeNode()
{
}

TreeNode::TreeNode(string leaf_decision):decision(leaf_decision)
{
}

void TreeNode::addChild(string label, TreeNode* child)
{
	childs.insert(pair<string, TreeNode*>(label, child));
}

TreeNode::~TreeNode()
{
}

map<string, TreeNode*> TreeNode::getChilds()
{
	return childs;
}

string TreeNode::getDecision()
{
	return decision;
}
