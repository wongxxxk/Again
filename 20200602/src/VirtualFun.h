#pragma once
#include <String>

class VirtualFun
{
public:
	virtual std::string GetName();//�����麯�������������ͬ������
};

class VirtualTest :public VirtualFun
{
private:
	std::string m_Name;

public:
	VirtualTest();
	VirtualTest(const std::string& name);//���캯��;const�ؼ��ֱ�ʾ�����޸�,ֻ��
	std::string GetName() override;//��д����'Override'
};

