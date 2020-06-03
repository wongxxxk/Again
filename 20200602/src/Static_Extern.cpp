#include <iostream>

int NormalVar = 5;	//默认允许被Extern调用
static int s_Var = 10;//内部变量，只实例这一个

void Satatic_add()
{
	static int s_i = 0;//静态变量,第一次调用时初始化一次(之后都是同一变量),同时有效保护了作用域
	s_i++;
	std::cout << s_i << std::endl;
}