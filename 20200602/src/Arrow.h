#pragma once
class Base
{
public:
	int x;
public:
	void printf() const;//��ĳ�Ա���������const������������������Զ���������ķ�static���ݳ�Ա���κθı�
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


