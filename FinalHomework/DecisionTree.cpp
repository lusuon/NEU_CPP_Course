#include <Eigen/Dense>
using namespace Eigen; 
#include <map>
#include <set>
#include <iostream>
#include <fstream>
using namespace std;
#include "DecisionTree.h"

/*
	��������ʵ��
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
		// ��ӡ�����ַ���
		cout << lineStr << endl;
		// ��ɶ�ά��ṹ
		stringstream ss(lineStr);
		string str;
		// ���ն��ŷָ�
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


// ɾ�������ָ����
Matrix<string, Dynamic, Dynamic> removeRow(Matrix<string, Dynamic, Dynamic> matrix, int rowToRemove)
{
	int numRows = matrix.rows() - 1;
	int numCols = matrix.cols();

	if (rowToRemove < numRows)
		matrix.block(rowToRemove, 0, numRows - rowToRemove, numCols) = matrix.block(rowToRemove + 1, 0, numRows - rowToRemove, numCols);
	matrix.conservativeResize(numRows, numCols);
	return matrix;
}

// �жϾ�����Ԫ���Ƿ�ȫ��һ��
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

// ����������ݼ�����ũ��
double DecisionTree::calcShannonEnt(Matrix<string, Dynamic, Dynamic> dataset)
{
	int numEntries =  dataset.rows();
	int datasetCols = dataset.cols();
	map<string, int> labelCounts;
	// ���һ�� m*1 �ı�ǩ����
	//cout << numEntries << endl;
	//cout << datasetCols << endl;
	Matrix<string, Dynamic, 1> labels = dataset.col(datasetCols-1);
	for (int i = 0; i < numEntries; i++)
	{
		string key = labels(i,0); //��i����ǩ��ֵ
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

//��ָ�����ϸ��ݸ���ֵ�����ݼ����л��֣�ѡ������ָ����Ҫ��ֵ�Ĳ��֣���ɾȥָ����
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
			//ȡ�����г���ָ���е����ಿ��
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

// ѡ�񻮷ָ����ݼ�����������е�����
int DecisionTree::chooseBestFeatureToSplit(Matrix<string, Dynamic, Dynamic> dataset)
{
	int numFeatures = dataset.cols() - 1; //���ݼ���������
	double baseEntropy = calcShannonEnt(dataset); //�������ݼ�����ũ��
	double bestInfoGain = 0; //��Ϣ����
	int bestFeature = -1; //��ʼ����ѻ�������
	for (int i = 0; i < numFeatures; i++) //����ÿһ��
	{
		// Ϊÿ�е�����ֵ��������
		set<string> col_feature_value_set; 
		for (int row = 0; row < dataset.rows(); row++) col_feature_value_set.insert(dataset(row, i));
		// ����ÿһ�е���Ϣ��
		double newEntropy = 0;
		for (set<string>::iterator it = col_feature_value_set.begin(); it != col_feature_value_set.end(); ++it)
		{
			//cout << "For calculating the entropy, split dataset:" << endl;
			//cout << dataset << endl;
			Matrix<string, Dynamic, Dynamic> subDataSet = splitDataSet(dataset, i, *it);
			double prob = double(subDataSet.rows()) / double(dataset.rows());
			newEntropy += prob * calcShannonEnt(subDataSet);
		}
		// ������Ϣ���棬���������Ϊ��ѻ���
		double infoGain = baseEntropy - newEntropy;
		if (infoGain > bestInfoGain)
		{
			bestInfoGain = infoGain;
			bestFeature = i;
		}
	}
	return bestFeature;
}

// δ���ԣ������������ǩ�г��ִ������ı�ǩ
string DecisionTree::majorityCnt(Array<string,Dynamic,1> classList)
{
	// ������ֱ�ǩ���ִ�����map���Ը���ǩ���м���
	int rows = classList.rows();
	map<string, int> classCount;
	for (int row = 0; row < rows; row++)
	{
		string label = classList(row, 0);
		if (classCount.count(label) == 0) classCount.insert(map<string, int>::value_type(label, 0));
		classCount[label] ++;
	}

	// Ѱ�ұ�ǩ�г��������
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


// labelsΪ�ж�Ӧ��������
TreeNode* DecisionTree::createTree(Matrix<string, Dynamic, Dynamic> dataset, Matrix<string, Dynamic, 1> labels)
{
	// ȡdataset���һ�У���ȡ��ǰ�������ݼ��ڵı�ǩ��������δ���ԣ�
	Matrix<string, Dynamic, 1> classList = dataset.rightCols(1); 
	// �ݹ�߽�����һ����ǩ��ȫ��ͬ�����ٻ��֣����ظñ�ǩ��string)���ɵ�Ҷ�ڵ�
	if (isAllElementTheSame(classList)) {
		//cout << "all the same,got leaf node:" << endl;
		//TreeNode* temp = &(TreeNode(classList(0,0)));
		//cout << *temp << endl;
		TreeNode* leaf =  new TreeNode(classList(0, 0)); //�ǵ��ͷţ�����������������
		return leaf;
	}
	// �ݹ�߽�����������������������ʱ�����س��ִ������ı�ǩ(string)���ɵ�Ҷ�ڵ�
	if (dataset.cols() == 1) {
		//cout << "finish mapping , the vote result:" << endl;
		//TreeNode temp = TreeNode(majorityCnt(classList));
		//cout << temp << endl;
		TreeNode* leaf = new TreeNode(majorityCnt(classList));
		return leaf;
	}
	// ѡ�����ݼ��������ѻ�������������
	int bestFeat = chooseBestFeatureToSplit(dataset); 
	// �� labels[bestFeat];
	string bestFeatLabel = labels(bestFeat, 0);
	// cout << "The bestFeatLabel is :"<<bestFeatLabel<<endl;
	// �����սڵ㣻python version:	TreeNode myTree(bestFeatLabel);// { bestFeatLabel: {} };
	TreeNode* myTree = new TreeNode(bestFeatLabel);
	//ɾȥlabels�е�bestFeatλ��������
	Matrix<string, Dynamic, 1> new_labels = removeRow(labels,bestFeat); 

	// �õ���ѻ����ڵ����е�featureֵ����dataset�ĵ�bestFeat��
	Matrix<string,Dynamic,1> featValues = dataset.col(bestFeat);
	set<string> uniqueVals;
	for (int row = 0; row < featValues.rows(); row++)
	{
		uniqueVals.insert(featValues(row,0));
	}
	// ������ѡ����������������ֵ����ÿ�������ϵݹ���ñ�����
	for (set<string>::iterator it = uniqueVals.begin(); it != uniqueVals.end(); ++it)
	{
		//��Ҫ�����µ����ǩ����֤ÿ��createTree ���ı�ԭʼ�б�����
		Matrix<string,Dynamic,1> subLabels = new_labels; 
		myTree->addChild((*it), createTree(splitDataSet(dataset, bestFeat, *it), subLabels));
		// value �ǵ�����ָ����ָ���ֵ����ʾ��ѡ������������
		// myTree[bestFeatLabel][value] = createTree(splitDataSet(dataset, bestFeat, value), subLabels); 
	}
	return myTree;
}

string DecisionTree::classify(TreeNode* tree, Matrix<string, Dynamic, 1> featLabels, Matrix<string, 1, Dynamic> testVec)
{
	string classLabel; // ��ʼ�����ر�ǩ���
	string decision = tree->getDecision();
	map<string,TreeNode*> childs= tree->getChilds();
	// ��ȡ��ǰ�����߱�ǩ�����ݼ��ڵ���λ��
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
		// testVec������ֵ���Ͼ������ӽڵ��decision��ǩ
		if (testVec(0, featIndex) == (*it).first)
		{
			//��Ӧ�ڵ��������ӽڵ㣬˵��Ϊ�м�ڵ㣬�ڸõ�ݹ���ñ�����
			if ((*it).second->getChilds().size() != 0) classLabel = classify((*it).second, featLabels, testVec);
			else classLabel = (*it).second->getDecision();// ����
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
