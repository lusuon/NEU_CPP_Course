#pragma once
#include<string>
using namespace std;
class Student
{
private:
	int age;
	string no;
	string gender;
public:
	Student(int ,string no,string gender);
	int getAge();
	string getNo();
	string getGender();

};
