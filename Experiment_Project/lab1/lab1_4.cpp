#include<iostream>

using namespace std;



/*

double* transcope(double *m)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			double temp;
			if (i < j)
			{
				//swap(m[i][j], m[j][i]);
				temp = m[i][j];
				m[i][j] = m[j][i];
				m[j][i] = temp;
			}
		}
	}
	return *m;
}
void main() {
	double** m = new double*[3]; 
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
*/
