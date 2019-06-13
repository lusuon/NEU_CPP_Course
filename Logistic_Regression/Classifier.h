#pragma once
#include <string>
#include <vector>
using namespace std;
/*
	Deveploer: Jackson Ma;
	Logistic Classifier for C++ course homework;
	Teacher:Mingwei Zhang;
	FIN 2019-5-28;
*/
/*
	#define M 345  //number of instances
	#define N 7    //number of attributes
*/
#define APLHA  0.01 // 新增宏，定义步长
#define maxCycle 500 //新增宏，定义迭代次数,500次较快；3000次左右准确率较高
#define TRAIN 0.7 //训练集比例
class Classifier
{
private:
	int rows = 0;
	int attr_nums = 0;
	vector< vector<double> > data; 
	
	double sigmoid(double z);//sigmoid函数，将输入数字映射到(0，1)之间
	vector< vector<double> > sigmoid(vector< vector<double> > z_vec);//针对向量的sigmoid函数，将列向量元素映射到(0，1)之间
	vector< vector<double> > matrix_multiple(vector< vector<double> > a, vector< vector<double> > b);// 矩阵乘法
	vector< vector<double> > matrix_multiple(double num, vector< vector<double> > m);// 矩阵数乘
	vector< vector<double> > matrix_subtract(vector< vector<double> > a, vector< vector<double> > b);// 矩阵减法
	vector< vector<double> > matrix_add(vector< vector<double> > a, vector< vector<double> > b);// 矩阵加法
	vector< vector<double> > update_weights(vector< vector<double> > weights, vector< vector<double> > error); // 迭代更新weight
	vector< vector<double> > transcope(vector< vector<double> > matrix); //矩阵转置
	vector< vector <double> > classify(vector< vector <double> > raw); // 将sigmoid函数处理后的数据转化为0，1的标签
public:
	vector< vector <double> > weights; // 权重
	vector< vector<double> > train_data; //训练集数据
	vector< vector <double> > train_label; //训练集标签
	vector< vector<double> > test_data; //测试集数据
	vector< vector <double> > test_label; //测试集标签
	Classifier(void);
	~Classifier(void);
	void ReadData(string textName);//读取textName文件中的数据至data中
	void preRead(string textName); // 预先读取文件，确认要创建的数组大小
	void OutputData(void); //输出data中的数据
	void OutputMatrix(vector< vector<double> > m);//输出矩阵
	void Preprocess(string textName);//预处理textName文件中的数据，存放到新文件“textName1”中
	vector< vector <double> > gradAscent();// 实现梯度提升算法，训练向量weight
	void devide_train_test();//将已有的数据集划分为训练集，测试集
	void test();//进行测试
	double check(vector< vector <double> > origin_labels, vector< vector <double> > classified_labels); // 计算分类的正确率
};