#include "Constructors.h"
#include <iostream>

Constructorswk::Constructorswk()
{}

Constructorswk::Constructorswk(float a,float b)
{
	x = a;
	y = b;
}

void Constructorswk::print()
{
	std::cout << x << "," << y << std::endl;
}


