#include <Eigen/Dense>
using namespace Eigen; 
#include <map>
#include <set>
#include <iostream>
#include <fstream>
using namespace std;
#include "DecisionTree.h"

/*
	决策树的实现
	Jackson Ma
	2019-06-15
*/

void DecisionTree::readData(string textName)
{
	dataset.resize(24, 5);
	ifstream inf(textName);
	int row = 0;
	string lineStr;
	while (getline(inf, lineStr))
	{
		// 打印整行字符串
		cout << lineStr << endl;
		// 存成二维表结构
		stringstream ss(lineStr);
		string str;
		// 按照逗号分隔
		int col = 0;
		while (getline(ss, str, ','))
		{
			dataset(row, col) = str;
			col++;
		}
		row++;
	}
	cout << dataset;
	cout << endl << "End reading";
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

	//for (set<string>::iterator it = checkSet.begin(); it != checkSet.end(); it++) cout << *it;
	return checkSet.size() == 1;
}

DecisionTree::DecisionTree()
{
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
	//cout << numEntries << endl;
	//cout << datasetCols << endl;
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
	//cout << d << endl;
	//cout << "find in: "<< axis << endl;
	//cout << "need satisfy: "<< value << endl;
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
	//cout << "the splitted dataset is:" << endl << splitted_dataset.middleRows(0, new_row_count) << endl;
	//cout << "the splitted dataset's middle row is:" << endl << splitted_dataset.middleRows(0, new_row_count) << endl;
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
			//cout << "For calculating the entropy, split dataset:" << endl;
			//cout << dataset << endl;
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

// 未测试，决定传入类标签中出现次数最多的标签
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
		//cout << "all the same,got leaf node:" << endl;
		//TreeNode* temp = &(TreeNode(classList(0,0)));
		//cout << *temp << endl;
		TreeNode* leaf =  new TreeNode(classList(0, 0)); //记得释放！！！！！！！！！
		return leaf;
	}
	// 递归边界条件二：遍历完所有特征时，返回出现次数最多的标签(string)构成的叶节点
	if (dataset.cols() == 1) {
		//cout << "finish mapping , the vote result:" << endl;
		//TreeNode temp = TreeNode(majorityCnt(classList));
		//cout << temp << endl;
		TreeNode* leaf = new TreeNode(majorityCnt(classList));
		return leaf;
	}
	// 选择数据集中最的最佳划分特征的索引
	int bestFeat = chooseBestFeatureToSplit(dataset); 
	// 即 labels[bestFeat];
	string bestFeatLabel = labels(bestFeat, 0);
	// cout << "The bestFeatLabel is :"<<bestFeatLabel<<endl;
	// 创建空节点；python version:	TreeNode myTree(bestFeatLabel);// { bestFeatLabel: {} };
	TreeNode* myTree = new TreeNode(bestFeatLabel);
	//删去labels中第bestFeat位的特征名
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
		// testVec的特征值符合决策树子节点的decision标签
		if (testVec(0, featIndex) == (*it).first)
		{
			//对应节点仍有其子节点，说明为中间节点，在该点递归调用本函数
			if ((*it).second->getChilds().size() != 0) classLabel = classify((*it).second, featLabels, testVec);
			else classLabel = (*it).second->getDecision();// 决策
		}
	}
	return classLabel;
}

ostream& operator<<(ostream& os, TreeNode tn)
{
	cout <<tn.decision;
	if(tn.childs.size()!=0) cout<< ":";
	for (map<string, TreeNode*>::iterator it = tn.childs.begin(); it != tn.childs.end(); ++it)
	{
		cout << "{ '" << (*it).first << "':" << *((*it).second) << "}";
	}
	return os;
}

Matrix<string, Dynamic, Dynamic> DecisionTree::getDataset() {
	return dataset;
}

void main()
{
	DecisionTree dt;
	Matrix<string, 4, 1> labels;
	Matrix<string, Dynamic, Dynamic> ds;
	/*
	labels << "No_Surfacing", "Flippers";
	ds.resize(5, 3);
	ds<< to_string(1), to_string(1), to_string(1),
		to_string(1), to_string(1), to_string(1),
		to_string(1), to_string(0), to_string(0),
		to_string(0), to_string(1), to_string(0),
		to_string(0), to_string(1), to_string(0);
	//cout << ds;
	TreeNode* tree = dt.createTree(ds,labels);
	cout << *tree << endl;
	Matrix<string, 2, 1> testVec;
	testVec << "1", "0";
	cout << "result:" << dt.classify(tree, labels, testVec);
	*/
	dt.readData("lense.csv");
	labels << "age", "prescript","astigmatic","tearRate";
	TreeNode* tree = dt.createTree(dt.getDataset(), labels);
	cout << *tree << endl;
	Matrix<string, 4, 1> testvec;
	testvec << "young", "myope", "no", "reduced";
	cout<<"The test result is:"<<dt.classify(tree, labels,testvec);
}
