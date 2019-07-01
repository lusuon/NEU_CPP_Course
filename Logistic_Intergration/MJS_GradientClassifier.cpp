#include "MJS_GradientClassifier.h"
#include <iostream>
using namespace std;

MJS_GradientClassifier::MJS_GradientClassifier(int row ,int col):MJS_Classifier(row,col)
{
}


MJS_GradientClassifier::~MJS_GradientClassifier()
{
}


void MJS_GradientClassifier::MJS_Train(void)
{
	cout << "Training with gradient." << endl;
	for (int i = 0; i < MJS_N; i++)
		MJS_weights[i] = 0;
	for (int p = 0; p < MJS_PASS; p++)
	{
		MJS_Gradient();
		for (int i = 0; i < MJS_N; i++)
		{
			MJS_weights[i] += MJS_ALPHA * MJS_nabla[i];
		}
	}
	return;
}
