#pragma once
class Base
{
public:
	int x;
public:
	void printf() const;//类的成员函数后面加const，表明这个函数不可以对这个类对象的非static数据成员作任何改变
};

class BaseArrow
{
private:
	Base* m_Obj;
public:
	BaseArrow(Base* entity);
	~BaseArrow();

	Base* GetObject();

	Base* operator->();
};


