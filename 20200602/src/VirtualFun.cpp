#include "VirtualFun.h"

std::string VirtualFun::GetName()
{
	return "Entity";//���෵��
}

VirtualTest::VirtualTest():m_Name("Unknown")
{
}

VirtualTest::VirtualTest(const std::string& name) : m_Name(name)//��ʼ���б�,Ҫ��˳���ʼ��
{

}

std::string VirtualTest::GetName()
{
	return m_Name;
}


