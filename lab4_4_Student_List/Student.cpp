#include "Student.h"

Student::Student(int a, string n, string g):age(a),no(n),gender(n)
{
}

int Student::getAge()
{
	return age;
}

string Student::getNo()
{
	return no;
}

string Student::getGender()
{
	return gender;
}

