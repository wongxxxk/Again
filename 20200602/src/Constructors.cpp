#include "Constructors.h"
#include <iostream>

Constructorswk::Constructorswk()//构造函数
{
	std::cout << "Created! "<< std::endl;
};

Constructorswk::Constructorswk(float a,float b)//构造函数,参数不同
{
	std::cout << "Created! " << std::endl;
	x = a;
	y = b;
}

Constructorswk::Constructorswk(int a, int b)//构造函数，参数不同
{
	std::cout << "Created! " << std::endl;
	x = 123;
	y = 321;
}

void Constructorswk::print()
{
	std::cout << x << "," << y << std::endl;
}

Constructorswk::~Constructorswk()
{
	std::cout <<"Destroyed!"<< std::endl;
}
