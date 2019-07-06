#include "Forest.h"
#include "tool.h"
/*
	使用bagging法创建随机森林
*/


void Forest::readData(string textName)
{
	vector<int> size = CountFile(textName);
	base_dataset.resize(size[0] - 1, size[1]);
	base_labels.resize(size[1] - 1);
	ifstream inf(textName);
	int row = 0;
	string lineStr;
	while (getline(inf, lineStr))
	{

		// 存成二维表结构
		stringstream ss(lineStr);
		string str;
		// 按照逗号分隔
		int col = 0;
		while (getline(ss, str, ','))
		{
			if (!row) {
				if (col < size[1] - 1) {
					this->base_labels(col, 0) = str;
				}
			}
			else base_dataset(row - 1, col) = str;
			col++;
		}
		row++;
	}
	for (int i = 0; i < base_labels.size(); i++)
	{
		Matrix<string, Dynamic, 1> col = base_dataset.col(i);
		for(int j = 0;j<base_dataset.rows();j++)
		{
			attr_value_dict[base_labels[i]].insert(col(j,0));
		}
	}

}

void Forest::test()
{
	double correct = 0;
	for (int i = 0; i < test_set.rows(); i++)
	{
		Matrix <string, 1, Dynamic> vec = test_set.row(i);
		Matrix <string, 1, Dynamic> feature = vec.middleCols(0, vec.cols()-1);
		string result = vec(0, vec.cols()-1);
		if (classify(feature) == result) correct++;
	}
	cout << "The total correctness of the random forest: " << correct / (double)test_set.rows();
}


Forest::Forest(string fnileName,int sf, int tn) :select_feature(sf), tree_nums(tn)
{
	readData(fnileName);
	int margin = base_dataset.rows() * TRAIN_RATE;//实现的时间有限，不做随机划分
	train_set = base_dataset.middleRows(0,margin);
	test_set = base_dataset.bottomRows(base_dataset.rows() - margin);
	for (int i = 0; i < tree_nums; i++)
	{
		cout << "A sub tree created: " << endl;
		DecisionTree* t = new DecisionTree(randomSeperate(base_dataset,base_labels,select_feature), randomLabel(select_feature,base_labels.rows()-1,base_labels));
		//t->createTree();
		trees.push_back(t);
	}
}

Forest::~Forest()
{
	for (vector<DecisionTree*>::iterator it = trees.begin(); it != trees.end(); it++)
	{
		delete (*it);
	}
}

string Forest::classify(Matrix<string, 1, Dynamic> testvec)
{
	map<string, int> votes;
	for (vector<DecisionTree*>::iterator it = trees.begin(); it != trees.end(); it++)
	{
		Matrix<string, 1, Dynamic> vec_processed;
		vec_processed.resize(1, (*it)->getLabels().size());
		int processed_num = 0;
		for (int i = 0; i < testvec.size(); i++)
		{
			for (map<string, set<string>>::iterator it = attr_value_dict.begin(); it != attr_value_dict.end(); it++)
			{
				if ((*it).second.count(testvec(i))) vec_processed(0, processed_num) = testvec(i); processed_num++; break;
			}
		}
		string result = (*it)->classify(vec_processed);
		if (!votes.count(result)) votes.insert(map<string, int>::value_type(result, 0));
		votes[result] ++;
	}

	int maxCount = 0;
	pair<string, int> maxp;
	for (map<string, int>::iterator it = votes.begin(); it != votes.end(); it++)
	{
		pair<string, int> current_pair = (*it);
		if (current_pair.second >= maxCount)
		{
			maxCount = current_pair.second;
			maxp = current_pair;
		}
	}
	//投票，选出最大者
	return maxp.first;
}


void main()
{
	Forest f = Forest("lense.csv", 2, 2);
	f.test();
}
