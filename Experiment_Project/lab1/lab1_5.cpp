# include<iostream>
# include<fstream>
using namespace std;

/*
	�á������Ʒ�ʽ����дָ�����ļ�a.bin����ÿһ��ǰ���к�
	д����һ���������ļ�b.bin,��b.bin�ж�ȡ�����������Ļ��
	��д����lab1_5.cpp
		ʹ��void main(int argc, char*argv[])�����еĲ������ݲ������ļ���
		����ofstream�Ķ�����ļ����в�����ʹ��read������write������Ա������������
		ʹ�����������������ݵ��ļ�����Ļ��
*/

void read(string path)
{
	char data[100];
	ifstream in(path);
	while (!in.eof())
	{

	}
}

void write(string path)
{
	ofstream out(path);
}

void main(int argc, char* argv[])
{
	string read_tar = argv[1];
	string write_tar = argv[2];
	read(read_tar);
	write(write_tar);
}