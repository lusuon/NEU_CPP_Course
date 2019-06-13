#pragma once
/*
定义一个车(vehicle)基类，
具有MaxSpeed、Weight等成员变量，
	Run、Stop等成员函数
*/
/*
由此派生出
	自行车(bicycle)类。自行车(bicycle)类有高度(Height)等属性
	汽车(motorcar)类。汽车(motorcar)类有座位数(SeatNum)等属性。
	从bicycle和motorcar派生出摩托车(motorcycle)类，它们都有Run、Stop等成员函数。
	观察虚函数的作用。在继承过程中，注意把vehicle设置为虚基类。
		如果不把vehicle设置为虚基类，会有什么问题？编程试试看。
*/
class Vehicle
{
protected:
	double maxSpeed;
	double weight;
public:
	Vehicle();
	Vehicle(double ms, double w);
	~Vehicle();
	virtual void run();
	virtual void stop();
	void showDetails();
};

