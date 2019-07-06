#include <Eigen/Dense>
using namespace Eigen; 
#include <map>
#include <set>
#include <iostream>
#include <fstream>
using namespace std;
#include "DecisionTree.h"
#include "tool.h"

//constexpr auto TRAIN_RATE = 0.9;

/*
	决策树的实现
	Jackson Ma
	2019-06-15
*/


void preorder(TreeNode* root, int depth)
{
	map <string, TreeNode*> c = root->getChilds();
	cout << (!(c.size()) ? "get result: " : "for attribute: ") << root->getDecision() << endl;
	depth++;
	if (c.size())
	{
		for (map <string, TreeNode*>::iterator it = c.begin(); it != c.end(); it++)
		{
			int i = 0;
			while (i < depth)
			{
				if (i < depth - 1) cout << ("\t");
				else cout << "|——";
				i++;
			}
			cout << "if " << (*it).first << ":";
			preorder((*it).second, depth);
		}
	}
	else return;
}

// 删除矩阵的指定行
Matrix<string, Dynamic, Dynamic> removeRow(Matrix<string, Dynamic, Dynamic> matrix, int rowToRemove)
{
	int numRows = matrix.rows() - 1;
	int numCols = matrix.cols();

	if (rowToRemove < numRows)
		matrix.block(rowToRemove, 0, numRows - rowToRemove, numCols) = matrix.block(rowToRemove + 1, 0, numRows - rowToRemove, numCols);
	matrix.conservativeResize(numRows, numCols);
	return matrix;
}

// 判断矩阵内元素是否全部一致
bool isAllElementTheSame(Matrix<string, Dynamic, Dynamic> m)
{
	set<string> checkSet;
	for (string *p = m.data(); p < m.data() + m.size(); p++) checkSet.insert(*p);
	return checkSet.size() == 1;
}

DecisionTree::DecisionTree(Matrix<string, Dynamic, Dynamic> d,Matrix<string,1,Dynamic> l)
{
	labels = l;
	dataset = d;
	createTree();
}

DecisionTree::~DecisionTree()
{
}

// 计算给定数据集的香农熵
double DecisionTree::calcShannonEnt(Matrix<string, Dynamic, Dynamic> dataset)
{
	int numEntries =  dataset.rows();
	int datasetCols = dataset.cols();
	map<string, int> labelCounts;
	// 最后一列 m*1 的标签向量
	Matrix<string, Dynamic, 1> labels = dataset.col(datasetCols-1);
	for (int i = 0; i < numEntries; i++)
	{
		string key = labels(i,0); //第i个标签的值
		if (labelCounts.count(key) == 0) labelCounts.insert(map<string, int>::value_type(key, 0));
		labelCounts[key] ++;
	}
	double shannonEnt = 0;
	for (map<string, int>::iterator i = labelCounts.begin(); i != labelCounts.end(); i++)
	{
		string key = i->first;
		double prob = double(labelCounts[key]) / double(numEntries);
		shannonEnt -= prob * (log(prob) / log(2));
	}
	return shannonEnt;
}

//在指定列上根据给定值对数据集进行划分：选出符合指定列要求值的部分，并删去指定列
Matrix<string, Dynamic, Dynamic> DecisionTree::splitDataSet(Matrix<string, Dynamic, Dynamic> d, int axis, string value)
{
	Matrix<string, Dynamic, Dynamic> splitted_dataset;
	splitted_dataset.resize(d.rows(), d.cols() - 1);
	int new_col_count = 0;
	int new_row_count = 0;
	for(int row = 0;row<d.rows();row++)
	{
		if (d(row, axis) == value) {
			//取出该行除了指定列的其余部分
			new_col_count = 0;
			for (int col = 0; col < d.cols(); col++)
			{
				if (col != axis)
				{
					splitted_dataset(new_row_count,new_col_count) = d(row, col);
					new_col_count++;
				}
			}
			if (new_col_count != 0) new_row_count++;
		}
	}
	return splitted_dataset.middleRows(0, new_row_count);
	//return splitted_dataset;
}

// 选择划分该数据集的最佳特征列的索引
int DecisionTree::chooseBestFeatureToSplit(Matrix<string, Dynamic, Dynamic> dataset)
{
	int numFeatures = dataset.cols() - 1; //数据集的特征数
	double baseEntropy = calcShannonEnt(dataset); //计算数据集的香农熵
	double bestInfoGain = 0; //信息增益
	int bestFeature = -1; //初始化最佳划分索引
	for (int i = 0; i < numFeatures; i++) //遍历每一列
	{
		// 为每列的特征值建立集合
		set<string> col_feature_value_set; 
		for (int row = 0; row < dataset.rows(); row++) col_feature_value_set.insert(dataset(row, i));
		// 计算每一列的信息熵
		double newEntropy = 0;
		for (set<string>::iterator it = col_feature_value_set.begin(); it != col_feature_value_set.end(); ++it)
		{
			Matrix<string, Dynamic, Dynamic> subDataSet = splitDataSet(dataset, i, *it);
			double prob = double(subDataSet.rows()) / double(dataset.rows());
			newEntropy += prob * calcShannonEnt(subDataSet);
		}
		// 计算信息增益，增益最大者为最佳划分
		double infoGain = baseEntropy - newEntropy;
		if (infoGain > bestInfoGain)
		{
			bestInfoGain = infoGain;
			bestFeature = i;
		}
	}
	return bestFeature;
}

