#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<set>
using namespace std;
#include <Eigen/Dense>
using namespace Eigen;

constexpr auto TRAIN_RATE = 0.5;

vector<int> CountFile(string filename);

vector<int> generateRandomInts(int length, int range);

Matrix<string, Dynamic, 1> randomLabel(int length, int range, Matrix<string, Dynamic, 1> base_labels);

Matrix<string, Dynamic, Dynamic> randomSeperate(Matrix<string, Dynamic, Dynamic> dataset, Matrix<string, Dynamic, 1> label, int feature_num);

