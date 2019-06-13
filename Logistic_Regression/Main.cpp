#include <iostream>
#include <vector>
#include "Classifier.h"
using namespace std;

void main()
{
	// todo: 更正训练向量、测试标签的选取，在readData方法内，同时更改preRead定义的函数，预留标签
	Classifier c1;
	cout << "bupa" << endl;
	c1.preRead("bupa.txt");
	c1.Preprocess("bupa.txt");
	cout << "1bupa" << endl;
	c1.ReadData("1bupa.txt");
	c1.OutputData();
	cout << "start dividing" << endl;
	c1.devide_train_test();
	/*
	cout << "train data:" << endl;
	c1.OutputMatrix(c1.train_data);
	cout << "train label:" << endl;
	c1.OutputMatrix(c1.train_label);
	cout << "test data:" << endl;
	c1.OutputMatrix(c1.test_data);
	cout << "test label" << endl;
	c1.OutputMatrix(c1.test_label);
	*/
	vector< vector<double> > weights= c1.gradAscent(); // 使用梯度上升法，训练w
	c1.test();//根据训练的w
	system("pause");
}