#pragma once
#include<Eigen/Eigen>
using namespace Eigen;

/*
	ʵ��SVM��Ŀǰ��ǳ
*/
class OptStruct
{
private:
	Matrix<double, Dynamic, Dynamic> x;
	Matrix<double, Dynamic, 1> labelMat;
	double C; // ���ơ���󻯼����������֤�󲿷ֵ��ĺ������<1.0������Ŀ��֮���Ȩ�أ�
	double tol; // ����  
	double b;
	int m;
	Matrix<double, Dynamic, 1> alphas;
	Matrix<double, Dynamic, 2> eCache; // ����
public:
	OptStruct();
	OptStruct(Matrix<double, Dynamic, Dynamic> dataMatIn, Matrix<double, Dynamic, 1> classLabels, double C, double toler);
	~OptStruct();
	friend double calcEk(OptStruct os, int k);
};
double calcEk(OptStruct os, int k);
