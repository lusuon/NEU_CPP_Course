#pragma once
#include<Eigen/Eigen>
using namespace Eigen;

/*
	实现SVM，目前搁浅
*/
class OptStruct
{
private:
	Matrix<double, Dynamic, Dynamic> x;
	Matrix<double, Dynamic, 1> labelMat;
	double C; // 控制“最大化间隔”、“保证大部分点间的函数间隔<1.0”两个目标之间的权重；
	double tol; // 容忍  
	double b;
	int m;
	Matrix<double, Dynamic, 1> alphas;
	Matrix<double, Dynamic, 2> eCache; // 误差缓存
public:
	OptStruct();
	OptStruct(Matrix<double, Dynamic, Dynamic> dataMatIn, Matrix<double, Dynamic, 1> classLabels, double C, double toler);
	~OptStruct();
	friend double calcEk(OptStruct os, int k);
};
double calcEk(OptStruct os, int k);
