#include<iostream>

using namespace std;

int** transcope(int** m)
{
	int b[3][3] = { 0 };
	memcpy(b, m, sizeof(b));
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{

		}
	}
	return b;
}
void main() {
	double** m = new double* [3];
	for (int i = 0; i < 3; i++) {
		double* new_row = new double[3];
		for (int j = 0; j < 3; j++) {
			new_row[j] = 3 * i + j;
		}
		m[i] = new_row;
	}


	//double* t = transcope(test_m);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << **m << " ";
			m++;
		}
		cout << endl;
	}
}
