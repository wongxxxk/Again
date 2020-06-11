#include "Arrow.h"
#include <iostream>

void Base::printf() const //��ĳ�Ա���������const������������������Զ���������ķ�static���ݳ�Ա���κθı�
{
	//Base::x = 5;x��static
	std::cout << "Hello Arrow" << std::endl;
}

BaseArrow::BaseArrow(Base* entity)
	:m_Obj(entity)
{

}

BaseArrow::~BaseArrow()
{
	delete m_Obj;
}

Base* BaseArrow::GetObject()
{
	return m_Obj;
}

Base* BaseArrow::operator->() 
{
	return m_Obj;
}

