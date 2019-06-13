#pragma once
/*
����һ����(vehicle)���࣬
����MaxSpeed��Weight�ȳ�Ա������
	Run��Stop�ȳ�Ա����
*/
/*
�ɴ�������
	���г�(bicycle)�ࡣ���г�(bicycle)���и߶�(Height)������
	����(motorcar)�ࡣ����(motorcar)������λ��(SeatNum)�����ԡ�
	��bicycle��motorcar������Ħ�г�(motorcycle)�࣬���Ƕ���Run��Stop�ȳ�Ա������
	�۲��麯�������á��ڼ̳й����У�ע���vehicle����Ϊ����ࡣ
		�������vehicle����Ϊ����࣬����ʲô���⣿������Կ���
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

