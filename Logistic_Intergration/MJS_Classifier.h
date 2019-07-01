 #pragma once
#include <string>
using namespace std;

class MJS_Classifier
{
protected:
	int MJS_M; //number of instances
	int MJS_N; //number of attributes
	int MJS_PASS; //number of training passes
	double MJS_ALPHA; //number of training passes
	double* MJS_data;
	double* MJS_weights;
	double* MJS_nabla;
public:
	MJS_Classifier(int rows, int cols);
	~MJS_Classifier(void);
	void MJS_ReadData(string textName);
	//读取textName文件中的数据至data中
	void MJS_OutputData(void);
	//输出data中的数据
	void MJS_Preprocess(string textName);
	//预处理textName文件中的数据，存放到新文件“textName1”中
	
protected:
	double MJS_WtX(int row);
	double MJS_Sigmoid(int row);
	void MJS_Gradient(void);
public:
	virtual void MJS_Train(void) = 0;
	void MJS_Test(void);
	void MJS_SetParameter(int pass, double alpha);
};

