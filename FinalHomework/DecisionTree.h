#pragma once
#include <map>
#include <math.h>  
#include <iostream>
#include <vector>
#include <set>
#include "TreeNode.h"
using namespace std;
#include <Eigen/Dense>
using namespace Eigen;

class DecisionTree
{
private:
	Matrix<string, Dynamic, Dynamic> dataset; // 数据集
public:
	void readData(string textName);
	DecisionTree();
	~DecisionTree();
	double calcShannonEnt(Matrix<string, Dynamic, Dynamic>); // 计算给定数据集的香农熵
	Matrix<string, Dynamic, Dynamic> splitDataSet(Matrix<string, Dynamic, Dynamic>, int, string); // 划分数据集
	int chooseBestFeatureToSplit(Matrix<string, Dynamic, Dynamic>);// 选择最好特征划分的索引
	string majorityCnt(Array<string, Dynamic, 1>);
	TreeNode* createTree(Matrix<string, Dynamic, Dynamic>, Matrix<string, Dynamic, 1>); // 训练决策树
	string classify(TreeNode*, Matrix<string, Dynamic, 1>, Matrix<string, 1, Dynamic>); // test
	Matrix<string, Dynamic, Dynamic> getDataset();
};
