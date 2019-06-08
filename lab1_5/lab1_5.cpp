# include<iostream>
# include<fstream>
# include<string>
using namespace std;

/*
	用【二进制方式】读写指定的文件a.bin，在每一行前加行号
	写入另一个二进制文件b.bin,从b.bin中读取数据输出到屏幕。
	编写程序lab1_5.cpp
		使用void main(int argc, char*argv[])函数中的参数传递操作的文件名
		定义ofstream的对象对文件进行操作，使用read（）和write（）成员函数读入数据
		使用输出流对象输出数据到文件和屏幕。
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
		// 接收流
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