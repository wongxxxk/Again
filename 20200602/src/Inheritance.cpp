#include "Inheritance.h"
#include <iostream>

void Inheritance::Copy(float x)
{
	f_PA = x;
}

void ChildInheritance::ChildAdd() 
{
	f_PA = 180.0f;
	std::cout <<"f_PA = "<< f_PA << std::endl;
	std::cout <<"f_PB = "<< f_PB << std::endl;
	std::cout << (f_PB + f_PA) << std::endl;
}

void fri_Test(ChildInheritance Test)
{
	Test.Child_i_PB = 666;
	std::cout << "Test.Child_i_PB = " << Test.Child_i_PB << std::endl;
}
