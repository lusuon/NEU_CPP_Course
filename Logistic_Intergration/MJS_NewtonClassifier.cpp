#include "MJS_NewtonClassifier.h"
#include "MJS_MyMatrix.h"
#include <iostream>
using namespace std;


MJS_NewtonClassifier::MJS_NewtonClassifier(int row, int col):MJS_Classifier(row,col)
{
	MJS_hessian = new double[MJS_N * MJS_N];
}


MJS_NewtonClassifier::~MJS_NewtonClassifier()
{
	delete[] MJS_hessian;
}



void MJS_NewtonClassifier::MJS_Hessian(void)
{
	for (int i = 0; i < MJS_N; i++)
		for (int j = 0; j < MJS_N; j++)
			MJS_hessian[i * MJS_N + j] = 0;

	for (int row = 0; row < MJS_M; row++)
	{
		double JS_ans = MJS_Sigmoid(row) * (MJS_Sigmoid(row) - 1);
		for (int i = 0; i < MJS_N; i++)
			for (int j = 0; j < MJS_N; j++)
				MJS_hessian[i * MJS_N + j] += JS_ans * MJS_data[row * (MJS_N + 1) + i] * MJS_data[row * (MJS_N + 1) + j];
	}
	return;
}




void MJS_NewtonClassifier::MJS_Train(void)
{
	cout << "Training with ." << endl;
	double* JS_temp = new double[MJS_N * MJS_N];
	double* JS_del = new double[MJS_N];
	for (int i = 0; i < MJS_PASS; i++)
	{
		MJS_Gradient();
		MJS_Hessian();
		if (MJS_Inverse(MJS_hessian, JS_temp, MJS_N) == false)
		{
			cout << "There is no Inverse matrix" << endl;
			exit(1);
		}
		MJS_Multiply(JS_temp, MJS_nabla, JS_del, MJS_N, MJS_N, 1);
		for (int i = 0; i < MJS_N; i++)
		{
			MJS_weights[i] -= JS_del[i];
		}
	}
	return;
}
