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
	VirtualTest(const std::string& name);
	std::string GetName() override;//��д����'Override'
};

