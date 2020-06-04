#pragma once

class Constructorswk
{
public:
	float x,y;
	Constructorswk();//构造函数
	Constructorswk(float a, float b);
	Constructorswk(int a, int b);

	~Constructorswk();//析构函数,实例消亡的时候自动调用，可执行某些操作

	void print();
};

