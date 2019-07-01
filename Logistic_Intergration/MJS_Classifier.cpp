#include "MJS_Classifier.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include "MJS_MyMatrix.h"

using namespace std;


MJS_Classifier::MJS_Classifier(int rows, int cols)
{
	MJS_M = rows;
	MJS_N = cols;
	MJS_data = new double[MJS_M*(MJS_N+1)];
	MJS_weights = new double[MJS_N];
	MJS_nabla = new double[MJS_N];
	for(int i=0;i< MJS_N;i++)
		MJS_weights[i] = 0;
}


MJS_Classifier::~MJS_Classifier(void)
{
	delete [] MJS_data;
	delete [] MJS_weights;
	delete [] MJS_nabla;
}

void MJS_Classifier::MJS_ReadData(string textName)
{
	ifstream inf(textName);
	char c;
	int row=0;
	while(inf.peek()!=EOF){
		for(int i=1;i<= MJS_N;i++)
		{
			MJS_data[row*(MJS_N+1)+0]=1;
			inf>> MJS_data[row*(MJS_N+1)+i];
			inf.get(c);
		}
		row++;
	}
	inf.close();
}

void MJS_Classifier::MJS_OutputData(void)
{
	cout<<left;
	for(int i=0;i< MJS_M;i++)
	{
		for(int j=0;j< MJS_N+1;j++)
			cout<<setw(10)<< MJS_data[i*(MJS_N+1)+j]<<"  ";
		cout<<endl;
	}
}

void MJS_Classifier::MJS_Preprocess(string textName)
{
	MJS_ReadData(textName);
	double* JS_maxMin = new double[MJS_N*2];
	
	for(int i=0;i< MJS_N;i++)
	{
		JS_maxMin[i*2+0]=-100000;
		JS_maxMin[i*2+1]=100000;
	}

	for(int row=0;row< MJS_M;row++)
		for(int i=1;i< MJS_N;i++)
		{
			if(MJS_data[row*(MJS_N+1)+i] > JS_maxMin[i*2+0])
				JS_maxMin[i*2+0]=MJS_data[row*(MJS_N+1)+i];
			if(MJS_data[row*(MJS_N+1)+i] < JS_maxMin[i*2+1])
				JS_maxMin[i*2+1]=MJS_data[row*(MJS_N+1)+i];
		}
	
	ofstream outs("1"+textName);
	double d;
	for(int row=0;row<MJS_M;row++){
		for(int i=1;i<MJS_N;i++)
		{
			d = (MJS_data[row*(MJS_N+1)+i]-JS_maxMin[i*2+1])/(JS_maxMin[i*2+0]-JS_maxMin[i*2+1]);
			outs<<d;
			outs.put(',');
		}
		outs<<MJS_data[row*(MJS_N+1)+MJS_N]-1; //针对liver数据集，转换类标为0和1
		outs.put('\n');
    }
	outs.close();

	delete[] JS_maxMin;
}


double MJS_Classifier::MJS_WtX(int row)
{
	double JS_ans = 0;
	for(int i=0;i<MJS_N;i++)
		JS_ans += MJS_weights[i]* MJS_data[row*(MJS_N+1)+i];
	return JS_ans;
}

double MJS_Classifier::MJS_Sigmoid(int row)
{
	double ans = MJS_WtX(row);
	return 1/(1+exp(-ans));
}

void MJS_Classifier::MJS_Gradient(void)
{
	for (int i = 0; i < MJS_N; i++)
		MJS_nabla[i] = 0;
	for (int row = 0; row < MJS_M; row++)
	{
		for (int j = 0; j < MJS_N; j++)
		{
			MJS_nabla[j] += MJS_data[row * (MJS_N + 1) + j] * (MJS_data[row * (MJS_N + 1) + MJS_N] - MJS_Sigmoid(row));
		}
	}
	return;
}

void MJS_Classifier::MJS_Test(void)
{
	int count=0;
	for(int row=0;row<MJS_M;row++)
		if((MJS_Sigmoid(row)>=0.5&& MJS_data[row*(MJS_N+1)+MJS_N]==1)||(MJS_Sigmoid(row)<0.5&& MJS_data[row*(MJS_N+1)+MJS_N]==0))
			count++;
	cout<<"The accuracy is:"<<(double)count/MJS_M<<endl;
}


void MJS_Classifier::MJS_SetParameter(int pass, double alpha)
{
	MJS_PASS = pass;
	MJS_ALPHA = alpha;
}
