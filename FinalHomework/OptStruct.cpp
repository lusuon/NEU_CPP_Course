#include "OptStruct.h"
#include<Eigen/Eigen>
using namespace Eigen;


OptStruct::OptStruct()
{
}

OptStruct::OptStruct(Matrix<double, Dynamic, Dynamic> dataMatIn, Matrix<double, Dynamic, 1> classLabels, double C, double toler)
{
	x = dataMatIn;
	labelMat = classLabels;
	C = C;
	tol = toler;
	//m = x.rows;
	alphas = VectorXd::Zero(m);
	b = 0;
	eCache = MatrixXd::Zero(m, 2);
}


OptStruct::~OptStruct()
{
}

// δ����
double calcEk(OptStruct os, int k)
{
	//alphas �� ��ǩ���� element-wise ���
	Matrix<double, 1, Dynamic> 	wT = os.alphas.cwiseProduct(os.labelMat).transpose(); // 1*m ������ 
	Matrix<double, Dynamic, 1> feature = os.x * os.x.middleRows(k, k).transpose();// m*1 ������
	double fXk = double(wT * feature) + os.b;
	double Ek = fXk - (os.labelMat.middleRows(k, k)).sum();
	return Ek;
}

// δ����

