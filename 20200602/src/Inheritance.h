#pragma once
class Inheritance
{
protected:
	float f_PA;//只允许子类和(friend关键字,不属于类成员，但可以访问类成员)友元函数改变

public:
	void Copy(float x);

private:
	int i_PA;//本类允许，派生\友元\对象都允许
};

//一个派生类继承了所有的基类方法，但下列情况除外：
//基类的构造函数、析构函数和拷贝构造函数。
//基类的重载运算符。
//基类的友元函数。
/*****派生类******/
class ChildInheritance : public Inheritance//一般都是用Public继承，不改变父类的属性
{
public:
	float f_PB;
	void ChildAdd();
	friend void fri_Test(ChildInheritance );

private:
	int Child_i_PB;
};
