#include "Classifier.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
#include <vector>
using namespace std;
/*
	Deveploer: Jackson Ma;
	Logistic Classifier for C++ course homework;
	Teacher:Mingwei Zhang;
	FIN 2019-5-28;
*/
vector< vector<double> > Classifier::matrix_subtract(vector< vector<double> > a, vector< vector<double> > b)
{
	int a_rows = a.size();
	int a_cols = a[0].size();
	int b_rows = b.size();
	int b_cols = b[0].size();
	vector< vector<double> > result(a_rows, vector<double>(a_cols));
	if ((a_rows == b_rows) && (a_cols == b_cols)) {
		for (int i = 0; i < a_rows; i++) {
			for (int j = 0; j < a_cols; j++) {
				result[i][j] += (a[i][j] - b[i][j]);
			}
		}
	}
	else {
		//cout << "Two matrix have different sizes." << endl;
	}
	return result;
}

vector<vector<double>> Classifier::matrix_add(vector<vector<double>> a, vector<vector<double>> b)
{
	int a_rows = a.size();
	int a_cols = a[0].size();
	int b_rows = b.size();
	int b_cols = b[0].size();
	vector< vector<double> > result(a_rows, vector<double>(a_cols));
	if ((a_rows == b_rows) && (a_cols == b_cols)) {
		for (int i = 0; i < a_rows; i++) {
			for (int j = 0; j < a_cols; j++) {
				result[i][j] += (a[i][j] + b[i][j]);
			}
		}
	}
	else {
		cout << "Two matrix have different sizes." << endl;
	}
	return result;
}

vector< vector<double> > Classifier::transcope(vector<vector<double>> matrix)
{
	int rows = matrix.size();
	int cols = matrix[0].size();
	vector< vector<double> > t(cols, vector<double>(rows));
	double temp = 0;
	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			t[col][row] = matrix[row][col];
		}
	}
	return t;
}

vector< vector<double> > Classifier::update_weights(vector<vector<double>> weights, vector<vector<double>> error)
{
	//weights += alpha * data.transcope() * error;
	vector< vector<double> > newWeights(weights.size(), vector<double>(weights[0].size()));
	newWeights = matrix_add(weights,matrix_multiple(matrix_multiple(APLHA, transcope(train_data)), error));
	return newWeights;
}

double Classifier::sigmoid(double z)
{
	return 1/(1+exp(-z));
}

vector< vector<double> > Classifier::sigmoid(vector< vector<double> > matrix)
{	
	int row = matrix.size();
	int col = matrix[0].size();
	vector< vector<double> > result(row,vector<double>(col));
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			result[i][j] = sigmoid(matrix[i][j]);
		}
	}
	return result;
}

vector<vector<double>> Classifier::matrix_multiple(vector<vector<double>> a, vector<vector<double>> b)
{
	int a_rows = a.size();
	int a_cols = a[0].size();
	int b_rows = b.size();
	int b_cols = b[0].size();
	// cout << a_rows << " " << a_cols << " " << b_rows << " " << b_cols << " " << endl;
	vector < vector<double> >result(a_rows, vector<double>(b_cols));
	if (a_cols == b_rows) {
		for (int ar = 0; ar < a_rows; ar++) {
			for (int bc = 0; bc < b_cols; bc++) {
				for (int ac = 0; ac < a_cols; ac++) {
					result[ar][bc] += a[ar][ac] * b[ac][bc];
				}
			}
		}
		//cout<< "Success." << endl;
	} else {
		//cout << "Two matrix cannot be multipled." << endl;
	}
	return result;
}

vector< vector<double> > Classifier::matrix_multiple(double num, vector<vector<double>> m)
{
	int rows = m.size();
	int cols = m[0].size();
	vector< vector<double> > result(rows, vector<double>(cols));
	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			result[row][col] = num * m[row][col];
		}
	}
	return result;
}

Classifier::Classifier(void)
{
}


Classifier::~Classifier(void)
{
}



void Classifier::ReadData(string textName)
{
	cout << "start reading" << endl;
	ifstream inf(textName);
	char c;
	int row = 0;
	while (inf.peek() != EOF) {
		for (int i = 1; i <= attr_nums ; i++)
		{
			data[row][0] = 1;
			inf >> data[row][i];
			inf.get(c);
		}
		row++;
	}
	inf.close();

	cout << "fin reading" << endl;
}

void Classifier::preRead(string textName)
{
	ifstream in(textName);
	string filename;
	string line;
	if (in) // 有该文件
	{
		getline(in, line);
		attr_nums = count(line.begin(), line.end(), ',') + 1;
		rows = 1;
		while (getline(in, line)) {
			rows++;
		}
		vector< vector<double> > init_data(rows,vector<double>(attr_nums+1) );
		vector< vector <double> > init_label(rows, vector <double>(1));
		data = init_data;
		cout << "The dataset has " << rows << "rows." << endl;
		cout << "The dataset has " << attr_nums << "attributes." << endl;
	}
	else // 没有该文件
	{
		cout << "no such file" << endl;
	}
}

