#include <Eigen/Dense>
using namespace Eigen; 
#include "DecisionTree.h"
#include <map>
#include <set>
#include <vector>
#include <iostream>
using namespace std;


DecisionTree::DecisionTree()
{
}


DecisionTree::~DecisionTree()
{
}

double DecisionTree::calcShannonEnt(Matrix<double, Dynamic, Dynamic> dataset)
{
	int numEntries =  dataset.rows();
	int datasetCols = dataset.cols();
	map<int, double> labelCounts;
	// 最后一列 m*1 的标签向量
	//cout << numEntries << endl;
	//cout << datasetCols << endl;
	Matrix<double, Dynamic, 1> labels = dataset.col(datasetCols-1);
	for (int i = 0; i < numEntries; i++)
	{
		int key = labels.row(i).sum(); //第i个标签的值
		if (labelCounts.count(key) == 0) labelCounts.insert(map<int, double>::value_type(key, 0));
		labelCounts[key] ++;
	}
	double shannonEnt = 0;
	for (map<int, double>::iterator i = labelCounts.begin(); i != labelCounts.end(); i++)
	{
		int key = i->first;
		double prob = double(labelCounts[key]) / double(numEntries);
		shannonEnt -= prob * (log(prob) / log(2));
	}
	return shannonEnt;
}

Matrix<double, Dynamic, Dynamic> DecisionTree::splitDataSet(Matrix<double, Dynamic, Dynamic> dataset, int axis, int value)
{
	Matrix<double, Dynamic, Dynamic> splitted_dataset;
	splitted_dataset.resize(dataset.rows(), dataset.cols() - 1);
	int new_col_count = 0;
	int new_rows_count = 0;
	for(int row = 0;row<dataset.rows();row++)
	{
		if (dataset(row, axis) == value) {
			//取出该行除了指定列的其余部分
			new_col_count = 0;
			for (int col = 0; col < dataset.cols(); col++)
			{
				if (col != axis)
				{
					splitted_dataset(row,new_col_count) = dataset(row, col);
					//cout << dataset(row, col) << endl;
					new_col_count++;
				}
			}
			if (new_col_count != 0) new_rows_count++;
		}
	}
	return splitted_dataset.middleRows(0, new_rows_count);
}

int DecisionTree::chooseBestFeatureToSplit(Matrix<double, Dynamic, Dynamic> dataset)
{
	int numFeatures = dataset.cols() - 1;
	double baseEntropy = calcShannonEnt(dataset);
	double bestInfoGain = 0;
	int bestFeature = -1;
	for (int i = 0; i < numFeatures; i++)
	{
		// 为每列的特征值建立集合
		set<double> col_feature_value_set;
		for (int row = 0; row < dataset.rows(); row++) col_feature_value_set.insert(dataset(row, i));
		// 每一列的信息熵
		double newEntropy = 0;
		for (set<double>::iterator it = col_feature_value_set.begin(); it != col_feature_value_set.end(); ++it)
		{
			Matrix<double, Dynamic, Dynamic> subDataSet = splitDataSet(dataset, i, *it);
			double prob = double(subDataSet.rows()) / double(dataset.rows());
			newEntropy += prob * calcShannonEnt(subDataSet);
		}
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
double DecisionTree::majorityCnt(vector<double> classList)
{
	map<double, int> classCount;
	for (vector<double>::iterator it = classList.begin(); it != classList.end(); ++it)
	{
		if (classCount.count(*it) == 0) classCount.insert(map<double, int>::value_type(*it, 0));
		classCount[*it] ++;
	}
	int maxCount = 0;
	pair<double, int> maxp;
	// 寻找map中value（出现次数）最大者
	for (map<double,int>::iterator it = classCount.begin(); it != classCount.end(); ++it)
	{
		pair<double,int> current_pair = (*it);
		if (current_pair.second >= maxCount)
		{
			maxCount = current_pair.second;
			maxp = current_pair;
		}
	}
	return maxp.first;
}

void main()
{
	DecisionTree dt;
	Matrix<double, 5, 3> ds;
	
	ds << 1, 1, 1,
		1, 1, 1,
		1, 0, 0,
		0, 1, 0,
		0, 1, 0;
	cout << dt.chooseBestFeatureToSplit(ds);
}
