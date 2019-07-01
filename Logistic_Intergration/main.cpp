#include <iostream>
#include "MJS_Classifier.h"
#include "MJS_GradientClassifier.h"
#include "MJS_NewtonClassifier.h"
using namespace std;

void main()
{
	MJS_NewtonClassifier c(345,7);
	c.MJS_Preprocess("bupa.txt");
	c.MJS_ReadData("1bupa.txt");
	c.MJS_SetParameter(10,0.01);
	c.MJS_Train();
	cout << "Newton with pass = 10, alpha = 0.01 :";
	c.MJS_Test();
	cout << endl;

	MJS_GradientClassifier g(345, 7);
	g.MJS_Preprocess("bupa.txt");
	g.MJS_ReadData("1bupa.txt");
	g.MJS_SetParameter(1000, 0.01);
	g.MJS_Train();
	cout << "Gradient with pass = 1000, alpha = 0.01 :";
	g.MJS_Test();
	cout << endl;
	system("pause");
}