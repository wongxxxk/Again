#pragma once
#include <String>

class VirtualFun
{
public:
	virtual std::string GetName();//基类虚函数，子类就允许同名覆盖
};

class VirtualTest :public VirtualFun
{
private:
	std::string m_Name;

public:
	VirtualTest();
	VirtualTest(const std::string& name);//构造函数;const关键字表示不会修改,只读
	std::string GetName() override;//复写申明'Override'
};

