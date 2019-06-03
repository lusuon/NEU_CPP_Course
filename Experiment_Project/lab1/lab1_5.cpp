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

static string content = "";

void read(string path)
{
	char buffer[100];
	int count = 1;
	ifstream in(path, std::ios::binary);
	while (!in.eof())
	{
		in.getline(buffer, 100);
		count++;
		// ������
		string line(&buffer[0], &buffer[strlen(buffer)]);
		line = count + " " + line;
		content += line;
		cout << line << endl;
	}
	in.close();
}

void write(string path)
{
	ofstream out(path, std::ios::binary);
	out << content;
	out.close();
	content = "";
}


void main(int argc, char* argv[])
{
	string read_tar = argv[1];
	string write_tar = argv[2];
	read(read_tar);
	write(write_tar);
}
