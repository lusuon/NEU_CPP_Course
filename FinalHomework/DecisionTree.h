#pragma once
#include <map>
#include <math.h>  
#include <iostream>
#include <vector>
#include <set>
using namespace std;
#include <Eigen/Dense>
using namespace Eigen;

class DecisionTree
{
private:
	Matrix<double, Dynamic, Dynamic> dataset; // 数据集
public:
	DecisionTree();
	~DecisionTree();
	double calcShannonEnt(Matrix<double, Dynamic, Dynamic>); // 计算给定数据集的香农熵
	Matrix<double, Dynamic, Dynamic> splitDataSet(Matrix<double, Dynamic, Dynamic>, int axis, int value); // 划分数据集
	int chooseBestFeatureToSplit(Matrix<double, Dynamic, Dynamic>);// 选择最好特征划分的索引
	double majorityCnt(vector<double>);
	createTree(Matrix<double, Dynamic, Dynamic>, Matrix<double, Dynamic, 1>);
};