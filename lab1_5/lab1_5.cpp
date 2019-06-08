# include<iostream>
# include<fstream>
# include<string>
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
static string toReadPath = "C:\\Users\\Jackson Ma\\Desktop\\toRead.bin";
static string toWritePath = "C:\\Users\\Jackson Ma\\Desktop\\toWrite.bin";

void read(string path)
{
	content = "";
	char buffer[100];
	int count = 0;
	ifstream in(path,std::ios::binary);
	while (!in.eof())
	{
		in.getline(buffer, 100);
		count++;
		// ������
		string line(&buffer[0], &buffer[strlen(buffer)]);
		line = to_string(count) + " " + line+"\n";
		content += line;
		cout << line << endl;
	}
	in.close();
}

void write(string text,string path)
{
	ofstream out(path,std::ios::binary);
	if (out.is_open())
	{
		out << text;
	}
	out.close();
}

/*

//int argc, char* argv[]
void main()
{
	string read_tar = toReadPath;//argv[1];
	string write_tar = toWritePath;//argv[2];
	read(read_tar);
	write(content,write_tar);
}

*/