void Classifier::OutputData(void)
{
	cout<<left;
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<attr_nums+1;j++)
			cout<<setw(10)<<data[i][j]<<"  ";
		cout<<endl;
	}
}

void Classifier::OutputMatrix(vector<vector<double>> m)
{
	int row = m.size();
	int col = m[0].size();
	cout << left;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			cout << setw(10) << m[i][j] << "  ";
		cout << endl;
	}
}

void Classifier::Preprocess(string textName)
{
	ReadData(textName);
	vector<vector<double>>maxMin(attr_nums, vector<double>(2));
	//double maxMin[attr_nums][2];
	//cout<<"init maxMin"<<endl;
	for(int i=0;i< attr_nums ;i++)
	{
		maxMin[i][0]=-100000;
		maxMin[i][1]=100000;
	}

	for(int row=0;row<rows;row++)
		for(int i=1;i< attr_nums;i++)
		{
			if(data[row][i] > maxMin[i][0]) 
				maxMin[i][0]=data[row][i];
			if(data[row][i] < maxMin[i][1]) 
				maxMin[i][1]=data[row][i];
		}
	cout << "finish maxMin" << endl;
	ofstream outs("1"+textName);
	double d;
	for(int row=0;row<rows;row++){
		for(int i=1;i< attr_nums;i++)
		{
			//d = data[row][i]; //尝试不标准化
			d = (data[row][i]-maxMin[i][1])/(maxMin[i][0]-maxMin[i][1]);
			outs<<d;
			outs.put(',');
		}
		outs<<data[row][attr_nums]-1; //针对liver数据集，转换类标为0和1
		outs.put('\n');
    }
	outs.close();
}

vector< vector <double> > Classifier::gradAscent()
{
	int train_rows = train_data.size();
	int train_attrs = train_data[0].size();
	weights = vector< vector <double> >(train_attrs,vector<double>(1,1)); // 回归系数向量
	vector< vector<double> > h(1, vector<double>(train_rows, 0)); // 列向量
	vector< vector<double> > error(1, vector<double>(train_rows, 0)); // 列向量
	for (int i = 0; i < maxCycle; i++) {
		//cout << "Calculating mid." << endl;
		vector< vector<double> > mid = matrix_multiple(train_data,weights);
		//cout << "Calculating h." << endl;
		vector< vector<double> > h = sigmoid(mid);
		//cout << "Calculating error." << endl;
		error = matrix_subtract(train_label,h);//OK
		//cout << "updating." << endl;
		weights = update_weights(weights,error);
		//cout << "updated" << endl;
		
		/*
		cout << "current weight: ";
		
		for (int i = 0; i < train_attrs; i++) {
			cout << weights[i][0] << " " ;
		}
		cout << endl;
		*/
		//打印迭代后的weight
		//weights += alpha * data.transcope() * error;
	}
	return weights;
}

void Classifier::devide_train_test()
{
	int trains = ceil(rows * TRAIN);
	int test = rows - trains;
	train_data = vector< vector<double> >(trains, vector<double>(attr_nums-1));
	train_label = vector< vector<double> >(trains, vector<double>(1));
	test_data = vector< vector<double> >(rows - trains, vector<double>(attr_nums - 1));
	test_label = vector< vector<double> >(rows - trains, vector<double>(1));
	int count = 0;
	for (int row = 0; row < rows; row++) {
		if (row <= trains-1) {
			cout << row << " of " << trains << endl;
			cout << train_data.size() << endl;
			train_data[row] = vector<double>(data[row].begin() + 1, data[row].begin() + 7);
			train_label[row][0] = data[row][attr_nums];
		}
		else {
			test_data[count] = vector<double>(data[row].begin() + 1, data[row].begin() + 7);
			test_label[count][0] = data[row][attr_nums];
			count++;
		}
	}
}

void Classifier::test()
{
	vector< vector<double> > label = classify(sigmoid(matrix_multiple(test_data, weights)));
	//OutputMatrix(label);
	cout << "test_set correctness:" <<check(test_label,label)<< endl;	
}

vector<vector<double>> Classifier::classify(vector<vector<double>> raw)
{
	for (int i = 0; i < raw.size(); i++) {
		if (raw[i][0] > 0.5) raw[i][0] = 1;
		else raw[i][0] = 0;
	}
	return raw;
}

double Classifier::check(vector<vector<double>> origin_labels, vector<vector<double>> classified_labels)
{
	//假定标签为n*1的二维向量
	double rows = origin_labels.size();
	double correct = 0;
	for (int i = 0; i < rows; i++) {
		int o = origin_labels[i][0];
		int c = classified_labels[i][0];

		if (o == c) correct++;
	}
	return correct / rows ;
}
