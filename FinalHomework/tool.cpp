#include "tool.h"


vector<int> CountFile(string filename)
{
	vector<int> size;
	int col = 0;
	ifstream ReadFile;
	int row = 0;
	string tmp;
	ReadFile.open(filename, ios::in);//ios::in ��ʾ��ֻ���ķ�ʽ��ȡ�ļ�
	if (ReadFile.fail())//�ļ���ʧ��:����0
	{
		return size;
	}
	else//�ļ�����
	{
		while (getline(ReadFile, tmp, '\n'))
		{
			if (!col) col = count(tmp.begin(), tmp.end(), ',');
			row++;
		}
		ReadFile.close();
		size.push_back(row);
		size.push_back(col + 1);
		return size;
	}
}


vector<int> generateRandomInts(int length, int range)
{
	vector<int> randomInts(length);
	for (int i = 0; i < length; i++)
	{
		randomInts[i] = rand() % range;
	}
	return randomInts;
}


Matrix<string,Dynamic,1> randomLabel(int length, int range, Matrix<string, Dynamic, 1> base_labels)
{
	set<int> randomInts;
	Matrix<string, Dynamic, 1> randomLabel;
	randomLabel.resize(length, 1);
	while(randomInts.size()!=length)
	{
		double val = rand() % range;
		randomInts.insert(val);
	}
	int row = 0;
	for (set<int>::iterator it = randomInts.begin(); it != randomInts.end(); it++)
	{
		randomLabel(row,0) = base_labels((*it),0);
		row++;
	}
	return randomLabel;
}


Matrix<string, Dynamic, Dynamic> randomSeperate(Matrix<string, Dynamic, Dynamic> dataset, Matrix<string, Dynamic, 1> label, int feature_num)
{
	// �����ݼ������зŻص�ȡ��
	vector<int> selectRows = generateRandomInts(dataset.rows(), dataset.rows());
	// ���ѡȡ����
	vector<int> selectFeature = generateRandomInts(feature_num, dataset.cols() - 1);

	//���¹����µľ���
	Matrix<string, Dynamic, Dynamic> seperatedData;
	int newRows = dataset.rows();
	int newCols = feature_num + 1;

	seperatedData.resize(newRows, newCols);
	for (int row = 0; row < newRows; row++)
	{
		for (int col = 0; col < newCols; col++)
		{
			int correspondRow = selectRows[row];
			int correspondCol = (col == feature_num) ? dataset.cols() - 1 : selectFeature[col];

			string corresponedVal = dataset(correspondRow, correspondCol);
			seperatedData(row, col) = corresponedVal;
		}
	}
	return seperatedData;
};

