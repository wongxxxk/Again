#include "VirtualFun.h"

std::string VirtualFun::GetName()
{
	return "Entity";//���෵��
}

VirtualTest::VirtualTest(const std::string& name) : m_Name(name)
{

}

std::string VirtualTest::GetName()
{
	return m_Name;
}


