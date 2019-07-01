#pragma once
#include "MJS_Classifier.h"
class MJS_NewtonClassifier :
	public MJS_Classifier
{
private:
	double* MJS_hessian;
public:
	MJS_NewtonClassifier(int row, int col);
	virtual ~MJS_NewtonClassifier();

private:
	void MJS_Hessian(void);
public:
	void MJS_Train(void);
};

