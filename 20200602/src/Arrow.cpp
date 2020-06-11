#include "Arrow.h"
#include <iostream>

void Base::printf() const //类的成员函数后面加const，表明这个函数不可以对这个类对象的非static数据成员作任何改变
{
	//Base::x = 5;x非static
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

