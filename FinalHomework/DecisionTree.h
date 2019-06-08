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
	Matrix<double, Dynamic, Dynamic> dataset; // ���ݼ�
public:
	DecisionTree();
	~DecisionTree();
	double calcShannonEnt(Matrix<double, Dynamic, Dynamic>); // ����������ݼ�����ũ��
	Matrix<double, Dynamic, Dynamic> splitDataSet(Matrix<double, Dynamic, Dynamic>, int axis, int value); // �������ݼ�
	int chooseBestFeatureToSplit(Matrix<double, Dynamic, Dynamic>);// ѡ������������ֵ�����
	double majorityCnt(vector<double>);
	createTree(Matrix<double, Dynamic, Dynamic>, Matrix<double, Dynamic, 1>);
};