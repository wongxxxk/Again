#include "Implicit_Explicit.h"

Implicit_Explicit::Implicit_Explicit(int i_a):i_var(i_a), str_var("Unknown")
{
	std::cout << "i_var = " << i_var << ";  str_var = " << str_var << std::endl;
};

Implicit_Explicit::Implicit_Explicit(const std::string& str_a):i_var(-1), str_var(str_a)
{
	std::cout << "i_var = " << i_var << ";  str_var = " << str_var << std::endl;
};
