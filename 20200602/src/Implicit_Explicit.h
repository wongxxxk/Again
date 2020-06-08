#pragma once
#include <String>
#include <iostream>

class Implicit_Explicit
{

private:
	int i_var;
	std::string str_var;

public:
	Implicit_Explicit(int );

	explicit Implicit_Explicit(const std::string& );
//注意：当类的声明和定义分别在两个文件中时，explicit只能写在在声明中，不能写在定义中。
};

