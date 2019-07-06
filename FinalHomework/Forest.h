#pragma once
#include "DecisionTree.h"
#include <vector>
#include <map>
using namespace std;

class Forest
{
private:
	vector<DecisionTree*> trees;
	map<string,set<string>> attr_value_dict;
	Matrix<string, Dynamic, Dynamic> base_dataset;
	Matrix<string, Dynamic, 1> base_labels;
	Matrix<string, Dynamic, Dynamic> train_set;
	Matrix<string, Dynamic, Dynamic> test_set;
	int select_feature = 0;
	int tree_nums = 0;
public:
	Forest(string,int sf, int tn);
	~Forest();
	string classify(Matrix<string, 1, Dynamic>);
	void readData(string textName);
	void test();
};

