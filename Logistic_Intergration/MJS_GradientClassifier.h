#pragma once
#include "MJS_Classifier.h"
class MJS_GradientClassifier :
	public MJS_Classifier
{
private:
public:
	MJS_GradientClassifier(int row, int col);
	virtual ~MJS_GradientClassifier();
	void MJS_Train();
};

