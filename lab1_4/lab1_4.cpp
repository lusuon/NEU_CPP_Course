#include<iostream>

using namespace std;

void transcope(int** m)
{
	int t;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < i; j++)
		{
			t = *(*(m + i) + j);//t=m[i][j];
			*(*(m + i) + j) = *(*(m + j) + i);//m[i][j]=m[j][i];
			*(*(m + j) + i) = t;//m[j][i]=t;
		}
	}
}
void output(int** m)
{
	int i,j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++) {
			cout << *(*(m + i) + j) << " " ;
		}
		cout << endl;
	}
}

/*
void main() {
	int** m = new int* [3];
	for (int i = 0; i < 3; i++) {
		int* new_row = new int[3];
		for (int j = 0; j < 3; j++) {
			new_row[j] = 3 * i + j+1;
		}
		m[i] = new_row;
	}
	transcope(m);

	output(m);
}
*/