// 未决定传入类标签中出现次数最多的标签
string DecisionTree::majorityCnt(Array<string,Dynamic,1> classList)
{
	// 计算各种标签出现次数的map，对各标签进行计数
	int rows = classList.rows();
	map<string, int> classCount;
	for (int row = 0; row < rows; row++)
	{
		string label = classList(row, 0);
		if (classCount.count(label) == 0) classCount.insert(map<string, int>::value_type(label, 0));
		classCount[label] ++;
	}

	// 寻找标签中出现最多者
	int maxCount = 0;
	pair<string, int> maxp;
	for (map<string,int>::iterator it = classCount.begin(); it != classCount.end(); ++it)
	{
		pair<string,int> current_pair = (*it);
		if (current_pair.second >= maxCount)
		{
			maxCount = current_pair.second;
			maxp = current_pair;
		}
	}
	return maxp.first;
}

// labels为列对应的特征名
TreeNode* DecisionTree::createTree(Matrix<string, Dynamic, Dynamic> dataset, Matrix<string, Dynamic, 1> labels)
{
	// 取dataset最后一列，获取当前划分数据集内的标签分类结果（未测试）
	Matrix<string, Dynamic, 1> classList = dataset.rightCols(1); 
	// 递归边界条件一：标签完全相同，不再划分，返回该标签（string)构成的叶节点
	if (isAllElementTheSame(classList)) {
		TreeNode* leaf =  new TreeNode(classList(0, 0)); //记得释放！！！！！！！！！
		return leaf;
	}
	// 递归边界条件二：遍历完所有特征时，返回出现次数最多的标签(string)构成的叶节点
	if (dataset.cols() == 1) {
		TreeNode* leaf = new TreeNode(majorityCnt(classList));
		return leaf;
	}
	// 选择数据集中最的最佳划分特征的索引
	int bestFeat = chooseBestFeatureToSplit(dataset); 
	string bestFeatLabel = labels(bestFeat, 0);
	TreeNode* myTree = new TreeNode(bestFeatLabel);
	Matrix<string, Dynamic, 1> new_labels = removeRow(labels,bestFeat); 

	// 得到最佳划分内的所有的feature值——dataset的第bestFeat列
	Matrix<string,Dynamic,1> featValues = dataset.col(bestFeat);
	set<string> uniqueVals;
	for (int row = 0; row < featValues.rows(); row++)
	{
		uniqueVals.insert(featValues(row,0));
	}
	// 遍历所选择特征的所有属性值，在每个划分上递归调用本函数
	for (set<string>::iterator it = uniqueVals.begin(); it != uniqueVals.end(); ++it)
	{
		//需要复制新的类标签，保证每次createTree 不改变原始列表内容
		Matrix<string,Dynamic,1> subLabels = new_labels; 
		myTree->addChild((*it), createTree(splitDataSet(dataset, bestFeat, *it), subLabels));
		// value 是迭代器指针所指向的值，表示所选择特征的属性
		// myTree[bestFeatLabel][value] = createTree(splitDataSet(dataset, bestFeat, value), subLabels); 
	}
	return myTree;
}

void DecisionTree::createTree()
{
	//Matrix<string, Dynamic, 1> labels = dataset.topRows(0).transpose();
	root = createTree(dataset,labels);
	preorder(root,0);
}

string DecisionTree::classify(TreeNode* tree, Matrix<string, Dynamic, 1> featLabels, Matrix<string, 1, Dynamic> testVec)
{
	string classLabel; // 初始化返回标签结果
	string decision = tree->getDecision();
	map<string,TreeNode*> childs= tree->getChilds();
	// 获取当前树决策标签在数据集内的列位置
	int featIndex = -1;
	for (int r = 0; r < featLabels.rows(); r++)
	{
		if (featLabels(r, 0) == decision)
		{
			featIndex = r;
			break;
		}
	}

	for (map<string, TreeNode*>::iterator it = childs.begin(); it != childs.end(); it++)
	{
		if (testVec(0, featIndex) == (*it).first)
		{
			//对应节点仍有其子节点，说明为中间节点，在该点递归调用本函数
			if ((*it).second->getChilds().size() != 0) classLabel = classify((*it).second, featLabels, testVec);
			else classLabel = (*it).second->getDecision();// 决策
		}
	}
	return classLabel;
}

string DecisionTree::classify(Matrix<string, 1, Dynamic> testvec)
{
	return classify(root, labels, testvec);
}

double DecisionTree::test()
{
	return 0;
}


ostream& operator<<(ostream& os, TreeNode* tn)
{
	cout << endl;
	preorder(tn,0);
	return os;
}






Matrix<string, Dynamic, Dynamic> DecisionTree::getDataset() {
	return dataset;
}

Matrix<string, Dynamic, 1> DecisionTree::getLabels()
{
	return this->labels;
}


