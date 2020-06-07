#include "VirtualFun.h"

std::string VirtualFun::GetName()
{
	return "Entity";//基类返回
}

VirtualTest::VirtualTest():m_Name("Unknown")
{
}

VirtualTest::VirtualTest(const std::string& name) : m_Name(name)//初始化列表,要按顺序初始化
{

}

std::string VirtualTest::GetName()
{
	return m_Name;
}


