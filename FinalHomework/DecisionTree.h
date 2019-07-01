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
	Matrix<string, Dynamic, Dynamic> dataset; // ���ݼ�
public:
	void readData(string textName);
	DecisionTree();
	~DecisionTree();
	double calcShannonEnt(Matrix<string, Dynamic, Dynamic>); // ����������ݼ�����ũ��
	Matrix<string, Dynamic, Dynamic> splitDataSet(Matrix<string, Dynamic, Dynamic>, int, string); // �������ݼ�
	int chooseBestFeatureToSplit(Matrix<string, Dynamic, Dynamic>);// ѡ������������ֵ�����
	string majorityCnt(Array<string, Dynamic, 1>);
	TreeNode* createTree(Matrix<string, Dynamic, Dynamic>, Matrix<string, Dynamic, 1>); // ѵ��������
	string classify(TreeNode*, Matrix<string, Dynamic, 1>, Matrix<string, 1, Dynamic>); // test
	Matrix<string, Dynamic, Dynamic> getDataset();
};
