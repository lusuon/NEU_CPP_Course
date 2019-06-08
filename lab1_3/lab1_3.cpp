#include<iostream>

using namespace std;

double test_m[3][3] = { {1,2,3},{4,5,6},{7,8,9} };

double* transcope(double (&m)[3][3])
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

/*
void main() {
	double *t = transcope(test_m);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << *t << " ";
			t++;
		}
		cout << endl;
	}
}
*/

