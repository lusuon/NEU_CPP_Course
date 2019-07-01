#pragma once

double MJS_Determinant(double* , int );
bool MJS_Inverse(double* M1, double*M2, int n);
void MJS_Multiply(double* A, double* B, double* C, int m, int n, int k);
void MJS_Output(double* M, int row, int col);